#pragma once

#include "NxBodyDesc.h"
#include "Nxap.h"

public ref class NxaBodyDescription
{
internal:
	NxBodyDesc* nxBodyDesc;

public:
	NxaBodyDescription(void);
	~NxaBodyDescription(void);
	!NxaBodyDescription(void);

	bool IsValid();
	void SetToDefault();

	property Matrix MassLocalPose
	{
		Matrix get();
		void set(Matrix value);
	}
	property Vector3 MassSpaceInertia
	{
		Vector3 get();
		void set(Vector3 value);
	}
	property Vector3 LinearVelocity
	{
		Vector3 get();
		void set(Vector3 value);
	}
	property Vector3 AngularVelocity
	{
		Vector3 get();
		void set(Vector3 value);
	}
	
	property float Mass
	{
		float get();
		void set(float value);
	}
	property float WakeUpCounter
	{
		float get();
		void set(float value);
	}
	property float LinearDamping
	{
		float get();
		void set(float value);
	}
	property float AngularDamping
	{
		float get();
		void set(float value);
	}
	property float MaxAngularVelocity
	{
		float get();
		void set(float value);
	}
	property float SleepLinearVelocity
	{
		float get();
		void set(float value);
	}
	property float SleepAngularVelocity
	{
		float get();
		void set(float value);
	}
	property float SleepDaming
	{
		float get();
		void set(float value);
	}
	
	property NxaU32 BodyFlags
	{
		NxaU32 get();
		void set(NxaU32 value);
	}
};
