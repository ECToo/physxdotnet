#include "StdAfx.h"
#include "NxaBoxControllerDescription.h"

NxaBoxControllerDescription::NxaBoxControllerDescription(void)
	: NxaControllerDescription(new NxBoxControllerDesc())
{
}

Vector3 NxaBoxControllerDescription::Extents::get()
{
	return NxaMath::Vector3PhysXToXNA(((NxBoxControllerDesc*)nxControllerDesc)->extents);
}

void NxaBoxControllerDescription::Extents::set(Vector3 value)
{
	(((NxBoxControllerDesc*)nxControllerDesc)->extents) = NxaMath::Vector3XNAToPhysX(value);
}
