#pragma once

#include "StdAfx.h"
#include "Nxap.h"
#include "NxShapeDesc.h"

public ref class NxaShapeDescription abstract
{
internal:
	static NxaShapeDescription^ CreateFromPointer(NxShapeDesc* ptr);
	NxShapeDesc* nxShapeDesc;

public:
	virtual ~NxaShapeDescription();
	!NxaShapeDescription();

	virtual void SetToDefault() { nxShapeDesc->setToDefault(); }
	virtual bool IsValid() { return nxShapeDesc->isValid(); }
	
	property Matrix LocalPose
	{
		Matrix get();
		void set(Matrix value);
	}

	property NxaU32 ShapeFlags
	{
		NxaU32 get();// { return nxShapeDesc->shapeFlags; }
		void set(NxaU32 value);// { nxShapeDesc->shapeFlags = value; }
	}
};