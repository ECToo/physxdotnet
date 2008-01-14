// PhysXCPP.h

#pragma once


#include "NxPhysics.h"
#include "NxaSceneDescription.h"
#include "NxaScene.h"

using namespace PhysXCPP;
using namespace System;
using namespace Microsoft::Xna::Framework;

namespace PhysXCPP {

	public ref class PhysXEngine
	{

	internal:
		static NxPhysicsSDK* sdk = NULL;

	public:
		PhysXEngine();

		NxaScene^ CreateScene(NxaSceneDescription^ description);			 
	};
}
