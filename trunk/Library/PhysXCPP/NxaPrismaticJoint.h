#pragma once

#include "NxaJoint.h"

ref class NxaPrismaticJointDescription;
class NxPrismaticJointDesc;

public ref class NxaPrismaticJoint : public NxaJoint
{
internal:
	NxaPrismaticJoint(NxPrismaticJoint* ptr);

public:
	void LoadFromDescription(NxaPrismaticJointDescription^ desc);
	void SaveToDescription([Out] NxaPrismaticJointDescription^% desc);
};