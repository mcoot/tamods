/** @file */

/**
An array of floating point values
*/
struct FloatArray
{
	/**
	Adds a new number to the array

	@param elem	The number to add
	*/
	void add(number elem);

	/**
	Removes a number from the array

	@param index	The index of the number to remove, 0-indexed
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
	@return			The requested element
	*/
	number get(number n);

	/**
	Sets the n-th element of the array to the given value

	@param n		The index of the element to replace
	@param value	The new value of the element
	*/
	void set(number n, number value);
};

/**
A cooked raw distribution. The interesting values are in LookupTable, play a bit with them and print them to the console to see how they are structured.

If you have more info on how exactly these structures are created/work, please PM /u/ensiss
*/
struct RawDistribution
{
	/**
	The type of the distribution, seems to be the same number in most cases

	If you have more info on the possible values of this variable and their meaning, please PM /u/ensiss
	*/
	number Type;
	/**
	This variable seems to be the same number in most cases

	If you have more info on the possible values of this variable and their meaning, please PM /u/ensiss
	*/
	number Op;
	/**
	NOT the number of elements in the array, this was 1 in most cases. Use LookupTable:size() if you want the real number of elements.

	If you have more info on the possible values of this variable and their meaning, please PM /u/ensiss
	*/
	number NumElements;
	/**
	The size of an individual array element, seems to be 1 for floats and 3 for vectors
	*/
	number ChunkSize;
	/**
	The cooked array containing the distribution values

	If you have more info on how exactly these structures are created/work, please PM /u/ensiss
	*/
	FloatArray LookupTable;
	/**
	If you have more info on the possible values of this variable and their meaning, please PM /u/ensiss
	*/
	number TimeScale;
	/**
	If you have more info on the possible values of this variable and their meaning, please PM /u/ensiss
	*/
	number StartTime;
};

/**
A Raw Distribution of floating point values
*/
struct RawDistributionFloat : public RawDistribution
{
};

/**
A Raw Distribution of vectors
*/
struct RawDistributionVector : public RawDistribution
{
};

/**
Unreal Engine 3's base Object structure
*/
struct Object
{
	/**
	Returns the name of the object

	@return	The name of the object
	*/
	string getName();
	/**
	Returns the class name of the object

	@return	The class name of the object
	*/
	string getClassName();
	/**
	Returns the full name of the object

	@return	The full name of the object
	*/
	string getFullName();
};

