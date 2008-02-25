#include "StdAfx.h"
#include "NxaJointLimitPairDescription.h"

#include "NxJointLimitPairDesc.h"

NxJointLimitPairDesc NxaJointLimitPairDescription::ConvertToNative()
{
	NxJointLimitPairDesc desc;
	desc.low = Low.ConvertToNative();
	desc.high = High.ConvertToNative();
	return desc;
}

NxaJointLimitPairDescription NxaJointLimitPairDescription::Default::get()
{
	NxaJointLimitPairDescription desc;
	desc.SetToDefault();
	return desc;
}

void NxaJointLimitPairDescription::SetToDefault()
{
	Low = NxaJointLimitDescription();
	High = NxaJointLimitDescription();
	Low.SetToDefault();
	High.SetToDefault();
}

bool NxaJointLimitPairDescription::IsValid()
{
	return (Low.IsValid() && High.IsValid() && Low.Value <= High.Value);
}