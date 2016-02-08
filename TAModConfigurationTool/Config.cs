using System;
using System.ServiceProcess;
using System.IO;
using System.Diagnostics;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using NLua;

namespace TAModConfigurationTool
{
    public class Config
    {
        private Lua lua;
        private string configPath;
        private string configFile;
        private string configPreset = null;
        private Dictionary<string, List<string>> configVarSections;
        private Dictionary<string, Object> configVars;
        private Dictionary<string, Object> configVarsDefault;
        private List<Loadout> configLoadouts;
        private List<CrosshairSetting> configCrosshairs;
        private List<MutedPlayer> configMutedPlayers;
        private List<ProjectileSetting> configProjectileSettings;
        private List<ProjectileSwap> configProjectileSwaps;
        private Dictionary<string, string> assetFiles;
        private Dictionary<string, string> assetFilesDefault;
        public string configVersion = "v0.6";

        public Config(string configPath, string configFilename)
        {
            lua = new Lua();
            // Register necessary functions to the script
            lua.RegisterFunction("require", this, this.GetType().GetMethod("setRequireFile"));
            lua.RegisterFunction("rgb", this, this.GetType().GetMethod("rgb"));
            lua.RegisterFunction("rgba", this, this.GetType().GetMethod("rgba"));
            lua.RegisterFunction("crosshair", this, this.GetType().GetMethod("crosshair"));
            lua.RegisterFunction("crosshairs", this, this.GetType().GetMethod("crosshairs"));
            lua.RegisterFunction("equipment", this, this.GetType().GetMethod("equipment"));
            lua.RegisterFunction("setLoadout", this, this.GetType().GetMethod("setLoadout"));
            lua.RegisterFunction("setCrosshairs", this, this.GetType().GetMethod("setCrosshairs"));
            lua.RegisterFunction("mplayer", this, typeof(MutedPlayer).GetMethod("create"));
            lua.RegisterFunction("mplayer_custom", this, typeof(MutedPlayer).GetMethod("create_custom"));
            lua.RegisterFunction("mutePlayer", this, this.GetType().GetMethod("mutePlayer"));
            lua.RegisterFunction("getProjectile", this, this.GetType().GetMethod("getProjectile"));
            lua.RegisterFunction("cloneProjectile", this, this.GetType().GetMethod("cloneProjectile"));
            lua.RegisterFunction("setProjectileColor", this, this.GetType().GetMethod("setProjectileColor"));
            lua.RegisterFunction("setProjectile", this, this.GetType().GetMethod("setProjectile"));


            this.configPath = configPath;
            this.configFile = configFilename;
            setupConfigVarDict();
            setupAssetFileDict();
            configLoadouts = new List<Loadout>();
            configCrosshairs = new List<CrosshairSetting>();
            configMutedPlayers = new List<MutedPlayer>();
            configProjectileSettings = new List<ProjectileSetting>();
            configProjectileSwaps = new List<ProjectileSwap>();

        }

        // Constructor puts the config path in the root of the C: drive if no path is given
        public Config() : this("C:\\", "config.lua") { }

        public void setConfigPath(string configPath)
        {
            this.configPath = configPath;
        }

