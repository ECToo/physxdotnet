//new file

#include "StdAfx.h"
#include "NxaRay.h"

NxaRay::NxaRay()
{
	nxRay = new NxRay();
}

NxaRay::NxaRay(Microsoft::Xna::Framework::Vector3 orig, Microsoft::Xna::Framework::Vector3 dir)
{
	nxRay = new NxRay(NxaMath::Vector3XNAToPhysX(orig), NxaMath::Vector3XNAToPhysX(dir));
}

NxaRay::~NxaRay(void)
{
	this->!NxaRay();
}

NxaRay::!NxaRay(void)
{
	delete nxRay;
}