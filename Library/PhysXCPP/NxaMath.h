#pragma once

#include "NxPhysics.h"
#include "Stdafx.h"

ref class NxaMath
{
public:
	static inline NxMat33 MatrixRotXNAToPhysX(Matrix m);
	static inline NxMat34 MatrixRotPosXNAToPhysX(Matrix m);

	static inline Matrix MatrixPhysXToXNA(NxMat33& m);
	static inline Matrix MatrixPhysXToXNA(NxMat34& m);

	static inline NxVec3 Vector3XNAToPhysX(Matrix m);

	static inline NxVec3 Vector3XNAToPhysX(Vector3 v);
	static inline Vector3 Vector3PhysXToXNA(NxVec3& v);

	static inline NxQuat QuaternionXNAToPhysX(Quaternion q);
	static inline Quaternion QuaternionPhysXToXNA(NxQuat& q);
};