        // Setup the keys for all known config variables
        private void setupConfigVarDict()
        {
            configVarSections = new Dictionary<string, List<string>>()
            {
                { "General", new List<string>()
                    {
                        "showErrorNotifications", "recordStats"
                    }
                },

                { "Display", new List<string>()
                    {
                        "showWeapon", "showHUDWeapons", "showBodyMesh", "showRainbow", "showCrosshair", "crosshairScale", "crosshairColor", "showFirstPersonAmmo", "skiBarMin", "skiBarMax"
                    }
                },

                { "HUD Icons", new List<string>()
                    {
                        "IFFScale", "showObjectiveIcon", "showFlagBaseIcon", "showFlagHomeBaseIcon", "showCTFBaseIcon", "showNuggetIcon", "showPlayerIcon", "showVehicleIcon", "showSensorIcon", "showMineIcon", "showObjectiveText", "showMineText"
                    }
                },

                { "HUD Colours", new List<string>()
                    {
                        "friendlyChatColor", "enemyChatColor", "whisperChatColor", "friendlyHUDChatColor", "enemyHUDChatColor", "friendlyColor", "enemyColor", "friendlyMarkerColor", "friendlyIsFMarkerColor", "enemyMarkerColor", "enemyIsFMarkerColor"
                    }
                },

                { "Damage Numbers", new List<string>()
                    {
                        "damageNumbersLimit", "showDamageNumberStream", "showChainBulletHitCount", "damageNumberStreamTimeout", "damageNumbersOffsetX", "damageNumbersOffsetY",
                        "damageNumbersScale", "damageNumberCustomText", "damageNumbersColorMin", "damageNumbersColorMax"
                    }
                },

                { "Magic Chain", new List<string>()
                    {
                        "useMagicChain", "useSmallBullets", "centerBulletSpawn", "bulletPingMultiplier", "bulletSpawnDelay"
                    }
                },

                { "Mouse Sensitivity", new List<string>()
                    {
                        "useFOVScaling", "sens", "sensZoom", "sensZoooom"
                    }
                },

                { "Roam Map", new List<string>()
                    {
                        "disableBaseTurrets", "disablePower", "maxSpeedWithFlag", "decelerationRateWithFlag"
                    }
                },

                { "Route Recording", new List<string>()
                    {
                        "routeDrawInterval", "routeDrawETAInterval", "routeReplayRotation", "routeCinematicMode", "showSavedLocations"
                    }
                },
                { "Stopwatch", new List<string>()
                    {
                        "stopwatchStopOnCap", "stopwatchStopOnDeath", "stopwatchNotifications"
                    }
                },

                { "Sounds", new List<string>()
                    {
                        "hitSoundMode", "hitSoundPitchMin", "hitSoundPitchMax", "hitSoundDamageRef", "volumeHitSound",

                        "customBluePlateSound", "customAirMailSound", "customHeadShotSound", "customArtilleryShot", "customHeadShotKill", "customMeleeKill",
                        "customRoadKill", "customFastGrab", "customFirstBlood", "customFlagBlueGrab", "customFlagRedGrab", "customFlagBluePickup", "customFlagRedPickup",
                        "customFlagBlueCapture", "customFlagRedCapture", "customFlagBlueReturn", "customFlagRedReturn", "customFlagBlueDrop", "customFlagRedDrop",
                        "customStreak1", "customStreak2", "customStreak3", "customStreak4", "customStreak5", "customMultiKill1", "customMultiKill2", "customMultiKill3",
                        "customMultiKill4", "customMultiKill5",

                        "volumeBluePlate", "volumeAirMail", "volumeHeadShot", "volumeArtilleryShot", "volumeHeadShotKill", "volumeMeleeKill",
                        "volumeRoadKill", "volumeFastGrab", "volumeFirstBlood", "volumeFlagBlueGrab", "volumeFlagRedGrab", "volumeFlagBluePickup", "volumeFlagRedPickup",
                        "volumeFlagBlueCapture", "volumeFlagRedCapture", "volumeFlagBlueReturn", "volumeFlagRedReturn", "volumeFlagBlueDrop", "volumeFlagRedDrop",
                        "volumeStreak1", "volumeStreak2", "volumeStreak3", "volumeStreak4", "volumeStreak5", "volumeMultiKill1", "volumeMultiKill2", "volumeMultiKill3",
                        "volumeMultiKill4", "volumeMultiKill5"
                    }
                },

                
            };

            configVarsDefault = new Dictionary<String, Object>()
            {
                { "showErrorNotifications", true },
                { "recordStats", false },
                { "showWeapon", true },
                { "showHUDWeapons", true },
                { "showBodyMesh", true },
                { "showRainbow", false },
                { "showCrosshair", true },
                { "crosshairScale", 1 },
                { "showFirstPersonAmmo", false },
                { "skiBarMin", 7 },
                { "skiBarMax", 180 },

                { "damageNumbersLimit", 0 },
                { "showDamageNumberStream", false },
                { "showChainBulletHitCount", false },
                { "damageNumberStreamTimeout", 0.5 },
                { "damageNumbersOffsetX", 0 },
                { "damageNumbersOffsetY", 0 },
                { "damageNumbersScale", 1 },
                { "damageNumberCustomText", "" },

                { "IFFScale", 1.0 },
                { "showObjectiveIcon", true },
                { "showFlagBaseIcon", true },
                { "showFlagHomeBaseIcon", true },
                { "showCTFBaseIcon", true },
                { "showNuggetIcon", true },
                { "showPlayerIcon", true },
                { "showVehicleIcon", true },
                { "showSensorIcon", true },
                { "showMineIcon", true },
                { "showObjectiveText", true },
                { "showMineText", true },

                { "useFOVScaling", true },
                { "sens", 10.0F },
                { "sensZoom", 5.0F },
                { "sensZoooom", 2.0F },

                { "crosshairColor", rgb(255, 255, 255) },
                { "damageNumbersColorMin", rgb(255, 255, 255) },
                { "damageNumbersColorMax", rgb(248, 83, 83) },
                { "friendlyChatColor", rgb(158, 208, 212) },
                { "enemyChatColor", rgb(255, 111, 111) },
                { "whisperChatColor", rgb(207, 165, 101) },
                { "friendlyHUDChatColor", rgb(158, 208, 211) },
                { "enemyHUDChatColor", rgb(249, 32, 32) },

                { "friendlyColor", rgb(119, 186, 255) },
                { "enemyColor", rgb(248, 83, 83) },
                { "enemyMarkerColor", rgb(255, 23, 23) },
                { "enemyIsFMarkerColor", rgb(239, 164, 0) },
                { "friendlyMarkerColor", rgb(115, 225, 255) },
                { "friendlyIsFMarkerColor", rgb(81, 250, 85) },

                { "hitSoundMode", 0 },
                { "hitSoundPitchMin", 0.4F },
                { "hitSoundPitchMax", 1.6F },
                { "hitSoundDamageRef", 600 },

                { "customAirMailSound", false },
                { "customBluePlateSound", false },
                { "customHeadShotSound", false },
                
                { "customStreak1", false }, { "customStreak2", false }, { "customStreak3", false }, { "customStreak4", false }, { "customStreak5", false },
                { "customMultiKill1", false }, { "customMultiKill2", false }, { "customMultiKill3", false }, { "customMultiKill4", false }, { "customMultiKill5", false },
                { "customFirstBlood", false }, { "customHeadShotKill", false }, { "customArtilleryShot", false }, { "customMeleeKill", false },
                { "customRoadKill", false }, { "customFastGrab", false },

                { "customFlagBlueGrab", false }, { "customFlagRedGrab", false },
                { "customFlagBluePickup", false }, { "customFlagRedPickup", false },
                { "customFlagBlueCapture", false }, { "customFlagRedCapture", false },
                { "customFlagBlueReturn", false }, { "customFlagRedReturn", false },
                { "customFlagBlueDrop", false }, { "customFlagRedDrop", false },

                { "volumeHitSound", 0.55F },
                { "volumeBluePlate", 1F },
                { "volumeAirMail", 1F },
                { "volumeHeadShot", 0.55F },
                
                { "volumeStreak1", 0.5F }, { "volumeStreak2", 0.5F }, { "volumeStreak3", 0.5F }, { "volumeStreak4", 0.5F }, { "volumeStreak5", 0.5F },
                { "volumeMultiKill1", 0.5F }, { "volumeMultiKill2", 0.5F }, { "volumeMultiKill3", 0.5F }, { "volumeMultiKill4", 0.5F }, { "volumeMultiKill5", 0.5F },
                { "volumeFirstBlood", 0.5F }, { "volumeHeadShotKill", 0.5F }, { "volumeArtilleryShot", 0.5F }, { "volumeMeleeKill", 0.5F },
                { "volumeRoadKill", 0.5F }, { "volumeFastGrab", 0.5F },

                { "volumeFlagBlueGrab", 0.5F }, { "volumeFlagRedGrab", 0.5F },
                { "volumeFlagBluePickup", 0.5F }, { "volumeFlagRedPickup", 0.5F },
                { "volumeFlagBlueCapture", 0.5F }, { "volumeFlagRedCapture", 0.5F },
                { "volumeFlagBlueReturn", 0.5F }, { "volumeFlagRedReturn", 0.5F },
                { "volumeFlagBlueDrop", 0.5F }, { "volumeFlagRedDrop", 0.5F },

                { "disableBaseTurrets", false },
                { "disablePower", false },
                { "maxSpeedWithFlag", 0 },
                { "decelerationRateWithFlag", 10 },

                { "useMagicChain", false },
                { "useSmallBullets", false },
                { "centerBulletSpawn", false },
                { "bulletPingMultiplier", 1.0F },
                { "bulletSpawnDelay", 0.0F },

                { "routeDrawInterval", 500 },
                { "routeDrawETAInterval", 5 },
                { "routeReplayRotation", true },
                { "routeCinematicMode", false },
                { "showSavedLocations", true },

                { "stopwatchStopOnCap", false },
                { "stopwatchStopOnDeath", true },
                { "stopwatchNotifications", true },
                
            };

            configVars = new Dictionary<String, Object>();
            foreach (string key in configVarsDefault.Keys)
            {
                configVars.Add(key, null);
            }
        }

