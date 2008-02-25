#include "StdAfx.h"
#include "NxaDistanceJointDescription.h"
#include "NxDistanceJointDesc.h"
#include "NxScene.h"
#include "NxaJoint.h"

void NxaDistanceJointDescription::LoadFromNative(NxDistanceJointDesc& desc)
{
	NxaJointDescription::LoadFromNative(desc);

	MaxDistance = desc.maxDistance;
	MinDistance = desc.minDistance;
	Flags = (NxaDistanceJointFlag)desc.flags;
	Spring->LoadFromNative(desc.spring);
}

NxDistanceJointDesc NxaDistanceJointDescription::ConvertToNative()
{
	NxDistanceJointDesc distanceDesc;

	NxaJointDescription::ConvertToNative(distanceDesc);

	//DistanceJointDescription Stuff
	distanceDesc.maxDistance = MaxDistance;
	distanceDesc.minDistance = MinDistance;
	distanceDesc.flags = (NxU32)Flags;
	distanceDesc.spring = Spring->ConvertToNative();

	return distanceDesc;
}

NxaJoint^ NxaDistanceJointDescription::CreateJoint(NxScene* scenePtr)
{
	NxDistanceJointDesc distanceDesc = ConvertToNative();	

	NxJoint* jointPtr = scenePtr->createJoint(distanceDesc);
	return NxaJoint::CreateFromPointer(jointPtr);
}

NxaDistanceJointDescription::NxaDistanceJointDescription() : NxaJointDescription(NxaJointType::Distance)
{
	Spring = gcnew NxaSpringDescription();
	SetToDefault();
}

void NxaDistanceJointDescription::SetToDefault()
{
	NxaJointDescription::SetToDefault();

	MaxDistance = 0.0f;
	MinDistance = 0.0f;
	Flags = (NxaDistanceJointFlag)0;
	Spring->SetToDefault();
}

bool NxaDistanceJointDescription::IsValid()
{
	if(MaxDistance < 0) return false;
	if(MinDistance < 0) return false;

	if((MinDistance > MaxDistance) && (Flags == (NxaDistanceJointFlag::MinDistanceEnabled | NxaDistanceJointFlag::MaxDistanceEnabled))) return false;
	if(!Spring->IsValid()) return false;

	return NxaJointDescription::IsValid();
}