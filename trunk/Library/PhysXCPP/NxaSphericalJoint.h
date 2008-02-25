#pragma once

#include "NxaJoint.h"

class NxSphericalJointDesc;
ref class NxaSphericalJointDescription;

public ref class NxaSphericalJoint : public NxaJoint
{
internal:
	NxaSphericalJoint(NxSphericalJoint* nxSphericalJoint);

public:
	void LoadFromDescription(NxaSphericalJointDescription^ desc);
	void SaveToDescription([Out] NxaSphericalJointDescription^% desc);
};