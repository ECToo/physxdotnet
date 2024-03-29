#pragma once

typedef unsigned short NxaActorGroup;
typedef unsigned short NxaCollisionGroup;
typedef unsigned short NxaDominanceGroup;
typedef unsigned short NxaMaterialIndex;
typedef unsigned short NxaActorGroup;
typedef unsigned int NxaSubmeshIndex;
typedef unsigned char NxaU8;
typedef unsigned short NxaU16;
typedef unsigned int NxaU32;
typedef unsigned __int64 NxaU64;
typedef float NxaF32;
typedef double NxaF64;


public enum class NxaActorFlag : NxaU32 
{ 
	DisableCollision = (1<<0),
	DisableResponse = (1<<1),
	LockCentreOfMass = (1<<2),
	FluidDisableCollision = (1<<3),
	ContactModification = (1<<4),
	ForceConeFriction = (1<<5),
	UserActorPairFiltering = (1<<6)
};
public enum class NxaBodyFlag : NxaU32 
{ 
	DisableGravity = (1<<0),
	FrozenPositionX = (1<<1),
	FrozenPositionY = (1<<2),
	FrozenPositionZ = (1<<3),
	FrozenRotationX = (1<<4),
	FrozenRotationY = (1<<5),
	FrozenRotationZ = (1<<6),
	FrozenPosition = FrozenPositionX | FrozenPositionY | FrozenPositionZ,
	FrozenRotation = FrozenRotationX | FrozenRotationY | FrozenRotationZ,
	Frozen = FrozenPosition | FrozenRotation,
	Kinematic = (1<<7),
	Visualization = (1<<8),
	PoseSleepTest = (1<<9),
	FilterSleepVelocities = (1<<10),
	EnergySleepTest = (1<<11)
};

public enum class NxaCombineMode 
{ 
	Average, 
	Minimum, 
	Multiply, 
	Maximum 
};

public enum class NxaConvexFlags  : NxaU32
{ 
	FlipNormals = (1<<0),
	SixteenBitIndices = (1<<1),
	ComputeConvex = (1<<2),
	InflateConvex = (1<<3),
	UseLegacyCooker = (1<<4),
	UseUncompressedNormals = (1<<5)
};

public enum class NxaD6JointDriveType : NxaU32
{
	DrivePosition = (1<<0),
	DriveVelocity = (1<<1)
};

public enum class NxaD6JointFlag : NxaU32
{
	SlerpDrive = (1<<0),
	GearEnabled = (1<<1)
};

public enum class NxaD6JointMotion
{
	Locked,
	Limited,
	Free
};

public enum class NxaForceMode 
{
	Force = 0,
	Impulse = 1,
	VelocityChange = 2,
	SmoothImpulse = 3,
	SmoothVelocityChange = 4,
	Acceleration = 5
};

public enum class NxaInternalArray 
{ 
	Triangles, 
	Vertices, 
	Normals, 
	HullVertices, 
	HullPolygons 
};

public enum class NxaInternalFormat 
{ 
	NoData, 
	Float, 
	Byte, 
	Short, 
	Int 
};

public enum class NxaJointType 
{
	Prismatic,
	Revolute,
	Cylindrical,
	Spherical,
	PointOnLine,
	PointInPlane,
	Distance,
	Pulley,
	Fixed,
	D6
};

public enum class NxaJointState 
{
	Unbound,
	Simulating,
	Broken
};

public enum class NxaJointFlag : NxaU32 
{ 
	CollisionEnabled = (1<<0),
	Visualization = (1<<1)
};

public enum class NxaJointProjectionMode
{
	None,
	PointMinimumDistance,
	LinearMinimumDistance
};

public enum class NxaRevoluteJointFlag : NxaU32
{
	LimitEnabled = (1<<0),
	MotorEnabled = (1<<1),
	SpringEnabled = (1<<2)
};

public enum class NxaDistanceJointFlag : NxaU32
{
	MaxDistanceEnabled = 1 << 0,
	MinDistanceEnabled = 1 << 1,
	SpringEnabled = 1 << 2
};

public enum class NxaPulleyJointFlag : NxaU32
{
	IsRigid = 1 << 0,
	MotorEnabled = 1 << 1
};

public enum class NxaMaterialFlag : NxaU32 
{ 
	Anisotropic = (1<<0), 
	Disable_Friction = (1<<4), 
	Disable_Strong_Friction = (1<<5) 
};

public enum class NxaShapeFlag : NxaU32
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

public enum class NxaShapesType : NxaU32
{
	StaticShapes = (1<<0),
	DynamicShapes = (1<<1),
	AllShapes = StaticShapes | DynamicShapes
};

public enum class NxaShapeType : NxaU32 
{ 
	Plane, 
	Sphere, 
	Box, 
	Capsule, 
	Wheel, 
	Convex, 
	Mesh, 
	Heightfield 
};

public enum class NxaSphericalJointFlag : NxaU32
{
	TwistLimitEnabled = (1<<0),
	SwingLimitEnabled = (1<<1),
	TwistSpringEnabled = (1<<2),
	SwingSpringEnabled = (1<<3),
	JointSpringEnabled = (1<<4)
};

public enum class NxaThreadPriority
{	
	High = 0, 
	AboveNormal = 1, 
	Normal = 2, 
	BelowNormal = 3, 
	Low = 4 
};

public enum class NxaContactPairFlag : NxaU32
{
	IgnorePair					= (1<<0),

	NotifyOnStartTouch			= (1<<1),
	NotifyOnEndTouch			= (1<<2),
	NotityOnTouch				= (1<<3),	// Not yet implemented
	NotifyOnImpact				= (1<<4),	// Not yet implemented
	NotifyOnRoll				= (1<<5),	// Not yet implemented
	NotifyOnSlide				= (1<<6),	// Not yet implemented
	NotifyForces				= (1<<7),

	NotifyContactModification	= (1<<16),

	NotifyAll					= (NotifyOnStartTouch | NotifyOnEndTouch | NotityOnTouch | NotifyOnImpact | NotifyOnRoll | NotifyOnSlide | NotifyForces),
};

public enum class NxaCapsuleClimbingMode : NxaU32
{
	ClimbEasy				= 0,
	ClimbConstrained		= 1,
	ClimbLast				= 2,
};

public enum class NxaControllerType : NxaU32
{
	ControllerBox			= 0,
	ControllerCapsule		= 1,
};

typedef NxaShapeFlag	NxaTriggerFlag;
