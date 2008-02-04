#pragma once

class NxMotorDesc;

public ref class NxaMotorDescription
{
internal:
	NxMotorDesc* nxMotorDesc;
	NxaMotorDescription(NxMotorDesc* ptr);

public:
	NxaMotorDescription();
	NxaMotorDescription(float targetVelocity, float maxForce, bool freeSpin);
	NxaMotorDescription(float targetVelocity, float maxForce);
	NxaMotorDescription(float targetVelocity);
	~NxaMotorDescription();
	!NxaMotorDescription();

	property float TargetVelocity
	{
		float get();
		void set(float value);
	}

	property float MaxForce
	{
		float get();
		void set(float value);
	}

	property bool FreeSpin
	{
		bool get();
		void set(bool value);
	}

	void SetToDefault();
	bool IsValid();	
};
