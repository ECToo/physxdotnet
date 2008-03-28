// completely new file

#pragma once

#include "NxHeightFieldSample.h"

public value struct NxaHeightFieldSample
{
	unsigned short height;
	unsigned char materialIndex0;
	bool tessFlag;
	unsigned char materialIndex1;
	unsigned char unused;

internal:
	void GetDataFrom(NxHeightFieldSample * sample)
	{
		this->height			= sample->height;
		this->materialIndex0	= sample->materialIndex0;
		this->tessFlag			= sample->tessFlag;
		this->materialIndex1	= sample->materialIndex1;
		this->unused			= sample->unused;
	}

	void SetDataIn(NxHeightFieldSample * sample)
	{
		sample->height			= this->height;
		sample->materialIndex0	= this->materialIndex0;
		sample->tessFlag		= this->tessFlag;
		sample->materialIndex1	= this->materialIndex1;
		sample->unused			= this->unused;
	}
};
