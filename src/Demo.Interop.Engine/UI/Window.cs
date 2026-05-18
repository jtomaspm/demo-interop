using Demo.Interop.Engine.Exceptions;

namespace Demo.Interop.Engine.UI;

#pragma warning disable CA1822 
/* 
    Window methods should not be static
    a valid Window instance must exist
    in the interoped C code.
*/

public class Window : IDisposable
{
    private static Window? _instance;
    public static Window Instance()
        => _instance ?? throw new NullWindowException();

    public Window(int width, int height)
    {
        if (_instance is not null)
            throw new MultipleWindowException();

        switch (Bindings.Window.InitWindow(width, height))
        {
            case 0:
                _instance = this;
                return;
            case -1:
                throw new GLFWInitException();
            case -2:
                throw new GLADInitException();
            default:
                throw new UnknownWindowException();
        }
    }

    public void ProcessInput()
    {
        Bindings.Window.ProcessInput();
    }

    public bool ShouldClose()
        => Bindings.Window.WindowShouldClose() == 1;

    public void Refresh()
    {
        Bindings.Window.RefreshWindow();
    }

    public void Dispose()
    {
        Bindings.Window.TerminateWindow();
        _instance = null;
        GC.SuppressFinalize(this);
    }
}

#pragma warning restore CA1822