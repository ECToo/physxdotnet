#pragma once

#include "Nxap.h"

#include "NxaJointDescription.h"

public ref class NxaD6JointDescription : NxaJointDescription
{
public:
	NxaD6JointDescription();

	virtual void SetToDefault();
	virtual bool IsValid();

	property NxaD6JointMotion XMotion
	{
		NxaD6JointMotion get();
		void set(NxaD6JointMotion value);
	}

	property NxaD6JointMotion YMotion
	{
		NxaD6JointMotion get();
		void set(NxaD6JointMotion value);
	}

	property NxaD6JointMotion ZMotion
	{
		NxaD6JointMotion get();
		void set(NxaD6JointMotion value);
	}

	/*property NxaD6JointMotion Swing1Motion
	{
		NxaD6JointMotion get();
		void set(NxaD6JointMotion value);
	}

	property NxaD6JointMotion Swing2Motion
	{
		NxaD6JointMotion get();
		void set(NxaD6JointMotion value);
	}

	property NxaD6JointMotion TwistMotion
	{
		NxaD6JointMotion get();
		void set(NxaD6JointMotion value);
	}*/

	/*property NxaJointLimitSoftDescription LinearLimit
	{
		NxaJointLimitSoftDescription get();
		void set(NxaJointLimitSoftDescription value);
	}

	property NxaJointLimitSoftDescription Swing1Limit
	{
		NxaJointLimitSoftDescription get();
		void set(NxaJointLimitSoftDescription value);
	}

	property NxaJointLimitSoftDescription Swing2Limit
	{
		NxaJointLimitSoftDescription get();
		void set(NxaJointLimitSoftDescription value);
	}

	property NxaJointDriveDescription XDrive
	{
		NxaJointDriveDescription get();
		void set(NxaJointDriveDescription value);
	}

	property NxaJointDriveDescription YDrive
	{
		NxaJointDriveDescription get();
		void set(NxaJointDriveDescription value);
	}

	property NxaJointDriveDescription ZDrive
	{
		NxaJointDriveDescription get();
		void set(NxaJointDriveDescription value);
	}

	property NxaJointDriveDescription SwingDrive
	{
		NxaJointDriveDescription get();
		void set(NxaJointDriveDescription value);
	}

	property NxaJointDriveDescription TwistDrive
	{
		NxaJointDriveDescription get();
		void set(NxaJointDriveDescription value);
	}

	property NxaJointDriveDescription SlerpDrive
	{
		NxaJointDriveDescription get();
		void set(NxaJointDriveDescription value);
	}*/

	/*property Vector3 DrivePosition
	{
		Vector3 get();
		void set(Vector3 value);
	}

	property Quaternion DriveOrientation
	{
		Quaternion get();
		void set(Quaternion value);
	}

	property Vector3 DriveLinearVelocity
	{
		Vector3 get();
		void set(Vector3 value);
	}

	property Vector3 DriveAngularVelocity
	{
		Vector3 get();
		void set(Vector3 value);
	}

	property NxaJointProjectionMode ProjectionMode
	{
		NxaJointProjectionMode get();
		void set(NxaJointProjectionMode value);
	}

	property float ProjectionDistance
	{
		float get();
		void set(float value);
	}

	property float ProjectionAngle
	{
		float get();
		void set(float value);
	}

	property float GearRatio
	{
		float get();
		void set(float value);
	}

	property NxaU32 Flags
	{
		NxaU32 get();
		void set(NxaU32 value);
	}*/
};
