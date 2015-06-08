using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using NLua;

namespace TAModConfigurationTool {
    public partial class MainForm : Form {

        Dictionary<string, Dictionary<string, string[]>> loadoutDetails;
        ConfigReader configReader;

        public MainForm() {
            InitializeComponent();
            setupLoadouts();
            
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            loadConfigIntoUI();
        }

        // Load a config file into the UI (returns true on success
        private bool loadConfigIntoUI()
        {
            
            // Clear the UI Elements
            clearUI();

            // Load the config from profile
            string profile = Environment.GetEnvironmentVariable("USERPROFILE");
            string directory;

            if (profile == null) {
                directory = "C:\\";
            } else {
                directory = profile + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\";
            }

            configReader = new ConfigReader(directory, "config.lua");

            // Load in the config file
            if (!configReader.loadConfig())
            {
                return false;
            }

            // Set the UI elements based on the config
            setUI();
            

            return true;
        }

        private void clearUI()
        {
            // General settings
            // Display settings
            checkShowWeapon.Checked = true;
            checkShowCrosshair.Checked = true;
            numCrosshairScale.Enabled = true;
            numCrosshairScale.Value = 1;

            // Damage Number Settings
            // Damage Number Display
            radioDamageNumberShow.Checked = true;
            numDamageNumberLimit.Enabled = false;
            numDamageNumberLimit.Value = 0;
            numDamageNumberScale.Enabled = true;
            numDamageNumberScale.Value = 1;
            numDamageNumberXOffset.Enabled = true;
            numDamageNumberXOffset.Value = 0;
            numDamageNumberYOffset.Enabled = true;
            numDamageNumberYOffset.Value = 0;

            // Damage Number Streaming
            radioDamageNumberDiscrete.Checked = true;

            // Colour Settings
            // Custom Damage Number Colours
            radioDamageNumberColorDefault.Checked = true;
            numDamageNumberMinColorA.Enabled = false;
            numDamageNumberMinColorA.Value = 255;
            numDamageNumberMinColorR.Enabled = false;
            numDamageNumberMinColorR.Value = 255;
            numDamageNumberMinColorG.Enabled = false;
            numDamageNumberMinColorG.Value = 255;
            numDamageNumberMinColorB.Enabled = false;
            numDamageNumberMinColorB.Value = 255;
            numDamageNumberMaxColorA.Enabled = false;
            numDamageNumberMaxColorA.Value = 255;
            numDamageNumberMaxColorR.Enabled = false;
            numDamageNumberMaxColorR.Value = 248;
            numDamageNumberMaxColorG.Enabled = false;
            numDamageNumberMaxColorG.Value = 83;
            numDamageNumberMaxColorB.Enabled = false;
            numDamageNumberMaxColorB.Value = 83;
            // Custom chat colour settings
            radioChatColorDefault.Checked = true;
            numChatColorFriendlyA.Enabled = false;
            numChatColorFriendlyA.Value = 255;
            numChatColorFriendlyR.Enabled = false;
            numChatColorFriendlyR.Value = 158;
            numChatColorFriendlyG.Enabled = false;
            numChatColorFriendlyG.Value = 208;
            numChatColorFriendlyB.Enabled = false;
            numChatColorFriendlyB.Value = 212;
            numChatColorEnemyA.Enabled = false;
            numChatColorEnemyA.Value = 255;
            numChatColorEnemyR.Enabled = false;
            numChatColorEnemyR.Value = 225;
            numChatColorEnemyG.Enabled = false;
            numChatColorEnemyG.Value = 111;
            numChatColorEnemyB.Enabled = false;
            numChatColorEnemyB.Value = 111;
            numChatColorTeamA.Enabled = false;
            numChatColorTeamA.Value = 255;
            numChatColorTeamR.Enabled = false;
            numChatColorTeamR.Value = 199;
            numChatColorTeamG.Enabled = false;
            numChatColorTeamG.Value = 254;
            numChatColorTeamB.Enabled = false;
            numChatColorTeamB.Value = 218;
            numChatColorWhisperA.Enabled = false;
            numChatColorWhisperA.Value = 255;
            numChatColorWhisperR.Enabled = false;
            numChatColorWhisperR.Value = 207;
            numChatColorWhisperG.Enabled = false;
            numChatColorWhisperG.Value = 165;
            numChatColorWhisperB.Enabled = false;
            numChatColorWhisperB.Value = 101;


        }

