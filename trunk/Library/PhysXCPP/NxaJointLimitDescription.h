#pragma once

#include "NxJointLimitDesc.h"

public ref class NxaJointLimitDescription
{
internal:
	NxJointLimitDesc* jointLimitDesc;

public:
	NxaJointLimitDescription(void);
	!NxaJointLimitDescription(void);

	property float Value
	{
		float get();
		void set(float value);
	}

	property float Restitution
	{
		float get();
		void set(float value);
	}
};