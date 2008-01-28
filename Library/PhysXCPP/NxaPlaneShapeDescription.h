#pragma once

#include "NxaShapeDescription.h"
#include "NxPlaneShapeDesc.h"

public ref class NxaPlaneShapeDescription : public NxaShapeDescription
{
internal:
	NxaPlaneShapeDescription(NxPlaneShapeDesc* ptr);

public:
	NxaPlaneShapeDescription();
};