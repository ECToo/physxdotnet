#pragma once

class NxScene;

ref class NxaActor;
ref class NxaActorDescription;
ref class NxaJoint;
ref class NxaJointDescription;
ref class NxaMaterial;

#include "Nxap.h"
#include "NxaSceneDescription.h"
#include "NxaUserContactReport.h"
#include "NxaUserTriggerReport.h"

public ref class NxaScene
{
private:
	NxDerivedUserContactReport * userContactReport;
	NxDerivedUserTriggerReport * userTriggerReport;

internal:
	NxScene* nxScene;
	NxaScene(NxScene* ptr);
	NxaScene(NxaSceneDescription^ description);

public:
	~NxaScene();
	!NxaScene();

	//-------
	// Actors
	//-------
	NxaActor^ CreateActor(NxaActorDescription^ actorDescription);
	NxaJoint^ CreateJoint(NxaJointDescription^ jointDescription);
	void ReleaseActor(NxaActor^ nxaActor);

	//-------
	// Update
	//-------
	void UpdateScene(float deltaTime);
	bool FetchResults(bool block);
	void FlushCaches();
	bool CheckResults(bool block);

	//----------
	// Materials
	//----------
	NxaMaterial^ GetMaterialFromIndex(NxaMaterialIndex matIndex);

	//----------
	// Callbacks
	//----------
	void SetUserContactReport(NxaUserContactDelegate ^ callback);
	void SetUserTriggerReport(NxaUserTriggerDelegate ^ callback);

	//---------------------------------
	// Collision Filtering and Grouping
	//---------------------------------
	void SetActorPairFlags(NxaActor ^ actorA, NxaActor ^ actorB, NxaU32 contactPairFlag);
	NxaU32 GetActorPairFlags(NxaActor ^ actorA, NxaActor ^ actorB);
	void SetActorGroupPairFlags(NxaActorGroup group1, NxaActorGroup group2, NxU32 contactPairFlag);
	NxaU32 GetActorGroupPairFlags(NxaActorGroup group1, NxaActorGroup group2);
	
	
};