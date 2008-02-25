#include "StdAfx.h"
#include "NxaJointLimitDescription.h"
#include "Nxp.h"
#include "NxJointLimitDesc.h"

NxJointLimitDesc NxaJointLimitDescription::ConvertToNative()
{
	NxJointLimitDesc desc;
	desc.value = Value;
	desc.restitution = Restitution;
	desc.hardness = Hardness;
	return desc;
}

void NxaJointLimitDescription::SetToDefault()
{
	Value = 0;
	Restitution = 0;
	Hardness = 1;
}

NxaJointLimitDescription NxaJointLimitDescription::Default::get()
{
	NxaJointLimitDescription desc;
	desc.SetToDefault();
	return desc;
}

bool NxaJointLimitDescription::IsValid()
{
	if(Restitution < 0  || Restitution > 1 || Hardness < 0 || Hardness > 1) 
		return false; 
	return true;
}