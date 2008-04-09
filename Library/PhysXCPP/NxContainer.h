#pragma once

ref class NxaActor;
ref class NxaShape;
ref class NxaScene;
ref class NxaController;

using namespace System::Collections::Generic;

#include <vcclr.h>

generic <typename U>
ref class NxContainer
{
private:
	Dictionary<IntPtr, U> ^ arObjects;

public:
	bool Add(IntPtr uObject, U mObject)
	{
		if(arObjects->ContainsKey(uObject))
			return false;

		arObjects->Add(uObject, mObject);
		return true;
	};
	U Find(IntPtr uObject)
	{
		if(arObjects->ContainsKey(uObject))
			return arObjects[uObject];
		else
			return U();
	};
	void Remove(IntPtr uObject)
	{
		arObjects->Remove(uObject);
	};
			
// singleton functions and data
private:
	NxContainer()
	{
		arObjects = gcnew Dictionary<IntPtr, U>();
	};
	static NxContainer ^ instance = nullptr;

public:
	static NxContainer^ GetInstance()
	{
		if(instance == nullptr)
			instance = gcnew NxContainer();

		return instance;
	};
};



typedef NxContainer<NxaScene ^> NxSceneContainer;
typedef NxContainer<NxaActor ^> NxActorContainer;
typedef NxContainer<NxaShape ^> NxShapeContainer;
typedef NxContainer<NxaController ^> NxControllerContainer;