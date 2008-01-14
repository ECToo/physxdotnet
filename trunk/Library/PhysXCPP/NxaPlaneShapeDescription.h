#pragma once

#include "NxaShapeDescription.h"

namespace PhysXCPP
{

	public ref class NxaPlaneShapeDescription : public NxaShapeDescription
	{
	internal:
		NxaPlaneShapeDescription(NxPlaneShapeDesc* ptr);

	public:
		NxaPlaneShapeDescription(void);
		!NxaPlaneShapeDescription(void);
	};

}