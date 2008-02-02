#include "StdAfx.h"
#include "NxaShape.h"
#include "NxaBoxShape.h"
#include "NxaCapsuleShape.h"
#include "NxaPlaneShape.h"
#include "NxaSphereShape.h"



NxaShape::NxaShape(NxShape *ptr)
{
	nxShape = ptr;
}

NxaShape^ NxaShape::CreateFromPointer(NxShape *ptr)
{
	if(ptr != NULL)
	{
		switch(ptr->getType())
		{
		case NX_SHAPE_SPHERE :
			return gcnew NxaSphereShape(ptr);
		case NX_SHAPE_BOX :
			return gcnew NxaBoxShape(ptr);
		case NX_SHAPE_PLANE :
			return gcnew NxaPlaneShape(ptr);
		case NX_SHAPE_CAPSULE :
			return gcnew NxaCapsuleShape(ptr);
		}
	}

	return nullptr;
}

void NxaShape::SetFlag(NxaShapeFlag flag, bool value)
{
	nxShape->setFlag((NxShapeFlag)flag, value);
}

bool NxaShape::GetFlag(NxaShapeFlag flag)
{
	return (nxShape->getFlag((NxShapeFlag)flag) == NX_TRUE);
}

bool NxaShape::Is(NxaShapeType type)
{
	switch(type)
	{
	case NxaShapeType::Box : return (this->IsBox());
	case NxaShapeType::Capsule : return (this->IsCapsule());
	case NxaShapeType::Convex : return (this->IsConvexMesh());
	case NxaShapeType::Heightfield : return (this->IsHeightField());
	case NxaShapeType::Plane : return (this->IsPlane());
	case NxaShapeType::Sphere : return (this->IsSphere());
	case NxaShapeType::Mesh : return (this->IsTriangleMesh());
	case NxaShapeType::Wheel : return (this->IsWheel());
	}

	return false;
}

Vector3 NxaShape::GetGlobalPosition()
{
	return NxaMath::Vector3PhysXToXNA(nxShape->getGlobalPosition());
}

Matrix NxaShape::GetGlobalPose()
{
	return NxaMath::MatrixPhysXToXNA(nxShape->getGlobalPose());
}

Matrix NxaShape::GetGlobalOrientation()
{
	return NxaMath::MatrixPhysXToXNA(nxShape->getGlobalOrientation());
}