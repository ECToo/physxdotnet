#pragma once

#include "NxSpringDesc.h"

public ref class NxaSpringDescription
{
internal:
	NxSpringDesc* nxSpringDesc;
	NxaSpringDescription(NxSpringDesc* ptr);

public:
	NxaSpringDescription(float spring, float damper, float targetValue);
	NxaSpringDescription(float spring, float damper);
	NxaSpringDescription(float spring);
	NxaSpringDescription(void);
	~NxaSpringDescription(void);
	!NxaSpringDescription(void);

	property float Spring
	{
		float get();
		void set(float value);
	}

	property float Damper
	{
		float get();
		void set(float value);
	}

	property float TargetValue
	{
		float get();
		void set(float value);
	}

	void SetToDefault();
	bool IsValid();
};
