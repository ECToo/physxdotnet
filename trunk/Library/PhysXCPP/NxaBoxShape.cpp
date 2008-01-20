#include "StdAfx.h"
#include "NxaBoxShape.h"

#include "NxBoxShape.h"

NxaBoxShape::NxaBoxShape(NxShape* ptr) : NxaShape(ptr)
{

}

void NxaBoxShape::SetDimensions(Vector3 vec)
{
	NxBoxShape* boxPtr = (NxBoxShape*)nxShape;
	boxPtr->setDimensions(NxaMath::Vector3XNAToPhysX(vec));
}

void NxaBoxShape::SetDimensions(Vector3% vec)
{
	NxBoxShape* boxPtr = (NxBoxShape*)nxShape;
	boxPtr->setDimensions(NxaMath::Vector3XNAToPhysX(vec));
}

Vector3 NxaBoxShape::GetDimensions()
{
	NxBoxShape* boxPtr = (NxBoxShape*)nxShape;
	return NxaMath::Vector3PhysXToXNA(boxPtr->getDimensions());
}

void NxaBoxShape::GetWorldOrientedBoundingBox([Out] NxaBox ^%obb)
{
	NxBoxShape* boxPtr = (NxBoxShape*)nxShape;
	boxPtr->getWorldOBB(*(obb->nxBox));
}

void NxaBoxShape::SaveToDesc([Out] NxaBoxShapeDescription^% desc)
{
	NxBoxShape* boxPtr = (NxBoxShape*)nxShape;
	NxBoxShapeDesc* bsDesc = (NxBoxShapeDesc*)desc->nxShapeDesc;
	boxPtr->saveToDesc(*bsDesc);
}