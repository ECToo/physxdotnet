#pragma once

#include "NxaJoint.h"
#include "NxaPrismaticJointDescription.h"

#include "NxPrismaticJointDesc.h"

public ref class NxaPrismaticJoint : public NxaJoint
{
internal:
	NxaPrismaticJoint(NxPrismaticJoint* ptr);

public:
	void LoadFromDescription(NxaPrismaticJointDescription^ desc);
	void SaveToDescription([Out] NxaPrismaticJointDescription^% desc);
};