#include "StdAfx.h"

#include "Nxp.h"
#include "NxMotorDesc.h"

#include "NxaMotorDescription.h"

NxaMotorDescription::NxaMotorDescription(NxMotorDesc *ptr)
{
	nxMotorDesc = ptr;
}

NxaMotorDescription::NxaMotorDescription()
{
	nxMotorDesc = new NxMotorDesc();
}

NxaMotorDescription::NxaMotorDescription(float targetVelocity, float maxForce, bool freeSpin)
{
	nxMotorDesc = new NxMotorDesc(targetVelocity, maxForce, freeSpin);
}

NxaMotorDescription::NxaMotorDescription(float targetVelocity, float maxForce)
{
	nxMotorDesc = new NxMotorDesc(targetVelocity, maxForce);
}

NxaMotorDescription::NxaMotorDescription(float targetVelocity)
{
	nxMotorDesc = new NxMotorDesc(targetVelocity);
}

NxaMotorDescription::~NxaMotorDescription()
{
	this->!NxaMotorDescription();
}

NxaMotorDescription::!NxaMotorDescription()
{
	delete nxMotorDesc;
}

float NxaMotorDescription::TargetVelocity::get()
{
	return nxMotorDesc->velTarget;
}

void NxaMotorDescription::TargetVelocity::set(float value)
{
	nxMotorDesc->velTarget = value;
}

float NxaMotorDescription::MaxForce::get()
{
	return nxMotorDesc->maxForce;
}

void NxaMotorDescription::MaxForce::set(float value)
{
	nxMotorDesc->maxForce = value;
}

bool NxaMotorDescription::FreeSpin::get()
{
	return nxMotorDesc->freeSpin;
}

void NxaMotorDescription::FreeSpin::set(bool value)
{
	nxMotorDesc->freeSpin = value;
}

void NxaMotorDescription::SetToDefault()
{
	nxMotorDesc->setToDefault();
}

bool NxaMotorDescription::IsValid()
{
	return nxMotorDesc->isValid();
}