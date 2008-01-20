#pragma once

#include "NxaShapeDescription.h"
#include "NxBoxShapeDesc.h"

public ref class NxaBoxShapeDescription : public NxaShapeDescription
{
internal:
	NxaBoxShapeDescription(NxBoxShapeDesc* ptr);

public:
	property Vector3 Dimensions 
	{
		Vector3 get();
		void set(Vector3 value);
	}

public:
	NxaBoxShapeDescription(void);
	~NxaBoxShapeDescription(void);
	!NxaBoxShapeDescription(void);
};