        private void setupAssetFileDict()
        {
            assetFilesDefault = new Dictionary<string, string>()
            {
                { "sounds\\hit.wav", null },
                { "sounds\\blueplate.wav", null },
                { "sounds\\airmail.wav", null },
                { "sounds\\headshot.wav", null },

                { "sounds\\streak1.wav", null },
                { "sounds\\streak2.wav", null },
                { "sounds\\streak3.wav", null },
                { "sounds\\streak4.wav", null },
                { "sounds\\streak5.wav", null },
                { "sounds\\multikill1.wav", null },
                { "sounds\\multikill2.wav", null },
                { "sounds\\multikill3.wav", null },
                { "sounds\\multikill4.wav", null },
                { "sounds\\multikill5.wav", null },
                { "sounds\\firstblood.wav", null },
                { "sounds\\headshotkill.wav", null },
                { "sounds\\artilleryshot.wav", null },
                { "sounds\\meleekill.wav", null },
                { "sounds\\roadkill.wav", null },
                { "sounds\\fastgrab.wav", null },

                { "sounds\\flagblue_grab.wav", null },
                { "sounds\\flagred_grab.wav", null },
                { "sounds\\flagblue_pickup.wav", null },
                { "sounds\\flagred_pickup.wav", null },
                { "sounds\\flagblue_capture.wav", null },
                { "sounds\\flagred_capture.wav", null },
                { "sounds\\flagblue_return.wav", null },
                { "sounds\\flagred_return.wav", null },
                { "sounds\\flagblue_drop.wav", null },
                { "sounds\\flagred_drop.wav", null },
            };

            assetFiles = new Dictionary<string, string>();
            foreach (string key in assetFilesDefault.Keys)
            {
                assetFiles.Add(key, null);
            }
        }

