#pragma once

class NxJointLimitSoftDesc;

public ref class NxaJointLimitSoftDescription
{
internal:
	NxJointLimitSoftDesc* nxDesc;
	NxaJointLimitSoftDescription(NxJointLimitSoftDesc* ptr);

public:
	NxaJointLimitSoftDescription();
	~NxaJointLimitSoftDescription();
	!NxaJointLimitSoftDescription();

	void SetToDefault();
	bool IsValid();

	property float Value
	{
		float get();
		void set(float value);
	}

	property float Restitution
	{
		float get();
		void set(float value);
	}

	property float Spring
	{
		float get();
		void set(float value);
	}

	property float Damping
	{
		float get();
		void set(float value);
	}
};
