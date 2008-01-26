#pragma once

#include "NxaSegment.h"

#include "NxCapsule.h"

public ref class NxaCapsule : NxaSegment
{
internal:
	NxCapsule* nxCapsule;

public:
	NxaCapsule(void);
	NxaCapsule(NxaSegment^ seg, float radius);
	~NxaCapsule(void);
	!NxaCapsule(void);

	property float Radius
	{	
		float get();
		void set(float value);
	}
};