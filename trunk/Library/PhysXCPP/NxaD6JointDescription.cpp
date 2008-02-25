#include "StdAfx.h"
#include "NxaD6JointDescription.h"
#include "NxaJointLimitSoftDescription.h"
#include "NxaJointLimitSoftPairDescription.h"
#include "NxaJointDriveDescription.h"
#include "NxaJoint.h"
#include "NxScene.h"
#include "Nxap.h"
#include "NxD6JointDesc.h"

void NxaD6JointDescription::LoadFromNative(NxD6JointDesc& desc)
{
	NxaJointDescription::LoadFromNative(desc);

	XMotion = (NxaD6JointMotion)desc.xMotion;
	YMotion = (NxaD6JointMotion)desc.yMotion;
	ZMotion = (NxaD6JointMotion)desc.zMotion;
	Swing1Motion = (NxaD6JointMotion)desc.swing1Motion;
	Swing2Motion = (NxaD6JointMotion)desc.swing2Motion;
	TwistMotion = (NxaD6JointMotion)desc.twistMotion;

	LinearLimit.LoadFromNative(desc.linearLimit);
	Swing1Limit.LoadFromNative(desc.swing1Limit);
	Swing2Limit.LoadFromNative(desc.swing2Limit);

	TwistLimit.LoadFromNative(desc.twistLimit);

	XDrive.LoadFromNative(desc.xDrive);
	YDrive.LoadFromNative(desc.yDrive);
	ZDrive.LoadFromNative(desc.zDrive);
	SwingDrive.LoadFromNative(desc.swingDrive);
	TwistDrive.LoadFromNative(desc.twistDrive);
	SlerpDrive.LoadFromNative(desc.slerpDrive);

	DrivePosition = NxaMath::Vector3PhysXToXNA(desc.drivePosition);
	DriveOrientation = NxaMath::QuaternionPhysXToXNA(desc.driveOrientation);
	DriveLinearVelocity = NxaMath::Vector3PhysXToXNA(desc.driveLinearVelocity);
	DriveAngularVelocity = NxaMath::Vector3PhysXToXNA(desc.driveAngularVelocity);

	ProjectionMode = (NxaJointProjectionMode)desc.projectionMode;
	ProjectionDistance = desc.projectionDistance;
	ProjectionAngle = desc.projectionAngle;

	GearRatio = desc.gearRatio;
	Flags = (NxaD6JointFlag)desc.flags;
}

NxD6JointDesc NxaD6JointDescription::ConvertToNative()
{
	NxD6JointDesc d6Desc;

	NxaJointDescription::ConvertToNative(d6Desc);

	// D6JointDesc Stuff
	d6Desc.xMotion = (NxD6JointMotion)XMotion;
	d6Desc.yMotion = (NxD6JointMotion)YMotion;
	d6Desc.zMotion = (NxD6JointMotion)ZMotion;
	d6Desc.swing1Motion= (NxD6JointMotion)Swing1Motion;
	d6Desc.swing2Motion = (NxD6JointMotion)Swing2Motion;
	d6Desc.twistMotion = (NxD6JointMotion)TwistMotion;

	d6Desc.linearLimit = LinearLimit.ConvertToNative();
	d6Desc.swing1Limit = Swing1Limit.ConvertToNative();
	d6Desc.swing2Limit = Swing2Limit.ConvertToNative();
	d6Desc.twistLimit = TwistLimit.ConvertToNative();

	d6Desc.xDrive = XDrive.ConvertToNative();
	d6Desc.yDrive = YDrive.ConvertToNative();
	d6Desc.zDrive = ZDrive.ConvertToNative();
	d6Desc.swingDrive = SwingDrive.ConvertToNative();
	d6Desc.twistDrive = TwistDrive.ConvertToNative();
	d6Desc.slerpDrive = SlerpDrive.ConvertToNative();

	d6Desc.drivePosition = NxaMath::Vector3XNAToPhysX(DrivePosition);
	d6Desc.driveOrientation = NxaMath::QuaternionXNAToPhysX(DriveOrientation);
	d6Desc.driveLinearVelocity = NxaMath::Vector3XNAToPhysX(DriveLinearVelocity);
	d6Desc.driveAngularVelocity = NxaMath::Vector3XNAToPhysX(DriveAngularVelocity);

	d6Desc.projectionMode = (NxJointProjectionMode)ProjectionMode;
	d6Desc.projectionDistance = ProjectionDistance;
	d6Desc.projectionAngle = ProjectionAngle;
	
	d6Desc.gearRatio = GearRatio;

	d6Desc.flags = (NxU32)Flags;

	return d6Desc;
}

