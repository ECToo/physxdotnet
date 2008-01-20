#pragma once

#include "Nxap.h"
class NxSceneDesc;

public ref class NxaSceneDescription
{
internal:
	NxSceneDesc* nxSceneDesc;

public:
	property Vector3 Gravity
	{
		Vector3 get();
		void set(Vector3 value);
	}

	//TODO Add userNotify.
	//TODO Add fluidUserNotify.
	//TODO Add userContactModify.
	//TODO Add userTriggerReport.
	//TODO Add userContactReport.
	//TODO Add userActorPairFiltering.

	property float MaxTimeStep
	{
		float get();
		void set(float value);
	}

	property NxaU32 MaxIterations
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaTimeStepMethod TimeStepMethod
	{
		NxaTimeStepMethod get();
		void set(NxaTimeStepMethod value);
	}

	//TODO Add maxBounds
	//TODO Add limits
	
	property NxaSimulationType SimulationType
	{
		NxaSimulationType get();
		void set(NxaSimulationType value);
	}

	property bool GroundPlane
	{
		bool get();
		void set(bool value);
	}

	property bool BoundsPlanes
	{
		bool get();
		void set(bool value);
	}

	property NxaU32 Flags
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	//TODO customerScheduler

	property NxaU32 SimulationThreadStackSize
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaThreadPriority SimulationThreadPriority
	{
		NxaThreadPriority get();
		void set(NxaThreadPriority value);
	}

	property NxaU32 SimulationThreadMask
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaU32 InternalThreadCount
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaU32 WorkerThreadStackSize
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaThreadPriority WorkerThreadPriority
	{
		NxaThreadPriority get();
		void set(NxaThreadPriority value);
	}

	property NxaU32 ThreadMask
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaU32 BackgroundThreadCount
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaU32 BackgroundThreadMask
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaU32 UpAxis
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property NxaU32 SubdivisionLevel
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	//TODO staticStructure
	//TODO dynamicStructure

	property Object^ UserData;
	property bool EnableRemoteDebugger;
	
	NxaSceneDescription(void);
	~NxaSceneDescription(void);
	!NxaSceneDescription(void);
};