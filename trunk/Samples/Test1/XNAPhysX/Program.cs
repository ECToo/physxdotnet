using System;

namespace XNAPhysX
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        static void Main(string[] args)
        {
            using (XNAPhysX game = new XNAPhysX())
            {
                game.Run();
            }
        }
    }
}

