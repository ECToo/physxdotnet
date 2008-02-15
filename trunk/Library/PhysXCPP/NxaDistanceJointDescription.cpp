#include "StdAfx.h"
#include "NxaDistanceJointDescription.h"

#include "NxDistanceJointDesc.h"

NxaDistanceJointDescription::NxaDistanceJointDescription(NxDistanceJointDesc *ptr)
{
	nxJointDesc = ptr;
}

NxaDistanceJointDescription::NxaDistanceJointDescription(void)
{
	nxJointDesc = new NxDistanceJointDesc();
}

float NxaDistanceJointDescription::MaxDistance::get()
{
	return ((NxDistanceJointDesc*)nxJointDesc)->maxDistance;
}

void NxaDistanceJointDescription::MaxDistance::set(float value)
{
	((NxDistanceJointDesc*)nxJointDesc)->maxDistance = value;
}

float NxaDistanceJointDescription::MinDistance::get()
{
	return ((NxDistanceJointDesc*)nxJointDesc)->minDistance;
}

void NxaDistanceJointDescription::MinDistance::set(float value)
{
	((NxDistanceJointDesc*)nxJointDesc)->minDistance = value;
}

NxaSpringDescription^ NxaDistanceJointDescription::Spring::get()
{
	return gcnew NxaSpringDescription(&(((NxDistanceJointDesc*)nxJointDesc)->spring));
}

void NxaDistanceJointDescription::Spring::set(NxaSpringDescription^ value)
{
	((NxDistanceJointDesc*)nxJointDesc)->spring = *(value->nxSpringDesc);
}

NxaDistanceJointFlag NxaDistanceJointDescription::Flags::get()
{
	return (NxaDistanceJointFlag)(((NxDistanceJointDesc*)nxJointDesc)->flags);
}

void NxaDistanceJointDescription::Flags::set(NxaDistanceJointFlag value)
{
	((NxDistanceJointDesc*)nxJointDesc)->flags = (NxDistanceJointFlag)value;
}



void NxaDistanceJointDescription::SetToDefault()
{
	((NxDistanceJointDesc*)nxJointDesc)->setToDefault();
}

bool NxaDistanceJointDescription::IsValid()
{
	return ((NxDistanceJointDesc*)nxJointDesc)->isValid();
}