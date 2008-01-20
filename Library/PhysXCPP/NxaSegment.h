#pragma once

#include "Stdafx.h"
#include "NxSegment.h"
#include "NxaMath.h"

public ref class NxaSegment
{
internal:
	NxSegment* nxSegment;
	
public:
	NxaSegment(void);
	NxaSegment(Vector3 p0, Vector3 p1);
	NxaSegment(NxaSegment^ seg);
	~NxaSegment();
	!NxaSegment(void);

	Vector3 GetOrigin();
	Vector3 ComputeDirection();
	float ComputeLength();
	float ComputeSquareLength();
	void SetOriginDirection(Vector3 origin, Vector3 direction);
	void ComputePoint(Vector3 pt, float t);

	property Vector3 p0
	{
		Vector3 get() { return NxaMath::Vector3PhysXToXNA(nxSegment->p0); }
		void set(Vector3 value) { nxSegment->p0 = NxaMath::Vector3XNAToPhysX(value); }
	}

	property Vector3 p1
	{
		Vector3 get() { return NxaMath::Vector3PhysXToXNA(nxSegment->p1); }
		void set(Vector3 value) { nxSegment->p1 = NxaMath::Vector3XNAToPhysX(value); }
	}

};