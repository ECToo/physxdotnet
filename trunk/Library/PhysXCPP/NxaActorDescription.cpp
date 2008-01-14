#include "StdAfx.h"
#include "NxaActorDescription.h"
#include "NxaBodyDescription.h"
#include "NxaShapeDescription.h"
#include "NxPhysics.h"

using namespace PhysXCPP;

NxaActorDescription::NxaActorDescription(void)
{
	nxActorDesc = new NxActorDesc();
}

NxaActorDescription::!NxaActorDescription(void)
{

}

void NxaActorDescription::AddShape(NxaShapeDescription^ description)
{
	NxShapeDesc* ptr = description->nxShapeDesc;
	nxActorDesc->shapes.pushBack(ptr);	
}

void NxaActorDescription::Body::set(NxaBodyDescription^ body)
{
	nxActorDesc->body = body->nxBodyDesc;
}

void NxaActorDescription::GlobalPose::set(Matrix m)
{
	nxActorDesc->globalPose.M.setColumn(0, NxVec3(m.M11, m.M12, m.M13));
	nxActorDesc->globalPose.M.setColumn(1, NxVec3(m.M21, m.M22, m.M23));
	nxActorDesc->globalPose.M.setColumn(2, NxVec3(m.M31, m.M32, m.M33));
	nxActorDesc->globalPose.t.set(NxVec3(m.M41, m.M42, m.M43));
}

void NxaActorDescription::Density::set(float density)
{
	nxActorDesc->density = density;
}

array<NxaShapeDescription^>^ NxaActorDescription::Shapes::get()
{
	NxArray<NxShapeDesc*, NxAllocatorDefault> ptrs = nxActorDesc->shapes;
	int size = ptrs.size();
	array<NxaShapeDescription^>^ shapeDescs = gcnew array<NxaShapeDescription^>(size);

	for(int p = 0; p < size; p++)
	{
		shapeDescs[p] = NxaShapeDescription::CreateFromPointer(ptrs[p]);
	}

	return shapeDescs;
}