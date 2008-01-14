#pragma once

#include "NxaShapeDescription.h"

using namespace Microsoft::Xna::Framework;

namespace PhysXCPP
{

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
		!NxaBoxShapeDescription(void);
	};

}