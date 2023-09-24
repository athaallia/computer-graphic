#include "Empat.hpp"

void Empat::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();

    // Modeling transformations.
    glTranslatef(0.0, 0.0, -15.0);
    glRotatef(60.0, 0.0, 0.0, 1.0);

    // Teapot
    glutWireTeapot(5.0); 

    glFlush();
}

void Empat::Resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}