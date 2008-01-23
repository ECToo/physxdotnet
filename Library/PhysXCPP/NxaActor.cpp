#include "StdAfx.h"
#include "Nxp.h"
#include "NxaActor.h"
#include "NxaMath.h"

#include "NxaShape.h"
#include "NxaScene.h"

#include "NxActor.h"
#include "NxShape.h"
#include "NxMat33.h"

NxaActor::NxaActor(NxActor* ptr)
{
	nxActor = ptr;
}

NxaScene^ NxaActor::GetScene()
{
	return gcnew NxaScene(&(nxActor->getScene()));
}

void NxaActor::SetName(String^ name)
{
	actorName = name;
}

String^ NxaActor::GetName()
{
	return actorName;
}

void NxaActor::SetGroup(NxaActorGroup actorGroup)
{
	nxActor->setGroup(actorGroup);
}

NxaActorGroup NxaActor::GetGroup()
{
	return nxActor->getGroup();
}

void NxaActor::SetDominanceGroup(NxaDominanceGroup dominanceGroup)
{
	nxActor->setDominanceGroup(dominanceGroup);
}

NxaDominanceGroup NxaActor::GetDominanceGroup()
{
	return nxActor->getDominanceGroup();
}

void NxaActor::ClearActorFlag(NxaActorFlag flag)
{
	nxActor->clearActorFlag((NxActorFlag)flag);
}

void NxaActor::RaiseActorFlag(NxaActorFlag flag)
{
	nxActor->raiseActorFlag((NxActorFlag)flag);
}

bool NxaActor::ReadActorFlag(NxaActorFlag flag)
{
	return nxActor->readActorFlag((NxActorFlag)flag);
}

void NxaActor::ResetUserActorPairFiltering()
{
	nxActor->resetUserActorPairFiltering();
}

bool NxaActor::IsDynamic()
{
	return nxActor->isDynamic();
}

float NxaActor::ComputeKineticEnergy()
{
	return nxActor->computeKineticEnergy();
}

void NxaActor::RaiseBodyFlag(NxaBodyFlag flag)
{
	nxActor->clearBodyFlag((NxBodyFlag)flag);
}

void NxaActor::ClearBodyFlag(NxaBodyFlag flag)
{
	nxActor->clearBodyFlag((NxBodyFlag)flag);
}

bool NxaActor::ReadBodyFlag(NxaBodyFlag flag)
{
	return nxActor->readBodyFlag((NxBodyFlag) flag);
}

bool NxaActor::SaveBodyToDescription([Out] NxaBodyDescription ^%bodyDesc)
{
	return nxActor->saveBodyToDesc(*(bodyDesc->nxBodyDesc));
}

void NxaActor::SetSolverIterationCount(NxaU32 count)
{
	nxActor->setSolverIterationCount(count);
}

NxaU32 NxaActor::GetSolverIterationCount()
{
	return nxActor->getSolverIterationCount();
}

void NxaActor::RecomputeAdaptiveForceCounters()
{
	nxActor->recomputeAdaptiveForceCounters();
}

void NxaActor::SetGlobalPose(Matrix m)
{
	nxActor->setGlobalPose(NxaMath::MatrixRotPosXNAToPhysX(m));
}

void NxaActor::SetGlobalPosition(Vector3 position)
{
	nxActor->setGlobalPosition(NxaMath::Vector3XNAToPhysX(position));
}

void NxaActor::SetGlobalOrientation(Matrix matrix)
{
	nxActor->setGlobalOrientation(NxaMath::MatrixRotXNAToPhysX(matrix));
}

void NxaActor::SetGlobalOrientationQuaternion(Quaternion quaternion)
{
	nxActor->setGlobalOrientationQuat(NxaMath::QuaternionXNAToPhysX(quaternion));
}

Matrix NxaActor::GetGlobalPose()
{
	return NxaMath::MatrixPhysXToXNA(nxActor->getGlobalPose());
}

