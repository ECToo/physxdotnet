#pragma once

#include "NxaJointDescription.h"
#include "NxaSpringDescription.h"

class NxDistanceJointDesc;

public ref class NxaDistanceJointDescription : public NxaJointDescription
{
internal:
	virtual void LoadFromNative(NxDistanceJointDesc& desc);
	virtual NxDistanceJointDesc ConvertToNative();
	virtual NxaJoint^ CreateJoint(NxScene* scenePtr) override;

public:
	NxaDistanceJointDescription();

	virtual void SetToDefault() override;
	virtual bool IsValid() override;

	float MaxDistance;
	float MinDistance;

	NxaSpringDescription Spring;

	NxaDistanceJointFlag Flags;	
};