        private void setUI()
        {
            // General settings
            // Display settings
            checkShowWeapon.Checked = (bool)configReader.getConfigVar("showWeapon");
            checkShowCrosshair.Checked = (bool)configReader.getConfigVar("showCrosshair");
            numCrosshairScale.Enabled = (bool)configReader.getConfigVar("showCrosshair");
            System.Diagnostics.Debug.WriteLine(configReader.getConfigVar("crosshairScale"));
            numCrosshairScale.Value = Convert.ToDecimal(configReader.getConfigVar("crosshairScale"));

            // Damage Number Settings
            // Damage Number Display
            numDamageNumberLimit.Value = 0;
            if (Convert.ToInt32(configReader.getConfigVar("damageNumbersLimit")) <= 0)
            {
                radioDamageNumberShow.Checked = true;
            }
            else if (Convert.ToInt32(configReader.getConfigVar("damageNumbersLimit")) < 10000)
            {
                radioDamageNumberLimit.Checked = true;
                numDamageNumberLimit.Value = Convert.ToInt32(configReader.getConfigVar("damageNumbersLimit"));
            }
            else
            {
                radioDamageNumberHide.Checked = true;
            }

            numDamageNumberScale.Value = Convert.ToDecimal(configReader.getConfigVar("damageNumbersScale"));
            numDamageNumberXOffset.Value = Convert.ToInt32(configReader.getConfigVar("damageNumbersOffsetX"));
            numDamageNumberYOffset.Value = Convert.ToInt32(configReader.getConfigVar("damageNumbersOffsetY"));

            // Damage Number Streaming
            if ((bool)configReader.getConfigVar("showChainBulletHitCount"))
            {
                radioDamageNumberCount.Checked = true;
            }
            else if ((bool)configReader.getConfigVar("showDamageNumberStream"))
            {
                radioDamageNumberStream.Checked = true;
            }
            else
            {
                radioDamageNumberDiscrete.Checked = true;
            }

            // Colour Settings
            Color c;
            // Custom Damage Number Colours
            radioDamageNumberColorDefault.Checked = true;
            if ((bool)configReader.getConfigVar("showRainbow"))
            {
                radioDamageNumberColorRainbow.Checked = true;
            }
            else if (configReader.configVarSet("damageNumbersColorMin") || configReader.configVarSet("damageNumbersColorMax"))
            {
                radioDamageNumberColorCustom.Checked = true;
            }
            c = (Color)configReader.getConfigVar("damageNumbersColorMin");
            numDamageNumberMinColorA.Value = c.A;
            numDamageNumberMinColorR.Value = c.R;
            numDamageNumberMinColorG.Value = c.G;
            numDamageNumberMinColorB.Value = c.B;
            c = (Color)configReader.getConfigVar("damageNumbersColorMax");
            numDamageNumberMaxColorA.Value = c.A;
            numDamageNumberMaxColorR.Value = c.R;
            numDamageNumberMaxColorG.Value = c.G;
            numDamageNumberMaxColorB.Value = c.B;

            radioChatColorDefault.Checked = true;
            if (configReader.configVarSet("friendlyChatColor") || configReader.configVarSet("enemyChatColor")
                || configReader.configVarSet("teamChatColor") || configReader.configVarSet("whisperChatColor"))
            {
                radioChatColorCustom.Checked = true;
            }

            c = (Color)configReader.getConfigVar("friendlyChatColor");
            numChatColorFriendlyA.Value = c.A;
            numChatColorFriendlyR.Value = c.R;
            numChatColorFriendlyG.Value = c.G;
            numChatColorFriendlyB.Value = c.B;
            c = (Color)configReader.getConfigVar("enemyChatColor");
            numChatColorEnemyA.Value = c.A;
            numChatColorEnemyR.Value = c.R;
            numChatColorEnemyG.Value = c.G;
            numChatColorEnemyB.Value = c.B;
            c = (Color)configReader.getConfigVar("teamChatColor");
            numChatColorTeamA.Value = c.A;
            numChatColorTeamR.Value = c.R;
            numChatColorTeamG.Value = c.G;
            numChatColorTeamB.Value = c.B;
            c = (Color)configReader.getConfigVar("whisperChatColor");
            numChatColorWhisperA.Value = c.A;
            numChatColorWhisperR.Value = c.R;
            numChatColorWhisperG.Value = c.G;
            numChatColorWhisperB.Value = c.B;
            
        }

