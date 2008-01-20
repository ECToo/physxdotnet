#pragma once

#include "Stdafx.h"
#include "NxSphere.h"

public ref class NxaSphere
{

internal:
	NxSphere* nxSphere;

public:
	NxaSphere();
	NxaSphere(Vector3 position, float radius);
	NxaSphere(NxaSphere^ sphere);
	!NxaSphere(void);

	bool IsValid();

	bool Contains(Vector3 point);
	bool Contains(Vector3% point);

	bool Contains(NxaSphere^ sphere);
	bool Contains(Vector3 min, Vector3 max);
	bool Contains(Vector3% min, Vector3% max);
	bool Intersect(NxaSphere^ sphere);

	property Vector3 Center;
	property float Radius;

};