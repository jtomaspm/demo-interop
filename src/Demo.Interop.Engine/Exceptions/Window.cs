namespace Demo.Interop.Engine.Exceptions;

public class MultipleWindowException : Exception
{
    public override string Message => "only one window instance is allowed";
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