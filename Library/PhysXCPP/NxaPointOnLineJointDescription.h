#pragma once

#include "NxaJointDescription.h"

#include "NxPointOnLineJointDesc.h"

public ref class NxaPointOnLineJointDescription : public NxaJointDescription
{
internal:
	NxaPointOnLineJointDescription(NxPointOnLineJointDesc* ptr);

public:
	NxaPointOnLineJointDescription(void);

	void SetToDefault();
	bool IsValid();
};