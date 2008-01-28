#pragma once

#include "NxaMaterialDescription.h"
#include "Nxap.h"

#include "NxMaterial.h"

ref class NxaScene;

public ref class NxaMaterial
{
internal:
	NxMaterial* nxMaterial;
	static NxaMaterial^ CreateFromPointer(NxMaterial* ptr);
	NxaMaterial(NxMaterial* ptr);
	~NxaMaterial();
	!NxaMaterial();

public:
	NxaMaterialIndex GetMaterialIndex();

	void LoadFromDescription(NxaMaterialDescription^ description);
	void SaveToDescription([Out] NxaMaterialDescription^% description);

	NxaScene^ GetScene();

	void SetDynamicFriction(float coefficient);
	float GetDynamicFriction();
	void SetStaticFriction(float coefficient);
	float GetStaticFriction();

	void SetRestitution(float restitution);
	float GetRestitution();

	void SetDynamicFrictionV(float coefficient);
	float GetDynamicFrictionV();

	void SetStaticFrictionV(float coefficient);
	float GetStaticFrictionV();

	void SetDirectionOfAnisotropy(Vector3 vector);
	Vector3 GetDirectionOfAnisotropy();

	void SetFlags(NxaU32 flags);
	NxaU32 GetFlags();

	void SetFrictionCombineMode(NxaCombineMode combineMode);
	NxaCombineMode GetFrictionCombineMode();

	void SetRestitutionCombineMode(NxaCombineMode combineMode);
	NxaCombineMode GetRestitutionCombineMode();

	property Object^ UserData;
};