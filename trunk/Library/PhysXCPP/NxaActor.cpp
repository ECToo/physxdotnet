#include "StdAfx.h"
#include "NxaActor.h"
#include "Nxp.h"
#include "NxaSphereShape.h"

using namespace PhysXCPP;

NxaActor::NxaActor()
{
}

NxaActor::!NxaActor()
{
	delete nxaActorDesc;
}

NxaActor::NxaActor(NxActor* actor, NxaActorDescription^ actorDesc)
{
	nxActor = actor;
	nxaActorDesc = actorDesc;
}

void NxaActor::AddForce(Vector3 force)
{
	nxActor->addForce(NxVec3(force.X, force.Y, force.Z));
}

NxaShape^ NxaActor::CreateShape(NxaShapeDescription^ shapeDesc)
{
	NxShape* shapePtr = nxActor->createShape(*(shapeDesc->nxShapeDesc));
	//nxaActorDesc->AddShape(shapeDesc);

	NxaShape^ newShape;

	/*switch(shapePtr->getType())
	{
		case NX_SHAPE_SPHERE : newShape = gcnew NxaSphereShape(shapePtr->isSphere()->getRadius());
	}*/

	return newShape;
}

array<NxaShape^>^ NxaActor::GetShapes()
{
	int numShapes = nxActor->getNbShapes();
	array<NxaShape^>^ shapeArray = gcnew array<NxaShape^>(numShapes);

	NxShape* const* ptr = nxActor->getShapes();

	for(int p = 0; p < numShapes; p++)
	{
		shapeArray[p] = NxaShape::CreateFromPointer(ptr[p]);
	}

	return shapeArray;
}

Matrix NxaActor::GetGlobalOrientation()
{
	NxMat33 rot = nxActor->getGlobalOrientation();
	NxVec3 row1 = rot.getColumn(0);
	NxVec3 row2 = rot.getColumn(1);
	NxVec3 row3 = rot.getColumn(2);

	return Matrix(row1.x, row1.y, row1.z, 0, row2.x, row2.y, row2.z, 0, row3.x, row3.y, row3.z, 0, 0, 0, 0, 1);
}

Quaternion NxaActor::GetGlobalOrientationQuaternion()
{
	NxQuat quat = nxActor->getGlobalOrientationQuat();
	return Quaternion(quat.x, quat.y, quat.z, quat.w);
}

Vector3 NxaActor::GetGlobalPosition()
{
	NxVec3 pos = nxActor->getGlobalPosition();
	return Vector3(pos.x, pos.y, pos.z);
}

void NxaActor::ClearActorFlag(NxaActorFlag flag)
{
	if((int)flag && (int)NxaActorFlag::Disable_Collision)
		nxActor->clearActorFlag(NX_AF_DISABLE_COLLISION);
}

void NxaActor::RaiseActorFlag(NxaActorFlag flag)
{
	if((int)flag && (int)NxaActorFlag::Disable_Collision)
		nxActor->raiseActorFlag(NX_AF_DISABLE_COLLISION);
}

void NxaActor::ClearBodyFlag(NxaBodyFlag flag)
{
	if((int)flag && (int)NxaBodyFlag::Disable_Gravity)
		nxActor->clearBodyFlag(NX_BF_DISABLE_GRAVITY);
	if ((int)flag && (int)NxaBodyFlag::Kinematic)
		nxActor->clearBodyFlag(NX_BF_KINEMATIC);
}

void NxaActor::RaiseBodyFlag(NxaBodyFlag flag)
{
	if((int)flag && (int)NxaBodyFlag::Disable_Gravity)
		nxActor->raiseBodyFlag(NX_BF_DISABLE_GRAVITY);
	if((int)flag && (int)NxaBodyFlag::Kinematic)
		nxActor->raiseBodyFlag(NX_BF_KINEMATIC);
}

void NxaActor::SetGlobalPose(Matrix m)
{
	NxMat34 pose;
	pose.M.setColumn(0, NxVec3(m.M11, m.M12, m.M13));
	pose.M.setColumn(1, NxVec3(m.M21, m.M22, m.M23));
	pose.M.setColumn(2, NxVec3(m.M31, m.M32, m.M33));
	pose.t.set(NxVec3(m.M41, m.M42, m.M43));

	nxActor->setGlobalPose(pose);
}

void NxaActor::SetGlobalPosition(Vector3 position)
{
	nxActor->setGlobalPosition(NxVec3(position.X, position.Y, position.Z));
}

void NxaActor::SetSleepAngularVelocity(float velocity)
{
	nxActor->setSleepAngularVelocity(velocity);
}

void NxaActor::SetSleepLinearVelocity(float velocity)
{
	nxActor->setSleepLinearVelocity(velocity);
}

void NxaActor::SetSolverIterationCount(int count)
{
	nxActor->setSolverIterationCount(count);
}

void NxaActor::WakeUp(float timeout)
{
	nxActor->wakeUp(timeout);
}