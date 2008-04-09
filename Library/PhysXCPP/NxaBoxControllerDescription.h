#pragma once

#include "NxBoxController.h"
#include "NxaControllerDescription.h"

public ref class NxaBoxControllerDescription : public NxaControllerDescription
{
public:
	NxaBoxControllerDescription();

	property Vector3 Extents
	{
		Vector3 get();
		void set(Vector3 value);
	}
};