        private void selectLoadoutClass_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateEquipmentSelectors();
        }

        // Set the colour pickers based on the RGBA values
        private void setColorBoxes()
        {
            boxDamageNumberMaxColor.BackColor = Color.FromArgb((int)numDamageNumberMaxColorA.Value, (int)numDamageNumberMaxColorR.Value, (int)numDamageNumberMaxColorG.Value, (int)numDamageNumberMaxColorB.Value);
            boxDamageNumberMinColor.BackColor = Color.FromArgb((int)numDamageNumberMinColorA.Value, (int)numDamageNumberMinColorR.Value, (int)numDamageNumberMinColorG.Value, (int)numDamageNumberMinColorB.Value); //Color.FromArgb((int)numDamageNumberMinColorA.Value, (int)numDamageNumberMinColorR.Value, (int)numDamageNumberMinColorG.Value, (int)numDamageNumberMinColorB.Value);
            boxChatColorFriendly.BackColor = Color.FromArgb((int)numChatColorFriendlyA.Value, (int)numChatColorFriendlyR.Value, (int)numChatColorFriendlyG.Value, (int)numChatColorFriendlyB.Value);
            boxChatColorEnemy.BackColor = Color.FromArgb((int)numChatColorEnemyA.Value, (int)numChatColorEnemyR.Value, (int)numChatColorEnemyG.Value, (int)numChatColorEnemyB.Value);
            boxChatColorTeam.BackColor = Color.FromArgb((int)numChatColorTeamA.Value, (int)numChatColorTeamR.Value, (int)numChatColorTeamG.Value, (int)numChatColorTeamB.Value);
            boxChatColorWhisper.BackColor = Color.FromArgb((int)numChatColorWhisperA.Value, (int)numChatColorWhisperR.Value, (int)numChatColorWhisperG.Value, (int)numChatColorWhisperB.Value);
        }

        // Colour change events
        private void numColor_changed(object sender, EventArgs e)
        {
            setColorBoxes();
        }


        // Update the dropdown lists for the equipment selection
        private void updateEquipmentSelectors()
        {
            string curClass = (string)selectLoadoutClass.SelectedItem;
            
            selectLoadoutPrimary.Items.Clear();
            selectLoadoutSecondary.Items.Clear();
            selectLoadoutBelt.Items.Clear();
            selectLoadoutPack.Items.Clear();
            selectLoadoutPerk1.Items.Clear();
            selectLoadoutPerk2.Items.Clear();

            selectLoadoutPrimary.Items.AddRange(loadoutDetails[curClass]["primary"]);
            selectLoadoutSecondary.Items.AddRange(loadoutDetails[curClass]["secondary"]);
            selectLoadoutBelt.Items.AddRange(loadoutDetails[curClass]["belt"]);
            selectLoadoutPack.Items.AddRange(loadoutDetails[curClass]["pack"]);
            selectLoadoutPerk1.Items.AddRange(loadoutDetails["all"]["perk1"]);
            selectLoadoutPerk2.Items.AddRange(loadoutDetails["all"]["perk2"]);
        }

        

