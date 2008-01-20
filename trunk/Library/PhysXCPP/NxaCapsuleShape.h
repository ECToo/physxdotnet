#pragma once

#include "Stdafx.h"
#include "nxashape.h"
#include "NxaCapsuleShapeDescription.h";

public ref class NxaCapsuleShape : 	public NxaShape
{
internal:
	NxaCapsuleShape(NxShape* ptr);

public:
	void SetDimensions(float radius, float height);
	void SetRadius(float radius);
	float GetRadius();
	void SetHeight(float height);
	float GetHeight();
	//void GetWorldCapsule([OUT] NxaCapsule^ worldCapsule);
	
	void SaveToDesc([Out] NxaCapsuleShapeDescription^% desc);		
};