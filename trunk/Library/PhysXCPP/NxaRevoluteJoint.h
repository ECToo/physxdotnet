#pragma once

#include "NxRevoluteJointDesc.h"

#include "NxaJoint.h"
#include "NxaRevoluteJointDescription.h"
#include "NxaJointLimitPairDescription.h"
#include "NxaMotorDescription.h"
#include "NxaSpringDescription.h"

public ref class NxaRevoluteJoint : public NxaJoint
{
internal:
	NxaRevoluteJoint(NxRevoluteJoint* ptr);

public:
	void LoadFromDescription(NxaRevoluteJointDescription^ desc);
	void SaveToDescription([Out] NxaRevoluteJointDescription^% desc);

	void SetLimits(NxaJointLimitPairDescription^ pair);
	void GetLimits([Out] NxaJointLimitPairDescription^% pair);

	void SetMotor(NxaMotorDescription^ motor);
	void GetMotor([Out] NxaMotorDescription^% motor);

	void SetSpring(NxaSpringDescription^ spring);
	void GetSpring([Out] NxaSpringDescription^% spring);

	float GetAngle();
	float GetVelocity();

	void SetFlags(NxaRevoluteJointFlag flag);
	NxaRevoluteJointFlag GetFlags();
	void SetProjectionMode(NxaJointProjectionMode mode);
	NxaJointProjectionMode GetProjectionMode();
};