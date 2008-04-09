#include "StdAfx.h"
#include "NxaBodyDescription.h"

NxaBodyDescription::NxaBodyDescription(void)
{
	nxBodyDesc = new NxBodyDesc();
}

NxaBodyDescription::~NxaBodyDescription()
{
	this->!NxaBodyDescription();
}

NxaBodyDescription::!NxaBodyDescription()
{
	delete nxBodyDesc;
}

bool NxaBodyDescription::IsValid()
{
	return nxBodyDesc->isValid();
}

void NxaBodyDescription::SetToDefault()
{
	nxBodyDesc->setToDefault();
}

Matrix NxaBodyDescription::MassLocalPose::get()
{
	return NxaMath::MatrixPhysXToXNA(nxBodyDesc->massLocalPose);
}
void NxaBodyDescription::MassLocalPose::set(Matrix value)
{
	nxBodyDesc->massLocalPose = NxaMath::MatrixRotPosXNAToPhysX(value);
}
Vector3 NxaBodyDescription::MassSpaceInertia::get()
{
	return NxaMath::Vector3PhysXToXNA(nxBodyDesc->massSpaceInertia);
}
void NxaBodyDescription::MassSpaceInertia::set(Vector3 value)
{
	nxBodyDesc->massSpaceInertia = NxaMath::Vector3XNAToPhysX(value);
}
Vector3 NxaBodyDescription::LinearVelocity::get()
{
	return NxaMath::Vector3PhysXToXNA(nxBodyDesc->linearVelocity);
}
void NxaBodyDescription::LinearVelocity::set(Vector3 value)
{
	nxBodyDesc->linearVelocity = NxaMath::Vector3XNAToPhysX(value);
}
Vector3 NxaBodyDescription::AngularVelocity::get()
{
	return NxaMath::Vector3PhysXToXNA(nxBodyDesc->angularVelocity);
}
void NxaBodyDescription::AngularVelocity::set(Vector3 value)
{
	nxBodyDesc->angularVelocity = NxaMath::Vector3XNAToPhysX(value);
}
float NxaBodyDescription::Mass::get()
{
	return nxBodyDesc->mass;
}
void NxaBodyDescription::Mass::set(float value)
{
	nxBodyDesc->mass = value;
}
float NxaBodyDescription::WakeUpCounter::get()
{
	return nxBodyDesc->wakeUpCounter;
}
void NxaBodyDescription::WakeUpCounter::set(float value)
{
	nxBodyDesc->wakeUpCounter = value;
}
float NxaBodyDescription::LinearDamping::get()
{
	return nxBodyDesc->linearDamping;
}
void NxaBodyDescription::LinearDamping::set(float value)
{
	nxBodyDesc->linearDamping = value;
}
float NxaBodyDescription::AngularDamping::get()
{
	return nxBodyDesc->angularDamping;
}
void NxaBodyDescription::AngularDamping::set(float value)
{
	nxBodyDesc->angularDamping = value;
}
float NxaBodyDescription::MaxAngularVelocity::get()
{
	return nxBodyDesc->maxAngularVelocity;
}
void NxaBodyDescription::MaxAngularVelocity::set(float value)
{
	nxBodyDesc->maxAngularVelocity = value;
}
float NxaBodyDescription::SleepLinearVelocity::get()
{
	return nxBodyDesc->sleepLinearVelocity;
}
void NxaBodyDescription::SleepLinearVelocity::set(float value)
{
	nxBodyDesc->sleepLinearVelocity = value;
}
float NxaBodyDescription::SleepAngularVelocity::get()
{
	return nxBodyDesc->sleepAngularVelocity;
}
void NxaBodyDescription::SleepAngularVelocity::set(float value)
{
	nxBodyDesc->sleepAngularVelocity = value;
}
float NxaBodyDescription::SleepDaming::get()
{
	return nxBodyDesc->sleepDamping;
}
void NxaBodyDescription::SleepDaming::set(float value)
{
	nxBodyDesc->sleepDamping = value;
}
NxaU32 NxaBodyDescription::BodyFlags::get()
{
	return nxBodyDesc->flags;
}
void NxaBodyDescription::BodyFlags::set(NxaU32 value)
{
	nxBodyDesc->flags = value;
}
