#pragma once

#include <iostream>
#include <cmath>

#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Tiga
{
public:
    static void Draw()
    {
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(20.0, 20.0, 0.0);
        glVertex3f(80.0, 20.0, 0.0);
        glVertex3f(80.0, 80.0, 0.0);
        glVertex3f(20.0, 80.0, 0.0);
        glEnd();

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(40.0, 40.0, 0.0);
        glVertex3f(60.0, 40.0, 0.0);
        glVertex3f(60.0, 60.0, 0.0);
        glVertex3f(40.0, 60.0, 0.0);
        glEnd();
    }
};