#include "StdAfx.h"
#include "NxaRevoluteJointDescription.h"

#include "NxRevoluteJointDesc.h"

NxaRevoluteJointDescription::NxaRevoluteJointDescription(NxRevoluteJointDesc *ptr)
{
	nxJointDesc = ptr;
}

NxaRevoluteJointDescription::NxaRevoluteJointDescription(void)
{
	nxJointDesc = new NxRevoluteJointDesc();
}

NxaJointLimitPairDescription^ NxaRevoluteJointDescription::Limit::get()
{
	return gcnew NxaJointLimitPairDescription(&(((NxRevoluteJointDesc*)nxJointDesc)->limit));
}

void NxaRevoluteJointDescription::Limit::set(NxaJointLimitPairDescription^ value)
{
	((NxRevoluteJointDesc*)nxJointDesc)->limit = *(value->nxJointLimitPairDesc);
}

NxaMotorDescription^ NxaRevoluteJointDescription::Motor::get()
{
	return gcnew NxaMotorDescription(&(((NxRevoluteJointDesc*)nxJointDesc)->motor));
}

void NxaRevoluteJointDescription::Motor::set(NxaMotorDescription^ value)
{
	((NxRevoluteJointDesc*)nxJointDesc)->motor = *(value->nxMotorDesc);
}

NxaSpringDescription^ NxaRevoluteJointDescription::Spring::get()
{
	return gcnew NxaSpringDescription(&(((NxRevoluteJointDesc*)nxJointDesc)->spring));
}

void NxaRevoluteJointDescription::Spring::set(NxaSpringDescription^ value)
{
	((NxRevoluteJointDesc*)nxJointDesc)->spring = *(value->nxSpringDesc);
}

float NxaRevoluteJointDescription::ProjectionDistance::get()
{
	return ((NxRevoluteJointDesc*)nxJointDesc)->projectionDistance;
}

void NxaRevoluteJointDescription::ProjectionDistance::set(float value)
{
	((NxRevoluteJointDesc*)nxJointDesc)->projectionDistance = value;
}

float NxaRevoluteJointDescription::ProjectionAngle::get()
{
	return ((NxRevoluteJointDesc*)nxJointDesc)->projectionAngle;
}

void NxaRevoluteJointDescription::ProjectionAngle::set(float value)
{
	((NxRevoluteJointDesc*)nxJointDesc)->projectionAngle = value;
}

NxaRevoluteJointFlag NxaRevoluteJointDescription::Flags::get()
{
	return (NxaRevoluteJointFlag)(((NxRevoluteJointDesc*)nxJointDesc)->flags);
}

void NxaRevoluteJointDescription::Flags::set(NxaRevoluteJointFlag value)
{
	((NxRevoluteJointDesc*)nxJointDesc)->flags = (NxRevoluteJointFlag)value;
}

NxaJointProjectionMode NxaRevoluteJointDescription::ProjectionMode::get()
{
	return (NxaJointProjectionMode)(((NxRevoluteJointDesc*)nxJointDesc)->projectionMode);
}

void NxaRevoluteJointDescription::ProjectionMode::set(NxaJointProjectionMode value)
{
	((NxRevoluteJointDesc*)nxJointDesc)->projectionMode = (NxJointProjectionMode)value;
}

void NxaRevoluteJointDescription::SetToDefault()
{
	((NxRevoluteJointDesc*)nxJointDesc)->setToDefault();
}

bool NxaRevoluteJointDescription::IsValid()
{
	return ((NxRevoluteJointDesc*)nxJointDesc)->isValid();
}