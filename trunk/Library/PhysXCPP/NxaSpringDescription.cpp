#include "StdAfx.h"
#include "NxaSpringDescription.h"

#include "NxSpringDesc.h"

void NxaSpringDescription::LoadFromNative(NxSpringDesc& desc)
{
	Spring = desc.spring;
	Damper = desc.damper;
	TargetValue = desc.targetValue;
}

NxSpringDesc NxaSpringDescription::ConvertToNative()
{
	NxSpringDesc desc(Spring, Damper, TargetValue);
	return desc;
}

NxaSpringDescription::NxaSpringDescription(float spring, float damper, float targetValue)
{
	Spring = spring;
	Damper = damper;
	TargetValue = targetValue;
}

NxaSpringDescription::NxaSpringDescription(float spring, float damper)
{
	Spring = spring;
	Damper = damper;
}

NxaSpringDescription::NxaSpringDescription(float spring)
{
	Spring = spring;
}

NxaSpringDescription::NxaSpringDescription(void)
{
	SetToDefault();
}

void NxaSpringDescription::SetToDefault()
{
	Spring = 0;
	Damper = 0;
	TargetValue = 0;
}

bool NxaSpringDescription::IsValid()
{
	return (Spring >= 0 && Damper >= 0);
}