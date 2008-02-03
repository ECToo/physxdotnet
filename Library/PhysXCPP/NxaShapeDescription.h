#pragma once

#include "StdAfx.h"
#include "Nxap.h"

class NxShapeDesc;

public ref class NxaShapeDescription abstract
{
internal:
	static NxaShapeDescription^ CreateFromPointer(NxShapeDesc* ptr);
	NxShapeDesc* nxShapeDesc;

public:
	virtual ~NxaShapeDescription();
	!NxaShapeDescription();

	virtual void SetToDefault();
	virtual bool IsValid();
	
	property Matrix LocalPose
	{
		Matrix get();
		void set(Matrix value);
	}

	property NxaU32 ShapeFlags
	{
		NxaU32 get();
		void set(NxaU32 value);
	}

	property Object^ UserData;
};