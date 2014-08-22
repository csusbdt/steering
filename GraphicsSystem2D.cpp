// GraphicsSystem2D.cpp

#include "ApplicationWindow.h"
#include "GraphicsSystem2D.h"
#include "Drawable.h"
//#include "SDL.h"
#include "SDL_opengl.h"

GraphicsSystem2D::GraphicsSystem2D() 
: horizontalPixels(-1), verticalPixels(-1), applicationWindow(0)
{
}

void GraphicsSystem2D::init()
{
    applicationWindow = ApplicationWindow::getInstance();
    horizontalPixels = applicationWindow->getHorizontalPixels();
    verticalPixels = applicationWindow->getVerticalPixels();
    aspectRatio = horizontalPixels / static_cast<float>(verticalPixels);
    minVisibleX = static_cast<float>(-horizontalPixels / 2.0);
    maxVisibleX = static_cast<float>(horizontalPixels / 2.0);
    minVisibleY = static_cast<float>(-verticalPixels / 2.0);
    maxVisibleY = static_cast<float>(verticalPixels / 2.0);
    float minVisibleZ = -1;
    float maxVisibleZ = 1;
    glViewport(0, 0, horizontalPixels, verticalPixels);
    glMatrixMode(GL_PROJECTION);
    glOrtho(minVisibleX, maxVisibleX, minVisibleY, maxVisibleY, minVisibleZ, maxVisibleZ);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 0);
	halfScreenWidth = horizontalPixels / 2.0f;
	halfScreenHeight = verticalPixels / 2.0f;
}

void GraphicsSystem2D::addDrawable(Drawable * drawable)
{
    drawables.insert(drawable);
}

void GraphicsSystem2D::removeDrawable(Drawable * drawable)
{
    drawables.erase(drawable);
}

void GraphicsSystem2D::draw() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    std::set<Drawable *>::const_iterator it = drawables.begin();
    std::set<Drawable *>::const_iterator end = drawables.end();
    while (it != end)
    {
        (*it)->draw();
        ++it;
    }
    applicationWindow->swapBuffers();
}