/**
Auto-generated documentation for the ParticleModule: ParticleModule

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModule : public Object
{
	boolean bSpawnModule;
	boolean bUpdateModule;
	boolean bFinalUpdateModule;
	boolean bCurvesAsColor;
	boolean b3DDrawMode;
	boolean bSupported3DDrawMode;
	boolean bEnabled;
	boolean bEditable;
	boolean LODDuplicate;
	boolean bSupportsRandomSeed;
	boolean bRequiresLoopingNotification;
	number LODValidity;
	Color ModuleEditorColor;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleAccelerationBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleAccelerationBase : public ParticleModule
{
	boolean bAlwaysInWorldSpace;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleAcceleration

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleAcceleration : public ParticleModuleAccelerationBase
{
	RawDistributionVector Acceleration;
	boolean bApplyOwnerScale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleAccelerationOverLifetime

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleAccelerationOverLifetime : public ParticleModuleAccelerationBase
{
	RawDistributionVector AccelOverLife;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleAttractorBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleAttractorBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleAttractorLine

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleAttractorLine : public ParticleModuleAttractorBase
{
	Vector EndPoint0;
	Vector EndPoint1;
	RawDistributionFloat Range;
	RawDistributionFloat Strength;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleAttractorParticle

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleAttractorParticle : public ParticleModuleAttractorBase
{
	Name EmitterName;
	RawDistributionFloat Range;
	boolean bStrengthByDistance;
	boolean bAffectBaseVelocity;
	boolean bRenewSource;
	boolean bInheritSourceVel;
	RawDistributionFloat Strength;
	number SelectionMethod;
	number LastSelIndex;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleAttractorPoint

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleAttractorPoint : public ParticleModuleAttractorBase
{
	RawDistributionVector Position;
	RawDistributionFloat Range;
	RawDistributionFloat Strength;
	boolean StrengthByDistance;
	boolean bAffectBaseVelocity;
	boolean bOverrideVelocity;
	boolean bUseWorldSpacePosition;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleBeamBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleBeamBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleBeamModifier

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleBeamModifier : public ParticleModuleBeamBase
{
	number ModifierType;
	BeamModifierOptions PositionOptions;
	RawDistributionVector Position;
	BeamModifierOptions TangentOptions;
	RawDistributionVector Tangent;
	boolean bAbsoluteTangent;
	BeamModifierOptions StrengthOptions;
	RawDistributionFloat Strength;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleBeamNoise

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleBeamNoise : public ParticleModuleBeamBase
{
	boolean bLowFreq_Enabled;
	boolean bNRScaleEmitterTime;
	boolean bSmooth;
	boolean bNoiseLock;
	boolean bOscillate;
	boolean bUseNoiseTangents;
	boolean bTargetNoise;
	boolean bApplyNoiseScale;
	number Frequency;
	number Frequency_LowRange;
	RawDistributionVector NoiseRange;
	RawDistributionFloat NoiseRangeScale;
	RawDistributionVector NoiseSpeed;
	number NoiseLockRadius;
	number NoiseLockTime;
	number NoiseTension;
	RawDistributionFloat NoiseTangentStrength;
	number NoiseTessellation;
	number FrequencyDistance;
	RawDistributionFloat NoiseScale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleBeamSource

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleBeamSource : public ParticleModuleBeamBase
{
	number SourceMethod;
	number SourceTangentMethod;
	Name SourceName;
	boolean bSourceAbsolute;
	boolean bLockSource;
	boolean bLockSourceTangent;
	boolean bLockSourceStength;
	RawDistributionVector Source;
	RawDistributionVector SourceTangent;
	RawDistributionFloat SourceStrength;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleBeamTarget

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleBeamTarget : public ParticleModuleBeamBase
{
	number TargetMethod;
	number TargetTangentMethod;
	Name TargetName;
	RawDistributionVector Target;
	boolean bTargetAbsolute;
	boolean bLockTarget;
	boolean bLockTargetTangent;
	boolean bLockTargetStength;
	RawDistributionVector TargetTangent;
	RawDistributionFloat TargetStrength;
	number LockRadius;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleCameraBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleCameraBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleCameraOffset

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleCameraOffset : public ParticleModuleCameraBase
{
	RawDistributionFloat CameraOffset;
	boolean bSpawnTimeOnly;
	number UpdateMethod;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleCollisionBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleCollisionBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleCollision

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleCollision : public ParticleModuleCollisionBase
{
	RawDistributionVector DampingFactor;
	RawDistributionVector DampingFactorRotation;
	RawDistributionFloat MaxCollisions;
	number CollisionCompletionOption;
	boolean bApplyPhysics;
	boolean bPawnsDoNotDecrementCount;
	boolean bOnlyVerticalNormalsDecrementCount;
	boolean bDropDetail;
	RawDistributionFloat ParticleMass;
	number DirScalar;
	number VerticalFudgeFactor;
	RawDistributionFloat DelayAmount;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleColorBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleColorBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleColor

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleColor : public ParticleModuleColorBase
{
	RawDistributionVector StartColor;
	RawDistributionFloat StartAlpha;
	boolean bClampAlpha;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleColor_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleColor_Seeded : public ParticleModuleColor
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleColorByParameter

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleColorByParameter : public ParticleModuleColorBase
{
	Name ColorParam;
	Color DefaultColor;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleColorOverLife

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleColorOverLife : public ParticleModuleColorBase
{
	RawDistributionVector ColorOverLife;
	RawDistributionFloat AlphaOverLife;
	boolean bClampAlpha;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleColorScaleOverDensity

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleColorScaleOverDensity : public ParticleModuleColorBase
{
	RawDistributionVector ColorScaleOverDensity;
	RawDistributionFloat AlphaScaleOverDensity;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleColorScaleOverLife

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleColorScaleOverLife : public ParticleModuleColorBase
{
	RawDistributionVector ColorScaleOverLife;
	RawDistributionFloat AlphaScaleOverLife;
	boolean bEmitterTime;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleEventBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleEventBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleEventGenerator

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleEventGenerator : public ParticleModuleEventBase
{
	TArray< struct FParticleEvent_GenerateInfo > Events;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleEventReceiverBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleEventReceiverBase : public ParticleModuleEventBase
{
	number EventGeneratorType;
	Name EventName;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleEventReceiverKillParticles

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleEventReceiverKillParticles : public ParticleModuleEventReceiverBase
{
	boolean bStopSpawning;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleEventReceiverSpawn

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleEventReceiverSpawn : public ParticleModuleEventReceiverBase
{
	RawDistributionFloat SpawnCount;
	boolean bUseParticleTime;
	boolean bUsePSysLocation;
	boolean bInheritVelocity;
	RawDistributionVector InheritVelocityScale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleKillBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleKillBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleKillBox

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleKillBox : public ParticleModuleKillBase
{
	RawDistributionVector LowerLeftCorner;
	RawDistributionVector UpperRightCorner;
	boolean bAbsolute;
	boolean bKillInside;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleKillHeight

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleKillHeight : public ParticleModuleKillBase
{
	RawDistributionFloat Height;
	boolean bAbsolute;
	boolean bFloor;
	boolean bApplyPSysScale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLifetimeBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLifetimeBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLifetime

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLifetime : public ParticleModuleLifetimeBase
{
	RawDistributionFloat Lifetime;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLifetime_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLifetime_Seeded : public ParticleModuleLifetime
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocation

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocation : public ParticleModuleLocationBase
{
	RawDistributionVector StartLocation;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocation_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocation_Seeded : public ParticleModuleLocation
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationBoneSocket

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationBoneSocket : public ParticleModuleLocationBase
{
	number SourceType;
	number SelectionMethod;
	Vector UniversalOffset;
	TArray< struct FLocationBoneSocketInfo > SourceLocations;
	boolean bUpdatePositionEachFrame;
	boolean bOrientMeshEmitters;
	Name SkelMeshActorParamName;
	class USkeletalMesh* EditorSkelMesh;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationDirect

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationDirect : public ParticleModuleLocationBase
{
	RawDistributionVector Location;
	RawDistributionVector LocationOffset;
	RawDistributionVector ScaleFactor;
	RawDistributionVector Direction;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationEmitter

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationEmitter : public ParticleModuleLocationBase
{
	Name EmitterName;
	number SelectionMethod;
	boolean InheritSourceVelocity;
	boolean bInheritSourceRotation;
	number InheritSourceVelocityScale;
	number InheritSourceRotationScale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationEmitterDirect

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationEmitterDirect : public ParticleModuleLocationBase
{
	Name EmitterName;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationPrimitiveBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationPrimitiveBase : public ParticleModuleLocationBase
{
	boolean Positive_X;
	boolean Positive_Y;
	boolean Positive_Z;
	boolean Negative_X;
	boolean Negative_Y;
	boolean Negative_Z;
	boolean SurfaceOnly;
	boolean Velocity;
	RawDistributionFloat VelocityScale;
	RawDistributionVector StartLocation;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationPrimitiveCylinder

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationPrimitiveCylinder : public ParticleModuleLocationPrimitiveBase
{
	boolean RadialVelocity;
	RawDistributionFloat StartRadius;
	RawDistributionFloat StartHeight;
	number HeightAxis;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationPrimitiveCylinder_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationPrimitiveCylinder_Seeded : public ParticleModuleLocationPrimitiveCylinder
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationPrimitiveSphere

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationPrimitiveSphere : public ParticleModuleLocationPrimitiveBase
{
	RawDistributionFloat StartRadius;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleLocationPrimitiveSphere_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleLocationPrimitiveSphere_Seeded : public ParticleModuleLocationPrimitiveSphere
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSourceMovement

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSourceMovement : public ParticleModuleLocationBase
{
	RawDistributionVector SourceMovementScale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMaterialBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMaterialBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMaterialByParameter

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMaterialByParameter : public ParticleModuleMaterialBase
{
	TArray< struct FName > MaterialParameters;
	TArray< class UMaterialInterface* > DefaultMaterials;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMeshMaterial

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMeshMaterial : public ParticleModuleMaterialBase
{
	TArray< class UMaterialInterface* > MeshMaterials;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleOrbitBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleOrbitBase : public ParticleModule
{
	boolean bUseEmitterTime;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleOrbit

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleOrbit : public ParticleModuleOrbitBase
{
	number ChainMode;
	RawDistributionVector OffsetAmount;
	OrbitOptions OffsetOptions;
	RawDistributionVector RotationAmount;
	OrbitOptions RotationOptions;
	RawDistributionVector RotationRateAmount;
	OrbitOptions RotationRateOptions;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleOrientationBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleOrientationBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleOrientationAxisLock

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleOrientationAxisLock : public ParticleModuleOrientationBase
{
	number LockAxisFlags;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleParameterBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleParameterBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleParameterDynamic

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleParameterDynamic : public ParticleModuleParameterBase
{
	TArray< struct FEmitterDynamicParameter > DynamicParams;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleParameterDynamic_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleParameterDynamic_Seeded : public ParticleModuleParameterDynamic
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRequired

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRequired : public ParticleModule
{
	class UMaterialInterface* Material;
	number ScreenAlignment;
	number SortMode;
	number ParticleBurstMethod;
	number InterpolationMethod;
	number EmitterNormalsMode;
	boolean bUseLocalSpace;
	boolean bKillOnDeactivate;
	boolean bKillOnCompleted;
	boolean bRequiresSorting;
	boolean bUseLegacyEmitterTime;
	boolean bEmitterDurationUseRange;
	boolean bDurationRecalcEachLoop;
	boolean bEmitterDelayUseRange;
	boolean bDelayFirstLoopOnly;
	boolean bScaleUV;
	boolean bDirectUV;
	boolean bUseMaxDrawCount;
	number EmitterDuration;
	number EmitterDurationLow;
	number EmitterLoops;
	RawDistributionFloat SpawnRate;
	TArray< struct FParticleBurst > BurstList;
	number EmitterDelay;
	number EmitterDelayLow;
	number SubImages_Horizontal;
	number SubImages_Vertical;
	number RandomImageTime;
	number RandomImageChanges;
	number MaxDrawCount;
	number DownsampleThresholdScreenFraction;
	Vector NormalsSphereCenter;
	Vector NormalsCylinderDirection;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRotationBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRotationBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMeshRotation

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMeshRotation : public ParticleModuleRotationBase
{
	RawDistributionVector StartRotation;
	boolean bInheritParent;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMeshRotation_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMeshRotation_Seeded : public ParticleModuleMeshRotation
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRotation

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRotation : public ParticleModuleRotationBase
{
	RawDistributionFloat StartRotation;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRotation_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRotation_Seeded : public ParticleModuleRotation
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRotationOverLifetime

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRotationOverLifetime : public ParticleModuleRotationBase
{
	RawDistributionFloat RotationOverLife;
	boolean Scale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRotationRateBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRotationRateBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMeshRotationRate

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMeshRotationRate : public ParticleModuleRotationRateBase
{
	RawDistributionVector StartRotationRate;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMeshRotationRate_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMeshRotationRate_Seeded : public ParticleModuleMeshRotationRate
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMeshRotationRateMultiplyLife

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMeshRotationRateMultiplyLife : public ParticleModuleRotationRateBase
{
	RawDistributionVector LifeMultiplier;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleMeshRotationRateOverLife

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleMeshRotationRateOverLife : public ParticleModuleRotationRateBase
{
	RawDistributionVector RotRate;
	boolean bScaleRotRate;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRotationRate

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRotationRate : public ParticleModuleRotationRateBase
{
	RawDistributionFloat StartRotationRate;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRotationRate_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRotationRate_Seeded : public ParticleModuleRotationRate
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleRotationRateMultiplyLife

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleRotationRateMultiplyLife : public ParticleModuleRotationRateBase
{
	RawDistributionFloat LifeMultiplier;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSizeBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSizeBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSize

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSize : public ParticleModuleSizeBase
{
	RawDistributionVector StartSize;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSize_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSize_Seeded : public ParticleModuleSize
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSizeMultiplyLife

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSizeMultiplyLife : public ParticleModuleSizeBase
{
	RawDistributionVector LifeMultiplier;
	boolean MultiplyX;
	boolean MultiplyY;
	boolean MultiplyZ;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSizeMultiplyVelocity

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSizeMultiplyVelocity : public ParticleModuleSizeBase
{
	RawDistributionVector VelocityMultiplier;
	boolean MultiplyX;
	boolean MultiplyY;
	boolean MultiplyZ;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSizeScale

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSizeScale : public ParticleModuleSizeBase
{
	RawDistributionVector SizeScale;
	boolean EnableX;
	boolean EnableY;
	boolean EnableZ;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSizeScaleByTime

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSizeScaleByTime : public ParticleModuleSizeBase
{
	RawDistributionVector SizeScaleByTime;
	boolean bEnableX;
	boolean bEnableY;
	boolean bEnableZ;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSpawnBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSpawnBase : public ParticleModule
{
	boolean bProcessSpawnRate;
	boolean bProcessBurstList;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSpawn

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSpawn : public ParticleModuleSpawnBase
{
	RawDistributionFloat Rate;
	RawDistributionFloat RateScale;
	number ParticleBurstMethod;
	TArray< struct FParticleBurst > BurstList;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSpawnPerUnit

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSpawnPerUnit : public ParticleModuleSpawnBase
{
	number UnitScalar;
	RawDistributionFloat SpawnPerUnit;
	boolean bIgnoreSpawnRateWhenMoving;
	boolean bIgnoreMovementAlongX;
	boolean bIgnoreMovementAlongY;
	boolean bIgnoreMovementAlongZ;
	number MovementTolerance;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleStoreSpawnTimeBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleStoreSpawnTimeBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleStoreSpawnTime

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleStoreSpawnTime : public ParticleModuleStoreSpawnTimeBase
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSubUVBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSubUVBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSubUV

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSubUV : public ParticleModuleSubUVBase
{
	RawDistributionFloat SubImageIndex;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSubUVMovie

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSubUVMovie : public ParticleModuleSubUV
{
	boolean bUseEmitterTime;
	RawDistributionFloat FrameRate;
	number StartingFrame;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSubUVDirect

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSubUVDirect : public ParticleModuleSubUVBase
{
	RawDistributionVector SubUVPosition;
	RawDistributionVector SubUVSize;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleSubUVSelect

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleSubUVSelect : public ParticleModuleSubUVBase
{
	RawDistributionVector SubImageSelect;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTrailBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTrailBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTrailSource

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTrailSource : public ParticleModuleTrailBase
{
	number SourceMethod;
	number SelectionMethod;
	Name SourceName;
	RawDistributionFloat SourceStrength;
	boolean bLockSourceStength;
	boolean bInheritRotation;
	number SourceOffsetCount;
	TArray< struct FVector > SourceOffsetDefaults;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTrailSpawn

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTrailSpawn : public ParticleModuleTrailBase
{
	class UDistributionFloatParticleParameter* SpawnDistanceMap;
	number MinSpawnVelocity;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTrailTaper

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTrailTaper : public ParticleModuleTrailBase
{
	number TaperMethod;
	RawDistributionFloat TaperFactor;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataBase : public ParticleModule
{
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataAnimTrail

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataAnimTrail : public ParticleModuleTypeDataBase
{
	Name ControlEdgeName;
	number SheetsPerTrail;
	boolean bDeadTrailsOnDeactivate;
	boolean bClipSourceSegement;
	boolean bEnablePreviousTangentRecalculation;
	boolean bTangentRecalculationEveryFrame;
	boolean bRenderGeometry;
	boolean bRenderSpawnPoints;
	boolean bRenderTangents;
	boolean bRenderTessellation;
	number TilingDistance;
	number DistanceTessellationStepSize;
	number TangentTessellationScalar;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataApex

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataApex : public ParticleModuleTypeDataBase
{
	class UApexGenericAsset* ApexIOFX;
	class UApexGenericAsset* ApexEmitter;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataBeam

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataBeam : public ParticleModuleTypeDataBase
{
	number BeamMethod;
	number EndPointMethod;
	RawDistributionFloat Distance;
	RawDistributionVector EndPoint;
	number TessellationFactor;
	RawDistributionFloat EmitterStrength;
	RawDistributionFloat TargetStrength;
	RawDistributionVector EndPointDirection;
	number TextureTile;
	boolean RenderGeometry;
	boolean RenderDirectLine;
	boolean RenderLines;
	boolean RenderTessellation;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataBeam2

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataBeam2 : public ParticleModuleTypeDataBase
{
	number BeamMethod;
	number TaperMethod;
	number TextureTile;
	number TextureTileDistance;
	number Sheets;
	number MaxBeamCount;
	number Speed;
	number InterpolationPoints;
	boolean bAlwaysOn;
	boolean RenderGeometry;
	boolean RenderDirectLine;
	boolean RenderLines;
	boolean RenderTessellation;
	number UpVectorStepSize;
	Name BranchParentName;
	RawDistributionFloat Distance;
	RawDistributionFloat TaperFactor;
	RawDistributionFloat TaperScale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataMesh

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataMesh : public ParticleModuleTypeDataBase
{
	class UStaticMesh* Mesh;
	boolean CastShadows;
	boolean DoCollisions;
	boolean bAllowMotionBlur;
	boolean bOverrideMaterial;
	boolean bCameraFacing;
	boolean bApplyParticleRotationAsSpin;
	number MeshAlignment;
	number AxisLockOption;
	number CameraFacingUpAxisOption;
	number CameraFacingOption;
	number Pitch;
	number Roll;
	number Yaw;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataMeshPhysX

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataMeshPhysX : public ParticleModuleTypeDataMesh
{
	class UPhysXParticleSystem* PhysXParSys;
	number PhysXRotationMethod;
	number FluidRotationCoefficient;
	Pointer RenderInstance;
	PhysXEmitterVerticalLodProperties VerticalLod;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataPhysX

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataPhysX : public ParticleModuleTypeDataBase
{
	class UPhysXParticleSystem* PhysXParSys;
	PhysXEmitterVerticalLodProperties VerticalLod;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataRibbon

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataRibbon : public ParticleModuleTypeDataBase
{
	number MaxTessellationBetweenParticles;
	number SheetsPerTrail;
	number MaxTrailCount;
	number MaxParticleInTrailCount;
	boolean bDeadTrailsOnDeactivate;
	boolean bDeadTrailsOnSourceLoss;
	boolean bClipSourceSegement;
	boolean bEnablePreviousTangentRecalculation;
	boolean bTangentRecalculationEveryFrame;
	boolean bRenderGeometry;
	boolean bRenderSpawnPoints;
	boolean bRenderTangents;
	boolean bRenderTessellation;
	number RenderAxis;
	number TangentSpawningScalar;
	number TilingDistance;
	number DistanceTessellationStepSize;
	number TangentTessellationScalar;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataTrail

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataTrail : public ParticleModuleTypeDataBase
{
	boolean RenderGeometry;
	boolean RenderLines;
	boolean RenderTessellation;
	boolean Tapered;
	boolean SpawnByDistance;
	number TessellationFactor;
	RawDistributionFloat Tension;
	Vector SpawnDistance;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleTypeDataTrail2

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleTypeDataTrail2 : public ParticleModuleTypeDataBase
{
	number TessellationFactor;
	number TessellationFactorDistance;
	number TessellationStrength;
	number TextureTile;
	number Sheets;
	number MaxTrailCount;
	number MaxParticleInTrailCount;
	boolean bClipSourceSegement;
	boolean bClearTangents;
	boolean RenderGeometry;
	boolean RenderDirectLine;
	boolean RenderLines;
	boolean RenderTessellation;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleUberBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleUberBase : public ParticleModule
{
	TArray< struct FName > RequiredModules;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleUberLTISIVCL

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleUberLTISIVCL : public ParticleModuleUberBase
{
	RawDistributionFloat Lifetime;
	RawDistributionVector StartSize;
	RawDistributionVector StartVelocity;
	RawDistributionFloat StartVelocityRadial;
	RawDistributionVector ColorOverLife;
	RawDistributionFloat AlphaOverLife;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleUberLTISIVCLIL

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleUberLTISIVCLIL : public ParticleModuleUberBase
{
	RawDistributionFloat Lifetime;
	RawDistributionVector StartSize;
	RawDistributionVector StartVelocity;
	RawDistributionFloat StartVelocityRadial;
	RawDistributionVector ColorOverLife;
	RawDistributionFloat AlphaOverLife;
	RawDistributionVector StartLocation;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleUberLTISIVCLILIRSSBLIRR

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleUberLTISIVCLILIRSSBLIRR : public ParticleModuleUberBase
{
	RawDistributionFloat Lifetime;
	RawDistributionVector StartSize;
	RawDistributionVector StartVelocity;
	RawDistributionFloat StartVelocityRadial;
	RawDistributionVector ColorOverLife;
	RawDistributionFloat AlphaOverLife;
	RawDistributionVector StartLocation;
	RawDistributionFloat StartRotation;
	RawDistributionVector SizeLifeMultiplier;
	boolean SizeMultiplyX;
	boolean SizeMultiplyY;
	boolean SizeMultiplyZ;
	RawDistributionFloat StartRotationRate;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleUberRainDrops

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleUberRainDrops : public ParticleModuleUberBase
{
	number LifetimeMin;
	number LifetimeMax;
	Vector StartSizeMin;
	Vector StartSizeMax;
	Vector StartVelocityMin;
	Vector StartVelocityMax;
	number StartVelocityRadialMin;
	number StartVelocityRadialMax;
	Vector ColorOverLife;
	number AlphaOverLife;
	boolean bIsUsingCylinder;
	boolean bPositive_X;
	boolean bPositive_Y;
	boolean bPositive_Z;
	boolean bNegative_X;
	boolean bNegative_Y;
	boolean bNegative_Z;
	boolean bSurfaceOnly;
	boolean bVelocity;
	boolean bRadialVelocity;
	number PC_VelocityScale;
	Vector PC_StartLocation;
	number PC_StartRadius;
	number PC_StartHeight;
	number PC_HeightAxis;
	Vector StartLocationMin;
	Vector StartLocationMax;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleUberRainImpacts

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleUberRainImpacts : public ParticleModuleUberBase
{
	RawDistributionFloat Lifetime;
	RawDistributionVector StartSize;
	RawDistributionVector StartRotation;
	boolean bInheritParent;
	boolean MultiplyX;
	boolean MultiplyY;
	boolean MultiplyZ;
	boolean bIsUsingCylinder;
	boolean bPositive_X;
	boolean bPositive_Y;
	boolean bPositive_Z;
	boolean bNegative_X;
	boolean bNegative_Y;
	boolean bNegative_Z;
	boolean bSurfaceOnly;
	boolean bVelocity;
	boolean bRadialVelocity;
	RawDistributionVector LifeMultiplier;
	RawDistributionFloat PC_VelocityScale;
	RawDistributionVector PC_StartLocation;
	RawDistributionFloat PC_StartRadius;
	RawDistributionFloat PC_StartHeight;
	number PC_HeightAxis;
	RawDistributionVector ColorOverLife;
	RawDistributionFloat AlphaOverLife;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleUberRainSplashA

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleUberRainSplashA : public ParticleModuleUberBase
{
	RawDistributionFloat Lifetime;
	RawDistributionVector StartSize;
	RawDistributionVector StartRotation;
	boolean bInheritParent;
	boolean MultiplyX;
	boolean MultiplyY;
	boolean MultiplyZ;
	RawDistributionVector LifeMultiplier;
	RawDistributionVector ColorOverLife;
	RawDistributionFloat AlphaOverLife;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleUberRainSplashB

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleUberRainSplashB : public ParticleModuleUberBase
{
	RawDistributionFloat Lifetime;
	RawDistributionVector StartSize;
	RawDistributionVector ColorOverLife;
	RawDistributionFloat AlphaOverLife;
	RawDistributionVector LifeMultiplier;
	boolean MultiplyX;
	boolean MultiplyY;
	boolean MultiplyZ;
	RawDistributionFloat StartRotationRate;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleVelocityBase

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleVelocityBase : public ParticleModule
{
	boolean bInWorldSpace;
	boolean bApplyOwnerScale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleVelocity

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleVelocity : public ParticleModuleVelocityBase
{
	RawDistributionVector StartVelocity;
	RawDistributionFloat StartVelocityRadial;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleVelocity_Seeded

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleVelocity_Seeded : public ParticleModuleVelocity
{
	ParticleRandomSeedInfo RandomSeedInfo;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleVelocityInheritParent

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleVelocityInheritParent : public ParticleModuleVelocityBase
{
	RawDistributionVector Scale;
};

/**
Auto-generated documentation for the ParticleModule: ParticleModuleVelocityOverLifetime

For more information please visit https://udn.epicgames.com/Three/ParticleSystemReference.html
*/
struct ParticleModuleVelocityOverLifetime : public ParticleModuleVelocityBase
{
	RawDistributionVector VelOverLife;
	boolean Absolute;
};

