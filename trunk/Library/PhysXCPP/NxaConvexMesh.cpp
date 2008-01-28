#include "Stdafx.h"
#include "NxaConvexMesh.h"
#include "NxaConvexMeshDescription.h"
#include "NxaMath.h"

NxaConvexMesh::NxaConvexMesh()
{

}

bool NxaConvexMesh::SaveToDescription(NxaConvexMeshDescription^ description)
{
	return nxConvexMesh->saveToDesc(*(description->nxConvexMeshDesc));
}

NxaU32 NxaConvexMesh::GetSubmeshCount()
{
	return nxConvexMesh->getSubmeshCount();
}

NxaU32 NxaConvexMesh::GetCount(NxaSubmeshIndex submeshIndex, NxaInternalArray internalArray)
{
	return nxConvexMesh->getCount(submeshIndex, (NxInternalArray)internalArray);
}

NxaInternalFormat NxaConvexMesh::GetFormat(NxaSubmeshIndex submeshIndex, NxaInternalArray internalArray)
{
	return (NxaInternalFormat)nxConvexMesh->getFormat(submeshIndex, (NxInternalArray)internalArray);
}

NxaU32 NxaConvexMesh::GetStride(NxSubmeshIndex submeshIndex, NxaInternalArray internalArray)
{
	return nxConvexMesh->getStride(submeshIndex, (NxInternalArray)internalArray);
}

NxaU32 NxaConvexMesh::GetReferenceCount()
{
	return nxConvexMesh->getReferenceCount();
}

void NxaConvexMesh::GetMassInformation(float mass, [Out] Matrix %localInertia, [Out] Vector3 %localCenterOfMass)
{
	NxMat33 li; NxVec3 lcom;

	nxConvexMesh->getMassInformation(mass, li, lcom);
	localInertia = NxaMath::MatrixPhysXToXNA(li);
	NxaMath::Vector3PhysXToXNA(lcom, localCenterOfMass);
}