        // Set up the dictionaries containing equipment data
        private void setupLoadouts()
        {
            loadoutDetails = new Dictionary<string, Dictionary<string, string[]>>();

            loadoutDetails["Pathfinder"] = new Dictionary<string, string[]>();
            loadoutDetails["Pathfinder"]["primary"] = new string[] {"Light Spinfusor", "Bolt Launcher", "Dueling Spinfusor", "Light Twinfusor", "Blinksfusor"};
            loadoutDetails["Pathfinder"]["secondary"] = new string[] { "Shotgun", "Holdout Shotgun", "Light Assault Rifle", "Shocklance" };
            loadoutDetails["Pathfinder"]["belt"] = new string[] { "Impact Nitrons", "Explosive Nitrons", "Compact Nitrons" };
            loadoutDetails["Pathfinder"]["pack"] = new string[] { "Energy Recharge", "Thrust Pack" };

            loadoutDetails["Sentinel"] = new Dictionary<string, string[]>();
            loadoutDetails["Sentinel"]["primary"] = new string[] { "BXT1 Rifle", "BXT1A Rifle", "Phase rifle", "SAP20 Rifle" };
            loadoutDetails["Sentinel"]["secondary"] = new string[] { "Nova Blaster", "Nova Blaster MX", "Falcon", "Accurized Shotgun", "Shocklance" };
            loadoutDetails["Sentinel"]["belt"] = new string[] { "Claymore Mines", "Focused Claymores", "T5 Grenades", "Motion Mines" };
            loadoutDetails["Sentinel"]["pack"] = new string[] { "Drop Jammer", "Energy Recharge" };

            loadoutDetails["Infiltrator"] = new Dictionary<string, string[]>();
            loadoutDetails["Infiltrator"]["primary"] = new string[] { "Rhino SMG", "Stealth Spinfusor", "Jackal", "Arctic Rhino SMG" };
            loadoutDetails["Infiltrator"]["secondary"] = new string[] { "SN7 Silenced Pistol", "Throwing Knives", "Arctic SN7 Silenced Pistol", "Shocklance" };
            loadoutDetails["Infiltrator"]["belt"] = new string[] { "Sticky Grenades", "Sticky Grenades XL", "Prism Mines", "Smoke Grenades" };
            loadoutDetails["Infiltrator"]["pack"] = new string[] { "Stealth Pack" };

            loadoutDetails["Soldier"] = new Dictionary<string, string[]>();
            loadoutDetails["Soldier"]["primary"] = new string[] { "Assault Rifle", "Gast's Rifle", "Spinfusor", "Twinfusor" };
            loadoutDetails["Soldier"]["secondary"] = new string[] { "Thumper D", "Thumper DX", "Spare Spinfusor", "Eagle Pistol", "Shocklance" };
            loadoutDetails["Soldier"]["belt"] = new string[] { "Frag Grenades XL", "AP Grenades", "Proxies", "Short-fuse Frag Grenades" };
            loadoutDetails["Soldier"]["pack"] = new string[] { "Energy Pack", "Utility Pack" };

            loadoutDetails["Technician"] = new Dictionary<string, string[]>();
            loadoutDetails["Technician"]["primary"] = new string[] { "Arx Buster", "Dust Devil", "Grenade Launcher", "Plasma Gun" };
            loadoutDetails["Technician"]["secondary"] = new string[] { "NJ4 SMG", "Desert NJ4 SMG", "NJ5-B SMG", "Shocklance" };
            loadoutDetails["Technician"]["belt"] = new string[] { "EMP Grenades", "EMP XLs", "Blackout Grenades", "Cluster Grenades" };
            loadoutDetails["Technician"]["pack"] = new string[] { "Shield Pack", "Jammer Pack" };

            loadoutDetails["Raider"] = new Dictionary<string, string[]>();
            loadoutDetails["Raider"]["primary"] = new string[] { "TCN4 SMG", "Rockwind SMG", "Thumper", "TC24" };
            loadoutDetails["Raider"]["secondary"] = new string[] { "Improved Repair Tool", "Long Range Repair Tool", "Sawed-off Shotgun", "Sparrow", "Shocklance" };
            loadoutDetails["Raider"]["belt"] = new string[] { "TCNGs", "TCNG Quickfuses", "Motion Sensors", "Repair Kits" };
            loadoutDetails["Raider"]["pack"] = new string[] { "Light Turret", "EXR Turret" };

            loadoutDetails["Juggernaut"] = new Dictionary<string, string[]>();
            loadoutDetails["Juggernaut"]["primary"] = new string[] { "Fusion Mortar", "Fusion Mortar Deluxe", "MIRV Launcher" };
            loadoutDetails["Juggernaut"]["secondary"] = new string[] { "Spinfusor MKD", "Spinfusor MK-X", "X1 LMG", "Heavy Twinfusor", "Shocklance" };
            loadoutDetails["Juggernaut"]["belt"] = new string[] { "Heavy AP Grenades", "Heavy AP Grenades XL", "Spinfusor Disks" };
            loadoutDetails["Juggernaut"]["pack"] = new string[] { "Health Regen Pack" };

            loadoutDetails["Doombringer"] = new Dictionary<string, string[]>();
            loadoutDetails["Doombringer"]["primary"] = new string[] { "Chaingun", "Chain Cannon", "Heavy Bolt Launcher" };
            loadoutDetails["Doombringer"]["secondary"] = new string[] { "Saber Launcher", "Titan Launcher", "Shocklance" };
            loadoutDetails["Doombringer"]["belt"] = new string[] { "Frag Grenades", "Mines", "Defective Frags" };
            loadoutDetails["Doombringer"]["pack"] = new string[] { "Forcefield" };

            loadoutDetails["Brute"] = new Dictionary<string, string[]>();
            loadoutDetails["Brute"]["primary"] = new string[] { "Heavy Spinfusor", "Devastator Spinfusor", "Gladiator" };
            loadoutDetails["Brute"]["secondary"] = new string[] { "Automatic Shotgun", "The Hammer", "Nova Colt", "Plasma Cannon", "Shocklance" };
            loadoutDetails["Brute"]["belt"] = new string[] { "Fractal Grenades", "Extended Fractal Grenades", "Heavy Sticky Grenades" };
            loadoutDetails["Brute"]["pack"] = new string[] { "Energy Pack", "Survival Pack", "Heavy Shield Pack" };

            loadoutDetails["all"] = new Dictionary<string, string[]>();
            loadoutDetails["all"]["perk1"] = new string[] { "Rage", "Ultra Capacitor 1", "Reach", "Safe Fall", "Wheel Deal", "Bounty Hunter", "Close Combat", "Looter", "Stealthy", "Safety Third" };
            loadoutDetails["all"]["perk2"] = new string[] { "Sonic Punch", "Determination", "Egocentric", "Potential Energy", "Pilot", "Survivalist", "Superheavy", "Ultra Capacitor 2", "Quick Draw", "Mechanic", "Lightweight" };
        }

