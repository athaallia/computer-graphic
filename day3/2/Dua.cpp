#include "Dua.hpp"

void Dua::Draw()
{
    glBegin(GL_LINE_STRIP);

    int numPoints = 100;
    for (int i = 0; i <= numPoints; i++)
    {
        float t = -1.0f + 2.0f * i / numPoints;
        float x = 50.0f + 50.0f * t;
        float y = 100.0f * t * t;
        float z = 0;
        glVertex3f(x, y, z);
    }

    glEnd();
};