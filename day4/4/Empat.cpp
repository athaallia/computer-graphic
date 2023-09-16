#include "Empat.hpp"

void Empat::Draw()
{
    // Dua
    float R = 20.0; // Radius of helix.

    float t; // Angle parameter.

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINE_STRIP);
    for (t = -10 * M_PI; t <= 10 * M_PI; t += M_PI / 20.0)
        glVertex3f(R * cos(t), t, R * sin(t) - 60.0);
    glEnd();

    glFlush();
    // End of Dua
}

void Empat::Resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 120.0);     // a
    // glFrustum(-5.0, 5.0, -5.0, 5.0, 10.0, 100.0);    // b
    glFrustum(-5.0, 5.0, -5.0, 5.0, 2.5, 100.0);     // c
    // glFrustum(-10.0, 10.0, -10.0, 10.0, 5.0, 100.0);    // d
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
};