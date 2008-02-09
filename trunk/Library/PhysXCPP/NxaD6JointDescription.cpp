#include "StdAfx.h"
#include "NxaD6JointDescription.h"

#include "NxD6JointDesc.h"

NxaD6JointDescription::NxaD6JointDescription(void)
{
	throw gcnew Exception("NOT IMPLEMENTED YET!");
	nxJointDesc = new NxD6JointDesc();
}

void NxaD6JointDescription::SetToDefault()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->setToDefault();
}

bool NxaD6JointDescription::IsValid()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return d6Ptr->isValid();
}

NxaD6JointMotion NxaD6JointDescription::XMotion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->xMotion);
}

void NxaD6JointDescription::XMotion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->xMotion = (NxD6JointMotion)value;
}

NxaD6JointMotion NxaD6JointDescription::YMotion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->yMotion);
}

void NxaD6JointDescription::YMotion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->yMotion = (NxD6JointMotion)value;
}

NxaD6JointMotion NxaD6JointDescription::ZMotion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->zMotion);
}

void NxaD6JointDescription::ZMotion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->zMotion = (NxD6JointMotion)value;
}