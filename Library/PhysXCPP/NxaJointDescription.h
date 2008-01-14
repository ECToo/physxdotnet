#pragma once

#include "NxPhysics.h"
#include "NxaActor.h"

using namespace Microsoft::Xna::Framework;
using namespace System::Collections;

namespace PhysXCPP
{

	public ref class NxaJointDescription abstract
	{

	public:
		property NxJointDesc* nxJointDesc;
	private:
		array<NxaActor^>^ actors;

	public:
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

	public:
		NxaJointDescription(void);
		!NxaJointDescription(void);
		
		void SetGlobalAnchor(Vector3 anchor);
		void SetGlobalAxis(Vector3 axis);
		void ClearJointFlag(NxaJointFlag flag);
		void RaiseJointFlag(NxaJointFlag flag);
	};

}