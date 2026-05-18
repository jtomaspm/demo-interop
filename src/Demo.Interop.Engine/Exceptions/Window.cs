namespace Demo.Interop.Engine.Exceptions;

public class MultipleWindowException : Exception
{
    public override string Message => "only one window instance is allowed, multiple windows are not supported yet";
}

public class GLFWInitException : Exception
{
    public override string Message => "failed to initialise GLFW";
}

public class GLADInitException : Exception
{
    public override string Message => "failed to initialise GLAD";
}

public class UnknownWindowException : Exception
{
    public override string Message => "unknown error initialising window";
}

public class NullWindowException : Exception
{
    public override string Message => "window instance is null, create a window before refencing it";
}
