#include "StdAfx.h"
#include "NxaDistanceJoint.h"
#include "NxaDistanceJointDescription.h"

#include "NxDistanceJoint.h"
#include "NxDistanceJointDesc.h"


NxaDistanceJoint::NxaDistanceJoint(NxDistanceJoint* nxDistanceJoint)
{
	nxJoint = nxDistanceJoint;
}

void NxaDistanceJoint::LoadFromDescription(NxaDistanceJointDescription ^desc)
{
	NxDistanceJoint* ptr = (NxDistanceJoint*)nxJoint;
	NxDistanceJointDesc distanceDesc = desc->ConvertToNative();
	ptr->loadFromDesc(distanceDesc);
}

void NxaDistanceJoint::SaveToDescription([Out] NxaDistanceJointDescription^% desc)
{
	NxDistanceJoint* ptr = (NxDistanceJoint*)nxJoint;

	NxDistanceJointDesc distanceDesc;
	ptr->saveToDesc(distanceDesc);

	desc->LoadFromNative(distanceDesc);
}