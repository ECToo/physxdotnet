#pragma once

#include "NxaShapeDescription.h"
#include "NxSphereShapeDesc.h"

public ref class NxaSphereShapeDescription  : public NxaShapeDescription
{
internal:
	NxaSphereShapeDescription(NxSphereShapeDesc* ptr);

public:
	NxaSphereShapeDescription(void);

	property float Radius
	{
		float get() { return ((NxSphereShapeDesc*)nxShapeDesc)->radius; }
		void set(float radius);
	}
};