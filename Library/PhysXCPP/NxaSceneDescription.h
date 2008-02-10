#pragma once

#include "Nxap.h"
class NxSceneDesc;

public enum class NxaTimeStepMethod 
{ 
	Fixed, 
	Variable,
	Inherit
};

public enum class NxaSimulationType 
{ 
	Software = 0,
	Hardware = 1,
};

public enum class NxaPruningStructure
{
	None,
	Octree,
	Quadtree,
	DynamicAABBTree,
	StaticAABBTree
};

public enum class NxaSceneFlags
{
	DisableSSE = (1<<0),
	DisableCollisions = (1<<1),
	SimulateSeparateThread = (1<<2),
	EnableMultithread = (1<<3),
	EnableActiveTransforms = (1<<4),
	RestrictedScene = (1<<5),
	DisableSceneMutex = (1<<6),
	ForceConeFriction = (1<<7),
	SequentialPrimary = (1<<8),
	FluidPerformanceHint = (1<<9)
};

public ref class NxaSceneDescription
{
internal:
	NxSceneDesc* nxSceneDesc;

public:
	NxaSceneDescription();
	~NxaSceneDescription();
	!NxaSceneDescription();

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

	property NxaPruningStructure StaticStructure
	{
		NxaPruningStructure get();
		void set(NxaPruningStructure value);
	}

	property NxaPruningStructure DynamicStructure
	{
		NxaPruningStructure get();
		void set(NxaPruningStructure value);
	}

	property Object^ UserData;
	property bool EnableRemoteDebugger;
};