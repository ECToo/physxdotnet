#include "StdAfx.h"
#include "NxaCapsuleShapeDescription.h"



NxaCapsuleShapeDescription::NxaCapsuleShapeDescription(void)
{
	nxShapeDesc = new NxCapsuleShapeDesc();
}

NxaCapsuleShapeDescription::NxaCapsuleShapeDescription(NxCapsuleShapeDesc* ptr)
{
	nxShapeDesc = ptr;
}

void NxaCapsuleShapeDescription::Radius::set(float value)
{
	NxCapsuleShapeDesc* capsuleDesc = (NxCapsuleShapeDesc*)nxShapeDesc;
	capsuleDesc->radius = value;
}

void NxaCapsuleShapeDescription::Height::set(float value)
{
	NxCapsuleShapeDesc* capsuleDesc = (NxCapsuleShapeDesc*)nxShapeDesc;
	capsuleDesc->height = value;
}