#include "Stdafx.h"
#include "NxaScene.h"
#include "NxaSceneDescription.h"

class NxPhysicsSDK;
ref class NxaHeightField;
ref class NxaHeightFieldDescription;


public ref class PhysXEngine
{
internal:
	static NxPhysicsSDK* sdk = 0;

public:
	PhysXEngine();
	~PhysXEngine();
	!PhysXEngine();

	//-----
	//Scene
	//-----
	NxaScene^ CreateScene(NxaSceneDescription^ description);

	//---------
	//Heightmap
	//---------
	NxaHeightField^ CreateHeightField(NxaHeightFieldDescription ^ description);
};
