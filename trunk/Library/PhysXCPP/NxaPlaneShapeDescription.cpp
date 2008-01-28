#include "StdAfx.h"
#include "NxaPlaneShapeDescription.h"

NxaPlaneShapeDescription::NxaPlaneShapeDescription()
{
	nxShapeDesc = new NxPlaneShapeDesc();
}

NxaPlaneShapeDescription::NxaPlaneShapeDescription(NxPlaneShapeDesc *ptr)
{
	nxShapeDesc = ptr;
}