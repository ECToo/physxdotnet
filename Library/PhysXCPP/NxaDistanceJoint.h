#pragma once

#include "NxaJoint.h"

ref class NxaDistanceJointDescription;

public ref class NxaDistanceJoint : NxaJoint
{
internal:
	NxaDistanceJoint(NxDistanceJoint* nxDistanceJoint);

public:
	void LoadFromDescription(NxaDistanceJointDescription^ desc);
	void SaveToDescription([Out] NxaDistanceJointDescription^% desc);
};
