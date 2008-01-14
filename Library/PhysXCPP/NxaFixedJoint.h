#pragma once

#include "NxPhysics.h"
#include "NxaJoint.h"

namespace PhysXCPP
{

	public ref class NxaFixedJoint : public NxaJoint
	{
	public:
		NxaFixedJoint(NxFixedJoint* nxFixedJoint);
		~NxaFixedJoint(void);
		!NxaFixedJoint(void);
	};

}