#pragma once

#include "NxaJointDescription.h"

class NxScene;
class NxFixedJointDesc;

public ref class NxaFixedJointDescription : public NxaJointDescription
{
internal:
	virtual void LoadFromNative(NxFixedJointDesc& desc);
	virtual NxFixedJointDesc ConvertToNative();
	virtual NxaJoint^ CreateJoint(NxScene* scenePtr) override;

public:
	NxaFixedJointDescription();

	virtual void SetToDefault() override;
	virtual bool IsValid() override;
};