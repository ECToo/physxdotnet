#include "StdAfx.h"
#include "NxaFixedJoint.h"

#include "NxJoint.h"
#include "NxFixedJoint.h"

NxaFixedJoint::NxaFixedJoint(NxFixedJoint* joint)
{
	nxJoint = joint;
}