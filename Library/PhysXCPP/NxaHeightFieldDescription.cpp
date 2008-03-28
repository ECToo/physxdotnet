// completely new file

#include "StdAfx.h"
#include "NxaHeightFieldDescription.h"

NxaHeightFieldDescription::NxaHeightFieldDescription(void)
{
	nxHeightFieldDesc = new NxHeightFieldDesc();
	nxHeightFieldDesc->sampleStride = sizeof(int);
	nxHeightFieldDesc->samples = 0;
}

NxaHeightFieldDescription::~NxaHeightFieldDescription(void)
{
	this->!NxaHeightFieldDescription();
}

NxaHeightFieldDescription::!NxaHeightFieldDescription(void)
{
	FreeSamplesMemory();

	delete nxHeightFieldDesc;
}

void NxaHeightFieldDescription::SetToDefault()
{
	FreeSamplesMemory();
	nxHeightFieldDesc->setToDefault();

	nxHeightFieldDesc->sampleStride = sizeof(int);
}

bool NxaHeightFieldDescription::IsValid()
{
	return nxHeightFieldDesc->isValid();
}

array<NxaHeightFieldSample> ^ NxaHeightFieldDescription::GetSamples()
{
	array<NxaHeightFieldSample> ^ samples = gcnew array<NxaHeightFieldSample>(nxHeightFieldDesc->nbColumns * nxHeightFieldDesc->nbRows);
	char * currentByte = (char *)nxHeightFieldDesc->samples;

	for(int i = 0; i < samples->Length; i++)
	{
		NxHeightFieldSample * sample = (NxHeightFieldSample *)currentByte;
		samples[i].GetDataFrom(sample);

		currentByte += nxHeightFieldDesc->sampleStride;
	}

	return samples;
}

bool NxaHeightFieldDescription::SetSamples(array<NxaHeightFieldSample> ^ samples)
{
	FreeSamplesMemory();

	nxHeightFieldDesc->samples = new int[samples->Length];
	char * currentByte = (char*)nxHeightFieldDesc->samples;

	for(int i = 0; i < samples->Length; i++)
	{
		NxHeightFieldSample * sample = (NxHeightFieldSample *)currentByte;
		samples[i].SetDataIn(sample);

		currentByte += nxHeightFieldDesc->sampleStride;
	}

	return nxHeightFieldDesc->nbRows * nxHeightFieldDesc->nbColumns == samples->Length;
}

void NxaHeightFieldDescription::FreeSamplesMemory()
{
	if(nxHeightFieldDesc->samples == 0)
		return;

	delete nxHeightFieldDesc->samples;
	nxHeightFieldDesc->samples = 0;
}

