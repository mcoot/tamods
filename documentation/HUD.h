/** @file */

/**
HUD object, used to draw on screen and perform various other screen operations
*/
struct HUD
{
};

/**
Projects a world location on the screen

@param hud	The HUD object
@param vec	The world location to project
@return		The resulting screen position
*/
Vector project(HUD hud, Vector vec);

/**
Draws a string on the screen

@param hud		The HUD object
@param text		The string to display
@param color	The color to use
@param loc		Where to draw the text
@param scalex	The horizontal scaling of the text
@param scaley	The vertical scaling of the text
*/
void drawDamageNumber(HUD hud, string text, Color color, Vector loc, float scalex, float scaley);

/**
Checks if a given location is in front or behind the player

@param hud		The HUD object
@param loc		The location to check
@return			true if the location is visible, false otherwise
*/
bool isOnScreen(HUD hud, Vector loc);

/**
Returns the position of the player

@param hud		The HUD object
@return			The position of the player
*/
Vector getPlayerPos(HUD hud);

/**
Controls if the 1st person weapon model should be visible or not
*/
boolean showWeapon;

/**
Controls if the ammo counter should be displayed at all times

This is mainly intended for users who play without weapon models, as they have no way to tell how many ammo they have left

This feature also enhances the counter, now displaying the in-clip ammo as well as the total ammo remaining
*/
boolean showFirstPersonAmmo;

/**
The color of messages sent by allies in the console (~)
*/
Color friendlyChatColor;

/**
The color of messages sent by enemies in the console (~)
*/
Color enemyChatColor;

/**
The color of messages sent by allies in the in-game chat
*/
Color friendlyHUDChatColor;

/**
The color of messages sent by enemies in the in-game chat
*/
Color enemyHUDChatColor;

/**
The color of the name of allies

You can set this variable's alpha value to 0 to hide allies' names
*/
Color friendlyColor;

/**
The color of the name of enemies

You can set this variable's alpha value to 0 to hide enemies' names
*/
Color enemyColor;

/**
The color of enemies markers

You can set this variable's alpha value to 0 to hide the markers
*/
Color enemyMarkerColor;

/**
The color of enemies markers when you are mutual friends

You can set this variable's alpha value to 0 to hide the markers
*/
Color enemyIsFMarkerColor;

/**
The color of allies markers

You can set this variable's alpha value to 0 to hide the markers
*/
Color friendlyMarkerColor;

/**
The color of allies markers when you added them as friend

You can set this variable's alpha value to 0 to hide the markers
*/
Color friendlyIsFMarkerColor;

/**
The speed you need to have to activate the first mark of the ski bars to the sides of the screen
*/
number skiBarMin;

/**
The speed you need to have to activate the last mark of the ski bars to the sides of the screen
*/
number skiBarMax;

/**
If the base objectives icons (generator, vehicle pad, base turrets, etc) should be displayed
*/
boolean showObjectiveIcon;

/**
If the flag base icons (when the flag is not on stand) should be displayed
*/
boolean showFlagBaseIcon;

/**
If the flag icon should be displayed
*/
boolean showCTFBaseIcon;

/**
If the ammo drop icons should be displayed
*/
boolean showNuggetIcon;

/**
If the player icons (name, health, marker, etc) should be displayed
*/
boolean showPlayerIcon;

/**
If the vehicle icons should be displayed
*/
boolean showVehicleIcon;

/**
If the mines icons should be displayed
*/
boolean showMineIcon;

/**
If the sensors icons should be displayed
*/
boolean showSensorIcon;
