#include "StdAfx.h"
#include "NxaSpringDescription.h"

NxaSpringDescription::NxaSpringDescription(NxSpringDesc *ptr)
{
	nxSpringDesc = ptr;
}

NxaSpringDescription::NxaSpringDescription(float spring, float damper, float targetValue)
{
	nxSpringDesc = new NxSpringDesc(spring, damper, targetValue);
}

NxaSpringDescription::NxaSpringDescription(float spring, float damper)
{
	nxSpringDesc = new NxSpringDesc(spring, damper);
}

NxaSpringDescription::NxaSpringDescription(float spring)
{
	nxSpringDesc = new NxSpringDesc(spring);
}

NxaSpringDescription::NxaSpringDescription(void)
{
	nxSpringDesc = new NxSpringDesc();
}

NxaSpringDescription::~NxaSpringDescription(void)
{
	this->!NxaSpringDescription();
}

NxaSpringDescription::!NxaSpringDescription(void)
{
	delete nxSpringDesc;
}

float NxaSpringDescription::Spring::get()
{
	return nxSpringDesc->spring;
}

void NxaSpringDescription::Spring::set(float value)
{
	nxSpringDesc->spring = value;
}

float NxaSpringDescription::Damper::get()
{
	return nxSpringDesc->damper;
}

void NxaSpringDescription::Damper::set(float value)
{
	nxSpringDesc->damper = value;
}

float NxaSpringDescription::TargetValue::get()
{
	return nxSpringDesc->targetValue;
}

void NxaSpringDescription::TargetValue::set(float value)
{
	nxSpringDesc->targetValue = value;
}

void NxaSpringDescription::SetToDefault()
{
	nxSpringDesc->setToDefault();
}

bool NxaSpringDescription::IsValid()
{
	return nxSpringDesc->isValid();
}