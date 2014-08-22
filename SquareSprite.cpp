#include "SquareSprite.h"
#include "SDL_opengl.h"

void SquareSprite::drawSprite() const
{
    glEnable(GL_BLEND);
    glColor4f (red, green, blue, alpha);
	glBegin(GL_QUADS);  
    glVertex2f(2, 2);
    glVertex2f(2, -2);
    glVertex2f(-2, -2);
    glVertex2f(-2, 2);
	glEnd();
    glDisable(GL_BLEND);
}
