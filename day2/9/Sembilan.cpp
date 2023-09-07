#pragma once

#include <iostream>
#include <cmath>

#include "Sembilan.hpp"

void Sembilan::Draw()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glVertex2f(20.0, 20.0);
    glVertex2f(160.0, 20.0);
    glVertex2f(160.0, 120.0);
    glVertex2f(20.0, 120.0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0); // White color
    glVertex2f(40.0, 40.0);
    glVertex2f(80.0, 40.0);
    glVertex2f(80.0, 100.0);
    glVertex2f(40.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0); // White color
    glVertex2f(100.0, 40.0);
    glVertex2f(140.0, 40.0);
    glVertex2f(140.0, 100.0);
    glVertex2f(100.0, 100.0);
    glEnd();
}