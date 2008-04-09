#pragma once

#include "NxaController.h"
#include "NxCapsuleController.h"
#include "Nxap.h"

public ref class NxaCapsuleController : public NxaController
{
internal:
	NxaCapsuleController(NxController* ptr);

public:
	float GetRadius();
	bool SetRadius(float radius);
	float GetHeight();
	bool SetHeight(float value);
	NxaCapsuleClimbingMode GetClimbingMode();
	bool SetClimbingMode(NxaCapsuleClimbingMode mode);

};
