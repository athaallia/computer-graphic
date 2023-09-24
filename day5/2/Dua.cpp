#include "Dua.hpp"

void Dua::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();

    // Modeling transformations.
    glTranslatef(0.0, 0.0, -15.0);

    // Nomor 1
    glScalef(2.0, 1.0, 1.0);

    // Nomor 2
    glScalef(1.0, 2.0, 1.0);

    // Nomor 3
    glScalef(1.0, 1.0, 2.0);

    // Teapot
    glutWireTeapot(5.0);

    glFlush();
}

void Dua::Resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}