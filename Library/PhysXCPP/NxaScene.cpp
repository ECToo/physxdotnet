#include "StdAfx.h"

#include "PhysXCPP.h"

#include "NxaScene.h"
#include "NxaActor.h"
#include "NxaFixedJoint.h"
#include "NxaActorDescription.h"
#include "NxaJointDescription.h"
#include "NxaMaterial.h"

#include "NxMaterial.h"
#include "NxSceneDesc.h"
#include "NxScene.h"
#include "NxRemoteDebugger.h"

NxaScene::NxaScene(NxScene* ptr)
{
	userContactReport = 0;
	userTriggerReport = 0;

	nxScene = ptr;
}

NxaScene::NxaScene(NxaSceneDescription^ desc)
{
	userContactReport = 0;
	userTriggerReport = 0;

	nxScene = PhysXEngine::sdk->createScene(*(desc->nxSceneDesc));

	if(!nxScene)
	{
		desc->SimulationType = NxaSimulationType::Software;
		nxScene = PhysXEngine::sdk->createScene(*(desc->nxSceneDesc));

		if(!nxScene)
		{
			return;
		}
	}

	if(desc->EnableRemoteDebugger)
		PhysXEngine::sdk->getFoundationSDK().getRemoteDebugger()->connect("localhost", 5425);

	NxMaterial* defaultMaterial = nxScene->getMaterialFromIndex(0);
	defaultMaterial->setRestitution(0.5);
	defaultMaterial->setStaticFriction(0.5);
	defaultMaterial->setDynamicFriction(0.5);
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

void NxaScene::SetUserContactReport(NxaUserContactDelegate ^ callback)
{
	if(userContactReport == 0)
	{
		userContactReport = new NxDerivedUserContactReport();
		nxScene->setUserContactReport(userContactReport);
	}

	userContactReport->SetContactDelegate(callback);
}

void NxaScene::SetUserTriggerReport(NxaUserTriggerDelegate ^ callback)
{
	if(userTriggerReport == 0)
	{
		userTriggerReport = new NxDerivedUserTriggerReport();
		nxScene->setUserTriggerReport(userTriggerReport);
	}

	userTriggerReport->SetTriggerDelegate(callback);
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
