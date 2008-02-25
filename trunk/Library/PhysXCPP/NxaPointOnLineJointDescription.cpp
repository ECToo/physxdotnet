#include "StdAfx.h"
#include "NxaPointOnLineJointDescription.h"
#include "NxaJoint.h"
#include "NxPointOnLineJointDesc.h"
#include "NxScene.h"

void NxaPointOnLineJointDescription::LoadFromNative(NxPointOnLineJointDesc& desc)
{
	NxaJointDescription::LoadFromNative(desc);
}

NxPointOnLineJointDesc NxaPointOnLineJointDescription::ConvertToNative()
{
	NxPointOnLineJointDesc pointOnLineDesc;

	NxaJointDescription::ConvertToNative(pointOnLineDesc);

	return pointOnLineDesc;
}

NxaJoint^ NxaPointOnLineJointDescription::CreateJoint(NxScene* scenePtr)
{
	NxPointOnLineJointDesc pointOnLineDesc = ConvertToNative();	

	NxJoint* jointPtr = scenePtr->createJoint(pointOnLineDesc);
	return NxaJoint::CreateFromPointer(jointPtr);
}

NxaPointOnLineJointDescription::NxaPointOnLineJointDescription() : NxaJointDescription(NxaJointType::PointOnLine)
{
	SetToDefault();
}

void NxaPointOnLineJointDescription::SetToDefault()
{
	NxaJointDescription::SetToDefault();
}

bool NxaPointOnLineJointDescription::IsValid()
{
	return NxaJointDescription::IsValid();
}