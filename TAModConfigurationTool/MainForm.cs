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
    public partial class MainForm : Form
    {

        public Dictionary<string, Dictionary<string, List<string>>> loadoutDetails;
        public Dictionary<string, Dictionary<string, List<string>>> loadoutRegex;
        public Dictionary<string, string> colorSettingVars;
        public List<string> crosshairDetails;
        public List<string> crosshairRegex;
        public Config config;

        public MainForm()
        {
            // Use '.' instead of ',' for floating point numbers
            System.Globalization.CultureInfo customCulture = (System.Globalization.CultureInfo)System.Threading.Thread.CurrentThread.CurrentCulture.Clone();
            customCulture.NumberFormat.NumberDecimalSeparator = ".";
            System.Threading.Thread.CurrentThread.CurrentCulture = customCulture;

            InitializeComponent();
            setupLoadouts();
            setupColorSettingVars();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            loadConfigIntoUI();
            colorColorSettings.ColorUpdated += new EventHandler(colorColorSettings_ColorUpdated);
        }

        // Load a config file into the UI (returns true on success
        private bool loadConfigIntoUI()
        {

            // Clear the UI Elements
            clearUI();

            // Load the config from profile
            string profile = Environment.GetEnvironmentVariable("USERPROFILE");
            string directory;

            if (profile == null)
            {
                directory = "C:\\";
            }
            else
            {
                directory = profile + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\";
            }

            config = new Config(directory, "config.lua");

            // Set title text to current config version
            this.Text = "TAMods Configuration Tool " + config.configVersion;

            // Load in the config file
            if (!config.loadConfig())
            {
                MessageBox.Show("Error reading configuration file!", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
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
            checkStatsRecord.Checked = false;
            checkShowWeapon.Checked = true;
            checkShowCrosshair.Checked = true;
            checkShowFirstPersonAmmo.Checked = false;
            numCrosshairScale.Enabled = true;
            numCrosshairScale.Value = 1;

            // Ski Bar Settings
            numSkiBarMin.Value = 7;
            numSkiBarMax.Value = 180;

            // Roam Map Settings
            checkRoamTurrets.Checked = false;
            checkRoamPower.Checked = false;
            numRoamFlagSpeed.Value = 0;
            numRoamFlagDecel.Value = 10;

            // Damage Number Settings
            // Damage Number Display
            checkDamageNumberRainbow.Checked = false;
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
            textDamageNumberCustomText.Text = "";
            textDamageNumberCustomText.Enabled = false;
            numDamageNumberStreamTimeout.Value = 0.5M;

            // HUD Icons
            checkHUDIconObjective.Checked = true;
            checkHUDIconFlagBase.Checked = true;
            checkHUDIconCTFBase.Checked = true;
            checkHUDIconNugget.Checked = true;
            checkHUDIconPlayer.Checked = true;
            checkHUDIconVehicle.Checked = true;
            checkHUDIconSensor.Checked = true;
            checkHUDIconMine.Checked = true;

            // Magic Chain
            checkMagicChainEnable.Checked = false;
            checkMagicChainSmallBullets.Checked = false;
            checkMagicChainCenter.Checked = false;
            numMagicChainPingMultiplier.Value = 1.0M;
            numMagicChainSpawnDelay.Value = 0.0M;

            // Colour Settings
            listColorSettings.Items.Clear();
            checkColorSettingOverride.Checked = false;
            colorColorSettings.setColor(0, 0, 0, 255);

            listLoadouts.Items.Clear();

            listCrosshairs.Items.Clear();

            listMute.Items.Clear();
            checkMuteVGS.Checked = false;
            checkMuteText.Checked = false;
            checkMuteDirectMessages.Checked = false;

            listProjectileSetting.Items.Clear();
            colorProjectileSetting.setColor(255, 255, 255, 255);
            numProjectileSettingIntensity.Value = 1M;

            listProjectileSwap.Items.Clear();
            checkProjectileSwapClone.Checked = false;

            // Hit Sounds
            selectHitSoundMode.SelectedIndex = 0;
            listHitSound.Items.Clear();

            listHitSound.Items.Add(createCustomSoundListWrapper("Hit Sound", "sounds\\hit.wav", "volumeHitSound", null));
            listHitSound.Items.Add(createCustomSoundListWrapper("Blueplate", "sounds\\blueplate.wav", "volumeBluePlate", "customBluePlateSound"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Air Mail", "sounds\\airmail.wav", "volumeAirMail", "customAirMailSound"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Head Shot", "sounds\\headshot.wav", "volumeHeadShot", "customHeadShotSound"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Artillery Shot", "sounds\\artilleryshot.wav", "volumeArtilleryShot", "customArtilleryShot"));
            
            listHitSound.Items.Add(createCustomSoundListWrapper("Head Shot Kill", "sounds\\headshotkill.wav", "volumeHeadShotKill", "customHeadShotKill"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Melee Kill", "sounds\\meleekill.wav", "volumeMeleeKill", "customMeleeKill"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Road Kill", "sounds\\roadkill.wav", "volumeRoadKill", "customRoadKill"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Fast Grab", "sounds\\fastgrab.wav", "volumeFastGrab", "customFastGrab"));
            listHitSound.Items.Add(createCustomSoundListWrapper("First Blood", "sounds\\firstblood.wav", "volumeFirstBlood", "customFirstBlood"));

            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Blue Grab", "sounds\\flagblue_grab.wav", "volumeFlagBlueGrab", "customFlagBlueGrab"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Red Grab", "sounds\\flagred_grab.wav", "volumeFlagRedGrab", "customFlagRedGrab"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Blue Pickup", "sounds\\flagblue_pickup.wav", "volumeFlagBluePickup", "customFlagBluePickup"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Red Pickup", "sounds\\flagred_pickup.wav", "volumeFlagRedPickup", "customFlagRedPickup"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Blue Capture", "sounds\\flagblue_capture.wav", "volumeFlagBlueCapture", "customFlagBlueCapture"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Red Capture", "sounds\\flagred_capture.wav", "volumeFlagRedCapture", "customFlagRedCapture"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Blue Return", "sounds\\flagblue_return.wav", "volumeFlagBlueReturn", "customFlagBlueReturn"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Red Return", "sounds\\flagred_return.wav", "volumeFlagRedReturn", "customFlagRedReturn"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Blue Drop", "sounds\\flagblue_drop.wav", "volumeFlagBlueDrop", "customFlagBlueDrop"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Flag Red Drop", "sounds\\flagred_drop.wav", "volumeFlagRedDrop", "customFlagRedDrop"));

            listHitSound.Items.Add(createCustomSoundListWrapper("Streak 1", "sounds\\streak1.wav", "volumeStreak1", "customStreak1"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Streak 2", "sounds\\streak2.wav", "volumeStreak2", "customStreak2"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Streak 3", "sounds\\streak3.wav", "volumeStreak3", "customStreak3"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Streak 4", "sounds\\streak4.wav", "volumeStreak4", "customStreak4"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Streak 5", "sounds\\streak5.wav", "volumeStreak5", "customStreak5"));

            listHitSound.Items.Add(createCustomSoundListWrapper("Multi Kill 1", "sounds\\multikill1.wav", "volumeMultiKill1", "customMultiKill1"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Multi Kill 2", "sounds\\multikill2.wav", "volumeMultiKill2", "customMultiKill2"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Multi Kill 3", "sounds\\multikill3.wav", "volumeMultiKill3", "customMultiKill3"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Multi Kill 4", "sounds\\multikill4.wav", "volumeMultiKill4", "customMultiKill4"));
            listHitSound.Items.Add(createCustomSoundListWrapper("Multi Kill 5", "sounds\\multikill5.wav", "volumeMultiKill5", "customMultiKill5"));


            trackHitSoundVolumeSpecific.Value = 100;
            checkHitSoundSpecific.Checked = false;

            numHitSoundDamageRef.Value = 600;
            numHitSoundPitchMin.Value = 0.4M;
            numHitSoundPitchMax.Value = 1.6M;
            selectHitSoundFileSpecific.Items.Clear();
        }

        private void setUI()
        {
            // General settings
            // Display settings
            checkStatsRecord.Checked = (bool)config.getConfigVar("recordStats");
            checkShowWeapon.Checked = (bool)config.getConfigVar("showWeapon");
            checkShowFirstPersonAmmo.Checked = (bool)config.getConfigVar("showFirstPersonAmmo");
            checkShowCrosshair.Checked = (bool)config.getConfigVar("showCrosshair");
            numCrosshairScale.Value = Convert.ToDecimal(config.getConfigVar("crosshairScale"));

            // Ski Bar Settings
            numSkiBarMin.Value = Convert.ToInt32(config.getConfigVar("skiBarMin"));
            numSkiBarMax.Value = Convert.ToInt32(config.getConfigVar("skiBarMax"));

            // Roam Map Settings
            checkRoamTurrets.Checked = (bool)config.getConfigVar("disableBaseTurrets");
            checkRoamPower.Checked = (bool)config.getConfigVar("disablePower");
            numRoamFlagSpeed.Value = Convert.ToDecimal(config.getConfigVar("maxSpeedWithFlag"));
            numRoamFlagDecel.Value = Convert.ToDecimal(config.getConfigVar("decelerationRateWithFlag"));

            // Damage Number Settings
            // Damage Number Display
            checkDamageNumberRainbow.Checked = (bool)config.getConfigVar("showRainbow");
            numDamageNumberLimit.Value = 0;
            if (Convert.ToInt32(config.getConfigVar("damageNumbersLimit")) <= 0)
            {
                radioDamageNumberShow.Checked = true;
            }
            else if (Convert.ToInt32(config.getConfigVar("damageNumbersLimit")) < 10000)
            {
                radioDamageNumberLimit.Checked = true;
                numDamageNumberLimit.Value = Convert.ToInt32(config.getConfigVar("damageNumbersLimit"));
            }
            else
            {
                radioDamageNumberHide.Checked = true;
            }

            numDamageNumberScale.Value = Convert.ToDecimal(config.getConfigVar("damageNumbersScale"));
            numDamageNumberXOffset.Value = Convert.ToInt32(config.getConfigVar("damageNumbersOffsetX"));
            numDamageNumberYOffset.Value = Convert.ToInt32(config.getConfigVar("damageNumbersOffsetY"));

            // Damage Number Streaming
            numDamageNumberStreamTimeout.Value = Convert.ToDecimal(config.getConfigVar("damageNumberStreamTimeout"));
            if ((string)config.getConfigVar("damageNumberCustomText") != "")
            {
                radioDamageNumberCustomText.Checked = true;
                textDamageNumberCustomText.Text = (string)config.getConfigVar("damageNumberCustomText");
            }
            else if ((bool)config.getConfigVar("showChainBulletHitCount"))
            {
                radioDamageNumberCount.Checked = true;
            }
            else if ((bool)config.getConfigVar("showDamageNumberStream"))
            {
                radioDamageNumberStream.Checked = true;
            }
            else
            {
                radioDamageNumberDiscrete.Checked = true;
            }

            // HUD Icons
            checkHUDIconObjective.Checked = (bool)config.getConfigVar("showObjectiveIcon");
            checkHUDIconFlagBase.Checked = (bool)config.getConfigVar("showFlagBaseIcon");
            checkHUDIconCTFBase.Checked = (bool)config.getConfigVar("showCTFBaseIcon");
            checkHUDIconNugget.Checked = (bool)config.getConfigVar("showNuggetIcon");
            checkHUDIconPlayer.Checked = (bool)config.getConfigVar("showPlayerIcon");
            checkHUDIconVehicle.Checked = (bool)config.getConfigVar("showVehicleIcon");
            checkHUDIconSensor.Checked = (bool)config.getConfigVar("showSensorIcon");
            checkHUDIconMine.Checked = (bool)config.getConfigVar("showMineIcon");

            // Magic Chain
            checkMagicChainEnable.Checked = (bool)config.getConfigVar("useMagicChain");
            checkMagicChainSmallBullets.Checked = (bool)config.getConfigVar("useSmallBullets");
            checkMagicChainCenter.Checked = (bool)config.getConfigVar("centerBulletSpawn");
            numMagicChainPingMultiplier.Value = Convert.ToDecimal(config.getConfigVar("bulletPingMultiplier"));
            numMagicChainSpawnDelay.Value = Convert.ToDecimal(config.getConfigVar("bulletSpawnDelay"));

            // Colour Settings
            listColorSettings.Items.Clear();
            checkColorSettingOverride.Checked = false;
            colorColorSettings.setColor(0, 0, 0, 255);

            foreach (string key in colorSettingVars.Keys)
            {
                ConfigVarItem c = new ConfigVarItem(key, colorSettingVars[key]);
                c.ReadFromConfig(config);
                listColorSettings.Items.Add(c);
            }

            // Loadouts
            listLoadouts.Items.Clear();
            foreach (Loadout l in config.getConfigLoadouts())
            {
                listLoadouts.Items.Add(l);
            }

            // Crosshairs
            listCrosshairs.Items.Clear();
            foreach (CrosshairSetting cs in config.getConfigSetCrosshairs())
            {
                listCrosshairs.Items.Add(cs);
            }

            // Muted Players
            listMute.Items.Clear();
            foreach (MutedPlayer player in config.getConfigMutedPlayers())
            {
                listMute.Items.Add(player);
            }

            // Modified Projectiles
            listProjectileSetting.Items.Clear();
            foreach (ProjectileSetting setting in config.getConfigProjectileSettings())
            {
                listProjectileSetting.Items.Add(setting);
            }

            // Projectile Swaps
            listProjectileSwap.Items.Clear();
            foreach (ProjectileSwap swap in config.getConfigProjectileSwaps())
            {
                listProjectileSwap.Items.Add(swap);
            }

            // Hit Sounds
            selectHitSoundMode.SelectedIndex = Math.Max(Math.Min(Convert.ToInt32(config.getConfigVar("hitSoundMode")), 3), 0);

            trackHitSoundVolumeSpecific.Value = 100;
            checkHitSoundSpecific.Checked = false;
            selectHitSoundFileSpecific.Items.Clear();

            foreach (ConfigSetListWrapper c in listHitSound.Items)
            {
                c.getSet().ReadFromConfig(config);
            }
            listHitSound.SelectedIndex = 0;

            numHitSoundDamageRef.Value = Convert.ToInt32(config.getConfigVar("hitSoundDamageRef"));
            numHitSoundPitchMin.Value = Convert.ToDecimal(config.getConfigVar("hitSoundPitchMin"));
            numHitSoundPitchMax.Value = Convert.ToDecimal(config.getConfigVar("hitSoundPitchMax"));
            
        }

        private void writeUIToConfig()
        {
            // General Settings
            // Display Settings
            config.setConfigVar("recordStats", checkStatsRecord.Checked);
            config.setConfigVar("showWeapon", checkShowWeapon.Checked);
            config.setConfigVar("showFirstPersonAmmo", checkShowFirstPersonAmmo.Checked);
            config.setConfigVar("showCrosshair", checkShowCrosshair.Checked);
            config.setConfigVar("crosshairScale", Convert.ToSingle(numCrosshairScale.Value));

            // Ski Bar Settings
            config.setConfigVar("skiBarMin", (int)numSkiBarMin.Value);
            config.setConfigVar("skiBarMax", (int)numSkiBarMax.Value);

            // Roam Map Settings
            config.setConfigVar("disableBaseTurrets", checkRoamTurrets.Checked);
            config.setConfigVar("disablePower", checkRoamPower.Checked);
            config.setConfigVar("maxSpeedWithFlag", Convert.ToSingle(numRoamFlagSpeed.Value));
            config.setConfigVar("decelerationRateWithFlag", Convert.ToSingle(numRoamFlagDecel.Value));

            // Damage Number Settings
            // Damage Number Display
            config.setConfigVar("showRainbow", checkDamageNumberRainbow.Checked);
            if (radioDamageNumberShow.Checked)
            {
                config.setConfigVar("damageNumbersLimit", 0);
            }
            else if (radioDamageNumberLimit.Checked)
            {
                config.setConfigVar("damageNumbersLimit", (int)numDamageNumberLimit.Value);
            }
            else
            {
                config.setConfigVar("damageNumbersLimit", 100000);
            }

            config.setConfigVar("damageNumbersScale", Convert.ToSingle(numDamageNumberScale.Value));
            config.setConfigVar("damageNumbersOffsetX", (int)numDamageNumberXOffset.Value);
            config.setConfigVar("damageNumbersOffsetY", (int)numDamageNumberYOffset.Value);

            // Damage Number Streaming
            config.setConfigVar("showChainBulletHitCount", false);
            config.setConfigVar("showDamageNumberStream", false);
            config.setConfigVar("damageNumberStreamTimeout", Convert.ToSingle(numDamageNumberStreamTimeout.Value));
            config.setConfigVar("damageNumberCustomText", "");
            if (radioDamageNumberCustomText.Checked)
            {
                config.setConfigVar("damageNumberCustomText", textDamageNumberCustomText.Text);
            }
            else if (radioDamageNumberCount.Checked)
            {
                config.setConfigVar("showChainBulletHitCount", true);
            }
            else if (radioDamageNumberStream.Checked)
            {
                config.setConfigVar("showDamageNumberStream", true);
            }

            // HUD Icons
            config.setConfigVar("showObjectiveIcon", checkHUDIconObjective.Checked);
            config.setConfigVar("showFlagBaseIcon", checkHUDIconFlagBase.Checked);
            config.setConfigVar("showCTFBaseIcon", checkHUDIconCTFBase.Checked);
            config.setConfigVar("showNuggetIcon", checkHUDIconNugget.Checked);
            config.setConfigVar("showPlayerIcon", checkHUDIconPlayer.Checked);
            config.setConfigVar("showVehicleIcon", checkHUDIconVehicle.Checked);
            config.setConfigVar("showSensorIcon", checkHUDIconSensor.Checked);
            config.setConfigVar("showMineIcon", checkHUDIconMine.Checked);

            // Magic Chain
            config.setConfigVar("useMagicChain", checkMagicChainEnable.Checked);
            config.setConfigVar("useSmallBullets", checkMagicChainSmallBullets.Checked);
            config.setConfigVar("centerBulletSpawn", checkMagicChainCenter.Checked);
            config.setConfigVar("bulletPingMultiplier", Convert.ToSingle(numMagicChainPingMultiplier.Value));
            config.setConfigVar("bulletSpawnDelay", Convert.ToSingle(numMagicChainSpawnDelay.Value));

            // Colour Settings
            // Custom Damage Number Colours
            foreach (ConfigVarItem c in listColorSettings.Items)
            {
                c.WriteToConfig(config);
            }

            // Loadouts
            config.clearConfigLoadouts();
            foreach (Loadout l in listLoadouts.Items)
            {
                config.setLoadout(l.gameClass, l.num, l.name, l.equipment);
            }

            // Crosshairs
            config.clearConfigCrosshairs();
            foreach (CrosshairSetting cs in listCrosshairs.Items)
            {
                config.setCrosshairs(cs.gameClass, cs.weapon, cs.crosshairs);
            }

            // Muted Players
            config.clearConfigMutedPlayers();
            foreach (MutedPlayer player in listMute.Items)
            {
                config.mutePlayer(player);
            }

            // Modified Projectiles
            config.clearConfigProjectileSettings();
            foreach (ProjectileSetting setting in listProjectileSetting.Items)
            {
                config.setProjectileColor(setting.projectile, setting.color, setting.intensity);
            }

            // Swapped Projectiles
            config.clearConfigProjectileSwaps();
            foreach (ProjectileSwap swap in listProjectileSwap.Items)
            {
                config.setProjectile(swap.projectile.gameClass, swap.projectile.weapon, swap.swapProjectile);
            }

            // Hit Sounds
            config.setConfigVar("hitSoundMode", Math.Max(0, Math.Min(3, selectHitSoundMode.SelectedIndex)));

            foreach (ConfigSetListWrapper c in listHitSound.Items)
            {
                c.getSet().WriteToConfig(config);
            }

            config.setConfigVar("hitSoundDamageRef", Convert.ToInt32(numHitSoundDamageRef.Value));
            config.setConfigVar("hitSoundPitchMin", Convert.ToSingle(numHitSoundPitchMin.Value));
            config.setConfigVar("hitSoundPitchMax", Convert.ToSingle(numHitSoundPitchMax.Value));
        }

        private ConfigSetListWrapper createCustomSoundListWrapper(string soundName, string asset, string volumeVar, string enableVar)
        {
            ConfigSet c = new ConfigSet(soundName);
            ConfigItem i = new ConfigAssetFileItem(soundName.Replace(" ", "").Trim().ToLower(), asset, enableVar);
            (i as ConfigAssetFileItem).doWrite = true;
            c.Add(i);
            i = new ConfigVarItem(soundName.Replace(" ", "").Trim().ToLower() + "_volume", volumeVar, true);
            c.Add(i);
            return new ConfigSetListWrapper(c);
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

            if (curClass == "")
            {
                return;
            }

            selectLoadoutPrimary.Items.AddRange(loadoutDetails[curClass]["primary"].ToArray());
            selectLoadoutSecondary.Items.AddRange(loadoutDetails[curClass]["secondary"].ToArray());
            selectLoadoutBelt.Items.AddRange(loadoutDetails[curClass]["belt"].ToArray());
            selectLoadoutPack.Items.AddRange(loadoutDetails[curClass]["pack"].ToArray());
            selectLoadoutPerk1.Items.AddRange(loadoutDetails["all"]["perk1"].ToArray());
            selectLoadoutPerk2.Items.AddRange(loadoutDetails["all"]["perk2"].ToArray());

            if (curNumber == -1)
            {
                return;
            }

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
            loadoutDetails["Pathfinder"]["primary"] = new List<String> { "Light Spinfusor", "Bolt Launcher", "Dueling Spinfusor", "Light Twinfusor", "Blinksfusor" };
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
            loadoutRegex["Soldier"]["secondary"] = new List<string> { "^(thumper|thumperd)$", "^(thumperdx|dx)$", "^(sparespinfusor|sparespin|spin|spinfusor)$", "^(eaglepistol|eagle|pistol)$", "^(shocklance)$" };
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
            loadoutDetails["Juggernaut"]["belt"] = new List<string> { "Heavy AP Grenades", "Heavy AP Grenades XL", "Spindisks" };
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

            crosshairDetails = new List<string>() { "Spinfusor", "SMG", "Rifle", "Locked On", "Crossbow", "Flamethrower", "Chaingun", "Thumper", "Nanite", "Shotgun", "Unknown", "Laser", "ch_v13", "Scope", "Nova Blaster", "Mortar", "Melee", "Shrike", "Spectator", "Chain", "BXT1", "Phase Rifle", "SAP20", "Plasma Gun" };
            crosshairRegex = new List<string>() { "^(spin(fusor)?)$", "^(smg)$", "^(rifle)$", "^(locked_?on)$", "^(crossbow)$", "^(flamethrower)$", "^(chaingun)$", "^(bolt(launcher)?|thumper|missile)$", "^(nanite)$", "^(shotgun)$", "^(unknown)$", "^(laser)$", "^(ch_?v13)$", "^(scope)$", "^(standard|(nova)?(colt|blaster)?)$", "^(grenadelauncher|mortar)$", "^(melee)$", "^(shrike)$", "^(spectator)$", "^(chain|dot|assaultrifle|ar|red_?dot)$", "^(bxt1?)$", "^(phase(rifle)?)$", "^(sap(20)?)$", "^(plasma(gun)?)$" };

            foreach (string xhair in crosshairDetails)
            {
                selectCrosshairNormal.Items.Add(xhair);
                selectCrosshairScoped.Items.Add(xhair);
            }

        }

        private void setupColorSettingVars()
        {
            colorSettingVars = new Dictionary<string, string>()
            {
                {"Damage Number Colour (Minimum)", "damageNumbersColorMin"},
                {"Damage Number Colour (Maximum)", "damageNumbersColorMax"},

                {"Crosshair Colour", "crosshairColor"},

                {"Console Chat Colour - Friendly", "friendlyChatColor"},
                {"Console Chat Colour - Enemy", "enemyChatColor"},
                {"HUD Chat Colour - Friendly", "friendlyHUDChatColor"},
                {"HUD Chat Colour - Enemy", "enemyHUDChatColor"},
                
                {"Player Name Colour - Friendly", "friendlyColor"},
                {"Player Name Colour - Enemy", "enemyColor"},
                {"Player Marker Colour - Friendly", "friendlyMarkerColor"},
                {"Player Marker Colour - Enemy", "enemyMarkerColor"},
                {"Friend Marker Colour - Friendly", "friendlyIsFMarkerColor"},
                {"Friend Marker Colour - Enemy", "enemyIsFMarkerColor"}
            };
        }

        private string findMatchingLoadoutItem(string gameClass, string slot, string item)
        {
            for (int i = 0; i < loadoutDetails[gameClass][slot.ToLower()].Count; i++)
            {
                if (Regex.IsMatch(item.Replace(" ", ""), loadoutRegex[gameClass][slot.ToLower()][i], RegexOptions.IgnoreCase | RegexOptions.IgnorePatternWhitespace))
                {
                    return loadoutDetails[gameClass][slot.ToLower()][i];
                }
            }

            return null;
        }

        private string findMatchingCrosshairName(string cname)
        {
            for (int i = 0; i < crosshairDetails.Count; i++)
            {
                if (Regex.IsMatch(cname.Replace(" ", ""), crosshairRegex[i], RegexOptions.IgnoreCase | RegexOptions.IgnorePatternWhitespace))
                {
                    return crosshairDetails[i];
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

        private void checkShowCrosshair_CheckedChanged(object sender, EventArgs e)
        {
            numCrosshairScale.Enabled = checkShowCrosshair.Checked;
        }

        private void btnSaveConfig_Click(object sender, EventArgs e)
        {
            writeUIToConfig();
            if (config.saveConfig())
            {
                MessageBox.Show("Config successfully saved!", "Save", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                // Show error if write failed
                MessageBox.Show("An error occurred saving the config file!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnLoadoutDelete_Click(object sender, EventArgs e)
        {
            if (listLoadouts.SelectedItem != null)
            {
                listLoadouts.Items.Remove(listLoadouts.SelectedItem);
            }
        }

        private void btnLoadoutSave_Click(object sender, EventArgs e)
        {
            Loadout lNew = new Loadout((string)selectLoadoutClass.SelectedItem, Convert.ToInt32(selectLoadoutNumber.SelectedItem), textLoadoutName.Text,
                Equipment.create((string)selectLoadoutPrimary.SelectedItem, (string)selectLoadoutSecondary.SelectedItem, (string)selectLoadoutBelt.SelectedItem, (string)selectLoadoutPack.SelectedItem,
                    (string)selectLoadoutPerk1.SelectedItem, (string)selectLoadoutPerk2.SelectedItem));
            if (lNew.name.Trim() != "" && lNew.equipment.primary.Trim() != "" && lNew.equipment.secondary.Trim() != ""
                     && lNew.equipment.belt.Trim() != "" && lNew.equipment.pack.Trim() != ""
                     && lNew.equipment.perk1.Trim() != "" && lNew.equipment.perk2.Trim() != "")
            {
                for (int i = 0; i < listLoadouts.Items.Count; i++)
                {
                    if (lNew.Equals(listLoadouts.Items[i]))
                    {
                        listLoadouts.Items.Remove(listLoadouts.Items[i]);
                        break;
                    }
                }

                listLoadouts.Items.Add(lNew);
            }

        }

        private void updateSelectorWeaponListings(ComboBox weaponSelector, ComboBox classSelector)
        {
            weaponSelector.Items.Clear();
            if (classSelector.SelectedItem != null)
            {
                foreach (string weapon in loadoutDetails[(string)classSelector.SelectedItem]["primary"])
                {
                    weaponSelector.Items.Add(weapon);
                }
                foreach (string weapon in loadoutDetails[(string)classSelector.SelectedItem]["secondary"])
                {
                    weaponSelector.Items.Add(weapon);
                }
                foreach (string weapon in loadoutDetails[(string)classSelector.SelectedItem]["belt"])
                {
                    weaponSelector.Items.Add(weapon);
                }
            }
        }

        private void updateCrosshairSelectors(object from)
        {

            updateSelectorWeaponListings(selectCrosshairWeapon, selectCrosshairClass);

            string curClass = "";
            string curWeapon = "";

            if (from.Equals(listCrosshairs))
            {
                if (listCrosshairs.SelectedItem != null)
                {
                    
                    curClass = ((CrosshairSetting)listCrosshairs.SelectedItem).gameClass;

                    curWeapon = findMatchingLoadoutItem(curClass, "primary",  ((CrosshairSetting)listCrosshairs.SelectedItem).weapon);
                    if (curWeapon == null) 
                    {
                        curWeapon = findMatchingLoadoutItem(curClass, "secondary", ((CrosshairSetting)listCrosshairs.SelectedItem).weapon);

                        if (curWeapon == null)
                        {
                            curWeapon = findMatchingLoadoutItem(curClass, "belt", ((CrosshairSetting)listCrosshairs.SelectedItem).weapon);

                            if (curWeapon == null)
                            {
                                curWeapon = findMatchingLoadoutItem(curClass, "pack", ((CrosshairSetting)listCrosshairs.SelectedItem).weapon);

                                if (curWeapon == null)
                                {
                                    curWeapon = "";
                                }
                            }
                        }
                    }

                    selectCrosshairClass.SelectedItem = curClass;

                    selectCrosshairWeapon.Items.Clear();
                    foreach (string weapon in loadoutDetails[(string)selectCrosshairClass.SelectedItem]["primary"])
                    {
                        selectCrosshairWeapon.Items.Add(weapon);
                    }
                    foreach (string weapon in loadoutDetails[(string)selectCrosshairClass.SelectedItem]["secondary"])
                    {
                        selectCrosshairWeapon.Items.Add(weapon);
                    }
                    foreach (string weapon in loadoutDetails[(string)selectCrosshairClass.SelectedItem]["belt"])
                    {
                        selectCrosshairWeapon.Items.Add(weapon);
                    }

                    selectCrosshairWeapon.SelectedItem = curWeapon;
                    selectCrosshairNormal.SelectedItem = findMatchingCrosshairName(((CrosshairSetting)listCrosshairs.SelectedItem).crosshairs.standard);
                    selectCrosshairScoped.SelectedItem = findMatchingCrosshairName(((CrosshairSetting)listCrosshairs.SelectedItem).crosshairs.zoomed);
                }
            }
            else
            {
                if (selectCrosshairWeapon.SelectedItem == null && listCrosshairs.SelectedItem != null)
                {
                    if ((string)((CrosshairSetting)listCrosshairs.SelectedItem).gameClass == (string)selectCrosshairClass.SelectedItem && (string)findMatchingCrosshairName(((CrosshairSetting)listCrosshairs.SelectedItem).crosshairs.standard) == (string)selectCrosshairNormal.SelectedItem && (string)findMatchingCrosshairName(((CrosshairSetting)listCrosshairs.SelectedItem).crosshairs.zoomed) == (string)selectCrosshairScoped.SelectedItem)
                    {
                        selectCrosshairWeapon.SelectedItem = ((CrosshairSetting)listCrosshairs.SelectedItem).weapon;
                    }
                }
            }
        }

        private void selectCrosshairClass_SelectionChangeCommitted(object sender, EventArgs e)
        {
            updateCrosshairSelectors(sender);
        }

        private void listCrosshairs_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateCrosshairSelectors(sender);
        }

        private void btnDeleteCrosshair_Click(object sender, EventArgs e)
        {
            if (listCrosshairs.SelectedItem != null)
            {
                listCrosshairs.Items.Remove(listCrosshairs.SelectedItem);
            }
        }

        private void btnSaveCrosshair_Click(object sender, EventArgs e)
        {
            CrosshairSetting csNew = new CrosshairSetting((string)selectCrosshairClass.SelectedItem, (string)selectCrosshairWeapon.SelectedItem,
                new Crosshairs((string)selectCrosshairNormal.SelectedItem, (string)selectCrosshairScoped.SelectedItem));
            if (csNew.gameClass.Trim() != "" && csNew.weapon.Trim() != "" && csNew.crosshairs.standard.Trim() != "" && csNew.crosshairs.zoomed.Trim() != "")
            {
                for (int i = 0; i < listCrosshairs.Items.Count; i++)
                {
                    if (csNew.Equals(listCrosshairs.Items[i]))
                    {
                        listCrosshairs.Items.Remove(listCrosshairs.Items[i]);
                        break;
                    }
                }

                listCrosshairs.Items.Add(csNew);
            }
        }

        private void radioDamageNumberCustomText_CheckedChanged(object sender, EventArgs e)
        {
            textDamageNumberCustomText.Enabled = radioDamageNumberCustomText.Checked;
            numDamageNumberStreamTimeout.Enabled = !(radioDamageNumberDiscrete.Checked || radioDamageNumberCustomText.Checked);
        }

        private void radioDamageNumberDiscrete_CheckedChanged(object sender, EventArgs e)
        {
            numDamageNumberStreamTimeout.Enabled = !(radioDamageNumberDiscrete.Checked || radioDamageNumberCustomText.Checked);
        }

        private void btnMuteAdd_Click(object sender, EventArgs e)
        {
            foreach (MutedPlayer player in listMute.Items)
            {
                if (player.username.Trim().ToLower() == textMute.Text.Trim().ToLower())
                {
                    listMute.Items.Remove(player);
                    listMute.Items.Add(MutedPlayer.create_custom(textMute.Text.Trim(), checkMuteVGS.Checked, checkMuteText.Checked, checkMuteDirectMessages.Checked));
                    return;
                }
            }
            
            if (textMute.Text.Trim() != "")
            {
                listMute.Items.Add(MutedPlayer.create_custom(textMute.Text.Trim(), checkMuteVGS.Checked, checkMuteText.Checked, checkMuteDirectMessages.Checked));
            }
        }

        private void btnMuteDelete_Click(object sender, EventArgs e)
        {
            if (listMute.SelectedItem != null)
            {
                listMute.Items.Remove(listMute.SelectedItem);
            }
        }

        private void listMute_SelectedIndexChanged(object sender, EventArgs e)
        {
            MutedPlayer selPlayer = listMute.SelectedItem as MutedPlayer;
            if (selPlayer != null)
            {
                textMute.Text = selPlayer.username;
                checkMuteVGS.Checked = selPlayer.muteVGS;
                checkMuteText.Checked = selPlayer.muteText;
                checkMuteDirectMessages.Checked = selPlayer.muteDirectMessages;
            }
        }

        private void colorColorSettings_ColorUpdated(object sender, EventArgs e)
        {
            ConfigVarItem currentItem = listColorSettings.SelectedItem as ConfigVarItem;

            if (currentItem != null)
            {
                if (currentItem.isOverridden)
                {
                    currentItem.value = colorColorSettings.getColor();
                }
                else
                {
                    currentItem.value = null;
                }
                
            }
        }

        private void checkColorSettingOverride_CheckedChanged(object sender, EventArgs e)
        {
            colorColorSettings.Enabled = checkColorSettingOverride.Checked;

            ConfigVarItem currentItem = listColorSettings.SelectedItem as ConfigVarItem;

            if (currentItem != null)
            {
                currentItem.isOverridden = checkColorSettingOverride.Checked;

                if (currentItem.isOverridden)
                {
                    colorColorSettings.setColor((Color)config.getConfigVarDefault(currentItem.var));
                    currentItem.value = (Color)config.getConfigVarDefault(currentItem.var);
                }
            }

            
        }

        private void listColorSettings_SelectedIndexChanged(object sender, EventArgs e)
        {
            colorColorSettings.ColorUpdated -= new EventHandler(colorColorSettings_ColorUpdated);
            checkColorSettingOverride.CheckedChanged -= new EventHandler(checkColorSettingOverride_CheckedChanged);

            ConfigVarItem currentItem = listColorSettings.SelectedItem as ConfigVarItem;

            if (currentItem != null)
            {
                checkColorSettingOverride.Checked = currentItem.isOverridden;
                if (currentItem.isOverridden && currentItem.value != null)
                {
                    Color col = (Color)currentItem.value;
                    colorColorSettings.setColor(col.R, col.G, col.B, col.A);
                }
                
            }
            colorColorSettings.Enabled = checkColorSettingOverride.Checked;

            checkColorSettingOverride.CheckedChanged += new EventHandler(checkColorSettingOverride_CheckedChanged);
            colorColorSettings.ColorUpdated += new EventHandler(colorColorSettings_ColorUpdated);
        }

        private void listProjectileSwap_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listProjectileSwap.SelectedItem == null) return;

            // Select the right classes
            selectProjectileSwapClass.SelectedItem = config.getGameClassName(((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.gameClass);
            selectProjectileSwapClass_Swap.SelectedItem = config.getGameClassName(((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.gameClass);

            // Update weapon boxes (disabling events!)
            selectProjectileSwapClass.SelectedIndexChanged -= new EventHandler(selectProjectileSwapClass_SelectedIndexChanged);
            selectProjectileSwapClass_Swap.SelectedIndexChanged -= new EventHandler(selectProjectileSwapClass_Swap_SelectedIndexChanged);
            updateSelectorWeaponListings(selectProjectileSwapWeapon, selectProjectileSwapClass);
            updateSelectorWeaponListings(selectProjectileSwapWeapon_Swap, selectProjectileSwapClass_Swap);
            selectProjectileSwapClass.SelectedIndexChanged += new EventHandler(selectProjectileSwapClass_SelectedIndexChanged);
            selectProjectileSwapClass_Swap.SelectedIndexChanged += new EventHandler(selectProjectileSwapClass_Swap_SelectedIndexChanged);

            // Select the right weapons
            selectProjectileSwapWeapon.SelectedItem =
                findMatchingLoadoutItem(((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.gameClass, "primary", ((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.weapon);
            if (selectProjectileSwapWeapon.SelectedItem == null)
            {
                selectProjectileSwapWeapon.SelectedItem =
                    findMatchingLoadoutItem(((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.gameClass, "secondary", ((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.weapon);
                if (selectProjectileSwapWeapon.SelectedItem == null)
                {
                    selectProjectileSwapWeapon.SelectedItem =
                     findMatchingLoadoutItem(((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.gameClass, "belt", ((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.weapon);
                }
            }
            selectProjectileSwapWeapon_Swap.SelectedItem =
                findMatchingLoadoutItem(((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.gameClass, "primary", ((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.weapon);
            if (selectProjectileSwapWeapon_Swap.SelectedItem == null)
            {
                selectProjectileSwapWeapon_Swap.SelectedItem =
                    findMatchingLoadoutItem(((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.gameClass, "secondary", ((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.weapon);
                if (selectProjectileSwapWeapon_Swap.SelectedItem == null)
                {
                    selectProjectileSwapWeapon_Swap.SelectedItem =
                     findMatchingLoadoutItem(((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.gameClass, "belt", ((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.weapon);
                }
            }

            // Set the clone checkbox
            checkProjectileSwapClone.Checked = ((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.isClone;

            
        }

        private void selectProjectileSwapClass_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateSelectorWeaponListings(selectProjectileSwapWeapon, selectProjectileSwapClass);
        }

        private void selectProjectileSwapClass_Swap_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateSelectorWeaponListings(selectProjectileSwapWeapon_Swap, selectProjectileSwapClass_Swap);
        }

        private void listProjectileSetting_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listProjectileSetting.SelectedItem == null) return;
            
            updateSelectorWeaponListings(selectProjectileSettingWeapon, selectProjectileSettingClass);

            // Select the right class
            selectProjectileSettingClass.SelectedItem = config.getGameClassName(((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.gameClass);

            // Update weapon box (disabling events!)
            selectProjectileSettingClass.SelectedIndexChanged -= new EventHandler(selectProjectileSettingClass_SelectedIndexChanged);
            updateSelectorWeaponListings(selectProjectileSettingWeapon, selectProjectileSettingClass);
            selectProjectileSettingClass.SelectedIndexChanged += new EventHandler(selectProjectileSettingClass_SelectedIndexChanged);

            // Select the right weapon
            selectProjectileSettingWeapon.SelectedItem =
                findMatchingLoadoutItem(((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.gameClass, "primary", ((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.weapon);
            if (selectProjectileSettingWeapon.SelectedItem == null)
            {
                selectProjectileSettingWeapon.SelectedItem =
                    findMatchingLoadoutItem(((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.gameClass, "secondary", ((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.weapon);
                if (selectProjectileSettingWeapon.SelectedItem == null)
                {
                    selectProjectileSettingWeapon.SelectedItem =
                     findMatchingLoadoutItem(((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.gameClass, "belt", ((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.weapon);
                }
            }

            // Set the colour/intensity box
            colorProjectileSetting.setColor(((ProjectileSetting)listProjectileSetting.SelectedItem).color);
            numProjectileSettingIntensity.Value = Convert.ToDecimal(((ProjectileSetting)listProjectileSetting.SelectedItem).intensity);
        }

        private void selectProjectileSettingClass_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateSelectorWeaponListings(selectProjectileSettingWeapon, selectProjectileSettingClass);
        }

        private void btnProjectileSettingDelete_Click(object sender, EventArgs e)
        {
            if (listProjectileSetting.SelectedItem != null)
            {
                listProjectileSetting.Items.Remove(listProjectileSetting.SelectedItem);
            }
        }

        private void btnProjectileSwapDelete_Click(object sender, EventArgs e)
        {
            if (listProjectileSwap.SelectedItem != null)
            {
                listProjectileSwap.Items.Remove(listProjectileSwap.SelectedItem);
            }
        }

        private void btnProjectileSettingSave_Click(object sender, EventArgs e)
        {
            if (selectProjectileSettingClass.SelectedItem == null || selectProjectileSettingWeapon.SelectedItem == null) return;
            
            ProjectileSetting pNew = ProjectileSetting.setProjectileColor(Projectile.getProjectile((string)selectProjectileSettingClass.SelectedItem, (string)selectProjectileSettingWeapon.SelectedItem),
                (Color)colorProjectileSetting.getColor(), Convert.ToSingle(numProjectileSettingIntensity.Value));
            
            foreach (ProjectileSetting p in listProjectileSetting.Items)
            {
                if (p.projectile.Equals(pNew.projectile))
                {
                    listProjectileSetting.Items.Remove(p);
                    break;
                }
            }

            listProjectileSetting.Items.Add(pNew);
            listProjectileSetting.SelectedItem = pNew;
        }

        private void btnProjectileSwapSave_Click(object sender, EventArgs e)
        {
            if (selectProjectileSwapClass.SelectedItem == null || selectProjectileSwapWeapon.SelectedItem == null
                || selectProjectileSwapClass_Swap.SelectedItem == null || selectProjectileSwapWeapon_Swap.SelectedItem == null) return;

            ProjectileSwap pNew = ProjectileSwap.setProjectile((string)selectProjectileSwapClass.SelectedItem, (string)selectProjectileSwapWeapon.SelectedItem,
                                        Projectile.getProjectile((string)selectProjectileSwapClass_Swap.SelectedItem, (string)selectProjectileSwapWeapon_Swap.SelectedItem));

            // Check for clone
            if (checkProjectileSwapClone.Checked)
            {
                pNew.swapProjectile.isClone = true;
            }

            // Remove existing entries
            foreach (ProjectileSwap p in listProjectileSwap.Items)
            {
                if (p.projectile.Equals(pNew.projectile))
                {
                    listProjectileSwap.Items.Remove(p);
                    break;
                }
            }

            listProjectileSwap.Items.Add(pNew);
            listProjectileSwap.SelectedItem = pNew;
        }

        private void listHitSound_SelectedIndexChanged(object sender, EventArgs e)
        {
            ConfigSet cSet = ((ConfigSetListWrapper)(listHitSound.SelectedItem)).getSet();
            ConfigAssetFileItem soundFile = null;
            ConfigVarItem volume = null;

            if (listHitSound.SelectedItem == null) return;

            // Find the ConfigItems
            foreach (ConfigItem c in cSet)
            {
                ConfigAssetFileItem cAsset = c as ConfigAssetFileItem;
                ConfigVarItem cVar = c as ConfigVarItem;
                if (cAsset != null)
                {
                    if (cAsset.name == cSet.name.Replace(" ", "").Trim().ToLower())
                    {
                        soundFile = cAsset;
                    }
                }
                else if (cVar != null)
                {
                    if (cVar.var.StartsWith("volume") && cVar.var.Replace("volume", "").Replace(" ", "").Trim().ToLower() == cSet.name.Replace(" ", "").Trim().ToLower())
                    {
                        volume = cVar;
                    }
                }
            }

            if (soundFile == null || volume == null) return;
            
            selectHitSoundFileSpecific.Items.Clear();

            if (soundFile.inputFilename != null)
            {
                selectHitSoundFileSpecific.Items.Add(soundFile.inputFilename);
            }
            selectHitSoundFileSpecific.Text = soundFile.inputFilename;

            
            string[] inputFiles = {};
            string relfile;
            if (Directory.Exists(AppDomain.CurrentDomain.BaseDirectory + "\\sounds\\"))
            {
                inputFiles = Directory.GetFiles(AppDomain.CurrentDomain.BaseDirectory + "\\sounds\\", "*.wav");
            }

            foreach (string file in inputFiles)
            {
                relfile = file;
                if (file.StartsWith(AppDomain.CurrentDomain.BaseDirectory))
                {
                    relfile = file.Replace(AppDomain.CurrentDomain.BaseDirectory, "");
                }
                selectHitSoundFileSpecific.Items.Add(relfile);
            }
            
            trackHitSoundVolumeSpecific.Value = Convert.ToInt32(Convert.ToSingle(volume.value) * 100);
            checkHitSoundSpecific.Enabled = true;
            checkHitSoundSpecific.Checked = soundFile.doWrite;

            if (cSet.name.Replace(" ", "").Trim().ToLower() == "hitsound")
            {
                checkHitSoundSpecific.Checked = (selectHitSoundFileSpecific.Text.Trim() != "");
                checkHitSoundSpecific.Enabled = false;
            }

        }

        private void trackHitSoundVolumeSpecific_Scroll(object sender, EventArgs e)
        {
            ConfigSet cSet = ((ConfigSetListWrapper)(listHitSound.SelectedItem)).getSet();
            ConfigVarItem volume = null;

            if (listHitSound.SelectedItem == null) return;

            // Find the ConfigItems
            foreach (ConfigItem c in cSet)
            {
                ConfigVarItem cVar = c as ConfigVarItem;
                if (cVar != null)
                {
                    if (cVar.var.StartsWith("volume") && cVar.var.Replace("volume", "").Replace(" ", "").Trim().ToLower() == cSet.name.Replace(" ", "").Trim().ToLower())
                    {
                        volume = cVar;
                    }
                }
            }

            volume.value = ((float)trackHitSoundVolumeSpecific.Value) / 100F;

        }

        private void checkHitSoundSpecific_CheckedChanged(object sender, EventArgs e)
        {
            ConfigSet cSet = ((ConfigSetListWrapper)(listHitSound.SelectedItem)).getSet();
            ConfigAssetFileItem soundFile = null;

            if (listHitSound.SelectedItem == null) return;

            // Find the ConfigItems
            foreach (ConfigItem c in cSet)
            {
                ConfigAssetFileItem cAsset = c as ConfigAssetFileItem;
                if (cAsset != null)
                {
                    if (cAsset.name == cSet.name.Replace(" ", "").Trim().ToLower())
                    {
                        soundFile = cAsset;
                    }
                }
            }

            soundFile.doWrite = checkHitSoundSpecific.Checked;
            if (cSet.name.Replace(" ", "").Trim().ToLower() == "hitsound")
            {
                checkHitSoundSpecific.Checked = true;
                soundFile.doWrite = true;
            }

        }

        private void selectHitSoundFileSpecific_Changed(object sender, EventArgs e)
        {
            ConfigSet cSet = ((ConfigSetListWrapper)(listHitSound.SelectedItem)).getSet();
            ConfigAssetFileItem soundFile = null;

            if (listHitSound.SelectedItem == null) return;

            // Find the ConfigItems
            foreach (ConfigItem c in cSet)
            {
                ConfigAssetFileItem cAsset = c as ConfigAssetFileItem;
                if (cAsset != null)
                {
                    if (cAsset.name == cSet.name.Replace(" ", "").Trim().ToLower())
                    {
                        soundFile = cAsset;
                    }
                }
            }

            soundFile.inputFilename = selectHitSoundFileSpecific.Text;

            if (cSet.name.Replace(" ", "").Trim().ToLower() == "hitsound")
            {
                checkHitSoundSpecific.Checked = true;
                soundFile.doWrite = true;
            }

        }

        private void btnHitSoundFile_Click(object sender, EventArgs e)
        {
            fileHitSound.ShowDialog();
        }

        private void fileHitSound_FileOk(object sender, CancelEventArgs e)
        {
            if (fileHitSound.FileName.Trim() != "")
            {
                selectHitSoundFileSpecific.Text = fileHitSound.FileName.Trim();
                selectHitSoundFileSpecific_Changed(fileHitSound, EventArgs.Empty);
            }
        }

        private void btnInject_Click(object sender, EventArgs e)
        {
            //Init Injector process
            Process wJect = new Process();
            wJect.StartInfo.FileName = Path.Combine(Directory.GetCurrentDirectory(), "Resources\\ACDontop.exe");

            //Admin rights()
            wJect.StartInfo.Verb = "runas";

            wJect.StartInfo.Arguments = "/dllname:TAMods.dll" + " /exename:TribesAscend.exe";         

            //Execute injection
            //TODO MUCH TESTING, POSSIBLE ISSUES, PROBABLY SHOULD LOCK MAIN APP
            wJect.Start();
        }


    }

}