// completely new file

#pragma once

#include "NxHeightFieldDesc.h"
#include "NxaHeightFieldSample.h"

public ref class NxaHeightFieldDescription
{
public:
	NxaHeightFieldDescription(void);
	~NxaHeightFieldDescription(void);
	!NxaHeightFieldDescription(void);

	void SetToDefault();
	bool IsValid();

	array<NxaHeightFieldSample> ^ GetSamples();
	bool SetSamples(array<NxaHeightFieldSample> ^ samples);

	property int Rows
	{
		int get() { return nxHeightFieldDesc->nbRows; }
		void set(int value) { nxHeightFieldDesc->nbRows = value; }
	}
	property int Columns
	{
		int get() { return nxHeightFieldDesc->nbColumns; }
		void set(int value) { nxHeightFieldDesc->nbColumns = value; }
	}
	property float Thickness
	{
		float get() { return nxHeightFieldDesc->thickness; }
		void set(float value) { nxHeightFieldDesc->thickness = value; }
	}
	property float VerticalExtent
	{
		float get() { return nxHeightFieldDesc->verticalExtent; }
		void set(float value) { nxHeightFieldDesc->verticalExtent = value; }
	}
	property float ConvexEdgeThreshold
	{
		float get() { return nxHeightFieldDesc->convexEdgeThreshold; }
		void set(float value) { nxHeightFieldDesc->convexEdgeThreshold = value; }
	}

internal:
	NxHeightFieldDesc* nxHeightFieldDesc;

private:
	void FreeSamplesMemory();
};
