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
	NxSceneDesc sceneDesc;
	sceneDesc.gravity = NxVec3(desc->Gravity.X, desc->Gravity.Y, desc->Gravity.Z);

	if(desc->SimulationType == NxaSimulationType::Hardware)
	{
		SimulationType = NxaSimulationType::Hardware;
		sceneDesc.simType = NX_SIMULATION_HW;
		nxScene = PhysXEngine::sdk->createScene(sceneDesc);
	}

	if(!nxScene)
	{
		SimulationType = NxaSimulationType::Software;
		sceneDesc.simType = NX_SIMULATION_SW;
		nxScene = PhysXEngine::sdk->createScene(sceneDesc);
		if(!nxScene) return;
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
	NxJoint* jointPtr = nxScene->createJoint(*(jointDescription->nxJointDesc));
	return NxaJoint::CreateFromPointer(jointPtr);

	///*NxJoint* nxJoint = scene->createJoint(*(jointDescription->nxJointDesc));

	//NxaJoint^ nxaJoint;

	//if(nxJoint->isFixedJoint())
	//	nxaJoint = gcnew NxaFixedJoint((NxFixedJoint*)nxJoint);
	//
	//nxaJoint->actorA = jointDescription->Actor[0];
	//nxaJoint->actorB = jointDescription->Actor[1];

	//return nxaJoint;*/
	//throw gcnew Exception("NOT IMPLEMENTED PROPERLY!");
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