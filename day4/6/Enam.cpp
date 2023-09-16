#include "Enam.hpp"

int Enam::numVertices = 90;

void Enam::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    DrawCircle(20.0, 50.0, 50.0);
    DrawCircleCover(20.0, 60.0, 50.0);

    glFlush();
}

void Enam::DrawCircle(float r, float x, float y)
{
    float t = 0;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < numVertices; ++i)
    {
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * M_PI / numVertices;
    }
    glEnd();
}

void Enam::DrawCircleCover(float r, float x, float y)
{
    float t = 0;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < numVertices; ++i)
    {
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * M_PI / numVertices;
    }
    glEnd();
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


void Enam::Resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}