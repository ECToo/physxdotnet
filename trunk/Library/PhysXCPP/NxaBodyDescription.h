#pragma once

#include "NxBodyDesc.h"

public ref class NxaBodyDescription
{
internal:
	NxBodyDesc* nxBodyDesc;

public:
	NxaBodyDescription(void);
	~NxaBodyDescription(void);
	!NxaBodyDescription(void);
};
