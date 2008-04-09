#pragma once

#include "NxController.h"
#include "Nxap.h"

ref class NxaActor;

public ref class NxaController abstract
{
internal:
	NxController * nxController;
	NxaController(NxController* ptr);

	static NxaController^ CreateFromPointer(NxController* ptr);

public:
	virtual ~NxaController();
	!NxaController();
	void SetPosition(Vector3 position);
	Vector3 GetPosition();
	Vector3 GetFilteredPosition();
	NxaActor ^ GetActor();
	void SetStepOffset(float offset);
	void SetCollision(bool enabled);
	void ReportSceneChanged();

	void Move(Vector3 displacement, NxaU32 activeGroups, float minDistance, [Out]NxaU32% collisionFlags);
	void Move(Vector3 displacement, NxaU32 activeGroups, float minDistance, [Out]NxaU32% collisionFlags, float sharpness);

	// TODO: implement getDebugPosition, setInteraction, getInteraction, getUserData, getType functions
};
