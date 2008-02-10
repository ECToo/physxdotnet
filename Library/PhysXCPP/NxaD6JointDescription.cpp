#include "StdAfx.h"
#include "NxaD6JointDescription.h"
#include "NxaJointLimitSoftDescription.h"
#include "NxaJointLimitSoftPairDescription.h"
#include "NxaJointDriveDescription.h"
#include "Nxap.h"

#include "NxD6JointDesc.h"

NxaD6JointDescription::NxaD6JointDescription(void)
{
	nxJointDesc = new NxD6JointDesc();
}

void NxaD6JointDescription::SetToDefault()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->setToDefault();
}

bool NxaD6JointDescription::IsValid()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return d6Ptr->isValid();
}

NxaD6JointMotion NxaD6JointDescription::XMotion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->xMotion);
}

void NxaD6JointDescription::XMotion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->xMotion = (NxD6JointMotion)value;
}

NxaD6JointMotion NxaD6JointDescription::YMotion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->yMotion);
}

void NxaD6JointDescription::YMotion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->yMotion = (NxD6JointMotion)value;
}

NxaD6JointMotion NxaD6JointDescription::ZMotion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->zMotion);
}

void NxaD6JointDescription::ZMotion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->zMotion = (NxD6JointMotion)value;
}

NxaD6JointMotion NxaD6JointDescription::Swing1Motion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->swing1Motion);
}

void NxaD6JointDescription::Swing1Motion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->swing1Motion = (NxD6JointMotion)value;
}

NxaD6JointMotion NxaD6JointDescription::Swing2Motion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->swing2Motion);
}

void NxaD6JointDescription::Swing2Motion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->swing2Motion = (NxD6JointMotion)value;
}

NxaD6JointMotion NxaD6JointDescription::TwistMotion::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaD6JointMotion)(d6Ptr->twistMotion);
}

void NxaD6JointDescription::TwistMotion::set(NxaD6JointMotion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->twistMotion = (NxD6JointMotion)value;
}

NxaJointLimitSoftDescription^ NxaD6JointDescription::LinearLimit::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointLimitSoftDescription(&(d6Ptr->linearLimit));
}

void NxaD6JointDescription::LinearLimit::set(NxaJointLimitSoftDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->linearLimit = *(value->nxDesc);
}

NxaJointLimitSoftDescription^ NxaD6JointDescription::Swing1Limit::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointLimitSoftDescription(&(d6Ptr->swing1Limit));
}

void NxaD6JointDescription::Swing1Limit::set(NxaJointLimitSoftDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->swing1Limit = *(value->nxDesc);
}

NxaJointLimitSoftDescription^ NxaD6JointDescription::Swing2Limit::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointLimitSoftDescription(&(d6Ptr->swing2Limit));
}

void NxaD6JointDescription::Swing2Limit::set(NxaJointLimitSoftDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->swing2Limit = *(value->nxDesc);
}

NxaJointLimitSoftPairDescription^ NxaD6JointDescription::TwistLimit::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointLimitSoftPairDescription(&(d6Ptr->twistLimit));
}

void NxaD6JointDescription::TwistLimit::set(NxaJointLimitSoftPairDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->twistLimit = *(value->nxDesc);
}

NxaJointDriveDescription^ NxaD6JointDescription::XDrive::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointDriveDescription(&(d6Ptr->xDrive));
}

void NxaD6JointDescription::XDrive::set(NxaJointDriveDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->xDrive = *(value->nxDesc);
}

NxaJointDriveDescription^ NxaD6JointDescription::YDrive::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointDriveDescription(&(d6Ptr->yDrive));
}

void NxaD6JointDescription::YDrive::set(NxaJointDriveDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->yDrive = *(value->nxDesc);
}

NxaJointDriveDescription^ NxaD6JointDescription::ZDrive::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointDriveDescription(&(d6Ptr->zDrive));
}

void NxaD6JointDescription::ZDrive::set(NxaJointDriveDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->zDrive = *(value->nxDesc);
}

NxaJointDriveDescription^ NxaD6JointDescription::SwingDrive::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointDriveDescription(&(d6Ptr->swingDrive));
}

void NxaD6JointDescription::SwingDrive::set(NxaJointDriveDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->swingDrive = *(value->nxDesc);
}

NxaJointDriveDescription^ NxaD6JointDescription::TwistDrive::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointDriveDescription(&(d6Ptr->twistDrive));
}

void NxaD6JointDescription::TwistDrive::set(NxaJointDriveDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->twistDrive = *(value->nxDesc);
}

NxaJointDriveDescription^ NxaD6JointDescription::SlerpDrive::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return gcnew NxaJointDriveDescription(&(d6Ptr->slerpDrive));
}

void NxaD6JointDescription::SlerpDrive::set(NxaJointDriveDescription^ value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->slerpDrive = *(value->nxDesc);
}

Vector3 NxaD6JointDescription::DrivePosition::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return NxaMath::Vector3PhysXToXNA(d6Ptr->drivePosition);
}

void NxaD6JointDescription::DrivePosition::set(Vector3 value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->drivePosition = NxaMath::Vector3XNAToPhysX(value);
}

Quaternion NxaD6JointDescription::DriveOrientation::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return NxaMath::QuaternionPhysXToXNA(d6Ptr->driveOrientation);
}

void NxaD6JointDescription::DriveOrientation::set(Quaternion value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->driveOrientation = NxaMath::QuaternionXNAToPhysX(value);
}

Vector3 NxaD6JointDescription::DriveLinearVelocity::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return NxaMath::Vector3PhysXToXNA(d6Ptr->driveLinearVelocity);
}

void NxaD6JointDescription::DriveLinearVelocity::set(Vector3 value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->driveLinearVelocity = NxaMath::Vector3XNAToPhysX(value);
}

Vector3 NxaD6JointDescription::DriveAngularVelocity::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return NxaMath::Vector3PhysXToXNA(d6Ptr->driveAngularVelocity);
}

void NxaD6JointDescription::DriveAngularVelocity::set(Vector3 value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->driveAngularVelocity = NxaMath::Vector3XNAToPhysX(value);
}

NxaJointProjectionMode NxaD6JointDescription::ProjectionMode::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return (NxaJointProjectionMode) d6Ptr->projectionMode;
}

void NxaD6JointDescription::ProjectionMode::set(NxaJointProjectionMode value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->projectionMode = (NxJointProjectionMode)value;
}

float NxaD6JointDescription::ProjectionDistance::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return d6Ptr->projectionDistance;
}

void NxaD6JointDescription::ProjectionDistance::set(float value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->projectionDistance = value;
}

float NxaD6JointDescription::ProjectionAngle::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return d6Ptr->projectionAngle;
}

void NxaD6JointDescription::ProjectionAngle::set(float value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->projectionAngle = value;
}

float NxaD6JointDescription::GearRatio::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return d6Ptr->gearRatio;
}

void NxaD6JointDescription::GearRatio::set(float value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->gearRatio = value;
}

NxaU32 NxaD6JointDescription::Flags::get()
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	return d6Ptr->flags;
}

void NxaD6JointDescription::Flags::set(NxaU32 value)
{
	NxD6JointDesc* d6Ptr = (NxD6JointDesc*)nxJointDesc;
	d6Ptr->flags = value;
}