#include "StdAfx.h"
#include "NxaSphereShapeDescription.h"
#include "NxPhysics.h"

using namespace PhysXCPP;
using namespace Microsoft::Xna::Framework;

NxaSphereShapeDescription::NxaSphereShapeDescription(void)
{
	nxShapeDesc = new NxSphereShapeDesc();
}

NxaSphereShapeDescription::NxaSphereShapeDescription(NxSphereShapeDesc* ptr)
{
	nxShapeDesc = ptr;
}

NxaSphereShapeDescription::!NxaSphereShapeDescription(void)
{
}

void NxaSphereShapeDescription::Radius::set(float radius)
{
	NxSphereShapeDesc* sphereDesc = (NxSphereShapeDesc*)nxShapeDesc;
	sphereDesc->radius = radius;
}