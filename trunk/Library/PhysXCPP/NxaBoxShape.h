#pragma once
#include "nxashape.h"
#include "Nxabox.h"
#include "NxaBoxShapeDescription.h"

#include "NxShape.h"

public ref class NxaBoxShape : public NxaShape
{
internal:
	NxaBoxShape(NxShape* ptr);

public:
	void SetDimensions(Vector3 vec);
	void SetDimensions(Vector3% vec);

	Vector3 GetDimensions();

	void GetWorldOrientedBoundingBox([Out] NxaBox^% obb);
	void SaveToDesc([Out] NxaBoxShapeDescription^% desc);
};