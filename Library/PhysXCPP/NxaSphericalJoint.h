#pragma once

#include "NxaJoint.h"

#include "NxSphericalJointDesc.h"

public ref class NxaSphericalJoint : public NxaJoint
{
internal:
	NxaSphericalJoint(NxSphericalJoint* nxSphericalJointDesc);
};