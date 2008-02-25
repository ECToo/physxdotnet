#pragma once

#include "NxaJointDescription.h"

class NxScene;
class NxPointOnLineJointDesc;

public ref class NxaPointOnLineJointDescription : public NxaJointDescription
{
internal:
	virtual void LoadFromNative(NxPointOnLineJointDesc& desc);
	virtual NxPointOnLineJointDesc ConvertToNative();
	virtual NxaJoint^ CreateJoint(NxScene* scenePtr) override;

public:
	NxaPointOnLineJointDescription();

	virtual void SetToDefault() override;
	virtual bool IsValid() override;
};