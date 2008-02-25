#include "StdAfx.h"
#include "NxaJointDriveDescription.h"
#include "NxMotorDesc.h"

void NxaJointDriveDescription::LoadFromNative(NxJointDriveDesc& desc)
{
	DriveType = (NxaD6JointDriveType)(NxU32)desc.driveType;
	Spring = desc.spring;
	ForceLimit = desc.forceLimit;
	Damping = desc.damping;
}

NxJointDriveDesc NxaJointDriveDescription::ConvertToNative()
{
	NxJointDriveDesc desc;
	desc.spring = Spring;
	desc.damping = Damping;
	desc.forceLimit = ForceLimit;
	desc.driveType = (NxU32)DriveType;
	return desc;
}

NxaJointDriveDescription::NxaJointDriveDescription()
{
	Spring = 0;
	Damping = 0;
	ForceLimit = float::MaxValue;
	DriveType = (NxaD6JointDriveType)0;
}
