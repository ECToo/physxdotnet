#pragma once

#include "NxPhysics.h"
using namespace Microsoft::Xna::Framework;

namespace PhysXCPP
{

	public ref class NxaMaterialDescription
	{
	public:
		NxaMaterialDescription(void);
		~NxaMaterialDescription(void);
		!NxaMaterialDescription(void);

		property float DynamicFriction
		{
			float get() { return nxMaterialDesc->dynamicFriction; }
			void set(float dFriction) { nxMaterialDesc->dynamicFriction = dFriction; }
		}

		property float StaticFriction
		{
			float get() { return nxMaterialDesc->staticFriction; }
			void set(float sFriction) { nxMaterialDesc->staticFriction = sFriction; }
		}

		property float Restitution
		{
			float get() { return nxMaterialDesc->restitution; }
			void set(float restitution) { nxMaterialDesc->restitution = restitution; }
		}

		property float DynamicFrictionV
		{
			float get() { return nxMaterialDesc->dynamicFrictionV; }
			void set(float dFrictionV) { nxMaterialDesc->dynamicFrictionV = dFrictionV; }
		}

		property float StaticFrictionV
		{
			float get() { return nxMaterialDesc->staticFrictionV; }
			void set(float sFrictionV) { nxMaterialDesc->staticFrictionV = sFrictionV; }
		}

		property Vector3 DirectionOfAnisotropy
		{
			Vector3 get();
			void set(Vector3 value) { nxMaterialDesc->dirOfAnisotropy = NxVec3(value.X, value.Y, value.Z); }
		}

	private:
		NxMaterialDesc* nxMaterialDesc;
	};

}