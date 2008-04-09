#pragma once

#include "StdAfx.h"
#include "Nxap.h"

class NxShapeDesc;

public ref class NxaShapeDescription abstract
{
internal:
	//static NxaShapeDescription^ CreateFromPointer(NxShapeDesc* ptr);
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

	property float Density
	{
		float get();
		void set(float value);
	}

	property float Mass
	{
		float get();
		void set(float value);
	}

	property NxaCollisionGroup Group
	{
		NxaCollisionGroup get();
		void set(NxaCollisionGroup value);
	}

	property NxaMaterialIndex MaterialIndex
	{
		NxaMaterialIndex get();
		void set(NxaMaterialIndex value);
	}

	property Object^ UserData
	{
		Object^ get();
		void set(Object ^ value);
	}
};