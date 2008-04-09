#include "StdAfx.h"
#include "NxaMath.h"

NxMat33 NxaMath::MatrixRotXNAToPhysX([In] Matrix% m)
{
	pin_ptr<float> ptr = &(m.M11);
	NxMat33 mat;
	mat.setColumnMajorStride4(ptr);
	return mat;
}

NxMat34 NxaMath::MatrixRotPosXNAToPhysX([In] Matrix% m)
{
	pin_ptr<float> ptr = &(m.M11);
	NxMat34 mat;
	mat.setColumnMajor44(ptr);
	return mat;
}

Matrix NxaMath::MatrixPhysXToXNA(const NxMat33& m)
{
	Matrix val = Matrix::Identity;
	m.getColumnMajorStride4(&val.M11);
	return val;
}

Matrix NxaMath::MatrixPhysXToXNA(const NxMat34& m)
{
	Matrix val = Matrix::Identity;
	m.getColumnMajor44(&val.M11);
	return val;
}

NxVec3 NxaMath::Vector3XNAToPhysX([In] Matrix% m)
{
	return NxVec3(m.M41, m.M42, m.M43);
}

NxVec3 NxaMath::Vector3XNAToPhysX([In] Vector3% v)
{
	return NxVec3(v.X, v.Y, v.Z);
}

Vector3 NxaMath::Vector3PhysXToXNA(const NxVec3 &v)
{
	return Vector3(v.x, v.y, v.z);
}

void NxaMath::Vector3PhysXToXNA(const NxVec3 &v, [Out] Vector3% out)
{
	out.X = v.x; out.Y = v.y; out.Z = v.z;
}

NxQuat NxaMath::QuaternionXNAToPhysX([In] Quaternion% q)
{
	NxQuat quat;
	quat.x = q.X; quat.y = q.Y; quat.z = q.Z; quat.w = q.W;
	return quat;
}

Quaternion NxaMath::QuaternionPhysXToXNA(const NxQuat &q)
{
	return Quaternion(q.x, q.y, q.z, q.w);
}

void NxaMath::QuaternionPhysXToXNA(const NxQuat &q, [Out] Quaternion% out)
{
	out.X = q.x; out.Y = q.y; out.Z = q.z; out.W = q.w;
}

Vector3 NxaMath::TransformWorldPointToLocal([In] Matrix% m, [In] Vector3% point)
{
	float numX = point.X - m.Translation.X;
	float numY = point.Y - m.Translation.Y;
	float numZ = point.Z - m.Translation.Z;
	float nX = (numX * m.M11) + (numY * m.M12) + (numZ * m.M13);
	float nY = (numY * m.M21) + (numY * m.M22) + (numZ * m.M23);
	float nZ = (numZ * m.M31) + (numY * m.M32) + (numZ * m.M33);
	return Vector3(nX, nY, nZ);
}

Vector3 NxaMath::TransformWorldNormalToLocal([In] Matrix% m, [In] Vector3% normal)
{
	float nX = (normal.X * m.M11) + (normal.Y * m.M12) + (normal.Z * m.M13);
	float nY = (normal.X * m.M21) + (normal.Y * m.M22) + (normal.Z * m.M23);
	float nZ = (normal.X * m.M31) + (normal.Y * m.M32) + (normal.Z * m.M33);
	return Vector3(nX, nY, nZ);
}

Vector3 NxaMath::GetPerpendicularVector([In] Vector3% v)
{
    Vector3 vec = Vector3(v.X * v.X, v.Y * v.Y, v.Z * v.Z);
	Vector3 vec2 = Vector3::UnitZ;

    if ((vec.X <= vec.Y) && (vec.X <= vec.Z))
    {
		vec2 = Vector3::UnitX;
    }
    else if ((vec.Y <= vec.X) && (vec.Y <= vec.Z))
    {
		vec2 = Vector3::UnitY;
    }
	Vector3 result;
	Vector3::Cross(v, vec2, result);
	result.Normalize();
    
	return result;

}

NxExtendedVec3 NxaMath::Vector3XNAToExtendedPhysX([In] Vector3% v)
{
	float x = v.X;
	float y = v.Y;
	float z = v.Z;
	NxExtendedVec3 vec;

	if(float::IsPositiveInfinity(x) || float::IsPositiveInfinity(y) || float::IsPositiveInfinity(z))
		vec.setPlusInfinity();
	else if(float::IsNegativeInfinity(x) || float::IsNegativeInfinity(y) || float::IsNegativeInfinity(z))
		vec.setMinusInfinity();
	else
		vec.set(v.X, v.Y, v.Z);

	return vec;
}

Vector3 NxaMath::Vector3ExtendedPhysXToXNA(const NxExtendedVec3& v)
{
	return Vector3(v.x, v.y, v.z);	
}