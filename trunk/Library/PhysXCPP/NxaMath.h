#pragma once

#include "Stdafx.h"

#include "NxMat33.h"
#include "NxMat34.h"
#include "NxQuat.h"
#include "NxVec3.h"
#include "NxExtended.h"

public ref class NxaMath
{
public:
	static NxMat33 MatrixRotXNAToPhysX([In] Matrix% m);
	static NxMat34 MatrixRotPosXNAToPhysX([In] Matrix% m);

	static Matrix MatrixPhysXToXNA(const NxMat33& m);
	static Matrix MatrixPhysXToXNA(const NxMat34& m);

	static NxVec3 Vector3XNAToPhysX([In] Matrix% m);
	static NxVec3 Vector3XNAToPhysX([In] Vector3% v);

	static Vector3 Vector3PhysXToXNA(const NxVec3& v);
	static void Vector3PhysXToXNA(const NxVec3 &v, [Out] Vector3% out);

	static NxQuat QuaternionXNAToPhysX([In] Quaternion% q);

	static Quaternion QuaternionPhysXToXNA(const NxQuat& q);
	static void QuaternionPhysXToXNA(const NxQuat&q, [Out] Quaternion% out);
	
	static Vector3 TransformWorldPointToLocal([In] Matrix% m, [In] Vector3% point);
	static Vector3 TransformWorldNormalToLocal([In] Matrix% m, [In] Vector3% normal);

	static Vector3 GetPerpendicularVector([In] Vector3%);

	static NxExtendedVec3 Vector3XNAToExtendedPhysX([In] Vector3% v);
	static Vector3 Vector3ExtendedPhysXToXNA(const NxExtendedVec3& v);
};
