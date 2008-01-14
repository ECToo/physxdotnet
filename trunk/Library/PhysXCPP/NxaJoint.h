#pragma once

#include "NxPhysics.h"
#include "NxaActor.h"

using namespace System::Runtime::InteropServices;

namespace PhysXCPP
{

	public ref class NxaJoint abstract
	{
	public:
		NxaJoint(void);
		NxaJoint(NxJoint* nxJoint);

		~NxaJoint(void);
		!NxaJoint(void);

		void GetActors([Out] NxaActor^% actorA, [Out] NxaActor^% actorB);

	protected:
		NxJoint* nxJoint;

	public:
		NxaActor^ actorA;
		NxaActor^ actorB;
	};

}