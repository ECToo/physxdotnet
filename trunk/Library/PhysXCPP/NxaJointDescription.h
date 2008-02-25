#pragma once

#include "Nxap.h"
#include "NxaActor.h"

ref class NxaJoint;

class NxScene;
class NxJointDesc;


public ref class NxaJointDescription abstract
{
internal:
	virtual void LoadFromNative(NxJointDesc& desc);
	virtual void ConvertToNative(NxJointDesc& desc);
	virtual NxaJoint^ CreateJoint(NxScene* scenePtr) abstract;

	void SetGlobalAnchor(int index, Vector3 worldAnchor);
	void SetGlobalAxis(int index, Vector3 worldAxis);

protected:
	NxaJointDescription(NxaJointType jointType);
	NxaJointType jointType;

public:
	
	virtual void SetToDefault();
	virtual bool IsValid();
	NxaJointType GetType();

	void SetGlobalAnchor(Vector3 anchor);
	void SetGlobalAxis(Vector3 axis);

	array<NxaActor^>^ Actor;
	array<Vector3>^ LocalAnchor;
	array<Vector3>^ LocalAxis;
	array<Vector3>^ LocalNormal;
	float MaxForce;
	float MaxTorque;
	Object^ UserData;
	String^ Name;
	NxaJointFlag JointFlags;
};