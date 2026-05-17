using System.Runtime.InteropServices;

namespace Demo.Interop.Engine.Bindings;

internal static partial class Renderer
{
    [LibraryImport("engine", EntryPoint="engine_RenderPass")]
    internal static partial void RenderPass();
}
