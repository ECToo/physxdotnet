#pragma once
#include "nxashape.h"

namespace PhysXCPP
{

	public ref class NxaSphereShape : public NxaShape
	{
	internal:
		NxaSphereShape(NxShape *ptr);

	public:
		void SetRadius(float radius) { nxShape->isSphere()->setRadius(radius); }
		float GetRadius() { return nxShape->isSphere()->getRadius(); }
	};

}