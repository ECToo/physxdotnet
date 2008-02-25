#pragma once

class NxMotorDesc;

public ref class NxaMotorDescription
{
internal:
	void LoadFromNative(NxMotorDesc& desc);
	NxMotorDesc ConvertToNative();

public:
	NxaMotorDescription();
	NxaMotorDescription(float velocityTarget, float maxForce, bool freeSpin);
	NxaMotorDescription(float velocityTarget, float maxForce);
	NxaMotorDescription(float velocityTarget);

	void SetToDefault();
	bool IsValid();	

	float VelocityTarget;
	float MaxForce;
	bool FreeSpin;
};
