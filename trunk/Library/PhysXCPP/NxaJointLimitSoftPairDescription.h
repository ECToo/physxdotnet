#pragma once

#include "NxaJointLimitSoftDescription.h"

class NxJointLimitSoftPairDesc;

public ref class NxaJointLimitSoftPairDescription
{
internal:
	void LoadFromNative(NxJointLimitSoftPairDesc& desc);
	NxJointLimitSoftPairDesc ConvertToNative();

public:
	NxaJointLimitSoftPairDescription();

	void SetToDefault();
	bool IsValid();

	NxaJointLimitSoftDescription Low;
	NxaJointLimitSoftDescription High;
};
