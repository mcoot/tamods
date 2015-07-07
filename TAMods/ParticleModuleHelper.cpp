#include "ParticleModuleHelper.h"

static void copyTArray(TArray<float> &out, TArray<float> &in)
{
	out.Data = (float *)malloc(in.Count * sizeof(float));
	memcpy(out.Data, in.Data, in.Count * sizeof(float));
}

void ParticleModuleHelper::freeModuleTArrays(UParticleModule *mod)
{
	if (mod->IsA(UParticleModuleAcceleration::StaticClass()))
	{
		free(((UParticleModuleAcceleration *)mod)->Acceleration.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleAccelerationOverLifetime::StaticClass()))
	{
		free(((UParticleModuleAccelerationOverLifetime *)mod)->AccelOverLife.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleAttractorLine::StaticClass()))
	{
		free(((UParticleModuleAttractorLine *)mod)->Range.LookupTable.Data);
		free(((UParticleModuleAttractorLine *)mod)->Strength.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleAttractorParticle::StaticClass()))
	{
		free(((UParticleModuleAttractorParticle *)mod)->Range.LookupTable.Data);
		free(((UParticleModuleAttractorParticle *)mod)->Strength.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleAttractorPoint::StaticClass()))
	{
		free(((UParticleModuleAttractorPoint *)mod)->Position.LookupTable.Data);
		free(((UParticleModuleAttractorPoint *)mod)->Range.LookupTable.Data);
		free(((UParticleModuleAttractorPoint *)mod)->Strength.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleBeamModifier::StaticClass()))
	{
		free(((UParticleModuleBeamModifier *)mod)->Position.LookupTable.Data);
		free(((UParticleModuleBeamModifier *)mod)->Tangent.LookupTable.Data);
		free(((UParticleModuleBeamModifier *)mod)->Strength.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleBeamNoise::StaticClass()))
	{
		free(((UParticleModuleBeamNoise *)mod)->NoiseRange.LookupTable.Data);
		free(((UParticleModuleBeamNoise *)mod)->NoiseRangeScale.LookupTable.Data);
		free(((UParticleModuleBeamNoise *)mod)->NoiseSpeed.LookupTable.Data);
		free(((UParticleModuleBeamNoise *)mod)->NoiseTangentStrength.LookupTable.Data);
		free(((UParticleModuleBeamNoise *)mod)->NoiseScale.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleBeamSource::StaticClass()))
	{
		free(((UParticleModuleBeamSource *)mod)->Source.LookupTable.Data);
		free(((UParticleModuleBeamSource *)mod)->SourceTangent.LookupTable.Data);
		free(((UParticleModuleBeamSource *)mod)->SourceStrength.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleBeamTarget::StaticClass()))
	{
		free(((UParticleModuleBeamTarget *)mod)->Target.LookupTable.Data);
		free(((UParticleModuleBeamTarget *)mod)->TargetTangent.LookupTable.Data);
		free(((UParticleModuleBeamTarget *)mod)->TargetStrength.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleCameraOffset::StaticClass()))
	{
		free(((UParticleModuleCameraOffset *)mod)->CameraOffset.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleCollision::StaticClass()))
	{
		free(((UParticleModuleCollision *)mod)->DampingFactor.LookupTable.Data);
		free(((UParticleModuleCollision *)mod)->DampingFactorRotation.LookupTable.Data);
		free(((UParticleModuleCollision *)mod)->MaxCollisions.LookupTable.Data);
		free(((UParticleModuleCollision *)mod)->ParticleMass.LookupTable.Data);
		free(((UParticleModuleCollision *)mod)->DelayAmount.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleColor::StaticClass()))
	{
		free(((UParticleModuleColor *)mod)->StartColor.LookupTable.Data);
		free(((UParticleModuleColor *)mod)->StartAlpha.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleColorOverLife::StaticClass()))
	{
		free(((UParticleModuleColorOverLife *)mod)->ColorOverLife.LookupTable.Data);
		free(((UParticleModuleColorOverLife *)mod)->AlphaOverLife.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleColorScaleOverDensity::StaticClass()))
	{
		free(((UParticleModuleColorScaleOverDensity *)mod)->ColorScaleOverDensity.LookupTable.Data);
		free(((UParticleModuleColorScaleOverDensity *)mod)->AlphaScaleOverDensity.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleColorScaleOverLife::StaticClass()))
	{
		free(((UParticleModuleColorScaleOverLife *)mod)->ColorScaleOverLife.LookupTable.Data);
		free(((UParticleModuleColorScaleOverLife *)mod)->AlphaScaleOverLife.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleEventReceiverSpawn::StaticClass()))
	{
		free(((UParticleModuleEventReceiverSpawn *)mod)->SpawnCount.LookupTable.Data);
		free(((UParticleModuleEventReceiverSpawn *)mod)->InheritVelocityScale.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleKillBox::StaticClass()))
	{
		free(((UParticleModuleKillBox *)mod)->LowerLeftCorner.LookupTable.Data);
		free(((UParticleModuleKillBox *)mod)->UpperRightCorner.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleKillHeight::StaticClass()))
	{
		free(((UParticleModuleKillHeight *)mod)->Height.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleLifetime::StaticClass()))
	{
		free(((UParticleModuleLifetime *)mod)->Lifetime.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleLocation::StaticClass()))
	{
		free(((UParticleModuleLocation *)mod)->StartLocation.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleLocationDirect::StaticClass()))
	{
		free(((UParticleModuleLocationDirect *)mod)->Location.LookupTable.Data);
		free(((UParticleModuleLocationDirect *)mod)->LocationOffset.LookupTable.Data);
		free(((UParticleModuleLocationDirect *)mod)->ScaleFactor.LookupTable.Data);
		free(((UParticleModuleLocationDirect *)mod)->Direction.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleLocationPrimitiveCylinder::StaticClass()))
	{
		free(((UParticleModuleLocationPrimitiveCylinder *)mod)->StartRadius.LookupTable.Data);
		free(((UParticleModuleLocationPrimitiveCylinder *)mod)->StartHeight.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleLocationPrimitiveSphere::StaticClass()))
	{
		free(((UParticleModuleLocationPrimitiveSphere *)mod)->StartRadius.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSourceMovement::StaticClass()))
	{
		free(((UParticleModuleSourceMovement *)mod)->SourceMovementScale.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleOrbit::StaticClass()))
	{
		free(((UParticleModuleOrbit *)mod)->OffsetAmount.LookupTable.Data);
		free(((UParticleModuleOrbit *)mod)->RotationAmount.LookupTable.Data);
		free(((UParticleModuleOrbit *)mod)->RotationRateAmount.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleRequired::StaticClass()))
	{
		free(((UParticleModuleRequired *)mod)->SpawnRate.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleMeshRotation::StaticClass()))
	{
		free(((UParticleModuleMeshRotation *)mod)->StartRotation.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleRotation::StaticClass()))
	{
		free(((UParticleModuleRotation *)mod)->StartRotation.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleRotationOverLifetime::StaticClass()))
	{
		free(((UParticleModuleRotationOverLifetime *)mod)->RotationOverLife.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleMeshRotationRate::StaticClass()))
	{
		free(((UParticleModuleMeshRotationRate *)mod)->StartRotationRate.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleMeshRotationRateMultiplyLife::StaticClass()))
	{
		free(((UParticleModuleMeshRotationRateMultiplyLife *)mod)->LifeMultiplier.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleMeshRotationRateOverLife::StaticClass()))
	{
		free(((UParticleModuleMeshRotationRateOverLife *)mod)->RotRate.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleRotationRate::StaticClass()))
	{
		free(((UParticleModuleRotationRate *)mod)->StartRotationRate.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleRotationRateMultiplyLife::StaticClass()))
	{
		free(((UParticleModuleRotationRateMultiplyLife *)mod)->LifeMultiplier.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSize::StaticClass()))
	{
		free(((UParticleModuleSize *)mod)->StartSize.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSizeMultiplyLife::StaticClass()))
	{
		free(((UParticleModuleSizeMultiplyLife *)mod)->LifeMultiplier.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSizeMultiplyVelocity::StaticClass()))
	{
		free(((UParticleModuleSizeMultiplyVelocity *)mod)->VelocityMultiplier.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSizeScale::StaticClass()))
	{
		free(((UParticleModuleSizeScale *)mod)->SizeScale.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSizeScaleByTime::StaticClass()))
	{
		free(((UParticleModuleSizeScaleByTime *)mod)->SizeScaleByTime.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSpawn::StaticClass()))
	{
		free(((UParticleModuleSpawn *)mod)->Rate.LookupTable.Data);
		free(((UParticleModuleSpawn *)mod)->RateScale.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSpawnPerUnit::StaticClass()))
	{
		free(((UParticleModuleSpawnPerUnit *)mod)->SpawnPerUnit.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSubUV::StaticClass()))
	{
		free(((UParticleModuleSubUV *)mod)->SubImageIndex.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSubUVMovie::StaticClass()))
	{
		free(((UParticleModuleSubUVMovie *)mod)->FrameRate.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSubUVDirect::StaticClass()))
	{
		free(((UParticleModuleSubUVDirect *)mod)->SubUVPosition.LookupTable.Data);
		free(((UParticleModuleSubUVDirect *)mod)->SubUVSize.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleSubUVSelect::StaticClass()))
	{
		free(((UParticleModuleSubUVSelect *)mod)->SubImageSelect.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleTrailSource::StaticClass()))
	{
		free(((UParticleModuleTrailSource *)mod)->SourceStrength.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleTrailTaper::StaticClass()))
	{
		free(((UParticleModuleTrailTaper *)mod)->TaperFactor.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleTypeDataBeam::StaticClass()))
	{
		free(((UParticleModuleTypeDataBeam *)mod)->Distance.LookupTable.Data);
		free(((UParticleModuleTypeDataBeam *)mod)->EndPoint.LookupTable.Data);
		free(((UParticleModuleTypeDataBeam *)mod)->EmitterStrength.LookupTable.Data);
		free(((UParticleModuleTypeDataBeam *)mod)->TargetStrength.LookupTable.Data);
		free(((UParticleModuleTypeDataBeam *)mod)->EndPointDirection.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleTypeDataBeam2::StaticClass()))
	{
		free(((UParticleModuleTypeDataBeam2 *)mod)->Distance.LookupTable.Data);
		free(((UParticleModuleTypeDataBeam2 *)mod)->TaperFactor.LookupTable.Data);
		free(((UParticleModuleTypeDataBeam2 *)mod)->TaperScale.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleTypeDataTrail::StaticClass()))
	{
		free(((UParticleModuleTypeDataTrail *)mod)->Tension.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleUberLTISIVCL::StaticClass()))
	{
		free(((UParticleModuleUberLTISIVCL *)mod)->Lifetime.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCL *)mod)->StartSize.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCL *)mod)->StartVelocity.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCL *)mod)->StartVelocityRadial.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCL *)mod)->ColorOverLife.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCL *)mod)->AlphaOverLife.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleUberLTISIVCLIL::StaticClass()))
	{
		free(((UParticleModuleUberLTISIVCLIL *)mod)->Lifetime.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLIL *)mod)->StartSize.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLIL *)mod)->StartVelocity.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLIL *)mod)->StartVelocityRadial.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLIL *)mod)->ColorOverLife.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLIL *)mod)->AlphaOverLife.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLIL *)mod)->StartLocation.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleUberLTISIVCLILIRSSBLIRR::StaticClass()))
	{
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->Lifetime.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->StartSize.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->StartVelocity.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->StartVelocityRadial.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->ColorOverLife.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->AlphaOverLife.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->StartLocation.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->StartRotation.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->SizeLifeMultiplier.LookupTable.Data);
		free(((UParticleModuleUberLTISIVCLILIRSSBLIRR *)mod)->StartRotationRate.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleUberRainImpacts::StaticClass()))
	{
		free(((UParticleModuleUberRainImpacts *)mod)->Lifetime.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->StartSize.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->StartRotation.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->LifeMultiplier.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->PC_VelocityScale.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->PC_StartLocation.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->PC_StartRadius.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->PC_StartHeight.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->ColorOverLife.LookupTable.Data);
		free(((UParticleModuleUberRainImpacts *)mod)->AlphaOverLife.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleUberRainSplashA::StaticClass()))
	{
		free(((UParticleModuleUberRainSplashA *)mod)->Lifetime.LookupTable.Data);
		free(((UParticleModuleUberRainSplashA *)mod)->StartSize.LookupTable.Data);
		free(((UParticleModuleUberRainSplashA *)mod)->StartRotation.LookupTable.Data);
		free(((UParticleModuleUberRainSplashA *)mod)->LifeMultiplier.LookupTable.Data);
		free(((UParticleModuleUberRainSplashA *)mod)->ColorOverLife.LookupTable.Data);
		free(((UParticleModuleUberRainSplashA *)mod)->AlphaOverLife.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleUberRainSplashB::StaticClass()))
	{
		free(((UParticleModuleUberRainSplashB *)mod)->Lifetime.LookupTable.Data);
		free(((UParticleModuleUberRainSplashB *)mod)->StartSize.LookupTable.Data);
		free(((UParticleModuleUberRainSplashB *)mod)->ColorOverLife.LookupTable.Data);
		free(((UParticleModuleUberRainSplashB *)mod)->AlphaOverLife.LookupTable.Data);
		free(((UParticleModuleUberRainSplashB *)mod)->LifeMultiplier.LookupTable.Data);
		free(((UParticleModuleUberRainSplashB *)mod)->StartRotationRate.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleVelocity::StaticClass()))
	{
		free(((UParticleModuleVelocity *)mod)->StartVelocity.LookupTable.Data);
		free(((UParticleModuleVelocity *)mod)->StartVelocityRadial.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleVelocityInheritParent::StaticClass()))
	{
		free(((UParticleModuleVelocityInheritParent *)mod)->Scale.LookupTable.Data);
	}
	if (mod->IsA(UParticleModuleVelocityOverLifetime::StaticClass()))
	{
		free(((UParticleModuleVelocityOverLifetime *)mod)->VelOverLife.LookupTable.Data);
	}
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
		copyModuleTArrays(out, in);
	}
	else
		out = in;
}

