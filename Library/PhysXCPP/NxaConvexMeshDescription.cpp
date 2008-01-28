#include "StdAfx.h"
#include "NxaConvexMeshDescription.h"

NxaConvexMeshDescription::NxaConvexMeshDescription()
{
	nxConvexMeshDesc = new NxConvexMeshDesc();
	nxConvexMeshDesc->pointStrideBytes = 12;
	nxConvexMeshDesc->triangleStrideBytes = 12;
}

NxaConvexMeshDescription::~NxaConvexMeshDescription()
{
	this->!NxaConvexMeshDescription();
}

NxaConvexMeshDescription::!NxaConvexMeshDescription()
{
	delete nxConvexMeshDesc;
}

NxaU32 NxaConvexMeshDescription::NumVertices::get()
{
	return nxConvexMeshDesc->numVertices;
}

void NxaConvexMeshDescription::NumVertices::set(NxaU32 value)
{
	nxConvexMeshDesc->numVertices = value;
}

NxaU32 NxaConvexMeshDescription::NumTriangles::get()
{
	return nxConvexMeshDesc->numTriangles;
}

NxaU32 NxaConvexMeshDescription::PointStrideBytes::get()
{
	return nxConvexMeshDesc->pointStrideBytes;
}

NxaU32 NxaConvexMeshDescription::TriangleStrideBytes::get()
{
	return nxConvexMeshDesc->triangleStrideBytes;
}

array<Vector3>^ NxaConvexMeshDescription::Points::get()
{
	return pointArray;
}

void NxaConvexMeshDescription::Points::set(array<Vector3>^ vectorArray)
{
	pointArray = vectorArray;
	NumVertices = vectorArray->Length;
}

NxaConvexFlags NxaConvexMeshDescription::Flags::get()
{
	return (NxaConvexFlags)nxConvexMeshDesc->flags;
}

void NxaConvexMeshDescription::Flags::set(NxaConvexFlags value)
{
	nxConvexMeshDesc->flags = (NxU32)value;
}