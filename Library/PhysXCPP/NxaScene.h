#pragma once

class NxScene;

ref class NxaActor;
ref class NxaActorDescription;
ref class NxaJoint;
ref class NxaJointDescription;
ref class NxaMaterial;
ref class NxaContactPair;
ref class NxaShape;
ref class NxaMaterialDescription;

#include "Nxap.h"
#include "NxaSceneDescription.h"
#include "NxScene.h"

public delegate void NxaUserContactDelegate(NxaContactPair ^pair, NxaU32 events);
public delegate void NxaUserTriggerDelegate(NxaShape ^ triggerShape, NxaShape ^ otherShape, NxaTriggerFlag status);

class NxDerivedUserContactReport;
class NxDerivedUserTriggerReport;

public ref class NxaScene
{
private:
	NxDerivedUserContactReport * userContactReport;
	NxDerivedUserTriggerReport * userTriggerReport;

	void InitialiseReporters();

	
internal:
	NxScene* nxScene;
	NxaScene(NxaSceneDescription^ description);

	void FireUserContactReporter(NxaContactPair ^ pair, NxU32 events);
	void FireUserTriggerReporter(NxaShape ^ triggerShape, NxaShape ^ otherShape, NxaTriggerFlag status);

public:
	~NxaScene();
	!NxaScene();

	//-------
	// Actors
	//-------
	NxaActor^ CreateActor(NxaActorDescription^ actorDescription);
	NxaJoint^ CreateJoint(NxaJointDescription^ jointDescription);
	void ReleaseActor(NxaActor^ nxaActor);

	//-------------
	// Enumerations
	//-------------
	NxaU32 GetNbActors();
	array<NxaActor^>^ GetActors();

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
	NxaMaterial^ CreateMaterial(NxaMaterialDescription^ materialDescription);
	void ReleaseMaterial(NxaMaterial^ material);

	//----------
	// Delegates
	//----------
	NxaUserContactDelegate ^ userContactReporter;
	NxaUserTriggerDelegate ^ userTriggerReporter;

	//---------------------------------
	// Collision Filtering and Grouping
	//---------------------------------
	void SetActorPairFlags(NxaActor ^ actorA, NxaActor ^ actorB, NxaU32 contactPairFlag);
	NxaU32 GetActorPairFlags(NxaActor ^ actorA, NxaActor ^ actorB);
	void SetActorGroupPairFlags(NxaActorGroup group1, NxaActorGroup group2, NxU32 contactPairFlag);
	NxaU32 GetActorGroupPairFlags(NxaActorGroup group1, NxaActorGroup group2);
	
	
	property Object ^ UserData
	{
		Object ^ get();
		void set(Object ^);
	};
	
};