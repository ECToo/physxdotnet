#pragma once

#include "NxaJointDescription.h"

public ref class NxaSphericalJointDescription : public NxaJointDescription
{
public:
	NxaSphericalJointDescription(void);

	virtual void SetToDefault();
	virtual bool IsValid();

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

	property NxaU32 Flags
	{
		NxaU32 get();
		void set(NxaU32 flags);
	}
};