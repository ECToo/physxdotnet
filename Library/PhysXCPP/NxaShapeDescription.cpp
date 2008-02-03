#include "StdAfx.h"
#include "NxaShapeDescription.h"
#include "Nxp.h"

#include "NxaBoxShapeDescription.h"
#include "NxaPlaneShapeDescription.h"
#include "NxaSphereShapeDescription.h"

NxaShapeDescription::~NxaShapeDescription()
{
	this->!NxaShapeDescription();
}

NxaShapeDescription::!NxaShapeDescription()
{
	delete nxShapeDesc;
}

void NxaShapeDescription::SetToDefault()
{
	nxShapeDesc->setToDefault();
}

bool NxaShapeDescription::IsValid()
{
	return nxShapeDesc->isValid();
}

NxaShapeDescription^ NxaShapeDescription::CreateFromPointer(NxShapeDesc *ptr)
{
	switch(ptr->getType())
	{
	case NX_SHAPE_SPHERE:
		return gcnew NxaSphereShapeDescription((NxSphereShapeDesc*)ptr);
	case NX_SHAPE_BOX:
		return gcnew NxaBoxShapeDescription((NxBoxShapeDesc*)ptr);
	case NX_SHAPE_PLANE:
		return gcnew NxaPlaneShapeDescription((NxPlaneShapeDesc*)ptr);
	}

	return nullptr;
}

Matrix NxaShapeDescription::LocalPose::get()
{
	NxMat34 pose = nxShapeDesc->localPose;
	NxVec3 row1 = pose.M.getRow(0);
	NxVec3 row2 = pose.M.getRow(1);
	NxVec3 row3 = pose.M.getRow(2);
	NxVec3 pos = pose.t;

	return Matrix(row1.x, row1.y, row1.z, 0, row2.x, row2.y, row2.z, 0, row3.x, row3.y, row3.z, 0, pos.x, pos.y, pos.z, 1);
}

void NxaShapeDescription::LocalPose::set(Matrix m)
{
	NxMat34 pose;
	pose.M.setColumn(0, NxVec3(m.M11, m.M12, m.M13));
	pose.M.setColumn(1, NxVec3(m.M21, m.M22, m.M23));
	pose.M.setColumn(2, NxVec3(m.M31, m.M32, m.M33));
	pose.t.set(NxVec3(m.M41, m.M42, m.M43));

	nxShapeDesc->localPose = pose;
}

NxaU32 NxaShapeDescription::ShapeFlags::get()
{
	return nxShapeDesc->shapeFlags;
}

void NxaShapeDescription::ShapeFlags::set(NxaU32 value)
{
	nxShapeDesc->shapeFlags = value;
}