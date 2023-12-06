#include <iostream>
#include <cmath>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "getBMP.h"

// Globals.
static unsigned int texture[2]; // Array of texture ids. // Storage for chessboard image.
static int id = 0;              // Currently displayed texture id.

bool lampOn = true; 
bool isLightOn = true;

static int isAnimate = 0;      
static int animationPeriod = 200; // Time interval between frames.

// Load external textures.
void LoadTextures()
{
    // Local storage for image data.
    imageFile *image[1];

    // Load the image.
    image[0] = getBMP("images/isiDalam.bmp");

    // Create texture object texture[0].
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->width, image[0]->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);

    // Set texture parameters for wrapping.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set texture parameters for filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

int lastX = 0;
int lastY = 0;
bool leftMouseButtonDown = false;
bool rightMouseButtonDown = false;
bool middleMouseButtonDown = false;

float rotateX = 0.0f;
float rotateY = 0.0f;

float cubeX = 0.0f;
float cubeY = 0.0f;
float cubeZ = 0.1f;

bool isOpen = false;
bool isClose = false;

GLfloat angle = 0;

float Color = 1.0f;

void AnimateOpen(int value)
{
    if (isAnimate)
    {
        angle -= 30;
        if (angle <= -120)
        {
            angle = -120;
            cubeX = -0.55f;
            cubeZ = 0.32f;
            glutPostRedisplay();
            isAnimate = 0;
            isOpen = true;
            isClose = false;
            return; 
        }
        cubeX -= 0.1375f;
        cubeZ += 0.08f;
        glutPostRedisplay();
        glutTimerFunc(animationPeriod, AnimateOpen, 1);
    }
}

void AnimateClose(int value)
{
    if (isAnimate)
    {
        angle = 0;
        if (angle >= 0)
        {
            angle = 0;
            cubeX = 0.0f;
            cubeZ = 0.1f;
            glutPostRedisplay();
            isAnimate = 0;
            isClose = true;
            isOpen = false;
            return;
        }
        cubeX += 0.13f;
        cubeZ -= 0.15f;
        glutPostRedisplay();
        glutTimerFunc(animationPeriod, AnimateClose, 1);
    }
}

void AnimateColor(int value)
{
    if (isAnimate)
    {
        Color += 0.2f;
        if (Color >= 2.0f)
            Color -= 1.0f;
        glutPostRedisplay();
        glutTimerFunc(animationPeriod, AnimateColor, 2);
    }
}

void SetupLighting()
{
    GLfloat lightPosition[] = {1.0f, 1.0f, 1.0f, 0.0f}; // Light position (directional light from top-right)
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};  // Ambient light color (gray)
    GLfloat diffuseColor[] = {1.0f, 1.0f, 1.0f, 1.0f};  // Diffuse light color (white)
    GLfloat specularColor[] = {1.0f, 1.0f, 1.0f, 1.0f}; // Specular light color (white)

    // Set light properties
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularColor);

    if (isLightOn == true)
    {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
    }
    else if (isLightOn == false)
    {
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_COLOR_MATERIAL);
    }
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void Mouse(int button, int state, int x, int y)
{
    lastX = x;
    lastY = y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        leftMouseButtonDown = true;
        rightMouseButtonDown = false;
        middleMouseButtonDown = false;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        leftMouseButtonDown = false;
        rightMouseButtonDown = true;
        middleMouseButtonDown = false;
    }
    else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
        leftMouseButtonDown = false;
        rightMouseButtonDown = false;
        middleMouseButtonDown = true;
    }
    else
    {
        leftMouseButtonDown = false;
        rightMouseButtonDown = false;
        middleMouseButtonDown = false;
    }
}

void Motion(int x, int y)
{
    int deltaX = x - lastX;
    int deltaY = y - lastY;

    if (leftMouseButtonDown)
    {
        rotateX += deltaY * 0.5;
        rotateY += deltaX * 0.5;

        if (rotateX > 360.0)
            rotateX = 360.0;
        if (rotateX < -360.0)
            rotateX = -360.0;
    }

    lastX = x;
    lastY = y;

    glutPostRedisplay();
}

