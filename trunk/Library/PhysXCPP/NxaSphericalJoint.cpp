#include "StdAfx.h"
#include "NxaSphericalJoint.h"
#include "NxaSphericalJointDescription.h"

#include "NxSphericalJoint.h"
#include "NxSphericalJointDesc.h"

NxaSphericalJoint::NxaSphericalJoint(NxSphericalJoint* joint)
{
	nxJoint = joint;
}

void NxaSphericalJoint::LoadFromDescription(NxaSphericalJointDescription ^desc)
{
	NxSphericalJoint* ptr = (NxSphericalJoint*)nxJoint;
	NxSphericalJointDesc sphericalDesc = desc->ConvertToNative();
	ptr->loadFromDesc(sphericalDesc);
}

void NxaSphericalJoint::SaveToDescription([Out] NxaSphericalJointDescription^% desc)
{
	NxSphericalJoint* ptr = (NxSphericalJoint*)nxJoint;

	NxSphericalJointDesc sphericalDesc;
	ptr->saveToDesc(sphericalDesc);

	desc->LoadFromNative(sphericalDesc);
}