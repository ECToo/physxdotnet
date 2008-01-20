#pragma once

class NxScene;

ref class NxaActor;
ref class NxaActorDescription;
ref class NxaJoint;
ref class NxaJointDescription;

#include "Nxap.h"
#include "NxaSceneDescription.h"

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
	void FlushCaches();
	bool CheckResults(bool block);
};