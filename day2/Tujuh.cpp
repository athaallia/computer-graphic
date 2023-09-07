#pragma once

#include <iostream>
#include <cmath>

#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Tujuh
{
public:
    static void Draw()
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(10.0, 90.0, 0.0);
        glVertex3f(10.0, 10.0, 0.0);
        glVertex3f(35.0, 75.0, 0.0);
        glVertex3f(30.0, 20.0, 0.0);
        glVertex3f(90.0, 90.0, 0.0);
        glVertex3f(80.0, 40.0, 0.0);
        glEnd();
    }
};