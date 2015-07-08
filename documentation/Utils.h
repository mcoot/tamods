/** @file */

/*! \mainpage TAMods Lua scripting API documentation
*
* \section intro_sec Introduction
*
* TAMods is a tool that allows the players to customize their Tribes:Ascend. From interface color changes to custom sounds and projectiles, there's a lot you can change now to make Tribes Ascend exactly how you want it to be.
*
* For users who can't or don't want to code, there's also a configuration tool that allows to configure all the basic features really easily.
*
* This documentation is aimed at players who want to extend the features even more, and provide the Mods they're able to make to the community.
*
* \section install_sec Prerequisites
*
* \subsection programming Programming knowledge
*
* The whole scripting API for the mods is in Lua, but even if you don't know Lua it's a relatively simple programming language and there are some examples of what you can do with the mods, so if you follow these you should be fine.
*
* If you don't know how to code at all but you're interested, please give it a go anyway. There are a lot of tutorials about Lua to get you started.
*
* \subsection unreal_engine Unreal Engine 3
*
* To edit the projectiles you will need a bit of Unreal Engine 3 knowledge, but here again by playing around with the values and the examples you should be able to do what you want after some time. Also, don't hesitate to ask for help if you're stuck somewhere.
*
* \section sharing Sharing
*
* If you managed to do something useful, interesting or even just funny with the mods, please share it with the community. The game is still alive, we as developers are doing our best to bring new content and updates, but now it's time for the community to step up and show what you can do.
*
* \section examples Examples
*
* These examples must be copy/pasted in custom.lua in your config folder to work.
*
* \subsection damage_numbers Damage Numbers
*
* - <a href="http://pastebin.com/rqLqEJuu">Basic damage numbers</a>, with a lot of comments. If you remove all the comments you'll see that the code is very short and readable
* - <a href="http://pastebin.com/QFm7R8Pu">Static damage numbers</a>, this source code is not optimized so you will encounter performance issues after some time. As training, you can try to optimize it a bit (instead of drawing everything with some numbers at 0 scale, try to draw only those visible)
* - <a href="http://pastebin.com/76QyeUwW">Custom fancy damage numbers</a>, just to show off what's possible with scripting. There's a "lol" message in rainbow color, smoothly following where you hit with added "lol" for each hit. Also, damage numbers are still present and go in a random direction when they spawn.
* 
* \subsection projectiles Custom Projectiles
*
* - <a href="http://pastebin.com/iufQEdsJ">Example function</a>, these prints a lot of info about the projectiles that you give to them, and can change the projectile color to check if it's working
*
*/

/**
A color
*/
struct Color
{
	/**
	A byte defining the red component of the color
	*/
	number r;
	/**
	A byte defining the green component of the color
	*/
	number g;
	/**
	A byte defining the blue component of the color
	*/
	number b;
	/**
	A byte defining the opacity component of the color
	*/
	number a;
};

/**
A 3 dimentional vector
*/
struct Vector
{
	number x;
	number y;
	number z;

	/**
	Constructor of the Vector
	*/
	Vector(number x, number y, number z);
};

/**
A 4 dimentional vector
*/
struct Vector4
{
	number x;
	number y;
	number z;
	/**
	The depth of the vector
	*/
	number w;

	/**
	Constructor of the Vector4
	*/
	Vector4(number x, number y, number z, number w);
};

/**
Creates a full opaque (alpha = 255) color object

Equivalent of rgba(r, g, b, 255);

@param r	The red component of the color
@param g	The green component of the color
@param b	The blue component of the color
@return		The created color
*/
Color rgb(number r, number g, number b);

/**
Creates a color object

@param r	The red component of the color
@param g	The green component of the color
@param b	The blue component of the color
@param a	The opacity of the color
@return		The created color
*/
Color rgba(number r, number g, number b, number a);

/**
Prints a message to the console (~)

@param message	The message to print
*/
void print(string message);

/**
Prints a message to the console (~)

@param message	The message to print
*/
void console(string message);

/**
Prints a message to the console (~) in a given color

@param message	The message to print
@param color	The color to use to display the message
*/
void consoleRGB(string message, Color color);

/**
Open a new notification window with the given title and message

@param title	The title of the notification
@param message	The message to display
*/
void notify(string title, string message);
