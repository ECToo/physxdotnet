#include "StdAfx.h"
#include "NxaFixedJoint.h"
#include "NxaFixedJointDescription.h"

#include "NxFixedJoint.h"
#include "NxFixedJointDesc.h"

NxaFixedJoint::NxaFixedJoint(NxFixedJoint* joint)
{
	nxJoint = joint;
}

void NxaFixedJoint::LoadFromDescription(NxaFixedJointDescription ^desc)
{
	NxFixedJoint* ptr = (NxFixedJoint*)nxJoint;
	NxFixedJointDesc fixedDesc = desc->ConvertToNative();
	ptr->loadFromDesc(fixedDesc);
}

void NxaFixedJoint::SaveToDescription([Out] NxaFixedJointDescription^% desc)
{
	NxFixedJoint* ptr = (NxFixedJoint*)nxJoint;

	NxFixedJointDesc fixedDesc;
	ptr->saveToDesc(fixedDesc);

	desc->LoadFromNative(fixedDesc);
}
