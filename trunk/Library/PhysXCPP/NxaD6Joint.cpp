#include "StdAfx.h"
#include "NxaD6Joint.h"
#include "NxaD6JointDescription.h"

#include "NxD6Joint.h"
#include "NxD6JointDesc.h"


NxaD6Joint::NxaD6Joint(NxD6Joint* nxD6Joint)
{
	nxJoint = nxD6Joint;
}

void NxaD6Joint::LoadFromDescription(NxaD6JointDescription ^desc)
{
	NxD6Joint* ptr = (NxD6Joint*)nxJoint;
	NxD6JointDesc d6Desc = desc->ConvertToNative();
	ptr->loadFromDesc(d6Desc);
}

void NxaD6Joint::SaveToDescription([Out] NxaD6JointDescription^% desc)
{
	NxD6Joint* ptr = (NxD6Joint*)nxJoint;

	NxD6JointDesc d6desc;
	ptr->saveToDesc(d6desc);

	desc->LoadFromNative(d6desc);
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