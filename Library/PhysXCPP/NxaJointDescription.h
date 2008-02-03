#pragma once

#include "Stdafx.h"
#include "Nxap.h"

#include "NxActor.h"
#include "NxJointDesc.h"

#include "NxaActor.h"
#include "NxaMath.h"

public ref class NxaJointDescription abstract
{
internal:
	NxJointDesc* nxJointDesc;
	NxaJointDescription();
	NxaJointDescription(NxJointDesc* ptr);

public:
	~NxaJointDescription(void);
	!NxaJointDescription(void);
	
	void SetGlobalAnchor(Vector3 anchor);
	void SetGlobalAxis(Vector3 axis);
	void ClearJointFlag(NxaJointFlag flag);
	void RaiseJointFlag(NxaJointFlag flag);

	property NxaActor^ Actor[int]
	{
		NxaActor^ get(int x);
		void set(int x, NxaActor^ value);
	}

	property Vector3 LocalAnchor[int]
	{
		Vector3 get(int x);
		void set(int x, Vector3 value);
	}

	property Vector3 LocalAxis[int]
	{
		Vector3 get(int x);
		void set(int x, Vector3 value);
	}

	property Vector3 LocalNormal[int]
	{
		Vector3 get(int x);
		void set(int x, Vector3 value);
	}

	property float MaxForce
	{
		float get();
		void set(float max);
	}

	property float MaxTorque
	{
		float get();
		void set(float max);
	}
};