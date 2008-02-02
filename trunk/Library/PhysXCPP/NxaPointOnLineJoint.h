#pragma once

#include "NxaJoint.h"
#include "NxaPointOnLineJointDescription.h"

#include "NxPointOnLineJointDesc.h"

public ref class NxaPointOnLineJoint : public NxaJoint
{
internal:
	NxaPointOnLineJoint(NxPointOnLineJoint* ptr);

public:
	void LoadFromDescription(NxaPointOnLineJointDescription^ desc);
	void SaveToDescription([Out] NxaPointOnLineJointDescription^% desc);
};