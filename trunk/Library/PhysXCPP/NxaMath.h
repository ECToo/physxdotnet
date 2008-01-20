#pragma once

#include "Stdafx.h"

#include "NxMat33.h"
#include "NxMat34.h"
#include "NxQuat.h"
#include "NxVec3.h"

ref class NxaMath
{
public:
	static inline NxMat33 MatrixRotXNAToPhysX([In] Matrix% m);
	static inline NxMat34 MatrixRotPosXNAToPhysX([In] Matrix% m);

	static inline Matrix MatrixPhysXToXNA(const NxMat33& m);
	static inline Matrix MatrixPhysXToXNA(const NxMat34& m);

	static inline NxVec3 Vector3XNAToPhysX([In] Matrix% m);

	static inline NxVec3 Vector3XNAToPhysX([In] Vector3% v);

	static inline Vector3 Vector3PhysXToXNA(const NxVec3& v);
	static inline void Vector3PhysXToXNA(const NxVec3 &v, [Out] Vector3% out);

	static inline NxQuat QuaternionXNAToPhysX([In] Quaternion% q);

	static inline Quaternion QuaternionPhysXToXNA(const NxQuat& q);
	static inline void QuaternionPhysXToXNA(const NxQuat&q, [Out] Quaternion% out);
};
