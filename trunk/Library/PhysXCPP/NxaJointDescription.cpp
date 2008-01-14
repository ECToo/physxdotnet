#include "StdAfx.h"
#include "NxaJointDescription.h"
#include "NxaActor.h"

using namespace PhysXCPP;
using namespace System::Collections;

NxaJointDescription::NxaJointDescription(void)
{
	actors = gcnew array<NxaActor^>(2);
}

NxaJointDescription::!NxaJointDescription(void)
{
	delete nxJointDesc;
}

Vector3 PhysXCPP::NxaJointDescription::LocalAnchor::get(int x)
{
	NxVec3 vec = nxJointDesc->localAnchor[x];
	return Vector3(vec.x, vec.y, vec.z);
}

void NxaJointDescription::LocalAnchor::set(int x, Vector3 value)
{
	nxJointDesc->localAnchor[x] = NxVec3(value.X, value.Y, value.Z);
}

Vector3 NxaJointDescription::LocalAxis::get(int x)
{
	NxVec3 vec = nxJointDesc->localAxis[x];
	return Vector3(vec.x, vec.y, vec.z);
}

void NxaJointDescription::LocalAxis::set(int x, Vector3 value)
{
	nxJointDesc->localAxis[x] = NxVec3(value.X, value.Y, value.Z);
}

Vector3 NxaJointDescription::LocalNormal::get(int x)
{
	NxVec3 vec = nxJointDesc->localNormal[x];
	return Vector3(vec.x, vec.y, vec.z);
}

void NxaJointDescription::LocalNormal::set(int x, Vector3 value)
{
	nxJointDesc->localNormal[x] = NxVec3(value.X, value.Y, value.Z);
}

void PhysXCPP::NxaJointDescription::SetGlobalAnchor(Vector3 anchor)
{
	nxJointDesc->setGlobalAnchor(NxVec3(anchor.X, anchor.Y, anchor.Z));
}

void PhysXCPP::NxaJointDescription::SetGlobalAxis(Microsoft::Xna::Framework::Vector3 axis)
{
	nxJointDesc->setGlobalAxis(NxVec3(axis.X, axis.Y, axis.Z));
}

void PhysXCPP::NxaJointDescription::RaiseJointFlag(NxaJointFlag flag)
{
	if((int)flag && (int)NxaJointFlag::Collision_Enabled)
		nxJointDesc->jointFlags = nxJointDesc->jointFlags | NX_JF_COLLISION_ENABLED;
}

void PhysXCPP::NxaJointDescription::ClearJointFlag(NxaJointFlag flag)
{
	if((int)flag && (int)NxaJointFlag::Collision_Enabled)
		nxJointDesc->jointFlags = nxJointDesc->jointFlags & ~NX_JF_COLLISION_ENABLED;
}

	