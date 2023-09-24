#pragma once

#define M_PI 3.14159265358979323846

#include <iostream>
#include <cmath>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>

class Enam
{
public:
    static float R;         // Radius of circle.
    static float X;         // X-coordinate of center of circle.
    static float Y;         // Y-coordinate of center of circle.
    static int numVertices; // Number of vertices on circle.

    static void Draw();
    static void Resize(int w, int h);
    static void DrawCircle(float r, float x, float y, float red, float green, float blue);
    static void DrawRectangle(float p, float l, float x, float y, float red, float green, float blue);
};
