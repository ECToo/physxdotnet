#pragma once

#include "NxaJointLimitDescription.h"

class NxJointLimitPairDesc;

public ref class NxaJointLimitPairDescription
{
internal:
	NxJointLimitPairDesc* nxJointLimitPairDesc;

public:
	NxaJointLimitPairDescription();
	~NxaJointLimitPairDescription();
	!NxaJointLimitPairDescription();

	property NxaJointLimitDescription^ Low
	{
		NxaJointLimitDescription^ get();
		void set(NxaJointLimitDescription^ value);
	}

	property NxaJointLimitDescription^ High
	{
		NxaJointLimitDescription^ get();
		void set(NxaJointLimitDescription^ value);
	}

	void SetToDefault();
	bool IsValid();
};
