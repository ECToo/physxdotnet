#pragma once

#include "NxaJointDescription.h"

#include "NxPrismaticJointDesc.h"

public ref class NxaPrismaticJointDescription : public NxaJointDescription
{
internal:
	NxaPrismaticJointDescription(NxPrismaticJointDesc* ptr);

public:
	NxaPrismaticJointDescription(void);

	void SetToDefault();
	bool IsValid();
};