// completely new file

#pragma once
#include "nxashape.h"

ref class NxaHeightField;
ref class NxaHeightFieldShapeDescription;

public ref class NxaHeightFieldShape : NxaShape
{
internal:
	NxaHeightFieldShape(NxShape * ptr);

public:
	float GetColumnScale();
	float GetRowScale();
	float GetHeightScale();
	void SetColumnScale(float scale);
	void SetRowScale(float scale);
	void SetHeightScale(float scale);
	NxaHeightField ^ GetHeightField();
	float GetHeightAtShapePoint(float x, float z);
	NxaMaterialIndex GetMaterialAtShapePoint(float x, float z);
	Vector3 GetNormalAtShapePoint(float x, float z);
	Vector3 GetSmoothNormalAtShapePoint(float x, float z);
	bool IsShapePointOnHeightField(float x, float z);
	void SaveToDescription(NxaHeightFieldShapeDescription ^% description);
};
