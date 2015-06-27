#include "ParticleModuleHelper.h"

static void copyTArray(TArray<float> &out, TArray<float> &in)
{
	out.Data = (float *)malloc(in.Count * sizeof(float));
	memcpy(out.Data, in.Data, in.Count * sizeof(float));
}

void ParticleModuleHelper::copyModuleTArrays(UParticleModule *&out, UParticleModule *&in)
{
	if (in->IsA(UParticleModuleAcceleration::StaticClass()))
	{
		copyTArray(((UParticleModuleAcceleration *)out)->Acceleration.LookupTable, ((UParticleModuleAcceleration *)in)->Acceleration.LookupTable);
	}
	if (in->IsA(UParticleModuleAccelerationOverLifetime::StaticClass()))
	{
		copyTArray(((UParticleModuleAccelerationOverLifetime *)out)->AccelOverLife.LookupTable, ((UParticleModuleAccelerationOverLifetime *)in)->AccelOverLife.LookupTable);
	}
	if (in->IsA(UParticleModuleAttractorLine::StaticClass()))
	{
		copyTArray(((UParticleModuleAttractorLine *)out)->Range.LookupTable, ((UParticleModuleAttractorLine *)in)->Range.LookupTable);
		copyTArray(((UParticleModuleAttractorLine *)out)->Strength.LookupTable, ((UParticleModuleAttractorLine *)in)->Strength.LookupTable);
	}
	if (in->IsA(UParticleModuleAttractorParticle::StaticClass()))
	{
		copyTArray(((UParticleModuleAttractorParticle *)out)->Range.LookupTable, ((UParticleModuleAttractorParticle *)in)->Range.LookupTable);
		copyTArray(((UParticleModuleAttractorParticle *)out)->Strength.LookupTable, ((UParticleModuleAttractorParticle *)in)->Strength.LookupTable);
	}
	if (in->IsA(UParticleModuleAttractorPoint::StaticClass()))
	{
		copyTArray(((UParticleModuleAttractorPoint *)out)->Position.LookupTable, ((UParticleModuleAttractorPoint *)in)->Position.LookupTable);
		copyTArray(((UParticleModuleAttractorPoint *)out)->Range.LookupTable, ((UParticleModuleAttractorPoint *)in)->Range.LookupTable);
		copyTArray(((UParticleModuleAttractorPoint *)out)->Strength.LookupTable, ((UParticleModuleAttractorPoint *)in)->Strength.LookupTable);
	}
	if (in->IsA(UParticleModuleBeamModifier::StaticClass()))
	{
		copyTArray(((UParticleModuleBeamModifier *)out)->Position.LookupTable, ((UParticleModuleBeamModifier *)in)->Position.LookupTable);
		copyTArray(((UParticleModuleBeamModifier *)out)->Tangent.LookupTable, ((UParticleModuleBeamModifier *)in)->Tangent.LookupTable);
		copyTArray(((UParticleModuleBeamModifier *)out)->Strength.LookupTable, ((UParticleModuleBeamModifier *)in)->Strength.LookupTable);
	}
	if (in->IsA(UParticleModuleBeamNoise::StaticClass()))
	{
		copyTArray(((UParticleModuleBeamNoise *)out)->NoiseRange.LookupTable, ((UParticleModuleBeamNoise *)in)->NoiseRange.LookupTable);
		copyTArray(((UParticleModuleBeamNoise *)out)->NoiseRangeScale.LookupTable, ((UParticleModuleBeamNoise *)in)->NoiseRangeScale.LookupTable);
		copyTArray(((UParticleModuleBeamNoise *)out)->NoiseSpeed.LookupTable, ((UParticleModuleBeamNoise *)in)->NoiseSpeed.LookupTable);
		copyTArray(((UParticleModuleBeamNoise *)out)->NoiseTangentStrength.LookupTable, ((UParticleModuleBeamNoise *)in)->NoiseTangentStrength.LookupTable);
		copyTArray(((UParticleModuleBeamNoise *)out)->NoiseScale.LookupTable, ((UParticleModuleBeamNoise *)in)->NoiseScale.LookupTable);
	}
	if (in->IsA(UParticleModuleBeamSource::StaticClass()))
	{
		copyTArray(((UParticleModuleBeamSource *)out)->Source.LookupTable, ((UParticleModuleBeamSource *)in)->Source.LookupTable);
		copyTArray(((UParticleModuleBeamSource *)out)->SourceTangent.LookupTable, ((UParticleModuleBeamSource *)in)->SourceTangent.LookupTable);
		copyTArray(((UParticleModuleBeamSource *)out)->SourceStrength.LookupTable, ((UParticleModuleBeamSource *)in)->SourceStrength.LookupTable);
	}
	if (in->IsA(UParticleModuleBeamTarget::StaticClass()))
	{
		copyTArray(((UParticleModuleBeamTarget *)out)->Target.LookupTable, ((UParticleModuleBeamTarget *)in)->Target.LookupTable);
		copyTArray(((UParticleModuleBeamTarget *)out)->TargetTangent.LookupTable, ((UParticleModuleBeamTarget *)in)->TargetTangent.LookupTable);
		copyTArray(((UParticleModuleBeamTarget *)out)->TargetStrength.LookupTable, ((UParticleModuleBeamTarget *)in)->TargetStrength.LookupTable);
	}
	if (in->IsA(UParticleModuleCameraOffset::StaticClass()))
	{
		copyTArray(((UParticleModuleCameraOffset *)out)->CameraOffset.LookupTable, ((UParticleModuleCameraOffset *)in)->CameraOffset.LookupTable);
	}
	if (in->IsA(UParticleModuleCollision::StaticClass()))
	{
		copyTArray(((UParticleModuleCollision *)out)->DampingFactor.LookupTable, ((UParticleModuleCollision *)in)->DampingFactor.LookupTable);
		copyTArray(((UParticleModuleCollision *)out)->DampingFactorRotation.LookupTable, ((UParticleModuleCollision *)in)->DampingFactorRotation.LookupTable);
		copyTArray(((UParticleModuleCollision *)out)->MaxCollisions.LookupTable, ((UParticleModuleCollision *)in)->MaxCollisions.LookupTable);
		copyTArray(((UParticleModuleCollision *)out)->ParticleMass.LookupTable, ((UParticleModuleCollision *)in)->ParticleMass.LookupTable);
		copyTArray(((UParticleModuleCollision *)out)->DelayAmount.LookupTable, ((UParticleModuleCollision *)in)->DelayAmount.LookupTable);
	}
	if (in->IsA(UParticleModuleColor::StaticClass()))
	{
		copyTArray(((UParticleModuleColor *)out)->StartColor.LookupTable, ((UParticleModuleColor *)in)->StartColor.LookupTable);
		copyTArray(((UParticleModuleColor *)out)->StartAlpha.LookupTable, ((UParticleModuleColor *)in)->StartAlpha.LookupTable);
	}
	if (in->IsA(UParticleModuleColorOverLife::StaticClass()))
	{
		copyTArray(((UParticleModuleColorOverLife *)out)->ColorOverLife.LookupTable, ((UParticleModuleColorOverLife *)in)->ColorOverLife.LookupTable);
		copyTArray(((UParticleModuleColorOverLife *)out)->AlphaOverLife.LookupTable, ((UParticleModuleColorOverLife *)in)->AlphaOverLife.LookupTable);
	}
	if (in->IsA(UParticleModuleColorScaleOverDensity::StaticClass()))
	{
		copyTArray(((UParticleModuleColorScaleOverDensity *)out)->ColorScaleOverDensity.LookupTable, ((UParticleModuleColorScaleOverDensity *)in)->ColorScaleOverDensity.LookupTable);
		copyTArray(((UParticleModuleColorScaleOverDensity *)out)->AlphaScaleOverDensity.LookupTable, ((UParticleModuleColorScaleOverDensity *)in)->AlphaScaleOverDensity.LookupTable);
	}
	if (in->IsA(UParticleModuleColorScaleOverLife::StaticClass()))
	{
		copyTArray(((UParticleModuleColorScaleOverLife *)out)->ColorScaleOverLife.LookupTable, ((UParticleModuleColorScaleOverLife *)in)->ColorScaleOverLife.LookupTable);
		copyTArray(((UParticleModuleColorScaleOverLife *)out)->AlphaScaleOverLife.LookupTable, ((UParticleModuleColorScaleOverLife *)in)->AlphaScaleOverLife.LookupTable);
	}
	if (in->IsA(UParticleModuleEventReceiverSpawn::StaticClass()))
	{
		copyTArray(((UParticleModuleEventReceiverSpawn *)out)->SpawnCount.LookupTable, ((UParticleModuleEventReceiverSpawn *)in)->SpawnCount.LookupTable);
		copyTArray(((UParticleModuleEventReceiverSpawn *)out)->InheritVelocityScale.LookupTable, ((UParticleModuleEventReceiverSpawn *)in)->InheritVelocityScale.LookupTable);
	}
	if (in->IsA(UParticleModuleKillBox::StaticClass()))
	{
		copyTArray(((UParticleModuleKillBox *)out)->LowerLeftCorner.LookupTable, ((UParticleModuleKillBox *)in)->LowerLeftCorner.LookupTable);
		copyTArray(((UParticleModuleKillBox *)out)->UpperRightCorner.LookupTable, ((UParticleModuleKillBox *)in)->UpperRightCorner.LookupTable);
	}
	if (in->IsA(UParticleModuleKillHeight::StaticClass()))
	{
		copyTArray(((UParticleModuleKillHeight *)out)->Height.LookupTable, ((UParticleModuleKillHeight *)in)->Height.LookupTable);
	}
	if (in->IsA(UParticleModuleLifetime::StaticClass()))
	{
		copyTArray(((UParticleModuleLifetime *)out)->Lifetime.LookupTable, ((UParticleModuleLifetime *)in)->Lifetime.LookupTable);
	}
	if (in->IsA(UParticleModuleLocation::StaticClass()))
	{
		copyTArray(((UParticleModuleLocation *)out)->StartLocation.LookupTable, ((UParticleModuleLocation *)in)->StartLocation.LookupTable);
	}
	if (in->IsA(UParticleModuleLocationDirect::StaticClass()))
	{
		copyTArray(((UParticleModuleLocationDirect *)out)->Location.LookupTable, ((UParticleModuleLocationDirect *)in)->Location.LookupTable);
		copyTArray(((UParticleModuleLocationDirect *)out)->LocationOffset.LookupTable, ((UParticleModuleLocationDirect *)in)->LocationOffset.LookupTable);
		copyTArray(((UParticleModuleLocationDirect *)out)->ScaleFactor.LookupTable, ((UParticleModuleLocationDirect *)in)->ScaleFactor.LookupTable);
		copyTArray(((UParticleModuleLocationDirect *)out)->Direction.LookupTable, ((UParticleModuleLocationDirect *)in)->Direction.LookupTable);
	}
	if (in->IsA(UParticleModuleLocationPrimitiveCylinder::StaticClass()))
	{
		copyTArray(((UParticleModuleLocationPrimitiveCylinder *)out)->StartRadius.LookupTable, ((UParticleModuleLocationPrimitiveCylinder *)in)->StartRadius.LookupTable);
		copyTArray(((UParticleModuleLocationPrimitiveCylinder *)out)->StartHeight.LookupTable, ((UParticleModuleLocationPrimitiveCylinder *)in)->StartHeight.LookupTable);
	}
	if (in->IsA(UParticleModuleLocationPrimitiveSphere::StaticClass()))
	{
		copyTArray(((UParticleModuleLocationPrimitiveSphere *)out)->StartRadius.LookupTable, ((UParticleModuleLocationPrimitiveSphere *)in)->StartRadius.LookupTable);
	}
	if (in->IsA(UParticleModuleSourceMovement::StaticClass()))
	{
		copyTArray(((UParticleModuleSourceMovement *)out)->SourceMovementScale.LookupTable, ((UParticleModuleSourceMovement *)in)->SourceMovementScale.LookupTable);
	}
	if (in->IsA(UParticleModuleOrbit::StaticClass()))
	{
		copyTArray(((UParticleModuleOrbit *)out)->OffsetAmount.LookupTable, ((UParticleModuleOrbit *)in)->OffsetAmount.LookupTable);
		copyTArray(((UParticleModuleOrbit *)out)->RotationAmount.LookupTable, ((UParticleModuleOrbit *)in)->RotationAmount.LookupTable);
		copyTArray(((UParticleModuleOrbit *)out)->RotationRateAmount.LookupTable, ((UParticleModuleOrbit *)in)->RotationRateAmount.LookupTable);
	}
	if (in->IsA(UParticleModuleRequired::StaticClass()))
	{
		copyTArray(((UParticleModuleRequired *)out)->SpawnRate.LookupTable, ((UParticleModuleRequired *)in)->SpawnRate.LookupTable);
	}
	if (in->IsA(UParticleModuleMeshRotation::StaticClass()))
	{
		copyTArray(((UParticleModuleMeshRotation *)out)->StartRotation.LookupTable, ((UParticleModuleMeshRotation *)in)->StartRotation.LookupTable);
	}
	if (in->IsA(UParticleModuleRotation::StaticClass()))
	{
		copyTArray(((UParticleModuleRotation *)out)->StartRotation.LookupTable, ((UParticleModuleRotation *)in)->StartRotation.LookupTable);
	}
	if (in->IsA(UParticleModuleRotationOverLifetime::StaticClass()))
	{
		copyTArray(((UParticleModuleRotationOverLifetime *)out)->RotationOverLife.LookupTable, ((UParticleModuleRotationOverLifetime *)in)->RotationOverLife.LookupTable);
	}
	if (in->IsA(UParticleModuleMeshRotationRate::StaticClass()))
	{
		copyTArray(((UParticleModuleMeshRotationRate *)out)->StartRotationRate.LookupTable, ((UParticleModuleMeshRotationRate *)in)->StartRotationRate.LookupTable);
	}
	if (in->IsA(UParticleModuleMeshRotationRateMultiplyLife::StaticClass()))
	{
		copyTArray(((UParticleModuleMeshRotationRateMultiplyLife *)out)->LifeMultiplier.LookupTable, ((UParticleModuleMeshRotationRateMultiplyLife *)in)->LifeMultiplier.LookupTable);
	}
	if (in->IsA(UParticleModuleMeshRotationRateOverLife::StaticClass()))
	{
		copyTArray(((UParticleModuleMeshRotationRateOverLife *)out)->RotRate.LookupTable, ((UParticleModuleMeshRotationRateOverLife *)in)->RotRate.LookupTable);
	}
	if (in->IsA(UParticleModuleRotationRate::StaticClass()))
	{
		copyTArray(((UParticleModuleRotationRate *)out)->StartRotationRate.LookupTable, ((UParticleModuleRotationRate *)in)->StartRotationRate.LookupTable);
	}
	if (in->IsA(UParticleModuleRotationRateMultiplyLife::StaticClass()))
	{
		copyTArray(((UParticleModuleRotationRateMultiplyLife *)out)->LifeMultiplier.LookupTable, ((UParticleModuleRotationRateMultiplyLife *)in)->LifeMultiplier.LookupTable);
	}
	if (in->IsA(UParticleModuleSize::StaticClass()))
	{
		copyTArray(((UParticleModuleSize *)out)->StartSize.LookupTable, ((UParticleModuleSize *)in)->StartSize.LookupTable);
	}
	if (in->IsA(UParticleModuleSizeMultiplyLife::StaticClass()))
	{
		copyTArray(((UParticleModuleSizeMultiplyLife *)out)->LifeMultiplier.LookupTable, ((UParticleModuleSizeMultiplyLife *)in)->LifeMultiplier.LookupTable);
	}
	if (in->IsA(UParticleModuleSizeMultiplyVelocity::StaticClass()))
	{
		copyTArray(((UParticleModuleSizeMultiplyVelocity *)out)->VelocityMultiplier.LookupTable, ((UParticleModuleSizeMultiplyVelocity *)in)->VelocityMultiplier.LookupTable);
	}
	if (in->IsA(UParticleModuleSizeScale::StaticClass()))
	{
		copyTArray(((UParticleModuleSizeScale *)out)->SizeScale.LookupTable, ((UParticleModuleSizeScale *)in)->SizeScale.LookupTable);
	}
	if (in->IsA(UParticleModuleSizeScaleByTime::StaticClass()))
	{
		copyTArray(((UParticleModuleSizeScaleByTime *)out)->SizeScaleByTime.LookupTable, ((UParticleModuleSizeScaleByTime *)in)->SizeScaleByTime.LookupTable);
	}
	if (in->IsA(UParticleModuleSpawn::StaticClass()))
	{
		copyTArray(((UParticleModuleSpawn *)out)->Rate.LookupTable, ((UParticleModuleSpawn *)in)->Rate.LookupTable);
		copyTArray(((UParticleModuleSpawn *)out)->RateScale.LookupTable, ((UParticleModuleSpawn *)in)->RateScale.LookupTable);
	}
	if (in->IsA(UParticleModuleSpawnPerUnit::StaticClass()))
	{
		copyTArray(((UParticleModuleSpawnPerUnit *)out)->SpawnPerUnit.LookupTable, ((UParticleModuleSpawnPerUnit *)in)->SpawnPerUnit.LookupTable);
	}
	if (in->IsA(UParticleModuleSubUV::StaticClass()))
	{
		copyTArray(((UParticleModuleSubUV *)out)->SubImageIndex.LookupTable, ((UParticleModuleSubUV *)in)->SubImageIndex.LookupTable);
	}
	if (in->IsA(UParticleModuleSubUVMovie::StaticClass()))
	{
		copyTArray(((UParticleModuleSubUVMovie *)out)->FrameRate.LookupTable, ((UParticleModuleSubUVMovie *)in)->FrameRate.LookupTable);
	}
	if (in->IsA(UParticleModuleSubUVDirect::StaticClass()))
	{
		copyTArray(((UParticleModuleSubUVDirect *)out)->SubUVPosition.LookupTable, ((UParticleModuleSubUVDirect *)in)->SubUVPosition.LookupTable);
		copyTArray(((UParticleModuleSubUVDirect *)out)->SubUVSize.LookupTable, ((UParticleModuleSubUVDirect *)in)->SubUVSize.LookupTable);
	}
	if (in->IsA(UParticleModuleSubUVSelect::StaticClass()))
	{
		copyTArray(((UParticleModuleSubUVSelect *)out)->SubImageSelect.LookupTable, ((UParticleModuleSubUVSelect *)in)->SubImageSelect.LookupTable);
	}
	if (in->IsA(UParticleModuleTrailSource::StaticClass()))
	{
		copyTArray(((UParticleModuleTrailSource *)out)->SourceStrength.LookupTable, ((UParticleModuleTrailSource *)in)->SourceStrength.LookupTable);
	}
	if (in->IsA(UParticleModuleTrailTaper::StaticClass()))
	{
		copyTArray(((UParticleModuleTrailTaper *)out)->TaperFactor.LookupTable, ((UParticleModuleTrailTaper *)in)->TaperFactor.LookupTable);
	}
	if (in->IsA(UParticleModuleTypeDataBeam::StaticClass()))
	{
		copyTArray(((UParticleModuleTypeDataBeam *)out)->Distance.LookupTable, ((UParticleModuleTypeDataBeam *)in)->Distance.LookupTable);
		copyTArray(((UParticleModuleTypeDataBeam *)out)->EndPoint.LookupTable, ((UParticleModuleTypeDataBeam *)in)->EndPoint.LookupTable);
		copyTArray(((UParticleModuleTypeDataBeam *)out)->EmitterStrength.LookupTable, ((UParticleModuleTypeDataBeam *)in)->EmitterStrength.LookupTable);
		copyTArray(((UParticleModuleTypeDataBeam *)out)->TargetStrength.LookupTable, ((UParticleModuleTypeDataBeam *)in)->TargetStrength.LookupTable);
		copyTArray(((UParticleModuleTypeDataBeam *)out)->EndPointDirection.LookupTable, ((UParticleModuleTypeDataBeam *)in)->EndPointDirection.LookupTable);
	}
	if (in->IsA(UParticleModuleTypeDataBeam2::StaticClass()))
	{
		copyTArray(((UParticleModuleTypeDataBeam2 *)out)->Distance.LookupTable, ((UParticleModuleTypeDataBeam2 *)in)->Distance.LookupTable);
		copyTArray(((UParticleModuleTypeDataBeam2 *)out)->TaperFactor.LookupTable, ((UParticleModuleTypeDataBeam2 *)in)->TaperFactor.LookupTable);
		copyTArray(((UParticleModuleTypeDataBeam2 *)out)->TaperScale.LookupTable, ((UParticleModuleTypeDataBeam2 *)in)->TaperScale.LookupTable);
	}
	if (in->IsA(UParticleModuleTypeDataTrail::StaticClass()))
	{
		copyTArray(((UParticleModuleTypeDataTrail *)out)->Tension.LookupTable, ((UParticleModuleTypeDataTrail *)in)->Tension.LookupTable);
	}
	if (in->IsA(UParticleModuleUberLTISIVCL::StaticClass()))
	{
		copyTArray(((UParticleModuleUberLTISIVCL *)out)->Lifetime.LookupTable, ((UParticleModuleUberLTISIVCL *)in)->Lifetime.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCL *)out)->StartSize.LookupTable, ((UParticleModuleUberLTISIVCL *)in)->StartSize.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCL *)out)->StartVelocity.LookupTable, ((UParticleModuleUberLTISIVCL *)in)->StartVelocity.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCL *)out)->StartVelocityRadial.LookupTable, ((UParticleModuleUberLTISIVCL *)in)->StartVelocityRadial.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCL *)out)->ColorOverLife.LookupTable, ((UParticleModuleUberLTISIVCL *)in)->ColorOverLife.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCL *)out)->AlphaOverLife.LookupTable, ((UParticleModuleUberLTISIVCL *)in)->AlphaOverLife.LookupTable);
	}
	if (in->IsA(UParticleModuleUberLTISIVCLIL::StaticClass()))
	{
		copyTArray(((UParticleModuleUberLTISIVCLIL *)out)->Lifetime.LookupTable, ((UParticleModuleUberLTISIVCLIL *)in)->Lifetime.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLIL *)out)->StartSize.LookupTable, ((UParticleModuleUberLTISIVCLIL *)in)->StartSize.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLIL *)out)->StartVelocity.LookupTable, ((UParticleModuleUberLTISIVCLIL *)in)->StartVelocity.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLIL *)out)->StartVelocityRadial.LookupTable, ((UParticleModuleUberLTISIVCLIL *)in)->StartVelocityRadial.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLIL *)out)->ColorOverLife.LookupTable, ((UParticleModuleUberLTISIVCLIL *)in)->ColorOverLife.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLIL *)out)->AlphaOverLife.LookupTable, ((UParticleModuleUberLTISIVCLIL *)in)->AlphaOverLife.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLIL *)out)->StartLocation.LookupTable, ((UParticleModuleUberLTISIVCLIL *)in)->StartLocation.LookupTable);
	}
	if (in->IsA(UParticleModuleUberLTISIVCLILIRSSBLIRR::StaticClass()))
	{
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->Lifetime.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->Lifetime.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->StartSize.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->StartSize.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->StartVelocity.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->StartVelocity.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->StartVelocityRadial.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->StartVelocityRadial.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->ColorOverLife.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->ColorOverLife.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->AlphaOverLife.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->AlphaOverLife.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->StartLocation.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->StartLocation.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->StartRotation.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->StartRotation.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->SizeLifeMultiplier.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->SizeLifeMultiplier.LookupTable);
		copyTArray(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)out)->StartRotationRate.LookupTable, ((UParticleModuleUberLTISIVCLILIRSSBLIRR *)in)->StartRotationRate.LookupTable);
	}
	if (in->IsA(UParticleModuleUberRainImpacts::StaticClass()))
	{
		copyTArray(((UParticleModuleUberRainImpacts *)out)->Lifetime.LookupTable, ((UParticleModuleUberRainImpacts *)in)->Lifetime.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->StartSize.LookupTable, ((UParticleModuleUberRainImpacts *)in)->StartSize.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->StartRotation.LookupTable, ((UParticleModuleUberRainImpacts *)in)->StartRotation.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->LifeMultiplier.LookupTable, ((UParticleModuleUberRainImpacts *)in)->LifeMultiplier.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->PC_VelocityScale.LookupTable, ((UParticleModuleUberRainImpacts *)in)->PC_VelocityScale.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->PC_StartLocation.LookupTable, ((UParticleModuleUberRainImpacts *)in)->PC_StartLocation.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->PC_StartRadius.LookupTable, ((UParticleModuleUberRainImpacts *)in)->PC_StartRadius.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->PC_StartHeight.LookupTable, ((UParticleModuleUberRainImpacts *)in)->PC_StartHeight.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->ColorOverLife.LookupTable, ((UParticleModuleUberRainImpacts *)in)->ColorOverLife.LookupTable);
		copyTArray(((UParticleModuleUberRainImpacts *)out)->AlphaOverLife.LookupTable, ((UParticleModuleUberRainImpacts *)in)->AlphaOverLife.LookupTable);
	}
	if (in->IsA(UParticleModuleUberRainSplashA::StaticClass()))
	{
		copyTArray(((UParticleModuleUberRainSplashA *)out)->Lifetime.LookupTable, ((UParticleModuleUberRainSplashA *)in)->Lifetime.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashA *)out)->StartSize.LookupTable, ((UParticleModuleUberRainSplashA *)in)->StartSize.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashA *)out)->StartRotation.LookupTable, ((UParticleModuleUberRainSplashA *)in)->StartRotation.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashA *)out)->LifeMultiplier.LookupTable, ((UParticleModuleUberRainSplashA *)in)->LifeMultiplier.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashA *)out)->ColorOverLife.LookupTable, ((UParticleModuleUberRainSplashA *)in)->ColorOverLife.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashA *)out)->AlphaOverLife.LookupTable, ((UParticleModuleUberRainSplashA *)in)->AlphaOverLife.LookupTable);
	}
	if (in->IsA(UParticleModuleUberRainSplashB::StaticClass()))
	{
		copyTArray(((UParticleModuleUberRainSplashB *)out)->Lifetime.LookupTable, ((UParticleModuleUberRainSplashB *)in)->Lifetime.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashB *)out)->StartSize.LookupTable, ((UParticleModuleUberRainSplashB *)in)->StartSize.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashB *)out)->ColorOverLife.LookupTable, ((UParticleModuleUberRainSplashB *)in)->ColorOverLife.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashB *)out)->AlphaOverLife.LookupTable, ((UParticleModuleUberRainSplashB *)in)->AlphaOverLife.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashB *)out)->LifeMultiplier.LookupTable, ((UParticleModuleUberRainSplashB *)in)->LifeMultiplier.LookupTable);
		copyTArray(((UParticleModuleUberRainSplashB *)out)->StartRotationRate.LookupTable, ((UParticleModuleUberRainSplashB *)in)->StartRotationRate.LookupTable);
	}
	if (in->IsA(UParticleModuleVelocity::StaticClass()))
	{
		copyTArray(((UParticleModuleVelocity *)out)->StartVelocity.LookupTable, ((UParticleModuleVelocity *)in)->StartVelocity.LookupTable);
		copyTArray(((UParticleModuleVelocity *)out)->StartVelocityRadial.LookupTable, ((UParticleModuleVelocity *)in)->StartVelocityRadial.LookupTable);
	}
	if (in->IsA(UParticleModuleVelocityInheritParent::StaticClass()))
	{
		copyTArray(((UParticleModuleVelocityInheritParent *)out)->Scale.LookupTable, ((UParticleModuleVelocityInheritParent *)in)->Scale.LookupTable);
	}
	if (in->IsA(UParticleModuleVelocityOverLifetime::StaticClass()))
	{
		copyTArray(((UParticleModuleVelocityOverLifetime *)out)->VelOverLife.LookupTable, ((UParticleModuleVelocityOverLifetime *)in)->VelOverLife.LookupTable);
	}
}

