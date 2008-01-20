#pragma once

#include "Stdafx.h"
#include "NxaMath.h"
#include "NxBox.h"

public ref class NxaBox
{
	internal:
		NxBox* nxBox;

	public:
		NxaBox(void);
		NxaBox(Vector3 center, Vector3 extents, Matrix rotation);
		~NxaBox(void);
		!NxaBox(void);

		void SetEmpty();
		bool IsValid();

		property Vector3 Center
		{
			Vector3 get() { return NxaMath::Vector3PhysXToXNA(nxBox->center); }
			void set(Vector3 center) { nxBox->center = NxaMath::Vector3XNAToPhysX(center); }
		}

		property Vector3 Extents
		{
			Vector3 get() { return NxaMath::Vector3PhysXToXNA(nxBox->extents); }
			void set(Vector3 extents) { nxBox->extents = NxaMath::Vector3XNAToPhysX(extents); }
		}

		property Matrix Rotation
		{
			Matrix get() { return NxaMath::MatrixPhysXToXNA(nxBox->rot); }
			void set(Matrix m) { nxBox->rot = NxaMath::MatrixRotXNAToPhysX(m); }
		}
};