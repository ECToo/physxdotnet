#include "StdAfx.h"
#include "NxaPointOnLineJointDescription.h"

#include "NxPointOnLineJointDesc.h"

NxaPointOnLineJointDescription::NxaPointOnLineJointDescription(NxPointOnLineJointDesc *ptr)
{
	nxJointDesc = ptr;
}

NxaPointOnLineJointDescription::NxaPointOnLineJointDescription(void)
{
	nxJointDesc = new NxPointOnLineJointDesc();
}

void NxaPointOnLineJointDescription::SetToDefault()
{
	nxJointDesc->setToDefault();
}

bool NxaPointOnLineJointDescription::IsValid()
{
	return nxJointDesc->isValid();
}