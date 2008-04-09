#include "StdAfx.h"
#include "NxaActorDescription.h"

#include "NxArray.h"
#include "NxActorDesc.h"


NxaActorDescription::NxaActorDescription(void)
{
	nxActorDesc = new NxActorDesc();

	arShapeDescriptions = gcnew List<NxaShapeDescription ^>();
	nxaBodyDescription = nullptr;
}

NxaActorDescription::~NxaActorDescription(void)
{
	this->!NxaActorDescription();
}

NxaActorDescription::!NxaActorDescription(void)
{
	delete nxActorDesc;
	arShapeDescriptions->Clear();
}

void NxaActorDescription::SetToDefault()
{
	nxActorDesc->setToDefault();
}

bool NxaActorDescription::IsValid()
{
	return nxActorDesc->isValid();
}

void NxaActorDescription::AddShape(NxaShapeDescription^ description)
{
	arShapeDescriptions->Add(description);

	NxShapeDesc* ptr = description->nxShapeDesc;
	nxActorDesc->shapes.pushBack(ptr);	
}

void NxaActorDescription::Body::set(NxaBodyDescription^ body)
{
	nxaBodyDescription = body;
	nxActorDesc->body = body->nxBodyDesc;
}

NxaBodyDescription ^ NxaActorDescription::Body::get()
{
	return nxaBodyDescription;
}

void NxaActorDescription::GlobalPose::set(Matrix m)
{
	nxActorDesc->globalPose.M.setColumn(0, NxVec3(m.M11, m.M12, m.M13));
	nxActorDesc->globalPose.M.setColumn(1, NxVec3(m.M21, m.M22, m.M23));
	nxActorDesc->globalPose.M.setColumn(2, NxVec3(m.M31, m.M32, m.M33));
	nxActorDesc->globalPose.t.set(NxVec3(m.M41, m.M42, m.M43));
}

float NxaActorDescription::Density::get()
{
   return nxActorDesc->density;
}

void NxaActorDescription::Density::set(float density)
{
	nxActorDesc->density = density;
}

array<NxaShapeDescription^>^ NxaActorDescription::Shapes::get()
{
	return arShapeDescriptions->ToArray();
}

NxaActorGroup NxaActorDescription::Group::get()
{
	return nxActorDesc->group;
}

void NxaActorDescription::Group::set(NxaActorGroup value)
{
	nxActorDesc->group = value;
}