#pragma once
#include "nxashape.h"

namespace PhysXCPP
{

	public ref class NxaPlaneShape : public NxaShape
	{
	internal:
		NxaPlaneShape(NxShape* ptr);
	};

}