/** @file */

/**
A damage number object
*/
struct DamageNumber
{
	/**
	The damage done that will be displayed
	*/
	number number;
	/**
	The time left before the damage number fades out
	*/
	number time;
	/**
	The 4D world location of the damage number
	*/
	Vector4 location;
	/**
	The color of the damage number
	*/
	Color color;
	/**
	The current scale
	*/
	number scale;
	/**
	If the damage number is from shield damage (base turret/sensor)
	*/
	boolean shieldDamage;

	/**
	Constructor of the damage number
	*/
	DamageNumber(number number, number time, Vector4 location, Color color, number scale, boolean shieldDamage);
};

/**
An array of damage numbers
*/
struct DamageNumberArray
{
	/**
	Adds a new damage number to the array

	@param dmg_num	The damage number to add
	*/
	void add(DamageNumber dmg_num);

	/**
	Removes a damage number from the array

	@param index	The index of the damage number to remove, 0-indexed
	*/
	void remove(number index);

	/**
	Removes all elements in the array
	*/
	void clear();

	/**
	Returns the number of elements in the array

	@return			The size of the array
	*/
	number size();

	/**
	Returns the n-th element of the array

	@param n		The index of the element to return
	@return			The element
	*/
	DamageNumber get(number n);
};

/**
This function will be called everytime a damage number is created, and will replace the default behaviour

You have to implement this function if you want to override the default damage number behaviour

@param dam_nums		The array that holds the already existing damage numbers
@param damage_value	The damage done and that will be displayed by the damage number
@param location		The 4d world position of the damage number
@param is_shield	If the damage number is shield (as in base turret or sensor shield) damage
*/
void onDamageNumberCreate(DamageNumberArray dam_nums, number damage_value, Vector4 location, boolean is_shield);

/**
This function will be called once per frame to update the damage numbers, and will replace the default behaviour

You have to implement this function if you want to override the default damage number behaviour

@param dam_nums		The array that holds the already existing damage numbers
@param hud			The HUD object that will allow you to draw the damage number and do variour things
@param time_delta	The time that passed since the last frame
*/
void onDamageNumberUpdate(DamageNumberArray dam_nums, HUD hud, number time_delta);

/**
Damage amount that needs to be done before damage numbers show up
*/
number damageNumbersLimit;

/**
Horizontal location of the damage numbers, relative to where they normally spawn
*/
number damageNumbersOffsetX;

/**
Vertical location of the damage numbers, relative to where they normally spawn

Keep in mind that a positive value will make the numbers appear lower, and a negative value will make them higher
*/
number damageNumbersOffsetY;

/**
The scale of the damage numbers

The default value is 1.0, 0.5 is half the size, etc
*/
number damageNumbersScale;

/**
If the damage numbers should add up the damage done instead of counting individual hits
*/
boolean showDamageNumberStream;

/**
If the damage numbers should show the number of hits done in a row instead of the damage done
*/
boolean showChainBulletHitCount;

/**
The number of seconds without hits needed to restart the damage numbers stream or bullet count
*/
number damageNumberStreamTimeout;

/**
The text that the damage numbers will show instead of the damage
*/
string damageNumberCustomText;

/**
If the damage number colors should change dynamically in rainbow colors
*/
boolean showRainbow;

/**
The initial color taken by the damage numbers

By default this color is white
*/
Color damageNumbersColorMin;

/**
The color that the damage numbers will take as they fade out

By default this color is red
*/
Color damageNumbersColorMax;