        // Clear all loaded config variables
        public void clearConfig()
        {
            setupConfigVarDict();
        }

        // Load config variables from the file, returning success
        public bool loadConfig()
        {

            if (!System.IO.File.Exists(configPath + configFile))
            {
                try
                {
                    System.IO.File.WriteAllText(configPath + configFile, "");
                }
                catch (DirectoryNotFoundException)
                {
                    MessageBox.Show(String.Format("Unable to access config path at {0}", configPath));
                    return false;
                }
            }

            // Run the lua script
            try
            {
                lua.DoFile(configPath + configFile);
            }
            catch (NLua.Exceptions.LuaException)
            {
                return false;
            }

            // Load the variables from the Lua object
            List<string> configKeys = new List<String>();
            foreach (string key in configVars.Keys)
            {
                configKeys.Add(key);
            }

            foreach (string key in configKeys)
            {
                loadConfigVar(key);
            }



            // Load in custom asset files where they exist
            List<string> assetKeys = new List<String>();
            foreach (string key in assetFiles.Keys)
            {
                assetKeys.Add(key);
            }

            foreach (string key in assetKeys)
            {
                if (System.IO.File.Exists(configPath + key))
                {
                    setAssetFile(key, configPath + key);
                }
            }

            return true;
        }

        private void loadConfigVar(string variableName)
        {
            configVars[variableName] = lua[variableName];
        }

        // Checks if a config variable has been set
        public bool isConfigVarSet(string variableName)
        {
            if (!configVars.ContainsKey(variableName)) return false;
            if (configVars[variableName] == null) return false;

            return true;
        }

        public object getConfigVar(string variableName)
        {
            if (configVars.ContainsKey(variableName))
            {
                if (configVars[variableName] == null)
                {
                    if (!configVarsDefault.ContainsKey(variableName))
                    {
                        return null;
                    }
                    else
                    {
                        return configVarsDefault[variableName];
                    }
                }
                return configVars[variableName];
            }
            else
            {
                if (!configVarsDefault.ContainsKey(variableName))
                {
                    return null;
                }
                else
                {
                    return configVarsDefault[variableName];
                }
            }

        }

        public object getConfigVarDefault(string variableName)
        {
            return configVarsDefault[variableName];
        }

        public void setConfigVar(string variableName, object value)
        {
            configVars[variableName] = value;
        }

        public bool isAssetFileSet(string assetName)
        {
            if (!assetFiles.ContainsKey(assetName)) return false;
            if (assetFiles[assetName] == null) return false;

            return true;
        }

        public string getAssetFile(string assetName)
        {
            if (assetFiles.ContainsKey(assetName))
            {
                if (assetFiles[assetName] == null)
                {
                    if (!assetFilesDefault.ContainsKey(assetName))
                    {
                        return null;
                    }
                    else
                    {
                        return assetFilesDefault[assetName];
                    }
                }
                return assetFiles[assetName];
            }
            else
            {
                if (!assetFilesDefault.ContainsKey(assetName))
                {
                    return null;
                }
                else
                {
                    return assetFilesDefault[assetName];
                }
            }
        }

        public string getAssetFileDefault(string assetName)
        {
            return assetFilesDefault[assetName];
        }

        public void setAssetFile(string assetName, string inputPath)
        {
            assetFiles[assetName] = inputPath;
        }

        public List<Loadout> getConfigLoadouts()
        {
            // Make a deep copy of the config loadouts list
            List<Loadout> cp = new List<Loadout>();
            foreach (Loadout l in configLoadouts)
            {
                cp.Add(l);
            }
            cp.Sort();
            return cp;
        }

        public void clearConfigLoadouts()
        {
            configLoadouts.Clear();
        }

