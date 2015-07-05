/** @file */

/**
An object defining the items to use in a loadout
*/
struct Equipment
{
	/** The primary weapon */
	string primary;
	/** The secondary weapon */
	string secondary;
	/** The belt item */
	string belt;
	/** The pack */
	string pack;
	/** The primary perk */
	string perk1;
	/** The secondary perk */
	string perk2;
};

/**
Creates an Equipment object containing the items to be used

@param primary_weapon	The primary weapon
@param secondary_weapon	The secondary weapon
@param belt_item		The belt item
@param pack				The pack
@param primary_perk		The primary perk
@param secondary_perk	The secondary perk
@return					The created loadout
*/
Equipment equipment(string primary_weapon, string secondary_weapon, string belt_item, string pack, string primary_perk, string secondary_perk);

/**
Configures the loadout defined by a class and loadout number to use the specified items

This functions allows the use of 9 loadouts per class instead of 6

@param class_name	The name of the class to define
@param loadout_num	The number of the loadout to define, from 1 to 9
@param loadout		An Equipment object containing the items to use
*/
void setLoadout(string class_name, number loadout_num, Equipment loadout);
