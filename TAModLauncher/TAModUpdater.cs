using System;
using System.ComponentModel;
using System.Net;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Xml;
using System.IO;

namespace TAModLauncher
{
    public class TAModUpdater
    {
        // The application folder
        private readonly string appPath = AppDomain.CurrentDomain.BaseDirectory;

        // Whether update checks should occur automatically
        public bool doAutoUpdateCheck = true;

        // The URL of the download server
        //public string updateUrl = "http://localhost/tamods/version.xml";
        //public string downloadUrl = "http://localhost/tamods";
        //public string updateUrl = "file://D:/UserFiles/Documents/GitHub/tamodsupdate/update/version.xml";
        public string updateUrl = "https://raw.githubusercontent.com/josephspearritt/tamodsupdate/release/version.xml";
        public string downloadUrl = "https://raw.githubusercontent.com/josephspearritt/tamodsupdate/release";
        

        // The filename of the local and server versioning manifest
        public string localManifestFilename = "version.xml";

        // Versioning channel to update from
        public string updateChannel = "stable";

        // Path to the config directory
        public string ConfigPath = Environment.GetFolderPath(Environment.SpecialFolder.Personal) + "/My Games/Tribes Ascend/TribesGame/config/";
        public string ConfigSignifier = "!CONFIG/";

        // The local and server version manifest XML files
        private XmlDocument localManifest;
        private XmlDocument serverManifest;

        // The local and server file lists
        public List<VersionedFile> localFiles;
        public List<VersionedFile> serverFiles;

        // The downloader object and associated versioned file listings
        private WebClient downloader = null;
        private Queue<VersionedFile> downloadQueue;
        private VersionedFile currentDownload = null;
        private int currentDownloadProgressPercentage = 0;
        private int totalFilesInCurrentDownloadList = 0;

        // Download events 
        public event EventHandler DownloadCompleted;
        public event EventHandler DownloadProgressChanged;

        public TAModUpdater()
        {
            downloadQueue = new Queue<VersionedFile>();
            localManifest = new XmlDocument();
            serverManifest = new XmlDocument();
        }

        public void loadLocalManifest()
        {
            // If local manifest does not exist, create empty filelist structure
            if (!File.Exists(appPath + localManifestFilename))
            {
                localFiles = new List<VersionedFile>();
                return;
            }

            // Load xml document; may throw exceptions
            localManifest.Load(appPath + localManifestFilename);

            // Load files into list; also may throw exceptions
            localFiles = getManifestFileList(localManifest);
        }

        public void loadServerManifest()
        {
            // Allow TLS 1.2
            ServicePointManager.SecurityProtocol = SecurityProtocolType.Ssl3 | SecurityProtocolType.Tls | SecurityProtocolType.Tls11 | SecurityProtocolType.Tls12;

            // Load xml document; may throw exceptions
            serverManifest.Load(updateUrl);

            // Load files into list; also may throw exceptions
            serverFiles = getManifestFileList(serverManifest);
        }

        public VersionedFile getLocalFile(string filename)
        {
            VersionedFile matchingLocalFile = localFiles.Find((VersionedFile localFile) => { return localFile.fileName == filename; });
            return matchingLocalFile;
        }

        public List<VersionedFile> getFilesNeedingUpdate()
        {
            List<VersionedFile> filesNeedingUpdate = new List<VersionedFile>();

            // Iterate through server manifest, comparing with local manifest
            foreach (VersionedFile file in serverFiles)
            {
                VersionedFile matchingLocalFile = getLocalFile(file.fileName);

                // Update is required if the local file does not exist or has a version < server version
                if (matchingLocalFile == null) filesNeedingUpdate.Add(file);
                else if (matchingLocalFile.version < file.version) filesNeedingUpdate.Add(file);
            }

            return filesNeedingUpdate;
        }

        public List<VersionedFile> getManifestFileList(XmlDocument manifest)
        {
            XmlNode fileRoot = manifest.SelectSingleNode("//TAMods/files[@channel='" + updateChannel + "']");

            if (manifest.DocumentElement == null)
            {
                throw new XmlException("Manifest contains no XML document root node.");
            }

            // Add all listed files
            List<VersionedFile> fileList = new List<VersionedFile>();
            foreach (XmlNode node in fileRoot.ChildNodes)
            {
                // Only look at file nodes
                if (node.Name == "file")
                {
                    // Throw exception if version is missing
                    if (node.Attributes["version"] == null) throw new XmlException("Version information missing from file node with InnerText " + node.InnerText);

                    // Throw exception if version is not a float
                    try
                    {
                        Convert.ToSingle(node.Attributes["version"].Value);
                    }
                    catch (InvalidCastException)
                    {
                        throw new XmlException("Invalid version number in file node with InnerText " + node.InnerText);
                    }

                    fileList.Add(new VersionedFile(node.InnerText.Trim(), Convert.ToSingle(node.Attributes["version"].Value)));
                }
            }

            return fileList;
        }

