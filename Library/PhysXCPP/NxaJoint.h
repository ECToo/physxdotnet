#pragma once

#include "NxaMath.h"
#include "NxaScene.h"
#include "Nxap.h"

#include "NxJoint.h"

public ref class NxaJoint abstract
{
internal:
	NxJoint* nxJoint;
	String^ jointName;
	
	static NxaJoint^ CreateFromPointer(NxJoint* ptr);
		
public:

	void SetGlobalAnchor(Vector3 vec);
	void SetGlobalAxis(Vector3 vec);
	Vector3 GetGlobalAnchor();
	Vector3 GetGlobalAxis();

	NxaJointState GetState();
	void SetBreakable(float maxForce, float maxTorque);
	void GetBreakable([Out] float maxForce,[Out] float maxTorque); //<-- doesn't work yet for floats

	/********Limits**********/

	void SetLimitPoint(Vector3 point, bool pointIsOnActor2);
	void SetLimitPoint(Vector3 point); //overload with default boolean = true
	bool GetLimitPoint([Out] Vector3% worldLimitPoint);
	bool AddLimitPlane(Vector3 normal, Vector3 pointInPlane, float restitution);
	bool AddLimitPlane(Vector3 normal, Vector3 pointInPlane);
	void PurgeLimitPlanes() { nxJoint->purgeLimitPlanes(); }
	void ResetLimitPlaneIterator() { nxJoint->resetLimitPlaneIterator(); }
	bool HasMoreLimitPlanes() { return nxJoint->hasMoreLimitPlanes(); }
	bool GetNextLimitPlane([Out] Vector3% planeNormal, [Out] float planeD, [Out] float restitution); //<--doesn't work yet for floats

	/********Types***********/

	NxJointType GetType() { return nxJoint->getType(); }
	bool Is(NxaJointType type);
	bool IsPrismaticJoint() { return (nxJoint->isPrismaticJoint() != NULL); }
	bool IsRevoluteJoint() { return (nxJoint->isRevoluteJoint() != NULL); }
	bool IsCylindricalJoint() { return (nxJoint->isCylindricalJoint() != NULL); }
	bool IsSphericalJoint() { return (nxJoint->isSphericalJoint() != NULL); }
	bool IsPointOnLineJoint() { return (nxJoint->isPointOnLineJoint() != NULL); }
	bool IsPointInPlaneJoint() { return (nxJoint->isPointInPlaneJoint() != NULL); }
	bool IsDistanceJoint() { return (nxJoint->isDistanceJoint() != NULL); }
	bool IsPulleyJoint() { return (nxJoint->isPulleyJoint() != NULL); }
	bool IsFixedJoint() { return (nxJoint->isFixedJoint() != NULL); }
	bool IsD6Joint() { return (nxJoint->isD6Joint() != NULL); }

	/********Name/Info*******/
	void SetName(String^ name);
	String^ GetName();
	NxaScene^ GetScene();
	Object^ userData;
};