#pragma once

#include "Nxap.h"
class NxJointDriveDesc;

public ref class NxaJointDriveDescription
{
internal:
	NxJointDriveDesc* nxDesc;
	NxaJointDriveDescription(NxJointDriveDesc* ptr);

public:
	NxaJointDriveDescription();
	~NxaJointDriveDescription();
	!NxaJointDriveDescription();

	property NxaD6JointDriveType DriveType
	{
		NxaD6JointDriveType get();
		void set(NxaD6JointDriveType value);
	}

	property float Spring
	{
		float get();
		void set(float value);
	}

	property float Damping
	{
		float get();
		void set(float value);
	}

	property float ForceLimit
	{
		float get();
		void set(float value);
	}
};
