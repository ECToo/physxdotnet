//new file

#pragma once

#include "Nxp.h"

public ref class NxaGroupsMask
{
internal:
	NxGroupsMask* nxGroupsMask;

public:
	
	property int bits0
	{
		int get() { return nxGroupsMask->bits0; }
		void set(int value) { nxGroupsMask->bits0 = value; }
	}

	property int bits1
	{
		int get() { return nxGroupsMask->bits1; }
		void set(int value) { nxGroupsMask->bits1 = value; }
	}

	property int bits2
	{
		int get() { return nxGroupsMask->bits2; }
		void set(int value) { nxGroupsMask->bits2 = value; }
	}

	property int bits3
	{
		int get() { return nxGroupsMask->bits3; }
		void set(int value) { nxGroupsMask->bits3 = value; }
	}

	NxaGroupsMask(int _bits0, int _bits1, int _bits2, int _bits3);
	~NxaGroupsMask(void);
	!NxaGroupsMask(void);

};