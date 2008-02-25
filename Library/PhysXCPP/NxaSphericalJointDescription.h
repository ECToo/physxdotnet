#pragma once

#include "NxaJointDescription.h"

#include "NxaJointLimitDescription.h"
#include "NxaJointLimitPairDescription.h"
#include "NxaSpringDescription.h"

class NxSphericalJointDesc;
class NxScene;

public ref class NxaSphericalJointDescription : public NxaJointDescription
{
internal:
	virtual void LoadFromNative(NxSphericalJointDesc& desc);
	virtual NxSphericalJointDesc ConvertToNative();
	virtual NxaJoint^ CreateJoint(NxScene* scenePtr) override;

public:
	NxaSphericalJointDescription();

	virtual void SetToDefault() override;
	virtual bool IsValid() override;

	Vector3 SwingAxis;

	float ProjectionDistance;

	NxaJointLimitPairDescription TwistLimit;
	NxaJointLimitDescription SwingLimit;

	NxaSpringDescription TwistSpring;
	NxaSpringDescription SwingSpring;
	NxaSpringDescription JointSpring;

	NxaSphericalJointFlag Flags;

	NxaJointProjectionMode ProjectionMode;
};