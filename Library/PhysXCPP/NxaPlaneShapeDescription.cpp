#include "StdAfx.h"
#include "NxaPlaneShapeDescription.h"



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
