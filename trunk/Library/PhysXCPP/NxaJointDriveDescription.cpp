#include "StdAfx.h"
#include "NxaJointDriveDescription.h"

#include "Nxp.h"
#include "NxMotorDesc.h"

NxaJointDriveDescription::NxaJointDriveDescription(void)
{
	nxDesc = new NxJointDriveDesc();
}

NxaJointDriveDescription::NxaJointDriveDescription(NxJointDriveDesc* ptr)
{
	nxDesc = ptr;
}

NxaJointDriveDescription::~NxaJointDriveDescription(void)
{
	this->!NxaJointDriveDescription();
}

NxaJointDriveDescription::!NxaJointDriveDescription(void)
{
	delete nxDesc;
}

NxaD6JointDriveType NxaJointDriveDescription::DriveType::get()
{
	return (NxaD6JointDriveType)nxDesc->driveType.bitField;
}

void NxaJointDriveDescription::DriveType::set(NxaD6JointDriveType value)
{
	nxDesc->driveType.bitField = (NxaU32)value;
}

float NxaJointDriveDescription::Spring::get()
{
	return nxDesc->spring;
}

void NxaJointDriveDescription::Spring::set(float value)
{
	nxDesc->spring = value;
}

float NxaJointDriveDescription::Damping::get()
{
	return nxDesc->damping;
}

void NxaJointDriveDescription::Damping::set(float value)
{
	nxDesc->damping = value;
}

float NxaJointDriveDescription::ForceLimit::get()
{
	return nxDesc->forceLimit;
}

void NxaJointDriveDescription::ForceLimit::set(float value)
{
	nxDesc->forceLimit = value;
}