// Really ugly I know but the SDK doesn't like virtual functions, so a virtual clone method in each ParticleModule doesn't work
// If you have a better alternative, feel free to fix this thing
#define _IF_MODULE_SET_SIZE(x) if (in->IsA(x::StaticClass())) size = sizeof(x)
#define _ELSEIF_MODULE_SET_SIZE(x) else if (in->IsA(x::StaticClass())) size = sizeof(x)
void ParticleModuleHelper::copyModule(UParticleModule *&out, UParticleModule *&in)
{
	size_t size = 0;

	_IF_MODULE_SET_SIZE(UParticleModuleVelocityOverLifetime);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleVelocityInheritParent);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleVelocity_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleVelocity);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleUberRainSplashB);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleUberRainSplashA);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleUberRainImpacts);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleUberRainDrops);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleUberLTISIVCLILIRSSBLIRR);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleUberLTISIVCLIL);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleUberLTISIVCL);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataTrail2);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataTrail);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataRibbon);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataPhysX);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataMeshPhysX);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataMesh);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataBeam2);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataBeam);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataApex);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTypeDataAnimTrail);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTrailTaper);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTrailSpawn);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleTrailSource);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSubUVSelect);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSubUVMovie);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSubUVDirect);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSubUV);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleStoreSpawnTime);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSpawnPerUnit);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSpawn);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSourceMovement);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSizeScaleByTime);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSizeScale);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSizeMultiplyVelocity);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSizeMultiplyLife);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSize_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleSize);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleRotationRateMultiplyLife);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleRotationRate_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleRotationRate);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleRotationOverLifetime);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleRotation_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleRotation);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleRequired);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleParameterDynamic_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleParameterDynamic);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleOrientationAxisLock);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleOrbit);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleMeshRotationRateOverLife);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleMeshRotationRateMultiplyLife);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleMeshRotationRate_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleMeshRotationRate);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleMeshRotation_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleMeshRotation);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleMeshMaterial);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleMaterialByParameter);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocationPrimitiveSphere_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocationPrimitiveSphere);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocationPrimitiveCylinder_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocationPrimitiveCylinder);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocationEmitterDirect);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocationEmitter);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocationDirect);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocationBoneSocket);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocation_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLocation);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLifetime_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleLifetime);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleKillHeight);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleKillBox);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleEventSendToGame);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleEventReceiverSpawn);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleEventReceiverKillParticles);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleEventGenerator);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleColorScaleOverLife);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleColorScaleOverDensity);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleColorOverLife);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleColorByParameter);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleColor_Seeded);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleColor);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleCollision);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleCameraOffset);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleBeamTarget);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleBeamSource);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleBeamNoise);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleBeamModifier);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleAttractorPoint);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleAttractorParticle);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleAttractorLine);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleAccelerationOverLifetime);
	_ELSEIF_MODULE_SET_SIZE(UParticleModuleAcceleration);

	if (size)
	{
		out = (UParticleModule *)malloc(size);
		memcpy(out, in, size);
	}
	else
		out = in;
	copyModuleTArrays(out, in);
}