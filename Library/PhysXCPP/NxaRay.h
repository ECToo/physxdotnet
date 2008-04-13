#pragma once

#include "NxRay.h"

public ref class NxaRay
{
internal:
	NxRay * nxRay;

public:
	NxaRay(void);
	NxaRay(Vector3 orig, Vector3 dir);
	~NxaRay(void);
	!NxaRay(void);

	property Vector3 Origin
	{	
		Vector3 get() { return NxaMath::Vector3PhysXToXNA(nxRay->orig); }
		void set(Vector3 value) { nxRay->orig = NxaMath::Vector3XNAToPhysX(value); }
	}

	property Vector3 Direction
	{	
		Vector3 get() { return NxaMath::Vector3PhysXToXNA(nxRay->dir); }
		void set(Vector3 value) { nxRay->dir = NxaMath::Vector3XNAToPhysX(value); }
	}
};