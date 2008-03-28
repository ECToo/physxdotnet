// completely new file

#include "StdAfx.h"
#include "NxaHeightField.h"
#include "PhysXloader.h"
#include "PhysXCPP.h"
#include "NxHeightFieldSample.h"

NxaHeightField::NxaHeightField(NxaHeightFieldDescription^ description)
{
	nxHeightField = PhysXEngine::sdk->createHeightField(*(description->nxHeightFieldDesc));
}

NxaHeightField::NxaHeightField(NxHeightField * ptr)
{
	nxHeightField = ptr;
}

array<NxaHeightFieldSample> ^ NxaHeightField::GetCells()
{
	int size = GetColumnsCount() * GetRowCount();
	array<NxaHeightFieldSample> ^ cells = gcnew array<NxaHeightFieldSample>(size);
	char * currentCell = (char *)nxHeightField->getCells();

	for(int i = 0; i < size; i++)
	{
		cells[i].GetDataFrom((NxHeightFieldSample *)currentCell);

		currentCell += GetSampleStride();
	}

	return cells;	
}

float NxaHeightField::GetConvexEdgeThreshold()
{
	return nxHeightField->getConvexEdgeThreshold();
}

float NxaHeightField::GetHeight(float x, float z)
{
	return nxHeightField->getHeight(x,z);
}

int NxaHeightField::GetColumnsCount()
{
	return nxHeightField->getNbColumns();
}

int NxaHeightField::GetRowCount()
{
	return nxHeightField->getNbRows();
}

int NxaHeightField::GetReferenceCount()
{
	return nxHeightField->getReferenceCount();
}

int NxaHeightField::GetSampleStride()
{
	return nxHeightField->getSampleStride();
}

float NxaHeightField::GetThickness()
{
	return nxHeightField->getThickness();
}

float NxaHeightField::GetVerticalExtent()
{
	return nxHeightField->getVerticalExtent();
}

bool NxaHeightField::LoadFromDescription(NxaHeightFieldDescription ^ description)
{
	return nxHeightField->loadFromDesc(*(description->nxHeightFieldDesc));
}

void NxaHeightField::SaveCells(array<NxaHeightFieldSample> ^% destBuffer)
{
	destBuffer = GetCells();
}
bool NxaHeightField::SaveToDescription(NxaHeightFieldDescription ^% description)
{
	return nxHeightField->saveToDesc(*(description->nxHeightFieldDesc));
}