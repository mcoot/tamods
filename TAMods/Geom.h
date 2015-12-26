#pragma once

#include <cmath>
#include "SdkHeaders.h"

namespace Geom
{
	FVector scale(const FVector &vec1, float s);
	FRotator sub(const FRotator &rot1, const FRotator &rot2);
	FVector sub(const FVector &vec1, const FVector &vec2);
	FVector sub(const FVector &vec1, float val);
	FVector add(const FVector &vec1, const FVector &vec2);
	FVector add(const FVector &vec1, float val);
	FVector mult(const FVector &vec1, float val);
	float dot(const FVector &vec1, const FVector &vec2);
	float scalar(const FVector &vec1, const FVector &vec2);
	float distance3D(const FVector &vec1, const FVector &vec2);
	float vSize(const FVector &v);
	float vSize2D(const FVector &v);
	void normalize(FVector &v);
	FVector normal(const FVector &v);
	FVector rotationToVector(const FRotator &R);
	FRotator vectorToRotation(const FVector &Vec);
	void inline getAxes(FRotator R, FVector &X, FVector &Y, FVector &Z);
};
