#pragma once

#include "Nxap.h"
#include "NxaJointDescription.h"

#include "NxaJointLimitSoftDescription.h"
#include "NxaJointLimitSoftPairDescription.h"
#include "NxaJointDriveDescription.h"

class NxD6JointDesc;

public ref class NxaD6JointDescription : NxaJointDescription
{
internal:
	virtual void LoadFromNative(NxD6JointDesc& desc);
	virtual NxD6JointDesc ConvertToNative();
	virtual NxaJoint^ CreateJoint(NxScene* scenePtr) override;

public:
	NxaD6JointDescription();

	virtual void SetToDefault() override;
	virtual bool IsValid() override;

	NxaD6JointMotion XMotion;
	NxaD6JointMotion YMotion;
	NxaD6JointMotion ZMotion;

	NxaD6JointMotion Swing1Motion;
	NxaD6JointMotion Swing2Motion;
	NxaD6JointMotion TwistMotion;

	NxaJointLimitSoftDescription LinearLimit;
	NxaJointLimitSoftDescription Swing1Limit;
	NxaJointLimitSoftDescription Swing2Limit;

	NxaJointLimitSoftPairDescription TwistLimit;

	NxaJointDriveDescription XDrive;
	NxaJointDriveDescription YDrive;
	NxaJointDriveDescription ZDrive;

	NxaJointDriveDescription SwingDrive;
	NxaJointDriveDescription TwistDrive;
	NxaJointDriveDescription SlerpDrive;
	
	Vector3 DrivePosition;
	Quaternion DriveOrientation;

	Vector3 DriveLinearVelocity;
	Vector3 DriveAngularVelocity;

	NxaJointProjectionMode ProjectionMode;
	float ProjectionDistance;
	float ProjectionAngle;

	float GearRatio;

	NxaD6JointFlag Flags;
};
