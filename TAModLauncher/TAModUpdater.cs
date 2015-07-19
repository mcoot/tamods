using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Xml;

namespace TAModLauncher
{
    class TAModUpdater
    {
        // The application folder
        private readonly string appPath = AppDomain.CurrentDomain.BaseDirectory;
        
        // Whether update checks should occur automatically
        public bool doAutoUpdateCheck = true;

        // The URL of the XML version / file manifest
        public string manifestUrl = "C:\\Tribes Mods\\modCurrent\\version.xml";

        // The filename of the local versioning manifest
        public string manifestLocalFilename = "version.xml";

        // Versioning channel to update from
        public string updateChannel = "stable";

        // The local and server version manifest XML files
        private XmlDocument localManifest = null;
        private XmlDocument serverManifest = null;

        public List<VersionedFile> localFiles;
        public List<VersionedFile> serverFiles;

        // The local and server fileLists

        public TAModUpdater() { }

        public void loadLocalManifest()
        {
            localManifest = new XmlDocument();

            // Load xml document; may throw exceptions - Reflected up to app.
            localManifest.Load(appPath + "\\" + manifestLocalFilename);

            // Load files into list; also may throw exceptions
            localFiles = getManifestFileList(localManifest);
        }

        public void loadServerManifest()
        {
            serverManifest = new XmlDocument();

            // Load xml document; may throw exceptions - Reflected up to app.
            serverManifest.Load(manifestUrl);

            // Load files into list; also may throw exceptions
            serverFiles = getManifestFileList(serverManifest);
        }

        public List<VersionedFile> getFilesNeedingUpdate()
        {
            List<VersionedFile> filesNeedingUpdate = new List<VersionedFile>();

            // Iterate through server manifest, comparing with local manifest
            foreach (VersionedFile file in serverFiles)
            {
                VersionedFile matchingLocalFile;
                // Find a local file with the server's file name
                matchingLocalFile = localFiles.Find((VersionedFile localFile) => { return localFile.fileName == file.fileName; });

                // Update is required if the local file does not exist or has a version < server version
                if (matchingLocalFile == null) filesNeedingUpdate.Add(file);
                if (matchingLocalFile.version < file.version) filesNeedingUpdate.Add(file); 
            }

            return filesNeedingUpdate;
        }

        public List<VersionedFile> getManifestFileList(XmlDocument manifest)
        {
            XmlNode fileRoot = manifest.SelectSingleNode("//TAMods/files[@channel='"+updateChannel+"']");

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

    }

    class VersionedFile : IComparable<VersionedFile>
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
