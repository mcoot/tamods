/** @file */

/**
An array of particle modules
*/
struct ParticleModuleArray
{
	/**
	Adds a new element to the array

	@param elem	The element to add
	*/
	void add(ParticleModule elem);

	/**
	Removes an element from the array

	@param index	The index of the element to remove, 0-indexed
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
	ParticleModule get(number n);
};

/**
A Particle Level Of Detail Level, defining spawn and update modules
*/
struct ParticleLODLevel
{
	/**
	The modules that will be used to create the particles
	*/
	ParticleModuleArray spawnModules;
	/**
	The modules that will be used to update the particles
	*/
	ParticleModuleArray updateModules;
};

/**
An array of particle LOD levels
*/
struct ParticleLODLevelArray
{
	/**
	Adds a new element to the array

	@param elem	The element to add
	*/
	void add(ParticleLODLevel elem);

	/**
	Removes an element from the array

	@param index	The index of the element to remove, 0-indexed
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
	ParticleLODLevel get(number n);
};

/**
A particle emitter, containing one or more ParticleLODLevel
*/
struct ParticleEmitter
{
	/**
	The Levels Of Detail defined by the emitter
	*/
	ParticleLODLevelArray LODLevels;
};

/**
An array of particle emitters
*/
struct ParticleEmitterArray
{
	/**
	Adds a new element to the array

	@param elem	The element to add
	*/
	void add(DamageNumber elem);

	/**
	Removes an element from the array

	@param index	The index of the element to remove, 0-indexed
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
	ParticleEmitter get(number n);
};

/**
A particle system, containing one or more ParticleEmitter
*/
struct ParticleSystem
{
	/**
	The emitters in the system
	*/
	ParticleEmitterArray emitters;
};

/**
Returns the projectile used by a weapon

@param class_name	The class name
@param weapon_name	The weapon name
@return				The ParticleSystem defining the projectile
*/
ParticleSystem getProjectile(string class_name, string weapon_name);

/**
Clones a projectile so the modifications applied to one of the projectiles is not applied to the other

@param projectile	The projectile to clone
@return				The cloned projectile
*/
ParticleSystem cloneProjectile(ParticleSystem projectile);

/**
Override the default projectile for a weapon

@param class_name	The class name
@param weapon_name	The weapon name
@param projectile	The projectile to use for this weapon
*/
void setProjectile(string class_name, string weapon_name, ParticleSystem projectile);

/**
Sets the color and trail (for spinfusors, bolts, blasters, etc) color of a projectile

@param projectile	The projectile to modify
@param color		The new color of the projectile
@param intensity	The intensity of the color
*/
void setProjectileColor(ParticleSystem projectile, Color color, number intensity);
