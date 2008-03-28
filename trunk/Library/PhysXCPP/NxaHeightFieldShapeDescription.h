// completely new file

#pragma once

#include "NxHeightFieldShapeDesc.h"
#include "NxaHeightFieldDescription.h"
#include "NxaHeightField.h"
#include "NxaShapeDescription.h"

public ref class NxaHeightFieldShapeDescription : NxaShapeDescription
{
public:
	NxaHeightFieldShapeDescription(void);
	~NxaHeightFieldShapeDescription(void);
	!NxaHeightFieldShapeDescription(void);

	property NxaHeightField^ HeightField
	{
		NxaHeightField^ get() { return gcnew NxaHeightField(((NxHeightFieldShapeDesc *)nxShapeDesc)->heightField); };
		void set(NxaHeightField^ value) { ((NxHeightFieldShapeDesc *)nxShapeDesc)->heightField = value->nxHeightField; };
	}
	property float HeightScale
	{
		float get() { return ((NxHeightFieldShapeDesc *)nxShapeDesc)->heightScale; };
		void set(float value) { ((NxHeightFieldShapeDesc *)nxShapeDesc)->heightScale = value; };
	}
	property float RowScale
	{
		float get() { return ((NxHeightFieldShapeDesc *)nxShapeDesc)->rowScale; };
		void set(float value) { ((NxHeightFieldShapeDesc *)nxShapeDesc)->rowScale = value; };
	}
	property float ColumnScale
	{
		float get() { return ((NxHeightFieldShapeDesc *)nxShapeDesc)->columnScale; };
		void set(float value) { ((NxHeightFieldShapeDesc *)nxShapeDesc)->columnScale = value; };
	}
	property NxaMaterialIndex MaterialIndexHighBits
	{
		NxaMaterialIndex get() { return ((NxHeightFieldShapeDesc *)nxShapeDesc)->materialIndexHighBits; };
		void set(NxaMaterialIndex value) { ((NxHeightFieldShapeDesc *)nxShapeDesc)->materialIndexHighBits = value; }
	}
	property NxaMaterialIndex HoleMaterial
	{
		NxaMaterialIndex get() { return ((NxHeightFieldShapeDesc *)nxShapeDesc)->holeMaterial; };
		void set(NxaMaterialIndex value) { ((NxHeightFieldShapeDesc *)nxShapeDesc)->holeMaterial = value; }
	}
	
internal:
	NxaHeightFieldShapeDescription(NxHeightFieldShapeDesc* ptr);
};
