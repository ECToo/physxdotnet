#pragma once

#include "NxaJoint.h"
class NxFixedJoint;

public ref class NxaFixedJoint : public NxaJoint
{
internal:
	NxaFixedJoint(NxFixedJoint* nxFixedJoint);
};