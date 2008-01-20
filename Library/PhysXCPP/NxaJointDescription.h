#pragma once

#include "Stdafx.h"
#include "Nxap.h"

#include "NxActor.h"
#include "NxJointDesc.h"

#include "NxaActor.h"

public ref class NxaJointDescription abstract
{
internal:
	NxJointDesc* nxJointDesc;

private:
	array<NxaActor^>^ actors;

public:
	NxaJointDescription(void);
	~NxaJointDescription(void);
	!NxaJointDescription(void);
	
	void SetGlobalAnchor(Vector3 anchor);
	void SetGlobalAxis(Vector3 axis);
	void ClearJointFlag(NxaJointFlag flag);
	void RaiseJointFlag(NxaJointFlag flag);

	property NxaActor^ Actor[int]
	{
		NxaActor^ get(int x) { return actors[x]; }
		void set(int x, NxaActor^ value) 
		{ 
			actors[x] = value; 
			nxJointDesc->actor[x] = value->nxActor;
		}
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
		float get() { return nxJointDesc->maxForce; }
		void set(float max) { nxJointDesc->maxForce = max; }
	}

	property float MaxTorque
	{
		float get() { return nxJointDesc->maxTorque; }
		void set(float max) { nxJointDesc->maxTorque = max; }
	}
};