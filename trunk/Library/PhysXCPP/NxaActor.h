#pragma once

#include "Stdafx.h"
#include "Nxap.h"
#include "NxaActorDescription.h"

class NxActor;
ref class NxaShape;
ref class NxaShapeDescription;

public ref class NxaActor
{
internal:
	NxActor* nxActor;

public:
	NxaActor(NxActor* ptr);

	void AddForce(Vector3 force);
	void AddForce([In] Vector3% force);
	void AddTorque(Vector3 torque);
	void AddTorque([In] Vector3% torque);

	Vector3 GetGlobalPosition();
	void GetGlobalPosition([Out] Vector3% position);

	Matrix GetGlobalOrientation();
	void GetGlobalOrientation([Out] Matrix% m);

	Quaternion GetGlobalOrientationQuaternion();
	void GetGlobalOrientationQuaternion([Out] Quaternion% orientation);

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
