#pragma once

#include "NxaSceneDescription.h"
#include "NxaActorDescription.h"
#include "NxaActor.h"
#include "NxaJointDescription.h"
#include "NxaJoint.h"



namespace PhysXCPP {

	public ref class NxaScene
	{
	internal:
		NxScene* scene;
		NxaScene(NxaSceneDescription^ description);

	public:
		property NxaSimulationType SimulationType;

	public:
		!NxaScene(void);

		NxaActor^ CreateActor(NxaActorDescription^ actorDescription);
		NxaJoint^ CreateJoint(NxaJointDescription^ jointDescription);
		void ReleaseActor(NxaActor^ nxaActor);

		void UpdateScene(float deltaTime);
		bool FetchResults(bool block);
		void FlushCaches() { scene->flushCaches(); }
		bool CheckResults(bool block);
	};

}
