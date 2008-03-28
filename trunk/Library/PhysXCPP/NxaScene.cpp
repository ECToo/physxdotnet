#include "StdAfx.h"

#include "PhysXCPP.h"
#include "NxFoundationSDK.h"
#include "NxaScene.h"
#include "NxaActor.h"
#include "NxaFixedJoint.h"
#include "NxaActorDescription.h"
#include "NxaJointDescription.h"
#include "NxaMaterial.h"
#include "NxaUserContactReport.h"
#include "NxaUserTriggerReport.h"
#include "NxSceneDesc.h"
#include "NxRemoteDebugger.h"

NxaScene::NxaScene(NxScene* ptr)
{
	nxScene = ptr;

	InitialiseReporters();
}

NxaScene::NxaScene(NxaSceneDescription^ desc)
{
	nxScene = PhysXEngine::sdk->createScene(*(desc->nxSceneDesc));

	if(!nxScene)
	{
		desc->SimulationType = NxaSimulationType::Software;
		nxScene = PhysXEngine::sdk->createScene(*(desc->nxSceneDesc));

		if(!nxScene)
			return;
	}

	if(desc->EnableRemoteDebugger)
		PhysXEngine::sdk->getFoundationSDK().getRemoteDebugger()->connect("localhost", 5425);

	NxMaterial* defaultMaterial = nxScene->getMaterialFromIndex(0);
	defaultMaterial->setRestitution(0.5);
	defaultMaterial->setStaticFriction(0.5);
	defaultMaterial->setDynamicFriction(0.5);

	InitialiseReporters();
}

NxaScene::~NxaScene()
{
	this->!NxaScene();
}

NxaScene::!NxaScene()
{
	if(userContactReport != 0)
	{
		delete userContactReport;
		userContactReport = 0;
	}

	if(userTriggerReport != 0)
	{
		delete userTriggerReport;
		userTriggerReport = 0;
	}
}


NxaActor^ NxaScene::CreateActor(NxaActorDescription^ actorDescription)
{
	NxActor* nxActor = nxScene->createActor(*(actorDescription->nxActorDesc));
	return gcnew NxaActor(nxActor);
}

NxaJoint^ NxaScene::CreateJoint(NxaJointDescription^ jointDescription)
{
	return jointDescription->CreateJoint(nxScene);
}

void NxaScene::ReleaseActor(NxaActor^ nxaActor)
{
	nxScene->releaseActor(*(nxaActor->nxActor));
}

void NxaScene::UpdateScene(float deltaTime)
{
	nxScene->simulate(deltaTime);
	nxScene->flushStream();
}

bool NxaScene::FetchResults(bool block)
{
	return nxScene->fetchResults(NX_RIGID_BODY_FINISHED, block);
}

bool NxaScene::CheckResults(bool block)
{
	return nxScene->checkResults(NX_RIGID_BODY_FINISHED, block);
}

void NxaScene::FlushCaches()
{ 
	nxScene->flushCaches(); 
}

NxaMaterial^ NxaScene::GetMaterialFromIndex(NxaMaterialIndex matIndex)
{
	NxMaterial* ptr = nxScene->getMaterialFromIndex(matIndex);
	return NxaMaterial::CreateFromPointer(ptr);
}

void NxaScene::InitialiseReporters()
{
	userContactReport = new NxDerivedUserContactReport(this);
	userTriggerReport = new NxDerivedUserTriggerReport(this);

	nxScene->setUserContactReport(userContactReport);
	nxScene->setUserTriggerReport(userTriggerReport);
}

void NxaScene::SetActorPairFlags(NxaActor ^ actorA, NxaActor ^actorB, NxaU32 contactPairFlag)
{
	nxScene->setActorPairFlags(*(actorA->nxActor), *(actorB->nxActor), contactPairFlag);
}

NxaU32 NxaScene::GetActorPairFlags(NxaActor ^actorA, NxaActor ^actorB)
{
	 return nxScene->getActorPairFlags(*(actorA->nxActor), *(actorB->nxActor));
}

void NxaScene::SetActorGroupPairFlags(NxActorGroup group1, NxActorGroup group2, NxU32 flags)
{
	nxScene->setActorGroupPairFlags(group1, group2, flags);
}

NxaU32 NxaScene::GetActorGroupPairFlags(NxActorGroup group1, NxActorGroup group2)
{
	return nxScene->getActorGroupPairFlags(group1, group2);
}

void NxaScene::FireUserContactReporter(NxaContactPair ^pair, NxaU32 events)
{
	if(userContactReporter != nullptr)
		userContactReporter(pair, events);
}

void NxaScene::FireUserTriggerReporter(NxaShape ^triggerShape, NxaShape ^otherShape, NxaTriggerFlag status)
{
	if(userTriggerReporter != nullptr)
		userTriggerReporter(triggerShape, otherShape, status);
}