/**
Used to group all the cast functions to cast from a ParticleModule to each one of the specifications
*/
namespace cast
{
	/**
	Casts a ParticleModule to ParticleModuleAccelerationBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleAccelerationBase ParticleModuleAccelerationBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleAcceleration

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleAcceleration ParticleModuleAcceleration(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleAccelerationOverLifetime

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleAccelerationOverLifetime ParticleModuleAccelerationOverLifetime(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleAttractorBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleAttractorBase ParticleModuleAttractorBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleAttractorLine

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleAttractorLine ParticleModuleAttractorLine(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleAttractorParticle

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleAttractorParticle ParticleModuleAttractorParticle(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleAttractorPoint

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleAttractorPoint ParticleModuleAttractorPoint(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleBeamBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleBeamBase ParticleModuleBeamBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleBeamModifier

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleBeamModifier ParticleModuleBeamModifier(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleBeamNoise

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleBeamNoise ParticleModuleBeamNoise(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleBeamSource

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleBeamSource ParticleModuleBeamSource(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleBeamTarget

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleBeamTarget ParticleModuleBeamTarget(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleCameraBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleCameraBase ParticleModuleCameraBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleCameraOffset

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleCameraOffset ParticleModuleCameraOffset(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleCollisionBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleCollisionBase ParticleModuleCollisionBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleCollision

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleCollision ParticleModuleCollision(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleColorBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleColorBase ParticleModuleColorBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleColor

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleColor ParticleModuleColor(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleColor_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleColor_Seeded ParticleModuleColor_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleColorByParameter

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleColorByParameter ParticleModuleColorByParameter(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleColorOverLife

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleColorOverLife ParticleModuleColorOverLife(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleColorScaleOverDensity

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleColorScaleOverDensity ParticleModuleColorScaleOverDensity(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleColorScaleOverLife

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleColorScaleOverLife ParticleModuleColorScaleOverLife(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleEventBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleEventBase ParticleModuleEventBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleEventGenerator

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleEventGenerator ParticleModuleEventGenerator(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleEventReceiverBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleEventReceiverBase ParticleModuleEventReceiverBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleEventReceiverKillParticles

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleEventReceiverKillParticles ParticleModuleEventReceiverKillParticles(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleEventReceiverSpawn

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleEventReceiverSpawn ParticleModuleEventReceiverSpawn(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleKillBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleKillBase ParticleModuleKillBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleKillBox

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleKillBox ParticleModuleKillBox(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleKillHeight

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleKillHeight ParticleModuleKillHeight(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLifetimeBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLifetimeBase ParticleModuleLifetimeBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLifetime

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLifetime ParticleModuleLifetime(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLifetime_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLifetime_Seeded ParticleModuleLifetime_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationBase ParticleModuleLocationBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocation

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocation ParticleModuleLocation(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocation_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocation_Seeded ParticleModuleLocation_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationBoneSocket

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationBoneSocket ParticleModuleLocationBoneSocket(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationDirect

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationDirect ParticleModuleLocationDirect(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationEmitter

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationEmitter ParticleModuleLocationEmitter(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationEmitterDirect

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationEmitterDirect ParticleModuleLocationEmitterDirect(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationPrimitiveBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationPrimitiveBase ParticleModuleLocationPrimitiveBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationPrimitiveCylinder

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationPrimitiveCylinder ParticleModuleLocationPrimitiveCylinder(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationPrimitiveCylinder_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationPrimitiveCylinder_Seeded ParticleModuleLocationPrimitiveCylinder_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationPrimitiveSphere

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationPrimitiveSphere ParticleModuleLocationPrimitiveSphere(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleLocationPrimitiveSphere_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleLocationPrimitiveSphere_Seeded ParticleModuleLocationPrimitiveSphere_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSourceMovement

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSourceMovement ParticleModuleSourceMovement(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMaterialBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMaterialBase ParticleModuleMaterialBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMaterialByParameter

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMaterialByParameter ParticleModuleMaterialByParameter(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMeshMaterial

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMeshMaterial ParticleModuleMeshMaterial(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleOrbitBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleOrbitBase ParticleModuleOrbitBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleOrbit

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleOrbit ParticleModuleOrbit(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleOrientationBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleOrientationBase ParticleModuleOrientationBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleOrientationAxisLock

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleOrientationAxisLock ParticleModuleOrientationAxisLock(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleParameterBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleParameterBase ParticleModuleParameterBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleParameterDynamic

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleParameterDynamic ParticleModuleParameterDynamic(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleParameterDynamic_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleParameterDynamic_Seeded ParticleModuleParameterDynamic_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRequired

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRequired ParticleModuleRequired(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRotationBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRotationBase ParticleModuleRotationBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMeshRotation

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMeshRotation ParticleModuleMeshRotation(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMeshRotation_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMeshRotation_Seeded ParticleModuleMeshRotation_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRotation

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRotation ParticleModuleRotation(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRotation_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRotation_Seeded ParticleModuleRotation_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRotationOverLifetime

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRotationOverLifetime ParticleModuleRotationOverLifetime(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRotationRateBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRotationRateBase ParticleModuleRotationRateBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMeshRotationRate

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMeshRotationRate ParticleModuleMeshRotationRate(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMeshRotationRate_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMeshRotationRate_Seeded ParticleModuleMeshRotationRate_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMeshRotationRateMultiplyLife

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMeshRotationRateMultiplyLife ParticleModuleMeshRotationRateMultiplyLife(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleMeshRotationRateOverLife

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleMeshRotationRateOverLife ParticleModuleMeshRotationRateOverLife(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRotationRate

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRotationRate ParticleModuleRotationRate(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRotationRate_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRotationRate_Seeded ParticleModuleRotationRate_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleRotationRateMultiplyLife

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleRotationRateMultiplyLife ParticleModuleRotationRateMultiplyLife(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSizeBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSizeBase ParticleModuleSizeBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSize

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSize ParticleModuleSize(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSize_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSize_Seeded ParticleModuleSize_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSizeMultiplyLife

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSizeMultiplyLife ParticleModuleSizeMultiplyLife(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSizeMultiplyVelocity

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSizeMultiplyVelocity ParticleModuleSizeMultiplyVelocity(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSizeScale

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSizeScale ParticleModuleSizeScale(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSizeScaleByTime

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSizeScaleByTime ParticleModuleSizeScaleByTime(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSpawnBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSpawnBase ParticleModuleSpawnBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSpawn

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSpawn ParticleModuleSpawn(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSpawnPerUnit

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSpawnPerUnit ParticleModuleSpawnPerUnit(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleStoreSpawnTimeBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleStoreSpawnTimeBase ParticleModuleStoreSpawnTimeBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleStoreSpawnTime

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleStoreSpawnTime ParticleModuleStoreSpawnTime(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSubUVBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSubUVBase ParticleModuleSubUVBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSubUV

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSubUV ParticleModuleSubUV(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSubUVMovie

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSubUVMovie ParticleModuleSubUVMovie(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSubUVDirect

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSubUVDirect ParticleModuleSubUVDirect(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleSubUVSelect

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleSubUVSelect ParticleModuleSubUVSelect(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTrailBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTrailBase ParticleModuleTrailBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTrailSource

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTrailSource ParticleModuleTrailSource(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTrailSpawn

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTrailSpawn ParticleModuleTrailSpawn(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTrailTaper

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTrailTaper ParticleModuleTrailTaper(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataBase ParticleModuleTypeDataBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataAnimTrail

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataAnimTrail ParticleModuleTypeDataAnimTrail(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataApex

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataApex ParticleModuleTypeDataApex(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataBeam

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataBeam ParticleModuleTypeDataBeam(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataBeam2

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataBeam2 ParticleModuleTypeDataBeam2(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataMesh

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataMesh ParticleModuleTypeDataMesh(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataMeshPhysX

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataMeshPhysX ParticleModuleTypeDataMeshPhysX(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataPhysX

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataPhysX ParticleModuleTypeDataPhysX(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataRibbon

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataRibbon ParticleModuleTypeDataRibbon(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataTrail

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataTrail ParticleModuleTypeDataTrail(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleTypeDataTrail2

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleTypeDataTrail2 ParticleModuleTypeDataTrail2(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleUberBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleUberBase ParticleModuleUberBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleUberLTISIVCL

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleUberLTISIVCL ParticleModuleUberLTISIVCL(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleUberLTISIVCLIL

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleUberLTISIVCLIL ParticleModuleUberLTISIVCLIL(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleUberLTISIVCLILIRSSBLIRR

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleUberLTISIVCLILIRSSBLIRR ParticleModuleUberLTISIVCLILIRSSBLIRR(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleUberRainDrops

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleUberRainDrops ParticleModuleUberRainDrops(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleUberRainImpacts

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleUberRainImpacts ParticleModuleUberRainImpacts(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleUberRainSplashA

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleUberRainSplashA ParticleModuleUberRainSplashA(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleUberRainSplashB

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleUberRainSplashB ParticleModuleUberRainSplashB(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleVelocityBase

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleVelocityBase ParticleModuleVelocityBase(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleVelocity

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleVelocity ParticleModuleVelocity(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleVelocity_Seeded

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleVelocity_Seeded ParticleModuleVelocity_Seeded(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleVelocityInheritParent

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleVelocityInheritParent ParticleModuleVelocityInheritParent(ParticleModule mod);

	/**
	Casts a ParticleModule to ParticleModuleVelocityOverLifetime

	@param mod	The module to cast
	@return		The casted module, or nil if the cast is not possible
	*/
	ParticleModuleVelocityOverLifetime ParticleModuleVelocityOverLifetime(ParticleModule mod);
};
