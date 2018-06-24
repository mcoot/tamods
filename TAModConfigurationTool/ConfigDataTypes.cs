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
    public abstract class ConfigItem : IComparable<ConfigItem>
    {
        public readonly string name;

        public ConfigItem(string name)
        {
            this.name = name;
        }

        public abstract void ReadFromConfig(Config config);

        public abstract void WriteToConfig(Config config);

        public override string ToString()
        {
            return name;
        }

        public int CompareTo(ConfigItem other)
        {
            return name.CompareTo(other.name);
        }

        public override bool Equals(object other)
        {
            ConfigVarItem cother = other as ConfigVarItem;
            if (cother == null)
            {
                return false;
            }

            return (name.Equals(cother.name));
        }

        public override int GetHashCode()
        {
            return name.GetHashCode();
        }

    }

    public class ConfigVarItem : ConfigItem
    {

        public readonly string var;
        public bool isOverridden;
        public object value;

        public ConfigVarItem(string name, string var, bool isOverridden)
            : base(name)
        {
            this.var = var;
            this.isOverridden = isOverridden;
        }

        public ConfigVarItem(string name, string var) : this(name, var, false) { }

        public override void ReadFromConfig(Config config)
        {
            value = config.getConfigVar(var);
            if (config.isConfigVarSet(var))
            {
                isOverridden = true;
            }
            else
            {
                isOverridden = false;
            }
        }

        public override void WriteToConfig(Config config)
        {
            if (isOverridden)
            {
                config.setConfigVar(var, value);
            }
            else
            {
                config.setConfigVar(var, null);
            }
        }
    }

    public class ConfigAssetFileItem : ConfigItem
    {
        public readonly string asset;
        public string inputFilename = null;
        public bool doWrite = false;
        public string enableVar = null;

        public ConfigAssetFileItem(string name, string asset, string enableVar)
            : base(name)
        {
            this.asset = asset;
            this.enableVar = enableVar;
        }

        public ConfigAssetFileItem(string name, string asset)
            : this(name, asset, null)
        {
            this.asset = asset;
        }

        public override void ReadFromConfig(Config config)
        {
            if (config.isAssetFileSet(asset))
            {
                doWrite = true;
                inputFilename = config.getAssetFile(asset);
            }
            else
            {
                doWrite = false;
                inputFilename = null;
            }
        }

        public override void WriteToConfig(Config config)
        {
            if (inputFilename == null)
            {
                doWrite = false;
            }

            // If an 'enable' variable for this asset exists in the config, write its value
            if (enableVar != null)
            {
                config.setConfigVar(enableVar, doWrite);
            }

            if (doWrite)
            {
                if (inputFilename == null)
                {
                    inputFilename = "";
                }


                // Handle relative paths
                if (inputFilename[0] == '\\')
                {
                    inputFilename = AppDomain.CurrentDomain.BaseDirectory + inputFilename;
                }

                config.setAssetFile(asset, inputFilename);
            }
            else
            {
                config.setAssetFile(asset, null);
            }
        }

    }

    public class ConfigSet : List<ConfigItem>, IComparable<ConfigSet>
    {
        public readonly string name;

        public ConfigSet(string name)
            : base()
        {
            this.name = name;
        }

        public void ReadFromConfig(Config config)
        {
            foreach (ConfigItem c in this)
            {
                c.ReadFromConfig(config);
            }
        }

        public void WriteToConfig(Config config)
        {
            foreach (ConfigItem c in this)
            {
                c.WriteToConfig(config);
            }
        }

        public ConfigSet() : this("") { }

        public int CompareTo(ConfigSet other)
        {
            // If names are equal, compare items
            if (name.Equals(other.name))
            {
                return base.ToString().CompareTo(other.ToString());
            }

            return name.CompareTo(other.name);
        }

        public override bool Equals(object obj)
        {
            ConfigSet c = obj as ConfigSet;
            if (c == null) return false;
            return name.Equals(c) && base.Equals(c);
        }

        public override int GetHashCode()
        {
            return name.GetHashCode() * 7 + base.GetHashCode();
        }
        public override string ToString()
        {
            return name.ToString();
        }
    }

    public class ConfigSetListWrapper
    {
        private ConfigSet set;

        public ConfigSetListWrapper(ConfigSet set)
        {
            this.set = set;
        }

        public ConfigSet getSet()
        {
            return set;
        }

        public void setSet(ConfigSet set)
        {
            this.set = set;
        }

        public override string ToString()
        {
            return set.name;
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
            if (other.gameClass.Equals(this.gameClass))
            {
                return this.num.CompareTo(other.num);
            }

            // If invalid gameClass, then just sort alphabetically
            if (!classOrder.Contains(this.gameClass) || !classOrder.Contains(other.gameClass))
            {
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

    public class CrosshairSetting : IComparable<CrosshairSetting>
    {
        public readonly string gameClass;
        public readonly string weapon;
        public readonly Crosshairs crosshairs;

        public CrosshairSetting(string gameClass, string weapon, Crosshairs crosshairs)
        {
            this.gameClass = gameClass;
            this.weapon = weapon;
            this.crosshairs = crosshairs;
        }

        public override string ToString()
        {
            return gameClass + ": " + weapon + " (" + crosshairs.standard + ", " + crosshairs.zoomed + ")";
        }

        public int CompareTo(CrosshairSetting other)
        {
            List<string> classOrder = new List<string>() { "pathfinder", "sentinel", "infiltrator", "soldier", "technician", "raider", "juggernaut", "doombringer", "brute" };
            // Sort by class first, then weapon
            if (other.gameClass.Equals(this.gameClass))
            {
                return this.weapon.CompareTo(other.weapon);
            }

            // If invalid gameClass, then just sort alphabetically
            if (!classOrder.Contains(this.gameClass) || !classOrder.Contains(other.gameClass))
            {
                return this.gameClass.CompareTo(other.gameClass);
            }

            return (classOrder.IndexOf(this.gameClass) - classOrder.IndexOf(other.gameClass));
        }

        public override bool Equals(object other)
        {
            // Return false if the other object cannot be cast to CrosshairSetting
            CrosshairSetting cother = other as CrosshairSetting;
            if ((object)cother == null)
            {
                return false;
            }

            if (this.gameClass == cother.gameClass && this.weapon == cother.weapon)
            {
                return true;
            }

            return false;
        }

        public override int GetHashCode()
        {
            return gameClass.GetHashCode() ^ weapon.GetHashCode();
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

        public readonly string standard;
        public readonly string zoomed;

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

    public class MutedPlayer : IComparable<MutedPlayer>
    {
        public readonly string username;
        public readonly bool muteVGS;
        public readonly bool muteText;
        public readonly bool muteDirectMessages;

        public MutedPlayer(string username, bool muteVGS, bool muteText, bool muteDirectMessages)
        {
            this.username = username;
            this.muteVGS = muteVGS;
            this.muteText = muteText;
            this.muteDirectMessages = muteDirectMessages;
        }

        public static MutedPlayer create_custom(string username, bool muteVGS, bool muteText, bool muteDirectMessages)
        {
            return new MutedPlayer(username, muteVGS, muteText, muteDirectMessages);
        }

        public static MutedPlayer create(string username)
        {
            return create_custom(username, true, true, true);
        }

        public int CompareTo(MutedPlayer other)
        {
            // Sort by username
            return (username.CompareTo(other.username));
        }

        public override bool Equals(object other)
        {
            // Return false if the other object cannot be cast to MutedPlayer
            MutedPlayer cother = other as MutedPlayer;
            if ((object)cother == null)
            {
                return false;
            }

            if (this.username.ToLower() == cother.username.ToLower())
            {
                return true;
            }

            return false;
        }

        public override int GetHashCode()
        {
            return username.GetHashCode();
        }

        public override string ToString()
        {
            return username + ": " + ((muteVGS) ? "VGS Muted" : "VGS On") + " / " + ((muteText) ? "Text Muted" : "Text On") + " / " + ((muteDirectMessages) ? "@ Muted" : "@ On");
        }


    }

    public class Projectile : IComparable<Projectile>
    {
        public string gameClass;
        public string weapon;
        public bool isClone;

        public Projectile(string gameClass, string weapon, bool isClone)
        {
            this.gameClass = gameClass;
            this.weapon = weapon;
            this.isClone = isClone;
        }

        public Projectile(string gameClass, string weapon) : this(gameClass, weapon, false) { }

        public static Projectile getProjectile(string gameClass, string weapon)
        {
            return new Projectile(gameClass, weapon);
        }

        public static Projectile cloneProjectile(Projectile projectile)
        {
            return new Projectile(projectile.gameClass, projectile.weapon, true);
        }

        public int CompareTo(Projectile other)
        {
            if (gameClass.Equals(other.gameClass))
            {
                return weapon.CompareTo(other.weapon);
            }

            return gameClass.CompareTo(other.gameClass);
        }

        public override bool Equals(object obj)
        {
            Projectile pother = obj as Projectile;
            if (pother == null)
            {
                return false;
            }

            return (gameClass.Equals(pother.gameClass) && weapon.Equals(pother.weapon) && isClone.Equals(pother.isClone));
        }

        public override int GetHashCode()
        {
            return gameClass.GetHashCode() * 11 + 19 * isClone.GetHashCode() + weapon.GetHashCode();
        }

        public override string ToString()
        {
            return gameClass + ": " + weapon + (isClone ? " (clone)" : "");
        }
    }

    public class ProjectileSetting : IComparable<ProjectileSetting>
    {
        public readonly Projectile projectile;
        public Color color;
        public float intensity;

        public ProjectileSetting(Projectile projectile, Color color, float intensity)
        {
            this.projectile = projectile;
            this.color = color;
            this.intensity = intensity;
        }

        public ProjectileSetting(Projectile projectile) : this(projectile, Color.White, 10) { }

        public static ProjectileSetting setProjectileColor(Projectile projectile, Color color, float intensity)
        {
            return new ProjectileSetting(projectile, color, intensity);
        }

        public int CompareTo(ProjectileSetting other)
        {
            return projectile.CompareTo(other.projectile);
        }

        public override bool Equals(object obj)
        {
            ProjectileSetting pother = obj as ProjectileSetting;
            if (pother == null)
            {
                return false;
            }

            return (projectile.Equals(pother.projectile));
        }

        public override int GetHashCode()
        {
            return projectile.GetHashCode();
        }

        public override string ToString()
        {
            return projectile.ToString();
        }
    }

    public class ProjectileSwap : IComparable<ProjectileSwap>
    {
        public readonly Projectile projectile;
        public Projectile swapProjectile;

        public ProjectileSwap(Projectile projectile, Projectile swapProjectile)
        {
            this.projectile = projectile;
            this.swapProjectile = swapProjectile;
        }

        public static ProjectileSwap setProjectile(string gameClass, string weapon, Projectile swapProjectile)
        {
            return new ProjectileSwap(Projectile.getProjectile(gameClass, weapon), swapProjectile);
        }

        public int CompareTo(ProjectileSwap other)
        {
            return projectile.CompareTo(other.projectile);
        }

        public override bool Equals(object obj)
        {
            ProjectileSwap pother = obj as ProjectileSwap;
            if (pother == null)
            {
                return false;
            }

            return (projectile.Equals(pother.projectile));
        }

        public override int GetHashCode()
        {
            return projectile.GetHashCode();
        }

        public override string ToString()
        {
            return projectile.ToString() + " -> " + swapProjectile.ToString();
        }
    }

    public class WeaponModelSwap : IComparable<WeaponModelSwap>
    {
        public readonly string origClass;
        public readonly string origWeapon;
        public string newClass;
        public string newWeapon;

        public WeaponModelSwap(string origClass, string origWeapon, string newClass, string newWeapon)
        {
            this.origClass = origClass;
            this.origWeapon = origWeapon;
            this.newClass = newClass;
            this.newWeapon = newWeapon;
        }

        public int CompareTo(WeaponModelSwap other)
        {
            if (origClass.CompareTo(other.origClass) != 0)
            {
                return origClass.CompareTo(other.origClass);
            }

            return origWeapon.CompareTo(other.origWeapon);
        }

        public override bool Equals(object obj)
        {
            WeaponModelSwap wother = obj as WeaponModelSwap;
            if (wother == null) return false;
            return (origClass.Equals(wother.origClass) && origWeapon.Equals(wother.origWeapon));
        }

        public override int GetHashCode()
        {
            return origClass.GetHashCode() + 29 * origWeapon.GetHashCode();
        }

        public override string ToString()
        {
            return $"{origClass}: {origWeapon} -> {newClass}: {newWeapon}";
        }
    }

}