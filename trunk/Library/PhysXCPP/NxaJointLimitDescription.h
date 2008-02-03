#pragma once

//#include "NxJointLimitDesc.h"
class NxJointLimitDesc;

public ref class NxaJointLimitDescription
{
internal:
	NxJointLimitDesc* nxJointLimitDesc;

public:
	NxaJointLimitDescription();
	~NxaJointLimitDescription();
	!NxaJointLimitDescription();

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

	property float Hardness
	{
		float get();
		void set(float value);
	}
};