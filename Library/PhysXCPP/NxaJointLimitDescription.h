#pragma once

class NxJointLimitDesc;

public ref class NxaJointLimitDescription
{
internal:
	NxJointLimitDesc* nxJointLimitDesc;
	NxaJointLimitDescription(NxJointLimitDesc* ptr);

public:
	NxaJointLimitDescription();

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

	property float Hardness
	{
		float get();
		void set(float value);
	}
};