#pragma once

#include "NxaJoint.h"

class NxPointOnLineJoint;
ref class NxaPointOnLineJointDescription;


public ref class NxaPointOnLineJoint : public NxaJoint
{
internal:
	NxaPointOnLineJoint(NxPointOnLineJoint* ptr);

public:
	void LoadFromDescription(NxaPointOnLineJointDescription^ desc);
	void SaveToDescription([Out] NxaPointOnLineJointDescription^% desc);
};