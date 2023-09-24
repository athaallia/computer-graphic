// file local
#include "2/Dua.hpp"
#include "4/Empat.hpp"
#include "6/Enam.hpp"

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void Resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void KeyInput(unsigned char key, int x, int y)
{
    // Empat::KeyInput(key, x, y);
    // Enam::KeyInput(key, x, y);
}

void Draw()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set the clear color to black
    glClear(GL_COLOR_BUFFER_BIT);     // Clear the color buffe`r

    // Dua::Draw();
    Empat::Draw();
    // Enam::Draw();

    glFlush();
}

int main(int argC, char *argV[])
{
    glutInit(&argC, argV);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Day 3");

    glutDisplayFunc(Draw);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(KeyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    Init();

    glutMainLoop();
    return 0;
}