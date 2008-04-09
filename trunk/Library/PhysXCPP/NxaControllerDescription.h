#pragma once

#include "NxController.h"

public ref class NxaControllerDescription abstract
{
internal:
	NxaControllerDescription(NxControllerDesc * ptr);
	NxControllerDesc * nxControllerDesc;

public:
	virtual ~NxaControllerDescription();
	!NxaControllerDescription();

	void SetToDefault();
	bool IsValid();

	property Vector3 Position
	{
		Vector3 get();
		void set(Vector3 value);
	}

	property float SlopeLimit
	{
		float get();
		void set(float value);
	}

	property float SkinWidth
	{
		float get();
		void set(float value);
	}

	property float StepOffset
	{
		float get();
		void set(float value);
	}

};
