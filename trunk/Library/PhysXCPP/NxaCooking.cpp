#include "StdAfx.h"

#include "NxaCooking.h"

#include "PhysXLoader.h"
#include "NxCooking.h"

bool NxaCooking::InitialiseCooking()
{
	return NxGetCookingLib(NX_PHYSICS_SDK_VERSION)->NxInitCooking();
}

void NxaCooking::CloseCooking()
{
	NxGetCookingLib(NX_PHYSICS_SDK_VERSION)->NxCloseCooking();
}