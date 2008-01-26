#pragma once

#include "Stdafx.h"
#include "Nxashape.h"
#include "NxaCapsuleShapeDescription.h"

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
	
	void SaveToDesc([Out] NxaCapsuleShapeDescription^% desc);		
};