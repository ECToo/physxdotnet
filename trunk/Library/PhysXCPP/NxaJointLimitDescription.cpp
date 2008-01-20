#include "StdAfx.h"

#include "NxaJointLimitDescription.h"



NxaJointLimitDescription::NxaJointLimitDescription(void)
{
	//jointLimitDesc = new NxJointLimitDesc();
}

NxaJointLimitDescription::!NxaJointLimitDescription(void)
{

}

float NxaJointLimitDescription::Value::get()
{
	return 1;
	//return jointLimitDesc->value;
}

void NxaJointLimitDescription::Value::set(float value)
{

	//jointLimitDesc->value = value;
}

float NxaJointLimitDescription::Restitution::get()
{
	return 1;
	//return jointLimitDesc->restitution;
}

void NxaJointLimitDescription::Restitution::set(float value)
{
	//jointLimitDesc->restitution = value;
}
