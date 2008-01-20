#pragma once

#include "NxaJointDescription.h"

public ref class NxaSphericalJointDescription : public NxaJointDescription
{
public:
	NxaSphericalJointDescription(void);

	property Vector3 SwingAxis
	{
		Vector3 get();
		void set(Vector3 axis);
	}

	property float ProjectionDistance
	{
		float get();
		void set(float dist);
	}
};