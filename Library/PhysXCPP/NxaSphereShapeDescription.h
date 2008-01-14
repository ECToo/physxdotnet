#pragma once

#include "NxaShapeDescription.h"
#include "NxPhysics.h"

using namespace Microsoft::Xna::Framework;

namespace PhysXCPP
{

	public ref class NxaSphereShapeDescription  : public NxaShapeDescription
	{
	internal:
		NxaSphereShapeDescription(NxSphereShapeDesc* ptr);

	public:
		property float Radius
		{
			float get() { return ((NxSphereShapeDesc*)nxShapeDesc)->radius; }
			void set(float radius);
		}
	
		NxaSphereShapeDescription(void);
		!NxaSphereShapeDescription(void);
	};
}