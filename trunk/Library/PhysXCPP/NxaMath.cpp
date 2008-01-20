#include "StdAfx.h"
#include "NxaMath.h"

NxMat33 inline NxaMath::MatrixRotXNAToPhysX([In] Matrix% m)
{
	return NxMat33(NxVec3(m.M11, m.M12, m.M13), NxVec3(m.M21, m.M22, m.M23), NxVec3(m.M31, m.M32, m.M33));
}

NxMat34 inline NxaMath::MatrixRotPosXNAToPhysX([In] Matrix% m)
{
	return NxMat34(MatrixRotXNAToPhysX(m), Vector3XNAToPhysX(m));
}

Matrix inline NxaMath::MatrixPhysXToXNA(const NxMat33& m)
{
	NxVec3 row1 = m.getColumn(0);
	NxVec3 row2 = m.getColumn(1);
	NxVec3 row3 = m.getColumn(2);

	return Matrix(row1.x, row1.y, row1.z, 0, row2.x, row2.y, row2.z, 0, row3.x, row3.y, row3.z, 0, 0, 0, 0, 1);
}

Matrix inline NxaMath::MatrixPhysXToXNA(const NxMat34& m)
{
	NxVec3 row1 = m.M.getColumn(0);
	NxVec3 row2 = m.M.getColumn(1);
	NxVec3 row3 = m.M.getColumn(2);
	NxVec3 pos = m.t;

	return Matrix(row1.x, row1.y, row1.z, 0, row2.x, row2.y, row2.z, 0, row3.x, row3.y, row3.z, 0, pos.x, pos.y, pos.z, 1);
}

NxVec3 inline NxaMath::Vector3XNAToPhysX([In] Matrix% m)
{
	return NxVec3(m.M41, m.M42, m.M43);
}

NxVec3 inline NxaMath::Vector3XNAToPhysX([In] Vector3% v)
{
	return NxVec3(v.X, v.Y, v.Z);
}

Vector3 inline NxaMath::Vector3PhysXToXNA(const NxVec3 &v)
{
	return Vector3(v.x, v.y, v.z);
}

void inline NxaMath::Vector3PhysXToXNA(const NxVec3 &v, [Out] Vector3% out)
{
	out.X = v.x; out.Y = v.y; out.Z = v.z;
}

NxQuat inline NxaMath::QuaternionXNAToPhysX([In] Quaternion% q)
{
	NxQuat quat;
	quat.x = q.X; quat.y = q.Y; quat.z = q.Z; quat.w = q.W;
	return quat;
}

Quaternion inline NxaMath::QuaternionPhysXToXNA(const NxQuat &q)
{
	return Quaternion(q.x, q.y, q.z, q.w);
}

void inline NxaMath::QuaternionPhysXToXNA(const NxQuat &q, [Out] Quaternion% out)
{
	out.X = q.x; out.Y = q.y; out.Z = q.z; out.W = q.w;
}