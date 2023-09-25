#include "Application.h"





int main(int argc,char** argv)
{
    
    Application app;
    app.InitWindow();
    app.InitGLEW();
    app.InitImGui();
    app.Run();
    
    return 0;
}