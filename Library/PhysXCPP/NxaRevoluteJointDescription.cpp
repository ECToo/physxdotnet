#include "StdAfx.h"
#include "NxaRevoluteJointDescription.h"
#include "NxaJoint.h"
#include "NxScene.h"
#include "NxRevoluteJointDesc.h"

void NxaRevoluteJointDescription::LoadFromNative(NxRevoluteJointDesc& desc)
{
	NxaJointDescription::LoadFromNative(desc);
}

NxRevoluteJointDesc NxaRevoluteJointDescription::ConvertToNative()
{
	NxRevoluteJointDesc revoluteDesc;

	NxaJointDescription::ConvertToNative(revoluteDesc);

	//RevoluteJointDescription Stuff
	revoluteDesc.limit = Limit.ConvertToNative();
	revoluteDesc.motor = Motor.ConvertToNative();
	revoluteDesc.spring = Spring.ConvertToNative();
	revoluteDesc.projectionDistance = ProjectionDistance;
	revoluteDesc.projectionAngle = ProjectionAngle;
	revoluteDesc.flags = (NxU32)Flags;
	revoluteDesc.projectionMode = (NxJointProjectionMode)ProjectionMode;

	return revoluteDesc;
}

NxaJoint^ NxaRevoluteJointDescription::CreateJoint(NxScene* scenePtr)
{
	NxRevoluteJointDesc revoluteDesc = ConvertToNative();	

	NxJoint* jointPtr = scenePtr->createJoint(revoluteDesc);
	return NxaJoint::CreateFromPointer(jointPtr);
}

NxaRevoluteJointDescription::NxaRevoluteJointDescription() : NxaJointDescription(NxaJointType::Revolute)
{
	SetToDefault();
}

void NxaRevoluteJointDescription::SetToDefault()
{
	NxaJointDescription::SetToDefault();
	
	ProjectionDistance = 1.0f;
	ProjectionAngle = 0.0872f; //about 5 degrees in radians.

	Limit.SetToDefault();
	Motor.SetToDefault();
	Spring.SetToDefault();

	Flags = (NxaRevoluteJointFlag)0;
	ProjectionMode = NxaJointProjectionMode::None;
}

bool NxaRevoluteJointDescription::IsValid()
{
	if(ProjectionDistance < 0.0f) return false;
	if(ProjectionAngle < 0.02f) return false;

	if(!Limit.IsValid()) return false;
	if(!Motor.IsValid()) return false;
	if(!Spring.IsValid()) return false;

	return NxaJointDescription::IsValid();
}