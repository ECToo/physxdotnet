#pragma once

#include "NxaJoint.h"

ref class NxaFixedJointDescription;
class NxFixedJoint;

public ref class NxaFixedJoint : public NxaJoint
{
internal:
	NxaFixedJoint(NxFixedJoint* nxFixedJoint);
	
public:
	void LoadFromDescription(NxaFixedJointDescription^ desc);
	void SaveToDescription([Out] NxaFixedJointDescription^% desc);
};