        public List<string> getAvailableUpdateChannels()
        {
            XmlNode root = serverManifest.SelectSingleNode("//TAMods");

            if (serverManifest.DocumentElement == null)
            {
                throw new XmlException("Manifest contains no XML document root node.");
            }

            // Find all update channels
            List<string> channels = new List<string>();

            foreach (XmlNode node in root.ChildNodes)
            {
                if (node.Name == "files")
                {
                    channels.Add(node.Attributes["channel"].Value.ToString().ToLower());
                }
            }

            return channels;
        }

        public void setUpdateChannel(string channel)
        {
            XmlNode root = serverManifest.SelectSingleNode("//TAMods");

            if (serverManifest.DocumentElement == null)
            {
                throw new XmlException("Manifest contains no XML document root node.");
            }

            // Find given update channel

            foreach (XmlNode node in root.ChildNodes)
            {
                if (node.Name == "files")
                {
                    if (node.Attributes["channel"].Value.ToString().ToLower() == channel.ToLower())
                    {
                        updateChannel = channel.ToLower();
                        return;
                    }
                }
            }

            throw new XmlException("Given update channel does not exist.");
        }

        public bool isUriAccessible(Uri uri)
        {
            var ret = true;

            HttpWebResponse response = null;
            var request = (HttpWebRequest)WebRequest.Create(uri);
            request.Method = "HEAD";

            try
            {
                response = (HttpWebResponse)request.GetResponse();
            }
            catch (WebException)
            {
                ret = false;
            }
            finally
            {
                if (response != null) response.Close();
            }

            return ret;
        }

        public void createNecessaryRelativeDirectories(string fileName, string absPath)
        {
            fileName = fileName.Replace('/', '\\');
            if (fileName.Contains('\\'))
            {
                string[] dirpath = fileName.Split('\\');
                string builtpath = "";
                for (int i = 0; i < dirpath.Length - 1; i++)
                {
                    builtpath += "\\" + dirpath[i];
                    if (!Directory.Exists(absPath + builtpath))
                    {
                        Debug.WriteLine("CREATING " + absPath + builtpath);
                        Directory.CreateDirectory(absPath + builtpath);
                    }
                }
            }

        }

        public int getDownloadListProgressPercentage()
        {
            if (totalFilesInCurrentDownloadList <= 0 || downloader == null)
            {
                return 100;
            }

            float pcScale = 1F / ((float)totalFilesInCurrentDownloadList);

            return (int)(pcScale * (float)currentDownloadProgressPercentage + 100 * pcScale * (float)(totalFilesInCurrentDownloadList - downloadQueue.Count));
        }

        public string getDownloadListCurrentFile()
        {
            if (currentDownload == null) return "";

            return currentDownload.fileName;
        }

        public void beginFullDownload()
        {
            if (serverFiles == null) throw new XmlException("Files to download could not be retrieved");
            
            beginFileListDownload(serverFiles);
        }

        public void beginUpdate()
        {
            beginFileListDownload(getFilesNeedingUpdate());
        }

        public void backupCurrentLocalFiles()
        {
            foreach (VersionedFile file in localFiles)
            {
                if (File.Exists(appPath + file.fileName))
                {

                    createNecessaryRelativeDirectories("backup\\" + file.fileName, appPath);
                    File.Copy(appPath + file.fileName, appPath + "backup\\" + file.fileName, true);
                }
                else if (File.Exists(ConfigPath + file.fileName.Replace(ConfigSignifier, "")))
                {
                    createNecessaryRelativeDirectories("backup\\" + file.fileName.Replace(ConfigSignifier, ""), ConfigPath);
                    File.Copy(ConfigPath + file.fileName.Replace(ConfigSignifier, ""), ConfigPath + "backup\\" + file.fileName.Replace(ConfigSignifier, ""), true);
                }
            }
        }

