// completely new file

#pragma once

#include "NxUserContactReport.h"

ref class NxaActor;

public ref class NxaContactPair
{
internal:
	NxaContactPair(NxContactPair * contactPair);
	NxContactPair * nxContactPair;

public:
	
	~NxaContactPair();
	!NxaContactPair();

	property array<NxaActor^> ^ Actors
	{
		array<NxaActor^>^ get();
	}

	property Vector3 SumNormalForce
	{
		Vector3 get();
	}

	property Vector3 SumFrictionForce
	{
		Vector3 get();
	}
};

