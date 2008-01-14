#pragma once

#include "NxaBodyDescription.h"
#include "NxaBoxShapeDescription.h"
#include "NxPhysics.h"

using namespace Microsoft::Xna::Framework;
using namespace System::Collections::Generic;

namespace PhysXCPP
{
	public ref class NxaActorDescription
	{

	internal:
		NxActorDesc* nxActorDesc;
	
	public:
		NxaActorDescription(void);
		!NxaActorDescription(void);

		void AddShape(NxaShapeDescription^ description);

		property NxaBodyDescription^ Body
		{
			void set(NxaBodyDescription^ value);
		}

		property float Density
		{
			float get() { return nxActorDesc->density; }
			void set(float value);
		}
		
		property Matrix GlobalPose
		{
			void set(Matrix value);
		}

		property array<NxaShapeDescription^>^ Shapes
		{
			array<NxaShapeDescription^>^ get();
		}
	};
}