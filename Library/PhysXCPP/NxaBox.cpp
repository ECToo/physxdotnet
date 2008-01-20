#include "StdAfx.h"
#include "NxaBox.h"

NxaBox::NxaBox()
{
	nxBox = new NxBox();
}

NxaBox::NxaBox(Vector3 center, Vector3 extents, Matrix rotation)
{
	nxBox = new NxBox(NxVec3(center.X, center.Y, center.Z), 
						NxVec3(extents.X, extents.Y, extents.Z), 
						NxaMath::MatrixRotXNAToPhysX(rotation));
}

NxaBox::!NxaBox(void)
{

}

void NxaBox::SetEmpty()
{
	nxBox->setEmpty();
}

inline bool NxaBox::IsValid()
{
	return nxBox->isValid();
}