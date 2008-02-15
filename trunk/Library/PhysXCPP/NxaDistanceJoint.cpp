#include "StdAfx.h"
#include "NxaDistanceJoint.h"
#include "NxaDistanceJointDescription.h"

#include "NxDistanceJoint.h"


NxaDistanceJoint::NxaDistanceJoint(NxDistanceJoint* nxDistanceJoint)
{
	nxJoint = nxDistanceJoint;
}

void NxaDistanceJoint::LoadFromDescription(NxaDistanceJointDescription ^desc)
{
	NxDistanceJointDesc* nxDesc = (NxDistanceJointDesc*)(desc->nxJointDesc);
	((NxDistanceJoint*)nxJoint)->loadFromDesc(*nxDesc);
}

void NxaDistanceJoint::SaveToDescription([Out] NxaDistanceJointDescription^% desc)
{
	NxDistanceJointDesc* ptr = (NxDistanceJointDesc*)desc->nxJointDesc;
	((NxDistanceJoint*)nxJoint)->saveToDesc(*ptr);
}
