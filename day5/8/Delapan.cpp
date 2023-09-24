#include "Delapan.hpp"

void Delapan::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glLoadIdentity();

    // Modeling transformations.
    glTranslatef(0.0, 0.0, -15.0);

    
    glBegin(GL_LINE_LOOP);
    glTranslatef(10.0, 0.0, 0.0);
    glVertex3f(4.0, 0.0, 0.0);
    glVertex3f(0.0, 4.0, 0.0);
    glVertex3f(-4.0, 0.0, 0.0);
    glVertex3f(0.0, -4.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 8.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glEnd();

    glFlush();
}

void Delapan::Resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}