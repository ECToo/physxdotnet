using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;

namespace XNAPhysX
{
    public class RTCamera
    {
        private float ar, fov;
        private Vector3 position;

        private Vector3 firstLook = Vector3.UnitZ;
        private float yaw, pitch, roll;
        private Quaternion rotation = Quaternion.Identity;

        private Matrix view = Matrix.Identity;
        private Matrix proj = Matrix.Identity;

        public RTCamera(float aspectRatio, Vector3 position, float fov)
        {
            this.fov = fov;
            this.ar = aspectRatio;
            this.position = position;

            UpdateViewMatrix();
            UpdateProjMatrix();
        }

        public void MoveForward(float distance)
        {
            Vector3 direction = Vector3.Transform(firstLook, rotation);
            Vector3 delta = (direction * distance);
            position += delta;
        }

        public void Strafe(float distance)
        {
            Vector3 forward = Vector3.Transform(firstLook, rotation);
            Vector3 right = Vector3.Cross(forward, Vector3.Transform(Vector3.Up, rotation));
            Vector3 delta = (right * distance);
            position += delta;
        }

        public void Yaw(float radians)
        {
            yaw -= radians;
        }

        public void Pitch(float radians)
        {
            pitch += radians;
        }

        public void Roll(float radians)
        {
            roll += radians;
        }

        private void UpdateViewMatrix()
        {
            rotation = Quaternion.CreateFromYawPitchRoll(yaw, pitch, roll);
            Vector3 rotated = Vector3.Transform(firstLook, rotation);

            view = Matrix.CreateLookAt(position, position + rotated, Vector3.Transform(Vector3.Up, rotation));
        }

        private void UpdateProjMatrix()
        {
            proj = Matrix.CreatePerspectiveFieldOfView(fov, 
                        ar, 0.01f, 1000f);
        }

        public Vector3 Position
        {
            get { return position; }
            set { position = value; }
        }

        public Vector3 LookAtPoint
        {
            set 
            {
                Vector3 viewDirection = Vector3.Normalize(value - position);
                float lVD = viewDirection.Length();
                Vector3 axis = Vector3.Normalize(Vector3.Cross(firstLook, viewDirection));

                if (!float.IsNaN(axis.X))
                {
                    float angle = (float)Math.Acos(Vector3.Dot(firstLook, viewDirection));
                    Quaternion q = Quaternion.CreateFromAxisAngle(axis, angle);

                    yaw = (float)Math.Atan2(2 * q.Y * q.W - 2 * q.X * q.Z, 1 - 2 * (q.Y * q.Y) - 2 * (q.Z * q.Z));
                    roll = (float)Math.Asin(2 * q.X * q.Y + 2 * q.Z * q.W);
                    pitch = (float)Math.Atan2(2 * q.X * q.W - 2 * q.Y * q.Z, 1 - 2 * (q.X * q.X) - 2 * (q.Z * q.Z));
                }
                else
                {
                    yaw = 0; roll = 0; pitch = 0;
                }
                UpdateViewMatrix();
            }
        }

        public Matrix ViewProjection
        {
            get { UpdateViewMatrix(); return view * proj; }
        }
    }
}