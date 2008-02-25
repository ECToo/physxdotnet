#include "StdAfx.h"
#include "NxaPointOnLineJoint.h"
#include "NxaPointOnLineJointDescription.h"

#include "NxPointOnLineJoint.h"
#include "NxPointOnLineJointDesc.h"

NxaPointOnLineJoint::NxaPointOnLineJoint(NxPointOnLineJoint* ptr)
{
	nxJoint = ptr;
}

void NxaPointOnLineJoint::LoadFromDescription(NxaPointOnLineJointDescription ^desc)
{
	NxPointOnLineJoint* ptr = (NxPointOnLineJoint*)nxJoint;
	NxPointOnLineJointDesc pointOnLineDesc = desc->ConvertToNative();
	ptr->loadFromDesc(pointOnLineDesc);
}

void NxaPointOnLineJoint::SaveToDescription([Out] NxaPointOnLineJointDescription^% desc)
{
	NxPointOnLineJoint* ptr = (NxPointOnLineJoint*)nxJoint;

	NxPointOnLineJointDesc pointOnLineDesc;
	ptr->saveToDesc(pointOnLineDesc);

	desc->LoadFromNative(pointOnLineDesc);
}