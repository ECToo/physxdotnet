#include "StdAfx.h"

#include "NxRevoluteJoint.h"

#include "NxaRevoluteJoint.h"


NxaRevoluteJoint::NxaRevoluteJoint(NxRevoluteJoint* ptr)
{
	nxJoint = ptr;
}

void NxaRevoluteJoint::LoadFromDescription(NxaRevoluteJointDescription ^desc)
{
	NxRevoluteJointDesc* nxDesc = (NxRevoluteJointDesc*)(desc->nxJointDesc);
	((NxRevoluteJoint*)nxJoint)->loadFromDesc(*nxDesc);
}

void NxaRevoluteJoint::SaveToDescription([Out] NxaRevoluteJointDescription^% desc)
{
	NxRevoluteJointDesc nxDesc;
	((NxRevoluteJoint*)nxJoint)->saveToDesc(nxDesc);
	desc = gcnew NxaRevoluteJointDescription(&nxDesc);
}

void NxaRevoluteJoint::SetLimits(NxaJointLimitPairDescription^ pair)
{
	((NxRevoluteJoint*)nxJoint)->setLimits(*(pair->nxJointLimitPairDesc));
}

void NxaRevoluteJoint::GetLimits([Out] NxaJointLimitPairDescription^% pair)
{
	NxJointLimitPairDesc nxPair;
	((NxRevoluteJoint*)nxJoint)->getLimits(nxPair);
	pair = gcnew NxaJointLimitPairDescription(&nxPair);
}

void NxaRevoluteJoint::SetMotor(NxaMotorDescription^ motor)
{
	((NxRevoluteJoint*)nxJoint)->setMotor(*(motor->nxMotorDesc));
}

void NxaRevoluteJoint::GetMotor([Out] NxaMotorDescription^% motor)
{
	NxMotorDesc nxMotor;
	((NxRevoluteJoint*)nxJoint)->getMotor(nxMotor);
	motor = gcnew NxaMotorDescription(&nxMotor);
}

void NxaRevoluteJoint::SetSpring(NxaSpringDescription^ spring)
{
	((NxRevoluteJoint*)nxJoint)->setSpring(*(spring->nxSpringDesc));
}

void NxaRevoluteJoint::GetSpring([Out] NxaSpringDescription^% spring)
{
	NxSpringDesc nxSpring;
	((NxRevoluteJoint*)nxJoint)->getSpring(nxSpring);
	spring = gcnew NxaSpringDescription(&nxSpring);
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