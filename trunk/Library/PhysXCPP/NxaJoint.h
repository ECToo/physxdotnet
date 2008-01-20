#pragma once

class NxJoint;
#include "NxaActor.h"

public ref class NxaJoint abstract
{
public:
	NxaJoint(void);
	NxaJoint(NxJoint* nxJoint);

	!NxaJoint(void);

	void GetActors([Out] NxaActor^% actorA, [Out] NxaActor^% actorB);

protected:
	NxJoint* nxJoint;

public:
	NxaActor^ actorA;
	NxaActor^ actorB;
};