#pragma once

#include "Nxap.h"

class NxJointDriveDesc;

public ref class NxaJointDriveDescription
{
internal:
	void LoadFromNative(NxJointDriveDesc& desc);
	NxJointDriveDesc ConvertToNative();

public:
	NxaJointDriveDescription();

	void SetToDefault();

	NxaD6JointDriveType DriveType;
	float Spring;
	float Damping;
	float ForceLimit;
};
