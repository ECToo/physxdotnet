#include "StdAfx.h"
#include "NxaJointLimitSoftDescription.h"
#include "NxJointLimitSoftDesc.h"

void NxaJointLimitSoftDescription::LoadFromNative(NxJointLimitSoftDesc& desc)
{
	Value = desc.value;
	Restitution = desc.restitution;
	Spring = desc.spring;
	Damping = desc.damping;
}

NxJointLimitSoftDesc NxaJointLimitSoftDescription::ConvertToNative()
{
	NxJointLimitSoftDesc desc;
	desc.value = Value;
	desc.restitution = Restitution;
	desc.spring = Spring;
	desc.damping = Damping;
	return desc;
}

NxaJointLimitSoftDescription::NxaJointLimitSoftDescription()
{
	SetToDefault();
}

void NxaJointLimitSoftDescription::SetToDefault()
{
	Value = 0;
	Restitution = 0;
	Spring = 0;
	Damping = 0;
}

bool NxaJointLimitSoftDescription::IsValid()
{
	return (Restitution >= 0 && Restitution <= 1);
}