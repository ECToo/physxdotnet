#pragma once

public enum class NxaActorFlag : unsigned int 
{ 
	DisableCollision = (1<<0),
	DisableResponse = (1<<1),
	LockCentreOfMass = (1<<2),
	FluidDisableCollision = (1<<3),
	ContactModification = (1<<4),
	ForceConeFriction = (1<<5),
	UserActorPairFiltering = (1<<6)
};
public enum class NxaBodyFlag : unsigned int { Disable_Gravity = (1<<0), Kinematic = (1<<1) };

public enum class NxaForceMode 
{
	Force = 0,
	Impulse = 1,
	VelocityChange = 2,
	SmoothImpulse = 3,
	SmoothVelocityChange = 4,
	Acceleration = 5
};

public enum class NxaJointFlag : unsigned int { Collision_Enabled = (1<<0) };
public enum class NxaMaterialFlag : unsigned int { Anisotropic = (1<<0), Disable_Friction = (1<<4), Disable_Strong_Friction = (1<<5) };

public enum class NxaShapeFlag : unsigned int 
{ 
	TriggerOnEnter = (1<<0), 
	TriggerOnLeave = (1<<1),
	TriggerOnStay = (1<<2),
	TriggerEnable = TriggerOnEnter | TriggerOnLeave | TriggerOnStay,
	Visualization = (1<<3),
	DisableCollision = (1<<4),
	FeatureIndices = (1<<5),
	DisableRaycasting = (1<<6),
	PointContactForce = (1<<7),
	FluidDrain = (1<<8),
	FluidDisableCollision = (1<<10),
	FluidTwoWay = (1<<11),
	DisableResponse = (1<<12),
	DynamicDynamicCCD = (1<<13),
	DisableSceneQueries = (1<<14),
	ClothDrain = (1<<15),
	ClothDisableCollision = (1<<16),
	ClothTwoWay = (1<<17),
	SoftBodyDrain = (1<<18),
	SoftBodyDisableCollision = (1<<19),
	SoftBodyTwoWay = (1<<20)
};

public enum class NxaShapeType : unsigned int { Plane, Sphere, Box, Capsule, Wheel, Convex, Mesh, Heightfield };
public enum class NxaSimulationType { Software, Hardware };

public enum class NxaThreadPriority { High = 0, AboveNormal = 1, Normal = 2, BelowNormal = 3, Low = 4 };
public enum class NxaTimeStepMethod { Fixed = 0, Variable = 1 };

typedef unsigned short NxaActorGroup;
typedef unsigned short NxaCollisionGroup;
typedef unsigned short NxaDominanceGroup;
typedef unsigned short NxaMaterialIndex;
typedef unsigned int NxaU32;