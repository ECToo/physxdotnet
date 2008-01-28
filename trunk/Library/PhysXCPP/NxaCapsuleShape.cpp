#include "StdAfx.h"
#include "NxaCapsuleShape.h"
#include "NxaCapsule.h"

NxaCapsuleShape::NxaCapsuleShape(NxShape* ptr) : NxaShape(ptr)
{

}

void NxaCapsuleShape::SetDimensions(float radius, float height)
{
	NxCapsuleShape* capsulePtr = (NxCapsuleShape*)nxShape;
	capsulePtr->setDimensions(radius, height);
}

void NxaCapsuleShape::SetRadius(float radius)
{
	NxCapsuleShape* capsulePtr = (NxCapsuleShape*)nxShape;
	capsulePtr->setRadius(radius);
}

float NxaCapsuleShape::GetRadius()
{
	NxCapsuleShape* capsulePtr = (NxCapsuleShape*)nxShape;
	return capsulePtr->getRadius();
}

void NxaCapsuleShape::SetHeight(float height)
{
	NxCapsuleShape* capsulePtr = (NxCapsuleShape*)nxShape;
	capsulePtr->setHeight(height);
}

float NxaCapsuleShape::GetHeight()
{
	NxCapsuleShape* capsulePtr = (NxCapsuleShape*)nxShape;
	return capsulePtr->getHeight();
}

void NxaCapsuleShape::GetWorldCapsule([Out] NxaCapsule^% worldCapsule)
{
	NxCapsuleShape* capsulePtr = (NxCapsuleShape*)nxShape;
	capsulePtr->getWorldCapsule(*(worldCapsule->nxCapsule));
}

void NxaCapsuleShape::SaveToDesc([Out] NxaCapsuleShapeDescription ^%desc)
{
	NxCapsuleShape* capsulePtr = (NxCapsuleShape*)nxShape;
	NxCapsuleShapeDesc* csDesc = (NxCapsuleShapeDesc*)desc->nxShapeDesc;
	capsulePtr->saveToDesc(*csDesc);
}