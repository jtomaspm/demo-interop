using System.Runtime.InteropServices;

namespace Demo.Interop.Engine;

public static partial class Engine
{
    [LibraryImport("engine", EntryPoint="engine_add")]
    public static partial int Add(int a, int b);
}
