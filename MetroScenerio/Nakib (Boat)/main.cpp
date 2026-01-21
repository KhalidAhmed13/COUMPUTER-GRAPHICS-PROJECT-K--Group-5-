#include <GL/glut.h>
#include <stdbool.h>

float boatx = -0.2f, boaty = -0.2f;
float boatsx = 1.0f, boatsy = 1.0f;
bool flag = true;

void Boat() {
    glPushMatrix();
    glTranslatef(boatx, boaty, 0.0f);
    glRotatef(-10.0f, -0.3f, 0.0f, 1.0f);
    glScalef(boatsx, boatsy, 1.0f);


    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6267f, -0.7880f);
        glVertex2f(-0.0683f, -0.5036f);
        glVertex2f(-0.0718f, -0.5913f);
        glVertex2f(-0.5494f, -0.8337f);
    glEnd();

    glColor3f(0.9f, 0.9f, 0.8f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5452f, -0.2358f);
        glVertex2f(-0.3554f, -0.6364f);
        glVertex2f(-0.0683f, -0.5036f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.5662f, -0.7333f);
        glVertex2f(-0.5156f, -0.3370f);
        glVertex2f(-0.3554f, -0.6364f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.3554f, -0.6364f);
        glVertex2f(-0.5452f, -0.2358f);
    glEnd();

    glPopMatrix();
}


void timer(int value) {
    if (boaty <= -0.03f && flag) {
        boatx += 0.005;
        boaty += 0.005;
        boatsx -= 0.005;
        boatsy -= 0.005;
    }
    else if (boatsx >= 0.0f && boatsy >= 0.0f) {
        boatx -= 0.0023;
        boaty -= 0.0023;
        boatsx -= 0.005;
        boatsy -= 0.005;
        flag = false;
    }

    if (boatsx <= 0.0f && boatsy <= 0.0f) {
        boatsx = 1.0f;
        boatsy = 1.0f;
        boatx = -0.2f;
        boaty = -0.2f;
        flag = true;
    }

    glutPostRedisplay();
    glutTimerFunc(20, timer , 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    Boat();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Boat");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}