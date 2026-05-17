using System.Runtime.InteropServices;

namespace Demo.Interop.Bindings;

public static partial class Engine
{
    [LibraryImport("engine", EntryPoint="engine_InitWindow")]
    public static partial int InitWindow();

    [LibraryImport("engine", EntryPoint="engine_WindowShouldClose")]
    public static partial int WindowShouldClose();

    [LibraryImport("engine", EntryPoint="engine_RenderPass")]
    public static partial void RenderPass();

    [LibraryImport("engine", EntryPoint="engine_RefreshWindow")]
    public static partial void RefreshWindow();

    [LibraryImport("engine", EntryPoint="engine_ProcessInput")]
    public static partial void ProcessInput();

    [LibraryImport("engine", EntryPoint="engine_TerminateWindow")]
    public static partial void TerminateWindow();
}
