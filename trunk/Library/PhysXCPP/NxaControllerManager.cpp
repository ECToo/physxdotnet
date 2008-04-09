#include "StdAfx.h"
#include "NxaControllerManager.h"
#include <crtdbg.h>
#include "NxUserAllocatorDefault.h"
#include "NxContainer.h"
#include "NxaController.h"
#include "NxaScene.h"
#include "NxaControllerDescription.h"

NxaControllerManager::NxaControllerManager(void)
{
	//nxControllerManager = NxCreateControllerManager(new NxUserAllocatorDefault());
}
NxaControllerManager^ NxaControllerManager::GetInstance()
{
	if(instance == nullptr)
		instance = gcnew NxaControllerManager();

	return instance;
}
NxaU32 NxaControllerManager::GetNbControllers()
{
	return nxControllerManager->getNbControllers();
}
NxaController ^ NxaControllerManager::GetController(NxaU32 index)
{
	return NxControllerContainer::GetInstance()->Find(IntPtr(nxControllerManager->getController(index)));	
}
NxaController ^ NxaControllerManager::CreateController(NxaScene ^ scene, NxaControllerDescription ^ description)
{
	return NxaController::CreateFromPointer(nxControllerManager->createController(scene->nxScene, *(description->nxControllerDesc)));
}
void NxaControllerManager::ReleaseController(NxaController ^controller)
{
	NxControllerContainer::GetInstance()->Remove(IntPtr(controller->nxController));
	nxControllerManager->releaseController(*(controller->nxController));

	delete controller;
}
void NxaControllerManager::PurgeControllers()
{
	// so we first release all the managed objects

	int nbOfControllers = nxControllerManager->getNbControllers();
	for(int i = nbOfControllers-1; i > 0; i--)
	{
		NxaController ^ controller = GetController(i);
		ReleaseController(controller);
	}
}
void NxaControllerManager::UpdateControllers()
{
	nxControllerManager->updateControllers();
}
