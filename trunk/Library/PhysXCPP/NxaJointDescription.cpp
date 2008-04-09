#include "StdAfx.h"
#include "NxaJointDescription.h"
#include "NxJointDesc.h"
#include "NxContainer.h"

void NxaJointDescription::LoadFromNative(NxJointDesc& desc)
{
	for(int i = 0; i < 2; i++)
	{
		Actor[i] = NxActorContainer::GetInstance()->Find(IntPtr(desc.actor[i]));
		LocalAnchor[i] = NxaMath::Vector3PhysXToXNA(desc.localAnchor[i]);
		LocalAxis[i] = NxaMath::Vector3PhysXToXNA(desc.localAxis[i]);
		LocalNormal[i] = NxaMath::Vector3PhysXToXNA(desc.localNormal[i]);
	}
	
	MaxForce = desc.maxForce;
	MaxTorque = desc.maxTorque;
	JointFlags = (NxaJointFlag)desc.jointFlags;
}

void NxaJointDescription::ConvertToNative(NxJointDesc& desc)
{
	desc.actor[0] = Actor[0]->nxActor;
	desc.actor[1] = Actor[1]->nxActor;
	desc.localAnchor[0] = NxaMath::Vector3XNAToPhysX(LocalAnchor[0]);
	desc.localAnchor[1] = NxaMath::Vector3XNAToPhysX(LocalAnchor[1]);
	desc.localAxis[0] = NxaMath::Vector3XNAToPhysX(LocalAxis[0]);
	desc.localAxis[1] = NxaMath::Vector3XNAToPhysX(LocalAxis[1]);
	desc.localNormal[0] = NxaMath::Vector3XNAToPhysX(LocalNormal[0]);
	desc.localNormal[1] = NxaMath::Vector3XNAToPhysX(LocalNormal[1]);
	desc.maxForce = MaxForce;
	desc.maxTorque = MaxTorque;
	desc.jointFlags = (NxU32)JointFlags;
}

NxaJointDescription::NxaJointDescription(NxaJointType type)
{
	jointType = type;

	Actor = gcnew array<NxaActor^>(2);
	LocalAnchor = gcnew array<Vector3>(2);
	LocalAxis = gcnew array<Vector3>(2);
	LocalNormal = gcnew array<Vector3>(2);
}

void NxaJointDescription::SetToDefault()
{
	for(int i = 0; i < 2; i++)
	{
		Actor[i] = nullptr;
		LocalAnchor[i] = Vector3::Zero;
		LocalAxis[i] = Vector3::UnitZ;
		LocalNormal[i] = Vector3::UnitX;
	}

	MaxForce = float::MaxValue;
	MaxTorque = float::MaxValue;
	UserData = nullptr;
	Name = nullptr;
	JointFlags = NxaJointFlag::Visualization;
}

bool NxaJointDescription::IsValid()
{
	if(Actor[0]->nxActor == Actor[1]->nxActor)
		return false;
	if(!(Actor[0]->nxActor || Actor[1]->nxActor))
		return false;

	if(Actor[0]->nxActor && !Actor[0]->IsDynamic())
		return false;
	if(Actor[1]->nxActor && !Actor[1]->IsDynamic())
		return false;

	//Should be no need for JointType check given it is typed.

	for(int i = 0; i < 2; i++)
	{
		if(Math::Abs(LocalAxis[i].LengthSquared() - 1.0f) > 0.1f)
			return false;
		if(Math::Abs(LocalNormal[i].LengthSquared() - 1.0f) > 0.1f)
			return false;

		if(Math::Abs(Vector3::Dot(LocalAxis[i], LocalNormal[i])) > 0.1f)
			return false;
	}

	if(MaxForce <= 0)
		return false;
	if(MaxTorque <= 0)
		return false;

	return true;
}

NxaJointType NxaJointDescription::GetType()
{
	return jointType;
}

void NxaJointDescription::SetGlobalAnchor(Vector3 anchor)
{
	SetGlobalAnchor(0, anchor);
	SetGlobalAnchor(1, anchor);
}

void NxaJointDescription::SetGlobalAxis(Vector3 axis)
{
	SetGlobalAxis(0, axis);
	SetGlobalAxis(1, axis);
}

void NxaJointDescription::SetGlobalAnchor(int index, Vector3 worldAnchor)
{
	if(index < 0 || index > 1)
		throw gcnew IndexOutOfRangeException("Index = " + index + ". 0 or 1 allowed.");
	if(Actor[index] == nullptr)
		throw gcnew NullReferenceException("Actor " + index + " is null.");

	LocalAnchor[index] = Vector3::Transform(worldAnchor - Actor[index]->GetGlobalPosition(), Actor[index]->GetGlobalOrientation());
}
	
void NxaJointDescription::SetGlobalAxis(int index, Vector3 worldAxis)
{
	if(index < 0 || index > 1)
		throw gcnew IndexOutOfRangeException("Index = " + index + ". 0 or 1 allowed.");
	if(Actor[index] == nullptr)
		throw gcnew NullReferenceException("Actor " + index + " is null.");

	worldAxis.Normalize();

	LocalAxis[index] = NxaMath::TransformWorldNormalToLocal(Actor[index]->GetGlobalOrientation(), worldAxis);
	LocalNormal[index] = NxaMath::GetPerpendicularVector(LocalAxis[index]);
}