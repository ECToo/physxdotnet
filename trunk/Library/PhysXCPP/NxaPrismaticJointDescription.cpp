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
	((NxPrismaticJointDesc*)nxJointDesc)->setToDefault();
}

bool NxaPrismaticJointDescription::IsValid()
{
	return ((NxPrismaticJointDesc*)nxJointDesc)->isValid();
}