#include "StdAfx.h"
#include "NxaConvexShapeDescription.h"

NxaConvexShapeDescription::NxaConvexShapeDescription()
{

}

NxaConvexShapeDescription::NxaConvexShapeDescription(NxConvexShapeDesc *ptr)
{
	nxShapeDesc = ptr;
}