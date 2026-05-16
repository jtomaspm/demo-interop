using Demo.Interop.Bindings;

if(Engine.InitWindow() is int iwRCode && iwRCode != 0)
{
    Console.WriteLine($"Engine failed to init window: {iwRCode}");
    return iwRCode;
}

while (Engine.WindowShouldClose() == 0)
{
    Engine.RenderPass();
}

Engine.TerminateWindow();
return 0;