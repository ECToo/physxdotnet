#include "StdAfx.h"
#include "NxaSegment.h"

NxaSegment::NxaSegment(void)
{
	nxSegment = new NxSegment();
}

NxaSegment::NxaSegment(Vector3 p0, Vector3 p1)
{
	nxSegment = new NxSegment(NxaMath::Vector3XNAToPhysX(p0), NxaMath::Vector3XNAToPhysX(p1));
}

NxaSegment::NxaSegment(NxaSegment ^seg)
{
	
}

NxaSegment::~NxaSegment(void)
{
	this->!NxaSegment();
}

NxaSegment::!NxaSegment(void)
{
	delete nxSegment;
}

Vector3 NxaSegment::GetOrigin()
{
	return NxaMath::Vector3PhysXToXNA(nxSegment->getOrigin());
}

Vector3 NxaSegment::ComputeDirection()
{
	return NxaMath::Vector3PhysXToXNA(nxSegment->computeDirection());
}

float NxaSegment::ComputeLength()
{
	return nxSegment->computeLength();
}

float NxaSegment::ComputeSquareLength()
{
	return nxSegment->computeSquareLength();
}

void NxaSegment::SetOriginDirection(Vector3 origin, Vector3 direction)
{

}

void NxaSegment::ComputePoint(Vector3 pt, float t)
{

}