void ToggleLamp()
{
    lampOn = !lampOn;

    if (lampOn)
        glEnable(GL_LIGHT0);
    else
        glDisable(GL_LIGHT0);

    glutPostRedisplay();
}

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // Create texture ids.
    glGenTextures(2, texture);

    // Load external texture.
    LoadTextures();

    // Specify how texture values combine with current surface color values.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void DrawCube(float s)
{
    glutSolidCube(s);
}

void DrawCylinder(double r, double h, GLint slices, GLint stacks)
{
    glutSolidCylinder(r, h, slices, stacks);
}

void DrawFrontSide()
{
    // Draw the front cube
    glPushMatrix();
    glColor3f(0.76f, 0.69f, 0.49f); // coklat
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(1.5f, 2.0f, 0.1f);
    DrawCube(0.5f);
    glPopMatrix();

    // Draw the back and green button
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // item back
    glTranslatef(-0.2f, 0.35f, 0.03f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.4, 20, 1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, Color, 0.0f); // ijo
    glTranslatef(-0.2f, 0.35f, 0.05f);
    glScalef(0.1f, 0.1f, 0.05f);
    DrawCylinder(0.5, 0.5, 20, 1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // item buletan bawah
    glTranslatef(-0.2f, 0.2f, 0.03f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.2, 0.4, 20, 1);
    glPopMatrix();

    // Draw the back and yellow button
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // item back
    glTranslatef(0.0f, 0.35f, 0.03f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.4, 20, 1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(Color, Color, 0.0f); // kuning
    glTranslatef(0.0f, 0.35f, 0.05f);
    glScalef(0.1f, 0.1f, 0.05f);
    DrawCylinder(0.5, 0.5, 20, 1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // item buletan bawah
    glTranslatef(0.0f, 0.2f, 0.03f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.2, 0.4, 20, 1);
    glPopMatrix();

    // Draw the back and red button
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // item back
    glTranslatef(0.2f, 0.35f, 0.03f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.4, 20, 1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(Color, 0.0f, 0.0f); // merah
    glTranslatef(0.2f, 0.35f, 0.07f);
    glScalef(0.1f, 0.1f, 0.05f);
    DrawCylinder(0.5, 0.5, 20, 1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // item buletan bawah
    glTranslatef(0.2f, 0.2f, 0.03f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.2, 0.4, 20, 1);
    glPopMatrix();

    // Draw the key hole
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // item
    glTranslatef(0.25f, 0.0f, 0.03f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.3, 0.4, 20, 1);
    glPopMatrix();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Enable lighting and set up light properties
    SetupLighting();
    // glEnable(GL_LIGHTING);

    // Apply rotations based on mouse movements
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);

    // Activate texture object.
    glBindTexture(GL_TEXTURE_2D, texture[id]);

    // Turn on OpenGL texturing.
    glEnable(GL_TEXTURE_2D);

    // Map the texture onto a square polygon.
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.34, -0.45, 0.1);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.34, -0.45, 0.1);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.34, 0.45, 0.1);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.34, 0.45, 0.1);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    // Draw the back cube
    glPushMatrix();
    glColor3f(0.76f, 0.69f, 0.50f); // coklat
    glScalef(1.5f, 2.0f, 0.3f);
    DrawCube(0.5f);
    glPopMatrix();

    // Panel listrik opened
    glPushMatrix();
    glTranslatef(cubeX, cubeY, cubeZ);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    DrawFrontSide();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        if (isAnimate)
            isAnimate = 0;
        else
        {
            isAnimate = 1;
            AnimateOpen(1);
        }
        break;
        glutPostRedisplay();
        break;
    case 'a':
        if (isAnimate)
            isAnimate = 0;
        else
        {
            isAnimate = 1;
            AnimateClose(1);
        }
        break;
        glutPostRedisplay();
        break;
    case 'w':
        // animasi warna
        if (isAnimate)
            isAnimate = 0;
        else
        {
            isAnimate = 2;
            AnimateColor(2);
        }
        glutPostRedisplay();
        break;
    case 't':
        isLightOn = false;
        glutPostRedisplay();
        break;
    case 'y':
        isLightOn = true;
        glutPostRedisplay();
        break;
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(720, 720);
    glutCreateWindow("Panel Kelistrikan");

    // Initialize GLEW after creating the OpenGL context
    glewInit();

    glutDisplayFunc(Draw);
    glutMouseFunc(Mouse);
    glutMotionFunc(Motion);
    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(keyInput);

    Init();

    glutMainLoop();
    return 0;
}