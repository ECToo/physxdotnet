#pragma once

class NxJointLimitSoftDesc;

public value class NxaJointLimitSoftDescription
{
internal:
	void LoadFromNative(NxJointLimitSoftDesc& desc);
	NxJointLimitSoftDesc ConvertToNative();

public:
	//NxaJointLimitSoftDescription();

	void SetToDefault();
	bool IsValid();

	float Value;
	float Restitution;
	float Spring;
	float Damping;
};