int ParticleModuleHelper::ParticleModule_getbSpawnModule(const UParticleModule *mod) { return mod->bSpawnModule; }
void ParticleModuleHelper::ParticleModule_setbSpawnModule(UParticleModule *mod, int val) { mod->bSpawnModule = val; }
int ParticleModuleHelper::ParticleModule_getbUpdateModule(const UParticleModule *mod) { return mod->bUpdateModule; }
void ParticleModuleHelper::ParticleModule_setbUpdateModule(UParticleModule *mod, int val) { mod->bUpdateModule = val; }
int ParticleModuleHelper::ParticleModule_getbFinalUpdateModule(const UParticleModule *mod) { return mod->bFinalUpdateModule; }
void ParticleModuleHelper::ParticleModule_setbFinalUpdateModule(UParticleModule *mod, int val) { mod->bFinalUpdateModule = val; }
int ParticleModuleHelper::ParticleModule_getbCurvesAsColor(const UParticleModule *mod) { return mod->bCurvesAsColor; }
void ParticleModuleHelper::ParticleModule_setbCurvesAsColor(UParticleModule *mod, int val) { mod->bCurvesAsColor = val; }
int ParticleModuleHelper::ParticleModule_getb3DDrawMode(const UParticleModule *mod) { return mod->b3DDrawMode; }
void ParticleModuleHelper::ParticleModule_setb3DDrawMode(UParticleModule *mod, int val) { mod->b3DDrawMode = val; }
int ParticleModuleHelper::ParticleModule_getbSupported3DDrawMode(const UParticleModule *mod) { return mod->bSupported3DDrawMode; }
void ParticleModuleHelper::ParticleModule_setbSupported3DDrawMode(UParticleModule *mod, int val) { mod->bSupported3DDrawMode = val; }
int ParticleModuleHelper::ParticleModule_getbEnabled(const UParticleModule *mod) { return mod->bEnabled; }
void ParticleModuleHelper::ParticleModule_setbEnabled(UParticleModule *mod, int val) { mod->bEnabled = val; }
int ParticleModuleHelper::ParticleModule_getbEditable(const UParticleModule *mod) { return mod->bEditable; }
void ParticleModuleHelper::ParticleModule_setbEditable(UParticleModule *mod, int val) { mod->bEditable = val; }
int ParticleModuleHelper::ParticleModule_getLODDuplicate(const UParticleModule *mod) { return mod->LODDuplicate; }
void ParticleModuleHelper::ParticleModule_setLODDuplicate(UParticleModule *mod, int val) { mod->LODDuplicate = val; }
int ParticleModuleHelper::ParticleModule_getbSupportsRandomSeed(const UParticleModule *mod) { return mod->bSupportsRandomSeed; }
void ParticleModuleHelper::ParticleModule_setbSupportsRandomSeed(UParticleModule *mod, int val) { mod->bSupportsRandomSeed = val; }
int ParticleModuleHelper::ParticleModule_getbRequiresLoopingNotification(const UParticleModule *mod) { return mod->bRequiresLoopingNotification; }
void ParticleModuleHelper::ParticleModule_setbRequiresLoopingNotification(UParticleModule *mod, int val) { mod->bRequiresLoopingNotification = val; }
struct FColor *ParticleModuleHelper::ParticleModule_getModuleEditorColor(const UParticleModule *mod) { return const_cast<struct FColor *>(&mod->ModuleEditorColor); }
void ParticleModuleHelper::ParticleModule_setModuleEditorColor(UParticleModule *mod, struct FColor val) { mod->ModuleEditorColor = val; }
int ParticleModuleHelper::ParticleModuleAccelerationBase_getbAlwaysInWorldSpace(const UParticleModuleAccelerationBase *mod) { return mod->bAlwaysInWorldSpace; }
void ParticleModuleHelper::ParticleModuleAccelerationBase_setbAlwaysInWorldSpace(UParticleModuleAccelerationBase *mod, int val) { mod->bAlwaysInWorldSpace = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleAcceleration_getAcceleration(const UParticleModuleAcceleration *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Acceleration); }
void ParticleModuleHelper::ParticleModuleAcceleration_setAcceleration(UParticleModuleAcceleration *mod, struct FRawDistributionVector val) { mod->Acceleration = val; }
int ParticleModuleHelper::ParticleModuleAcceleration_getbApplyOwnerScale(const UParticleModuleAcceleration *mod) { return mod->bApplyOwnerScale; }
void ParticleModuleHelper::ParticleModuleAcceleration_setbApplyOwnerScale(UParticleModuleAcceleration *mod, int val) { mod->bApplyOwnerScale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleAccelerationOverLifetime_getAccelOverLife(const UParticleModuleAccelerationOverLifetime *mod) { return const_cast<struct FRawDistributionVector *>(&mod->AccelOverLife); }
void ParticleModuleHelper::ParticleModuleAccelerationOverLifetime_setAccelOverLife(UParticleModuleAccelerationOverLifetime *mod, struct FRawDistributionVector val) { mod->AccelOverLife = val; }
struct FVector *ParticleModuleHelper::ParticleModuleAttractorLine_getEndPoint0(const UParticleModuleAttractorLine *mod) { return const_cast<struct FVector *>(&mod->EndPoint0); }
void ParticleModuleHelper::ParticleModuleAttractorLine_setEndPoint0(UParticleModuleAttractorLine *mod, struct FVector val) { mod->EndPoint0 = val; }
struct FVector *ParticleModuleHelper::ParticleModuleAttractorLine_getEndPoint1(const UParticleModuleAttractorLine *mod) { return const_cast<struct FVector *>(&mod->EndPoint1); }
void ParticleModuleHelper::ParticleModuleAttractorLine_setEndPoint1(UParticleModuleAttractorLine *mod, struct FVector val) { mod->EndPoint1 = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleAttractorLine_getRange(const UParticleModuleAttractorLine *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Range); }
void ParticleModuleHelper::ParticleModuleAttractorLine_setRange(UParticleModuleAttractorLine *mod, struct FRawDistributionFloat val) { mod->Range = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleAttractorLine_getStrength(const UParticleModuleAttractorLine *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Strength); }
void ParticleModuleHelper::ParticleModuleAttractorLine_setStrength(UParticleModuleAttractorLine *mod, struct FRawDistributionFloat val) { mod->Strength = val; }
struct FName *ParticleModuleHelper::ParticleModuleAttractorParticle_getEmitterName(const UParticleModuleAttractorParticle *mod) { return const_cast<struct FName *>(&mod->EmitterName); }
void ParticleModuleHelper::ParticleModuleAttractorParticle_setEmitterName(UParticleModuleAttractorParticle *mod, struct FName val) { mod->EmitterName = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleAttractorParticle_getRange(const UParticleModuleAttractorParticle *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Range); }
void ParticleModuleHelper::ParticleModuleAttractorParticle_setRange(UParticleModuleAttractorParticle *mod, struct FRawDistributionFloat val) { mod->Range = val; }
int ParticleModuleHelper::ParticleModuleAttractorParticle_getbStrengthByDistance(const UParticleModuleAttractorParticle *mod) { return mod->bStrengthByDistance; }
void ParticleModuleHelper::ParticleModuleAttractorParticle_setbStrengthByDistance(UParticleModuleAttractorParticle *mod, int val) { mod->bStrengthByDistance = val; }
int ParticleModuleHelper::ParticleModuleAttractorParticle_getbAffectBaseVelocity(const UParticleModuleAttractorParticle *mod) { return mod->bAffectBaseVelocity; }
void ParticleModuleHelper::ParticleModuleAttractorParticle_setbAffectBaseVelocity(UParticleModuleAttractorParticle *mod, int val) { mod->bAffectBaseVelocity = val; }
int ParticleModuleHelper::ParticleModuleAttractorParticle_getbRenewSource(const UParticleModuleAttractorParticle *mod) { return mod->bRenewSource; }
void ParticleModuleHelper::ParticleModuleAttractorParticle_setbRenewSource(UParticleModuleAttractorParticle *mod, int val) { mod->bRenewSource = val; }
int ParticleModuleHelper::ParticleModuleAttractorParticle_getbInheritSourceVel(const UParticleModuleAttractorParticle *mod) { return mod->bInheritSourceVel; }
void ParticleModuleHelper::ParticleModuleAttractorParticle_setbInheritSourceVel(UParticleModuleAttractorParticle *mod, int val) { mod->bInheritSourceVel = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleAttractorParticle_getStrength(const UParticleModuleAttractorParticle *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Strength); }
void ParticleModuleHelper::ParticleModuleAttractorParticle_setStrength(UParticleModuleAttractorParticle *mod, struct FRawDistributionFloat val) { mod->Strength = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleAttractorPoint_getPosition(const UParticleModuleAttractorPoint *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Position); }
void ParticleModuleHelper::ParticleModuleAttractorPoint_setPosition(UParticleModuleAttractorPoint *mod, struct FRawDistributionVector val) { mod->Position = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleAttractorPoint_getRange(const UParticleModuleAttractorPoint *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Range); }
void ParticleModuleHelper::ParticleModuleAttractorPoint_setRange(UParticleModuleAttractorPoint *mod, struct FRawDistributionFloat val) { mod->Range = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleAttractorPoint_getStrength(const UParticleModuleAttractorPoint *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Strength); }
void ParticleModuleHelper::ParticleModuleAttractorPoint_setStrength(UParticleModuleAttractorPoint *mod, struct FRawDistributionFloat val) { mod->Strength = val; }
int ParticleModuleHelper::ParticleModuleAttractorPoint_getStrengthByDistance(const UParticleModuleAttractorPoint *mod) { return mod->StrengthByDistance; }
void ParticleModuleHelper::ParticleModuleAttractorPoint_setStrengthByDistance(UParticleModuleAttractorPoint *mod, int val) { mod->StrengthByDistance = val; }
int ParticleModuleHelper::ParticleModuleAttractorPoint_getbAffectBaseVelocity(const UParticleModuleAttractorPoint *mod) { return mod->bAffectBaseVelocity; }
void ParticleModuleHelper::ParticleModuleAttractorPoint_setbAffectBaseVelocity(UParticleModuleAttractorPoint *mod, int val) { mod->bAffectBaseVelocity = val; }
int ParticleModuleHelper::ParticleModuleAttractorPoint_getbOverrideVelocity(const UParticleModuleAttractorPoint *mod) { return mod->bOverrideVelocity; }
void ParticleModuleHelper::ParticleModuleAttractorPoint_setbOverrideVelocity(UParticleModuleAttractorPoint *mod, int val) { mod->bOverrideVelocity = val; }
int ParticleModuleHelper::ParticleModuleAttractorPoint_getbUseWorldSpacePosition(const UParticleModuleAttractorPoint *mod) { return mod->bUseWorldSpacePosition; }
void ParticleModuleHelper::ParticleModuleAttractorPoint_setbUseWorldSpacePosition(UParticleModuleAttractorPoint *mod, int val) { mod->bUseWorldSpacePosition = val; }
struct FBeamModifierOptions *ParticleModuleHelper::ParticleModuleBeamModifier_getPositionOptions(const UParticleModuleBeamModifier *mod) { return const_cast<struct FBeamModifierOptions *>(&mod->PositionOptions); }
void ParticleModuleHelper::ParticleModuleBeamModifier_setPositionOptions(UParticleModuleBeamModifier *mod, struct FBeamModifierOptions val) { mod->PositionOptions = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleBeamModifier_getPosition(const UParticleModuleBeamModifier *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Position); }
void ParticleModuleHelper::ParticleModuleBeamModifier_setPosition(UParticleModuleBeamModifier *mod, struct FRawDistributionVector val) { mod->Position = val; }
struct FBeamModifierOptions *ParticleModuleHelper::ParticleModuleBeamModifier_getTangentOptions(const UParticleModuleBeamModifier *mod) { return const_cast<struct FBeamModifierOptions *>(&mod->TangentOptions); }
void ParticleModuleHelper::ParticleModuleBeamModifier_setTangentOptions(UParticleModuleBeamModifier *mod, struct FBeamModifierOptions val) { mod->TangentOptions = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleBeamModifier_getTangent(const UParticleModuleBeamModifier *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Tangent); }
void ParticleModuleHelper::ParticleModuleBeamModifier_setTangent(UParticleModuleBeamModifier *mod, struct FRawDistributionVector val) { mod->Tangent = val; }
int ParticleModuleHelper::ParticleModuleBeamModifier_getbAbsoluteTangent(const UParticleModuleBeamModifier *mod) { return mod->bAbsoluteTangent; }
void ParticleModuleHelper::ParticleModuleBeamModifier_setbAbsoluteTangent(UParticleModuleBeamModifier *mod, int val) { mod->bAbsoluteTangent = val; }
struct FBeamModifierOptions *ParticleModuleHelper::ParticleModuleBeamModifier_getStrengthOptions(const UParticleModuleBeamModifier *mod) { return const_cast<struct FBeamModifierOptions *>(&mod->StrengthOptions); }
void ParticleModuleHelper::ParticleModuleBeamModifier_setStrengthOptions(UParticleModuleBeamModifier *mod, struct FBeamModifierOptions val) { mod->StrengthOptions = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleBeamModifier_getStrength(const UParticleModuleBeamModifier *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Strength); }
void ParticleModuleHelper::ParticleModuleBeamModifier_setStrength(UParticleModuleBeamModifier *mod, struct FRawDistributionFloat val) { mod->Strength = val; }
int ParticleModuleHelper::ParticleModuleBeamNoise_getbLowFreq_Enabled(const UParticleModuleBeamNoise *mod) { return mod->bLowFreq_Enabled; }
void ParticleModuleHelper::ParticleModuleBeamNoise_setbLowFreq_Enabled(UParticleModuleBeamNoise *mod, int val) { mod->bLowFreq_Enabled = val; }
int ParticleModuleHelper::ParticleModuleBeamNoise_getbNRScaleEmitterTime(const UParticleModuleBeamNoise *mod) { return mod->bNRScaleEmitterTime; }
void ParticleModuleHelper::ParticleModuleBeamNoise_setbNRScaleEmitterTime(UParticleModuleBeamNoise *mod, int val) { mod->bNRScaleEmitterTime = val; }
int ParticleModuleHelper::ParticleModuleBeamNoise_getbSmooth(const UParticleModuleBeamNoise *mod) { return mod->bSmooth; }
void ParticleModuleHelper::ParticleModuleBeamNoise_setbSmooth(UParticleModuleBeamNoise *mod, int val) { mod->bSmooth = val; }
int ParticleModuleHelper::ParticleModuleBeamNoise_getbNoiseLock(const UParticleModuleBeamNoise *mod) { return mod->bNoiseLock; }
void ParticleModuleHelper::ParticleModuleBeamNoise_setbNoiseLock(UParticleModuleBeamNoise *mod, int val) { mod->bNoiseLock = val; }
int ParticleModuleHelper::ParticleModuleBeamNoise_getbOscillate(const UParticleModuleBeamNoise *mod) { return mod->bOscillate; }
void ParticleModuleHelper::ParticleModuleBeamNoise_setbOscillate(UParticleModuleBeamNoise *mod, int val) { mod->bOscillate = val; }
int ParticleModuleHelper::ParticleModuleBeamNoise_getbUseNoiseTangents(const UParticleModuleBeamNoise *mod) { return mod->bUseNoiseTangents; }
void ParticleModuleHelper::ParticleModuleBeamNoise_setbUseNoiseTangents(UParticleModuleBeamNoise *mod, int val) { mod->bUseNoiseTangents = val; }
int ParticleModuleHelper::ParticleModuleBeamNoise_getbTargetNoise(const UParticleModuleBeamNoise *mod) { return mod->bTargetNoise; }
void ParticleModuleHelper::ParticleModuleBeamNoise_setbTargetNoise(UParticleModuleBeamNoise *mod, int val) { mod->bTargetNoise = val; }
int ParticleModuleHelper::ParticleModuleBeamNoise_getbApplyNoiseScale(const UParticleModuleBeamNoise *mod) { return mod->bApplyNoiseScale; }
void ParticleModuleHelper::ParticleModuleBeamNoise_setbApplyNoiseScale(UParticleModuleBeamNoise *mod, int val) { mod->bApplyNoiseScale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseRange(const UParticleModuleBeamNoise *mod) { return const_cast<struct FRawDistributionVector *>(&mod->NoiseRange); }
void ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseRange(UParticleModuleBeamNoise *mod, struct FRawDistributionVector val) { mod->NoiseRange = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseRangeScale(const UParticleModuleBeamNoise *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->NoiseRangeScale); }
void ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseRangeScale(UParticleModuleBeamNoise *mod, struct FRawDistributionFloat val) { mod->NoiseRangeScale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseSpeed(const UParticleModuleBeamNoise *mod) { return const_cast<struct FRawDistributionVector *>(&mod->NoiseSpeed); }
void ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseSpeed(UParticleModuleBeamNoise *mod, struct FRawDistributionVector val) { mod->NoiseSpeed = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseTangentStrength(const UParticleModuleBeamNoise *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->NoiseTangentStrength); }
void ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseTangentStrength(UParticleModuleBeamNoise *mod, struct FRawDistributionFloat val) { mod->NoiseTangentStrength = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseScale(const UParticleModuleBeamNoise *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->NoiseScale); }
void ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseScale(UParticleModuleBeamNoise *mod, struct FRawDistributionFloat val) { mod->NoiseScale = val; }
struct FName *ParticleModuleHelper::ParticleModuleBeamSource_getSourceName(const UParticleModuleBeamSource *mod) { return const_cast<struct FName *>(&mod->SourceName); }
void ParticleModuleHelper::ParticleModuleBeamSource_setSourceName(UParticleModuleBeamSource *mod, struct FName val) { mod->SourceName = val; }
int ParticleModuleHelper::ParticleModuleBeamSource_getbSourceAbsolute(const UParticleModuleBeamSource *mod) { return mod->bSourceAbsolute; }
void ParticleModuleHelper::ParticleModuleBeamSource_setbSourceAbsolute(UParticleModuleBeamSource *mod, int val) { mod->bSourceAbsolute = val; }
int ParticleModuleHelper::ParticleModuleBeamSource_getbLockSource(const UParticleModuleBeamSource *mod) { return mod->bLockSource; }
void ParticleModuleHelper::ParticleModuleBeamSource_setbLockSource(UParticleModuleBeamSource *mod, int val) { mod->bLockSource = val; }
int ParticleModuleHelper::ParticleModuleBeamSource_getbLockSourceTangent(const UParticleModuleBeamSource *mod) { return mod->bLockSourceTangent; }
void ParticleModuleHelper::ParticleModuleBeamSource_setbLockSourceTangent(UParticleModuleBeamSource *mod, int val) { mod->bLockSourceTangent = val; }
int ParticleModuleHelper::ParticleModuleBeamSource_getbLockSourceStength(const UParticleModuleBeamSource *mod) { return mod->bLockSourceStength; }
void ParticleModuleHelper::ParticleModuleBeamSource_setbLockSourceStength(UParticleModuleBeamSource *mod, int val) { mod->bLockSourceStength = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleBeamSource_getSource(const UParticleModuleBeamSource *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Source); }
void ParticleModuleHelper::ParticleModuleBeamSource_setSource(UParticleModuleBeamSource *mod, struct FRawDistributionVector val) { mod->Source = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleBeamSource_getSourceTangent(const UParticleModuleBeamSource *mod) { return const_cast<struct FRawDistributionVector *>(&mod->SourceTangent); }
void ParticleModuleHelper::ParticleModuleBeamSource_setSourceTangent(UParticleModuleBeamSource *mod, struct FRawDistributionVector val) { mod->SourceTangent = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleBeamSource_getSourceStrength(const UParticleModuleBeamSource *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->SourceStrength); }
void ParticleModuleHelper::ParticleModuleBeamSource_setSourceStrength(UParticleModuleBeamSource *mod, struct FRawDistributionFloat val) { mod->SourceStrength = val; }
struct FName *ParticleModuleHelper::ParticleModuleBeamTarget_getTargetName(const UParticleModuleBeamTarget *mod) { return const_cast<struct FName *>(&mod->TargetName); }
void ParticleModuleHelper::ParticleModuleBeamTarget_setTargetName(UParticleModuleBeamTarget *mod, struct FName val) { mod->TargetName = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleBeamTarget_getTarget(const UParticleModuleBeamTarget *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Target); }
void ParticleModuleHelper::ParticleModuleBeamTarget_setTarget(UParticleModuleBeamTarget *mod, struct FRawDistributionVector val) { mod->Target = val; }
int ParticleModuleHelper::ParticleModuleBeamTarget_getbTargetAbsolute(const UParticleModuleBeamTarget *mod) { return mod->bTargetAbsolute; }
void ParticleModuleHelper::ParticleModuleBeamTarget_setbTargetAbsolute(UParticleModuleBeamTarget *mod, int val) { mod->bTargetAbsolute = val; }
int ParticleModuleHelper::ParticleModuleBeamTarget_getbLockTarget(const UParticleModuleBeamTarget *mod) { return mod->bLockTarget; }
void ParticleModuleHelper::ParticleModuleBeamTarget_setbLockTarget(UParticleModuleBeamTarget *mod, int val) { mod->bLockTarget = val; }
int ParticleModuleHelper::ParticleModuleBeamTarget_getbLockTargetTangent(const UParticleModuleBeamTarget *mod) { return mod->bLockTargetTangent; }
void ParticleModuleHelper::ParticleModuleBeamTarget_setbLockTargetTangent(UParticleModuleBeamTarget *mod, int val) { mod->bLockTargetTangent = val; }
int ParticleModuleHelper::ParticleModuleBeamTarget_getbLockTargetStength(const UParticleModuleBeamTarget *mod) { return mod->bLockTargetStength; }
void ParticleModuleHelper::ParticleModuleBeamTarget_setbLockTargetStength(UParticleModuleBeamTarget *mod, int val) { mod->bLockTargetStength = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleBeamTarget_getTargetTangent(const UParticleModuleBeamTarget *mod) { return const_cast<struct FRawDistributionVector *>(&mod->TargetTangent); }
void ParticleModuleHelper::ParticleModuleBeamTarget_setTargetTangent(UParticleModuleBeamTarget *mod, struct FRawDistributionVector val) { mod->TargetTangent = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleBeamTarget_getTargetStrength(const UParticleModuleBeamTarget *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->TargetStrength); }
void ParticleModuleHelper::ParticleModuleBeamTarget_setTargetStrength(UParticleModuleBeamTarget *mod, struct FRawDistributionFloat val) { mod->TargetStrength = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleCameraOffset_getCameraOffset(const UParticleModuleCameraOffset *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->CameraOffset); }
void ParticleModuleHelper::ParticleModuleCameraOffset_setCameraOffset(UParticleModuleCameraOffset *mod, struct FRawDistributionFloat val) { mod->CameraOffset = val; }
int ParticleModuleHelper::ParticleModuleCameraOffset_getbSpawnTimeOnly(const UParticleModuleCameraOffset *mod) { return mod->bSpawnTimeOnly; }
void ParticleModuleHelper::ParticleModuleCameraOffset_setbSpawnTimeOnly(UParticleModuleCameraOffset *mod, int val) { mod->bSpawnTimeOnly = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleCollision_getDampingFactor(const UParticleModuleCollision *mod) { return const_cast<struct FRawDistributionVector *>(&mod->DampingFactor); }
void ParticleModuleHelper::ParticleModuleCollision_setDampingFactor(UParticleModuleCollision *mod, struct FRawDistributionVector val) { mod->DampingFactor = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleCollision_getDampingFactorRotation(const UParticleModuleCollision *mod) { return const_cast<struct FRawDistributionVector *>(&mod->DampingFactorRotation); }
void ParticleModuleHelper::ParticleModuleCollision_setDampingFactorRotation(UParticleModuleCollision *mod, struct FRawDistributionVector val) { mod->DampingFactorRotation = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleCollision_getMaxCollisions(const UParticleModuleCollision *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->MaxCollisions); }
void ParticleModuleHelper::ParticleModuleCollision_setMaxCollisions(UParticleModuleCollision *mod, struct FRawDistributionFloat val) { mod->MaxCollisions = val; }
int ParticleModuleHelper::ParticleModuleCollision_getbApplyPhysics(const UParticleModuleCollision *mod) { return mod->bApplyPhysics; }
void ParticleModuleHelper::ParticleModuleCollision_setbApplyPhysics(UParticleModuleCollision *mod, int val) { mod->bApplyPhysics = val; }
int ParticleModuleHelper::ParticleModuleCollision_getbPawnsDoNotDecrementCount(const UParticleModuleCollision *mod) { return mod->bPawnsDoNotDecrementCount; }
void ParticleModuleHelper::ParticleModuleCollision_setbPawnsDoNotDecrementCount(UParticleModuleCollision *mod, int val) { mod->bPawnsDoNotDecrementCount = val; }
int ParticleModuleHelper::ParticleModuleCollision_getbOnlyVerticalNormalsDecrementCount(const UParticleModuleCollision *mod) { return mod->bOnlyVerticalNormalsDecrementCount; }
void ParticleModuleHelper::ParticleModuleCollision_setbOnlyVerticalNormalsDecrementCount(UParticleModuleCollision *mod, int val) { mod->bOnlyVerticalNormalsDecrementCount = val; }
int ParticleModuleHelper::ParticleModuleCollision_getbDropDetail(const UParticleModuleCollision *mod) { return mod->bDropDetail; }
void ParticleModuleHelper::ParticleModuleCollision_setbDropDetail(UParticleModuleCollision *mod, int val) { mod->bDropDetail = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleCollision_getParticleMass(const UParticleModuleCollision *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->ParticleMass); }
void ParticleModuleHelper::ParticleModuleCollision_setParticleMass(UParticleModuleCollision *mod, struct FRawDistributionFloat val) { mod->ParticleMass = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleCollision_getDelayAmount(const UParticleModuleCollision *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->DelayAmount); }
void ParticleModuleHelper::ParticleModuleCollision_setDelayAmount(UParticleModuleCollision *mod, struct FRawDistributionFloat val) { mod->DelayAmount = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleColor_getStartColor(const UParticleModuleColor *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartColor); }
void ParticleModuleHelper::ParticleModuleColor_setStartColor(UParticleModuleColor *mod, struct FRawDistributionVector val) { mod->StartColor = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleColor_getStartAlpha(const UParticleModuleColor *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartAlpha); }
void ParticleModuleHelper::ParticleModuleColor_setStartAlpha(UParticleModuleColor *mod, struct FRawDistributionFloat val) { mod->StartAlpha = val; }
int ParticleModuleHelper::ParticleModuleColor_getbClampAlpha(const UParticleModuleColor *mod) { return mod->bClampAlpha; }
void ParticleModuleHelper::ParticleModuleColor_setbClampAlpha(UParticleModuleColor *mod, int val) { mod->bClampAlpha = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleColor_Seeded_getRandomSeedInfo(const UParticleModuleColor_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleColor_Seeded_setRandomSeedInfo(UParticleModuleColor_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FName *ParticleModuleHelper::ParticleModuleColorByParameter_getColorParam(const UParticleModuleColorByParameter *mod) { return const_cast<struct FName *>(&mod->ColorParam); }
void ParticleModuleHelper::ParticleModuleColorByParameter_setColorParam(UParticleModuleColorByParameter *mod, struct FName val) { mod->ColorParam = val; }
struct FColor *ParticleModuleHelper::ParticleModuleColorByParameter_getDefaultColor(const UParticleModuleColorByParameter *mod) { return const_cast<struct FColor *>(&mod->DefaultColor); }
void ParticleModuleHelper::ParticleModuleColorByParameter_setDefaultColor(UParticleModuleColorByParameter *mod, struct FColor val) { mod->DefaultColor = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleColorOverLife_getColorOverLife(const UParticleModuleColorOverLife *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorOverLife); }
void ParticleModuleHelper::ParticleModuleColorOverLife_setColorOverLife(UParticleModuleColorOverLife *mod, struct FRawDistributionVector val) { mod->ColorOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleColorOverLife_getAlphaOverLife(const UParticleModuleColorOverLife *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaOverLife); }
void ParticleModuleHelper::ParticleModuleColorOverLife_setAlphaOverLife(UParticleModuleColorOverLife *mod, struct FRawDistributionFloat val) { mod->AlphaOverLife = val; }
int ParticleModuleHelper::ParticleModuleColorOverLife_getbClampAlpha(const UParticleModuleColorOverLife *mod) { return mod->bClampAlpha; }
void ParticleModuleHelper::ParticleModuleColorOverLife_setbClampAlpha(UParticleModuleColorOverLife *mod, int val) { mod->bClampAlpha = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleColorScaleOverDensity_getColorScaleOverDensity(const UParticleModuleColorScaleOverDensity *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorScaleOverDensity); }
void ParticleModuleHelper::ParticleModuleColorScaleOverDensity_setColorScaleOverDensity(UParticleModuleColorScaleOverDensity *mod, struct FRawDistributionVector val) { mod->ColorScaleOverDensity = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleColorScaleOverDensity_getAlphaScaleOverDensity(const UParticleModuleColorScaleOverDensity *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaScaleOverDensity); }
void ParticleModuleHelper::ParticleModuleColorScaleOverDensity_setAlphaScaleOverDensity(UParticleModuleColorScaleOverDensity *mod, struct FRawDistributionFloat val) { mod->AlphaScaleOverDensity = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleColorScaleOverLife_getColorScaleOverLife(const UParticleModuleColorScaleOverLife *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorScaleOverLife); }
void ParticleModuleHelper::ParticleModuleColorScaleOverLife_setColorScaleOverLife(UParticleModuleColorScaleOverLife *mod, struct FRawDistributionVector val) { mod->ColorScaleOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleColorScaleOverLife_getAlphaScaleOverLife(const UParticleModuleColorScaleOverLife *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaScaleOverLife); }
void ParticleModuleHelper::ParticleModuleColorScaleOverLife_setAlphaScaleOverLife(UParticleModuleColorScaleOverLife *mod, struct FRawDistributionFloat val) { mod->AlphaScaleOverLife = val; }
int ParticleModuleHelper::ParticleModuleColorScaleOverLife_getbEmitterTime(const UParticleModuleColorScaleOverLife *mod) { return mod->bEmitterTime; }
void ParticleModuleHelper::ParticleModuleColorScaleOverLife_setbEmitterTime(UParticleModuleColorScaleOverLife *mod, int val) { mod->bEmitterTime = val; }
TArray< struct FParticleEvent_GenerateInfo > *ParticleModuleHelper::ParticleModuleEventGenerator_getEvents(const UParticleModuleEventGenerator *mod) { return const_cast<TArray< struct FParticleEvent_GenerateInfo > *>(&mod->Events); }
void ParticleModuleHelper::ParticleModuleEventGenerator_setEvents(UParticleModuleEventGenerator *mod, TArray< struct FParticleEvent_GenerateInfo > val) { mod->Events = val; }
struct FName *ParticleModuleHelper::ParticleModuleEventReceiverBase_getEventName(const UParticleModuleEventReceiverBase *mod) { return const_cast<struct FName *>(&mod->EventName); }
void ParticleModuleHelper::ParticleModuleEventReceiverBase_setEventName(UParticleModuleEventReceiverBase *mod, struct FName val) { mod->EventName = val; }
int ParticleModuleHelper::ParticleModuleEventReceiverKillParticles_getbStopSpawning(const UParticleModuleEventReceiverKillParticles *mod) { return mod->bStopSpawning; }
void ParticleModuleHelper::ParticleModuleEventReceiverKillParticles_setbStopSpawning(UParticleModuleEventReceiverKillParticles *mod, int val) { mod->bStopSpawning = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getSpawnCount(const UParticleModuleEventReceiverSpawn *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->SpawnCount); }
void ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setSpawnCount(UParticleModuleEventReceiverSpawn *mod, struct FRawDistributionFloat val) { mod->SpawnCount = val; }
int ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getbUseParticleTime(const UParticleModuleEventReceiverSpawn *mod) { return mod->bUseParticleTime; }
void ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setbUseParticleTime(UParticleModuleEventReceiverSpawn *mod, int val) { mod->bUseParticleTime = val; }
int ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getbUsePSysLocation(const UParticleModuleEventReceiverSpawn *mod) { return mod->bUsePSysLocation; }
void ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setbUsePSysLocation(UParticleModuleEventReceiverSpawn *mod, int val) { mod->bUsePSysLocation = val; }
int ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getbInheritVelocity(const UParticleModuleEventReceiverSpawn *mod) { return mod->bInheritVelocity; }
void ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setbInheritVelocity(UParticleModuleEventReceiverSpawn *mod, int val) { mod->bInheritVelocity = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getInheritVelocityScale(const UParticleModuleEventReceiverSpawn *mod) { return const_cast<struct FRawDistributionVector *>(&mod->InheritVelocityScale); }
void ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setInheritVelocityScale(UParticleModuleEventReceiverSpawn *mod, struct FRawDistributionVector val) { mod->InheritVelocityScale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleKillBox_getLowerLeftCorner(const UParticleModuleKillBox *mod) { return const_cast<struct FRawDistributionVector *>(&mod->LowerLeftCorner); }
void ParticleModuleHelper::ParticleModuleKillBox_setLowerLeftCorner(UParticleModuleKillBox *mod, struct FRawDistributionVector val) { mod->LowerLeftCorner = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleKillBox_getUpperRightCorner(const UParticleModuleKillBox *mod) { return const_cast<struct FRawDistributionVector *>(&mod->UpperRightCorner); }
void ParticleModuleHelper::ParticleModuleKillBox_setUpperRightCorner(UParticleModuleKillBox *mod, struct FRawDistributionVector val) { mod->UpperRightCorner = val; }
int ParticleModuleHelper::ParticleModuleKillBox_getbAbsolute(const UParticleModuleKillBox *mod) { return mod->bAbsolute; }
void ParticleModuleHelper::ParticleModuleKillBox_setbAbsolute(UParticleModuleKillBox *mod, int val) { mod->bAbsolute = val; }
int ParticleModuleHelper::ParticleModuleKillBox_getbKillInside(const UParticleModuleKillBox *mod) { return mod->bKillInside; }
void ParticleModuleHelper::ParticleModuleKillBox_setbKillInside(UParticleModuleKillBox *mod, int val) { mod->bKillInside = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleKillHeight_getHeight(const UParticleModuleKillHeight *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Height); }
void ParticleModuleHelper::ParticleModuleKillHeight_setHeight(UParticleModuleKillHeight *mod, struct FRawDistributionFloat val) { mod->Height = val; }
int ParticleModuleHelper::ParticleModuleKillHeight_getbAbsolute(const UParticleModuleKillHeight *mod) { return mod->bAbsolute; }
void ParticleModuleHelper::ParticleModuleKillHeight_setbAbsolute(UParticleModuleKillHeight *mod, int val) { mod->bAbsolute = val; }
int ParticleModuleHelper::ParticleModuleKillHeight_getbFloor(const UParticleModuleKillHeight *mod) { return mod->bFloor; }
void ParticleModuleHelper::ParticleModuleKillHeight_setbFloor(UParticleModuleKillHeight *mod, int val) { mod->bFloor = val; }
int ParticleModuleHelper::ParticleModuleKillHeight_getbApplyPSysScale(const UParticleModuleKillHeight *mod) { return mod->bApplyPSysScale; }
void ParticleModuleHelper::ParticleModuleKillHeight_setbApplyPSysScale(UParticleModuleKillHeight *mod, int val) { mod->bApplyPSysScale = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleLifetime_getLifetime(const UParticleModuleLifetime *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Lifetime); }
void ParticleModuleHelper::ParticleModuleLifetime_setLifetime(UParticleModuleLifetime *mod, struct FRawDistributionFloat val) { mod->Lifetime = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleLifetime_Seeded_getRandomSeedInfo(const UParticleModuleLifetime_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleLifetime_Seeded_setRandomSeedInfo(UParticleModuleLifetime_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleLocation_getStartLocation(const UParticleModuleLocation *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartLocation); }
void ParticleModuleHelper::ParticleModuleLocation_setStartLocation(UParticleModuleLocation *mod, struct FRawDistributionVector val) { mod->StartLocation = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleLocation_Seeded_getRandomSeedInfo(const UParticleModuleLocation_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleLocation_Seeded_setRandomSeedInfo(UParticleModuleLocation_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FVector *ParticleModuleHelper::ParticleModuleLocationBoneSocket_getUniversalOffset(const UParticleModuleLocationBoneSocket *mod) { return const_cast<struct FVector *>(&mod->UniversalOffset); }
void ParticleModuleHelper::ParticleModuleLocationBoneSocket_setUniversalOffset(UParticleModuleLocationBoneSocket *mod, struct FVector val) { mod->UniversalOffset = val; }
TArray< struct FLocationBoneSocketInfo > *ParticleModuleHelper::ParticleModuleLocationBoneSocket_getSourceLocations(const UParticleModuleLocationBoneSocket *mod) { return const_cast<TArray< struct FLocationBoneSocketInfo > *>(&mod->SourceLocations); }
void ParticleModuleHelper::ParticleModuleLocationBoneSocket_setSourceLocations(UParticleModuleLocationBoneSocket *mod, TArray< struct FLocationBoneSocketInfo > val) { mod->SourceLocations = val; }
int ParticleModuleHelper::ParticleModuleLocationBoneSocket_getbUpdatePositionEachFrame(const UParticleModuleLocationBoneSocket *mod) { return mod->bUpdatePositionEachFrame; }
void ParticleModuleHelper::ParticleModuleLocationBoneSocket_setbUpdatePositionEachFrame(UParticleModuleLocationBoneSocket *mod, int val) { mod->bUpdatePositionEachFrame = val; }
int ParticleModuleHelper::ParticleModuleLocationBoneSocket_getbOrientMeshEmitters(const UParticleModuleLocationBoneSocket *mod) { return mod->bOrientMeshEmitters; }
void ParticleModuleHelper::ParticleModuleLocationBoneSocket_setbOrientMeshEmitters(UParticleModuleLocationBoneSocket *mod, int val) { mod->bOrientMeshEmitters = val; }
struct FName *ParticleModuleHelper::ParticleModuleLocationBoneSocket_getSkelMeshActorParamName(const UParticleModuleLocationBoneSocket *mod) { return const_cast<struct FName *>(&mod->SkelMeshActorParamName); }
void ParticleModuleHelper::ParticleModuleLocationBoneSocket_setSkelMeshActorParamName(UParticleModuleLocationBoneSocket *mod, struct FName val) { mod->SkelMeshActorParamName = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleLocationDirect_getLocation(const UParticleModuleLocationDirect *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Location); }
void ParticleModuleHelper::ParticleModuleLocationDirect_setLocation(UParticleModuleLocationDirect *mod, struct FRawDistributionVector val) { mod->Location = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleLocationDirect_getLocationOffset(const UParticleModuleLocationDirect *mod) { return const_cast<struct FRawDistributionVector *>(&mod->LocationOffset); }
void ParticleModuleHelper::ParticleModuleLocationDirect_setLocationOffset(UParticleModuleLocationDirect *mod, struct FRawDistributionVector val) { mod->LocationOffset = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleLocationDirect_getScaleFactor(const UParticleModuleLocationDirect *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ScaleFactor); }
void ParticleModuleHelper::ParticleModuleLocationDirect_setScaleFactor(UParticleModuleLocationDirect *mod, struct FRawDistributionVector val) { mod->ScaleFactor = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleLocationDirect_getDirection(const UParticleModuleLocationDirect *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Direction); }
void ParticleModuleHelper::ParticleModuleLocationDirect_setDirection(UParticleModuleLocationDirect *mod, struct FRawDistributionVector val) { mod->Direction = val; }
struct FName *ParticleModuleHelper::ParticleModuleLocationEmitter_getEmitterName(const UParticleModuleLocationEmitter *mod) { return const_cast<struct FName *>(&mod->EmitterName); }
void ParticleModuleHelper::ParticleModuleLocationEmitter_setEmitterName(UParticleModuleLocationEmitter *mod, struct FName val) { mod->EmitterName = val; }
int ParticleModuleHelper::ParticleModuleLocationEmitter_getInheritSourceVelocity(const UParticleModuleLocationEmitter *mod) { return mod->InheritSourceVelocity; }
void ParticleModuleHelper::ParticleModuleLocationEmitter_setInheritSourceVelocity(UParticleModuleLocationEmitter *mod, int val) { mod->InheritSourceVelocity = val; }
int ParticleModuleHelper::ParticleModuleLocationEmitter_getbInheritSourceRotation(const UParticleModuleLocationEmitter *mod) { return mod->bInheritSourceRotation; }
void ParticleModuleHelper::ParticleModuleLocationEmitter_setbInheritSourceRotation(UParticleModuleLocationEmitter *mod, int val) { mod->bInheritSourceRotation = val; }
struct FName *ParticleModuleHelper::ParticleModuleLocationEmitterDirect_getEmitterName(const UParticleModuleLocationEmitterDirect *mod) { return const_cast<struct FName *>(&mod->EmitterName); }
void ParticleModuleHelper::ParticleModuleLocationEmitterDirect_setEmitterName(UParticleModuleLocationEmitterDirect *mod, struct FName val) { mod->EmitterName = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getPositive_X(const UParticleModuleLocationPrimitiveBase *mod) { return mod->Positive_X; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setPositive_X(UParticleModuleLocationPrimitiveBase *mod, int val) { mod->Positive_X = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getPositive_Y(const UParticleModuleLocationPrimitiveBase *mod) { return mod->Positive_Y; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setPositive_Y(UParticleModuleLocationPrimitiveBase *mod, int val) { mod->Positive_Y = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getPositive_Z(const UParticleModuleLocationPrimitiveBase *mod) { return mod->Positive_Z; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setPositive_Z(UParticleModuleLocationPrimitiveBase *mod, int val) { mod->Positive_Z = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getNegative_X(const UParticleModuleLocationPrimitiveBase *mod) { return mod->Negative_X; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setNegative_X(UParticleModuleLocationPrimitiveBase *mod, int val) { mod->Negative_X = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getNegative_Y(const UParticleModuleLocationPrimitiveBase *mod) { return mod->Negative_Y; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setNegative_Y(UParticleModuleLocationPrimitiveBase *mod, int val) { mod->Negative_Y = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getNegative_Z(const UParticleModuleLocationPrimitiveBase *mod) { return mod->Negative_Z; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setNegative_Z(UParticleModuleLocationPrimitiveBase *mod, int val) { mod->Negative_Z = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getSurfaceOnly(const UParticleModuleLocationPrimitiveBase *mod) { return mod->SurfaceOnly; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setSurfaceOnly(UParticleModuleLocationPrimitiveBase *mod, int val) { mod->SurfaceOnly = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getVelocity(const UParticleModuleLocationPrimitiveBase *mod) { return mod->Velocity; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setVelocity(UParticleModuleLocationPrimitiveBase *mod, int val) { mod->Velocity = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getVelocityScale(const UParticleModuleLocationPrimitiveBase *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->VelocityScale); }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setVelocityScale(UParticleModuleLocationPrimitiveBase *mod, struct FRawDistributionFloat val) { mod->VelocityScale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getStartLocation(const UParticleModuleLocationPrimitiveBase *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartLocation); }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setStartLocation(UParticleModuleLocationPrimitiveBase *mod, struct FRawDistributionVector val) { mod->StartLocation = val; }
int ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_getRadialVelocity(const UParticleModuleLocationPrimitiveCylinder *mod) { return mod->RadialVelocity; }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_setRadialVelocity(UParticleModuleLocationPrimitiveCylinder *mod, int val) { mod->RadialVelocity = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_getStartRadius(const UParticleModuleLocationPrimitiveCylinder *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartRadius); }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_setStartRadius(UParticleModuleLocationPrimitiveCylinder *mod, struct FRawDistributionFloat val) { mod->StartRadius = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_getStartHeight(const UParticleModuleLocationPrimitiveCylinder *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartHeight); }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_setStartHeight(UParticleModuleLocationPrimitiveCylinder *mod, struct FRawDistributionFloat val) { mod->StartHeight = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_Seeded_getRandomSeedInfo(const UParticleModuleLocationPrimitiveCylinder_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_Seeded_setRandomSeedInfo(UParticleModuleLocationPrimitiveCylinder_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleLocationPrimitiveSphere_getStartRadius(const UParticleModuleLocationPrimitiveSphere *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartRadius); }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveSphere_setStartRadius(UParticleModuleLocationPrimitiveSphere *mod, struct FRawDistributionFloat val) { mod->StartRadius = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleLocationPrimitiveSphere_Seeded_getRandomSeedInfo(const UParticleModuleLocationPrimitiveSphere_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleLocationPrimitiveSphere_Seeded_setRandomSeedInfo(UParticleModuleLocationPrimitiveSphere_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSourceMovement_getSourceMovementScale(const UParticleModuleSourceMovement *mod) { return const_cast<struct FRawDistributionVector *>(&mod->SourceMovementScale); }
void ParticleModuleHelper::ParticleModuleSourceMovement_setSourceMovementScale(UParticleModuleSourceMovement *mod, struct FRawDistributionVector val) { mod->SourceMovementScale = val; }
TArray< struct FName > *ParticleModuleHelper::ParticleModuleMaterialByParameter_getMaterialParameters(const UParticleModuleMaterialByParameter *mod) { return const_cast<TArray< struct FName > *>(&mod->MaterialParameters); }
void ParticleModuleHelper::ParticleModuleMaterialByParameter_setMaterialParameters(UParticleModuleMaterialByParameter *mod, TArray< struct FName > val) { mod->MaterialParameters = val; }
TArray< class UMaterialInterface* > *ParticleModuleHelper::ParticleModuleMaterialByParameter_getDefaultMaterials(const UParticleModuleMaterialByParameter *mod) { return const_cast<TArray< class UMaterialInterface* > *>(&mod->DefaultMaterials); }
void ParticleModuleHelper::ParticleModuleMaterialByParameter_setDefaultMaterials(UParticleModuleMaterialByParameter *mod, TArray< class UMaterialInterface* > val) { mod->DefaultMaterials = val; }
TArray< class UMaterialInterface* > *ParticleModuleHelper::ParticleModuleMeshMaterial_getMeshMaterials(const UParticleModuleMeshMaterial *mod) { return const_cast<TArray< class UMaterialInterface* > *>(&mod->MeshMaterials); }
void ParticleModuleHelper::ParticleModuleMeshMaterial_setMeshMaterials(UParticleModuleMeshMaterial *mod, TArray< class UMaterialInterface* > val) { mod->MeshMaterials = val; }
int ParticleModuleHelper::ParticleModuleOrbitBase_getbUseEmitterTime(const UParticleModuleOrbitBase *mod) { return mod->bUseEmitterTime; }
void ParticleModuleHelper::ParticleModuleOrbitBase_setbUseEmitterTime(UParticleModuleOrbitBase *mod, int val) { mod->bUseEmitterTime = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleOrbit_getOffsetAmount(const UParticleModuleOrbit *mod) { return const_cast<struct FRawDistributionVector *>(&mod->OffsetAmount); }
void ParticleModuleHelper::ParticleModuleOrbit_setOffsetAmount(UParticleModuleOrbit *mod, struct FRawDistributionVector val) { mod->OffsetAmount = val; }
struct FOrbitOptions *ParticleModuleHelper::ParticleModuleOrbit_getOffsetOptions(const UParticleModuleOrbit *mod) { return const_cast<struct FOrbitOptions *>(&mod->OffsetOptions); }
void ParticleModuleHelper::ParticleModuleOrbit_setOffsetOptions(UParticleModuleOrbit *mod, struct FOrbitOptions val) { mod->OffsetOptions = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleOrbit_getRotationAmount(const UParticleModuleOrbit *mod) { return const_cast<struct FRawDistributionVector *>(&mod->RotationAmount); }
void ParticleModuleHelper::ParticleModuleOrbit_setRotationAmount(UParticleModuleOrbit *mod, struct FRawDistributionVector val) { mod->RotationAmount = val; }
struct FOrbitOptions *ParticleModuleHelper::ParticleModuleOrbit_getRotationOptions(const UParticleModuleOrbit *mod) { return const_cast<struct FOrbitOptions *>(&mod->RotationOptions); }
void ParticleModuleHelper::ParticleModuleOrbit_setRotationOptions(UParticleModuleOrbit *mod, struct FOrbitOptions val) { mod->RotationOptions = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleOrbit_getRotationRateAmount(const UParticleModuleOrbit *mod) { return const_cast<struct FRawDistributionVector *>(&mod->RotationRateAmount); }
void ParticleModuleHelper::ParticleModuleOrbit_setRotationRateAmount(UParticleModuleOrbit *mod, struct FRawDistributionVector val) { mod->RotationRateAmount = val; }
struct FOrbitOptions *ParticleModuleHelper::ParticleModuleOrbit_getRotationRateOptions(const UParticleModuleOrbit *mod) { return const_cast<struct FOrbitOptions *>(&mod->RotationRateOptions); }
void ParticleModuleHelper::ParticleModuleOrbit_setRotationRateOptions(UParticleModuleOrbit *mod, struct FOrbitOptions val) { mod->RotationRateOptions = val; }
TArray< struct FEmitterDynamicParameter > *ParticleModuleHelper::ParticleModuleParameterDynamic_getDynamicParams(const UParticleModuleParameterDynamic *mod) { return const_cast<TArray< struct FEmitterDynamicParameter > *>(&mod->DynamicParams); }
void ParticleModuleHelper::ParticleModuleParameterDynamic_setDynamicParams(UParticleModuleParameterDynamic *mod, TArray< struct FEmitterDynamicParameter > val) { mod->DynamicParams = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleParameterDynamic_Seeded_getRandomSeedInfo(const UParticleModuleParameterDynamic_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleParameterDynamic_Seeded_setRandomSeedInfo(UParticleModuleParameterDynamic_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbUseLocalSpace(const UParticleModuleRequired *mod) { return mod->bUseLocalSpace; }
void ParticleModuleHelper::ParticleModuleRequired_setbUseLocalSpace(UParticleModuleRequired *mod, int val) { mod->bUseLocalSpace = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbKillOnDeactivate(const UParticleModuleRequired *mod) { return mod->bKillOnDeactivate; }
void ParticleModuleHelper::ParticleModuleRequired_setbKillOnDeactivate(UParticleModuleRequired *mod, int val) { mod->bKillOnDeactivate = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbKillOnCompleted(const UParticleModuleRequired *mod) { return mod->bKillOnCompleted; }
void ParticleModuleHelper::ParticleModuleRequired_setbKillOnCompleted(UParticleModuleRequired *mod, int val) { mod->bKillOnCompleted = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbRequiresSorting(const UParticleModuleRequired *mod) { return mod->bRequiresSorting; }
void ParticleModuleHelper::ParticleModuleRequired_setbRequiresSorting(UParticleModuleRequired *mod, int val) { mod->bRequiresSorting = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbUseLegacyEmitterTime(const UParticleModuleRequired *mod) { return mod->bUseLegacyEmitterTime; }
void ParticleModuleHelper::ParticleModuleRequired_setbUseLegacyEmitterTime(UParticleModuleRequired *mod, int val) { mod->bUseLegacyEmitterTime = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbEmitterDurationUseRange(const UParticleModuleRequired *mod) { return mod->bEmitterDurationUseRange; }
void ParticleModuleHelper::ParticleModuleRequired_setbEmitterDurationUseRange(UParticleModuleRequired *mod, int val) { mod->bEmitterDurationUseRange = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbDurationRecalcEachLoop(const UParticleModuleRequired *mod) { return mod->bDurationRecalcEachLoop; }
void ParticleModuleHelper::ParticleModuleRequired_setbDurationRecalcEachLoop(UParticleModuleRequired *mod, int val) { mod->bDurationRecalcEachLoop = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbEmitterDelayUseRange(const UParticleModuleRequired *mod) { return mod->bEmitterDelayUseRange; }
void ParticleModuleHelper::ParticleModuleRequired_setbEmitterDelayUseRange(UParticleModuleRequired *mod, int val) { mod->bEmitterDelayUseRange = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbDelayFirstLoopOnly(const UParticleModuleRequired *mod) { return mod->bDelayFirstLoopOnly; }
void ParticleModuleHelper::ParticleModuleRequired_setbDelayFirstLoopOnly(UParticleModuleRequired *mod, int val) { mod->bDelayFirstLoopOnly = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbScaleUV(const UParticleModuleRequired *mod) { return mod->bScaleUV; }
void ParticleModuleHelper::ParticleModuleRequired_setbScaleUV(UParticleModuleRequired *mod, int val) { mod->bScaleUV = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbDirectUV(const UParticleModuleRequired *mod) { return mod->bDirectUV; }
void ParticleModuleHelper::ParticleModuleRequired_setbDirectUV(UParticleModuleRequired *mod, int val) { mod->bDirectUV = val; }
int ParticleModuleHelper::ParticleModuleRequired_getbUseMaxDrawCount(const UParticleModuleRequired *mod) { return mod->bUseMaxDrawCount; }
void ParticleModuleHelper::ParticleModuleRequired_setbUseMaxDrawCount(UParticleModuleRequired *mod, int val) { mod->bUseMaxDrawCount = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleRequired_getSpawnRate(const UParticleModuleRequired *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->SpawnRate); }
void ParticleModuleHelper::ParticleModuleRequired_setSpawnRate(UParticleModuleRequired *mod, struct FRawDistributionFloat val) { mod->SpawnRate = val; }
TArray< struct FParticleBurst > *ParticleModuleHelper::ParticleModuleRequired_getBurstList(const UParticleModuleRequired *mod) { return const_cast<TArray< struct FParticleBurst > *>(&mod->BurstList); }
void ParticleModuleHelper::ParticleModuleRequired_setBurstList(UParticleModuleRequired *mod, TArray< struct FParticleBurst > val) { mod->BurstList = val; }
struct FVector *ParticleModuleHelper::ParticleModuleRequired_getNormalsSphereCenter(const UParticleModuleRequired *mod) { return const_cast<struct FVector *>(&mod->NormalsSphereCenter); }
void ParticleModuleHelper::ParticleModuleRequired_setNormalsSphereCenter(UParticleModuleRequired *mod, struct FVector val) { mod->NormalsSphereCenter = val; }
struct FVector *ParticleModuleHelper::ParticleModuleRequired_getNormalsCylinderDirection(const UParticleModuleRequired *mod) { return const_cast<struct FVector *>(&mod->NormalsCylinderDirection); }
void ParticleModuleHelper::ParticleModuleRequired_setNormalsCylinderDirection(UParticleModuleRequired *mod, struct FVector val) { mod->NormalsCylinderDirection = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleMeshRotation_getStartRotation(const UParticleModuleMeshRotation *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartRotation); }
void ParticleModuleHelper::ParticleModuleMeshRotation_setStartRotation(UParticleModuleMeshRotation *mod, struct FRawDistributionVector val) { mod->StartRotation = val; }
int ParticleModuleHelper::ParticleModuleMeshRotation_getbInheritParent(const UParticleModuleMeshRotation *mod) { return mod->bInheritParent; }
void ParticleModuleHelper::ParticleModuleMeshRotation_setbInheritParent(UParticleModuleMeshRotation *mod, int val) { mod->bInheritParent = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleMeshRotation_Seeded_getRandomSeedInfo(const UParticleModuleMeshRotation_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleMeshRotation_Seeded_setRandomSeedInfo(UParticleModuleMeshRotation_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleRotation_getStartRotation(const UParticleModuleRotation *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartRotation); }
void ParticleModuleHelper::ParticleModuleRotation_setStartRotation(UParticleModuleRotation *mod, struct FRawDistributionFloat val) { mod->StartRotation = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleRotation_Seeded_getRandomSeedInfo(const UParticleModuleRotation_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleRotation_Seeded_setRandomSeedInfo(UParticleModuleRotation_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleRotationOverLifetime_getRotationOverLife(const UParticleModuleRotationOverLifetime *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->RotationOverLife); }
void ParticleModuleHelper::ParticleModuleRotationOverLifetime_setRotationOverLife(UParticleModuleRotationOverLifetime *mod, struct FRawDistributionFloat val) { mod->RotationOverLife = val; }
int ParticleModuleHelper::ParticleModuleRotationOverLifetime_getScale(const UParticleModuleRotationOverLifetime *mod) { return mod->Scale; }
void ParticleModuleHelper::ParticleModuleRotationOverLifetime_setScale(UParticleModuleRotationOverLifetime *mod, int val) { mod->Scale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleMeshRotationRate_getStartRotationRate(const UParticleModuleMeshRotationRate *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartRotationRate); }
void ParticleModuleHelper::ParticleModuleMeshRotationRate_setStartRotationRate(UParticleModuleMeshRotationRate *mod, struct FRawDistributionVector val) { mod->StartRotationRate = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleMeshRotationRate_Seeded_getRandomSeedInfo(const UParticleModuleMeshRotationRate_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleMeshRotationRate_Seeded_setRandomSeedInfo(UParticleModuleMeshRotationRate_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleMeshRotationRateMultiplyLife_getLifeMultiplier(const UParticleModuleMeshRotationRateMultiplyLife *mod) { return const_cast<struct FRawDistributionVector *>(&mod->LifeMultiplier); }
void ParticleModuleHelper::ParticleModuleMeshRotationRateMultiplyLife_setLifeMultiplier(UParticleModuleMeshRotationRateMultiplyLife *mod, struct FRawDistributionVector val) { mod->LifeMultiplier = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleMeshRotationRateOverLife_getRotRate(const UParticleModuleMeshRotationRateOverLife *mod) { return const_cast<struct FRawDistributionVector *>(&mod->RotRate); }
void ParticleModuleHelper::ParticleModuleMeshRotationRateOverLife_setRotRate(UParticleModuleMeshRotationRateOverLife *mod, struct FRawDistributionVector val) { mod->RotRate = val; }
int ParticleModuleHelper::ParticleModuleMeshRotationRateOverLife_getbScaleRotRate(const UParticleModuleMeshRotationRateOverLife *mod) { return mod->bScaleRotRate; }
void ParticleModuleHelper::ParticleModuleMeshRotationRateOverLife_setbScaleRotRate(UParticleModuleMeshRotationRateOverLife *mod, int val) { mod->bScaleRotRate = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleRotationRate_getStartRotationRate(const UParticleModuleRotationRate *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartRotationRate); }
void ParticleModuleHelper::ParticleModuleRotationRate_setStartRotationRate(UParticleModuleRotationRate *mod, struct FRawDistributionFloat val) { mod->StartRotationRate = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleRotationRate_Seeded_getRandomSeedInfo(const UParticleModuleRotationRate_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleRotationRate_Seeded_setRandomSeedInfo(UParticleModuleRotationRate_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleRotationRateMultiplyLife_getLifeMultiplier(const UParticleModuleRotationRateMultiplyLife *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->LifeMultiplier); }
void ParticleModuleHelper::ParticleModuleRotationRateMultiplyLife_setLifeMultiplier(UParticleModuleRotationRateMultiplyLife *mod, struct FRawDistributionFloat val) { mod->LifeMultiplier = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSize_getStartSize(const UParticleModuleSize *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartSize); }
void ParticleModuleHelper::ParticleModuleSize_setStartSize(UParticleModuleSize *mod, struct FRawDistributionVector val) { mod->StartSize = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleSize_Seeded_getRandomSeedInfo(const UParticleModuleSize_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleSize_Seeded_setRandomSeedInfo(UParticleModuleSize_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSizeMultiplyLife_getLifeMultiplier(const UParticleModuleSizeMultiplyLife *mod) { return const_cast<struct FRawDistributionVector *>(&mod->LifeMultiplier); }
void ParticleModuleHelper::ParticleModuleSizeMultiplyLife_setLifeMultiplier(UParticleModuleSizeMultiplyLife *mod, struct FRawDistributionVector val) { mod->LifeMultiplier = val; }
int ParticleModuleHelper::ParticleModuleSizeMultiplyLife_getMultiplyX(const UParticleModuleSizeMultiplyLife *mod) { return mod->MultiplyX; }
void ParticleModuleHelper::ParticleModuleSizeMultiplyLife_setMultiplyX(UParticleModuleSizeMultiplyLife *mod, int val) { mod->MultiplyX = val; }
int ParticleModuleHelper::ParticleModuleSizeMultiplyLife_getMultiplyY(const UParticleModuleSizeMultiplyLife *mod) { return mod->MultiplyY; }
void ParticleModuleHelper::ParticleModuleSizeMultiplyLife_setMultiplyY(UParticleModuleSizeMultiplyLife *mod, int val) { mod->MultiplyY = val; }
int ParticleModuleHelper::ParticleModuleSizeMultiplyLife_getMultiplyZ(const UParticleModuleSizeMultiplyLife *mod) { return mod->MultiplyZ; }
void ParticleModuleHelper::ParticleModuleSizeMultiplyLife_setMultiplyZ(UParticleModuleSizeMultiplyLife *mod, int val) { mod->MultiplyZ = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_getVelocityMultiplier(const UParticleModuleSizeMultiplyVelocity *mod) { return const_cast<struct FRawDistributionVector *>(&mod->VelocityMultiplier); }
void ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_setVelocityMultiplier(UParticleModuleSizeMultiplyVelocity *mod, struct FRawDistributionVector val) { mod->VelocityMultiplier = val; }
int ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_getMultiplyX(const UParticleModuleSizeMultiplyVelocity *mod) { return mod->MultiplyX; }
void ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_setMultiplyX(UParticleModuleSizeMultiplyVelocity *mod, int val) { mod->MultiplyX = val; }
int ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_getMultiplyY(const UParticleModuleSizeMultiplyVelocity *mod) { return mod->MultiplyY; }
void ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_setMultiplyY(UParticleModuleSizeMultiplyVelocity *mod, int val) { mod->MultiplyY = val; }
int ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_getMultiplyZ(const UParticleModuleSizeMultiplyVelocity *mod) { return mod->MultiplyZ; }
void ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_setMultiplyZ(UParticleModuleSizeMultiplyVelocity *mod, int val) { mod->MultiplyZ = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSizeScale_getSizeScale(const UParticleModuleSizeScale *mod) { return const_cast<struct FRawDistributionVector *>(&mod->SizeScale); }
void ParticleModuleHelper::ParticleModuleSizeScale_setSizeScale(UParticleModuleSizeScale *mod, struct FRawDistributionVector val) { mod->SizeScale = val; }
int ParticleModuleHelper::ParticleModuleSizeScale_getEnableX(const UParticleModuleSizeScale *mod) { return mod->EnableX; }
void ParticleModuleHelper::ParticleModuleSizeScale_setEnableX(UParticleModuleSizeScale *mod, int val) { mod->EnableX = val; }
int ParticleModuleHelper::ParticleModuleSizeScale_getEnableY(const UParticleModuleSizeScale *mod) { return mod->EnableY; }
void ParticleModuleHelper::ParticleModuleSizeScale_setEnableY(UParticleModuleSizeScale *mod, int val) { mod->EnableY = val; }
int ParticleModuleHelper::ParticleModuleSizeScale_getEnableZ(const UParticleModuleSizeScale *mod) { return mod->EnableZ; }
void ParticleModuleHelper::ParticleModuleSizeScale_setEnableZ(UParticleModuleSizeScale *mod, int val) { mod->EnableZ = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSizeScaleByTime_getSizeScaleByTime(const UParticleModuleSizeScaleByTime *mod) { return const_cast<struct FRawDistributionVector *>(&mod->SizeScaleByTime); }
void ParticleModuleHelper::ParticleModuleSizeScaleByTime_setSizeScaleByTime(UParticleModuleSizeScaleByTime *mod, struct FRawDistributionVector val) { mod->SizeScaleByTime = val; }
int ParticleModuleHelper::ParticleModuleSizeScaleByTime_getbEnableX(const UParticleModuleSizeScaleByTime *mod) { return mod->bEnableX; }
void ParticleModuleHelper::ParticleModuleSizeScaleByTime_setbEnableX(UParticleModuleSizeScaleByTime *mod, int val) { mod->bEnableX = val; }
int ParticleModuleHelper::ParticleModuleSizeScaleByTime_getbEnableY(const UParticleModuleSizeScaleByTime *mod) { return mod->bEnableY; }
void ParticleModuleHelper::ParticleModuleSizeScaleByTime_setbEnableY(UParticleModuleSizeScaleByTime *mod, int val) { mod->bEnableY = val; }
int ParticleModuleHelper::ParticleModuleSizeScaleByTime_getbEnableZ(const UParticleModuleSizeScaleByTime *mod) { return mod->bEnableZ; }
void ParticleModuleHelper::ParticleModuleSizeScaleByTime_setbEnableZ(UParticleModuleSizeScaleByTime *mod, int val) { mod->bEnableZ = val; }
int ParticleModuleHelper::ParticleModuleSpawnBase_getbProcessSpawnRate(const UParticleModuleSpawnBase *mod) { return mod->bProcessSpawnRate; }
void ParticleModuleHelper::ParticleModuleSpawnBase_setbProcessSpawnRate(UParticleModuleSpawnBase *mod, int val) { mod->bProcessSpawnRate = val; }
int ParticleModuleHelper::ParticleModuleSpawnBase_getbProcessBurstList(const UParticleModuleSpawnBase *mod) { return mod->bProcessBurstList; }
void ParticleModuleHelper::ParticleModuleSpawnBase_setbProcessBurstList(UParticleModuleSpawnBase *mod, int val) { mod->bProcessBurstList = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleSpawn_getRate(const UParticleModuleSpawn *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Rate); }
void ParticleModuleHelper::ParticleModuleSpawn_setRate(UParticleModuleSpawn *mod, struct FRawDistributionFloat val) { mod->Rate = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleSpawn_getRateScale(const UParticleModuleSpawn *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->RateScale); }
void ParticleModuleHelper::ParticleModuleSpawn_setRateScale(UParticleModuleSpawn *mod, struct FRawDistributionFloat val) { mod->RateScale = val; }
TArray< struct FParticleBurst > *ParticleModuleHelper::ParticleModuleSpawn_getBurstList(const UParticleModuleSpawn *mod) { return const_cast<TArray< struct FParticleBurst > *>(&mod->BurstList); }
void ParticleModuleHelper::ParticleModuleSpawn_setBurstList(UParticleModuleSpawn *mod, TArray< struct FParticleBurst > val) { mod->BurstList = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleSpawnPerUnit_getSpawnPerUnit(const UParticleModuleSpawnPerUnit *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->SpawnPerUnit); }
void ParticleModuleHelper::ParticleModuleSpawnPerUnit_setSpawnPerUnit(UParticleModuleSpawnPerUnit *mod, struct FRawDistributionFloat val) { mod->SpawnPerUnit = val; }
int ParticleModuleHelper::ParticleModuleSpawnPerUnit_getbIgnoreSpawnRateWhenMoving(const UParticleModuleSpawnPerUnit *mod) { return mod->bIgnoreSpawnRateWhenMoving; }
void ParticleModuleHelper::ParticleModuleSpawnPerUnit_setbIgnoreSpawnRateWhenMoving(UParticleModuleSpawnPerUnit *mod, int val) { mod->bIgnoreSpawnRateWhenMoving = val; }
int ParticleModuleHelper::ParticleModuleSpawnPerUnit_getbIgnoreMovementAlongX(const UParticleModuleSpawnPerUnit *mod) { return mod->bIgnoreMovementAlongX; }
void ParticleModuleHelper::ParticleModuleSpawnPerUnit_setbIgnoreMovementAlongX(UParticleModuleSpawnPerUnit *mod, int val) { mod->bIgnoreMovementAlongX = val; }
int ParticleModuleHelper::ParticleModuleSpawnPerUnit_getbIgnoreMovementAlongY(const UParticleModuleSpawnPerUnit *mod) { return mod->bIgnoreMovementAlongY; }
void ParticleModuleHelper::ParticleModuleSpawnPerUnit_setbIgnoreMovementAlongY(UParticleModuleSpawnPerUnit *mod, int val) { mod->bIgnoreMovementAlongY = val; }
int ParticleModuleHelper::ParticleModuleSpawnPerUnit_getbIgnoreMovementAlongZ(const UParticleModuleSpawnPerUnit *mod) { return mod->bIgnoreMovementAlongZ; }
void ParticleModuleHelper::ParticleModuleSpawnPerUnit_setbIgnoreMovementAlongZ(UParticleModuleSpawnPerUnit *mod, int val) { mod->bIgnoreMovementAlongZ = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleSubUV_getSubImageIndex(const UParticleModuleSubUV *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->SubImageIndex); }
void ParticleModuleHelper::ParticleModuleSubUV_setSubImageIndex(UParticleModuleSubUV *mod, struct FRawDistributionFloat val) { mod->SubImageIndex = val; }
int ParticleModuleHelper::ParticleModuleSubUVMovie_getbUseEmitterTime(const UParticleModuleSubUVMovie *mod) { return mod->bUseEmitterTime; }
void ParticleModuleHelper::ParticleModuleSubUVMovie_setbUseEmitterTime(UParticleModuleSubUVMovie *mod, int val) { mod->bUseEmitterTime = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleSubUVMovie_getFrameRate(const UParticleModuleSubUVMovie *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->FrameRate); }
void ParticleModuleHelper::ParticleModuleSubUVMovie_setFrameRate(UParticleModuleSubUVMovie *mod, struct FRawDistributionFloat val) { mod->FrameRate = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSubUVDirect_getSubUVPosition(const UParticleModuleSubUVDirect *mod) { return const_cast<struct FRawDistributionVector *>(&mod->SubUVPosition); }
void ParticleModuleHelper::ParticleModuleSubUVDirect_setSubUVPosition(UParticleModuleSubUVDirect *mod, struct FRawDistributionVector val) { mod->SubUVPosition = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSubUVDirect_getSubUVSize(const UParticleModuleSubUVDirect *mod) { return const_cast<struct FRawDistributionVector *>(&mod->SubUVSize); }
void ParticleModuleHelper::ParticleModuleSubUVDirect_setSubUVSize(UParticleModuleSubUVDirect *mod, struct FRawDistributionVector val) { mod->SubUVSize = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleSubUVSelect_getSubImageSelect(const UParticleModuleSubUVSelect *mod) { return const_cast<struct FRawDistributionVector *>(&mod->SubImageSelect); }
void ParticleModuleHelper::ParticleModuleSubUVSelect_setSubImageSelect(UParticleModuleSubUVSelect *mod, struct FRawDistributionVector val) { mod->SubImageSelect = val; }
struct FName *ParticleModuleHelper::ParticleModuleTrailSource_getSourceName(const UParticleModuleTrailSource *mod) { return const_cast<struct FName *>(&mod->SourceName); }
void ParticleModuleHelper::ParticleModuleTrailSource_setSourceName(UParticleModuleTrailSource *mod, struct FName val) { mod->SourceName = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTrailSource_getSourceStrength(const UParticleModuleTrailSource *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->SourceStrength); }
void ParticleModuleHelper::ParticleModuleTrailSource_setSourceStrength(UParticleModuleTrailSource *mod, struct FRawDistributionFloat val) { mod->SourceStrength = val; }
int ParticleModuleHelper::ParticleModuleTrailSource_getbLockSourceStength(const UParticleModuleTrailSource *mod) { return mod->bLockSourceStength; }
void ParticleModuleHelper::ParticleModuleTrailSource_setbLockSourceStength(UParticleModuleTrailSource *mod, int val) { mod->bLockSourceStength = val; }
int ParticleModuleHelper::ParticleModuleTrailSource_getbInheritRotation(const UParticleModuleTrailSource *mod) { return mod->bInheritRotation; }
void ParticleModuleHelper::ParticleModuleTrailSource_setbInheritRotation(UParticleModuleTrailSource *mod, int val) { mod->bInheritRotation = val; }
TArray< struct FVector > *ParticleModuleHelper::ParticleModuleTrailSource_getSourceOffsetDefaults(const UParticleModuleTrailSource *mod) { return const_cast<TArray< struct FVector > *>(&mod->SourceOffsetDefaults); }
void ParticleModuleHelper::ParticleModuleTrailSource_setSourceOffsetDefaults(UParticleModuleTrailSource *mod, TArray< struct FVector > val) { mod->SourceOffsetDefaults = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTrailTaper_getTaperFactor(const UParticleModuleTrailTaper *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->TaperFactor); }
void ParticleModuleHelper::ParticleModuleTrailTaper_setTaperFactor(UParticleModuleTrailTaper *mod, struct FRawDistributionFloat val) { mod->TaperFactor = val; }
struct FName *ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getControlEdgeName(const UParticleModuleTypeDataAnimTrail *mod) { return const_cast<struct FName *>(&mod->ControlEdgeName); }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setControlEdgeName(UParticleModuleTypeDataAnimTrail *mod, struct FName val) { mod->ControlEdgeName = val; }
int ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbDeadTrailsOnDeactivate(const UParticleModuleTypeDataAnimTrail *mod) { return mod->bDeadTrailsOnDeactivate; }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbDeadTrailsOnDeactivate(UParticleModuleTypeDataAnimTrail *mod, int val) { mod->bDeadTrailsOnDeactivate = val; }
int ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbClipSourceSegement(const UParticleModuleTypeDataAnimTrail *mod) { return mod->bClipSourceSegement; }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbClipSourceSegement(UParticleModuleTypeDataAnimTrail *mod, int val) { mod->bClipSourceSegement = val; }
int ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbEnablePreviousTangentRecalculation(const UParticleModuleTypeDataAnimTrail *mod) { return mod->bEnablePreviousTangentRecalculation; }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbEnablePreviousTangentRecalculation(UParticleModuleTypeDataAnimTrail *mod, int val) { mod->bEnablePreviousTangentRecalculation = val; }
int ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbTangentRecalculationEveryFrame(const UParticleModuleTypeDataAnimTrail *mod) { return mod->bTangentRecalculationEveryFrame; }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbTangentRecalculationEveryFrame(UParticleModuleTypeDataAnimTrail *mod, int val) { mod->bTangentRecalculationEveryFrame = val; }
int ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbRenderGeometry(const UParticleModuleTypeDataAnimTrail *mod) { return mod->bRenderGeometry; }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbRenderGeometry(UParticleModuleTypeDataAnimTrail *mod, int val) { mod->bRenderGeometry = val; }
int ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbRenderSpawnPoints(const UParticleModuleTypeDataAnimTrail *mod) { return mod->bRenderSpawnPoints; }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbRenderSpawnPoints(UParticleModuleTypeDataAnimTrail *mod, int val) { mod->bRenderSpawnPoints = val; }
int ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbRenderTangents(const UParticleModuleTypeDataAnimTrail *mod) { return mod->bRenderTangents; }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbRenderTangents(UParticleModuleTypeDataAnimTrail *mod, int val) { mod->bRenderTangents = val; }
int ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbRenderTessellation(const UParticleModuleTypeDataAnimTrail *mod) { return mod->bRenderTessellation; }
void ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbRenderTessellation(UParticleModuleTypeDataAnimTrail *mod, int val) { mod->bRenderTessellation = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTypeDataBeam_getDistance(const UParticleModuleTypeDataBeam *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Distance); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setDistance(UParticleModuleTypeDataBeam *mod, struct FRawDistributionFloat val) { mod->Distance = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleTypeDataBeam_getEndPoint(const UParticleModuleTypeDataBeam *mod) { return const_cast<struct FRawDistributionVector *>(&mod->EndPoint); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setEndPoint(UParticleModuleTypeDataBeam *mod, struct FRawDistributionVector val) { mod->EndPoint = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTypeDataBeam_getEmitterStrength(const UParticleModuleTypeDataBeam *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->EmitterStrength); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setEmitterStrength(UParticleModuleTypeDataBeam *mod, struct FRawDistributionFloat val) { mod->EmitterStrength = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTypeDataBeam_getTargetStrength(const UParticleModuleTypeDataBeam *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->TargetStrength); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setTargetStrength(UParticleModuleTypeDataBeam *mod, struct FRawDistributionFloat val) { mod->TargetStrength = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleTypeDataBeam_getEndPointDirection(const UParticleModuleTypeDataBeam *mod) { return const_cast<struct FRawDistributionVector *>(&mod->EndPointDirection); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setEndPointDirection(UParticleModuleTypeDataBeam *mod, struct FRawDistributionVector val) { mod->EndPointDirection = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam_getRenderGeometry(const UParticleModuleTypeDataBeam *mod) { return mod->RenderGeometry; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setRenderGeometry(UParticleModuleTypeDataBeam *mod, int val) { mod->RenderGeometry = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam_getRenderDirectLine(const UParticleModuleTypeDataBeam *mod) { return mod->RenderDirectLine; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setRenderDirectLine(UParticleModuleTypeDataBeam *mod, int val) { mod->RenderDirectLine = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam_getRenderLines(const UParticleModuleTypeDataBeam *mod) { return mod->RenderLines; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setRenderLines(UParticleModuleTypeDataBeam *mod, int val) { mod->RenderLines = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam_getRenderTessellation(const UParticleModuleTypeDataBeam *mod) { return mod->RenderTessellation; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam_setRenderTessellation(UParticleModuleTypeDataBeam *mod, int val) { mod->RenderTessellation = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam2_getbAlwaysOn(const UParticleModuleTypeDataBeam2 *mod) { return mod->bAlwaysOn; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setbAlwaysOn(UParticleModuleTypeDataBeam2 *mod, int val) { mod->bAlwaysOn = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam2_getRenderGeometry(const UParticleModuleTypeDataBeam2 *mod) { return mod->RenderGeometry; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setRenderGeometry(UParticleModuleTypeDataBeam2 *mod, int val) { mod->RenderGeometry = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam2_getRenderDirectLine(const UParticleModuleTypeDataBeam2 *mod) { return mod->RenderDirectLine; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setRenderDirectLine(UParticleModuleTypeDataBeam2 *mod, int val) { mod->RenderDirectLine = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam2_getRenderLines(const UParticleModuleTypeDataBeam2 *mod) { return mod->RenderLines; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setRenderLines(UParticleModuleTypeDataBeam2 *mod, int val) { mod->RenderLines = val; }
int ParticleModuleHelper::ParticleModuleTypeDataBeam2_getRenderTessellation(const UParticleModuleTypeDataBeam2 *mod) { return mod->RenderTessellation; }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setRenderTessellation(UParticleModuleTypeDataBeam2 *mod, int val) { mod->RenderTessellation = val; }
struct FName *ParticleModuleHelper::ParticleModuleTypeDataBeam2_getBranchParentName(const UParticleModuleTypeDataBeam2 *mod) { return const_cast<struct FName *>(&mod->BranchParentName); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setBranchParentName(UParticleModuleTypeDataBeam2 *mod, struct FName val) { mod->BranchParentName = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTypeDataBeam2_getDistance(const UParticleModuleTypeDataBeam2 *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Distance); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setDistance(UParticleModuleTypeDataBeam2 *mod, struct FRawDistributionFloat val) { mod->Distance = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTypeDataBeam2_getTaperFactor(const UParticleModuleTypeDataBeam2 *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->TaperFactor); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setTaperFactor(UParticleModuleTypeDataBeam2 *mod, struct FRawDistributionFloat val) { mod->TaperFactor = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTypeDataBeam2_getTaperScale(const UParticleModuleTypeDataBeam2 *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->TaperScale); }
void ParticleModuleHelper::ParticleModuleTypeDataBeam2_setTaperScale(UParticleModuleTypeDataBeam2 *mod, struct FRawDistributionFloat val) { mod->TaperScale = val; }
int ParticleModuleHelper::ParticleModuleTypeDataMesh_getCastShadows(const UParticleModuleTypeDataMesh *mod) { return mod->CastShadows; }
void ParticleModuleHelper::ParticleModuleTypeDataMesh_setCastShadows(UParticleModuleTypeDataMesh *mod, int val) { mod->CastShadows = val; }
int ParticleModuleHelper::ParticleModuleTypeDataMesh_getDoCollisions(const UParticleModuleTypeDataMesh *mod) { return mod->DoCollisions; }
void ParticleModuleHelper::ParticleModuleTypeDataMesh_setDoCollisions(UParticleModuleTypeDataMesh *mod, int val) { mod->DoCollisions = val; }
int ParticleModuleHelper::ParticleModuleTypeDataMesh_getbAllowMotionBlur(const UParticleModuleTypeDataMesh *mod) { return mod->bAllowMotionBlur; }
void ParticleModuleHelper::ParticleModuleTypeDataMesh_setbAllowMotionBlur(UParticleModuleTypeDataMesh *mod, int val) { mod->bAllowMotionBlur = val; }
int ParticleModuleHelper::ParticleModuleTypeDataMesh_getbOverrideMaterial(const UParticleModuleTypeDataMesh *mod) { return mod->bOverrideMaterial; }
void ParticleModuleHelper::ParticleModuleTypeDataMesh_setbOverrideMaterial(UParticleModuleTypeDataMesh *mod, int val) { mod->bOverrideMaterial = val; }
int ParticleModuleHelper::ParticleModuleTypeDataMesh_getbCameraFacing(const UParticleModuleTypeDataMesh *mod) { return mod->bCameraFacing; }
void ParticleModuleHelper::ParticleModuleTypeDataMesh_setbCameraFacing(UParticleModuleTypeDataMesh *mod, int val) { mod->bCameraFacing = val; }
int ParticleModuleHelper::ParticleModuleTypeDataMesh_getbApplyParticleRotationAsSpin(const UParticleModuleTypeDataMesh *mod) { return mod->bApplyParticleRotationAsSpin; }
void ParticleModuleHelper::ParticleModuleTypeDataMesh_setbApplyParticleRotationAsSpin(UParticleModuleTypeDataMesh *mod, int val) { mod->bApplyParticleRotationAsSpin = val; }
struct FPointer *ParticleModuleHelper::ParticleModuleTypeDataMeshPhysX_getRenderInstance(const UParticleModuleTypeDataMeshPhysX *mod) { return const_cast<struct FPointer *>(&mod->RenderInstance); }
void ParticleModuleHelper::ParticleModuleTypeDataMeshPhysX_setRenderInstance(UParticleModuleTypeDataMeshPhysX *mod, struct FPointer val) { mod->RenderInstance = val; }
struct FPhysXEmitterVerticalLodProperties *ParticleModuleHelper::ParticleModuleTypeDataMeshPhysX_getVerticalLod(const UParticleModuleTypeDataMeshPhysX *mod) { return const_cast<struct FPhysXEmitterVerticalLodProperties *>(&mod->VerticalLod); }
void ParticleModuleHelper::ParticleModuleTypeDataMeshPhysX_setVerticalLod(UParticleModuleTypeDataMeshPhysX *mod, struct FPhysXEmitterVerticalLodProperties val) { mod->VerticalLod = val; }
struct FPhysXEmitterVerticalLodProperties *ParticleModuleHelper::ParticleModuleTypeDataPhysX_getVerticalLod(const UParticleModuleTypeDataPhysX *mod) { return const_cast<struct FPhysXEmitterVerticalLodProperties *>(&mod->VerticalLod); }
void ParticleModuleHelper::ParticleModuleTypeDataPhysX_setVerticalLod(UParticleModuleTypeDataPhysX *mod, struct FPhysXEmitterVerticalLodProperties val) { mod->VerticalLod = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbDeadTrailsOnDeactivate(const UParticleModuleTypeDataRibbon *mod) { return mod->bDeadTrailsOnDeactivate; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbDeadTrailsOnDeactivate(UParticleModuleTypeDataRibbon *mod, int val) { mod->bDeadTrailsOnDeactivate = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbDeadTrailsOnSourceLoss(const UParticleModuleTypeDataRibbon *mod) { return mod->bDeadTrailsOnSourceLoss; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbDeadTrailsOnSourceLoss(UParticleModuleTypeDataRibbon *mod, int val) { mod->bDeadTrailsOnSourceLoss = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbClipSourceSegement(const UParticleModuleTypeDataRibbon *mod) { return mod->bClipSourceSegement; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbClipSourceSegement(UParticleModuleTypeDataRibbon *mod, int val) { mod->bClipSourceSegement = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbEnablePreviousTangentRecalculation(const UParticleModuleTypeDataRibbon *mod) { return mod->bEnablePreviousTangentRecalculation; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbEnablePreviousTangentRecalculation(UParticleModuleTypeDataRibbon *mod, int val) { mod->bEnablePreviousTangentRecalculation = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbTangentRecalculationEveryFrame(const UParticleModuleTypeDataRibbon *mod) { return mod->bTangentRecalculationEveryFrame; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbTangentRecalculationEveryFrame(UParticleModuleTypeDataRibbon *mod, int val) { mod->bTangentRecalculationEveryFrame = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbRenderGeometry(const UParticleModuleTypeDataRibbon *mod) { return mod->bRenderGeometry; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbRenderGeometry(UParticleModuleTypeDataRibbon *mod, int val) { mod->bRenderGeometry = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbRenderSpawnPoints(const UParticleModuleTypeDataRibbon *mod) { return mod->bRenderSpawnPoints; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbRenderSpawnPoints(UParticleModuleTypeDataRibbon *mod, int val) { mod->bRenderSpawnPoints = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbRenderTangents(const UParticleModuleTypeDataRibbon *mod) { return mod->bRenderTangents; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbRenderTangents(UParticleModuleTypeDataRibbon *mod, int val) { mod->bRenderTangents = val; }
int ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbRenderTessellation(const UParticleModuleTypeDataRibbon *mod) { return mod->bRenderTessellation; }
void ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbRenderTessellation(UParticleModuleTypeDataRibbon *mod, int val) { mod->bRenderTessellation = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail_getRenderGeometry(const UParticleModuleTypeDataTrail *mod) { return mod->RenderGeometry; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail_setRenderGeometry(UParticleModuleTypeDataTrail *mod, int val) { mod->RenderGeometry = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail_getRenderLines(const UParticleModuleTypeDataTrail *mod) { return mod->RenderLines; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail_setRenderLines(UParticleModuleTypeDataTrail *mod, int val) { mod->RenderLines = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail_getRenderTessellation(const UParticleModuleTypeDataTrail *mod) { return mod->RenderTessellation; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail_setRenderTessellation(UParticleModuleTypeDataTrail *mod, int val) { mod->RenderTessellation = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail_getTapered(const UParticleModuleTypeDataTrail *mod) { return mod->Tapered; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail_setTapered(UParticleModuleTypeDataTrail *mod, int val) { mod->Tapered = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail_getSpawnByDistance(const UParticleModuleTypeDataTrail *mod) { return mod->SpawnByDistance; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail_setSpawnByDistance(UParticleModuleTypeDataTrail *mod, int val) { mod->SpawnByDistance = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleTypeDataTrail_getTension(const UParticleModuleTypeDataTrail *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Tension); }
void ParticleModuleHelper::ParticleModuleTypeDataTrail_setTension(UParticleModuleTypeDataTrail *mod, struct FRawDistributionFloat val) { mod->Tension = val; }
struct FVector *ParticleModuleHelper::ParticleModuleTypeDataTrail_getSpawnDistance(const UParticleModuleTypeDataTrail *mod) { return const_cast<struct FVector *>(&mod->SpawnDistance); }
void ParticleModuleHelper::ParticleModuleTypeDataTrail_setSpawnDistance(UParticleModuleTypeDataTrail *mod, struct FVector val) { mod->SpawnDistance = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail2_getbClipSourceSegement(const UParticleModuleTypeDataTrail2 *mod) { return mod->bClipSourceSegement; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail2_setbClipSourceSegement(UParticleModuleTypeDataTrail2 *mod, int val) { mod->bClipSourceSegement = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail2_getbClearTangents(const UParticleModuleTypeDataTrail2 *mod) { return mod->bClearTangents; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail2_setbClearTangents(UParticleModuleTypeDataTrail2 *mod, int val) { mod->bClearTangents = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail2_getRenderGeometry(const UParticleModuleTypeDataTrail2 *mod) { return mod->RenderGeometry; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail2_setRenderGeometry(UParticleModuleTypeDataTrail2 *mod, int val) { mod->RenderGeometry = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail2_getRenderDirectLine(const UParticleModuleTypeDataTrail2 *mod) { return mod->RenderDirectLine; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail2_setRenderDirectLine(UParticleModuleTypeDataTrail2 *mod, int val) { mod->RenderDirectLine = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail2_getRenderLines(const UParticleModuleTypeDataTrail2 *mod) { return mod->RenderLines; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail2_setRenderLines(UParticleModuleTypeDataTrail2 *mod, int val) { mod->RenderLines = val; }
int ParticleModuleHelper::ParticleModuleTypeDataTrail2_getRenderTessellation(const UParticleModuleTypeDataTrail2 *mod) { return mod->RenderTessellation; }
void ParticleModuleHelper::ParticleModuleTypeDataTrail2_setRenderTessellation(UParticleModuleTypeDataTrail2 *mod, int val) { mod->RenderTessellation = val; }
TArray< struct FName > *ParticleModuleHelper::ParticleModuleUberBase_getRequiredModules(const UParticleModuleUberBase *mod) { return const_cast<TArray< struct FName > *>(&mod->RequiredModules); }
void ParticleModuleHelper::ParticleModuleUberBase_setRequiredModules(UParticleModuleUberBase *mod, TArray< struct FName > val) { mod->RequiredModules = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCL_getLifetime(const UParticleModuleUberLTISIVCL *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Lifetime); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCL_setLifetime(UParticleModuleUberLTISIVCL *mod, struct FRawDistributionFloat val) { mod->Lifetime = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCL_getStartSize(const UParticleModuleUberLTISIVCL *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartSize); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCL_setStartSize(UParticleModuleUberLTISIVCL *mod, struct FRawDistributionVector val) { mod->StartSize = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCL_getStartVelocity(const UParticleModuleUberLTISIVCL *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartVelocity); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCL_setStartVelocity(UParticleModuleUberLTISIVCL *mod, struct FRawDistributionVector val) { mod->StartVelocity = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCL_getStartVelocityRadial(const UParticleModuleUberLTISIVCL *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartVelocityRadial); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCL_setStartVelocityRadial(UParticleModuleUberLTISIVCL *mod, struct FRawDistributionFloat val) { mod->StartVelocityRadial = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCL_getColorOverLife(const UParticleModuleUberLTISIVCL *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorOverLife); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCL_setColorOverLife(UParticleModuleUberLTISIVCL *mod, struct FRawDistributionVector val) { mod->ColorOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCL_getAlphaOverLife(const UParticleModuleUberLTISIVCL *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaOverLife); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCL_setAlphaOverLife(UParticleModuleUberLTISIVCL *mod, struct FRawDistributionFloat val) { mod->AlphaOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getLifetime(const UParticleModuleUberLTISIVCLIL *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Lifetime); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setLifetime(UParticleModuleUberLTISIVCLIL *mod, struct FRawDistributionFloat val) { mod->Lifetime = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getStartSize(const UParticleModuleUberLTISIVCLIL *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartSize); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setStartSize(UParticleModuleUberLTISIVCLIL *mod, struct FRawDistributionVector val) { mod->StartSize = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getStartVelocity(const UParticleModuleUberLTISIVCLIL *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartVelocity); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setStartVelocity(UParticleModuleUberLTISIVCLIL *mod, struct FRawDistributionVector val) { mod->StartVelocity = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getStartVelocityRadial(const UParticleModuleUberLTISIVCLIL *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartVelocityRadial); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setStartVelocityRadial(UParticleModuleUberLTISIVCLIL *mod, struct FRawDistributionFloat val) { mod->StartVelocityRadial = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getColorOverLife(const UParticleModuleUberLTISIVCLIL *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorOverLife); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setColorOverLife(UParticleModuleUberLTISIVCLIL *mod, struct FRawDistributionVector val) { mod->ColorOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getAlphaOverLife(const UParticleModuleUberLTISIVCLIL *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaOverLife); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setAlphaOverLife(UParticleModuleUberLTISIVCLIL *mod, struct FRawDistributionFloat val) { mod->AlphaOverLife = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getStartLocation(const UParticleModuleUberLTISIVCLIL *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartLocation); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setStartLocation(UParticleModuleUberLTISIVCLIL *mod, struct FRawDistributionVector val) { mod->StartLocation = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getLifetime(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Lifetime); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setLifetime(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionFloat val) { mod->Lifetime = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartSize(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartSize); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartSize(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionVector val) { mod->StartSize = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartVelocity(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartVelocity); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartVelocity(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionVector val) { mod->StartVelocity = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartVelocityRadial(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartVelocityRadial); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartVelocityRadial(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionFloat val) { mod->StartVelocityRadial = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getColorOverLife(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorOverLife); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setColorOverLife(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionVector val) { mod->ColorOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getAlphaOverLife(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaOverLife); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setAlphaOverLife(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionFloat val) { mod->AlphaOverLife = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartLocation(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartLocation); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartLocation(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionVector val) { mod->StartLocation = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartRotation(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartRotation); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartRotation(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionFloat val) { mod->StartRotation = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getSizeLifeMultiplier(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionVector *>(&mod->SizeLifeMultiplier); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setSizeLifeMultiplier(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionVector val) { mod->SizeLifeMultiplier = val; }
int ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getSizeMultiplyX(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return mod->SizeMultiplyX; }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setSizeMultiplyX(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, int val) { mod->SizeMultiplyX = val; }
int ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getSizeMultiplyY(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return mod->SizeMultiplyY; }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setSizeMultiplyY(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, int val) { mod->SizeMultiplyY = val; }
int ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getSizeMultiplyZ(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return mod->SizeMultiplyZ; }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setSizeMultiplyZ(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, int val) { mod->SizeMultiplyZ = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartRotationRate(const UParticleModuleUberLTISIVCLILIRSSBLIRR *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartRotationRate); }
void ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartRotationRate(UParticleModuleUberLTISIVCLILIRSSBLIRR *mod, struct FRawDistributionFloat val) { mod->StartRotationRate = val; }
struct FVector *ParticleModuleHelper::ParticleModuleUberRainDrops_getStartSizeMin(const UParticleModuleUberRainDrops *mod) { return const_cast<struct FVector *>(&mod->StartSizeMin); }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setStartSizeMin(UParticleModuleUberRainDrops *mod, struct FVector val) { mod->StartSizeMin = val; }
struct FVector *ParticleModuleHelper::ParticleModuleUberRainDrops_getStartSizeMax(const UParticleModuleUberRainDrops *mod) { return const_cast<struct FVector *>(&mod->StartSizeMax); }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setStartSizeMax(UParticleModuleUberRainDrops *mod, struct FVector val) { mod->StartSizeMax = val; }
struct FVector *ParticleModuleHelper::ParticleModuleUberRainDrops_getStartVelocityMin(const UParticleModuleUberRainDrops *mod) { return const_cast<struct FVector *>(&mod->StartVelocityMin); }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setStartVelocityMin(UParticleModuleUberRainDrops *mod, struct FVector val) { mod->StartVelocityMin = val; }
struct FVector *ParticleModuleHelper::ParticleModuleUberRainDrops_getStartVelocityMax(const UParticleModuleUberRainDrops *mod) { return const_cast<struct FVector *>(&mod->StartVelocityMax); }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setStartVelocityMax(UParticleModuleUberRainDrops *mod, struct FVector val) { mod->StartVelocityMax = val; }
struct FVector *ParticleModuleHelper::ParticleModuleUberRainDrops_getColorOverLife(const UParticleModuleUberRainDrops *mod) { return const_cast<struct FVector *>(&mod->ColorOverLife); }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setColorOverLife(UParticleModuleUberRainDrops *mod, struct FVector val) { mod->ColorOverLife = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbIsUsingCylinder(const UParticleModuleUberRainDrops *mod) { return mod->bIsUsingCylinder; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbIsUsingCylinder(UParticleModuleUberRainDrops *mod, int val) { mod->bIsUsingCylinder = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbPositive_X(const UParticleModuleUberRainDrops *mod) { return mod->bPositive_X; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbPositive_X(UParticleModuleUberRainDrops *mod, int val) { mod->bPositive_X = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbPositive_Y(const UParticleModuleUberRainDrops *mod) { return mod->bPositive_Y; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbPositive_Y(UParticleModuleUberRainDrops *mod, int val) { mod->bPositive_Y = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbPositive_Z(const UParticleModuleUberRainDrops *mod) { return mod->bPositive_Z; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbPositive_Z(UParticleModuleUberRainDrops *mod, int val) { mod->bPositive_Z = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbNegative_X(const UParticleModuleUberRainDrops *mod) { return mod->bNegative_X; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbNegative_X(UParticleModuleUberRainDrops *mod, int val) { mod->bNegative_X = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbNegative_Y(const UParticleModuleUberRainDrops *mod) { return mod->bNegative_Y; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbNegative_Y(UParticleModuleUberRainDrops *mod, int val) { mod->bNegative_Y = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbNegative_Z(const UParticleModuleUberRainDrops *mod) { return mod->bNegative_Z; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbNegative_Z(UParticleModuleUberRainDrops *mod, int val) { mod->bNegative_Z = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbSurfaceOnly(const UParticleModuleUberRainDrops *mod) { return mod->bSurfaceOnly; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbSurfaceOnly(UParticleModuleUberRainDrops *mod, int val) { mod->bSurfaceOnly = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbVelocity(const UParticleModuleUberRainDrops *mod) { return mod->bVelocity; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbVelocity(UParticleModuleUberRainDrops *mod, int val) { mod->bVelocity = val; }
int ParticleModuleHelper::ParticleModuleUberRainDrops_getbRadialVelocity(const UParticleModuleUberRainDrops *mod) { return mod->bRadialVelocity; }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setbRadialVelocity(UParticleModuleUberRainDrops *mod, int val) { mod->bRadialVelocity = val; }
struct FVector *ParticleModuleHelper::ParticleModuleUberRainDrops_getPC_StartLocation(const UParticleModuleUberRainDrops *mod) { return const_cast<struct FVector *>(&mod->PC_StartLocation); }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setPC_StartLocation(UParticleModuleUberRainDrops *mod, struct FVector val) { mod->PC_StartLocation = val; }
struct FVector *ParticleModuleHelper::ParticleModuleUberRainDrops_getStartLocationMin(const UParticleModuleUberRainDrops *mod) { return const_cast<struct FVector *>(&mod->StartLocationMin); }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setStartLocationMin(UParticleModuleUberRainDrops *mod, struct FVector val) { mod->StartLocationMin = val; }
struct FVector *ParticleModuleHelper::ParticleModuleUberRainDrops_getStartLocationMax(const UParticleModuleUberRainDrops *mod) { return const_cast<struct FVector *>(&mod->StartLocationMax); }
void ParticleModuleHelper::ParticleModuleUberRainDrops_setStartLocationMax(UParticleModuleUberRainDrops *mod, struct FVector val) { mod->StartLocationMax = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainImpacts_getLifetime(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Lifetime); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setLifetime(UParticleModuleUberRainImpacts *mod, struct FRawDistributionFloat val) { mod->Lifetime = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainImpacts_getStartSize(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartSize); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setStartSize(UParticleModuleUberRainImpacts *mod, struct FRawDistributionVector val) { mod->StartSize = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainImpacts_getStartRotation(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartRotation); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setStartRotation(UParticleModuleUberRainImpacts *mod, struct FRawDistributionVector val) { mod->StartRotation = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbInheritParent(const UParticleModuleUberRainImpacts *mod) { return mod->bInheritParent; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbInheritParent(UParticleModuleUberRainImpacts *mod, int val) { mod->bInheritParent = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getMultiplyX(const UParticleModuleUberRainImpacts *mod) { return mod->MultiplyX; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setMultiplyX(UParticleModuleUberRainImpacts *mod, int val) { mod->MultiplyX = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getMultiplyY(const UParticleModuleUberRainImpacts *mod) { return mod->MultiplyY; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setMultiplyY(UParticleModuleUberRainImpacts *mod, int val) { mod->MultiplyY = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getMultiplyZ(const UParticleModuleUberRainImpacts *mod) { return mod->MultiplyZ; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setMultiplyZ(UParticleModuleUberRainImpacts *mod, int val) { mod->MultiplyZ = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbIsUsingCylinder(const UParticleModuleUberRainImpacts *mod) { return mod->bIsUsingCylinder; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbIsUsingCylinder(UParticleModuleUberRainImpacts *mod, int val) { mod->bIsUsingCylinder = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbPositive_X(const UParticleModuleUberRainImpacts *mod) { return mod->bPositive_X; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbPositive_X(UParticleModuleUberRainImpacts *mod, int val) { mod->bPositive_X = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbPositive_Y(const UParticleModuleUberRainImpacts *mod) { return mod->bPositive_Y; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbPositive_Y(UParticleModuleUberRainImpacts *mod, int val) { mod->bPositive_Y = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbPositive_Z(const UParticleModuleUberRainImpacts *mod) { return mod->bPositive_Z; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbPositive_Z(UParticleModuleUberRainImpacts *mod, int val) { mod->bPositive_Z = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbNegative_X(const UParticleModuleUberRainImpacts *mod) { return mod->bNegative_X; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbNegative_X(UParticleModuleUberRainImpacts *mod, int val) { mod->bNegative_X = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbNegative_Y(const UParticleModuleUberRainImpacts *mod) { return mod->bNegative_Y; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbNegative_Y(UParticleModuleUberRainImpacts *mod, int val) { mod->bNegative_Y = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbNegative_Z(const UParticleModuleUberRainImpacts *mod) { return mod->bNegative_Z; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbNegative_Z(UParticleModuleUberRainImpacts *mod, int val) { mod->bNegative_Z = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbSurfaceOnly(const UParticleModuleUberRainImpacts *mod) { return mod->bSurfaceOnly; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbSurfaceOnly(UParticleModuleUberRainImpacts *mod, int val) { mod->bSurfaceOnly = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbVelocity(const UParticleModuleUberRainImpacts *mod) { return mod->bVelocity; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbVelocity(UParticleModuleUberRainImpacts *mod, int val) { mod->bVelocity = val; }
int ParticleModuleHelper::ParticleModuleUberRainImpacts_getbRadialVelocity(const UParticleModuleUberRainImpacts *mod) { return mod->bRadialVelocity; }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setbRadialVelocity(UParticleModuleUberRainImpacts *mod, int val) { mod->bRadialVelocity = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainImpacts_getLifeMultiplier(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionVector *>(&mod->LifeMultiplier); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setLifeMultiplier(UParticleModuleUberRainImpacts *mod, struct FRawDistributionVector val) { mod->LifeMultiplier = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainImpacts_getPC_VelocityScale(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->PC_VelocityScale); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setPC_VelocityScale(UParticleModuleUberRainImpacts *mod, struct FRawDistributionFloat val) { mod->PC_VelocityScale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainImpacts_getPC_StartLocation(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionVector *>(&mod->PC_StartLocation); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setPC_StartLocation(UParticleModuleUberRainImpacts *mod, struct FRawDistributionVector val) { mod->PC_StartLocation = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainImpacts_getPC_StartRadius(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->PC_StartRadius); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setPC_StartRadius(UParticleModuleUberRainImpacts *mod, struct FRawDistributionFloat val) { mod->PC_StartRadius = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainImpacts_getPC_StartHeight(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->PC_StartHeight); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setPC_StartHeight(UParticleModuleUberRainImpacts *mod, struct FRawDistributionFloat val) { mod->PC_StartHeight = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainImpacts_getColorOverLife(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorOverLife); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setColorOverLife(UParticleModuleUberRainImpacts *mod, struct FRawDistributionVector val) { mod->ColorOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainImpacts_getAlphaOverLife(const UParticleModuleUberRainImpacts *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaOverLife); }
void ParticleModuleHelper::ParticleModuleUberRainImpacts_setAlphaOverLife(UParticleModuleUberRainImpacts *mod, struct FRawDistributionFloat val) { mod->AlphaOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainSplashA_getLifetime(const UParticleModuleUberRainSplashA *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Lifetime); }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setLifetime(UParticleModuleUberRainSplashA *mod, struct FRawDistributionFloat val) { mod->Lifetime = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainSplashA_getStartSize(const UParticleModuleUberRainSplashA *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartSize); }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setStartSize(UParticleModuleUberRainSplashA *mod, struct FRawDistributionVector val) { mod->StartSize = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainSplashA_getStartRotation(const UParticleModuleUberRainSplashA *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartRotation); }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setStartRotation(UParticleModuleUberRainSplashA *mod, struct FRawDistributionVector val) { mod->StartRotation = val; }
int ParticleModuleHelper::ParticleModuleUberRainSplashA_getbInheritParent(const UParticleModuleUberRainSplashA *mod) { return mod->bInheritParent; }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setbInheritParent(UParticleModuleUberRainSplashA *mod, int val) { mod->bInheritParent = val; }
int ParticleModuleHelper::ParticleModuleUberRainSplashA_getMultiplyX(const UParticleModuleUberRainSplashA *mod) { return mod->MultiplyX; }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setMultiplyX(UParticleModuleUberRainSplashA *mod, int val) { mod->MultiplyX = val; }
int ParticleModuleHelper::ParticleModuleUberRainSplashA_getMultiplyY(const UParticleModuleUberRainSplashA *mod) { return mod->MultiplyY; }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setMultiplyY(UParticleModuleUberRainSplashA *mod, int val) { mod->MultiplyY = val; }
int ParticleModuleHelper::ParticleModuleUberRainSplashA_getMultiplyZ(const UParticleModuleUberRainSplashA *mod) { return mod->MultiplyZ; }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setMultiplyZ(UParticleModuleUberRainSplashA *mod, int val) { mod->MultiplyZ = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainSplashA_getLifeMultiplier(const UParticleModuleUberRainSplashA *mod) { return const_cast<struct FRawDistributionVector *>(&mod->LifeMultiplier); }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setLifeMultiplier(UParticleModuleUberRainSplashA *mod, struct FRawDistributionVector val) { mod->LifeMultiplier = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainSplashA_getColorOverLife(const UParticleModuleUberRainSplashA *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorOverLife); }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setColorOverLife(UParticleModuleUberRainSplashA *mod, struct FRawDistributionVector val) { mod->ColorOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainSplashA_getAlphaOverLife(const UParticleModuleUberRainSplashA *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaOverLife); }
void ParticleModuleHelper::ParticleModuleUberRainSplashA_setAlphaOverLife(UParticleModuleUberRainSplashA *mod, struct FRawDistributionFloat val) { mod->AlphaOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainSplashB_getLifetime(const UParticleModuleUberRainSplashB *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->Lifetime); }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setLifetime(UParticleModuleUberRainSplashB *mod, struct FRawDistributionFloat val) { mod->Lifetime = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainSplashB_getStartSize(const UParticleModuleUberRainSplashB *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartSize); }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setStartSize(UParticleModuleUberRainSplashB *mod, struct FRawDistributionVector val) { mod->StartSize = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainSplashB_getColorOverLife(const UParticleModuleUberRainSplashB *mod) { return const_cast<struct FRawDistributionVector *>(&mod->ColorOverLife); }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setColorOverLife(UParticleModuleUberRainSplashB *mod, struct FRawDistributionVector val) { mod->ColorOverLife = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainSplashB_getAlphaOverLife(const UParticleModuleUberRainSplashB *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->AlphaOverLife); }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setAlphaOverLife(UParticleModuleUberRainSplashB *mod, struct FRawDistributionFloat val) { mod->AlphaOverLife = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleUberRainSplashB_getLifeMultiplier(const UParticleModuleUberRainSplashB *mod) { return const_cast<struct FRawDistributionVector *>(&mod->LifeMultiplier); }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setLifeMultiplier(UParticleModuleUberRainSplashB *mod, struct FRawDistributionVector val) { mod->LifeMultiplier = val; }
int ParticleModuleHelper::ParticleModuleUberRainSplashB_getMultiplyX(const UParticleModuleUberRainSplashB *mod) { return mod->MultiplyX; }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setMultiplyX(UParticleModuleUberRainSplashB *mod, int val) { mod->MultiplyX = val; }
int ParticleModuleHelper::ParticleModuleUberRainSplashB_getMultiplyY(const UParticleModuleUberRainSplashB *mod) { return mod->MultiplyY; }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setMultiplyY(UParticleModuleUberRainSplashB *mod, int val) { mod->MultiplyY = val; }
int ParticleModuleHelper::ParticleModuleUberRainSplashB_getMultiplyZ(const UParticleModuleUberRainSplashB *mod) { return mod->MultiplyZ; }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setMultiplyZ(UParticleModuleUberRainSplashB *mod, int val) { mod->MultiplyZ = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleUberRainSplashB_getStartRotationRate(const UParticleModuleUberRainSplashB *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartRotationRate); }
void ParticleModuleHelper::ParticleModuleUberRainSplashB_setStartRotationRate(UParticleModuleUberRainSplashB *mod, struct FRawDistributionFloat val) { mod->StartRotationRate = val; }
int ParticleModuleHelper::ParticleModuleVelocityBase_getbInWorldSpace(const UParticleModuleVelocityBase *mod) { return mod->bInWorldSpace; }
void ParticleModuleHelper::ParticleModuleVelocityBase_setbInWorldSpace(UParticleModuleVelocityBase *mod, int val) { mod->bInWorldSpace = val; }
int ParticleModuleHelper::ParticleModuleVelocityBase_getbApplyOwnerScale(const UParticleModuleVelocityBase *mod) { return mod->bApplyOwnerScale; }
void ParticleModuleHelper::ParticleModuleVelocityBase_setbApplyOwnerScale(UParticleModuleVelocityBase *mod, int val) { mod->bApplyOwnerScale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleVelocity_getStartVelocity(const UParticleModuleVelocity *mod) { return const_cast<struct FRawDistributionVector *>(&mod->StartVelocity); }
void ParticleModuleHelper::ParticleModuleVelocity_setStartVelocity(UParticleModuleVelocity *mod, struct FRawDistributionVector val) { mod->StartVelocity = val; }
struct FRawDistributionFloat *ParticleModuleHelper::ParticleModuleVelocity_getStartVelocityRadial(const UParticleModuleVelocity *mod) { return const_cast<struct FRawDistributionFloat *>(&mod->StartVelocityRadial); }
void ParticleModuleHelper::ParticleModuleVelocity_setStartVelocityRadial(UParticleModuleVelocity *mod, struct FRawDistributionFloat val) { mod->StartVelocityRadial = val; }
struct FParticleRandomSeedInfo *ParticleModuleHelper::ParticleModuleVelocity_Seeded_getRandomSeedInfo(const UParticleModuleVelocity_Seeded *mod) { return const_cast<struct FParticleRandomSeedInfo *>(&mod->RandomSeedInfo); }
void ParticleModuleHelper::ParticleModuleVelocity_Seeded_setRandomSeedInfo(UParticleModuleVelocity_Seeded *mod, struct FParticleRandomSeedInfo val) { mod->RandomSeedInfo = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleVelocityInheritParent_getScale(const UParticleModuleVelocityInheritParent *mod) { return const_cast<struct FRawDistributionVector *>(&mod->Scale); }
void ParticleModuleHelper::ParticleModuleVelocityInheritParent_setScale(UParticleModuleVelocityInheritParent *mod, struct FRawDistributionVector val) { mod->Scale = val; }
struct FRawDistributionVector *ParticleModuleHelper::ParticleModuleVelocityOverLifetime_getVelOverLife(const UParticleModuleVelocityOverLifetime *mod) { return const_cast<struct FRawDistributionVector *>(&mod->VelOverLife); }
void ParticleModuleHelper::ParticleModuleVelocityOverLifetime_setVelOverLife(UParticleModuleVelocityOverLifetime *mod, struct FRawDistributionVector val) { mod->VelOverLife = val; }
int ParticleModuleHelper::ParticleModuleVelocityOverLifetime_getAbsolute(const UParticleModuleVelocityOverLifetime *mod) { return mod->Absolute; }
void ParticleModuleHelper::ParticleModuleVelocityOverLifetime_setAbsolute(UParticleModuleVelocityOverLifetime *mod, int val) { mod->Absolute = val; }

TArray<float>* ParticleModuleHelper::RawDistribution_getTable(const FRawDistribution *distrib) { return const_cast<TArray<float> *>(&distrib->LookupTable); }
void ParticleModuleHelper::RawDistribution_setTable(FRawDistribution *distrib, TArray<float> val) { distrib->LookupTable = val; }

TArray<UParticleEmitter *>* ParticleModuleHelper::ParticleSystem_getEmitters(const UParticleSystem *ps) { return const_cast<TArray<UParticleEmitter *> *>(&ps->Emitters); }
void ParticleModuleHelper::ParticleSystem_setEmitters(UParticleSystem *ps, TArray<UParticleEmitter *> val) { ps->Emitters = val; }
TArray<UParticleLODLevel *>* ParticleModuleHelper::ParticleEmitter_getLODLevels(const UParticleEmitter *ps) { return const_cast<TArray<UParticleLODLevel *> *>(&ps->LODLevels); }
void ParticleModuleHelper::ParticleEmitter_setLODLevels(UParticleEmitter *ps, TArray<UParticleLODLevel *> val) { ps->LODLevels = val; }
TArray<UParticleModule *>* ParticleModuleHelper::ParticleLODLevel_getSpawnModules(const UParticleLODLevel *ps) { return const_cast<TArray<UParticleModule *> *>(&ps->SpawnModules); }
void ParticleModuleHelper::ParticleLODLevel_setSpawnModules(UParticleLODLevel *ps, TArray<UParticleModule *> val) { ps->SpawnModules = val; }
TArray<UParticleModule *>* ParticleModuleHelper::ParticleLODLevel_getUpdateModules(const UParticleLODLevel *ps) { return const_cast<TArray<UParticleModule *> *>(&ps->UpdateModules); }
void ParticleModuleHelper::ParticleLODLevel_setUpdateModules(UParticleLODLevel *ps, TArray<UParticleModule *> val) { ps->UpdateModules = val; }
