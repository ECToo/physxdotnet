#include "StdAfx.h"
#include "NxaJointLimitDescription.h"

using namespace PhysXCPP;

NxaJointLimitDescription::NxaJointLimitDescription(void)
{
	jointLimitDesc = new NxJointLimitDesc();
}

NxaJointLimitDescription::~NxaJointLimitDescription(void)
{

}

NxaJointLimitDescription::!NxaJointLimitDescription(void)
{

}

float NxaJointLimitDescription::Value::get()
{
	return jointLimitDesc->value;
}

void NxaJointLimitDescription::Value::set(float value)
{
	jointLimitDesc->value = value;
}

float NxaJointLimitDescription::Restitution::get()
{
	return jointLimitDesc->restitution;
}

void NxaJointLimitDescription::Restitution::set(float value)
{
	jointLimitDesc->restitution = value;
}
