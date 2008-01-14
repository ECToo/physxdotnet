#include "StdAfx.h"
#include "NxaScene.h"
#include "NxaSceneDescription.h"
#include "PhysXCPP.h"
#include <iostream>
#include "NxaFixedJoint.h"

using namespace PhysXCPP;

NxaScene::NxaScene(NxaSceneDescription^ desc)
{
	NxSceneDesc sceneDesc;
	sceneDesc.gravity = NxVec3(desc->Gravity.X, desc->Gravity.Y, desc->Gravity.Z);

	if(desc->SimulationType == NxaSimulationType::Hardware)
	{
		SimulationType = NxaSimulationType::Hardware;
		sceneDesc.simType = NX_SIMULATION_HW;
		scene = PhysXEngine::sdk->createScene(sceneDesc);
	}

	if(!scene)
	{
		SimulationType = NxaSimulationType::Software;
		sceneDesc.simType = NX_SIMULATION_SW;
		scene = PhysXEngine::sdk->createScene(sceneDesc);
		if(!scene) return;
	}

	if(desc->EnableRemoteDebugger)
		PhysXEngine::sdk->getFoundationSDK().getRemoteDebugger()->connect("localhost", 5425);

	NxMaterial* defaultMaterial = scene->getMaterialFromIndex(0);
	defaultMaterial->setRestitution(0.5);
	defaultMaterial->setStaticFriction(0.5);
	defaultMaterial->setDynamicFriction(0.5);
}

NxaScene::!NxaScene(void)
{

}

NxaActor^ NxaScene::CreateActor(NxaActorDescription^ actorDescription)
{
	NxActor* nxActor = scene->createActor(*(actorDescription->nxActorDesc));
	return gcnew NxaActor(nxActor, actorDescription);
}

NxaJoint^ NxaScene::CreateJoint(NxaJointDescription^ jointDescription)
{
	NxJoint* nxJoint = scene->createJoint(*(jointDescription->nxJointDesc));

	NxaJoint^ nxaJoint;

	if(nxJoint->isFixedJoint())
		nxaJoint = gcnew NxaFixedJoint((NxFixedJoint*)nxJoint);
	
	nxaJoint->actorA = jointDescription->Actor[0];
	nxaJoint->actorB = jointDescription->Actor[1];

	return nxaJoint;
}

void NxaScene::ReleaseActor(NxaActor^ nxaActor)
{
	scene->releaseActor(*(nxaActor->nxActor));
}

void NxaScene::UpdateScene(float deltaTime)
{
	scene->simulate(deltaTime);
	scene->flushStream();
}

bool NxaScene::FetchResults(bool block)
{
	return scene->fetchResults(NX_RIGID_BODY_FINISHED, block);
}

bool NxaScene::CheckResults(bool block)
{
	return scene->checkResults(NX_RIGID_BODY_FINISHED, block);
}