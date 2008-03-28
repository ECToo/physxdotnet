// completely new file

#pragma once

#include "NxHeightField.h"
#include "NxaHeightFieldDescription.h"

public ref class NxaHeightField
{
internal:
	NxaHeightField(NxaHeightFieldDescription^ description);
	NxaHeightField(NxHeightField * ptr);
	NxHeightField * nxHeightField;

public:
	array<NxaHeightFieldSample> ^ GetCells();
	float GetConvexEdgeThreshold();
	float GetHeight(float x, float z);
	int GetColumnsCount();
	int GetRowCount();
	int GetReferenceCount();
	int GetSampleStride();
	float GetThickness();
	float GetVerticalExtent();
	bool LoadFromDescription(NxaHeightFieldDescription ^ description);
	void SaveCells(array<NxaHeightFieldSample> ^% destBuffer);
	bool SaveToDescription(NxaHeightFieldDescription ^% description);
};
