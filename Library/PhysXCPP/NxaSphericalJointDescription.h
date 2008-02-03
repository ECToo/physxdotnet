#pragma once

#include "NxaJointDescription.h"

ref class NxaJointLimitDescription;
ref class NxaJointLimitPairDescription;


public ref class NxaSphericalJointDescription : public NxaJointDescription
{
public:
	NxaSphericalJointDescription(void);

	virtual void SetToDefault();
	virtual bool IsValid();

	property Vector3 SwingAxis
	{
		Vector3 get();
		void set(Vector3 axis);
	}

	property float ProjectionDistance
	{
		float get();
		void set(float dist);
	}

	/*property NxaJointLimitPairDescription^ TwistLimit
	{
		NxaJointLimitPairDescription^ get();
		void set(NxaJointLimitPairDescription^ twistLimit);
	}

	property NxaJointLimitDescription^ SwingLimit
	{
		NxaJointLimitDescription^ get();
		void set(NxaJointLimitDescription^ swingLimit);
	}*/

	//property NxaSpringDescription^ TwistSpring
	//{
	//	NxaSwingDescription^ get();
	//	void set(NxaSwingDescription^ twistSpring);
	//}

	//property NxaSpringDescription^ SwingSpring
	//{
	//	NxaSpringDescription^ get();
	//	void set(NxaSpringDescription^ swingSpring);
	//}

	//property NxaSpringDescription^ JointSpring
	//{
	//	NxaSpringDescription^ get();
	//	void set(NxaSpringDescription^ jointSpring);
	//}

	property NxaU32 Flags
	{
		NxaU32 get();
		void set(NxaU32 flags);
	}

	/*property NxaJointProjectionMode ProjectionMode
	{
		NxaJointProjectionMode get();
		void set(NxaJointProjectionMode projectionMode);
	}*/
};