        public List<CrosshairSetting> getConfigSetCrosshairs()
        {
            // Make a deep copy of the config crosshairs list
            List<CrosshairSetting> cp = new List<CrosshairSetting>();
            foreach (CrosshairSetting xhair in configCrosshairs)
            {
                cp.Add(xhair);
            }
            cp.Sort();
            return cp;
        }

        public void clearConfigCrosshairs()
        {
            configCrosshairs.Clear();
        }

        public List<MutedPlayer> getConfigMutedPlayers()
        {
            // Make a deep copy of the config muted players list
            List<MutedPlayer> cp = new List<MutedPlayer>();
            foreach (MutedPlayer player in configMutedPlayers)
            {
                cp.Add(player);
            }
            cp.Sort();
            return cp;
        }

        public void clearConfigMutedPlayers()
        {
            configMutedPlayers.Clear();
        }

        public List<ProjectileSetting> getConfigProjectileSettings()
        {
            // Make a deep copy of the config projectiles list
            List<ProjectileSetting> cp = new List<ProjectileSetting>();
            foreach (ProjectileSetting proj in configProjectileSettings)
            {
                cp.Add(proj);
            }
            cp.Sort();
            return cp;
        }

        public void clearConfigProjectileSettings()
        {
            configProjectileSettings.Clear();
        }

        public List<ProjectileSwap> getConfigProjectileSwaps()
        {
            // Make a deep copy of the config projectiles swap list
            List<ProjectileSwap> cp = new List<ProjectileSwap>();
            foreach (ProjectileSwap proj in configProjectileSwaps)
            {
                cp.Add(proj);
            }
            cp.Sort();
            return cp;
        }

        public void clearConfigProjectileSwaps()
        {
            configProjectileSwaps.Clear();
        }

        // Config save formats
        private string[] formatGetStringLines(string s)
        {
            return Regex.Split(s, "\r\n|\r|\n");
        }

        private string formatConfigHeading1(string[] headings, int lineLength, int numBordersTop, int numBordersBottom)
        {
            string s = "";
            string border = "";
            List<string> msgLines = new List<string>();
            int curStart = 0;
            string curLine = "";

            // Create the border lines
            for (int i = 0; i < lineLength; i++)
            {
                border += "-";
            }

            // Create the message lines
            for (int i = 0; i < headings.Length; i++)
            {
                curLine = "";
                // Determine where the message should be placed
                curStart = lineLength / 2 - headings[i].Length / 2;

                // Add preceding dashes
                for (int j = 0; j < curStart; j++)
                {
                    curLine += "-";
                }

                // Add message
                curLine += headings[i];

                // Add suffix dashes
                while (curLine.Length < lineLength)
                {
                    curLine += "-";
                }

                msgLines.Add(curLine);
            }

            // Construct the final string
            for (int i = 0; i < numBordersTop; i++)
            {
                if (s != "")
                {
                    s += System.Environment.NewLine;
                }

                s += border;
            }
            for (int i = 0; i < msgLines.Count; i++)
            {
                if (s != "")
                {
                    s += System.Environment.NewLine;
                }

                s += msgLines[i];
            }
            for (int i = 0; i < numBordersBottom; i++)
            {
                if (s != "")
                {
                    s += System.Environment.NewLine;
                }

                s += border;
            }

            return s;
        }

        private string formatConfigHeading2(string heading, int lineLength)
        {
            string s = "";
            string border = "";
            string msgLine = "";
            int msgStart = 0;

            // Create the border lines
            for (int i = 0; i < lineLength; i++)
            {
                border += "-";
            }

            // Determine where the message should be placed
            msgStart = lineLength / 2 - heading.Length / 2;

            // Add preceding dashes
            for (int i = 0; i < msgStart; i++)
            {
                msgLine += "-";
            }

            // Add message
            msgLine += heading;

            // Add suffix dashes
            while (msgLine.Length < lineLength)
            {
                msgLine += "-";
            }

            s = border + System.Environment.NewLine + msgLine + System.Environment.NewLine + border;

            return s;
        }

        private string formatConfigHeading3(string heading, int numDashes)
        {
            string s = "";
            string b = "";

            for (int i = 0; i < numDashes; i++)
            {
                b += "-";
            }

            s = b + heading + b;

            return s;
        }

        private string formatVariable(string variable, object value)
        {
            string s = null;

            if (value == null)
            {
                return null;
            }

            if (value is Color)
            {
                if (configVars[variable] != null)
                {
                    Color c = (Color)value;
                    s = variable + " = " + formatColor(c);
                }
            }
            else if (value is string)
            {
                s = variable + " = \"" + value + "\"";
            }
            else
            {
                s = variable + " = " + value.ToString().ToLower();
            }

            return s;
        }

