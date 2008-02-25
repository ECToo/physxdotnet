using System;
using System.Collections.Generic;
using System.Text;

using XNAPhysX.Physics;
using XNAPhysX.Input;
using XNAPhysX.Graphics.DebugRenderer;
using XNAPhysX;

using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

using System.Diagnostics;

namespace Lesson215
{
    public class Lesson215Scene : PhysXScene
    {
        const float forceStrength = 50000;
        const float deltaTime = 1f / 60f;
        const float forceLineLength = 3;

        NxaActor groundPlane;
        NxaActor sphere1, sphere2;

        NxaD6Joint d6Joint;
        int gJointType = 0;

        Vector3 forceDirection = Vector3.Zero;
        bool forceMode = true;

        public Lesson215Scene() : base()
        {
            groundPlane = CreateGroundPlane();

            sphere1 = CreateSphere(new Vector3(0, 5, 0), 1f, 10);
            sphere1.RaiseBodyFlag(NxaBodyFlag.Kinematic);
            sphere2 = CreateSphere(new Vector3(0, 3, 0), 1, 10);
            sphere2.SetLinearDamping(0.5f);

            actors.Add(groundPlane);
            actors.Add(sphere1);
            actors.Add(sphere2);

            d6Joint = CreateD6Joint(sphere1, sphere2, new Vector3(0, 5, 0), -Vector3.UnitZ);
            
            selectedActor = sphere2;

            Console.WriteLine(" Flight Controls:\n ----------------\n w = forward, s = back\n a = strafe left, d = strafe right\n q = up, z = down\n");
            Console.WriteLine(" Force Controls:\n ---------------\n i = +z, k = -z\n j = +x, l = -x\n u = +y, m = -y\n");
            Console.WriteLine(" Miscellaneous:\n --------------\n r = Select Next Actor\n f = Toggle Force Mode\n");
            Console.WriteLine(" Special:\n --------------\n t = Reconfigure Joint");
        }

        private NxaD6Joint CreateD6Joint(NxaActor a0, NxaActor a1, Vector3 globalAnchor, Vector3 globalAxis)
        {
            NxaD6JointDescription d6Desc = new NxaD6JointDescription();
            d6Desc.Actor[0] = a0;
            d6Desc.Actor[1] = a1;
            d6Desc.SetGlobalAnchor(globalAnchor);
            d6Desc.SetGlobalAxis(globalAxis);

            d6Desc.TwistMotion = NxaD6JointMotion.Locked;
            d6Desc.Swing1Motion = NxaD6JointMotion.Locked;
            d6Desc.Swing2Motion = NxaD6JointMotion.Locked;

            d6Desc.XMotion = NxaD6JointMotion.Locked;
            d6Desc.YMotion = NxaD6JointMotion.Locked;
            d6Desc.ZMotion = NxaD6JointMotion.Locked;

            d6Desc.ProjectionMode = NxaJointProjectionMode.None;

            return (NxaD6Joint)scene.CreateJoint(d6Desc);
        }

        private NxaActor CreateSphere(Vector3 pos, float radius, float density)
        {
            NxaActorDescription actorDesc = new NxaActorDescription();
            NxaBodyDescription bodyDesc = new NxaBodyDescription();

            NxaSphereShapeDescription sphereDesc = new NxaSphereShapeDescription();
            sphereDesc.Radius = radius;
            sphereDesc.LocalPose = Matrix.CreateTranslation(new Vector3(0, radius, 0));
            actorDesc.AddShape(sphereDesc);

            actorDesc.Body = bodyDesc;
            actorDesc.Density = density;
            actorDesc.GlobalPose = Matrix.CreateTranslation(pos);

            return scene.CreateActor(actorDesc);
        }

        private NxaActor CreateGroundPlane()
        {
            NxaPlaneShapeDescription planeDesc = new NxaPlaneShapeDescription();
            NxaActorDescription actorDesc = new NxaActorDescription();
            actorDesc.AddShape(planeDesc);
            return scene.CreateActor(actorDesc);
        }

