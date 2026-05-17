using Demo.Interop.Engine.Exceptions;

namespace Demo.Interop.Engine.UI;

public class Window : IDisposable
{
    private static Window? _instance;

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
    {
        return Bindings.Window.WindowShouldClose() == 1;
    }

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