#include "Stdafx.h"
#include "PhysXCPP.h"
#include "PhysXloader.h"
#include "NxaScene.h"



NxaScene^ PhysXEngine::CreateScene(NxaSceneDescription^ description)
{
	return gcnew NxaScene(description);
}

PhysXEngine::PhysXEngine()
{
	sdk = NxCreatePhysicsSDK(NX_PHYSICS_SDK_VERSION);
	
	if(!sdk) return;
		sdk->setParameter(NX_SKIN_WIDTH, 0.001f);
}