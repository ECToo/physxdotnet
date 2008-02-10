#include "StdAfx.h"
#include "NxaD6Joint.h"
#include "NxaD6JointDescription.h"

#include "NxD6Joint.h"


NxaD6Joint::NxaD6Joint(NxD6Joint* nxD6Joint)
{
	nxJoint = nxD6Joint;
}

void NxaD6Joint::LoadFromDescription(NxaD6JointDescription ^desc)
{
	NxD6JointDesc* nxDesc = (NxD6JointDesc*)(desc->nxJointDesc);
	((NxD6Joint*)nxJoint)->loadFromDesc(*nxDesc);
}

void NxaD6Joint::SaveToDescription([Out] NxaD6JointDescription^% desc)
{
	NxD6JointDesc* ptr = (NxD6JointDesc*)desc->nxJointDesc;
	((NxD6Joint*)nxJoint)->saveToDesc(*ptr);
}

void NxaD6Joint::SetDrivePosition(Vector3 position)
{
	NxD6Joint* ptr = (NxD6Joint*)nxJoint;
	ptr->setDrivePosition(NxaMath::Vector3XNAToPhysX(position));
}

void NxaD6Joint::SetDriveOrientation(Quaternion orientation)
{
	NxD6Joint* ptr = (NxD6Joint*)nxJoint;
	ptr->setDriveOrientation(NxaMath::QuaternionXNAToPhysX(orientation));
}

void NxaD6Joint::SetDriveLinearVelocity(Vector3 linearVelocity)
{
	NxD6Joint* ptr = (NxD6Joint*)nxJoint;
	ptr->setDriveLinearVelocity(NxaMath::Vector3XNAToPhysX(linearVelocity));
}

void NxaD6Joint::SetDriveAngularVelocity(Vector3 angularVelocity)
{
	NxD6Joint* ptr = (NxD6Joint*)nxJoint;
	ptr->setDriveAngularVelocity(NxaMath::Vector3XNAToPhysX(angularVelocity));
}