        private string formatColor(Color c)
        {
            if (c.A == 255)
            {
                return "rgb(" + c.R + ", " + c.G + ", " + c.B + ")";
            }
            else
            {
                return "rgba(" + c.R + ", " + c.G + ", " + c.B + ", " + c.A + ")";
            }
        }

        private string formatEquipment(Equipment e)
        {
            return "equipment(\"" + e.primary + "\", \"" + e.secondary + "\", \"" + e.belt + "\", \"" + e.pack + "\", \"" + e.perk1 + "\", \"" + e.perk2 + "\")";
        }

        private string formatLoadout(Loadout l)
        {
            return "setLoadout(\"" + l.gameClass + "\", " + l.num + ", \"" + l.name + "\", " + formatEquipment(l.equipment) + ")";
        }

        private string formatCrosshairs(Crosshairs x)
        {
            return "crosshairs(\"" + x.standard + "\", \"" + x.zoomed + "\")";
        }

        private string formatCrosshairSetting(CrosshairSetting xs)
        {
            return "setCrosshairs(\"" + xs.gameClass + "\", \"" + xs.weapon + "\", " + formatCrosshairs(xs.crosshairs) + ")";
        }

        private string formatMutePlayer(MutedPlayer m)
        {
            return "mutePlayer(mplayer_custom(\"" + m.username + "\", " + m.muteVGS.ToString().ToLower() + ", " + m.muteText.ToString().ToLower() + ", " + m.muteDirectMessages.ToString().ToLower() + "))";
        }

        private string formatProjectile(Projectile proj)
        {
            return "getProjectile(\"" + proj.gameClass + "\", \"" + proj.weapon + "\")";
        }

        private string formatProjectileSetting(ProjectileSetting setting)
        {
            return "setProjectileColor(" + formatProjectile(setting.projectile) + ", " + formatColor(setting.color) + ", " + setting.intensity.ToString().ToLower() + ")";
        }

        private string formatProjectileSwap(ProjectileSwap swap)
        {
            if (swap.swapProjectile.isClone)
            {
                return "setProjectile(\"" + swap.projectile.gameClass + "\", \"" + swap.projectile.weapon + "\", cloneProjectile(" + formatProjectile(swap.swapProjectile) + "))";
            }
            else
            {
                return "setProjectile(\"" + swap.projectile.gameClass + "\", \"" + swap.projectile.weapon + "\", " + formatProjectile(swap.swapProjectile) + ")";
            }
        }

        // Save the current config to the file, returning success
        public bool saveConfig()
        {
            try
            {

                List<string> flines = new List<string>();

                flines.AddRange(formatGetStringLines(formatConfigHeading1(new string[] { "TAMods Lua Configuration Script",
                                                                                          "Generated by TAMods Configuration Tool "+ configVersion }, 60, 0, 2)));
                flines.Add("");
                flines.Add("");

                // Write ConfigPreset (if any)
                if (configPreset != null)
                {
                    flines.Add(formatConfigHeading2("Config Preset", 40));
                    flines.Add(String.Format("require(\"{0}\")", configPreset));
                }

                // Write ConfigVars
                flines.AddRange(formatGetStringLines(formatConfigHeading2("Config Variables", 40)));

                // Get checklist of vars to write
                Dictionary<string, bool> configVarHasBeenDone = new Dictionary<string, bool>();
                foreach (string variable in configVars.Keys)
                {
                    configVarHasBeenDone[variable] = false;
                }

                // Write out each variable section
                foreach (string section in configVarSections.Keys)
                {
                    flines.Add("");
                    flines.Add(formatConfigHeading3(section, 3));
                    foreach (string variable in configVarSections[section])
                    {
                        if (!configVarHasBeenDone[variable])
                        {
                            object value = getConfigVar(variable);
                            string tmp = formatVariable(variable, value);
                            if (tmp != null) flines.Add(tmp);

                            configVarHasBeenDone[variable] = true;
                        }
                    }
                }

                // Write out any leftover (non-sectioned) variables

                flines.Add("");
                flines.Add(formatConfigHeading3("Miscellaneous", 3));
                foreach (string variable in configVars.Keys)
                {
                    if (!configVarHasBeenDone[variable])
                    {
                        object value = getConfigVar(variable);
                        string tmp = formatVariable(variable, value);
                        if (tmp != null) flines.Add(tmp);
                    }


                }

                // Custom Loadouts
                flines.Add("");
                flines.AddRange(formatGetStringLines(formatConfigHeading2("Custom Loadouts", 40)));
                flines.Add("");

                foreach (Loadout l in configLoadouts)
                {
                    flines.Add(formatLoadout(l));
                }

                // Custom Crosshairs
                flines.Add("");
                flines.AddRange(formatGetStringLines(formatConfigHeading2("Global Crosshair Settings", 40)));
                flines.Add("");
                foreach (CrosshairSetting c in configCrosshairs)
                {
                    flines.Add(formatCrosshairSetting(c));
                }

                // Global Mutes
                flines.Add("");
                flines.AddRange(formatGetStringLines(formatConfigHeading2("Globally Muted Players", 40)));
                flines.Add("");
                foreach (MutedPlayer player in configMutedPlayers)
                {
                    flines.Add(formatMutePlayer(player));
                }

                // Projectile Swaps
                flines.Add("");
                flines.AddRange(formatGetStringLines(formatConfigHeading2("Projectile Swaps", 40)));
                foreach (ProjectileSwap swap in configProjectileSwaps)
                {
                    flines.Add(formatProjectileSwap(swap));
                }

                // Projectile Settings
                flines.Add("");
                flines.AddRange(formatGetStringLines(formatConfigHeading2("Modified Projectiles", 40)));
                foreach (ProjectileSetting setting in configProjectileSettings)
                {
                    flines.Add(formatProjectileSetting(setting));
                }

                // Save custom asset files
                foreach (string key in assetFiles.Keys)
                {
                    // If in a subdirectory, make sure the subdirectory exists
                    if (key.Contains('\\'))
                    {
                        string[] dirpath = key.Split('\\');
                        string builtpath = "";
                        for (int i = 0; i < dirpath.Length - 1; i++)
                        {
                            builtpath += dirpath[i];
                            if (!Directory.Exists(configPath + builtpath))
                            {
                                Directory.CreateDirectory(configPath + builtpath);
                            }
                        }
                    }

                    // Delete file if not required
                    if (assetFiles[key] == null)
                    {
                        if (File.Exists(configPath + key))
                        {
                            System.IO.File.Delete(configPath + key);
                        }
                    }

                    // Only save if the file is needed and isn't already there
                    if (assetFiles[key] != null && assetFiles[key] != configPath + key && assetFiles[key].Trim() != "")
                    {
                        File.Copy(assetFiles[key], configPath + key, true);
                    }
                }

                // Overwrite if required
                if (File.Exists(configPath + configFile))
                {
                    File.Delete(configPath + configFile);
                }

                File.WriteAllLines(configPath + configFile, flines.ToArray());
            }
            catch (IOException)
            {
                return false;
            }

            return true;
        }

