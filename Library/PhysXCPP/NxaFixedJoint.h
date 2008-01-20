#pragma once

#include "NxaJoint.h"
class NxFixedJoint;

public ref class NxaFixedJoint : public NxaJoint
{
public:
	NxaFixedJoint(NxFixedJoint* nxFixedJoint);
	~NxaFixedJoint(void);
	!NxaFixedJoint(void);
};