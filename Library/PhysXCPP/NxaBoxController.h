#pragma once
#include "NxaController.h"
#include "NxBoxController.h"

public ref class NxaBoxController : public NxaController
{
internal:
	NxaBoxController(NxController* ptr);

public:
	Vector3 GetExtents();
	void SetExtents(Vector3 extents);
};
