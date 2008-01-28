#pragma once

#include "NxaShapeDescription.h"
#include "NxConvexShapeDesc.h"

public ref class NxaConvexShapeDescription : public NxaShapeDescription
{
internal:
	NxaConvexShapeDescription(NxConvexShapeDesc* ptr);

public:
	NxaConvexShapeDescription();
};
