using System.Runtime.InteropServices;

namespace Demo.Interop.Engine;

public static partial class Engine
{
    [LibraryImport("engine", EntryPoint="start_engine")]
    public static partial int Start();
}
