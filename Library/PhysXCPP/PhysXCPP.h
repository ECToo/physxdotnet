#include "Stdafx.h"
#include "NxaScene.h"
#include "NxaSceneDescription.h"

class NxPhysicsSDK;


public ref class PhysXEngine
{
internal:
	static NxPhysicsSDK* sdk;

public:
	PhysXEngine();

	NxaScene^ CreateScene(NxaSceneDescription^ description);			 
};
