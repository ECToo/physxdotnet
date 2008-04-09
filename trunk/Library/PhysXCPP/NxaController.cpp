#include "StdAfx.h"
#include "NxaController.h"
#include "NxaBoxController.h"
#include "NxaCapsuleController.h"
#include "NxContainer.h"

NxaController::NxaController(NxController* ptr)
{
	nxController = ptr;

	NxControllerContainer::GetInstance()->Add(IntPtr(ptr), this);
}

NxaController::~NxaController()
{
	this->!NxaController();
}
NxaController::!NxaController()
{
	NxControllerContainer::GetInstance()->Remove(IntPtr(nxController));
}

NxaController^ NxaController::CreateFromPointer(NxController* ptr)
{
	switch(ptr->getType())
	{
	case NX_CONTROLLER_BOX:		return gcnew NxaBoxController(ptr);
	case NX_CONTROLLER_CAPSULE: return gcnew NxaCapsuleController(ptr);
	}

	return nullptr;
}

void NxaController::SetPosition(Vector3 position)
{
	nxController->setPosition(NxaMath::Vector3XNAToExtendedPhysX(position));
}

Vector3 NxaController::GetPosition()
{
	return NxaMath::Vector3ExtendedPhysXToXNA(nxController->getPosition());
}

Vector3 NxaController::GetFilteredPosition()
{
	return NxaMath::Vector3ExtendedPhysXToXNA(nxController->getFilteredPosition());
}

NxaActor ^ NxaController::GetActor()
{
	return NxActorContainer::GetInstance()->Find(IntPtr(nxController->getActor()));
}

void NxaController::SetStepOffset(float offset)
{
	nxController->setStepOffset(offset);
}

void NxaController::SetCollision(bool enabled)
{
	nxController->setCollision(enabled);
}

void NxaController::ReportSceneChanged()
{
	nxController->reportSceneChanged();
}

void NxaController::Move(Vector3 displacement, NxaU32 activeGroups, float minDistance, [Out]NxaU32% collisionFlags)
{
	Move(displacement, activeGroups, minDistance, collisionFlags, 1);
}

void NxaController::Move(Vector3 displacement, NxaU32 activeGroups, float minDistance, [Out]NxaU32% collisionFlags, float sharpness)
{
	NxU32 flags;

	nxController->move(NxaMath::Vector3XNAToPhysX(displacement), activeGroups, minDistance, flags, sharpness);

	collisionFlags = flags;
}