#include "StdAfx.h"
#include "NxaMaterialDescription.h"

using namespace PhysXCPP;

NxaMaterialDescription::NxaMaterialDescription(void)
{
	nxMaterialDesc = new NxMaterialDesc();
}

NxaMaterialDescription::~NxaMaterialDescription(void)
{

}

NxaMaterialDescription::!NxaMaterialDescription(void)
{

}

Vector3 NxaMaterialDescription::DirectionOfAnisotropy::get()
{
	NxVec3 vec = nxMaterialDesc->dirOfAnisotropy;
	return Vector3(vec.x, vec.y, vec.z);
}
