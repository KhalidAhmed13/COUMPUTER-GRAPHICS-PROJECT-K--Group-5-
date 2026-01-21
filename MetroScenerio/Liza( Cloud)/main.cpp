#include <math.h>

#define PI 3.141592653589793

void drawCircle(float cx, float cy, float r)
{
    int segments = 100;          // smoothness
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++)
    {
        float angle = 2 * PI * i / segments;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}



   void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    drawCircle(-0.1f, 0.0f, 0.0931772472179f); //w1

    glColor3f(1.0, 1.0, 1.0);
    drawCircle(0.05f, 0.0f, 0.1567941478983f); //z1

    glColor3f(1.0, 1.0, 1.0);
    drawCircle(0.24f, 0.0f, 0.1272743704149f); //a2

    glColor3f(1.0, 1.0, 1.0);
    drawCircle(-0.4f, 0.0f, 0.0917201246409f); //c2

    glColor3f(1.0, 1.0, 1.0);
    drawCircle(-0.5f, 0.0f, 0.06425599519322091f); //b2







    glFlush();
}



void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);    // 2D view