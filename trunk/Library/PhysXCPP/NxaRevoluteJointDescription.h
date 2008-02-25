#pragma once

#include "Nxap.h"
#include "NxaJointDescription.h"
#include "NxaJointLimitPairDescription.h"
#include "NxaSpringDescription.h"
#include "NxaMotorDescription.h"

class NxScene;
class NxRevoluteJointDesc;

public ref class NxaRevoluteJointDescription : public NxaJointDescription
{
internal:
	virtual void LoadFromNative(NxRevoluteJointDesc& desc);
	virtual NxRevoluteJointDesc ConvertToNative();
	virtual NxaJoint^ CreateJoint(NxScene* scenePtr) override;

public:
	NxaRevoluteJointDescription();

	virtual void SetToDefault() override;
	virtual bool IsValid() override;

	NxaJointLimitPairDescription Limit;
	NxaMotorDescription Motor;
	NxaSpringDescription Spring;

	float ProjectionDistance;
	float ProjectionAngle;

	NxaRevoluteJointFlag Flags;
	NxaJointProjectionMode ProjectionMode;
};