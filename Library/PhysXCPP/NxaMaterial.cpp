#include "StdAfx.h"

#include "NxaMaterial.h"
#include "NxaMath.h"
#include "NxaScene.h"
#include "NxContainer.h"

NxaMaterial^ NxaMaterial::CreateFromPointer(NxMaterial *ptr)
{
	if(ptr == NULL)
	{
		return nullptr;
	}

	return gcnew NxaMaterial(ptr);
}

NxaMaterial::NxaMaterial(NxMaterial* ptr)
{
	nxMaterial = ptr;
}

NxaMaterial::~NxaMaterial()
{

}

NxaMaterial::!NxaMaterial()
{

}

NxaMaterialIndex NxaMaterial::GetMaterialIndex()
{
	return nxMaterial->getMaterialIndex();
}

void NxaMaterial::LoadFromDescription(NxaMaterialDescription^ description)
{
	nxMaterial->loadFromDesc(*(description->nxMaterialDesc));
}

void NxaMaterial::SaveToDescription([Out] NxaMaterialDescription ^%description)
{
	nxMaterial->saveToDesc(*(description->nxMaterialDesc));
}

NxaScene^ NxaMaterial::GetScene()
{
	NxScene& sceneRef = nxMaterial->getScene();
	return NxSceneContainer::GetInstance()->Find(IntPtr(&sceneRef));
}

void NxaMaterial::SetDynamicFriction(float coefficient)
{
	nxMaterial->setDynamicFriction(coefficient);
}

float NxaMaterial::GetDynamicFriction()
{
	return nxMaterial->getDynamicFriction();
}

void NxaMaterial::SetStaticFriction(float coefficient)
{
	nxMaterial->setStaticFriction(coefficient);
}

float NxaMaterial::GetStaticFriction()
{
	return nxMaterial->getStaticFriction();
}

void NxaMaterial::SetRestitution(float restitution)
{
	nxMaterial->setRestitution(restitution);
}

float NxaMaterial::GetRestitution()
{
	return nxMaterial->getRestitution();
}

void NxaMaterial::SetDynamicFrictionV(float coefficient)
{
	nxMaterial->setDynamicFrictionV(coefficient);
}

float NxaMaterial::GetDynamicFrictionV()
{
	return nxMaterial->getDynamicFrictionV();
}

void NxaMaterial::SetStaticFrictionV(float coefficient)
{
	nxMaterial->setStaticFrictionV(coefficient);
}

float NxaMaterial::GetStaticFrictionV()
{
	return nxMaterial->getStaticFrictionV();
}

void NxaMaterial::SetDirectionOfAnisotropy(Vector3 vector)
{
	nxMaterial->setDirOfAnisotropy(NxaMath::Vector3XNAToPhysX(vector));
}

Vector3 NxaMaterial::GetDirectionOfAnisotropy()
{
	return NxaMath::Vector3PhysXToXNA(nxMaterial->getDirOfAnisotropy());
}

void NxaMaterial::SetFlags(NxaU32 flags)
{
	nxMaterial->setFlags(flags);
}

NxaU32 NxaMaterial::GetFlags()
{
	return nxMaterial->getFlags();
}

void NxaMaterial::SetFrictionCombineMode(NxaCombineMode combineMode)
{
	nxMaterial->setFrictionCombineMode((NxCombineMode)combineMode);
}

NxaCombineMode NxaMaterial::GetFrictionCombineMode()
{
	return (NxaCombineMode)nxMaterial->getFrictionCombineMode();
}

void NxaMaterial::SetRestitutionCombineMode(NxaCombineMode combineMode)
{
	nxMaterial->setRestitutionCombineMode((NxCombineMode)combineMode);
}

NxaCombineMode NxaMaterial::GetRestitutionCombineMode()
{
	return (NxaCombineMode)nxMaterial->getRestitutionCombineMode();
}