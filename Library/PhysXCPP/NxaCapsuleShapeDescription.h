#pragma once

#include "NxaShapeDescription.h"

#include "NxCapsuleShapeDesc.h"

public ref class NxaCapsuleShapeDescription : public NxaShapeDescription
{
internal:
	NxaCapsuleShapeDescription(NxCapsuleShapeDesc* ptr);

public:
	NxaCapsuleShapeDescription(void);

	property float Radius
	{
		float get() { return ((NxCapsuleShapeDesc*)nxShapeDesc)->radius; }
		void set(float value);
	}

	property float Height
	{
		float get() { return ((NxCapsuleShapeDesc*)nxShapeDesc)->height; }
		void set(float value);
	}
	
};