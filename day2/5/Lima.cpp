#include "Lima.hpp"

void Lima::Draw()
{
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(20.0, 20.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(80.0, 20.0, 0.0);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(0.5, 0.5, 0.0);
    glVertex3f(50.0, 21.0, 0.0);
    glEnd();
}