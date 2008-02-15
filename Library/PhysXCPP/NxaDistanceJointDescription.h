#pragma once

#include "NxaJointDescription.h"
#include "NxaSpringDescription.h"

#include "NxDistanceJointDesc.h"

public ref class NxaDistanceJointDescription : public NxaJointDescription
{
internal:
	NxaDistanceJointDescription(NxDistanceJointDesc* ptr);

public:
	NxaDistanceJointDescription(void);

	property float MaxDistance {
		float get();
		void set(float value);
	}

	property float MinDistance {
		float get();
		void set(float value);
	}

	property NxaSpringDescription^ Spring {
		NxaSpringDescription^ get();
		void set(NxaSpringDescription^ value);
	}

	property NxaDistanceJointFlag Flags {
		NxaDistanceJointFlag get();
		void set(NxaDistanceJointFlag value);
	}

	void SetToDefault();
	bool IsValid();
};