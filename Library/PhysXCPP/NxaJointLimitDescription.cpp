#include "StdAfx.h"

#include "Nxp.h" //Included because NxJointLimitDesc.h doesn't appear to do it itself.
#include "NxJointLimitDesc.h"

#include "NxaJointLimitDescription.h"

NxaJointLimitDescription::NxaJointLimitDescription(NxJointLimitDesc* ptr)
{
	nxJointLimitDesc = ptr;
}

NxaJointLimitDescription::NxaJointLimitDescription(void)
{
	nxJointLimitDesc = new NxJointLimitDesc();
}

NxaJointLimitDescription::~NxaJointLimitDescription(void)
{
	this->!NxaJointLimitDescription();
}

NxaJointLimitDescription::!NxaJointLimitDescription(void)
{
	delete nxJointLimitDesc;
}

float NxaJointLimitDescription::Value::get()
{
	return nxJointLimitDesc->value;
}

void NxaJointLimitDescription::Value::set(float value)
{
	nxJointLimitDesc->value = value;
}

float NxaJointLimitDescription::Restitution::get()
{
	return nxJointLimitDesc->restitution;
}

void NxaJointLimitDescription::Restitution::set(float value)
{
	nxJointLimitDesc->restitution = value;
}

float NxaJointLimitDescription::Hardness::get()
{
	return nxJointLimitDesc->hardness;
}

void NxaJointLimitDescription::Hardness::set(float value)
{
	nxJointLimitDesc->hardness = value;
}