        public bool saveConfig_NoSections()
        {
            try
            {

                List<string> flines = new List<string>();

                flines.Add("----------TAMod Lua Configuration Script----------");
                flines.Add("------Generated by TAMod Configuration Tool " + configVersion + "--");
                flines.Add("--------------------------------------------------");
                flines.Add("");


                // Write ConfigVars
                flines.Add("--Config Variables");
                foreach (string variable in configVars.Keys)
                {
                    object value = getConfigVar(variable);

                    if (value != null)
                    {
                        if (value is Color)
                        {
                            if (configVars[variable] != null)
                            {
                                Color c = (Color)value;
                                flines.Add(variable + " = " + formatColor(c));
                            }
                        }
                        else if (value is string)
                        {
                            flines.Add(variable + " = \"" + value + "\"");
                        }
                        else
                        {
                            flines.Add(variable + " = " + value.ToString().ToLower());
                        }
                    }
                }

                // Custom Loadouts
                flines.Add("");
                flines.Add("--Custom Loadouts");

                foreach (Loadout l in configLoadouts)
                {
                    flines.Add(formatLoadout(l));
                }

                // Custom Crosshairs
                flines.Add("");
                flines.Add("--Custom Crosshair Settings");
                foreach (CrosshairSetting c in configCrosshairs)
                {
                    flines.Add(formatCrosshairSetting(c));
                }

                // Global Mutes
                flines.Add("");
                flines.Add("--Globally Muted Players");
                foreach (MutedPlayer player in configMutedPlayers)
                {
                    flines.Add(formatMutePlayer(player));
                }

                // Projectile Swaps
                flines.Add("");
                flines.Add("--Projectile Swaps");
                foreach (ProjectileSwap swap in configProjectileSwaps)
                {
                    flines.Add(formatProjectileSwap(swap));
                }

                // Projectile Settings
                flines.Add("");
                flines.Add("--Modified Projectiles");
                foreach (ProjectileSetting setting in configProjectileSettings)
                {
                    flines.Add(formatProjectileSetting(setting));
                }

                // Save custom asset files
                foreach (string key in assetFiles.Keys)
                {
                    // If in a subdirectory, make sure the subdirectory exists
                    if (key.Contains('\\'))
                    {
                        string[] dirpath = key.Split('\\');
                        string builtpath = "";
                        for (int i = 0; i < dirpath.Length - 1; i++)
                        {
                            builtpath += dirpath[i];
                            if (!Directory.Exists(configPath + builtpath))
                            {
                                Directory.CreateDirectory(configPath + builtpath);
                            }
                        }
                    }

                    // Delete file if not required
                    if (assetFiles[key] == null)
                    {
                        if (File.Exists(configPath + key))
                        {
                            System.IO.File.Delete(configPath + key);
                        }
                    }

                    // Only save if the file is needed and isn't already there
                    if (assetFiles[key] != null && assetFiles[key] != configPath + key && assetFiles[key].Trim() != "")
                    {
                        File.Copy(assetFiles[key], configPath + key, true);
                    }
                }

                // Overwrite if required
                if (File.Exists(configPath + configFile))
                {
                    File.Delete(configPath + configFile);
                }

                File.WriteAllLines(configPath + configFile, flines.ToArray());
            }
            catch (IOException)
            {
                return false;
            }

            return true;
        }

