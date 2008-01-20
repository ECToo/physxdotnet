#pragma once

//#include "NxActorDesc.h"
class NxActorDesc;

#include "NxaBodyDescription.h"
#include "NxaShapeDescription.h"

public ref class NxaActorDescription
{

internal:
	NxActorDesc* nxActorDesc;

public:
	NxaActorDescription(void);
	~NxaActorDescription(void);
	!NxaActorDescription(void);

	void AddShape(NxaShapeDescription^ description);

	property NxaBodyDescription^ Body
	{
		void set(NxaBodyDescription^ value);
	}

	property float Density
	{
		//float get() { return nxActorDesc->density; }
		float get() { return 1; }
		void set(float value);
	}
	
	property Matrix GlobalPose
	{
		void set(Matrix value);
	}

	property array<NxaShapeDescription^>^ Shapes
	{
		array<NxaShapeDescription^>^ get();
	}
};