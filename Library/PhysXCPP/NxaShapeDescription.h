#pragma once

#include "StdAfx.h"

#include "NxShapeDesc.h"

public ref class NxaShapeDescription abstract
{
internal:
	static NxaShapeDescription^ CreateFromPointer(NxShapeDesc* ptr);
	NxShapeDesc* nxShapeDesc;

public:
	~NxaShapeDescription();
	!NxaShapeDescription();
	
	property Matrix LocalPose
	{
		Matrix get();
		void set(Matrix value);
	}

	property unsigned int ShapeFlags
	{
		unsigned int get() { return nxShapeDesc->shapeFlags; }
		void set(unsigned int value) { nxShapeDesc->shapeFlags = value; }
	}
};