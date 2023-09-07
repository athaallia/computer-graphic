#pragma once

#define M_PI 3.14159265358979323846

#include <iostream>
#include <cmath>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>

class Empat
{
public:
    static float R;         // Radius of circle.
    static float X;         // X-coordinate of center of circle.
    static float Y;         // Y-coordinate of center of circle.
    static int numVertices; // Number of vertices on circle.

    static void Draw();

    static void KeyInput(unsigned char key, int x, int y);

    static void DrawDisc(float r, float x, float y);
};