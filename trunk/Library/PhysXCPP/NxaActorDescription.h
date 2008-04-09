#pragma once

//#include "NxActorDesc.h"
class NxActorDesc;

#include "NxaBodyDescription.h"
#include "NxaShapeDescription.h"

public ref class NxaActorDescription
{
internal:
	NxActorDesc* nxActorDesc;

private:
	List<NxaShapeDescription ^> ^ arShapeDescriptions;
	NxaBodyDescription ^ nxaBodyDescription;

public:
	NxaActorDescription(void);
	~NxaActorDescription(void);
	!NxaActorDescription(void);

	virtual void SetToDefault();
	virtual bool IsValid();

	void AddShape(NxaShapeDescription^ description);

	property NxaBodyDescription^ Body
	{
		NxaBodyDescription ^ get();
		void set(NxaBodyDescription^ value);
	}

	property float Density
	{
		float get();
		void set(float value);
	}
	
	property Matrix GlobalPose
	{
		void set(Matrix value);
	}

	property NxaActorGroup Group
	{
		NxaActorGroup get();
		void set(NxaActorGroup value);
	}

	property array<NxaShapeDescription^>^ Shapes
	{
		array<NxaShapeDescription^>^ get();
	}
};