#include "StdAfx.h"
#include "NxaCapsuleShape.h"



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

void NxaCapsuleShape::SaveToDesc([Out] NxaCapsuleShapeDescription ^%desc)
{
	NxCapsuleShape* capsulePtr = (NxCapsuleShape*)nxShape;
	desc->Height = capsulePtr->getHeight();
	desc->Radius = capsulePtr->getRadius();
}