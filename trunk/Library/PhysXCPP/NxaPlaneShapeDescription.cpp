#include "StdAfx.h"
#include "NxaPlaneShapeDescription.h"
#include "NxPhysics.h"

using namespace PhysXCPP;

NxaPlaneShapeDescription::NxaPlaneShapeDescription(void)
{
	nxShapeDesc = new NxPlaneShapeDesc();
}

NxaPlaneShapeDescription::NxaPlaneShapeDescription(NxPlaneShapeDesc *ptr)
{
	nxShapeDesc = ptr;
}

NxaPlaneShapeDescription::!NxaPlaneShapeDescription()
{

}
