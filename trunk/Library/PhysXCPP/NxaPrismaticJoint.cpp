#include "StdAfx.h"
#include "NxaPrismaticJoint.h"
#include "NxaPrismaticJointDescription.h"

#include "NxPrismaticJoint.h"
#include "NxPrismaticJointDesc.h"

NxaPrismaticJoint::NxaPrismaticJoint(NxPrismaticJoint* ptr)
{
	nxJoint = ptr;
}

void NxaPrismaticJoint::LoadFromDescription(NxaPrismaticJointDescription ^desc)
{
	NxPrismaticJoint* ptr = (NxPrismaticJoint*)nxJoint;
	NxPrismaticJointDesc prismaticDesc = desc->ConvertToNative();
	ptr->loadFromDesc(prismaticDesc);
}

void NxaPrismaticJoint::SaveToDescription([Out] NxaPrismaticJointDescription^% desc)
{
	NxPrismaticJoint* ptr = (NxPrismaticJoint*)nxJoint;

	NxPrismaticJointDesc prismaticDesc;
	ptr->saveToDesc(prismaticDesc);

	desc->LoadFromNative(prismaticDesc);
}