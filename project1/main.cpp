#include <iostream>
#include <cmath>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>

int lastX = 0;
int lastY = 0;
bool leftMouseButtonDown = false;
bool middleMouseButtonDown = false;
bool rightMouseButtonDown = false;

float rotateX = 0.0;
float rotateY = 0.0;
float translateX = 0.0;
float translateY = 0.0;
float translateZ = -5.0; // Move the cube along the z-axis to make it visible

void setupLighting()
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

    glEnable(GL_LIGHT0);                                        // Enable the light source
    glEnable(GL_COLOR_MATERIAL);                                // Enable color tracking for materials
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); // Set material properties to follow glColor
}

void mouse(int button, int state, int x, int y)
{
    lastX = x;
    lastY = y;

    if (button == GLUT_LEFT_BUTTON)
    {
        leftMouseButtonDown = (state == GLUT_DOWN);
    }
    else if (button == GLUT_MIDDLE_BUTTON)
    {
        middleMouseButtonDown = (state == GLUT_DOWN);
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        rightMouseButtonDown = (state == GLUT_DOWN);
    }
}

void motion(int x, int y)
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
    else if (middleMouseButtonDown)
    {
        translateX += deltaX * 0.01;
        translateY -= deltaY * 0.01;
    }
    else if (rightMouseButtonDown)
    {
        translateZ += deltaY * 0.03;
    }

    lastX = x;
    lastY = y;

    glutPostRedisplay();
}

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void DrawCube(float s)
{
    glutSolidCube(s);
}

void DrawCylinder(double r, double h, GLint slices, GLint stacks)
{
    glutSolidCylinder(r, h, slices, stacks);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // Enable lighting and set up light properties
    glEnable(GL_LIGHTING);
    setupLighting();
    // Apply rotations based on mouse movements
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);

    // Draw the back cube
    glPushMatrix();
    glColor3f(0.76f, 0.69f, 0.50f);
    glScalef(1.5f, 2.0f, 0.5f);
    DrawCube(0.5f);
    glPopMatrix();
    glEnd();

    // Draw the middle cube
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.05f);
    glScalef(1.5f, 2.0f, 0.03f);
    DrawCube(0.5f);
    glPopMatrix();
    glEnd();

    // Draw the front cube
    glPushMatrix();
    glColor3f(0.76f, 0.69f, 0.49f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(1.5f, 2.0f, 0.1f);
    DrawCube(0.5f);
    glPopMatrix();
    glEnd();

    // Draw the back and green button
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(-0.2f, 0.35f, 0.12f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.4, 20, 1);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(-0.2f, 0.35f, 0.15f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.5, 20, 1);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(-0.2f, 0.2f, 0.12f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.2, 0.4, 20, 1);
    glPopMatrix();
    glEnd();

    // Draw the back and yellow button
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.35f, 0.12f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.4, 20, 1);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.35f, 0.15f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.5, 20, 1);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.2f, 0.12f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.2, 0.4, 20, 1);
    glPopMatrix();
    glEnd();

    // Draw the back and red button
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.2f, 0.35f, 0.12f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.4, 20, 1);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.2f, 0.35f, 0.15f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.5, 0.5, 20, 1);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.2f, 0.2f, 0.12f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.2, 0.4, 20, 1);
    glPopMatrix();
    glEnd();

    // Draw the key hole
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.25f, 0.0f, 0.12f);
    glScalef(0.1f, 0.1f, 0.1f);
    DrawCylinder(0.3, 0.4, 20, 1);
    glPopMatrix();
    glEnd();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(720, 720);
    glutCreateWindow("Panel Kelistrikan");

    glewInit(); // Initialize GLEW after creating the OpenGL context

    // Enable lighting and material properties
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glutDisplayFunc(Draw);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glEnable(GL_DEPTH_TEST);

    Init();

    glutMainLoop();
    return 0;
}
