#pragma once

#include "Nxap.h"
#include "NxaActorDescription.h"
#include "NxaShapeDescription.h"
#include "NxPhysics.h"
#include "NxaShape.h"

using namespace Microsoft::Xna::Framework;

namespace PhysXCPP
{

	public ref class NxaActor
	{
	internal:
		NxActor* nxActor;
		NxaActorDescription^ nxaActorDesc;

		NxaActor(NxActor* nxActor, NxaActorDescription^ nxaActorDesc);

	public:
		NxaActor(void);
		!NxaActor(void);

		void AddForce(Vector3 force);

		Vector3 GetGlobalPosition();

		Matrix GetGlobalOrientation();
		Quaternion GetGlobalOrientationQuaternion();

		NxaShape^ CreateShape(NxaShapeDescription^ shape);

		array<NxaShape^>^ GetShapes();

		void SetSleepAngularVelocity(float velocity);
		void SetSleepLinearVelocity(float velocity);
		void SetGlobalPose(Matrix matrix);
		void SetGlobalPosition(Vector3 position);

		void ClearActorFlag(NxaActorFlag flag);
		void RaiseActorFlag(NxaActorFlag flag);
		void ClearBodyFlag(NxaBodyFlag flag);
		void RaiseBodyFlag(NxaBodyFlag flag);

		void WakeUp(float timeout);

		void SetSolverIterationCount(int count);	
	};

}
