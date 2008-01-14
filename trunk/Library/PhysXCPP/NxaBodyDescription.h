#pragma once

#include "NxPhysics.h"

namespace PhysXCPP
{
	public ref class NxaBodyDescription
	{
	public:
		property NxBodyDesc* nxBodyDesc;

	public:
		NxaBodyDescription(void);
		!NxaBodyDescription(void);
	};

}
