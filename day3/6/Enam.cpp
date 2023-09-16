#include "Enam.hpp"

// float Enam::R = 20.0;
// float Enam::X = 25.0;
// float Enam::Y = 25.0;
int Enam::numVertices = 90;

void Enam::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    DrawDisc(20.0, 25.0, 75.0);
    DrawDisc(20.0, 75.0, 75.0);
    DrawDisc(20.0, 50.0, 25.0);

    glFlush();
}

void Enam::KeyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case '=':
        numVertices++;
        glutPostRedisplay();
        break;
    case '-':
        if (numVertices > 3)
            numVertices--;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void Enam::DrawDisc(float r, float x, float y)
{
    float t = 0;

    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i)
    {
        glColor3f(0., 0.5, 1.0);
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * M_PI / numVertices;
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i)
    {
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x + r / 2 * cos(t), y + r / 2 * sin(t), 0.0);
        t += 2 * M_PI / numVertices;
    }
    glEnd();
}