#include "2/Dua.hpp"
#include "4/Empat.hpp"
#include "6/Enam.hpp"
#include "8/Delapan.hpp"

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void Draw()
{
    // Dua::Draw();
    // Empat::Draw();
    Enam::Draw();
    // Delapan::Draw();
}

void Resize(int w, int h)
{
    // Dua::Resize(w, h);
    // Empat::Resize(w, h);
    Enam::Resize(w, h);
    // Delapan::Resize(w, h);
}

void KeyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Day 5");
    glutDisplayFunc(Draw);
    glutReshapeFunc(Resize);
    glutKeyboardFunc(KeyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    Init();

    glutMainLoop();
}
