#include "StdAfx.h"
#include "NxaCapsuleController.h"

NxaCapsuleController::NxaCapsuleController(NxController* ptr) : NxaController(ptr)
{
}

float NxaCapsuleController::GetRadius()
{
	return ((NxCapsuleController *)nxController)->getRadius();
}

bool NxaCapsuleController::SetRadius(float radius)
{
	return ((NxCapsuleController *)nxController)->setRadius(radius);
}
float NxaCapsuleController::GetHeight()
{
	return ((NxCapsuleController *)nxController)->getHeight();
}
bool NxaCapsuleController::SetHeight(float value)
{
	return ((NxCapsuleController *)nxController)->setHeight(value);
}
NxaCapsuleClimbingMode NxaCapsuleController::GetClimbingMode()
{
	return (NxaCapsuleClimbingMode)(((NxCapsuleController *)nxController)->getClimbingMode());
}
bool NxaCapsuleController::SetClimbingMode(NxaCapsuleClimbingMode mode)
{
	return ((NxCapsuleController *)nxController)->setClimbingMode((NxCapsuleClimbingMode)mode);
}
