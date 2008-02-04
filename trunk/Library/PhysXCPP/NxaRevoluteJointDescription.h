#pragma once

#include "NxaJointDescription.h"
#include "NxaJointLimitPairDescription.h"
#include "NxaSpringDescription.h"
#include "NxaMotorDescription.h"

#include "NxRevoluteJointDesc.h"

public ref class NxaRevoluteJointDescription : public NxaJointDescription
{
internal:
	NxaRevoluteJointDescription(NxRevoluteJointDesc* ptr);

public:
	NxaRevoluteJointDescription(void);

	property NxaJointLimitPairDescription^ Limit
	{
		NxaJointLimitPairDescription^ get();
		void set(NxaJointLimitPairDescription^ value);
	}

	property NxaMotorDescription^ Motor
	{
		NxaMotorDescription^ get();
		void set(NxaMotorDescription^ value);
	}

	property NxaSpringDescription^ Spring
	{
		NxaSpringDescription^ get();
		void set(NxaSpringDescription^ value);
	}

	property float ProjectionDistance
	{
		float get();
		void set(float value);
	}

	property float ProjectionAngle
	{
		float get();
		void set(float value);
	}

	property NxaRevoluteJointFlag Flags
	{
		NxaRevoluteJointFlag get();
		void set(NxaRevoluteJointFlag value);
	}

	void SetToDefault();
	bool IsValid();
};