#include "StdAfx.h"

#include "PhysXCPP.h"
#include "NxFoundationSDK.h"
#include "NxaScene.h"
#include "NxaActor.h"
#include "NxaFixedJoint.h"
#include "NxaActorDescription.h"
#include "NxaJointDescription.h"
#include "NxaMaterialDescription.h"
#include "NxaMaterial.h"
#include "NxaUserContactReport.h"
#include "NxaUserTriggerReport.h"
#include "NxSceneDesc.h"
#include "NxRemoteDebugger.h"

#include "NxContainer.h"

NxaScene::NxaScene(NxaSceneDescription^ desc)
{
	// create the unmanaged object
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

	// set the default material
	NxMaterial* defaultMaterial = nxScene->getMaterialFromIndex(0);
	defaultMaterial->setRestitution(0.5);
	defaultMaterial->setStaticFriction(0.5);
	defaultMaterial->setDynamicFriction(0.5);

	// initialise callbackers for UserContactReport and UserTriggerReport
	InitialiseReporters();

	// add the scene to the container
	NxSceneContainer::GetInstance()->Add(IntPtr(nxScene), this);
}

NxaScene::~NxaScene()
{
	this->!NxaScene();
}

NxaScene::!NxaScene()
{
	// remove the UserContact callback class
	if(userContactReport != 0)
	{
		delete userContactReport;
		userContactReport = 0;
	}

	// remove the userTrigger callback class
	if(userTriggerReport != 0)
	{
		delete userTriggerReport;
		userTriggerReport = 0;
	}

	// remove the managed object from the container
	if(nxScene != 0)
	{
		NxSceneContainer::GetInstance()->Remove(IntPtr(nxScene));
		
		array<NxaActor ^> ^ arActors = GetActors();
		int nrOfActors = arActors->Length;

		for(int i = 0; i < nrOfActors; i++)
			delete arActors[i];
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
	// release the actor
	nxScene->releaseActor(*(nxaActor->nxActor));

	// destroy the managed NxaActor object
	delete nxaActor;
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

NxaU32 NxaScene::GetNbActors()
{
	return nxScene->getNbActors();
}
array<NxaActor^>^ NxaScene::GetActors()
{
	int nrOfActors = nxScene->getNbActors();
	array<NxaActor^> ^ arActors = gcnew array<NxaActor^>(nrOfActors);

	NxActor* const* ptr = nxScene->getActors();

	for(int i = 0; i < nrOfActors; i++)
		arActors[i] = NxActorContainer::GetInstance()->Find(IntPtr(ptr[i]));
	
	return arActors;
}

Object^ NxaScene::UserData::get()
{
	if(nxScene->userData != 0)
	{
		GCHandle gch = GCHandle::FromIntPtr((System::IntPtr)(nxScene->userData));
		Object^ obj = (Object^)(gch.Target);
		return obj;
	}
	else
	{
		return nullptr;
	}
}

void NxaScene::UserData::set(Object ^ value)
{
	if(nxScene->userData != 0)
	{
		GCHandle gch = GCHandle::FromIntPtr(IntPtr(nxScene->userData));
		gch.Free();
		nxScene->userData = 0;
	}
	if( value != nullptr)
	{
		GCHandle gch = GCHandle::Alloc(value);
		nxScene->userData = (void*)(GCHandle::ToIntPtr(gch));
	}
}

NxaMaterial^ NxaScene::CreateMaterial(NxaMaterialDescription^ matDesc)
{
	NxMaterial* mat = nxScene->createMaterial(*(matDesc->nxMaterialDesc));
	return gcnew NxaMaterial(mat);
}

void NxaScene::ReleaseMaterial(NxaMaterial^ material)
{
	if(material->nxMaterial != nullptr)
	{
		nxScene->releaseMaterial(*(material->nxMaterial));
		material->nxMaterial = nullptr;
	}
}