#pragma once

#include "Stdafx.h"
#include "NxaShape.h"
#include "NxaSphereShapeDescription.h"

#include "NxShape.h"
#include "NxSphereShape.h"

public ref class NxaSphereShape : public NxaShape
{
internal:
	NxaSphereShape(NxShape *ptr);

public:
	void SetRadius(float radius) { nxShape->isSphere()->setRadius(radius); }
	float GetRadius() { return nxShape->isSphere()->getRadius(); }
	
	void SaveToDesc(NxaSphereShapeDescription^% desc);
};