#include "TriangleSprite.h"
#include "SDL_opengl.h"

void TriangleSprite::drawSprite() const
{
    glEnable(GL_BLEND);
    glColor4f (red, green, blue, alpha);
    glBegin(GL_TRIANGLES);  
    glVertex2f(5, -10);
    glVertex2f(0, 10);
    glVertex2f(-5, -10);
	glEnd();
    glDisable(GL_BLEND);
}