        private void radioDamageNumberLimit_CheckedChanged(object sender, EventArgs e)
        {
            numDamageNumberLimit.Enabled = radioDamageNumberLimit.Checked;
        }

        private void radioDamageNumberHide_CheckedChanged(object sender, EventArgs e)
        {
            numDamageNumberScale.Enabled = !radioDamageNumberHide.Checked;
            numDamageNumberXOffset.Enabled = !radioDamageNumberHide.Checked;
            numDamageNumberYOffset.Enabled = !radioDamageNumberHide.Checked;
        }

        private void radioDamageNumberColorCustom_CheckedChanged(object sender, EventArgs e)
        {
            numDamageNumberMaxColorA.Enabled = radioDamageNumberColorCustom.Checked;
            numDamageNumberMaxColorR.Enabled = radioDamageNumberColorCustom.Checked;
            numDamageNumberMaxColorG.Enabled = radioDamageNumberColorCustom.Checked;
            numDamageNumberMaxColorB.Enabled = radioDamageNumberColorCustom.Checked;
            numDamageNumberMinColorA.Enabled = radioDamageNumberColorCustom.Checked;
            numDamageNumberMinColorR.Enabled = radioDamageNumberColorCustom.Checked;
            numDamageNumberMinColorG.Enabled = radioDamageNumberColorCustom.Checked;
            numDamageNumberMinColorB.Enabled = radioDamageNumberColorCustom.Checked;
        }

