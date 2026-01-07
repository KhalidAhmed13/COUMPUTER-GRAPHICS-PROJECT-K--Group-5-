#include <GL/glut.h>

void drawRectangle()

{

    glBegin(GL_QUADS);

        glVertex2f(-0.2, -0.1);

        glVertex2f( 0.2, -0.1);

        glVertex2f( 0.2,  0.1);

        glVertex2f(-0.2,  0.1);

    glEnd();
    glFlush();

}

void display()

{

    glClear(GL_COLOR_BUFFER_BIT);



    glPushMatrix();

        glColor3f(1.0, 0.0, 0.0);

        glTranslatef(-0.5, 0.2, 0.0);

         glRotatef(180.0, 0.0, 0.0, 1.0);

        drawRectangle();

    glPopMatrix();



    glPushMatrix();

        glColor3f(0.0, 1.0, 0.0);

        glTranslatef(0.0, 0.6, 0.0);

        glScalef(2.0, 2.0, 1.0);

        drawRectangle();

    glPopMatrix();


    glPushMatrix();

        glColor3f(0.0, 0.0, 1.0);

        glTranslatef(0.1, -0.1, 0.0);

        glRotatef(50.0, 0.0, 0.0, 1.0);

        drawRectangle();

    glPopMatrix();

    glFlush();

}

void init()

{

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);

}

int main(int argc, char** argv)

{

    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);

    glutCreateWindow("Transformations");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}

