#pragma once

class NxJointLimitSoftPairDesc;
ref class NxaJointLimitSoftDescription;

public ref class NxaJointLimitSoftPairDescription
{
internal:
	NxJointLimitSoftPairDesc* nxDesc;
	NxaJointLimitSoftPairDescription(NxJointLimitSoftPairDesc* ptr);

public:
	NxaJointLimitSoftPairDescription();
	~NxaJointLimitSoftPairDescription();
	!NxaJointLimitSoftPairDescription();

	void SetToDefault();
	bool IsValid();

	property NxaJointLimitSoftDescription^ Low
	{
		NxaJointLimitSoftDescription^ get();
		void set(NxaJointLimitSoftDescription^ value);
	}

	property NxaJointLimitSoftDescription^ High
	{
		NxaJointLimitSoftDescription^ get();
		void set(NxaJointLimitSoftDescription^ value);
	}
};
