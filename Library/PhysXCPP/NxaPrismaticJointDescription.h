#pragma once

#include "NxaJointDescription.h"

class NxScene;
class NxPrismaticJointDesc;

public ref class NxaPrismaticJointDescription : public NxaJointDescription
{
internal:
	virtual void LoadFromNative(NxPrismaticJointDesc& desc);
	virtual NxPrismaticJointDesc ConvertToNative();
	virtual NxaJoint^ CreateJoint(NxScene* scenePtr) override;

public:
	NxaPrismaticJointDescription();

	virtual void SetToDefault() override;
	virtual bool IsValid() override;
};