#pragma once

public enum class NxaActorFlag : unsigned int { Disable_Collision = (1<<0) };
public enum class NxaBodyFlag : unsigned int { Disable_Gravity = (1<<0), Kinematic = (1<<1) };
public enum class NxaJointFlag : unsigned int { Collision_Enabled = (1<<0) };
public enum class NxaMaterialFlag : unsigned int { Anisotropic = (1<<0), Disable_Friction = (1<<4), Disable_Strong_Friction = (1<<5) };
public enum class NxaShapeFlag : unsigned int { Disable_Collision = (1<<4) };
public enum class NxaShapeType : unsigned int { Plane, Sphere, Box, Capsule, Wheel, Convex, Mesh, Heightfield };
public enum class NxaSimulationType { Software, Hardware };