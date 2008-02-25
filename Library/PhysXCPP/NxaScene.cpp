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
	nxScene = ptr;
}

NxaScene::NxaScene(NxaSceneDescription^ desc)
{
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