        // Set the current config preset
        public void setRequireFile(string file)
        {
            configPreset = file;
        }

        // Turn an RGBA value into a colour
        public Color rgba(byte r, byte g, byte b, byte a)
        {
            return Color.FromArgb(a, r, g, b);
        }

        // Turn an RGB value into a colour
        public Color rgb(byte r, byte g, byte b)
        {
            return rgba(r, g, b, 255);
        }

        public Crosshairs crosshair(string xhair)
        {
            return Crosshairs.create(xhair);
        }

        public Crosshairs crosshairs(string xhair1, string xhair2)
        {
            return Crosshairs.create2(xhair1, xhair2);
        }

        public Equipment equipment(string primary, string secondary, string belt, string pack, string perk1, string perk2)
        {
            return Equipment.create(primary, secondary, belt, pack, perk1, perk2);
        }

        public bool setLoadout(string gameClass, int num, string name, Equipment equipment)
        {

            gameClass = getGameClassName(gameClass);

            configLoadouts.Add(new Loadout(gameClass, num, name, equipment));
            return true;
        }

        public bool setCrosshairs(string gameClass, string weapon, Crosshairs xhairs)
        {
            gameClass = getGameClassName(gameClass);

            configCrosshairs.Add(new CrosshairSetting(gameClass, weapon, xhairs));
            return true;
        }

        public bool mutePlayer(MutedPlayer player)
        {
            configMutedPlayers.Add(player);
            return true;
        }

        public Projectile getProjectile(string gameClass, string weapon)
        {
            gameClass = getGameClassName(gameClass);
            return Projectile.getProjectile(gameClass, weapon);
        }

        public Projectile cloneProjectile(Projectile projectile)
        {
            return Projectile.cloneProjectile(projectile);
        }

        public bool setProjectileColor(Projectile projectile, Color color, float intensity)
        {
            configProjectileSettings.Add(ProjectileSetting.setProjectileColor(projectile, color, intensity));
            return true;
        }

        public bool setProjectile(string gameClass, string weapon, Projectile swapProjectile)
        {
            gameClass = getGameClassName(gameClass);

            configProjectileSwaps.Add(ProjectileSwap.setProjectile(gameClass, weapon, swapProjectile));
            return true;
        }

        public string getGameClassName(string gameClass)
        {
            // Use regex to check if it's a known class
            if (Regex.IsMatch(gameClass, "(^(pathfinder|pth|path)$)", RegexOptions.IgnoreCase))
            {
                return "Pathfinder";
            }
            else if (Regex.IsMatch(gameClass, "(^(sentinel|sen)$)", RegexOptions.IgnoreCase))
            {
                return "Sentinel";
            }
            else if (Regex.IsMatch(gameClass, "(^(infiltrator|inf)$)", RegexOptions.IgnoreCase))
            {
                return "Infiltrator";
            }
            else if (Regex.IsMatch(gameClass, "(^(soldier|sld)$)", RegexOptions.IgnoreCase))
            {
                return "Soldier";
            }
            else if (Regex.IsMatch(gameClass, "(^(technician|tcn|tech)$)", RegexOptions.IgnoreCase))
            {
                return "Technician";
            }
            else if (Regex.IsMatch(gameClass, "(^(raider|rdr)$)", RegexOptions.IgnoreCase))
            {
                return "Raider";
            }
            else if (Regex.IsMatch(gameClass, "(^(juggernaut|juggernaught|jug|jugg)$)", RegexOptions.IgnoreCase))
            {
                return "Juggernaut";
            }
            else if (Regex.IsMatch(gameClass, "(^(doombringer|doom|dmb)$)", RegexOptions.IgnoreCase))
            {
                return "Doombringer";
            }
            else if (Regex.IsMatch(gameClass, "(^(brute|brt)$)", RegexOptions.IgnoreCase))
            {
                return "Brute";
            }

            return gameClass;
        }

    }

}