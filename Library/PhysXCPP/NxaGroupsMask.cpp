//new file

#include "StdAfx.h"
#include "NxaGroupsMask.h"

NxaGroupsMask::NxaGroupsMask(int _bits0, int _bits1, int _bits2, int _bits3)
{
	nxGroupsMask = new NxGroupsMask();

	this->bits0 = _bits0;
	this->bits1 = _bits1;
	this->bits2 = _bits2;
	this->bits3 = _bits3;
}

NxaGroupsMask::!NxaGroupsMask(void)
{
	delete nxGroupsMask;
}

NxaGroupsMask::~NxaGroupsMask(void)
{
	this->!NxaGroupsMask();
}

