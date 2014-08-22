#ifndef GRAPHICS_SYSTEM_2D_H
#define GRAPHICS_SYSTEM_2D_H

#include <set>
#include "ApplicationWindow.h"

class Drawable;
class ApplicationWindow;
class WindowClosingListener;

class GraphicsSystem2D
{
public:
    static GraphicsSystem2D * getInstance() { static GraphicsSystem2D instance; return &instance; }
    void init();
    void draw() const;
    void addDrawable(Drawable * drawable);
    void removeDrawable(Drawable * drawable);
	void removeAllDrawables() { drawables.clear(); }

    float xScreenToWorld(unsigned int xScreen)
    { 
		return static_cast<float>(xScreen - halfScreenWidth);
    }

    float yScreenToWorld(unsigned int yScreen) 
    { 
		return static_cast<float>(halfScreenHeight - yScreen);
    }

	float getMinVisibleX() { return minVisibleX; }
	float getMinVisibleY() { return minVisibleY; }
	float getMaxVisibleX() { return maxVisibleX; }
	float getMaxVisibleY() { return maxVisibleY; }

private:
    GraphicsSystem2D();
    ApplicationWindow * applicationWindow;
    float aspectRatio;
    std::set<Drawable *> drawables;
    int horizontalPixels;
    int verticalPixels;
	float halfScreenWidth;
	float halfScreenHeight;
	float minVisibleX;
	float minVisibleY;
	float maxVisibleX;
	float maxVisibleY;
};

#endif
