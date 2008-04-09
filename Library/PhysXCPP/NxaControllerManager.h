#pragma once

#include "Nxap.h"
#include "NxControllerManager.h"

ref class NxaController;
ref class NxaScene;
ref class NxaControllerDescription;

ref class NxaControllerManager
{
private:
	static NxaControllerManager ^ instance = nullptr;
	NxaControllerManager();

internal:
	NxControllerManager * nxControllerManager;

public:
	static NxaControllerManager ^ GetInstance();
	NxaU32 GetNbControllers();
	NxaController ^ GetController(NxaU32 index);
	NxaController ^ CreateController(NxaScene ^ scene, NxaControllerDescription ^ description);
	void ReleaseController(NxaController ^controller);
	void PurgeControllers();
	void UpdateControllers();
};
