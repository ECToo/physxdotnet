#pragma once

#include "NxaJoint.h"

ref class NxaD6JointDescription;

public ref class NxaD6Joint : NxaJoint
{
internal:
	NxaD6Joint(NxD6Joint* nxD6Joint);

public:
	void LoadFromDescription(NxaD6JointDescription^ desc);
	void SaveToDescription([Out] NxaD6JointDescription^% desc);

	virtual void SetDrivePosition(Vector3 position);
	virtual void SetDriveOrientation(Quaternion orientation);
	virtual void SetDriveLinearVelocity(Vector3 linearVelocity);
	virtual void SetDriveAngularVelocity(Vector3 angularVelocity);
};
