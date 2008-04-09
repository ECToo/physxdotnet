#pragma once

#include "Nxap.h"

#include "NxShape.h"
ref class NxaActor;

public ref class NxaShape abstract
{
internal:

	NxShape* nxShape;
	NxaShape(NxShape* ptr);

	static NxaShape^ CreateFromPointer(NxShape* ptr);

public:
	!NxaShape();
	~NxaShape();
	NxaActor^ GetActor();
	//void SetGroup(NxaCollisionGroup collisionGroup) { nxShape->setGroup(collisionGroup); }
	//NxaCollisionGroup GetGroup();
	
	void SetFlag(NxaShapeFlag flag, bool value);
	bool GetFlag(NxaShapeFlag flag);

	//Is... Shape Type
	bool Is(NxaShapeType type);
	bool IsBox() { return (nxShape->isBox() != NULL); }
	bool IsCapsule() { return (nxShape->isCapsule() != NULL); }
	bool IsConvexMesh() { return (nxShape->isConvexMesh() != NULL); }
	bool IsHeightField() { return (nxShape->isHeightField() != NULL); }
	bool IsPlane() { return (nxShape->isPlane() != NULL); }
	bool IsSphere() { return (nxShape->isSphere() != NULL); }
	bool IsTriangleMesh() { return (nxShape->isTriangleMesh() != NULL); }
	bool IsWheel() { return (nxShape->isWheel() != NULL); }
	
	Vector3 GetGlobalPosition();
	void SetGlobalPosition(Vector3 position);
	Matrix GetGlobalPose();
	void SetGlobalPose(Matrix pose);
	Matrix GetGlobalOrientation();
	void SetGlobalOrientation(Matrix orientation);

	property Object^ UserData
	{
		Object^ get();
		void set(Object ^);
	}
};