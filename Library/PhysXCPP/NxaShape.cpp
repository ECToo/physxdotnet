#include "StdAfx.h"
#include "NxaShape.h"
#include "NxaBoxShape.h"
#include "NxaCapsuleShape.h"
#include "NxaPlaneShape.h"
#include "NxaSphereShape.h"
#include "NxaHeightFieldShape.h"
#include "NxContainer.h"

NxaShape::NxaShape(NxShape *ptr)
{
	nxShape = ptr;

	NxShapeContainer::GetInstance()->Add(IntPtr(ptr), this);
}

NxaShape::~NxaShape()
{
	this->!NxaShape();
}

NxaShape::!NxaShape()
{
	NxShapeContainer::GetInstance()->Remove(IntPtr(nxShape));
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
		case NX_SHAPE_HEIGHTFIELD:
			return gcnew NxaHeightFieldShape(ptr);

		default:
			throw gcnew Exception("Unknown shape type");
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

void NxaShape::SetGlobalPosition(Vector3 position)
{
	nxShape->setGlobalPosition(NxaMath::Vector3XNAToPhysX(position));
}
void NxaShape::SetGlobalPose(Matrix pose)
{
	nxShape->setGlobalPose(NxaMath::MatrixRotPosXNAToPhysX(pose));
}
void NxaShape::SetGlobalOrientation(Matrix orientation)
{
	nxShape->setGlobalOrientation(NxaMath::MatrixRotXNAToPhysX(orientation));
}

NxaActor^ NxaShape::GetActor()
{
	return NxActorContainer::GetInstance()->Find(IntPtr(&(nxShape->getActor())));
}

Object^ NxaShape::UserData::get()
{
	if(nxShape->userData != 0)
	{
		GCHandle gch = GCHandle::FromIntPtr((System::IntPtr)(nxShape->userData));
		Object^ obj = (Object^)(gch.Target);
		return obj;
	}
	else
	{
		return nullptr;
	}
}

void NxaShape::UserData::set(Object ^ value)
{
	if(nxShape->userData != 0)
	{
		GCHandle gch = GCHandle::FromIntPtr(IntPtr(nxShape->userData));
		gch.Free();
		nxShape->userData = 0;
	}
	if( value != nullptr)
	{
		GCHandle gch = GCHandle::Alloc(value);
		nxShape->userData = (void*)(GCHandle::ToIntPtr(gch));
	}
}