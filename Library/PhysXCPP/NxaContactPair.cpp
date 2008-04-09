// completely new file

#include "StdAfx.h"
#include "NxaContactPair.h"
#include "NxaActor.h"
#include "NxContainer.h"

NxaContactPair::NxaContactPair(NxContactPair * contactPair)
{
	nxContactPair = contactPair;
}


NxaContactPair::~NxaContactPair()
{
	this->!NxaContactPair();
}

NxaContactPair::!NxaContactPair()
{
}

array<NxaActor^> ^ NxaContactPair::Actors::get()
{
	array<NxaActor^> ^ actors = gcnew array<NxaActor^>(2);

	for(int i = 0; i < 2; i++)
		actors[i] = NxActorContainer::GetInstance()->Find(IntPtr(nxContactPair->actors[i]));

	return actors;
}

Vector3 NxaContactPair::SumNormalForce::get()
{
	return NxaMath::Vector3PhysXToXNA(nxContactPair->sumNormalForce);
}

Vector3 NxaContactPair::SumFrictionForce::get()
{
	return NxaMath::Vector3PhysXToXNA(nxContactPair->sumFrictionForce);
}
