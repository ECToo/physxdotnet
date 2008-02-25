#include "StdAfx.h"
#include "NxaSphericalJointDescription.h"
#include "NxaJoint.h"

#include "NxSphericalJointDesc.h"
#include "NxScene.h"

void NxaSphericalJointDescription::LoadFromNative(NxSphericalJointDesc& desc)
{
	NxaJointDescription::LoadFromNative(desc);
}

NxSphericalJointDesc NxaSphericalJointDescription::ConvertToNative()
{
	NxSphericalJointDesc sphericalDesc;

	NxaJointDescription::ConvertToNative(sphericalDesc);

	//SphericalJointDescription Stuff
	sphericalDesc.swingAxis = NxaMath::Vector3XNAToPhysX(SwingAxis);
	sphericalDesc.projectionDistance = ProjectionDistance;
	sphericalDesc.twistLimit = TwistLimit.ConvertToNative();
	sphericalDesc.swingLimit = SwingLimit.ConvertToNative();
	sphericalDesc.twistSpring = TwistSpring.ConvertToNative();
	sphericalDesc.swingSpring = SwingSpring.ConvertToNative();
	sphericalDesc.jointSpring = JointSpring.ConvertToNative();
	sphericalDesc.flags = (NxU32)Flags;
	sphericalDesc.projectionMode = (NxJointProjectionMode)ProjectionMode;

	return sphericalDesc;
}

NxaJoint^ NxaSphericalJointDescription::CreateJoint(NxScene* scenePtr)
{
	NxSphericalJointDesc sphericalDesc = ConvertToNative();	

	NxJoint* jointPtr = scenePtr->createJoint(sphericalDesc);
	return NxaJoint::CreateFromPointer(jointPtr);
}

NxaSphericalJointDescription::NxaSphericalJointDescription() : NxaJointDescription(NxaJointType::Spherical)
{
	SetToDefault();
}

void NxaSphericalJointDescription::SetToDefault()
{
	NxaJointDescription::SetToDefault();

	SwingAxis = Vector3::UnitZ;
	TwistLimit.SetToDefault();
	SwingLimit.SetToDefault();
	TwistSpring.SetToDefault();
	SwingSpring.SetToDefault();
	JointSpring.SetToDefault();

	ProjectionDistance = 1.0f;

	Flags = (NxaSphericalJointFlag)0;
	ProjectionMode = NxaJointProjectionMode::None;
}

bool NxaSphericalJointDescription::IsValid()
{
	if(SwingAxis.LengthSquared() < 0.9f) return false;
	if(ProjectionDistance < 0.0f) return false;

	if(!TwistLimit.IsValid()) return false;
	if(!SwingLimit.IsValid()) return false;
	if(!SwingSpring.IsValid()) return false;
	if(!TwistSpring.IsValid()) return false;
	if(!JointSpring.IsValid()) return false;

	return true;
}