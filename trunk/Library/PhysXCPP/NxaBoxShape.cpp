#include "StdAfx.h"
#include "NxaBoxShape.h"

using namespace PhysXCPP;

NxaBoxShape::NxaBoxShape(NxShape* ptr) : NxaShape(ptr)
{

}

Vector3 NxaBoxShape::GetDimensions()
{
	NxBoxShape* boxPtr = (NxBoxShape*)nxShape;
	return NxaMath::Vector3PhysXToXNA(boxPtr->getDimensions());
}
