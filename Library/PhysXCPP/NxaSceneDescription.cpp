#include "StdAfx.h"
#include "NxaSceneDescription.h"
#include "NxaMath.h"
#include "NxSceneDesc.h"

NxaSceneDescription::NxaSceneDescription(void)
{
	nxSceneDesc = new NxSceneDesc();
}

NxaSceneDescription::~NxaSceneDescription(void)
{
	this->!NxaSceneDescription();
}

NxaSceneDescription::!NxaSceneDescription(void)
{
	delete nxSceneDesc;
}

Vector3 NxaSceneDescription::Gravity::get()
{
	return NxaMath::Vector3PhysXToXNA(nxSceneDesc->gravity);
}

void NxaSceneDescription::Gravity::set(Vector3 value)
{
	nxSceneDesc->gravity = NxaMath::Vector3XNAToPhysX(value);
}

float NxaSceneDescription::MaxTimeStep::get()
{
	return nxSceneDesc->maxTimestep;
}

void NxaSceneDescription::MaxTimeStep::set(float value)
{
	nxSceneDesc->maxTimestep = value;
}

NxaU32 NxaSceneDescription::MaxIterations::get()
{
	return nxSceneDesc->maxIter;
}

void NxaSceneDescription::MaxIterations::set(NxaU32 value)
{
	nxSceneDesc->maxIter = value;
}

NxaTimeStepMethod NxaSceneDescription::TimeStepMethod::get()
{
	return (NxaTimeStepMethod)(nxSceneDesc->timeStepMethod);
}

void NxaSceneDescription::TimeStepMethod::set(NxaTimeStepMethod value)
{
	nxSceneDesc->timeStepMethod = (NxTimeStepMethod)value;
}

NxaSimulationType NxaSceneDescription::SimulationType::get()
{
	return (NxaSimulationType)(nxSceneDesc->simType);
}

void NxaSceneDescription::SimulationType::set(NxaSimulationType value)
{
	nxSceneDesc->simType = (NxSimulationType)value;
}

bool NxaSceneDescription::GroundPlane::get()
{
	return (nxSceneDesc->groundPlane == NX_TRUE);
}

void NxaSceneDescription::GroundPlane::set(bool value)
{
	nxSceneDesc->groundPlane = value;
}

bool NxaSceneDescription::BoundsPlanes::get()
{
	return (nxSceneDesc->boundsPlanes == NX_TRUE);
}

void NxaSceneDescription::BoundsPlanes::set(bool value)
{
	nxSceneDesc->boundsPlanes = value;
}

NxaU32 NxaSceneDescription::Flags::get()
{
	return nxSceneDesc->flags;
}

void NxaSceneDescription::Flags::set(NxaU32 value)
{
	nxSceneDesc->flags = value;
}

NxaU32 NxaSceneDescription::SimulationThreadStackSize::get()
{
	return nxSceneDesc->simThreadStackSize;
}

void NxaSceneDescription::SimulationThreadStackSize::set(NxaU32 value)
{
	nxSceneDesc->simThreadStackSize = value;
}

NxaThreadPriority NxaSceneDescription::SimulationThreadPriority::get()
{
	return (NxaThreadPriority)nxSceneDesc->simThreadPriority;
}

void NxaSceneDescription::SimulationThreadPriority::set(NxaThreadPriority value)
{
	nxSceneDesc->simThreadPriority = (NxThreadPriority)value;
}

NxaU32 NxaSceneDescription::SimulationThreadMask::get()
{
	return nxSceneDesc->simThreadMask;
}

void NxaSceneDescription::SimulationThreadMask::set(NxaU32 value)
{
	nxSceneDesc->simThreadMask = value;
}

NxaU32 NxaSceneDescription::InternalThreadCount::get()
{
	return nxSceneDesc->internalThreadCount;
}

void NxaSceneDescription::InternalThreadCount::set(NxaU32 value)
{
	nxSceneDesc->internalThreadCount = value;
}

NxaU32 NxaSceneDescription::WorkerThreadStackSize::get()
{
	return nxSceneDesc->workerThreadStackSize;
}

void NxaSceneDescription::WorkerThreadStackSize::set(NxaU32 value)
{
	nxSceneDesc->workerThreadStackSize = value;
}

NxaThreadPriority NxaSceneDescription::WorkerThreadPriority::get()
{
	return (NxaThreadPriority)nxSceneDesc->workerThreadPriority;
}

void NxaSceneDescription::WorkerThreadPriority::set(NxaThreadPriority value)
{
	nxSceneDesc->workerThreadPriority = (NxThreadPriority)value;
}

NxaU32 NxaSceneDescription::ThreadMask::get()
{
	return nxSceneDesc->threadMask;
}

void NxaSceneDescription::ThreadMask::set(NxaU32 value)
{
	nxSceneDesc->threadMask = value;
}

NxaU32 NxaSceneDescription::BackgroundThreadCount::get()
{
	return nxSceneDesc->backgroundThreadCount;
}

void NxaSceneDescription::BackgroundThreadCount::set(NxaU32 value)
{
	nxSceneDesc->backgroundThreadCount = value;
}

NxaU32 NxaSceneDescription::BackgroundThreadMask::get()
{
	return nxSceneDesc->backgroundThreadMask;
}

void NxaSceneDescription::BackgroundThreadMask::set(NxaU32 value)
{
	nxSceneDesc->backgroundThreadMask = value;
}

NxaU32 NxaSceneDescription::UpAxis::get()
{
	return nxSceneDesc->upAxis;
}

void NxaSceneDescription::UpAxis::set(NxaU32 value)
{
	nxSceneDesc->upAxis = value;
}

NxaU32 NxaSceneDescription::SubdivisionLevel::get()
{
	return nxSceneDesc->subdivisionLevel;
}

void NxaSceneDescription::SubdivisionLevel::set(NxaU32 value)
{
	nxSceneDesc->subdivisionLevel = value;
}