#include "StdAfx.h"
#include "NxaSphere.h"



NxaSphere::NxaSphere()
{
	nxSphere = new NxSphere();
}

NxaSphere::NxaSphere(Vector3 position, float radius)
{
	throw gcnew Exception("The method or operation is not implemented.");
}

NxaSphere::NxaSphere(NxaSphere ^sphere)
{
	throw gcnew Exception("The method or operation is not implemented.");
}

NxaSphere::~NxaSphere(void)
{
	this->!NxaSphere();
}

NxaSphere::!NxaSphere(void)
{
	delete nxSphere;
}

bool NxaSphere::IsValid()
{
	throw gcnew Exception("The method or operation is not implemented.");
	return false;
}

bool NxaSphere::Contains(Vector3 point)
{
	//throw gcnew Exception("The method or operation is not implemented.");
	return true;
}

bool NxaSphere::Contains(Vector3% point)
{
	return true;
}

bool NxaSphere::Contains(NxaSphere ^sphere)
{
	throw gcnew Exception("The method or operation is not implemented.");
	return false;
}

bool NxaSphere::Contains(Vector3 min, Vector3 max)
{
	throw gcnew Exception("The method or operation is not implemented.");
	return false;
}

bool NxaSphere::Contains(Vector3% min, Vector3% max)
{
	throw gcnew Exception("The method or operation is not implemented.");
	return false;
}

bool NxaSphere::Intersect(NxaSphere ^sphere)
{
	throw gcnew Exception("The method or operation is not implemented.");
	return false;
}