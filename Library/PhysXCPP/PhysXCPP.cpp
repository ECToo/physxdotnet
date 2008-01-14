// This is the main DLL file.

#include "stdafx.h"
#include "NxaSceneDescription.h"
#include "PhysXCPP.h"

using namespace PhysXCPP;

NxaScene^ PhysXEngine::CreateScene(NxaSceneDescription^ description)
{
	return gcnew NxaScene(description);
}

PhysXEngine::PhysXEngine()
{
	sdk = NxCreatePhysicsSDK(NX_PHYSICS_SDK_VERSION);
	
	if(!sdk) return;
	sdk->setParameter(NX_SKIN_WIDTH, 0.001);
}