Vector3 NxaActor::GetGlobalPosition()
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getGlobalPosition());
}

Matrix NxaActor::GetGlobalOrientation()
{
	return NxaMath::MatrixPhysXToXNA(nxActor->getGlobalOrientation());
}

Quaternion NxaActor::GetGlobalOrientationQuaternion()
{
	return NxaMath::QuaternionPhysXToXNA(nxActor->getGlobalOrientationQuat());
}

void NxaActor::MoveGlobalPose(Matrix pose)
{
	nxActor->moveGlobalPose(NxaMath::MatrixRotPosXNAToPhysX(pose));
}

void NxaActor::MoveGlobalPosition(Vector3 position)
{
	nxActor->moveGlobalPosition(NxaMath::Vector3XNAToPhysX(position));
}

void NxaActor::MoveGlobalOrientation(Matrix orientation)
{
	nxActor->moveGlobalOrientation(NxaMath::MatrixRotXNAToPhysX(orientation));
}

void NxaActor::MoveGlobalOrientationQuaternion(Quaternion orientation)
{
	nxActor->moveGlobalOrientationQuat(NxaMath::QuaternionXNAToPhysX(orientation));
}

NxaShape^ NxaActor::CreateShape(NxaShapeDescription^ shapeDesc)
{
	NxShape* shapePtr = nxActor->createShape(*(shapeDesc->nxShapeDesc));
	return NxaShape::CreateFromPointer(shapePtr);
}

void NxaActor::ReleaseShape(NxaShape^ shape)
{
	nxActor->releaseShape(*(shape->nxShape));
}

NxaU32 NxaActor::GetNumberOfShapes()
{
	return nxActor->getNbShapes();
}

array<NxaShape^>^ NxaActor::GetShapes()
{
	NxaU32 numShapes = nxActor->getNbShapes();
	array<NxaShape^>^ shapeArray = gcnew array<NxaShape^>(numShapes);

	NxShape* const* ptr = nxActor->getShapes();

	for(int p = 0; p < numShapes; p++)
		shapeArray[p] = NxaShape::CreateFromPointer(ptr[p]);

	return shapeArray;
}

void NxaActor::SetCenterOfMassOffsetLocalPose(Matrix pose)
{
	nxActor->setCMassOffsetLocalPose(NxaMath::MatrixRotPosXNAToPhysX(pose));
}

void NxaActor::SetCenterOfMassOffsetLocalPosition(Vector3 position)
{
	nxActor->setCMassOffsetLocalPosition(NxaMath::Vector3XNAToPhysX(position));
}

void NxaActor::SetCenterOfMassOffsetLocalOrientation(Matrix orientation)
{
	nxActor->setCMassOffsetLocalOrientation(NxaMath::MatrixRotXNAToPhysX(orientation));
}

void NxaActor::SetCenterOfMassOffsetGlobalPose(Matrix pose)
{
	nxActor->setCMassOffsetGlobalPose(NxaMath::MatrixRotPosXNAToPhysX(pose));
}

void NxaActor::SetCenterOfMassOffsetGlobalPosition(Vector3 position)
{
	nxActor->setCMassOffsetGlobalPosition(NxaMath::Vector3XNAToPhysX(position));
}

void NxaActor::SetCenterOfMassOffsetGlobalOrientation(Matrix orientation)
{
	nxActor->setCMassOffsetGlobalOrientation(NxaMath::MatrixRotXNAToPhysX(orientation));
}

void NxaActor::SetCenterOfMassGlobalPose(Matrix pose)
{
	nxActor->setCMassGlobalPose(NxaMath::MatrixRotPosXNAToPhysX(pose));
}

void NxaActor::SetCenterOfMassGlobalPosition(Vector3 position)
{
	nxActor->setCMassGlobalPosition(NxaMath::Vector3XNAToPhysX(position));
}

void NxaActor::SetCenterOfMassGlobalOrientation(Matrix orientation)
{
	nxActor->setCMassGlobalOrientation(NxaMath::MatrixRotXNAToPhysX(orientation));
}

