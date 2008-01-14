#pragma once

#include "NxPhysics.h"
#include "NxaJoint.h"

namespace PhysXCPP
{

	public ref class NxaSphericalJoint : public NxaJoint
	{
	public:
		NxaSphericalJoint(NxSphericalJoint* nxSphericalJointDesc);
	};

}