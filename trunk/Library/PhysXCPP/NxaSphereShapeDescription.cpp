#include "StdAfx.h"
#include "NxaSphereShapeDescription.h"



NxaSphereShapeDescription::NxaSphereShapeDescription(void)
{
	nxShapeDesc = new NxSphereShapeDesc();
}

NxaSphereShapeDescription::NxaSphereShapeDescription(NxSphereShapeDesc* ptr)
{
	nxShapeDesc = ptr;
}

void NxaSphereShapeDescription::Radius::set(float radius)
{
	NxSphereShapeDesc* sphereDesc = (NxSphereShapeDesc*)nxShapeDesc;
	sphereDesc->radius = radius;
}