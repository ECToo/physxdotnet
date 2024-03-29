#include "StdAfx.h"
#include "NxaJoint.h"

#include "NxaDistanceJoint.h"
#include "NxaFixedJoint.h"
#include "NxaPrismaticJoint.h"
#include "NxaPointOnLineJoint.h"
#include "NxaRevoluteJoint.h"
#include "NxaSphericalJoint.h"
#include "NxaD6Joint.h"
#include "NxContainer.h"

NxaJoint^ NxaJoint::CreateFromPointer(NxJoint* ptr)
{
	if(ptr != NULL)
	{
		switch(ptr->getType())
		{
		case NX_JOINT_PRISMATIC :
			return gcnew NxaPrismaticJoint((NxPrismaticJoint*)ptr);
		case NX_JOINT_REVOLUTE :
			return gcnew NxaRevoluteJoint((NxRevoluteJoint*)ptr);
		case NX_JOINT_SPHERICAL :
			return gcnew NxaSphericalJoint((NxSphericalJoint*)ptr);
		case NX_JOINT_POINT_ON_LINE :
			return gcnew NxaPointOnLineJoint((NxPointOnLineJoint*)ptr);
		case NX_JOINT_POINT_IN_PLANE :
			throw gcnew Exception("NOT IMPLEMENTED PROPERLY!");
			return nullptr;
		case NX_JOINT_DISTANCE :
			return gcnew NxaDistanceJoint((NxDistanceJoint*)ptr);
		case NX_JOINT_PULLEY :
			throw gcnew Exception("NOT IMPLEMENTED PROPERLY!");
			return nullptr;
		case NX_JOINT_FIXED :
			return gcnew NxaFixedJoint((NxFixedJoint*)ptr);
		case NX_JOINT_D6 :
			return gcnew NxaD6Joint((NxD6Joint*)ptr);
		}
	}

	return nullptr;
}

void NxaJoint::GetActors([Out] NxaActor^% actor1, [Out] NxaActor^% actor2)
{
	NxActor* a1;
	NxActor* a2;
	nxJoint->getActors(&a1, &a2);
	actor1 = NxActorContainer::GetInstance()->Find(IntPtr(a1));
	actor2 = NxActorContainer::GetInstance()->Find(IntPtr(a2));
}

void NxaJoint::SetGlobalAnchor(Vector3 vec)
{
	nxJoint->setGlobalAnchor(NxaMath::Vector3XNAToPhysX(vec));
}

void NxaJoint::SetGlobalAxis(Vector3 vec)
{
	nxJoint->setGlobalAxis(NxaMath::Vector3XNAToPhysX(vec));
}

Vector3 NxaJoint::GetGlobalAnchor()
{
	return NxaMath::Vector3PhysXToXNA(nxJoint->getGlobalAnchor());
}

Vector3 NxaJoint::GetGlobalAxis()
{
	return NxaMath::Vector3PhysXToXNA(nxJoint->getGlobalAxis());
}

NxaJointState NxaJoint::GetState()
{
	return (NxaJointState)nxJoint->getState();
}

void NxaJoint::SetBreakable(float maxForce, float maxTorque)
{
	nxJoint->setBreakable(maxForce, maxTorque);
}

void NxaJoint::GetBreakable([Out] float% maxForce, [Out] float% maxTorque)
{
	float F, T;
	nxJoint->getBreakable(F, T);
	maxForce = F;
	maxTorque = T;
}

/********Limits**********/

void NxaJoint::SetLimitPoint(Vector3 point, bool pointIsOnActor2)
{
	nxJoint->setLimitPoint(NxaMath::Vector3XNAToPhysX(point), pointIsOnActor2);
}

void NxaJoint::SetLimitPoint(Vector3 point)
{
	nxJoint->setLimitPoint(NxaMath::Vector3XNAToPhysX(point));
}

bool NxaJoint::GetLimitPoint([Out] Vector3% worldLimitPoint)
{
	NxVec3 nxV;
	bool r = nxJoint->getLimitPoint(nxV);
	NxaMath::Vector3PhysXToXNA(nxV, worldLimitPoint);
	return r;
}

bool NxaJoint::AddLimitPlane(Vector3 normal, Vector3 pointInPlane, float restitution)
{
	return nxJoint->addLimitPlane(NxaMath::Vector3XNAToPhysX(normal), NxaMath::Vector3XNAToPhysX(pointInPlane), restitution);
}

bool NxaJoint::AddLimitPlane(Vector3 normal, Vector3 pointInPlane)
{
	return nxJoint->addLimitPlane(NxaMath::Vector3XNAToPhysX(normal), NxaMath::Vector3XNAToPhysX(pointInPlane));
}

bool NxaJoint::GetNextLimitPlane([Out] Vector3% planeNormal, [Out] float planeD, [Out] float restitution)
{
	NxVec3 nxV;
	bool r = nxJoint->getNextLimitPlane(nxV, planeD, &restitution);
	NxaMath::Vector3PhysXToXNA(nxV, planeNormal);
	return r;
}

/************************/

bool NxaJoint::Is(NxaJointType type)
{
	switch(type)
	{
	case NxaJointType::Prismatic : return (this->IsPrismaticJoint());
	case NxaJointType::Revolute : return (this->IsRevoluteJoint());
	case NxaJointType::Cylindrical : return (this->IsCylindricalJoint());
	case NxaJointType::Spherical : return (this->IsSphericalJoint());
	case NxaJointType::PointOnLine : return (this->IsPointOnLineJoint());
	case NxaJointType::PointInPlane : return (this->IsPointInPlaneJoint());
	case NxaJointType::Distance : return (this->IsDistanceJoint());
	case NxaJointType::Pulley : return (this->IsPulleyJoint());
	case NxaJointType::Fixed : return (this->IsFixedJoint());
	case NxaJointType::D6 : return (this->IsD6Joint());
	}

	return false;
}

/************************/

void NxaJoint::SetName(String^ name)
{
	jointName = name;
}

String^ NxaJoint::GetName()
{
	return jointName;
}

NxaScene^ NxaJoint::GetScene()
{
	return NxSceneContainer::GetInstance()->Find(IntPtr(&(nxJoint->getScene())));
}
