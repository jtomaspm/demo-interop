using System.Runtime.InteropServices;

namespace Demo.Interop.Engine.Bindings;

internal static partial class Window
{
    [LibraryImport("engine", EntryPoint="engine_InitWindow")]
    internal static partial int InitWindow(int width, int height);

    [LibraryImport("engine", EntryPoint="engine_WindowShouldClose")]
    internal static partial int WindowShouldClose();

    [LibraryImport("engine", EntryPoint="engine_RefreshWindow")]
    internal static partial void RefreshWindow();

    [LibraryImport("engine", EntryPoint="engine_ProcessInput")]
    internal static partial void ProcessInput();

    [LibraryImport("engine", EntryPoint="engine_TerminateWindow")]
    internal static partial void TerminateWindow();
}
