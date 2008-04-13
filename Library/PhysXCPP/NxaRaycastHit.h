// new file

#pragma once

#include "NxUserRaycastReport.h"
#include "NxaShape.h"

public value struct NxaRaycastHit
{
internal:
	NxRaycastHit * nxRaycastHit;

public:
	property Vector3 WorldImpact
	{	
		Vector3 get() { return NxaMath::Vector3PhysXToXNA((nxRaycastHit->worldImpact)); }
	}

	property Vector3 WorldNormal
	{	
		Vector3 get() { return NxaMath::Vector3PhysXToXNA(nxRaycastHit->worldNormal); }
	}

	property NxaShape^ shape
	{
		NxaShape^ get() { return NxaShape::CreateFromPointer(nxRaycastHit->shape); }
	}

	property float distance
	{
		float get() { return nxRaycastHit->distance; }
	}

	property NxaU32 flags
	{
		NxaU32 get() { return nxRaycastHit->flags; }
	}

	property NxaU32 faceID
	{
		NxaU32 get() { return nxRaycastHit->faceID; }
	}

	property NxaMaterialIndex materialIndex
	{
		NxaMaterialIndex get() { return nxRaycastHit->materialIndex; }
	}

	property float u
	{
		float get() { return nxRaycastHit->u; }
	}

	property float v
	{
		float get() { return nxRaycastHit->v; }
	}

};



