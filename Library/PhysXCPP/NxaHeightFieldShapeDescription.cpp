// completely new file

#include "StdAfx.h"
#include "NxaHeightFieldShapeDescription.h"


NxaHeightFieldShapeDescription::NxaHeightFieldShapeDescription(void)
{
	nxShapeDesc = new NxHeightFieldShapeDesc();
}

NxaHeightFieldShapeDescription::NxaHeightFieldShapeDescription(NxHeightFieldShapeDesc* ptr)
{
	nxShapeDesc = ptr;
}

NxaHeightFieldShapeDescription::!NxaHeightFieldShapeDescription(void)
{
	
}

NxaHeightFieldShapeDescription::~NxaHeightFieldShapeDescription(void)
{
	this->!NxaHeightFieldShapeDescription();
}