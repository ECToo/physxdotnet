#include "StdAfx.h"
#include "NxaJointLimitSoftDescription.h"

#include "Nxp.h"
#include "NxJointLimitSoftDesc.h"

NxaJointLimitSoftDescription::NxaJointLimitSoftDescription()
{
	nxDesc = new NxJointLimitSoftDesc();
}

NxaJointLimitSoftDescription::NxaJointLimitSoftDescription(NxJointLimitSoftDesc* ptr)
{
	nxDesc = ptr;
}

NxaJointLimitSoftDescription::~NxaJointLimitSoftDescription()
{
	this->!NxaJointLimitSoftDescription();
}

NxaJointLimitSoftDescription::!NxaJointLimitSoftDescription()
{
	delete nxDesc;
}

void NxaJointLimitSoftDescription::SetToDefault()
{
	nxDesc->setToDefault();
}

bool NxaJointLimitSoftDescription::IsValid()
{
	return nxDesc->isValid();
}

float NxaJointLimitSoftDescription::Value::get()
{
	return nxDesc->value;
}

void NxaJointLimitSoftDescription::Value::set(float value)
{
	nxDesc->value = value;
}

float NxaJointLimitSoftDescription::Restitution::get()
{
	return nxDesc->restitution;
}

void NxaJointLimitSoftDescription::Restitution::set(float value)
{
	nxDesc->restitution = value;
}

float NxaJointLimitSoftDescription::Spring::get()
{
	return nxDesc->spring;
}

void NxaJointLimitSoftDescription::Spring::set(float value)
{
	nxDesc->spring = value;
}

float NxaJointLimitSoftDescription::Damping::get()
{
	return nxDesc->damping;
}

void NxaJointLimitSoftDescription::Damping::set(float value)
{
	nxDesc->damping = value;
}