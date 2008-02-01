#pragma once

#include "NxaMath.h"

#include "NxJoint.h"

public ref class NxaJoint abstract
{
internal:
	NxJoint* nxJoint;
		
public:
	NxaJoint(void);

	void setGlobalAnchor(Vector3 vec);
	void setGlobalAxis(Vector3 vec);
	Vector3 getGlobalAnchor();
	Vector3 getGlobalAxis();

	//NxJointState getState();
	void setBreakable(float maxForce, float maxTorque);
};