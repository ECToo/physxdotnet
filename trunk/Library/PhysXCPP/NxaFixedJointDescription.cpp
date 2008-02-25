#include "StdAfx.h"
#include "NxaFixedJointDescription.h"
#include "NxaJoint.h"
#include "NxFixedJointDesc.h"
#include "NxScene.h"

void NxaFixedJointDescription::LoadFromNative(NxFixedJointDesc& desc)
{
	NxaJointDescription::LoadFromNative(desc);
}

NxFixedJointDesc NxaFixedJointDescription::ConvertToNative()
{
	NxFixedJointDesc fixedDesc;

	NxaJointDescription::ConvertToNative(fixedDesc);

	return fixedDesc;
}

NxaJoint^ NxaFixedJointDescription::CreateJoint(NxScene* scenePtr)
{
	NxFixedJointDesc fixedDesc = ConvertToNative();	

	NxJoint* jointPtr = scenePtr->createJoint(fixedDesc);
	return NxaJoint::CreateFromPointer(jointPtr);
}

NxaFixedJointDescription::NxaFixedJointDescription() : NxaJointDescription(NxaJointType::Fixed)
{
	SetToDefault();
}

void NxaFixedJointDescription::SetToDefault()
{
	NxaJointDescription::SetToDefault();
}

bool NxaFixedJointDescription::IsValid()
{
	return NxaJointDescription::IsValid();
}