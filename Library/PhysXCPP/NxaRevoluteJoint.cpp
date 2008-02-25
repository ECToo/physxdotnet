#include "StdAfx.h"
#include "NxaRevoluteJoint.h"
#include "NxaRevoluteJointDescription.h"

#include "NxRevoluteJoint.h"
#include "NxRevoluteJointDesc.h"

NxaRevoluteJoint::NxaRevoluteJoint(NxRevoluteJoint* ptr)
{
	nxJoint = ptr;
}

void NxaRevoluteJoint::LoadFromDescription(NxaRevoluteJointDescription ^desc)
{
	NxRevoluteJoint* ptr = (NxRevoluteJoint*)nxJoint;
	NxRevoluteJointDesc revoluteDesc = desc->ConvertToNative();
	ptr->loadFromDesc(revoluteDesc);
}

void NxaRevoluteJoint::SaveToDescription([Out] NxaRevoluteJointDescription^% desc)
{
	NxRevoluteJoint* ptr = (NxRevoluteJoint*)nxJoint;

	NxRevoluteJointDesc revoluteDesc;
	ptr->saveToDesc(revoluteDesc);

	desc->LoadFromNative(revoluteDesc);
}

void NxaRevoluteJoint::SetLimits(NxaJointLimitPairDescription^ pair)
{
	NxRevoluteJoint* ptr = (NxRevoluteJoint*)nxJoint;
	ptr->setLimits(pair->ConvertToNative());
}

void NxaRevoluteJoint::GetLimits([Out] NxaJointLimitPairDescription^% pair)
{
	throw gcnew Exception("NOT YET IMPLEMENTED");
}

void NxaRevoluteJoint::SetMotor(NxaMotorDescription^ motor)
{
	((NxRevoluteJoint*)nxJoint)->setMotor(
		NxMotorDesc(motor->VelocityTarget, motor->MaxForce, motor->FreeSpin));
}

void NxaRevoluteJoint::GetMotor([Out] NxaMotorDescription^% motor)
{
	NxMotorDesc nxMotor;
	((NxRevoluteJoint*)nxJoint)->getMotor(nxMotor);
	motor->VelocityTarget = nxMotor.velTarget;
	motor->MaxForce = nxMotor.maxForce;
	motor->FreeSpin = (nxMotor.freeSpin == NX_TRUE);
}

void NxaRevoluteJoint::SetSpring(NxaSpringDescription^ spring)
{
	NxRevoluteJoint* ptr = (NxRevoluteJoint*)nxJoint;
	ptr->setSpring(spring->ConvertToNative());
}

void NxaRevoluteJoint::GetSpring([Out] NxaSpringDescription^% spring)
{
	NxSpringDesc nxSpring;
	((NxRevoluteJoint*)nxJoint)->getSpring(nxSpring);
	spring->LoadFromNative(nxSpring);
}

float NxaRevoluteJoint::GetAngle()
{
	return ((NxRevoluteJoint*)nxJoint)->getAngle();
}

float NxaRevoluteJoint::GetVelocity()
{
	return ((NxRevoluteJoint*)nxJoint)->getVelocity();
}

void NxaRevoluteJoint::SetFlags(NxaRevoluteJointFlag flag)
{
	((NxRevoluteJoint*)nxJoint)->setFlags((NxU32)flag);
}

NxaRevoluteJointFlag NxaRevoluteJoint::GetFlags()
{
	return (NxaRevoluteJointFlag)(((NxRevoluteJoint*)nxJoint)->getFlags());
}

void NxaRevoluteJoint::SetProjectionMode(NxaJointProjectionMode mode)
{
	((NxRevoluteJoint*)nxJoint)->setProjectionMode((NxJointProjectionMode)mode);
}

NxaJointProjectionMode NxaRevoluteJoint::GetProjectionMode()
{
	return (NxaJointProjectionMode)(((NxRevoluteJoint*)nxJoint)->getProjectionMode());
}