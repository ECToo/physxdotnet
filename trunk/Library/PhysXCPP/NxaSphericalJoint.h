#pragma once

#include "NxaJoint.h"

#include "NxSphericalJointDesc.h"

public ref class NxaSphericalJoint : public NxaJoint
{
public:
	NxaSphericalJoint(NxSphericalJoint* nxSphericalJointDesc);
};