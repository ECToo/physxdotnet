#include "StdAfx.h"
#include "NxaSphereShape.h"



NxaSphereShape::NxaSphereShape(NxShape *ptr) : NxaShape(ptr)
{
}

void NxaSphereShape::SaveToDesc(NxaSphereShapeDescription ^%desc)
{
	NxSphereShape* spherePtr = (NxSphereShape*)nxShape;
	desc->Radius = spherePtr->getRadius();
}