#include "StdAfx.h"
#include "NxaMotorDescription.h"
#include "NxMotorDesc.h"

void NxaMotorDescription::LoadFromNative(NxMotorDesc& desc)
{
	VelocityTarget = desc.velTarget;
	MaxForce = desc.maxForce;
	FreeSpin = (desc.freeSpin == NX_TRUE);
}

NxMotorDesc NxaMotorDescription::ConvertToNative()
{
	NxMotorDesc desc(VelocityTarget, MaxForce, FreeSpin);
	return desc;
}

NxaMotorDescription::NxaMotorDescription()
{
	SetToDefault();
}

NxaMotorDescription::NxaMotorDescription(float velocityTarget, float maxForce, bool freeSpin)
{
	VelocityTarget = velocityTarget;
	MaxForce = maxForce;
	FreeSpin = freeSpin;
}

NxaMotorDescription::NxaMotorDescription(float velocityTarget, float maxForce)
{
	VelocityTarget = velocityTarget;
	MaxForce = maxForce;
}

NxaMotorDescription::NxaMotorDescription(float velocityTarget)
{
	VelocityTarget = velocityTarget;
}

void NxaMotorDescription::SetToDefault()
{
	VelocityTarget = float::MaxValue;
	MaxForce = 0;
	FreeSpin = 0;
}

bool NxaMotorDescription::IsValid()
{
	return MaxForce >= 0;
}