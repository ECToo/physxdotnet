#include "StdAfx.h"
#include "NxaMath.h"

inline NxMat33 NxaMath::MatrixRotXNAToPhysX(Matrix m)
{
	return NxMat33(NxVec3(m.M11, m.M12, m.M13), NxVec3(m.M21, m.M22, m.M23), NxVec3(m.M31, m.M32, m.M33));
}

inline NxMat34 NxaMath::MatrixRotPosXNAToPhysX(Matrix m)
{
	return NxMat34(MatrixRotXNAToPhysX(m), Vector3XNAToPhysX(m));
}

inline Matrix NxaMath::MatrixPhysXToXNA(NxMat33& m)
{
	NxVec3 row1 = m.getColumn(0);
	NxVec3 row2 = m.getColumn(1);
	NxVec3 row3 = m.getColumn(2);

	return Matrix(row1.x, row1.y, row1.z, 0, row2.x, row2.y, row2.z, 0, row3.x, row3.y, row3.z, 0, 0, 0, 0, 1);
}

inline Matrix NxaMath::MatrixPhysXToXNA(NxMat34& m)
{
	NxVec3 row1 = m.M.getColumn(0);
	NxVec3 row2 = m.M.getColumn(1);
	NxVec3 row3 = m.M.getColumn(2);
	NxVec3 pos = m.t;

	return Matrix(row1.x, row1.y, row1.z, 0, row2.x, row2.y, row2.z, 0, row3.x, row3.y, row3.z, 0, pos.x, pos.y, pos.z, 1);
}

inline NxVec3 NxaMath::Vector3XNAToPhysX(Matrix m)
{
	return NxVec3(m.M41, m.M42, m.M43);
}

inline NxVec3 NxaMath::Vector3XNAToPhysX(Vector3 v)
{
	return NxVec3(v.X, v.Y, v.Z);
}

inline Vector3 NxaMath::Vector3PhysXToXNA(NxVec3 &v)
{
	return Vector3(v.x, v.y, v.z);
}

inline NxQuat NxaMath::QuaternionXNAToPhysX(Quaternion q)
{
	return NxQuat();
	//return NxQuat(q.X, q.Y, q.Z, q.W);
}

inline Quaternion NxaMath::QuaternionPhysXToXNA(NxQuat &q)
{
	return Quaternion(q.x, q.y, q.z, q.w);
}