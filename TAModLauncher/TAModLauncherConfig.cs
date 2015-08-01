using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Diagnostics;
using System.IO;
using Microsoft.Win32;

namespace TAModLauncher
{
    public class TAModLauncherConfig
    {
        private XmlDocument config;
        private XmlElement root;

        public TAModLauncherConfig(string filepath)
        {
            config = new XmlDocument();
            root = config.CreateElement("LauncherConfig");
            config.AppendChild(root);
            loadConfig(filepath);
        }

        public void loadConfig(string filepath)
        {
            if (File.Exists(filepath))
            {
                config.Load(filepath);
            }
        }

        public void saveConfig(string filepath)
        {
            config.Save(filepath);
        }

        public string getProperty(string propertyXPath)
        {
            XmlNode node = config.SelectSingleNode(propertyXPath);
            if (node == null) return null;

            return node.InnerText;
        }

        public void setProperty(string propertyXPath, string value)
        {
            System.Xml.XPath.XPathNavigator nav = config.CreateNavigator();

            XmlNode node = config.SelectSingleNode(propertyXPath);

            if (node == null)
            {
                
                // Create necessary XPath
                var xSplit = propertyXPath.Remove(0, 2).Split('/');
                string builtPath = "/";

                for (int i = 0; i < xSplit.Length; i++)
                {
                    nav = config.DocumentElement.CreateNavigator().SelectSingleNode(builtPath);
                    
                    builtPath += "/" + xSplit[i];
                    if (config.SelectSingleNode(builtPath) == null)
                    {
                        nav.AppendChild("<" + xSplit[i] + "></" + xSplit[i] + ">");
                    }
                }

            }

            // Set the node's value
            nav.SelectSingleNode(propertyXPath).SetValue(value);
            
        }

        public string getRegistryEntry(RegistryKey registryRoot, string registryPath, string value)
        {
            using (RegistryKey key = registryRoot.OpenSubKey(registryPath))
            {
                if (key == null) return null;

                Object o = key.GetValue(value);

                if (o == null) return null;

                return o.ToString();
            }
        }
    }
}