        public void finaliseLocalFileUpdate()
        {
            foreach (VersionedFile file in serverFiles)
            {
                if (File.Exists(appPath + "inprogress\\" + file.fileName))
                {
                    //Deal with files relative to the config folder
                    if (file.fileName.StartsWith(ConfigSignifier))
                    {
                        string fName = file.fileName.Replace(ConfigSignifier, "");
                        createNecessaryRelativeDirectories(fName, ConfigPath);
                        File.Copy(appPath + "inprogress\\" + file.fileName, ConfigPath + fName, true);
                    }
                    else
                    {
                        createNecessaryRelativeDirectories(file.fileName, appPath);
                        File.Copy(appPath + "inprogress\\" + file.fileName, appPath + file.fileName, true);

                    }
                    //createNecessaryRelativeDirectories(file.fileName, appPath);
                    //File.Copy(appPath + "inprogress\\" + file.fileName, appPath + file.fileName, true);
                    File.Delete(appPath + "inprogress\\" + file.fileName);
                }
            }

            if (Directory.Exists(appPath + "inprogress"))
            {
                Directory.Delete(appPath + "inprogress", true);
            }

        }

        public void finishDownload()
        {
            // Backup old version, then copy over new one
            backupCurrentLocalFiles();
            finaliseLocalFileUpdate();
            // Get the new version manifest
            if (File.Exists(appPath + localManifestFilename))
            {
                File.Delete(appPath + localManifestFilename);
            }
            serverManifest.Save(appPath + localManifestFilename);
            loadLocalManifest();
        }

        public void beginFileListDownload(List<VersionedFile> fileList)
        {
            if (currentDownload != null || downloadQueue.Count != 0)
            {
                throw new Exception("Cannot begin a file list download while one is in progress.");
            }

            totalFilesInCurrentDownloadList = 0;
            currentDownloadProgressPercentage = 0;

            foreach (VersionedFile file in fileList)
            {
                createNecessaryRelativeDirectories("inprogress\\" + file.fileName, appPath);
                totalFilesInCurrentDownloadList++;
                addFileToDownloadQueue(file);
            }

        }

        public void addFileToDownloadQueue(VersionedFile file)
        {
            // If queue is empty, start downloading immediately, otherwise add to the end of the queue
            if (currentDownload == null && downloadQueue.Count == 0)
            {
                if (!Directory.Exists(appPath + "\\inprogress")) Directory.CreateDirectory(appPath + "\\inprogress");
                download(new Uri(downloadUrl + "\\" + file.fileName), appPath + "\\inprogress\\" + file.fileName);
                currentDownload = file;
                return;
            }
            else
            {
                downloadQueue.Enqueue(file);
            }
        }

        public void download(Uri uri, string filepath)
        {
            // Do not allow download to start if one is already happening
            if (downloader != null)
            {
                throw new IOException("A file download is already in progress");
            }

            // Check that the uri to download from actually exists
            if (!isUriAccessible(uri))
            {
                throw new WebException("The URI given was not accessible");
            }

            // Download the file and add event handlers
            downloader = new WebClient();
            downloader.DownloadFileCompleted += new AsyncCompletedEventHandler(webClientDownloadCompleted);
            downloader.DownloadProgressChanged += new DownloadProgressChangedEventHandler(webClientDownloadProgressChanged);
            downloader.DownloadFileAsync(uri, filepath);
        }

        private void webClientDownloadCompleted(object sender, AsyncCompletedEventArgs e)
        {

            downloader.Dispose();
            downloader = null;

            // Trigger completed event if queue is finished, otherwise move on to next download in the queue
            if (downloadQueue.Count == 0)
            {
                finishDownload();
                DownloadCompleted(this, EventArgs.Empty);
            }
            else
            {
                VersionedFile nextFile = downloadQueue.Dequeue();
                if (!Directory.Exists(appPath + "\\inprogress")) Directory.CreateDirectory(appPath + "\\inprogress");
                download(new Uri(downloadUrl + "\\" + nextFile.fileName), appPath + "\\inprogress\\" + nextFile.fileName);
                currentDownload = nextFile;
            }
        }

        private void webClientDownloadProgressChanged(object sender, DownloadProgressChangedEventArgs e)
        {
            currentDownloadProgressPercentage = e.ProgressPercentage;
            DownloadProgressChanged(this, EventArgs.Empty);
        }

    }

    public class VersionedFile : IComparable<VersionedFile>
    {
        public readonly string fileName;
        public readonly float version;

        public VersionedFile(string fileName, float version)
        {
            this.fileName = fileName;
            this.version = version;
        }

        public VersionedFile(string fileName) : this(fileName, 1) { }

        public int CompareTo(VersionedFile other)
        {
            if (fileName == other.fileName) return version.CompareTo(other.version);
            return fileName.CompareTo(other.fileName);
        }

        public override bool Equals(object obj)
        {
            VersionedFile other = obj as VersionedFile;
            if (other == null) return false;
            return fileName == other.fileName && version == other.version;
        }

        public override int GetHashCode()
        {
            return fileName.GetHashCode() * 7 + version.GetHashCode();
        }

        public override string ToString()
        {
            return fileName + " | version " + version;
        }
    }
}
