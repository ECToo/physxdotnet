#include "StdAfx.h"

#include "Nxp.h"
#include "NxJointLimitPairDesc.h"

#include "NxaJointLimitPairDescription.h"

NxaJointLimitPairDescription::NxaJointLimitPairDescription(void)
{
	nxJointLimitPairDesc = new NxJointLimitPairDesc();
}

NxaJointLimitPairDescription::~NxaJointLimitPairDescription(void)
{
	this->!NxaJointLimitPairDescription();
}

NxaJointLimitPairDescription::!NxaJointLimitPairDescription(void)
{
	delete nxJointLimitPairDesc;
}

NxaJointLimitDescription^ NxaJointLimitPairDescription::Low::get()
{
	return gcnew NxaJointLimitDescription(&(nxJointLimitPairDesc->low));
}

void NxaJointLimitPairDescription::Low::set(NxaJointLimitDescription^ value)
{
	nxJointLimitPairDesc->low = *(value->nxJointLimitDesc);
}

NxaJointLimitDescription^ NxaJointLimitPairDescription::High::get()
{
	return gcnew NxaJointLimitDescription(&(nxJointLimitPairDesc->high));
}

void NxaJointLimitPairDescription::High::set(NxaJointLimitDescription^ value)
{
	nxJointLimitPairDesc->high = *(value->nxJointLimitDesc);
}

void NxaJointLimitPairDescription::SetToDefault()
{
	nxJointLimitPairDesc->setToDefault();
}

bool NxaJointLimitPairDescription::IsValid()
{
	return nxJointLimitPairDesc->isValid();
}