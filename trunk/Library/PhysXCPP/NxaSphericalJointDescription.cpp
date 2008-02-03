#include "StdAfx.h"
#include "NxaSphericalJointDescription.h"

#include "NxSphericalJointDesc.h"

NxaSphericalJointDescription::NxaSphericalJointDescription(void)
{
	nxJointDesc = new NxSphericalJointDesc();
}

void NxaSphericalJointDescription::SetToDefault()
{
	nxJointDesc->setToDefault();
}

bool NxaSphericalJointDescription::IsValid()
{
	return nxJointDesc->isValid();
}

Vector3 NxaSphericalJointDescription::SwingAxis::get()
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	return Vector3(joint->swingAxis.x, joint->swingAxis.y, joint->swingAxis.z);
}

void NxaSphericalJointDescription::SwingAxis::set(Vector3 axis)
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	joint->swingAxis.set(axis.X, axis.Y, axis.Z);
}

float NxaSphericalJointDescription::ProjectionDistance::get()
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	return joint->projectionDistance;
}

void NxaSphericalJointDescription::ProjectionDistance::set(float dist)
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	joint->projectionDistance = dist;
}

NxaU32 NxaSphericalJointDescription::Flags::get()
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	return joint->flags;
}

void NxaSphericalJointDescription::Flags::set(NxaU32 flags)
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	joint->flags = flags;
}