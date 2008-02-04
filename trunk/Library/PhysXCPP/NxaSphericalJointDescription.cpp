#include "StdAfx.h"
#include "NxaSphericalJointDescription.h"
#include "NxaSpringDescription.h"
#include "NxaJointLimitPairDescription.h"

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

NxaJointLimitPairDescription^ NxaSphericalJointDescription::TwistLimit::get()
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	return gcnew NxaJointLimitPairDescription(&(joint->twistLimit));
}

void NxaSphericalJointDescription::TwistLimit::set(NxaJointLimitPairDescription^ twistLimit)
{
	((NxSphericalJointDesc*)nxJointDesc)->twistLimit = *(twistLimit->nxJointLimitPairDesc);
}

NxaJointLimitDescription^ NxaSphericalJointDescription::SwingLimit::get()
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	return gcnew NxaJointLimitDescription(&(joint->swingLimit));
}

void NxaSphericalJointDescription::SwingLimit::set(NxaJointLimitDescription^ swingLimit)
{
	((NxSphericalJointDesc*)nxJointDesc)->swingLimit = *(swingLimit->nxJointLimitDesc);
}

NxaSpringDescription^ NxaSphericalJointDescription::TwistSpring::get()
{
	NxSpringDesc desc = ((NxSphericalJointDesc*)nxJointDesc)->twistSpring;
	return gcnew NxaSpringDescription(&desc);
}

void NxaSphericalJointDescription::TwistSpring::set(NxaSpringDescription^ twistSpring)
{
	((NxSphericalJointDesc*)nxJointDesc)->twistSpring = *(twistSpring->nxSpringDesc);
}

NxaSpringDescription^ NxaSphericalJointDescription::SwingSpring::get()
{
	NxSpringDesc desc = ((NxSphericalJointDesc*)nxJointDesc)->swingSpring;
	return gcnew NxaSpringDescription(&desc);
}

void NxaSphericalJointDescription::SwingSpring::set(NxaSpringDescription^ swingSpring)
{
	((NxSphericalJointDesc*)nxJointDesc)->swingSpring = *(swingSpring->nxSpringDesc);
}

NxaSpringDescription^ NxaSphericalJointDescription::JointSpring::get()
{
	NxSpringDesc desc = ((NxSphericalJointDesc*)nxJointDesc)->jointSpring;
	return gcnew NxaSpringDescription(&desc);
}

void NxaSphericalJointDescription::JointSpring::set(NxaSpringDescription^ jointSpring)
{
	((NxSphericalJointDesc*)nxJointDesc)->jointSpring = *(jointSpring->nxSpringDesc);
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

NxaJointProjectionMode NxaSphericalJointDescription::ProjectionMode::get()
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	return (NxaJointProjectionMode)joint->projectionMode;
}

void NxaSphericalJointDescription::ProjectionMode::set(NxaJointProjectionMode projectionMode)
{
	NxSphericalJointDesc* joint = (NxSphericalJointDesc*)nxJointDesc;
	joint->projectionMode = (NxJointProjectionMode)projectionMode;
}