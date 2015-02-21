// Author: Jordan Reed

#include <iostream>
using namespace std;

#include "Graphics.h"
#include "Renderer.h"

#define INITIAL_WINDOW_WIDTH  960
#define INITIAL_WINDOW_HEIGHT 640

// http://www.opengl.org/wiki/Tutorial1:_Creating_a_Cross_Platform_OpenGL_3.2_Context_in_SDL_%28C_/_SDL%29
void sdldie(const char *msg)
{
    printf("%s: %s\n", msg, SDL_GetError());
    SDL_Quit();
    exit(1);
}
void checkSDLError(int line)
{
#ifndef NDEBUG
    const char *error = SDL_GetError();
    if (*error != '\0')
    {
        cout << "SDL Error: " << error << endl;
        if (line != -1) cout << " + line: " << line << endl;
        SDL_ClearError();
    }
#endif
}

SDL_Window* initGraphics(SDL_GLContext &context)
{
    SDL_Window *window = NULL;
    
    // Initialize SDL's Video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0) sdldie("Unable to initialize SDL");
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  32);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,     8); //only needed for systems other than mac osx
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,   8); //only needed for systems other than mac osx
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,    8); //only needed for systems other than mac osx
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,   8); //only needed for systems other than mac osx
    
    // Create the window
    window = SDL_CreateWindow("OpenGL Example",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN |
                              SDL_WINDOW_RESIZABLE); // | SDL_WINDOW_MAXIMIZED);
    
    if (!window) sdldie("Unable to create window");
    checkSDLError(__LINE__);
    context = SDL_GL_CreateContext(window);
    checkSDLError(__LINE__);
    
    // Syncronize with monitor's vertical refresh rate
    SDL_GL_SetSwapInterval(1);
    
    // Display OpenGL information
    cout << "OPENGL:  " << glGetString(GL_VERSION) << endl;
    cout << "GLSL:    " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    
    return window;
}

void cleanupGraphics(SDL_Window *window, SDL_GLContext &context)
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    SDL_GLContext maincontext;
    SDL_Window *mainwindow = initGraphics(maincontext);
    
    float screenWidth  = INITIAL_WINDOW_WIDTH;
    float screenHeight = INITIAL_WINDOW_HEIGHT;

    Renderer renderer;
    renderer.init(screenWidth, screenHeight);

    bool continueLoop = true;
    while (continueLoop)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                {
                    int key = event.key.keysym.scancode;
                    break;
                }
                case SDL_KEYUP:
                {
                    int key = event.key.keysym.scancode;
                    break;
                }
                case SDL_MOUSEMOTION:
                {
                    float x = event.motion.x;
                    float y = screenHeight - event.motion.y;
                    break;
                }
                case SDL_WINDOWEVENT:
                {
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                    {
                        screenWidth  = event.window.data1;
                        screenHeight = event.window.data2;
                        renderer.reshape(screenWidth, screenHeight);
                    }
                    break;
                }
                case SDL_QUIT:
                {
                    continueLoop = false;
                    break;
                }
                default: break;
            }
        }
        
        // Update state
        renderer.update();
        
        // Draw state
        renderer.draw();
        
        // Flush it all to the screen
        SDL_GL_SwapWindow(mainwindow);
    }
    
    cleanupGraphics(mainwindow, maincontext);
    return 0;
}