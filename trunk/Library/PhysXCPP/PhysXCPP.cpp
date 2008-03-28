#include "Stdafx.h"
#include "PhysXCPP.h"
#include "PhysXloader.h"
#include "NxaScene.h"
#include "NxaHeightField.h"

PhysXEngine::PhysXEngine()
{
	if(sdk != 0)
		return;

	sdk = NxCreatePhysicsSDK(NX_PHYSICS_SDK_VERSION);
	
	if(!sdk) 
		throw gcnew Exception("Unable to load PhysXEngine");
		
	sdk->setParameter(NX_SKIN_WIDTH, 0.001f);
}

PhysXEngine::~PhysXEngine()
{
}

PhysXEngine::!PhysXEngine()
{
}

NxaHeightField^ PhysXEngine::CreateHeightField(NxaHeightFieldDescription ^description)
{
	return gcnew NxaHeightField(description);
}

NxaScene^ PhysXEngine::CreateScene(NxaSceneDescription^ description)
{
	return gcnew NxaScene(description);
}