        private void radioChatColorCustom_CheckedChanged(object sender, EventArgs e)
        {
            numChatColorFriendlyA.Enabled = radioChatColorCustom.Checked;
            numChatColorFriendlyR.Enabled = radioChatColorCustom.Checked;
            numChatColorFriendlyG.Enabled = radioChatColorCustom.Checked;
            numChatColorFriendlyB.Enabled = radioChatColorCustom.Checked;
            numChatColorEnemyA.Enabled = radioChatColorCustom.Checked;
            numChatColorEnemyR.Enabled = radioChatColorCustom.Checked;
            numChatColorEnemyG.Enabled = radioChatColorCustom.Checked;
            numChatColorEnemyB.Enabled = radioChatColorCustom.Checked;
            numChatColorTeamA.Enabled = radioChatColorCustom.Checked;
            numChatColorTeamR.Enabled = radioChatColorCustom.Checked;
            numChatColorTeamG.Enabled = radioChatColorCustom.Checked;
            numChatColorTeamB.Enabled = radioChatColorCustom.Checked;
            numChatColorWhisperA.Enabled = radioChatColorCustom.Checked;
            numChatColorWhisperR.Enabled = radioChatColorCustom.Checked;
            numChatColorWhisperG.Enabled = radioChatColorCustom.Checked;
            numChatColorWhisperB.Enabled = radioChatColorCustom.Checked;
        }

