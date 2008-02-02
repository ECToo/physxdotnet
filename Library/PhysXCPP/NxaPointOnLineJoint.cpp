#include "StdAfx.h"
#include "NxaPointOnLineJoint.h"

#include "NxPointOnLineJoint.h"

NxaPointOnLineJoint::NxaPointOnLineJoint(NxPointOnLineJoint* ptr)
{
	nxJoint = ptr;
}

void NxaPointOnLineJoint::LoadFromDescription(NxaPointOnLineJointDescription ^desc)
{
	NxPointOnLineJointDesc* nxDesc = (NxPointOnLineJointDesc*)(desc->nxJointDesc);
	((NxPointOnLineJoint*)nxJoint)->loadFromDesc(*nxDesc);
}

void NxaPointOnLineJoint::SaveToDescription([Out] NxaPointOnLineJointDescription^% desc)
{
	NxPointOnLineJointDesc nxDesc;
	((NxPointOnLineJoint*)nxJoint)->saveToDesc(nxDesc);
	desc = gcnew NxaPointOnLineJointDescription(&nxDesc);
}