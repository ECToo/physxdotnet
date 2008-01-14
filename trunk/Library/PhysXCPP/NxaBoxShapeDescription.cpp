#include "StdAfx.h"
#include "NxaBoxShapeDescription.h"
#include "NxPhysics.h"

using namespace PhysXCPP;
using namespace Microsoft::Xna::Framework;

NxaBoxShapeDescription::NxaBoxShapeDescription(void)
{
	nxShapeDesc = new NxBoxShapeDesc();
}

NxaBoxShapeDescription::NxaBoxShapeDescription(NxBoxShapeDesc* ptr)
{
	nxShapeDesc = ptr;
}

NxaBoxShapeDescription::!NxaBoxShapeDescription(void)
{

}

Vector3 NxaBoxShapeDescription::Dimensions::get()
{
	NxVec3 dimensions = ((NxBoxShapeDesc*)nxShapeDesc)->dimensions;
	return Vector3(dimensions.x, dimensions.y, dimensions.z);
}

void NxaBoxShapeDescription::Dimensions::set(Vector3 dimensions)
{
	NxBoxShapeDesc* boxDesc = (NxBoxShapeDesc*)nxShapeDesc;
	boxDesc->dimensions.x = dimensions.X;
	boxDesc->dimensions.y = dimensions.Y;
	boxDesc->dimensions.z = dimensions.Z;
	
}
