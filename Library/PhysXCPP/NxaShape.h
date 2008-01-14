#pragma once

#include "Nxap.h"

namespace PhysXCPP
{

	public ref class NxaShape abstract
	{
	internal:
		NxShape* nxShape;

		static NxaShape^ CreateFromPointer(NxShape* ptr);

	public:
		NxaShape(NxShape* ptr);

		//Is... Shape Type
		bool Is(NxaShapeType type);
		bool IsBox() { return nxShape->isBox(); }
		bool IsCapsule() { return nxShape->isCapsule(); }
		bool IsConvexMesh() { return nxShape->isConvexMesh(); }
		bool IsHeightField() { return nxShape->isHeightField(); }
		bool IsPlane() { return nxShape->isPlane(); }
		bool IsSphere() { return nxShape->isSphere(); }
		bool IsTriangleMesh() { return nxShape->isTriangleMesh(); }
		bool IsWheel() { return nxShape->isWheel(); }
		
		Vector3 GetGlobalPosition();
		Matrix GetGlobalPose();
		Matrix GetGlobalOrientation();
	};

}