Matrix NxaActor::GetCenterOfMassLocalPose()
{
	return NxaMath::MatrixPhysXToXNA(nxActor->getCMassLocalPose());
}

Vector3 NxaActor::GetCenterOfMassLocalPosition()
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getCMassLocalPosition());
}

Matrix NxaActor::GetCenterOfMassLocalOrientation()
{
	return NxaMath::MatrixPhysXToXNA(nxActor->getCMassLocalOrientation());
}

Matrix NxaActor::GetCenterOfMassGlobalPose()
{
	return NxaMath::MatrixPhysXToXNA(nxActor->getCMassGlobalPose());
}

Vector3 NxaActor::GetCenterOfMassGlobalPosition()
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getCMassGlobalPosition());
}

Matrix NxaActor::GetCenterOfMassGlobalOrientation()
{
	return NxaMath::MatrixPhysXToXNA(nxActor->getCMassGlobalOrientation());
}

void NxaActor::SetMass(float mass)
{
	nxActor->setMass(mass);
}

float NxaActor::GetMass()
{
	return nxActor->getMass();
}

void NxaActor::SetMassSpaceInertiaTensor(Vector3 tensor)
{
	nxActor->setMassSpaceInertiaTensor(NxaMath::Vector3XNAToPhysX(tensor));
}

Vector3 NxaActor::GetMassSpaceInertiaTensor()
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getMassSpaceInertiaTensor());
}

Matrix NxaActor::GetGlobalInertiaTensor()
{
	return NxaMath::MatrixPhysXToXNA(nxActor->getGlobalInertiaTensor());
}

Matrix NxaActor::GetGlobalInertiaTensorInverse()
{
	return NxaMath::MatrixPhysXToXNA(nxActor->getGlobalInertiaTensorInverse());
}

void NxaActor::UpdateMassFromShapes(float density, float totalMass)
{
	nxActor->updateMassFromShapes(density, totalMass);
}

void NxaActor::SetLinearDamping(float linearDamping)
{
	nxActor->setLinearDamping(linearDamping);
}

float NxaActor::GetLinearDamping()
{
	return nxActor->getLinearDamping();
}

void NxaActor::SetAngularDamping(float angularDamping)
{
	nxActor->setAngularDamping(angularDamping);
}

float NxaActor::GetAngularDamping()
{
	return nxActor->getAngularDamping();
}

void NxaActor::SetLinearVelocity(Vector3 linearVelocity)
{
	nxActor->setLinearVelocity(NxaMath::Vector3XNAToPhysX(linearVelocity));
}

void NxaActor::SetAngularVelocity(Vector3 angularVelocity)
{
	nxActor->setAngularVelocity(NxaMath::Vector3XNAToPhysX(angularVelocity));
}

Vector3 NxaActor::GetLinearVelocity()
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getLinearVelocity());
}

Vector3 NxaActor::GetAngularVelocity()
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getAngularVelocity());
}

void NxaActor::SetMaxAngularVelocity(float maxAngularVelocity)
{
	nxActor->setMaxAngularVelocity(maxAngularVelocity);
}

float NxaActor::GetMaxAngularVelocity()
{
	return nxActor->getMaxAngularVelocity();
}

void NxaActor::SetCCDMotionThreshold(float threshold)
{
	nxActor->setCCDMotionThreshold(threshold);
}

float NxaActor::GetCCDMotionThreshold()
{
	return nxActor->getCCDMotionThreshold();
}

void NxaActor::SetLinearMomentum(Vector3 linearMomentum)
{
	nxActor->setLinearMomentum(NxaMath::Vector3XNAToPhysX(linearMomentum));
}

void NxaActor::SetAngularMomentum(Vector3 angularMomentum)
{
	nxActor->setAngularMomentum(NxaMath::Vector3XNAToPhysX(angularMomentum));
}

Vector3 NxaActor::GetLinearMomentum()
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getLinearMomentum());
}

