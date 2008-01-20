#include "StdAfx.h"
#include "Nxp.h"
#include "NxaActor.h"
#include "NxaMath.h"
//#include "NxaSphereShape.h"

#include "NxaShape.h"

#include "NxActor.h"
#include "NxShape.h"
#include "NxMat33.h"

NxaActor::NxaActor(NxActor* ptr)
{
	nxActor = ptr;
}

void NxaActor::AddForce(Vector3 force)
{
	nxActor->addForce(NxaMath::Vector3XNAToPhysX(force));
}

void NxaActor::AddForce([In] Vector3% force)
{
	nxActor->addForce(NxaMath::Vector3XNAToPhysX(force));
}

void NxaActor::AddTorque(Vector3 torque)
{
	nxActor->addTorque(NxaMath::Vector3XNAToPhysX(torque));
}

void NxaActor::AddTorque([In] Vector3% torque)
{
	nxActor->addTorque(NxaMath::Vector3XNAToPhysX(torque));
}

NxaShape^ NxaActor::CreateShape(NxaShapeDescription^ shapeDesc)
{
	NxShape* shapePtr = nxActor->createShape(*(shapeDesc->nxShapeDesc));
	//nxaActorDesc->AddShape(shapeDesc);

	NxaShape^ newShape;

	//TODO Fix!

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

void NxaActor::GetGlobalOrientation(Matrix %m)
{
	Quaternion q;
	GetGlobalOrientationQuaternion(q);
	Matrix::CreateFromQuaternion(q, m);

	/*NxMat33 rot = nxActor->getGlobalOrientation();
	NxVec3 row1 = rot.getColumn(0);
	NxVec3 row2 = rot.getColumn(1);
	NxVec3 row3 = rot.getColumn(2);

	m.M11 = row1.x;		m.M12 = row1.y;		m.M13 = row1.z;		m.M14 = 0;
	m.M21 = row2.x;		m.M22 = row2.y;		m.M23 = row2.z;		m.M24 = 0;
	m.M31 = row3.x;		m.M32 = row3.y;		m.M33 = row3.z;		m.M34 = 0;
	m.M41 = 0;			m.M42 = 0;			m.M43 = 0;			m.M44 = 1;*/
}


Quaternion NxaActor::GetGlobalOrientationQuaternion()
{
	NxQuat quat = nxActor->getGlobalOrientationQuat();
	return Quaternion(quat.x, quat.y, quat.z, quat.w);
}

void NxaActor::GetGlobalOrientationQuaternion(Quaternion% orientation)
{
	NxQuat quat = nxActor->getGlobalOrientationQuat();
	NxaMath::QuaternionPhysXToXNA(quat, orientation);
}

Vector3 NxaActor::GetGlobalPosition()
{
	NxVec3 pos = nxActor->getGlobalPosition();
	return Vector3(pos.x, pos.y, pos.z);
}

void NxaActor::GetGlobalPosition([Out] Vector3% position)
{
	NxVec3 pos = nxActor->getGlobalPosition();
	NxaMath::Vector3PhysXToXNA(pos, position);
}

void NxaActor::ClearActorFlag(NxaActorFlag flag)
{
	//TODO Fix!
	if((int)flag && (int)NxaActorFlag::Disable_Collision)
		nxActor->clearActorFlag(NX_AF_DISABLE_COLLISION);
}

void NxaActor::RaiseActorFlag(NxaActorFlag flag)
{
	//TODO Fix!
	if((int)flag && (int)NxaActorFlag::Disable_Collision)
		nxActor->raiseActorFlag(NX_AF_DISABLE_COLLISION);
}

void NxaActor::ClearBodyFlag(NxaBodyFlag flag)
{
	//TODO Fix!
	if((int)flag && (int)NxaBodyFlag::Disable_Gravity)
		nxActor->clearBodyFlag(NX_BF_DISABLE_GRAVITY);
	if ((int)flag && (int)NxaBodyFlag::Kinematic)
		nxActor->clearBodyFlag(NX_BF_KINEMATIC);
}

void NxaActor::RaiseBodyFlag(NxaBodyFlag flag)
{
	//TODO Fix!
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