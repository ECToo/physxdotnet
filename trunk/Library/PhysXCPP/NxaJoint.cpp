#include "StdAfx.h"
#include "NxaJoint.h"



NxaJoint::NxaJoint(void)
{

}

NxaJoint::NxaJoint(NxJoint *joint)
{
	nxJoint = joint;
}

NxaJoint::!NxaJoint(void)
{

}

void NxaJoint::GetActors([Out] NxaActor^% firstActor, [Out] NxaActor^% secondActor)
{
	firstActor = actorA;
	secondActor = actorB;
}