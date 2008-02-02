#include "StdAfx.h"
#include "NxaPrismaticJoint.h"

#include "NxPrismaticJoint.h"

NxaPrismaticJoint::NxaPrismaticJoint(NxPrismaticJoint* ptr)
{
	nxJoint = ptr;
}

void NxaPrismaticJoint::LoadFromDescription(NxaPrismaticJointDescription ^desc)
{
	NxPrismaticJointDesc* nxDesc = (NxPrismaticJointDesc*)(desc->nxJointDesc);
	((NxPrismaticJoint*)nxJoint)->loadFromDesc(*nxDesc);
}

void NxaPrismaticJoint::SaveToDescription([Out] NxaPrismaticJointDescription^% desc)
{
	NxPrismaticJointDesc nxDesc;
	((NxPrismaticJoint*)nxJoint)->saveToDesc(nxDesc);
	desc = gcnew NxaPrismaticJointDescription(&nxDesc);
}