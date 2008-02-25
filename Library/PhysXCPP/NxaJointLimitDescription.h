#pragma once

class NxJointLimitDesc;

public value class NxaJointLimitDescription
{
internal:
	NxJointLimitDesc ConvertToNative();

public:

	void SetToDefault();
	bool IsValid();

	static property NxaJointLimitDescription Default
	{
		NxaJointLimitDescription get();
	}

	float Value;
	float Restitution;
	float Hardness;
};