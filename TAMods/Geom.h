#pragma once

#include <cmath>
#include "SdkHeaders.h"

namespace Geom
{
	FVector scale(FVector vec1, float s);
	FRotator sub(FRotator rot1, FRotator rot2);
	FVector sub(FVector vec1, FVector vec2);
	FVector add(FVector vec1, FVector vec2);
	float dot(FVector vec1, FVector vec2);
	float scalar(FVector vec1, FVector vec2);
	float distance3D(FVector vec1, FVector vec2);
	float vSize(FVector &v);
	float vSize2D(FVector &v);
	void normalize(FVector &v);
	FVector normal(FVector v);
	FVector rotationToVector(FRotator R);
	void inline getAxes(FRotator R, FVector &X, FVector &Y, FVector &Z);
};
