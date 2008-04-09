#include "StdAfx.h"
#include "NxaBoxController.h"

NxaBoxController::NxaBoxController(NxController* ptr) : NxaController(ptr)
{
}

Vector3 NxaBoxController::GetExtents()
{
	return NxaMath::Vector3PhysXToXNA(((NxBoxController*)nxController)->getExtents());
}

void NxaBoxController::SetExtents(Vector3 extents)
{
	((NxBoxController *)nxController)->setExtents(NxaMath::Vector3XNAToPhysX(extents));
}
