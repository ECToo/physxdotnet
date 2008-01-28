#pragma once

#include "NxConvexMesh.h"
#include "Nxap.h"

ref class NxaConvexMeshDescription;

public ref class NxaConvexMesh
{
internal:
	NxConvexMesh* nxConvexMesh;

public:
	NxaConvexMesh();

	bool SaveToDescription(NxaConvexMeshDescription^ description);
	NxaU32 GetSubmeshCount();
	NxaU32 GetCount(NxaSubmeshIndex submeshIndex, NxaInternalArray internalArray);
	NxaInternalFormat GetFormat(NxaSubmeshIndex submeshIndex, NxaInternalArray internalArray);
	//TODO Add GetBase()
	NxaU32 GetStride(NxSubmeshIndex submeshIndex, NxaInternalArray internalArray);
	//TODO Add Load()
	NxaU32 GetReferenceCount();
	void GetMassInformation([Out] float mass, [Out] Matrix% localInertia, [Out] Vector3% localCenterOfMass);
	//TODO Add GetInternal()
};
