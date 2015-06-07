#include "Geom.h"

#define UCONST_Pi			3.1415926f
#define URotation180		32768.0f
#define URotationToRadians	UCONST_Pi / URotation180

FVector Geom::scale(FVector vec1, float s) {
	FVector result;
	result.X = vec1.X * s;
	result.Y = vec1.Y * s;
	result.Z = vec1.Z * s;
	return result;
}

FRotator Geom::sub(FRotator rot1, FRotator rot2) {
	FRotator result;
	result.Pitch = rot1.Pitch - rot2.Pitch;
	result.Yaw = rot1.Yaw - rot2.Yaw;
	result.Roll = rot1.Roll - rot2.Roll;
	return result;
}

FVector Geom::sub(FVector vec1, FVector vec2) {
	FVector result;
	result.X = vec1.X - vec2.X;
	result.Y = vec1.Y - vec2.Y;
	result.Z = vec1.Z - vec2.Z;
	return result;
}

FVector Geom::add(FVector vec1, FVector vec2) {
	FVector result;
	result.X = vec1.X + vec2.X;
	result.Y = vec1.Y + vec2.Y;
	result.Z = vec1.Z + vec2.Z;
	return result;
}

float Geom::dot(FVector vec1, FVector vec2) {
	return (vec1.X * vec2.X) + (vec1.Y * vec2.Y) + (vec1.Z * vec2.Z);
}

float Geom::scalar(FVector vec1, FVector vec2) {
	return (vec1.X * vec2.X) + (vec1.Y * vec2.Y) + (vec1.Z * vec2.Z);
}

float Geom::distance3D(FVector vec1, FVector vec2){
	float distance = sqrt(((vec1.X - vec2.X)*(vec1.X - vec2.X) + (vec1.Y - vec2.Y)*(vec1.Y - vec2.Y) + (vec1.Z - vec2.Z)*(vec1.Z - vec2.Z)));
	return distance;
}

float Geom::vSize(FVector &v)
{
	return sqrt(v.X*v.X + v.Y*v.Y + v.Z*v.Z);
}

float Geom::vSize2D(FVector &v)
{
	return sqrt(v.X*v.X + v.Y*v.Y);
}

void Geom::normalize(FVector &v)
{
	float size = vSize(v);

	if (!size)
	{
		v.X = v.Y = v.Z = 0;
	}
	else
	{
		v.X /= size;
		v.Y /= size;
		v.Z /= size;
	}
}

FVector Geom::normal(FVector v)
{
	FVector Ret;
	Ret.X = v.X;
	Ret.Y = v.Y;
	Ret.Z = v.Z;
	normalize(Ret);
	return Ret;
}

FVector Geom::rotationToVector(FRotator R)
{
	FVector Vec;
	float fYaw = R.Yaw * URotationToRadians;
	float fPitch = R.Pitch * URotationToRadians;
	float CosPitch = cos(fPitch);
	Vec.X = cos(fYaw) * CosPitch;
	Vec.Y = sin(fYaw) * CosPitch;
	Vec.Z = sin(fPitch);

	return Vec;
}

void inline Geom::getAxes(FRotator R, FVector &X, FVector &Y, FVector &Z)
{
	X = rotationToVector(R);
	normalize(X);
	R.Yaw += 16384;
	FRotator R2 = R;
	R2.Pitch = 0;
	Y = rotationToVector(R2);
	normalize(Y);
	Y.Z = 0.f;
	R.Yaw -= 16384;
	R.Pitch += 16384;
	Z = rotationToVector(R);
	normalize(Z);
}
