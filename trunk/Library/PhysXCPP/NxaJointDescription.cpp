#include "StdAfx.h"
#include "NxaJointDescription.h"

NxaJointDescription::NxaJointDescription(NxJointDesc *ptr)
{
	nxJointDesc = ptr;
}

NxaJointDescription::NxaJointDescription(void)
{ }

NxaJointDescription::~NxaJointDescription(void)
{
	this->!NxaJointDescription();
}

NxaJointDescription::!NxaJointDescription(void)
{
	delete nxJointDesc;
}

NxaActor^ NxaJointDescription::Actor::get(int x)
{
	return gcnew NxaActor(nxJointDesc->actor[x]); 
}

void NxaJointDescription::Actor::set(int x, NxaActor^ value)
{
	nxJointDesc->actor[x] = value->nxActor;
}

Vector3 NxaJointDescription::LocalAnchor::get(int x)
{
	NxVec3 vec = nxJointDesc->localAnchor[x];
	return NxaMath::Vector3PhysXToXNA(vec);
}

void NxaJointDescription::LocalAnchor::set(int x, Vector3 value)
{
	nxJointDesc->localAnchor[x] = NxaMath::Vector3XNAToPhysX(value);
}

Vector3 NxaJointDescription::LocalAxis::get(int x)
{
	NxVec3 vec = nxJointDesc->localAxis[x];
	return NxaMath::Vector3PhysXToXNA(vec);
}

void NxaJointDescription::LocalAxis::set(int x, Vector3 value)
{
	nxJointDesc->localAxis[x] = NxaMath::Vector3XNAToPhysX(value);
}

Vector3 NxaJointDescription::LocalNormal::get(int x)
{
	NxVec3 vec = nxJointDesc->localNormal[x];
	return NxaMath::Vector3PhysXToXNA(vec);
}

void NxaJointDescription::LocalNormal::set(int x, Vector3 value)
{
	nxJointDesc->localNormal[x] = NxaMath::Vector3XNAToPhysX(value);
}

void NxaJointDescription::SetGlobalAnchor(Vector3 anchor)
{
	nxJointDesc->setGlobalAnchor(NxaMath::Vector3XNAToPhysX(anchor));
}

void NxaJointDescription::SetGlobalAxis(Vector3 axis)
{
	nxJointDesc->setGlobalAxis(NxaMath::Vector3XNAToPhysX(axis));
}

void NxaJointDescription::RaiseJointFlag(NxaJointFlag flag)
{
	if((int)flag && (int)NxaJointFlag::Collision_Enabled)
		nxJointDesc->jointFlags = nxJointDesc->jointFlags | NX_JF_COLLISION_ENABLED;
}

void NxaJointDescription::ClearJointFlag(NxaJointFlag flag)
{
	if((int)flag && (int)NxaJointFlag::Collision_Enabled)
		nxJointDesc->jointFlags = nxJointDesc->jointFlags & ~NX_JF_COLLISION_ENABLED;
}

float NxaJointDescription::MaxForce::get()
{
	return nxJointDesc->maxForce;
}

void NxaJointDescription::MaxForce::set(float max)
{
	nxJointDesc->maxForce = max;
}

float NxaJointDescription::MaxTorque::get()
{
	return nxJointDesc->maxTorque;
}

void NxaJointDescription::MaxTorque::set(float max)
{
	nxJointDesc->maxTorque = max;
}

	