#pragma once

#include "NxaShapeDescription.h"

namespace PhysXCPP
{

	public ref class NxaCapsuleShapeDescription : public NxaShapeDescription
	{
	public:
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


	public:
		NxaCapsuleShapeDescription(void);
		~NxaCapsuleShapeDescription(void);
		!NxaCapsuleShapeDescription(void);
	};

}
