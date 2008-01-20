#include "StdAfx.h"
#include "NxaSphericalJointDescription.h"

#include "NxSphericalJointDesc.h"



NxaSphericalJointDescription::NxaSphericalJointDescription(void)
{
	nxJointDesc = new NxSphericalJointDesc();
}

Vector3 NxaSphericalJointDescription::SwingAxis::get()
{
	NxSphericalJointDesc* joint = dynamic_cast<NxSphericalJointDesc*>(nxJointDesc);
	return Vector3(joint->swingAxis.x, joint->swingAxis.y, joint->swingAxis.z);
}

void NxaSphericalJointDescription::SwingAxis::set(Vector3 axis)
{
	NxSphericalJointDesc* joint = dynamic_cast<NxSphericalJointDesc*>(nxJointDesc);
	joint->swingAxis.set(axis.X, axis.Y, axis.Z);
}

float NxaSphericalJointDescription::ProjectionDistance::get()
{
	NxSphericalJointDesc* joint = dynamic_cast<NxSphericalJointDesc*>(nxJointDesc);
	return joint->projectionDistance;
}

void NxaSphericalJointDescription::ProjectionDistance::set(float dist)
{
	NxSphericalJointDesc* joint = dynamic_cast<NxSphericalJointDesc*>(nxJointDesc);
	joint->projectionDistance = dist;
}