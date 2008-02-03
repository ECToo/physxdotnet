#pragma once

class NxScene;

ref class NxaActor;
ref class NxaActorDescription;
ref class NxaJoint;
ref class NxaJointDescription;
ref class NxaMaterial;

#include "Nxap.h"
#include "NxaSceneDescription.h"

public ref class NxaScene
{
internal:
	NxScene* nxScene;
	NxaScene(NxScene* ptr);
	NxaScene(NxaSceneDescription^ description);

public:
	NxaActor^ CreateActor(NxaActorDescription^ actorDescription);
	NxaJoint^ CreateJoint(NxaJointDescription^ jointDescription);
	void ReleaseActor(NxaActor^ nxaActor);

	void UpdateScene(float deltaTime);
	bool FetchResults(bool block);
	void FlushCaches();
	bool CheckResults(bool block);

	//----------
	// Materials
	//----------

	NxaMaterial^ GetMaterialFromIndex(NxaMaterialIndex matIndex);
};