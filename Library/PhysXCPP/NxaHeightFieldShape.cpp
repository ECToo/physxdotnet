// completely new file

#include "StdAfx.h"
#include "NxaHeightFieldShape.h"
#include "NxaHeightField.h"
#include "NxHeightFieldShape.h"
#include "NxaHeightFieldShapeDescription.h"

NxaHeightFieldShape::NxaHeightFieldShape(NxShape * ptr)
: NxaShape(ptr)
{
}

float NxaHeightFieldShape::GetColumnScale()
{
	return ((NxHeightFieldShape*)nxShape)->getColumnScale();
}

float NxaHeightFieldShape::GetRowScale()
{
	return ((NxHeightFieldShape*)nxShape)->getRowScale();
}

float NxaHeightFieldShape::GetHeightScale()
{
	return ((NxHeightFieldShape*)nxShape)->getHeightScale();
}

void NxaHeightFieldShape::SetColumnScale(float scale)
{
	((NxHeightFieldShape*)nxShape)->setColumnScale(scale);
}

void NxaHeightFieldShape::SetRowScale(float scale)
{
	((NxHeightFieldShape*)nxShape)->setRowScale(scale);
}

void NxaHeightFieldShape::SetHeightScale(float scale)
{
	((NxHeightFieldShape*)nxShape)->setHeightScale(scale);
}

NxaHeightField ^ NxaHeightFieldShape::GetHeightField()
{
	return gcnew NxaHeightField(&((NxHeightFieldShape*)nxShape)->getHeightField());
}

float NxaHeightFieldShape::GetHeightAtShapePoint(float x, float z)
{
	return ((NxHeightFieldShape*)nxShape)->getHeightAtShapePoint(x,z);
}

NxaMaterialIndex NxaHeightFieldShape::GetMaterialAtShapePoint(float x, float z)
{
	return ((NxHeightFieldShape*)nxShape)->getMaterialAtShapePoint(x,z);
}
Vector3 NxaHeightFieldShape::GetNormalAtShapePoint(float x, float z)
{
	return NxaMath::Vector3PhysXToXNA(((NxHeightFieldShape*)nxShape)->getNormalAtShapePoint(x,z));
}

Vector3 NxaHeightFieldShape::GetSmoothNormalAtShapePoint(float x, float z)
{
	return NxaMath::Vector3PhysXToXNA(((NxHeightFieldShape*)nxShape)->getSmoothNormalAtShapePoint(x,z));
}

bool NxaHeightFieldShape::IsShapePointOnHeightField(float x, float z)
{
	return ((NxHeightFieldShape*)nxShape)->isShapePointOnHeightField(x,z);
}
void NxaHeightFieldShape::SaveToDescription(NxaHeightFieldShapeDescription ^% description)
{
	((NxHeightFieldShape*)nxShape)->saveToDesc(*(NxHeightFieldShapeDesc*)(description->nxShapeDesc));
}