        private void ReconfigureD6Joint()
        {
            NxaActor a0 = sphere1;
            NxaActor a1 = sphere2;

            NxaD6JointDescription oldD6Desc = new NxaD6JointDescription();
            NxaD6JointDescription d6Desc = new NxaD6JointDescription();

            Vector3[] localAnchor = new Vector3[2];
            Vector3[] localAxis = new Vector3[2];
            Vector3[] localNormal = new Vector3[2];
            Vector3[] localBinormal = new Vector3[2];

            d6Joint.SaveToDescription(out oldD6Desc);

            for (int i = 0; i < 2; i++)
            {
                localAnchor[i] = oldD6Desc.LocalAnchor[i];
                localAxis[i] = oldD6Desc.LocalAxis[i];
                localNormal[i] = oldD6Desc.LocalNormal[i];
                localBinormal[i] = Vector3.Cross(localNormal[i], localAxis[0]);
            }

            switch (gJointType)
            {
                case 0: //Fixed Joint
                    {
                        //Coming from spherical joint, so reset actor #1
                        Matrix orientation = Matrix.Identity;
                        a1.RaiseBodyFlag(NxaBodyFlag.Kinematic);
                        a1.SetGlobalOrientation(orientation);
                        a1.SetGlobalPosition(new Vector3(0, 3, 0));
                        a1.ClearBodyFlag(NxaBodyFlag.Kinematic);

                        d6Desc.Actor[0] = a0;
                        d6Desc.Actor[1] = a1;

                        // Reset anchor and axis
                        Vector3 globalAnchor = new Vector3(0, 5, 0);
                        Vector3 globalAxis = new Vector3(0, 0, -1);

                        d6Desc.SetGlobalAnchor(globalAnchor);
                        d6Desc.SetGlobalAxis(globalAxis);

                        d6Desc.TwistMotion = NxaD6JointMotion.Locked;
                        d6Desc.Swing1Motion = NxaD6JointMotion.Locked;
                        d6Desc.Swing2Motion = NxaD6JointMotion.Locked;

                        d6Desc.XMotion = NxaD6JointMotion.Locked;
                        d6Desc.YMotion = NxaD6JointMotion.Locked;
                        d6Desc.ZMotion = NxaD6JointMotion.Locked;

                        Console.WriteLine("Joint is now a Fixed Joint");
                    }
                    break;

                case 1: // Revolute Joint
                    {
                        d6Desc.Actor[0] = a0;
                        d6Desc.Actor[1] = a1;

                        for (int i = 0; i < 2; i++)
                        {
                            d6Desc.LocalAnchor[i] = localAnchor[i];
                            d6Desc.LocalAxis[i] = localAxis[i];
                            d6Desc.LocalNormal[i] = localNormal[i];
                        }

                        d6Desc.TwistMotion = NxaD6JointMotion.Free;
                        d6Desc.Swing1Motion = NxaD6JointMotion.Locked;
                        d6Desc.Swing2Motion = NxaD6JointMotion.Locked;

                        d6Desc.XMotion = NxaD6JointMotion.Locked;
                        d6Desc.YMotion = NxaD6JointMotion.Locked;
                        d6Desc.ZMotion = NxaD6JointMotion.Locked;

                        Console.WriteLine("Joint is now a Revolute Joint");
                    }
                    break;
                case 2: // Spherical Joint
                    {
                        d6Desc.Actor[0] = a0;
                        d6Desc.Actor[1] = a1;

                        for (int i = 0; i < 2; i++)
                        {
                            d6Desc.LocalAnchor[i] = localAnchor[i];
                            d6Desc.LocalAxis[i] = localBinormal[i];
                            d6Desc.LocalNormal[i] = localNormal[i];
                        }

                        d6Desc.TwistMotion = NxaD6JointMotion.Free;
                        d6Desc.Swing1Motion = NxaD6JointMotion.Free;
                        d6Desc.Swing2Motion = NxaD6JointMotion.Free;

                        d6Desc.XMotion = NxaD6JointMotion.Locked;
                        d6Desc.YMotion = NxaD6JointMotion.Locked;
                        d6Desc.ZMotion = NxaD6JointMotion.Locked;

                        Console.WriteLine("Joint is now a Spherical Joint");
                    }
                    break;
            }

            d6Desc.ProjectionMode = NxaJointProjectionMode.None;
            d6Joint.LoadFromDescription(d6Desc);
        }

        private void NextSelectedActor()
        {
            int index = actors.IndexOf(selectedActor);
            index++;
            selectedActor = actors[index % actors.Count];

            while (!IsSelectable(selectedActor))
            {
                index++;
                selectedActor = actors[index % actors.Count];
            }
        }

        private bool IsSelectable(NxaActor actor)
        {
            return actor != groundPlane;
        }

        public override void HandleInput(GameTime gameTime, GameInput input)
        {
            float f = (float)gameTime.ElapsedGameTime.TotalSeconds;

            if (input.Keyboard.NewState.IsKeyDown(Keys.R) && input.Keyboard.OldState.IsKeyUp(Keys.R))
                NextSelectedActor();

            if (input.Keyboard.NewState.IsKeyDown(Keys.F) && input.Keyboard.OldState.IsKeyUp(Keys.F))
                forceMode = !forceMode;

            if (input.Keyboard.NewState.IsKeyDown(Keys.I))
                forceDirection = Vector3.UnitZ;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.K))
                forceDirection = -Vector3.UnitZ;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.J))
                forceDirection = Vector3.UnitX;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.L))
                forceDirection = -Vector3.UnitX;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.U))
                forceDirection = Vector3.UnitY;
            else if (input.Keyboard.NewState.IsKeyDown(Keys.M))
                forceDirection = -Vector3.UnitY;
            else
                forceDirection = Vector3.Zero;

            if (input.Keyboard.NewState.IsKeyDown(Keys.T) && input.Keyboard.OldState.IsKeyUp(Keys.T))
            {
                gJointType++;
                gJointType %= 3;
                ReconfigureD6Joint();
            }

            if (forceDirection != Vector3.Zero)
            {
                if (forceMode)
                    selectedActor.AddForce(forceDirection * forceStrength * f, NxaForceMode.Force, true);
                else
                    selectedActor.AddTorque(forceDirection * forceStrength * f, NxaForceMode.Force, true);
            }
        }

        public override void Draw(DebugCamera camera, GameTime gameTime)
        {
            base.Draw(camera, gameTime);

            if (forceDirection != Vector3.Zero)
            {
                Vector3 pos = selectedActor.GetCenterOfMassGlobalPosition();

                Color c = Color.Yellow;
                if (!forceMode)
                    c = Color.Cyan;

                DebugRenderer.DrawLine(camera.ViewProjection, pos, pos + (forceDirection * forceLineLength), c);
            }
        }
    }
}
