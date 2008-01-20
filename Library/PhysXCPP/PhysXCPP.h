#include "Stdafx.h"
#include "NxaScene.h";

class NxPhysicsSDK;
#include "NxaSceneDescription.h";

public ref class PhysXEngine
{
internal:
	static NxPhysicsSDK* sdk;

public:
	PhysXEngine();

	NxaScene^ CreateScene(NxaSceneDescription^ description);			 
};
