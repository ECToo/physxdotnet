#include "StdAfx.h"
#include "NxaJointLimitSoftPairDescription.h"
#include "NxaJointLimitSoftDescription.h"

#include "Nxp.h"
#include "NxJointLimitSoftPairDesc.h"

NxaJointLimitSoftPairDescription::NxaJointLimitSoftPairDescription()
{
	nxDesc = new NxJointLimitSoftPairDesc();
}

NxaJointLimitSoftPairDescription::NxaJointLimitSoftPairDescription(NxJointLimitSoftPairDesc* ptr)
{
	nxDesc = ptr;
}

NxaJointLimitSoftPairDescription::~NxaJointLimitSoftPairDescription()
{
	this->!NxaJointLimitSoftPairDescription();
}

NxaJointLimitSoftPairDescription::!NxaJointLimitSoftPairDescription()
{
	delete nxDesc;
}

void NxaJointLimitSoftPairDescription::SetToDefault()
{
	nxDesc->setToDefault();
}

bool NxaJointLimitSoftPairDescription::IsValid()
{
	return nxDesc->isValid();
}

NxaJointLimitSoftDescription^ NxaJointLimitSoftPairDescription::Low::get()
{
	return gcnew NxaJointLimitSoftDescription(&(nxDesc->low));
}

void NxaJointLimitSoftPairDescription::Low::set(NxaJointLimitSoftDescription^ value)
{
	nxDesc->low = *(value->nxDesc);
}

NxaJointLimitSoftDescription^ NxaJointLimitSoftPairDescription::High::get()
{
	return gcnew NxaJointLimitSoftDescription(&(nxDesc->high));
}

void NxaJointLimitSoftPairDescription::High::set(NxaJointLimitSoftDescription^ value)
{
	nxDesc->high = *(value->nxDesc);
}