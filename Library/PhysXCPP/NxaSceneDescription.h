#pragma once

#include "Nxap.h"

using namespace Microsoft::Xna::Framework;

namespace PhysXCPP 
{

	public ref class NxaSceneDescription
	{

	public:
		property Vector3 Gravity;
		property NxaSimulationType SimulationType;
		property bool EnableRemoteDebugger;
		
		NxaSceneDescription(void);
		!NxaSceneDescription(void);
	};

}