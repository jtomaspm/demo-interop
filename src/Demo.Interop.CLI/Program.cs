using Demo.Interop.Engine.UI;

using var window = new Window(800, 600);

while (!window.ShouldClose())
{
    window.ProcessInput();
    Renderer.RenderPass();
    window.Refresh();
}