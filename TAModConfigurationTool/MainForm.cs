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
        public string matchedPreset = null;
        public string configDir = Environment.GetFolderPath(Environment.SpecialFolder.Personal) + "/My Games/Tribes Ascend/TribesGame/config/";

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
            string profile = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile);
            string directory = configDir;

            //if (profile == null)
            //{
            //    directory = "C:\\";
            //}
            //else
            //{
            //    directory = profile + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\";
            //}

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

            // Presets
            selectConfigPreset.Items.Clear();
            selectConfigPreset.Items.Add("<None>");
            selectConfigPreset.SelectedIndex = 0;

            // General settings
            // Display settings
            checkStatsRecord.Checked = true;
            checkStatsRecordGame.Checked = false;
            checkStatsSave.Checked = false;
            checkStatsSaveGame.Enabled = false;
            checkStatsSaveGame.Checked = false;
            checkShowWeapon.Checked = true;
            checkShowHUDWeapons.Checked = true;
            checkShowPlayerModel.Checked = true;
            checkShowCrosshair.Checked = true;
            checkShowFirstPersonAmmo.Checked = false;
            numCrosshairScale.Enabled = true;
            numCrosshairScale.Value = 1;
            numConsoleScale.Value = 0.75M;
            numConsoleTransparency.Value = 0.8M;

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
            checkRevertOriginalPositioning.Checked = false;
            numRevertOldPositioningThreshold.Value = 150;

            // Damage Number Streaming
            radioDamageNumberDiscrete.Checked = true;
            textDamageNumberCustomText.Text = "";
            textDamageNumberCustomText.Enabled = false;
            numDamageNumberStreamTimeout.Value = 0.5M;

            // HUD Icons
            numIFFScale.Value = 1.0M;
            checkHUDIconObjective.Checked = true;
            checkHUDIconFlagBase.Checked = true;
            checkHUDIconFlagHomeBase.Checked = true;
            checkHUDIconCTFBase.Checked = true;
            checkHUDIconNugget.Checked = true;
            checkHUDIconPlayer.Checked = true;
            checkHUDIconVehicle.Checked = true;
            checkHUDIconSensor.Checked = true;
            checkHUDIconMine.Checked = true;
            checkHUDTextObjective.Checked = true;
            checkHUDTextMine.Checked = true;

            // Magic Chain
            checkMagicChainEnable.Checked = false;
            checkMagicChainSmallBullets.Checked = false;
            checkMagicChainCenter.Checked = false;
            numMagicChainPingMultiplier.Value = 1.0M;
            numMagicChainSpawnDelay.Value = 0.0M;

            // Mouse Sensitivity
            checkMouseDisableFovScaling.Checked = false;
            numMouseSensitivity.Enabled = false;
            numMouseSensitivity.Value = 10.0M;
            numMouseZoomSensitivity.Enabled = false;
            numMouseZoomSensitivity.Value = 5.0M;
            numMouseZoom2Sensitivity.Enabled = false;
            numMouseZoom2Sensitivity.Value = 2.0M;

            // Route Recording
            checkRouteReplayRotation.Checked = true;
            checkRouteCinematicMode.Checked = false;
            checkRouteDrawMarkers.Checked = true;
            numRouteDrawInterval.Value = 500;
            checkRouteDrawETA.Checked = true;
            numRouteETAInterval.Value = 5;
            checkRouteDrawSavedLocations.Checked = true;

            // Stopwatch
            checkStopwatchStopOnCap.Checked = false;
            checkStopwatchStopOnDeath.Checked = true;
            checkStopwatchNotifications.Checked = true;

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
            // Presets
            // Find presets in the config directory
            scanForConfigPresets();
            foreach (string requirement in config.getConfigRequirements())
            {
                // Only load if it matches the preset folder structure format
                Match r = Regex.Match(requirement, @"^presets\/([\w\-. ]+)\/preset$");
                if (!r.Success)
                {
                    // Try matching a backslashed path as well
                    r = Regex.Match(requirement, @"^presets\\([\w\-. ]+)\\preset$");
                }
                if (r.Success)
                {
                    string presetName = r.Groups[1].Value;
                    matchedPreset = presetName;
                    if (selectConfigPreset.Items.IndexOf(presetName) != -1)
                    {
                        selectConfigPreset.SelectedIndex = selectConfigPreset.Items.IndexOf(presetName);
                        break;
                    }

                }
            }

            // General settings
            // Display settings
            checkStatsRecord.Checked = (bool)config.getConfigVar("recordStats");
            checkStatsRecordGame.Checked = (bool)config.getConfigVar("recordTeamStats");
            checkStatsSave.Checked = (bool)config.getConfigVar("saveStats");
            checkStatsSave.Enabled = checkStatsRecordGame.Enabled;
            checkStatsSaveGame.Checked = (bool)config.getConfigVar("saveTeamStats");
            checkStatsSaveGame.Enabled = checkStatsRecordGame.Checked;
            checkShowWeapon.Checked = (bool)config.getConfigVar("showWeapon");
            checkShowHUDWeapons.Checked = (bool)config.getConfigVar("showHUDWeapons");
            checkShowPlayerModel.Checked = (bool)config.getConfigVar("showBodyMesh");
            checkShowFirstPersonAmmo.Checked = (bool)config.getConfigVar("showFirstPersonAmmo");
            checkShowCrosshair.Checked = (bool)config.getConfigVar("showCrosshair");
            numCrosshairScale.Value = Convert.ToDecimal(config.getConfigVar("crosshairScale"));
            numConsoleScale.Value = Convert.ToDecimal(config.getConfigVar("consoleSize"));
            numConsoleTransparency.Value = Convert.ToDecimal(config.getConfigVar("consoleTransparency"));

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
            checkRevertOriginalPositioning.Checked = (bool)config.getConfigVar("revertOriginalDamageNumbers");
            numRevertOldPositioningThreshold.Value = Convert.ToInt32(config.getConfigVar("revertOriginalDamageNumbersThreshold"));

            // HUD Icons
            numIFFScale.Value = Convert.ToDecimal(config.getConfigVar("IFFScale"));
            checkHUDIconObjective.Checked = (bool)config.getConfigVar("showObjectiveIcon");
            checkHUDIconFlagBase.Checked = (bool)config.getConfigVar("showFlagBaseIcon");
            checkHUDIconFlagHomeBase.Checked = (bool)config.getConfigVar("showFlagHomeBaseIcon");
            checkHUDIconCTFBase.Checked = (bool)config.getConfigVar("showCTFBaseIcon");
            checkHUDIconNugget.Checked = (bool)config.getConfigVar("showNuggetIcon");
            checkHUDIconPlayer.Checked = (bool)config.getConfigVar("showPlayerIcon");
            checkHUDIconVehicle.Checked = (bool)config.getConfigVar("showVehicleIcon");
            checkHUDIconSensor.Checked = (bool)config.getConfigVar("showSensorIcon");
            checkHUDIconMine.Checked = (bool)config.getConfigVar("showMineIcon");
            checkHUDTextObjective.Checked = (bool)config.getConfigVar("showObjectiveText");
            checkHUDTextMine.Checked = (bool)config.getConfigVar("showMineText");

            // Magic Chain
            checkMagicChainEnable.Checked = (bool)config.getConfigVar("useMagicChain");
            checkMagicChainSmallBullets.Checked = (bool)config.getConfigVar("useSmallBullets");
            checkMagicChainCenter.Checked = (bool)config.getConfigVar("centerBulletSpawn");
            numMagicChainPingMultiplier.Value = Convert.ToDecimal(config.getConfigVar("bulletPingMultiplier"));
            numMagicChainSpawnDelay.Value = Convert.ToDecimal(config.getConfigVar("bulletSpawnDelay"));

            // Mouse Sensitivity
            checkMouseDisableFovScaling.Checked = !(bool)config.getConfigVar("useFOVScaling");
            numMouseSensitivity.Value = Convert.ToDecimal(config.getConfigVar("sens"));
            numMouseZoomSensitivity.Value = Convert.ToDecimal(config.getConfigVar("sensZoom"));
            numMouseZoom2Sensitivity.Value = Convert.ToDecimal(config.getConfigVar("sensZoooom"));

            // Route Recording
            checkRouteReplayRotation.Checked = (bool)config.getConfigVar("routeReplayRotation");
            checkRouteCinematicMode.Checked = (bool)config.getConfigVar("routeCinematicMode");
            if (Convert.ToInt32(config.getConfigVar("routeDrawInterval")) == 0)
            {
                checkRouteDrawMarkers.Checked = false;
                numRouteDrawInterval.Value = 500;
            }
            else
            {
                checkRouteDrawMarkers.Checked = true;
                numRouteDrawInterval.Value = Convert.ToInt32(config.getConfigVar("routeDrawInterval"));
            }
            if (Convert.ToInt32(config.getConfigVar("routeDrawETAInterval")) == 0)
            {
                checkRouteDrawETA.Checked = false;
                numRouteETAInterval.Value = 5;
            }
            else
            {
                checkRouteDrawETA.Checked = true;
                numRouteETAInterval.Value = Convert.ToInt32(config.getConfigVar("routeDrawETAInterval"));
            }
            checkRouteDrawSavedLocations.Checked = (bool)config.getConfigVar("showSavedLocations");

            // Stopwatch
            checkStopwatchStopOnCap.Checked = (bool)config.getConfigVar("stopwatchStopOnCap");
            checkStopwatchStopOnDeath.Checked = (bool)config.getConfigVar("stopwatchStopOnDeath");
            checkStopwatchNotifications.Checked = (bool)config.getConfigVar("stopwatchNotifications");

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

            // Weapon Model Swaps
            listWeaponSwap.Items.Clear();
            foreach (WeaponModelSwap swap in config.getWeaponModelSwaps())
            {
                listWeaponSwap.Items.Add(swap);
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
            // Presets
            //if (matchedPreset != null && matchedPreset != selectConfigPreset.SelectedItem) {
            //    config.removeConfigRequirement(String.Format("presets/{0}/preset", matchedPreset));
            config.clearConfigRequirements();
            if ((string)selectConfigPreset.SelectedItem != "<None>")
            {
                config.addConfigRequirement(String.Format("presets/{0}/preset", selectConfigPreset.SelectedItem));
            }
            //}

            // General Settings
            // Display Settings
            config.setConfigVar("recordStats", checkStatsRecord.Checked);
            config.setConfigVar("recordTeamStats", checkStatsRecordGame.Checked);
            config.setConfigVar("saveStats", checkStatsSave.Checked);
            config.setConfigVar("saveTeamStats", checkStatsSaveGame.Checked);
            config.setConfigVar("showWeapon", checkShowWeapon.Checked);
            config.setConfigVar("showHUDWeapons", checkShowHUDWeapons.Checked);
            config.setConfigVar("showBodyMesh", checkShowPlayerModel.Checked);
            config.setConfigVar("showFirstPersonAmmo", checkShowFirstPersonAmmo.Checked);
            config.setConfigVar("showCrosshair", checkShowCrosshair.Checked);
            config.setConfigVar("crosshairScale", Convert.ToSingle(numCrosshairScale.Value));
            config.setConfigVar("consoleSize", Convert.ToSingle(numConsoleScale.Value));
            config.setConfigVar("consoleTransparency", Convert.ToSingle(numConsoleTransparency.Value));

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
            config.setConfigVar("revertOriginalDamageNumbers", checkRevertOriginalPositioning.Checked);
            config.setConfigVar("revertOriginalDamageNumbersThreshold", (int)numRevertOldPositioningThreshold.Value);

            // HUD Icons
            config.setConfigVar("IFFScale", Convert.ToSingle(numIFFScale.Value));
            config.setConfigVar("showObjectiveIcon", checkHUDIconObjective.Checked);
            config.setConfigVar("showFlagBaseIcon", checkHUDIconFlagBase.Checked);
            config.setConfigVar("showFlagHomeBaseIcon", checkHUDIconFlagHomeBase.Checked);
            config.setConfigVar("showCTFBaseIcon", checkHUDIconCTFBase.Checked);
            config.setConfigVar("showNuggetIcon", checkHUDIconNugget.Checked);
            config.setConfigVar("showPlayerIcon", checkHUDIconPlayer.Checked);
            config.setConfigVar("showVehicleIcon", checkHUDIconVehicle.Checked);
            config.setConfigVar("showSensorIcon", checkHUDIconSensor.Checked);
            config.setConfigVar("showMineIcon", checkHUDIconMine.Checked);
            config.setConfigVar("showObjectiveText", checkHUDTextObjective.Checked);
            config.setConfigVar("showMineText", checkHUDTextMine.Checked);

            // Magic Chain
            config.setConfigVar("useMagicChain", checkMagicChainEnable.Checked);
            config.setConfigVar("useSmallBullets", checkMagicChainSmallBullets.Checked);
            config.setConfigVar("centerBulletSpawn", checkMagicChainCenter.Checked);
            config.setConfigVar("bulletPingMultiplier", Convert.ToSingle(numMagicChainPingMultiplier.Value));
            config.setConfigVar("bulletSpawnDelay", Convert.ToSingle(numMagicChainSpawnDelay.Value));

            // Mouse Sensitivity
            config.setConfigVar("useFOVScaling", !checkMouseDisableFovScaling.Checked);
            config.setConfigVar("sens", Convert.ToSingle(numMouseSensitivity.Value));
            config.setConfigVar("sensZoom", Convert.ToSingle(numMouseZoomSensitivity.Value));
            config.setConfigVar("sensZoooom", Convert.ToSingle(numMouseZoom2Sensitivity.Value));

            // Route Recording
            config.setConfigVar("routeReplayRotation", checkRouteReplayRotation.Checked);
            config.setConfigVar("routeCinematicMode", checkRouteCinematicMode.Checked);
            if (!checkRouteDrawMarkers.Checked)
            {
                config.setConfigVar("routeDrawInterval", 0);
            }
            else
            {
                config.setConfigVar("routeDrawInterval", (int)numRouteDrawInterval.Value);
            }
            if (!checkRouteDrawETA.Checked)
            {
                config.setConfigVar("routeDrawETAInterval", 0);
            }
            else
            {
                config.setConfigVar("routeDrawETAInterval", (int)numRouteETAInterval.Value);
            }
            config.setConfigVar("showSavedLocations", checkRouteDrawSavedLocations.Checked);

            // Stopwatch
            config.setConfigVar("stopwatchStopOnCap", checkStopwatchStopOnCap.Checked);
            config.setConfigVar("stopwatchStopOnDeath", checkStopwatchStopOnDeath.Checked);
            config.setConfigVar("stopwatchNotifications", checkStopwatchNotifications.Checked);

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

            config.clearConfigWeaponModelSwaps();
            foreach (WeaponModelSwap swap in listWeaponSwap.Items)
            {
                config.setWeaponModel(swap.origClass, swap.origWeapon, swap.newClass, swap.newWeapon, swap.updateAnims, swap.leavePositioning);
            }

            // Hit Sounds
            //config.setConfigVar("hitSoundMode", Math.Max(0, Math.Min(3, selectHitSoundMode.SelectedIndex)));

            //foreach (ConfigSetListWrapper c in listHitSound.Items)
            //{
            //    c.getSet().WriteToConfig(config);
            //}

            //config.setConfigVar("hitSoundDamageRef", Convert.ToInt32(numHitSoundDamageRef.Value));
            //config.setConfigVar("hitSoundPitchMin", Convert.ToSingle(numHitSoundPitchMin.Value));
            //config.setConfigVar("hitSoundPitchMax", Convert.ToSingle(numHitSoundPitchMax.Value));
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

        private void scanForConfigPresets()
        {
            if (!Directory.Exists(configDir + "presets\\"))
            {
                return;
            }

            foreach (string subdir in Directory.EnumerateDirectories(configDir + "presets\\"))
            {
                if (File.Exists(subdir + "\\preset.lua"))
                {
                    string subdirName = subdir.Split('\\').Last();
                    selectConfigPreset.Items.Add(subdirName);
                }
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

            loadoutDetails["Light"] = new Dictionary<string, List<string>>();
            loadoutRegex["Light"] = new Dictionary<string, List<string>>();
            loadoutDetails["Light"]["impact"] = new List<String> { "Light Spinfusor", "Dueling Spinfusor", "Stealth Spinfusor", "Bolt Launcher", "Light Twinfusor", "Blinksfusor" };
            loadoutRegex["Light"]["impact"] = new List<String> { "^(spin(fusor)?|light(spin)?(fusor)?)$", "^(dueling(spin)?(fusor)?)$", "^(stealth(spin)?(fusor)?)$", "^(bolt|boltlauncher)$", "^(twin|twinfusor|lighttwinfusor)$", "^(blinks?|blinks?fusor)$" };
            loadoutDetails["Light"]["timed"] = new List<string> { "Light Grenade Launcher", "Jackal" };
            loadoutRegex["Light"]["timed"] = new List<String> { "^((light)?(gl|grenadelauncher)|lgl)$", "^(jackal)$" };
            loadoutDetails["Light"]["specialty"] = new List<string> { "BXT", "BXT-1A", "Phase Rifle", "SAP20" };
            loadoutRegex["Light"]["specialty"] = new List<String> { "^(bxt|bxt1|bxt1rifle)$", "^((bxt1a|bxt-1a|bxt1-a|bxt-1a)(rifle)?)$", "^(phase|phaserifle)$", "^(sap(20)?(rifle)?)$" };
            loadoutDetails["Light"]["automatic"] = new List<string> { "Falcon", "Light Assault Rifle", "Rhino SMG", "Arctic Rhino SMG" };
            loadoutRegex["Light"]["automatic"] = new List<String> { "^(falcon)$", "^(lightassaultrifle|lar|ar|assaultrifle|rifle)$", "^(rhino(smg)?)$", "^(arcticrhino(smg)?)$" };
            loadoutDetails["Light"]["shortrange"] = new List<string> { "Shotgun", "Holdout Shotgun", "Accurized Shotgun", "Shocklance" };
            loadoutRegex["Light"]["shortrange"] = new List<String> { "^(shotgun)$", "^(holdout(shotgun)?)$", "^((accurized|accurised|sniper)(shotgun)?)$", "^(shocklance)$" };
            loadoutDetails["Light"]["sidearms"] = new List<string> { "Sparrow", "Throwing Knives", "SN7 Silenced Pistol", "Arctic SN7" };
            loadoutRegex["Light"]["sidearms"] = new List<String> { "^(sparrow)$", "^(throwingknives|knives)$", "^(sn7(silenced)?(pistol)?)$", "^(arcticsn7(silenced)?(pistol)?)$" };

            loadoutDetails["Light"]["belt"] = new List<string> { "Impact Nitrons", "Explosive Nitrons", "Compact Nitrons", "T5 Grenades", "Sticky Grenades", "Sticky Grenades XL", "Claymore Mines", "Prism Mines", "Chaff Grenades" };
            loadoutRegex["Light"]["belt"] = new List<string> { "^(nitrons?|impactnitrons?|impacts?)$", "^(explosivenitrons?|explosives?)$", "^(compactnitrons?|compacts?)$", "^(T5s?(grenades)?)$", "^(stickygrenades?|sticky|stickies)$", "^(stickygrenades?xl|stickyxl|stickiesxl)$", "^(claymores?|claymoremines?)$", "^(prismmines?|mines?)$", "^(chaffs?(grenades?)?)$" };
            loadoutDetails["Light"]["pack"] = new List<string> { "Energy Recharge", "Thrust Pack" };
            loadoutRegex["Light"]["pack"] = new List<string> { "^(energyrecharge|energy)$", "^(thrustpack|thrust)$" };


            loadoutDetails["Medium"] = new Dictionary<string, List<string>>();
            loadoutRegex["Medium"] = new Dictionary<string, List<string>>();
            loadoutDetails["Medium"]["impact"] = new List<String> { "Spinfusor", "Honorfusor", "Thumper", "Thumper D", "Thumper DX", "Twinfusor", "Blinksfusor" };
            loadoutRegex["Medium"]["impact"] = new List<String> { "^(spinfusor|spin)$", "^(honorfusor|honourfusor|honor)$", "^(thumper)$", "^(thumperd)$", "^(thumperdx)$", "^(twinfusor)$", "^(blinks?|blinks?fusor)$" };
            loadoutDetails["Medium"]["timed"] = new List<string> { "Arx Buster", "Dust Devil", "Grenade Launcher" };
            loadoutRegex["Medium"]["timed"] = new List<String> { "^(arxbuster|arx)$", "^(dustdevil)$", "^(grenadelauncher|nadelauncher|launcher|gl)$" };
            loadoutDetails["Medium"]["specialty"] = new List<string> { "Improved repair tool", "Long Range Repair Tool", "ELF Projector" };
            loadoutRegex["Medium"]["specialty"] = new List<String> { "^(improvedrepairtool|repairtool|repair)$", "^(longrangerepairtool)$", "^(elf(projector)?)$" };
            loadoutDetails["Medium"]["automatic"] = new List<string> { "Assault Rifle", "Gast Rifle", "NJ4", "Desert NJ4", "NJ5", "TCN4 SMG", "TCN4 Rockwind", "TC24", "Plasma Gun" };
            loadoutRegex["Medium"]["automatic"] = new List<String> { "^(assaultrifle|rifle|ar)$", "^(gast('s)?(rifle)?)$", "^(nj4smg|nj4)$", "^(desertnj4|desertnj4smg)$", "^(nj5(-?b)?)$", "^(tcn4(smg)?)$", "^(tcn4rockwind(smg)?)$", "^(tc24)$", "^(plasmagun|plasma)$" };
            loadoutDetails["Medium"]["shortrange"] = new List<string> { "Sawed off", "Flak cannon" };
            loadoutRegex["Medium"]["shortrange"] = new List<String> { "^(sawed-?offshotgun|shotgun|sawed-?off)$", "^(flak(cannon)?)$" };
            loadoutDetails["Medium"]["sidearms"] = new List<string> { "Nova blaster", "Eagle Pistol" };
            loadoutRegex["Medium"]["sidearms"] = new List<String> { "^(nova|blaster|novablaster)$", "^(eaglepistol|eagle|pistol)$" };

            loadoutDetails["Medium"]["belt"] = new List<string> { "Frag Grenades XL", "AP Grenades", "EMP Grenades", "EMP XL Grenades", "Blackout Grenades", "Cluster Grenades", "Proxies", "Short-fuse Frag Grenades" };
            loadoutRegex["Medium"]["belt"] = new List<string> { "^(fraggrenades?(xl)?|frags?(xl)?|grenades?(xl)?)$", "^(anti-?personnelgrenades?|aps?|apgrenades?)$", "^(emps?|empgrenades?)$", "^(emps?xls?|emps?xlgrenades?)$", "^(blackouts?|blackoutgrenades?)$", "^(clustergrenades?|clusters?)$", "^(proxmitys?(grenades?)?|proxies|proxys?)$", "^(short-?fusefraggrenades?|short-?fuses?)$" };
            loadoutDetails["Medium"]["pack"] = new List<string> { "Energy Pack", "Utility Pack" };
            loadoutRegex["Medium"]["pack"] = new List<string> { "^(energypack|energy)$", "^(utilitypack|utility)$" };


            loadoutDetails["Heavy"] = new Dictionary<string, List<string>>();
            loadoutRegex["Heavy"] = new Dictionary<string, List<string>>();
            loadoutDetails["Heavy"]["impact"] = new List<String> { "Spinfusor MKD", "Spinfusor MK-X", "Heavy Spinfusor", "Devastator Spinfusor", "Heavy Bolt Launcher", "Heavy Blinksfusor", "Heavy Twinfusor" };
            loadoutRegex["Heavy"]["impact"] = new List<String> { "^(spinfusormkd)$", "^(spinfusormk-?x)$", "^(heavy(spin)?(fusor)?|spin(fusor)?|fusor)$", "^(devastator(spinfusor)?)$", "^(heavyboltlauncher|boltlauncher|bolt)$", "^((heavy)?blinks?(fusor)?)$", "^(heavytwinfusor|twinfusor|twin)$" };
            loadoutDetails["Heavy"]["timed"] = new List<string> { "Fusion Mortar", "Fusion Mortar Deluxe", "MIRV Launcher" };
            loadoutRegex["Heavy"]["timed"] = new List<String> { "^(fusionmortar|mortar)$", "^((fusion)?mortardeluxe)$", "^(mirvlauncher|mirv)$" };
            loadoutDetails["Heavy"]["specialty"] = new List<string> { "Saber Launcher", "Titan Launcher", "Gladiator" };
            loadoutRegex["Heavy"]["specialty"] = new List<String> { "^(saberlauncher|saber)$", "^(titanlauncher|titan)$", "^(gladiator)$" };
            loadoutDetails["Heavy"]["automatic"] = new List<string> { "Chaingun", "Chain Cannon", "X1 LMG", "Plasma Cannon" };
            loadoutRegex["Heavy"]["automatic"] = new List<String> { "^(chaingun)$", "^(chaincannon)$", "^(x1|lmg|x1lmg)$", "^(plasmacannon|plasma)$" };
            loadoutDetails["Heavy"]["shortrange"] = new List<string> { "Automatic Shotgun", "The Hammer", "EFG" };
            loadoutRegex["Heavy"]["shortrange"] = new List<String> { "^(automaticshotgun|shotgun)$", "^((the)?hammer)$", "^(efg)$" };
            loadoutDetails["Heavy"]["sidearms"] = new List<string> { "Nova Colt", "Nova Blaster MX" };
            loadoutRegex["Heavy"]["sidearms"] = new List<String> { "^(novacolt|colt|nova)$", "^(mx|novablastermx|novamx|blaster(mx)?)$" };

            loadoutDetails["Heavy"]["belt"] = new List<String> { "Frag Grenades", "Fractal Grenades", "Extended Fractals", "Light Sticky Grenades", "Mines", "Spinfusor Disks" };
            loadoutRegex["Heavy"]["belt"] = new List<String> { "^(fraggrenades?|frags?)$", "^(fractals?|fractalgrenades?)$", "^(extendedfractals?(grenades)?)$", "^(lightsticky(grenades?)?|lightstickies)$", "^(mines?)$", "^(spinfusordisks?|spinfusordiscs?|spins?|disks?|discs?|spindisks?|spindiscs?)$" };
            loadoutDetails["Heavy"]["pack"] = new List<String> { };
            loadoutRegex["Heavy"]["pack"] = new List<String> { };


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
                {"Console Chat Colour - PM", "whisperChatColor"},
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
                foreach (string type in new List<String> { "impact", "timed", "specialty", "automatic", "shortrange", "sidearms", "belt" })
                {
                    foreach (string weapon in loadoutDetails[(string)classSelector.SelectedItem][type])
                    {
                        weaponSelector.Items.Add(weapon);
                    }
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

                    curWeapon = findMatchingLoadoutItem(curClass, "primary", ((CrosshairSetting)listCrosshairs.SelectedItem).weapon);
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
            selectProjectileSwapWeapon.SelectedItem = null;
            selectProjectileSwapWeapon_Swap.SelectedItem = null;
            foreach (string type in new List<String> { "impact", "timed", "specialty", "automatic", "shortrange", "sidearms", "belt" })
            {
                if (selectProjectileSwapWeapon.SelectedItem == null)
                    selectProjectileSwapWeapon.SelectedItem = findMatchingLoadoutItem(((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.gameClass, type, ((ProjectileSwap)listProjectileSwap.SelectedItem).projectile.weapon);
                if (selectProjectileSwapWeapon_Swap.SelectedItem == null)
                    selectProjectileSwapWeapon_Swap.SelectedItem = findMatchingLoadoutItem(((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.gameClass, type, ((ProjectileSwap)listProjectileSwap.SelectedItem).swapProjectile.weapon);
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
            selectProjectileSettingWeapon.SelectedItem = null;
            foreach (string type in new List<String> { "impact", "timed", "specialty", "automatic", "shortrange", "sidearms", "belt" })
            {
                selectProjectileSettingWeapon.SelectedItem = findMatchingLoadoutItem(((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.gameClass, type, ((ProjectileSetting)listProjectileSetting.SelectedItem).projectile.weapon);
                if (selectProjectileSettingWeapon.SelectedItem != null)
                    break;
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


            string[] inputFiles = { };
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

        private void checkMouseDisableFovScaling_CheckedChanged(object sender, EventArgs e)
        {
            numMouseSensitivity.Enabled = checkMouseDisableFovScaling.Checked;
            numMouseZoomSensitivity.Enabled = checkMouseDisableFovScaling.Checked;
            numMouseZoom2Sensitivity.Enabled = checkMouseDisableFovScaling.Checked;
        }

        private void checkRouteDrawMarkers_CheckedChanged(object sender, EventArgs e)
        {
            numRouteDrawInterval.Enabled = checkRouteDrawMarkers.Checked;
        }

        private void checkRouteDrawETA_CheckedChanged(object sender, EventArgs e)
        {
            numRouteETAInterval.Enabled = checkRouteDrawETA.Checked;
        }

        private void selectProjectileSettingWeapon_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void colorProjectileSetting_Paint(object sender, PaintEventArgs e)
        {

        }

        private void selectWeaponModelSwapClass_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateSelectorWeaponListings(selectWeaponModelSwapWeapon, selectWeaponModelSwapClass);
        }

        private void selectWeaponModelSwapClass_Swap_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateSelectorWeaponListings(selectWeaponModelSwapWeapon_Swap, selectWeaponModelSwapClass_Swap);
        }

        private void listWeaponSwap_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listWeaponSwap.SelectedItem == null) return;

            // Select the right classes
            selectWeaponModelSwapClass.SelectedItem = config.getGameClassName(((WeaponModelSwap)listWeaponSwap.SelectedItem).origClass);
            selectWeaponModelSwapClass_Swap.SelectedItem = config.getGameClassName(((WeaponModelSwap)listWeaponSwap.SelectedItem).newClass);

            // Update weapon boxes (disabling events!)
            selectWeaponModelSwapClass.SelectedIndexChanged -= new EventHandler(selectProjectileSwapClass_SelectedIndexChanged);
            selectWeaponModelSwapClass_Swap.SelectedIndexChanged -= new EventHandler(selectProjectileSwapClass_Swap_SelectedIndexChanged);
            updateSelectorWeaponListings(selectWeaponModelSwapWeapon, selectWeaponModelSwapClass);
            updateSelectorWeaponListings(selectWeaponModelSwapWeapon_Swap, selectWeaponModelSwapClass_Swap);
            selectWeaponModelSwapClass.SelectedIndexChanged += new EventHandler(selectProjectileSwapClass_SelectedIndexChanged);
            selectWeaponModelSwapClass_Swap.SelectedIndexChanged += new EventHandler(selectProjectileSwapClass_Swap_SelectedIndexChanged);

            // Select the right weapons
            selectWeaponModelSwapWeapon.SelectedItem = null;
            selectWeaponModelSwapWeapon_Swap.SelectedItem = null;
            foreach (string type in new List<String> { "impact", "timed", "specialty", "automatic", "shortrange", "sidearms", "belt" })
            {
                if (selectWeaponModelSwapWeapon.SelectedItem == null)
                    selectWeaponModelSwapWeapon.SelectedItem = findMatchingLoadoutItem(((WeaponModelSwap)listWeaponSwap.SelectedItem).origClass, type, ((WeaponModelSwap)listWeaponSwap.SelectedItem).origWeapon);
                if (selectWeaponModelSwapWeapon_Swap.SelectedItem == null)
                    selectWeaponModelSwapWeapon_Swap.SelectedItem = findMatchingLoadoutItem(((WeaponModelSwap)listWeaponSwap.SelectedItem).newClass, type, ((WeaponModelSwap)listWeaponSwap.SelectedItem).newWeapon);
            }

            // Setup anim/pos checks
            checkWeaponModelSwapUpdateAnims.Checked = ((WeaponModelSwap)listWeaponSwap.SelectedItem).updateAnims;
            checkWeaponModelSwapUpdatePositioning.Checked = !((WeaponModelSwap)listWeaponSwap.SelectedItem).leavePositioning;
        }

        private void btnWeaponSwapSave_Click(object sender, EventArgs e)
        {
            if (selectWeaponModelSwapClass.SelectedItem == null || selectWeaponModelSwapWeapon.SelectedItem == null
                    || selectWeaponModelSwapClass_Swap.SelectedItem == null || selectWeaponModelSwapWeapon_Swap.SelectedItem == null) return;

            WeaponModelSwap newSwap = new WeaponModelSwap((string)selectWeaponModelSwapClass.SelectedItem, (string)selectWeaponModelSwapWeapon.SelectedItem,
                                                           (string)selectWeaponModelSwapClass_Swap.SelectedItem, (string)selectWeaponModelSwapWeapon_Swap.SelectedItem,
                                                           checkWeaponModelSwapUpdateAnims.Checked, !checkWeaponModelSwapUpdatePositioning.Checked);

            // Remove existing entries
            foreach (WeaponModelSwap swap in listWeaponSwap.Items)
            {
                if (swap.origClass == newSwap.origClass && swap.origWeapon == newSwap.origWeapon)
                {
                    listWeaponSwap.Items.Remove(swap);
                    break;
                }
            }

            listWeaponSwap.Items.Add(newSwap);
            listWeaponSwap.SelectedItem = newSwap;
        }

        private void btnWeaponSwapDelete_Click(object sender, EventArgs e)
        {
            if (listWeaponSwap.SelectedItem != null)
            {
                listWeaponSwap.Items.Remove(listWeaponSwap.SelectedItem);
            }
        }

        private void checkStatsRecord_CheckedChanged(object sender, EventArgs e)
        {
            checkStatsSave.Enabled = checkStatsRecord.Checked;
            if (!checkStatsSave.Enabled)
            {
                checkStatsSave.Checked = false;
            }
        }

        private void checkStatsRecordGame_CheckedChanged(object sender, EventArgs e)
        {
            checkStatsSaveGame.Enabled = checkStatsRecordGame.Checked;
            if (!checkStatsSaveGame.Enabled)
            {
                checkStatsSaveGame.Checked = false;
            }
        }
    }

}