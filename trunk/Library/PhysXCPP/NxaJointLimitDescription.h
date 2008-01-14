#pragma once

#include "NxPhysics.h"

namespace PhysXCPP
{

	public ref class NxaJointLimitDescription
	{
	public:
		NxaJointLimitDescription(void);
		~NxaJointLimitDescription(void);
		!NxaJointLimitDescription(void);

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

	private:
		NxJointLimitDesc* jointLimitDesc;


	};

}