#include <iostream>
#include <cmath>

#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>

// file local
#include "Satu.cpp"
#include "Tiga.cpp"
#include "Lima.cpp"
#include "Tujuh.cpp"
#include "Sembilan.cpp"

void Draw()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set the clear color to black
    glClear(GL_COLOR_BUFFER_BIT);     // Clear the color buffer

    // code berada di sini

    Satu::Draw();
    // Tiga::Draw();
    // Lima::Draw();
    // Tujuh::Draw();
    // Sembilan::Draw();

    glFlush();
}

void Init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set glOrtho(left, right, bottom, top, near, far)
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 200.0, 0.0, 160.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argC, char *argV[])
{
    glutInit(&argC, argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 400);
    glutCreateWindow("Day 2");

    Init();
    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}