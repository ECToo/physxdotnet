#pragma once

#include "NxaJointLimitDescription.h"

class NxJointLimitPairDesc;

public value class NxaJointLimitPairDescription
{
internal:
	NxJointLimitPairDesc ConvertToNative();

public:
	NxaJointLimitDescription Low;
	NxaJointLimitDescription High;

	static property NxaJointLimitPairDescription Default
	{
		NxaJointLimitPairDescription get();
	}

	void SetToDefault();
	bool IsValid();
};
