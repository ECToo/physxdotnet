#include "StdAfx.h"
#include "NxPhysics.h"
#include "NxaCapsuleShapeDescription.h"

using namespace PhysXCPP;

NxaCapsuleShapeDescription::NxaCapsuleShapeDescription(void)
{
	nxShapeDesc = new NxCapsuleShapeDesc();
}

NxaCapsuleShapeDescription::~NxaCapsuleShapeDescription(void)
{

}

NxaCapsuleShapeDescription::!NxaCapsuleShapeDescription(void)
{

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