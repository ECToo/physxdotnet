#include "StdAfx.h"
#include "NxaPrismaticJointDescription.h"
#include "NxaJoint.h"
#include "NxPrismaticJointDesc.h"
#include "NxScene.h"

void NxaPrismaticJointDescription::LoadFromNative(NxPrismaticJointDesc& desc)
{
	NxaJointDescription::LoadFromNative(desc);
}

NxPrismaticJointDesc NxaPrismaticJointDescription::ConvertToNative()
{
	NxPrismaticJointDesc prismaticDesc;

	NxaJointDescription::ConvertToNative(prismaticDesc);

	return prismaticDesc;
}

NxaJoint^ NxaPrismaticJointDescription::CreateJoint(NxScene* scenePtr)
{
	NxPrismaticJointDesc prismaticDesc = ConvertToNative();	

	NxJoint* jointPtr = scenePtr->createJoint(prismaticDesc);
	return NxaJoint::CreateFromPointer(jointPtr);
}

NxaPrismaticJointDescription::NxaPrismaticJointDescription() : NxaJointDescription(NxaJointType::Prismatic)
{
	SetToDefault();
}

void NxaPrismaticJointDescription::SetToDefault()
{
	NxaJointDescription::SetToDefault();
}

bool NxaPrismaticJointDescription::IsValid()
{
	return NxaJointDescription::IsValid();
}