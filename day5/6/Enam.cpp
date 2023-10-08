#include "Enam.hpp"

int Enam::numVertices = 90;

void Enam::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLoadIdentity();

    // Modeling transformations.
    glTranslatef(0.0, 50.0, 0.0);

    glScalef(1.0, 0.3, 1.0);
    DrawCircle(20, 50, 45, 0.18, 0.77, 0.52);
    DrawCircle(20, 50, 50, 0.36, 0.94, 0.55);

    glTranslatef(0.0, -99.0, 0.0);
    glScalef(1.0, 2.0, 1.0);
    DrawRectangle(70, 5, 50, 28, 0.18, 0.77, 0.52);

    // kiri
    glTranslatef(5.0, 6.0, 0.0);
    glRotatef(-10.0, 0.0, 0.0, 1.0);
    DrawRectangle(70, 5, 25, 30, 0.18, 0.77, 0.52);
    glRotatef(10.0, 0.0, 0.0, 1.0);

    // kanan
    glTranslatef(-8.0, -18.0, 0.0);
    glRotatef(10.0, 0.0, 0.0, 1.0);
    DrawRectangle(70, 5, 75, 30, 0.18, 0.77, 0.52);
    glRotatef(-10.0, 0.0, 0.0, 1.0);

    glFlush();
}

void Enam::DrawCircle(float r, float x, float y, float red, float green, float blue)
{
    float t = 0;

    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i)
    {
        glColor3f(red, green, blue);
        glVertex3f(x + r * cos(t), y + r * sin(t), 0.0);
        t += 2 * M_PI / numVertices;
    }
    glEnd();
}

void Enam::DrawRectangle(float p, float l, float x, float y, float red, float green, float blue)
{
    glBegin(GL_POLYGON);
    glColor3f(red, green, blue);
    glVertex3f(x - (l / 2), y - (p / 2), 0.0);
    glVertex3f(x + (l / 2), y - (p / 2), 0.0);
    glVertex3f(x + (l / 2), y + (p / 2), 0.0);
    glVertex3f(x - (l / 2), y + (p / 2), 0.0);
    glEnd();
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
