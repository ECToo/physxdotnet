#include "StdAfx.h"
#include "NxaJointLimitSoftPairDescription.h"
#include "NxaJointLimitSoftDescription.h"
#include "NxJointLimitSoftPairDesc.h"

void NxaJointLimitSoftPairDescription::LoadFromNative(NxJointLimitSoftPairDesc& desc)
{
	Low.LoadFromNative(desc.low);
	High.LoadFromNative(desc.high);
}

NxJointLimitSoftPairDesc NxaJointLimitSoftPairDescription::ConvertToNative()
{
	NxJointLimitSoftPairDesc desc;
	desc.low = Low.ConvertToNative();
	desc.high = High.ConvertToNative();
	return desc;
}

//NxaJointLimitSoftPairDescription::NxaJointLimitSoftPairDescription()
//{
//	SetToDefault();
//}

void NxaJointLimitSoftPairDescription::SetToDefault()
{
	//nothing
}

bool NxaJointLimitSoftPairDescription::IsValid()
{
	return (Low.IsValid() && High.IsValid() && Low.Value <= High.Value);
}