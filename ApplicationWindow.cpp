// ApplicationWindow.cpp

// Mac OS X, Linux, and Windows have different syntax for including OpenGL 
// header files; SDL_opengl.h will include these correctly across platforms.
#include "SDL.h"
#include "SDL_opengl.h"
#include "ApplicationWindow.h"

ApplicationWindow::ApplicationWindow() : 
	fullScreen(false), 
	horizontalPixels(640), 
	verticalPixels(480), 
	title(""),
	windowClosingListener(0), 
	leftClickListener(0)
{
}

void ApplicationWindow::init(unsigned int horizontalPixels, unsigned int verticalPixels, bool fullScreen, const std::string & title)
{
    this->fullScreen = fullScreen;
    this->horizontalPixels = horizontalPixels;
    this->verticalPixels = verticalPixels;
    this->title = title;
    atexit(SDL_Quit); 
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult == -1)
    {
        std::string msg = "SDL_Init failed.";
        throw msg;
    }
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_WM_SetCaption(title.c_str(), NULL);
    Uint32 sdlVideoModeFlags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER;
    if (fullScreen)
    {
        sdlVideoModeFlags |= SDL_FULLSCREEN;
    }
    SDL_Surface * screen = SDL_SetVideoMode(
              horizontalPixels,
              verticalPixels,
              32, 
              sdlVideoModeFlags
	);
    if (screen == NULL)
    {
        std::string msg = "SDL_SetVideoMode failed.";
        throw msg;
    }
    // Maybe comment out the following 3 lines when in the linux lab.
    const SDL_VideoInfo * sdlVideoInfo = SDL_GetVideoInfo();
    horizontalPixels = sdlVideoInfo->current_w;
    verticalPixels = sdlVideoInfo->current_h;
    SDL_ShowCursor(SDL_DISABLE);
}

void ApplicationWindow::setMouseVisible(bool visible)
{
	if (visible)
	{
	    SDL_ShowCursor(SDL_ENABLE);
	}
	else
	{
	    SDL_ShowCursor(SDL_DISABLE);
	}
}

unsigned int ApplicationWindow::getTicks() const
{
	return SDL_GetTicks();
}

void ApplicationWindow::processEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) 
        {
			if (windowClosingListener != 0) windowClosingListener->processWindowClosing();
        }
		else if (event.type == SDL_MOUSEMOTION)
        {
			if (mouseMoveListener != 0)
			{
				mouseMoveListener->processMouseMove(event.motion.x, event.motion.y);
			}
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
			if (leftClickListener != 0)
			{
				leftClickListener->processLeftClick(event.button.x, event.button.y);
			}
        }
    }
}

void ApplicationWindow::swapBuffers()
{
    SDL_GL_SwapBuffers();
}

void ApplicationWindow::setWindowClosingListener(WindowClosingListener * windowClosingListener)
{
	this->windowClosingListener = windowClosingListener;
}

void ApplicationWindow::setLeftClickListener(LeftClickListener * leftClickListener)
{
    this->leftClickListener = leftClickListener;
}

void ApplicationWindow::setMouseMoveListener(MouseMoveListener * mouseMoveListener)
{
    this->mouseMoveListener = mouseMoveListener;
}
