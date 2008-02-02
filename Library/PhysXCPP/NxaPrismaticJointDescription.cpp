#include "StdAfx.h"
#include "NxaPrismaticJointDescription.h"

#include "NxPrismaticJointDesc.h"

NxaPrismaticJointDescription::NxaPrismaticJointDescription(NxPrismaticJointDesc *ptr)
{
	nxJointDesc = ptr;
}

NxaPrismaticJointDescription::NxaPrismaticJointDescription(void)
{
	nxJointDesc = new NxPrismaticJointDesc();
}

void NxaPrismaticJointDescription::SetToDefault()
{
	nxJointDesc->setToDefault();
}

bool NxaPrismaticJointDescription::IsValid()
{
	return nxJointDesc->isValid();
}