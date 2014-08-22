#pragma once

#include <string>

class LeftClickListener
{
public:
    virtual void processLeftClick(unsigned int xScreen, unsigned int yScreen) =0;
};

class MouseMoveListener
{
public:
    virtual void processMouseMove(unsigned int xScreen, unsigned int yScreen) =0;
};

class WindowClosingListener
{
public:
    virtual void processWindowClosing() =0;
};

class ApplicationWindow
{
public:
    static ApplicationWindow * getInstance() { static ApplicationWindow instance; return &instance; }
    unsigned int getHorizontalPixels() { return horizontalPixels; }
    unsigned int getVerticalPixels() { return verticalPixels; }
    void init(unsigned int horizontalPixels, unsigned int verticalPixels, bool fullScreen, const std::string & title);
    void setWindowClosingListener(WindowClosingListener *);
    void setLeftClickListener(LeftClickListener *);
    void setMouseMoveListener(MouseMoveListener *);
	void setMouseVisible(bool visible);
	unsigned int getTicks() const;
    void processEvents();
    void swapBuffers();

private:
    ApplicationWindow();
    bool fullScreen;
    unsigned int horizontalPixels;
    unsigned int verticalPixels;
    std::string title;
    WindowClosingListener * windowClosingListener;
    LeftClickListener * leftClickListener;
    MouseMoveListener * mouseMoveListener;
};
