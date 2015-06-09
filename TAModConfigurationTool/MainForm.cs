using System;
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

namespace TAModConfigurationTool {
    public partial class MainForm : Form {

        Dictionary<string, Dictionary<string, List<string>>> loadoutDetails;
        Dictionary<string, Dictionary<string, List<string>>> loadoutRegex;
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

            listLoadouts.ClearSelected();
            listLoadouts.Items.Clear();


        }

        private void setUI()
        {
            // General settings
            // Display settings
            checkShowWeapon.Checked = (bool)configReader.getConfigVar("showWeapon");
            checkShowCrosshair.Checked = (bool)configReader.getConfigVar("showCrosshair");
            numCrosshairScale.Enabled = (bool)configReader.getConfigVar("showCrosshair");
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

            // Custom Chat Colours
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

            // Loadouts
            listLoadouts.ClearSelected();
            listLoadouts.Items.Clear();
            foreach (Loadout l in configReader.getConfigLoadouts())
            {
                listLoadouts.Items.Add(l);
            }

        }

        private void selectLoadoutClass_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateLoadoutSelectors(sender);
        }

        private void listLoadouts_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateLoadoutSelectors(sender);
        }

        private void selectLoadoutNumber_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateLoadoutSelectors(sender);
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
        private void updateLoadoutSelectors(object from)
        {
            string curClass = "";
            int curNumber = -1;
            if (from.Equals(listLoadouts))
            {
                if (listLoadouts.SelectedItem != null)
                {
                    curClass = ((Loadout)listLoadouts.SelectedItem).gameClass;
                    curNumber = ((Loadout)listLoadouts.SelectedItem).num;
                    selectLoadoutClass.SelectedItem = curClass;
                    selectLoadoutNumber.SelectedItem = curNumber.ToString();
                }
            }
            else
            {

                if (selectLoadoutClass.SelectedItem != null)
                {
                    curClass = (string)selectLoadoutClass.SelectedItem;
                }

                if (selectLoadoutNumber.SelectedItem != null)
                {
                    curNumber = Convert.ToInt32(selectLoadoutNumber.SelectedItem);
                }
            }
            
            selectLoadoutPrimary.Items.Clear();
            selectLoadoutSecondary.Items.Clear();
            selectLoadoutBelt.Items.Clear();
            selectLoadoutPack.Items.Clear();
            selectLoadoutPerk1.Items.Clear();
            selectLoadoutPerk2.Items.Clear();

            if (curClass == "" || curNumber == -1)
            {
                return;
            }

            selectLoadoutPrimary.Items.AddRange(loadoutDetails[curClass]["primary"].ToArray());
            selectLoadoutSecondary.Items.AddRange(loadoutDetails[curClass]["secondary"].ToArray());
            selectLoadoutBelt.Items.AddRange(loadoutDetails[curClass]["belt"].ToArray());
            selectLoadoutPack.Items.AddRange(loadoutDetails[curClass]["pack"].ToArray());
            selectLoadoutPerk1.Items.AddRange(loadoutDetails["all"]["perk1"].ToArray());
            selectLoadoutPerk2.Items.AddRange(loadoutDetails["all"]["perk2"].ToArray());

            Loadout lCompare = new Loadout(curClass, curNumber, "", null);

            foreach (Loadout l in listLoadouts.Items) 
            {
                if (l.Equals(lCompare))
                {
                    selectLoadoutPrimary.SelectedItem = findMatchingLoadoutItem(curClass, "primary", l.equipment.primary);
                    selectLoadoutSecondary.SelectedItem = findMatchingLoadoutItem(curClass, "secondary", l.equipment.secondary);
                    selectLoadoutBelt.SelectedItem = findMatchingLoadoutItem(curClass, "belt", l.equipment.belt);
                    selectLoadoutPack.SelectedItem = findMatchingLoadoutItem(curClass, "pack", l.equipment.pack);
                    selectLoadoutPerk1.SelectedItem = findMatchingLoadoutItem("all", "perk1", l.equipment.perk1);
                    selectLoadoutPerk2.SelectedItem = findMatchingLoadoutItem("all", "perk2", l.equipment.perk2);
                    textLoadoutName.Text = l.name;
                    break;
                }
            }
        }

        

        // Set up the dictionaries containing equipment data
        private void setupLoadouts()
        {
            loadoutDetails = new Dictionary<string, Dictionary<string, List<string>>>();
            loadoutRegex = new Dictionary<string, Dictionary<string, List<string>>>();

            loadoutDetails["Pathfinder"] = new Dictionary<string, List<string>>();
            loadoutRegex["Pathfinder"] = new Dictionary<string, List<string>>();
            loadoutDetails["Pathfinder"]["primary"] = new List<String> {"Light Spinfusor", "Bolt Launcher", "Dueling Spinfusor", "Light Twinfusor", "Blinksfusor"};
            loadoutRegex["Pathfinder"]["primary"] = new List<String> { "^(spin(fusor)?|light(spin)?(fusor)?)$", "^(bolt|boltlauncher)$", "^(duel|dueling|duelingspinfusor)$", "^(twin|twinfusor|lighttwinfusor)$", "^(blinks|blinksfusor)$" };
            loadoutDetails["Pathfinder"]["secondary"] = new List<string> { "Shotgun", "Holdout Shotgun", "Light Assault Rifle", "Shocklance" };
            loadoutRegex["Pathfinder"]["secondary"] = new List<String> { "^(shotgun)$", "^(holdoutshotgun|holdout)$", "^(lightassaultrifle|lar|ar|assaultrifle|rifle)$", "^(shocklance)$" };
            loadoutDetails["Pathfinder"]["belt"] = new List<string> { "Impact Nitrons", "Explosive Nitrons", "Compact Nitrons" };
            loadoutRegex["Pathfinder"]["belt"] = new List<string> { "^(nitrons?|impactnitrons?|impacts?)$", "^(explosivenitrons?|explosives?)$", "^(compactnitrons?|compacts?)$" };
            loadoutDetails["Pathfinder"]["pack"] = new List<string> { "Energy Recharge", "Thrust Pack" };
            loadoutRegex["Pathfinder"]["pack"] = new List<string> { "^(energyrecharge|energy)$", "^(thrustpack|thrust)$" };

            loadoutDetails["Sentinel"] = new Dictionary<string, List<string>>();
            loadoutRegex["Sentinel"] = new Dictionary<string, List<string>>();
            loadoutDetails["Sentinel"]["primary"] = new List<string> { "BXT1 Rifle", "BXT1A Rifle", "Phase rifle", "SAP20 Rifle" };
            loadoutRegex["Sentinel"]["primary"] = new List<string> { "^(bxt|bxt1|bxt1rifle)$", "^(bxt1a|bxt1-a|bxt1-arifle|bxt1arifle)$", "^(phase|phaserifle)$", "^(sap20(sniper)?(rifle)?)$" };
            loadoutDetails["Sentinel"]["secondary"] = new List<string> { "Nova Blaster", "Nova Blaster MX", "Falcon", "Accurized Shotgun", "Shocklance" };
            loadoutRegex["Sentinel"]["secondary"] = new List<string> { "^(nova|blaster|novablaster)$", "^(falcon)$", "^(mx|novablastermx|novamx|blastermx)$", "^(shotgun|accurizedshotgun)$", "^(shocklance)$" };
            loadoutDetails["Sentinel"]["belt"] = new List<string> { "Claymore Mines", "Focused Claymores", "T5 Grenades", "Motion Mines" };
            loadoutRegex["Sentinel"]["belt"] = new List<string> { "^(claymores?|claymoremines?)$", "^(focusedclaymores?|focusedclaymoremines?)$", "^(t5s?|grenades?|t5grenades?)$", "^(motionmines?|motions?|mines?)$" };
            loadoutDetails["Sentinel"]["pack"] = new List<string> { "Drop Jammer", "Energy Recharge" };
            loadoutRegex["Sentinel"]["pack"] = new List<string> { "^(dropjammer|jammer|jammerpack)$", "^(energypack|energyrecharge|energy)$" };

            loadoutDetails["Infiltrator"] = new Dictionary<string, List<string>>();
            loadoutRegex["Infiltrator"] = new Dictionary<string, List<string>>();
            loadoutDetails["Infiltrator"]["primary"] = new List<string> { "Rhino SMG", "Stealth Spinfusor", "Jackal", "Arctic Rhino SMG" };
            loadoutRegex["Infiltrator"]["primary"] = new List<string> { "^(rhinosmg|smg|rhino)$", "^(stealthspinfusor|spinfusor|spin|stealth)$", "^(jackal)$", "^(arcticrhinosmg|arcticrhino|arcticsmg)$" };
            loadoutDetails["Infiltrator"]["secondary"] = new List<string> { "SN7 Silenced Pistol", "Throwing Knives", "Arctic SN7 Silenced Pistol", "Shocklance" };
            loadoutRegex["Infiltrator"]["secondary"] = new List<string> { "^(sn7silencedpistol|sn7|pistol)$", "^(throwingknives|knives)$", "^(arcticsn7silencedpistol|arcticsn7|arcticpistol)$", "^(shocklance)$" };
            loadoutDetails["Infiltrator"]["belt"] = new List<string> { "Sticky Grenades", "Sticky Grenades XL", "Prism Mines", "Smoke Grenades" };
            loadoutRegex["Infiltrator"]["belt"] = new List<string> { "^(stickygrenades?|sticky|stickies)$", "^(stickygrenades?xl|stickyxls?|stickiesxl)$", "^(prismmines?|mines?)$", "^(smokegrenades?|smokes?" };
            loadoutDetails["Infiltrator"]["pack"] = new List<string> { "Stealth Pack" };
            loadoutRegex["Infiltrator"]["pack"] = new List<string> { "^(stealthpack|stealth)$" };

            loadoutDetails["Soldier"] = new Dictionary<string, List<string>>();
            loadoutRegex["Soldier"] = new Dictionary<string, List<string>>();
            loadoutDetails["Soldier"]["primary"] = new List<string> { "Assault Rifle", "Gast's Rifle", "Spinfusor", "Twinfusor" };
            loadoutRegex["Soldier"]["primary"] = new List<string> { "^(assaultrifle|rifle|ar)$", "^(gast'srifle|gast|gastrifle)$", "^(spinfusor|spin)$", "^(twinfusor)$" };
            loadoutDetails["Soldier"]["secondary"] = new List<string> { "Thumper D", "Thumper DX", "Spare Spinfusor", "Eagle Pistol", "Shocklance" };
            loadoutRegex["Soldier"]["secondary"] = new List<string> { "^(thumper|thumperd)$", "^(thumperdx)$", "^(sparespinfusor|sparespin|spin|spinfusor)$", "^(eaglepistol|eagle|pistol)$", "^(shocklance)$" };
            loadoutDetails["Soldier"]["belt"] = new List<string> { "Frag Grenades XL", "AP Grenades", "Proxies", "Short-fuse Frag Grenades" };
            loadoutRegex["Soldier"]["belt"] = new List<string> { "^(fraggrenades?(xl)?|frag(xl)?|grenades?(xl)?)$", "^(anti-?personnelgrenades?|aps?|apgrenades?)$", "^(proxmitys?(grenades?)?|proxies|proxys?)$", "^(short-?fusefraggrenades?|short-?fuses?)$" };
            loadoutDetails["Soldier"]["pack"] = new List<string> { "Energy Pack", "Utility Pack" };
            loadoutRegex["Soldier"]["pack"] = new List<string> { "^(energypack|energy)$", "^(utilitypack|utility)$" };

            loadoutDetails["Raider"] = new Dictionary<string, List<string>>();
            loadoutRegex["Raider"] = new Dictionary<string, List<string>>();
            loadoutDetails["Raider"]["primary"] = new List<string> { "Arx Buster", "Dust Devil", "Grenade Launcher", "Plasma Gun" };
            loadoutRegex["Raider"]["primary"] = new List<string> { "^(arxbuster|arx)$", "^(dustdevil|dust|devil)$", "^(grenadelauncher|nadelauncher|launcher)$", "^(plasmagun|plasma)$" };
            loadoutDetails["Raider"]["secondary"] = new List<string> { "NJ4 SMG", "Desert NJ4 SMG", "NJ5-B SMG", "Shocklance" };
            loadoutRegex["Raider"]["secondary"] = new List<string> { "^(nj4smg|nj4)$", "^(desertnj4smg|desertnj4|desert)$", "^(nj5-?bsmg|nj5)$", "^(shocklance)$" };
            loadoutDetails["Raider"]["belt"] = new List<string> { "EMP Grenades", "EMP XLs", "Blackout Grenades", "Cluster Grenades" };
            loadoutRegex["Raider"]["belt"] = new List<string> { "^(emps?|empgrenades?)$", "^(emps?xls?|empgrenades?xls?)$", "^(blackouts?|blackoutgrenades?)$", "^(clustergrenades?|clusters?)$" };
            loadoutDetails["Raider"]["pack"] = new List<string> { "Shield Pack", "Jammer Pack" };
            loadoutRegex["Raider"]["pack"] = new List<string> { "^(shieldpack|shield)$", "^(jammerpack|jammer)$" };

            loadoutDetails["Technician"] = new Dictionary<string, List<string>>();
            loadoutRegex["Technician"] = new Dictionary<string, List<string>>();
            loadoutDetails["Technician"]["primary"] = new List<string> { "TCN4 SMG", "Rockwind SMG", "Thumper", "TC24" };
            loadoutRegex["Technician"]["primary"] = new List<string> { "^(tcn4smg|tcn4)$", "^(tcn4rockwindsmg|rockwind|rockwindsmg|tcn4rockwind)$", "^(thumper)$", "^(tc24)$" };
            loadoutDetails["Technician"]["secondary"] = new List<string> { "Improved Repair Tool", "Long Range Repair Tool", "Sawed-off Shotgun", "Sparrow", "Shocklance" };
            loadoutRegex["Technician"]["secondary"] = new List<string> { "^(improvedrepairtool|repairtool|repair)$", "^(longrangerepairtool|longrange(repair|tool)?)$", "^(sawed-?offshotgun|shotgun|sawed-?off)$", "^(sparrow)$", "^(shocklance)$" };
            loadoutDetails["Technician"]["belt"] = new List<string> { "TCNGs", "TCNG Quickfuses", "Motion Sensors", "Repair Kits" };
            loadoutRegex["Technician"]["belt"] = new List<string> { "^(tcngs?|grenades?)$", "^(tcngs?quickfuses?|quickfuses?)$", "^(motionsensors?|sensors?)$", "^(repairkits?|repair|kits?)$" };
            loadoutDetails["Technician"]["pack"] = new List<string> { "Light Turret", "EXR Turret" };
            loadoutRegex["Technician"]["pack"] = new List<string> { "^(turrets?|lightturrets?)$", "^(exrs?|exrturrets?)$" };

            loadoutDetails["Juggernaut"] = new Dictionary<string, List<string>>();
            loadoutRegex["Juggernaut"] = new Dictionary<string, List<string>>();
            loadoutDetails["Juggernaut"]["primary"] = new List<string> { "Fusion Mortar", "Fusion Mortar Deluxe", "MIRV Launcher" };
            loadoutRegex["Juggernaut"]["primary"] = new List<string> { "^(fusionmortar|mortar)$", "^((fusion)?(mortar)?deluxe)$", "^(mirvlauncher|mirv)$" };
            loadoutDetails["Juggernaut"]["secondary"] = new List<string> { "Spinfusor MKD", "Spinfusor MK-X", "X1 LMG", "Heavy Twinfusor", "Shocklance" };
            loadoutRegex["Juggernaut"]["secondary"] = new List<string> { "^(spin(fusor)?|spin(fusor)?mkd|(fusor)?mkd)$", "^((spin)?(fusor)?mk-?x)$", "^(x1|lmg|x1lmg)$", "^(heavytwinfusor|twinfusor|twin)$", "^(shocklance)$" };
            loadoutDetails["Juggernaut"]["belt"] = new List<string> { "Heavy AP Grenades", "Heavy AP Grenades XL", "Spinfusor Disks" };
            loadoutRegex["Juggernaut"]["belt"] = new List<string> { "^(heavyaps?grenades?|grenades?|heavyaps?|aps?)$", "^(xls?|heavy(aps?)?(grenades?)?xl|aps?xl|heavyxls?)$", "^(spinfusordisks?|spins?|disks?|discs?|spindisks?|throwingdisks?)$" };
            loadoutDetails["Juggernaut"]["pack"] = new List<string> { "Health Regen Pack" };
            loadoutRegex["Juggernaut"]["pack"] = new List<string> { "^(healthregenpack|healthpack|health|regenpack|regen)$" };

            loadoutDetails["Doombringer"] = new Dictionary<string, List<string>>();
            loadoutRegex["Doombringer"] = new Dictionary<string, List<string>>();
            loadoutDetails["Doombringer"]["primary"] = new List<string> { "Chaingun", "Chain Cannon", "Heavy Bolt Launcher" };
            loadoutRegex["Doombringer"]["primary"] = new List<string> { "^(chaingun)$", "^(chaincannon)$", "^(heavyboltlauncher|boltlauncher|bolt)$" };
            loadoutDetails["Doombringer"]["secondary"] = new List<string> { "Saber Launcher", "Titan Launcher", "Shocklance" };
            loadoutRegex["Doombringer"]["secondary"] = new List<string> { "^(saberlauncher|saber)$", "^(titanlauncher|titan)$", "^(shocklance)$" };
            loadoutDetails["Doombringer"]["belt"] = new List<string> { "Frag Grenades", "Mines", "Defective Frags" };
            loadoutRegex["Doombringer"]["belt"] = new List<string> { "^(fraggrenades?|frags?)$", "^(mines?)$", "^(defectivefraggrenades?|defectivefrags?|defectivegrenades?)$" };
            loadoutDetails["Doombringer"]["pack"] = new List<string> { "Forcefield" };
            loadoutRegex["Doombringer"]["pack"] = new List<string> { "^(forcefield|shield|energyfield)$" };

            loadoutDetails["Brute"] = new Dictionary<string, List<string>>();
            loadoutRegex["Brute"] = new Dictionary<string, List<string>>();
            loadoutDetails["Brute"]["primary"] = new List<string> { "Heavy Spinfusor", "Devastator Spinfusor", "Gladiator" };
            loadoutRegex["Brute"]["primary"] = new List<string> { "^(heavy(spin)?(fusor)?|spin(fusor)?|fusor)$", "^(devastator|devastatorspin(fusor)?|dev|devspin)$", "^(gladiator)$" };
            loadoutDetails["Brute"]["secondary"] = new List<string> { "Automatic Shotgun", "The Hammer", "Nova Colt", "Plasma Cannon", "Shocklance" };
            loadoutRegex["Brute"]["secondary"] = new List<string> { "^(automaticshotgun|autoshotgun|shotgun)$", "^(thehammer|hammer)$", "^(novacolt|colt|nova)$", "^(plasmacannon|plasma)$", "^(shocklance)$" };
            loadoutDetails["Brute"]["belt"] = new List<string> { "Fractal Grenades", "Extended Fractal Grenades", "Heavy Sticky Grenades" };
            loadoutRegex["Brute"]["belt"] = new List<string> { "^(fractals?|fractalgrenades?)$", "^(extendedfractalgrenades?|extendedfractals?)$", "^(heavystickygrenades?|stickys?|stickies|heavystickys?|heavystickies)$" };
            loadoutDetails["Brute"]["pack"] = new List<string> { "Energy Pack", "Survival Pack", "Heavy Shield Pack" };
            loadoutRegex["Brute"]["pack"] = new List<string> { "^(energypack|energy)$", "^(survivalpack|survival)$", "^(heavyshieldpack|heavyshield|shieldpack|shield)$" };


            loadoutDetails["all"] = new Dictionary<string, List<string>>();
            loadoutRegex["all"] = new Dictionary<string, List<string>>();
            loadoutDetails["all"]["perk1"] = new List<string> { "Rage", "Ultra Capacitor 1", "Reach", "Safe Fall", "Wheel Deal", "Bounty Hunter", "Close Combat", "Looter", "Stealthy", "Safety Third" };
            loadoutRegex["all"]["perk1"] = new List<string> { "^(rage)$", "^(ultracapacitor[i1]?|capacitor)$", "^(reach)$", "^(safefall|fall|sf)$", "^(wheeldeal)$", "^(bountyhunter|bounty|hunter)$", "^(closecombat|cc)$", "^(looter)$", "^(stealthy)$", "^(safetythird|safety3rd|3rd|third)$" };
            loadoutDetails["all"]["perk2"] = new List<string> { "Sonic Punch", "Determination", "Egocentric", "Potential Energy", "Pilot", "Survivalist", "Superheavy", "Ultra Capacitor 2", "Quick Draw", "Mechanic", "Lightweight" };
            loadoutRegex["all"]["perk2"] = new List<string> { "^(sonicpunch|sonic|punch)$", "^(determination)$", "^(egocentric|ego)$", "^(potentialenergy|potential|pe)$", "^(pilot)$", "^(survivalist)$", "^(superheavy|heavy|sh)$", "^(ultracapacitor(2|ii)?|capacitor)$", "^(quickdraw|qd|draw)$", "^(mechanic)$", "^(lightweight|lw)$" };
        }

        private string findMatchingLoadoutItem(string gameClass, string slot, string item)
        {
            for (int i = 0; i < loadoutDetails[gameClass][slot.ToLower()].Count; i++)
            {
                if (Regex.IsMatch(item, loadoutRegex[gameClass][slot.ToLower()][i]))
                {
                    return loadoutDetails[gameClass][slot.ToLower()][i];
                }
            }

            return null;
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
            // Use regex to chack if it's a known class
            if (Regex.IsMatch(gameClass, "(^(pathfinder|pth|path)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Pathfinder";
            }
            else if (Regex.IsMatch(gameClass, "(^(sentinel|sen)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Sentinel";
            }
            else if (Regex.IsMatch(gameClass, "(^(infiltrator|inf)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Infiltrator";
            }
            else if (Regex.IsMatch(gameClass, "(^(soldier|sld)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Soldier";
            }
            else if (Regex.IsMatch(gameClass, "(^(technician|tcn|tech)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Technician";
            }
            else if (Regex.IsMatch(gameClass, "(^(raider|rdr)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Raider";
            }
            else if (Regex.IsMatch(gameClass, "(^(juggernaut|juggernaught|jug|jugg)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Juggernaut";
            }
            else if (Regex.IsMatch(gameClass, "(^(doombringer|doom|dmb)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Doombringer";
            }
            else if (Regex.IsMatch(gameClass, "(^(brute|brt)$)", RegexOptions.IgnoreCase))
            {
                gameClass = "Brute";
            }
            
            configLoadouts.Add(new Loadout(gameClass, num, name, equipment));
            return true;
        }

        public bool setCrosshairs(string gameClass, string weapon, Crosshairs xhairs)
        {
            //configCrosshairs.Add();
            return true;
        }

    }

    public class Loadout : IComparable<Loadout>
    {
        public readonly string gameClass;
        public readonly int num;
        public readonly string name;
        public readonly Equipment equipment;

        public Loadout(string gameClass, int num, string name, Equipment equipment)
        {
            this.gameClass = gameClass;
            this.num = num;
            this.name = name;
            this.equipment = equipment;
        }

        public override string ToString()
        {
            return gameClass + " #" + num;
        }

        public int CompareTo(Loadout other)
        {
            List<string> classOrder = new List<string>() { "pathfinder", "sentinel", "infiltrator", "soldier", "technician", "raider", "juggernaut", "doombringer", "brute" };
            // Sort by class first, then number
            if (other.gameClass == this.gameClass)
            {
                return this.num.CompareTo(other.num);
            }
            
            // If invalid gameClass, then just sort alphabetically
            if (!classOrder.Contains(this.gameClass) || !classOrder.Contains(other.gameClass)) {
                return this.gameClass.CompareTo(other.gameClass);
            }

            return (classOrder.IndexOf(this.gameClass) - classOrder.IndexOf(other.gameClass));
        }

        // Override Equals method so that loadouts with the same name/num are 'equal' (even if they have different equipment)
        public override bool Equals(object other)
        {
            // Return false if the other object cannot be cast to loadout
            Loadout lother = other as Loadout;
            if ((object)lother == null)
            {
                return false;
            }

            if (this.gameClass == lother.gameClass && this.num == lother.num) 
            {
                return true;
            }
            
            return false;
        }

        public override int GetHashCode()
        {
            return gameClass.GetHashCode() ^ num.GetHashCode();
        }
        

    }

    public class Equipment
    {

        public readonly string primary;
        public readonly string secondary;
        public readonly string belt;
        public readonly string pack;
        public readonly string perk1;
        public readonly string perk2;

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
