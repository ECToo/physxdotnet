#pragma once

#include "NxConvexMeshDesc.h"
#include "Nxap.h"

public ref class NxaConvexMeshDescription
{
internal:
	NxConvexMeshDesc* nxConvexMeshDesc;
	array<Vector3>^ pointArray;
	array<Vector3>^ triangleArray;

public:
	NxaConvexMeshDescription();
	~NxaConvexMeshDescription();
	!NxaConvexMeshDescription();
	
	property NxaU32 NumVertices
	{
		NxaU32 get();
	internal:
		void set(NxaU32 value);
	}

	property NxaU32 NumTriangles
	{
		NxaU32 get();
	}

	property NxaU32 PointStrideBytes
	{
		NxaU32 get();
	}

	property NxaU32 TriangleStrideBytes
	{
		NxaU32 get();
	}

	property array<Vector3>^ Points
	{
		array<Vector3>^ get();
		void set(array<Vector3>^ value);
	}

	property NxaConvexFlags Flags
	{
		NxaConvexFlags get();
		void set(NxaConvexFlags value);
	}
};
