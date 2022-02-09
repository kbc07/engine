#include "k2EngineLowPreCompile.h"
#include "DirectionLight.h"

namespace nsK2EngineLow
{
	DirectionLight::DirectionLight()
	{
		directionLight.lightDirection.x = 1.0f;
		directionLight.lightDirection.y = -1.0f;
		directionLight.lightDirection.z = -1.0f;
		directionLight.lightDirection.Normalize();

		directionLight.lightColor.x = 0.5f;
		directionLight.lightColor.y = 0.5f;
		directionLight.lightColor.z = 0.5f;
	}
}