        private void checkShowCrosshair_CheckedChanged(object sender, EventArgs e)
        {
            numCrosshairScale.Enabled = checkShowCrosshair.Checked;
        }
    }

    public class ConfigReader
    {
        private Lua lua;
        private string configPath;
        private string configFile;
        private Dictionary<string, Object> configVars;
        private Dictionary<string, Object> configVarsDefault;
        private List<Loadout> configLoadouts;
        private List<Crosshairs> configCrosshairs;

        public ConfigReader(string configPath, string configFilename)
        {
            lua = new Lua();
            // Register necessary functions to the script
            lua.RegisterFunction("rgb", this, this.GetType().GetMethod("rgb"));
            lua.RegisterFunction("rgba", this, this.GetType().GetMethod("rgba"));
            lua.RegisterFunction("crosshair", this, this.GetType().GetMethod("crosshair"));
            lua.RegisterFunction("crosshairs", this, this.GetType().GetMethod("crosshairs"));
            lua.RegisterFunction("equipment", this, this.GetType().GetMethod("equipment"));
            lua.RegisterFunction("setLoadout", this, this.GetType().GetMethod("setLoadout"));
            lua.RegisterFunction("setCrosshairs", this, this.GetType().GetMethod("setCrosshairs"));
            

            this.configPath = configPath;
            this.configFile = configFilename;
            setupConfigVarDict();
            configLoadouts = new List<Loadout>();
            configCrosshairs = new List<Crosshairs>();
        }

        // Constructor puts the config path in the root of the C: drive if no path is given
        public ConfigReader() : this("C:\\", "config.lua") {}

        public void setConfigPath(string configPath)
        {
            this.configPath = configPath;
        }

        // Setup the keys for all known config variables
        private void setupConfigVarDict()
        {
            configVars = new Dictionary<String, Object>()
            {
                { "showErrorNotifications", null },
                { "showWeapon", null },
                { "showCrosshair", null },
                { "crosshairScale", null },

                { "damageNumbersLimit", null },
                { "showDamageNumberStream", null },
                { "showChainBulletHitCount", null },
                { "damageNumberStreamTimeout", null },
                { "damageNumbersOffsetX", null },
                { "damageNumbersOffsetY", null },
                { "damageNumbersScale", null },

                { "showRainbow", null },
                { "damageNumbersColorMin", null },
                { "damageNumbersColorMax", null },
                { "friendlyChatColor", null },
                { "enemyChatColor", null },
                { "teamChatColor", null },
                { "whisperChatColor", null }
            };

            configVarsDefault = new Dictionary<String, Object>()
            {
                { "showErrorNotifications", true },
                { "showWeapon", true },
                { "showCrosshair", true },
                { "crosshairScale", 1 },

                { "damageNumbersLimit", 0 },
                { "showDamageNumberStream", false },
                { "showChainBulletHitCount", false },
                { "damageNumberStreamTimeout", 0.5 },
                { "damageNumbersOffsetX", 0 },
                { "damageNumbersOffsetY", 0 },
                { "damageNumbersScale", 1 },

                { "showRainbow", false },
                { "damageNumbersColorMin", rgb(255, 255, 255) },
                { "damageNumbersColorMax", rgb(248, 83, 83) },
                { "friendlyChatColor", rgb(158, 208, 212) },
                { "enemyChatColor", rgb(255, 111, 111) },
                { "teamChatColor", rgb(199, 254, 218) },
                { "whisperChatColor", rgb(207, 165, 101) }
            };
        }

        // Clear all loaded config variables
        public void clearConfig()
        {
            setupConfigVarDict();
        }

        // Load config variables from the file, returning success
        public bool loadConfig()
        {

            try
            {
                lua.DoFile(configPath + configFile);
            }
            catch (NLua.Exceptions.LuaException e)
            {
                return false;
            }

            List<string> configKeys = new List<String>();

            foreach (string key in configVars.Keys)
            {
                configKeys.Add(key);
            }
            
            foreach (string key in configKeys)
            {
                loadConfigVar(key);
            }

            return true;
        }

        private void loadConfigVar(string variableName)
        {
            configVars[variableName] = lua[variableName];
        }

        // Checks if a config variable has been set
        public bool configVarSet(string variableName)
        {
            if (!configVars.ContainsKey(variableName))
            {
                return false;
            }

            if (configVars[variableName] == null)
            {
                return false;
            }

            return true;
        }

        public Object getConfigVar(string variableName)
        {
            if (configVars.ContainsKey(variableName))
            {
                if (configVars[variableName] == null) {
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

        public List<Loadout> getConfigLoadouts()
        {
            // Make a deep copy of the config loadouts list
            List<Loadout> cp = new List<Loadout>();
            foreach (Loadout l in configLoadouts)
            {
                cp.Add(l);
            }
            return cp;
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
            configLoadouts.Add(new Loadout(gameClass, num, name, equipment));
            return true;
        }

        public bool setCrosshairs(string gameClass, string weapon, Crosshairs xhairs)
        {
            //configCrosshairs.Add();
            return true;
        }

    }

    public class Loadout
    {
        public string gameClass;
        public int num;
        public string name;
        public Equipment equipment;

        public Loadout(string gameClass, int num, string name, Equipment equipment)
        {
            this.gameClass = gameClass;
            this.num = num;
            this.name = name;
            this.equipment = equipment;
        }
    }

    public class Equipment
    {

        public string primary;
        public string secondary;
        public string belt;
        public string pack;
        public string perk1;
        public string perk2;

        public Equipment(string primary, string secondary, string belt, string pack, string perk1, string perk2)
        {
            this.primary = primary;
            this.secondary = secondary;
            this.belt = belt;
            this.pack = pack;
            this.perk1 = perk1;
            this.perk2 = perk2;
        }

        public static Equipment create(string primary, string secondary, string belt, string pack, string perk1, string perk2)
        {
            return new Equipment(primary, secondary, belt, pack, perk1, perk2);
        }

    }

    public class Crosshairs
    {

        public string standard;
        public string zoomed;

        public Crosshairs(string standard, string zoomed)
        {
            this.standard = standard;
            this.zoomed = zoomed;
        }


        public static Crosshairs create2(string xhair1, string xhair2)
        {
            return new Crosshairs(xhair1, xhair2);
        }

        public static Crosshairs create(string xhair)
        {
            return Crosshairs.create2(xhair, xhair);
        }

    }

}
