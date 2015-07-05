/** @file */

/**
An object defining the crosshairs to use for the normal and zoomed states
*/
struct Crosshairs
{
	/**
	The crosshair to use in the normal state
	*/
	string standard;
	/**
	The crosshair to use in the zoomed state
	*/
	string zoomed;
};

/**
Creates a Crosshairs objects defining a standard and a zoomed crosshair

@param standard	The standard crosshair to use
@param zoomed	The zoomed crosshair to use
@return			The Crosshairs object containing the specified crosshairs
*/
Crosshairs crosshairs(string standard, string zoomed);

/**
Creates a Crosshairs objects using the same crosshair for both the normal and zoomed states

@param crosshair	The crosshair to use for both states
@return				The Crosshairs object containing the specified crosshair for all states
*/
Crosshairs crosshair(string crosshair);

/**
Sets the default and zoomed stock crosshairs to be used for a particular weapon

@param class_name	The name of the class that you want to edit
@param weapon_name	The name of the weapon that you want to edit
@param crosshairs	A Crosshairs object defining the default and zoomed crosshairs that you want
*/
void setCrosshairs(string class_name, string weapon_name, Crosshairs crosshairs);

/**
Allows to hide the stock crosshairs while keeping the hitmarkers
*/
boolean showCrosshair;

/**
Allows to scale the stock crosshairs

The default value is 1.0, 0.5 is half the size, etc
*/
number crosshairScale;

/**
The color of the stock crosshairs
*/
Color crosshairColor;
