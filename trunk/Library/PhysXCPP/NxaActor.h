#pragma once

#include "Stdafx.h"
#include "Nxap.h"
#include "NxaActorDescription.h"


class NxActor;
ref class NxaScene;
ref class NxaShape;
ref class NxaShapeDescription;

public ref class NxaActor
{
internal:
	NxActor* nxActor;
	String^ actorName;

	NxaActor(NxActor * actor);

public:
	~NxaActor();
	!NxaActor();

	//-----------------------
	//Public Member Functions
	//-----------------------

	NxaScene^ GetScene();

	//TODO Add SaveToDescription

	void SetName(String^ name);
	String^ GetName();

	void SetGroup(NxaActorGroup actorGroup);
	NxaActorGroup GetGroup();

	void SetDominanceGroup(NxaDominanceGroup dominanceGroup);
	NxaDominanceGroup GetDominanceGroup();

	void RaiseActorFlag(NxaActorFlag flag);
	void ClearActorFlag(NxaActorFlag flag);
	bool ReadActorFlag(NxaActorFlag flag);

	void ResetUserActorPairFiltering();

	bool IsDynamic();

	float ComputeKineticEnergy();

	void RaiseBodyFlag(NxaBodyFlag flag);
	void ClearBodyFlag(NxaBodyFlag flag);
	bool ReadBodyFlag(NxaBodyFlag flag);

	bool SaveBodyToDescription([Out] NxaBodyDescription^% bodyDesc);

	void SetSolverIterationCount(NxaU32 count);
	NxaU32 GetSolverIterationCount();

	//void RecomputeAdaptiveForceCounters(); //doesn't work in 2.8.0

	//TODO Add LinearSweep.
	//TODO Add GetCompartment.

	//------------------------
	//Global Pose Manipulation
	//------------------------

	void SetGlobalPose(Matrix matrix);
	void SetGlobalPosition(Vector3 position);
	
	void SetGlobalOrientation(Matrix matrix);
	void SetGlobalOrientationQuaternion(Quaternion quaternion);

	Matrix GetGlobalPose();
	Vector3 GetGlobalPosition();
	Matrix GetGlobalOrientation();
	Quaternion GetGlobalOrientationQuaternion();

	//----------------
	//Kinematic Actors
	//----------------

	void MoveGlobalPose(Matrix pose);
	void MoveGlobalPosition(Vector3 position);
	void MoveGlobalOrientation(Matrix orientation);
	void MoveGlobalOrientationQuaternion(Quaternion orientation);

	//------
	//Shapes
	//------

	NxaShape^ CreateShape(NxaShapeDescription^ shape);
	void ReleaseShape(NxaShape^ shape);
	NxaU32 GetNumberOfShapes();
	array<NxaShape^>^ GetShapes();

	//-----------------
	//Mass Manipulation
	//-----------------

	void SetCenterOfMassOffsetLocalPose(Matrix pose);
	void SetCenterOfMassOffsetLocalPosition(Vector3 position);
	void SetCenterOfMassOffsetLocalOrientation(Matrix orientation);

	void SetCenterOfMassOffsetGlobalPose(Matrix pose);
	void SetCenterOfMassOffsetGlobalPosition(Vector3 position);
	void SetCenterOfMassOffsetGlobalOrientation(Matrix orientation);

	void SetCenterOfMassGlobalPose(Matrix pose);
	void SetCenterOfMassGlobalPosition(Vector3 position);
	void SetCenterOfMassGlobalOrientation(Matrix orientation);

	Matrix GetCenterOfMassLocalPose();
	Vector3 GetCenterOfMassLocalPosition();
	Matrix GetCenterOfMassLocalOrientation();

	Matrix GetCenterOfMassGlobalPose();
	Vector3 GetCenterOfMassGlobalPosition();
	Matrix GetCenterOfMassGlobalOrientation();

	void SetMass(float mass);
	float GetMass();

	void SetMassSpaceInertiaTensor(Vector3 tensor);
	Vector3 GetMassSpaceInertiaTensor();
	Matrix GetGlobalInertiaTensor();
	Matrix GetGlobalInertiaTensorInverse();
	
	void UpdateMassFromShapes(float density, float totalMass);

	//-------
	//Damping
	//-------

	void SetLinearDamping(float linearDamping);
	float GetLinearDamping();
	void SetAngularDamping(float angularDamping);
	float GetAngularDamping();

	//---------
	// Velocity
	//---------

	void SetLinearVelocity(Vector3 linearVelocity);
	void SetAngularVelocity(Vector3 angularVelocity);
	Vector3 GetLinearVelocity();
	Vector3 GetAngularVelocity();
	void SetMaxAngularVelocity(float maxAngularVelocity);
	float GetMaxAngularVelocity();

	//----
	// CCD
	//----

	void SetCCDMotionThreshold(float threshold);
	float GetCCDMotionThreshold();

	//---------
	// Momentum
	//---------

	void SetLinearMomentum(Vector3 linearMomentum);
	void SetAngularMomentum(Vector3 angularMomentum);
	Vector3 GetLinearMomentum();
	Vector3 GetAngularMomentum();

	//-------
	// Forces
	//-------

	void AddForceAtPosition(Vector3 force, Vector3 position, NxaForceMode forceMode, bool wakeup);
	void AddForceAtLocalPosition(Vector3 force, Vector3 position, NxaForceMode forceMode, bool wakeup);
	void AddLocalForceAtPosition(Vector3 force, Vector3 position, NxaForceMode forceMode, bool wakeup);
	void AddLocalForceAtLocalPosition(Vector3 forc, Vector3 position, NxaForceMode forceMode, bool wakeup);
	void AddForce(Vector3 force, NxaForceMode forceMode, bool wakeup);
	void AddLocalForce(Vector3 force, NxaForceMode forceMode, bool wakeup);
	void AddTorque(Vector3 torque, NxaForceMode forceMode, bool wakeup);
	void AddLocalTorque(Vector3 torque, NxaForceMode forceMode, bool wakeup);

	//---------------
	// Point Velocity
	//---------------

	Vector3 GetPointVelocity(Vector3 point);
	Vector3 GetLocalPointVelocity(Vector3 point);

	//---------
	// Sleeping
	//---------

	bool IsGroupSleeping();
	bool IsSleeping();
	float GetSleepLinearVelocity();
	void SetSleepLinearVelocity(float velocity);
	float GetSleepAngularVelocity();
	void SetSleepAngularVelocity(float velocity);
	float GetSleepEnergyThreshold();
	void SetSleepEnergyThreshold(float threshold);
	void WakeUp(float timeout);
	void PutToSleep();

	//------------------
	// Public Attributes
	//------------------

	property Object^ UserData
	{
		Object^ get();
		void set(Object ^);
	};
};
