#pragma once

#include <iostream>
#include <cmath>

#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Satu
{
public:
    static void Draw()
    {
        // Set color (R= , G= , B= )
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(20.0, 20.0, 0.0);
        glVertex3f(80.0, 20.0, 0.0);
        glVertex3f(80.0, 80.0, 0.0);
        glVertex3f(20.0, 80.0, 0.0);
        glEnd();
    }
};