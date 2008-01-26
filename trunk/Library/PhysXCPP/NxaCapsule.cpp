#include "StdAfx.h"
#include "NxaCapsule.h"

NxaCapsule::NxaCapsule(void)
{
	nxCapsule = new NxCapsule();
}

NxaCapsule::NxaCapsule(NxaSegment ^seg, float radius)
{
	nxCapsule = new NxCapsule(*(seg->nxSegment), radius);
}

NxaCapsule::~NxaCapsule(void)
{
	this->!NxaCapsule();
}

NxaCapsule::!NxaCapsule(void)
{
	delete nxCapsule;
}

float NxaCapsule::Radius::get()
{
	return nxCapsule->radius;
}

void NxaCapsule::Radius::set(float value)
{
	nxCapsule->radius = value;
}