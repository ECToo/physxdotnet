#include "StdAfx.h"
#include "NxaControllerDescription.h"

NxaControllerDescription::NxaControllerDescription(NxControllerDesc * ptr)
{
	nxControllerDesc = ptr;
}

NxaControllerDescription::~NxaControllerDescription()
{
	this->!NxaControllerDescription();
}

NxaControllerDescription::!NxaControllerDescription()
{
}

void NxaControllerDescription::SetToDefault()
{
	nxControllerDesc->setToDefault();
}

bool NxaControllerDescription::IsValid()
{
	return nxControllerDesc->isValid();
}

Vector3 NxaControllerDescription::Position::get()
{
	return NxaMath::Vector3ExtendedPhysXToXNA(nxControllerDesc->position);
}

void NxaControllerDescription::Position::set(Vector3 value)
{
	nxControllerDesc->position = NxaMath::Vector3XNAToExtendedPhysX(value);
}

float NxaControllerDescription::SlopeLimit::get()
{
	return nxControllerDesc->slopeLimit;
}

void NxaControllerDescription::SlopeLimit::set(float value)
{
	nxControllerDesc->slopeLimit = value;
}

float NxaControllerDescription::SkinWidth::get()
{
	return nxControllerDesc->skinWidth;
}

void NxaControllerDescription::SkinWidth::set(float value)
{
	nxControllerDesc->skinWidth = value;
}

float NxaControllerDescription::StepOffset::get()
{
	return nxControllerDesc->stepOffset;
}

void NxaControllerDescription::StepOffset::set(float value)
{
	nxControllerDesc->stepOffset = value;
}
