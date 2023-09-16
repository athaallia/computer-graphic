#pragma once

#define _USE_MATH_DEFINES

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

class Dua
{
public:
    static void Draw();
    static void Resize(int w, int h);
};