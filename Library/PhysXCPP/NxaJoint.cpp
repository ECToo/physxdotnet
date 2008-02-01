#include "StdAfx.h"
#include "NxaJoint.h"


NxaJoint::NxaJoint(void)
{

}

void NxaJoint::setGlobalAnchor(Microsoft::Xna::Framework::Vector3 vec)
{
	nxJoint->setGlobalAnchor(NxaMath::Vector3XNAToPhysX(vec));
}

void NxaJoint::setGlobalAxis(Microsoft::Xna::Framework::Vector3 vec)
{
	nxJoint->setGlobalAxis(NxaMath::Vector3XNAToPhysX(vec));
}

Vector3 NxaJoint::getGlobalAnchor()
{
	return NxaMath::Vector3PhysXToXNA(nxJoint->getGlobalAnchor());
}

Vector3 NxaJoint::getGlobalAxis()
{
	return NxaMath::Vector3PhysXToXNA(nxJoint->getGlobalAxis());
}

//NxJointState getState(); <-- recreate this enum?

void NxaJoint::setBreakable(float maxForce, float maxTorque)
{
	nxJoint->setBreakable(maxForce, maxTorque);
}