NxaJoint^ NxaD6JointDescription::CreateJoint(NxScene* scenePtr)
{
	NxD6JointDesc d6Desc = ConvertToNative();

	NxJoint* jointPtr = scenePtr->createJoint(d6Desc);
	return NxaJoint::CreateFromPointer(jointPtr);
}

NxaD6JointDescription::NxaD6JointDescription() : NxaJointDescription(NxaJointType::D6)
{
	SetToDefault();
}

void NxaD6JointDescription::SetToDefault()
{
	NxaJointDescription::SetToDefault();

	XMotion = NxaD6JointMotion::Free;
	YMotion = NxaD6JointMotion::Free;
	ZMotion = NxaD6JointMotion::Free;
	TwistMotion = NxaD6JointMotion::Free;
	Swing1Motion = NxaD6JointMotion::Free;
	Swing2Motion = NxaD6JointMotion::Free;

	DrivePosition = Vector3::Zero;
	DriveOrientation = Quaternion::Identity;

	DriveLinearVelocity = Vector3::Zero;
	DriveAngularVelocity = Vector3::Zero;

	ProjectionMode = NxaJointProjectionMode::None;
	ProjectionDistance = 0.1f;
	ProjectionAngle = 0.0872f; //about 5 degrees in radians.

	Flags = (NxaD6JointFlag)0;
	GearRatio = 1.0f;
}

bool NxaD6JointDescription::IsValid()
{
	 // only possible with all angular DOF available
	if((Flags & NxaD6JointFlag::SlerpDrive) == NxaD6JointFlag::SlerpDrive) 
	{
		if(Swing1Motion == NxaD6JointMotion::Locked ||
			Swing2Motion == NxaD6JointMotion::Locked ||
			TwistMotion == NxaD6JointMotion::Locked)
		{
			return false;
		}
	}

	// swing limits are symmetric, thus their range is 0..180 degrees
	if(Swing1Motion == NxaD6JointMotion::Limited)
	{
		if(Swing1Limit.Value < 0.0f) return false;
		if(Swing1Limit.Value > Math::PI) return false;
	}
	if(Swing2Motion == NxaD6JointMotion::Limited)
	{
		if(Swing2Limit.Value < 0.0f) return false;
		if(Swing2Limit.Value > Math::PI) return false;
	}

	// Twist limits are asymmetric with -180 <= low < high <= 180 degrees
	if(TwistMotion == NxaD6JointMotion::Limited)
	{
		if(TwistLimit.Low.Value < -Math::PI) return false;
		if(TwistLimit.High.Value > Math::PI) return false;
		if(TwistLimit.Low.Value > TwistLimit.High.Value) return false;
	}

	// In angular limited-free mode, only -90..90 swings are possible
	if(Swing1Motion == NxaD6JointMotion::Limited && Swing2Motion == NxaD6JointMotion::Free)
		if(Swing1Limit.Value > MathHelper::PiOver2) return false;
	if(Swing2Motion == NxaD6JointMotion::Limited && Swing2Motion == NxaD6JointMotion::Free)
		if(Swing2Limit.Value > MathHelper::PiOver2) return false;

	// gear only with twist motion enabled
	if((Flags & NxaD6JointFlag::GearEnabled) == NxaD6JointFlag::GearEnabled)
		if(TwistMotion == NxaD6JointMotion::Locked) return false;

	return NxaJointDescription::IsValid();
}