Vector3 NxaActor::GetAngularMomentum()
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getAngularMomentum());
}

void NxaActor::AddForceAtPosition(Vector3 force, Vector3 position, NxaForceMode forceMode, bool wakeup)
{
	nxActor->addForceAtPos(NxaMath::Vector3XNAToPhysX(force), NxaMath::Vector3XNAToPhysX(position), (NxForceMode)forceMode, wakeup);
}

void NxaActor::AddForceAtLocalPosition(Vector3 force, Vector3 position, NxaForceMode forceMode, bool wakeup)
{
	nxActor->addForceAtLocalPos(NxaMath::Vector3XNAToPhysX(force), NxaMath::Vector3XNAToPhysX(position), (NxForceMode)forceMode, wakeup);
}

void NxaActor::AddLocalForceAtPosition(Vector3 force, Vector3 position, NxaForceMode forceMode, bool wakeup)
{
	nxActor->addLocalForceAtPos(NxaMath::Vector3XNAToPhysX(force), NxaMath::Vector3XNAToPhysX(position), (NxForceMode)forceMode, wakeup);
}

void NxaActor::AddLocalForceAtLocalPosition(Vector3 force, Vector3 position, NxaForceMode forceMode, bool wakeup)
{
	nxActor->addLocalForceAtLocalPos(NxaMath::Vector3XNAToPhysX(force), NxaMath::Vector3XNAToPhysX(position), (NxForceMode)forceMode, wakeup);
}

void NxaActor::AddForce(Vector3 force, NxaForceMode forceMode, bool wakeup)
{
	nxActor->addForce(NxaMath::Vector3XNAToPhysX(force), (NxForceMode)forceMode, wakeup);
}

void NxaActor::AddLocalForce(Vector3 force, NxaForceMode forceMode, bool wakeup)
{
	nxActor->addLocalForce(NxaMath::Vector3XNAToPhysX(force), (NxForceMode)forceMode, wakeup);
}

void NxaActor::AddTorque(Vector3 torque, NxaForceMode forceMode, bool wakeup)
{
	nxActor->addTorque(NxaMath::Vector3XNAToPhysX(torque), (NxForceMode)forceMode, wakeup);
}

void NxaActor::AddLocalTorque(Vector3 torque, NxaForceMode forceMode, bool wakeup)
{
	nxActor->addLocalTorque(NxaMath::Vector3XNAToPhysX(torque), (NxForceMode)forceMode, wakeup);
}

Vector3 NxaActor::GetPointVelocity(Vector3 point)
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getPointVelocity(NxaMath::Vector3XNAToPhysX(point)));
}

Vector3 NxaActor::GetLocalPointVelocity(Vector3 point)
{
	return NxaMath::Vector3PhysXToXNA(nxActor->getLocalPointVelocity(NxaMath::Vector3XNAToPhysX(point)));
}

bool NxaActor::IsGroupSleeping()
{
	return nxActor->isGroupSleeping();
}

bool NxaActor::IsSleeping()
{
	return nxActor->isGroupSleeping();
}

float NxaActor::GetSleepLinearVelocity()
{
	return nxActor->getSleepLinearVelocity();
}

void NxaActor::SetSleepLinearVelocity(float velocity)
{
	nxActor->setSleepLinearVelocity(velocity);
}

float NxaActor::GetSleepAngularVelocity()
{
	return nxActor->getSleepAngularVelocity();
}

void NxaActor::SetSleepAngularVelocity(float velocity)
{
	nxActor->setSleepAngularVelocity(velocity);
}

float NxaActor::GetSleepEnergyThreshold()
{
	return nxActor->getSleepEnergyThreshold();
}

void NxaActor::SetSleepEnergyThreshold(float threshold)
{
	nxActor->setSleepEnergyThreshold(threshold);
}

void NxaActor::WakeUp(float timeout)
{
	nxActor->wakeUp(timeout);
}

void NxaActor::PutToSleep()
{
	nxActor->putToSleep();
}