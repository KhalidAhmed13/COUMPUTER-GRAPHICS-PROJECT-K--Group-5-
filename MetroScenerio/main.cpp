#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void Sky()
{
    glBegin(GL_QUADS);
    glColor3f(0.62f, 0.86f, 0.94f);


    glVertex2f(-1,0.2);//F
    glVertex2f(-1,1);//A

    glVertex2f(1,1);//B
    glVertex2f(1,0.2);//H

    glEnd();
    glFlush();
}

void River()
{
    glBegin(GL_QUADS);
    glColor3f(0.07f, 0.69f, 0.77f);


    glVertex2f(-1,-1);//D
    glVertex2f(-1,-0.2473947971585);//K

    glVertex2f(1,-0.315032477823);//R
    glVertex2f(1,-1);//C

    glEnd();
    glFlush();
}

void Bridge()
{
    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.45f, 0.16f);


    glVertex2f(-0.9997394863153,-0.4352753401423);//G
    glVertex2f(-1,0.2);//F

    glVertex2f(1,0.2);//H
    glVertex2f(1,-0.4262208144234);//P

    glEnd();
    glFlush();
}
void Par1()
{
    glBegin(GL_POLYGON);

    glColor3f(0.0f,0.7f,0.0f);


    glVertex2f(-1,-0.6);//E
    glVertex2f(-1,-0.2473947971585);//K

    glVertex2f(-0.5310625515532,-0.460935968825);//M


    glEnd();
    glFlush();
}


void Par2()
{
    glBegin(GL_POLYGON);

    glColor3f(0.0f,0.7f,0.0f);


    glVertex2f(0.8133941285336,-0.4747971150962);//O
    glVertex2f(1,-0.315032477823);//R

    glVertex2f(1,-0.5303478601908);//T


    glEnd();
    glFlush();
}

void Par3()
{
    glBegin(GL_POLYGON);

    glColor3f(0.0f,0.7f,0.0f);


    glVertex2f(0.6,-1);//L
    glVertex2f(1,-0.7047843572814);//N

    glVertex2f(1,-1);//C


    glEnd();
    glFlush();
}


void metroWindow(float x , float y)

{
    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.93f, 0.96f);
    glVertex2f(x,y);//W
    glVertex2f(x+0.1832768690296f , y );//B1                        //B1(x-value)- W(x-value) = 0.1832768690296
    glVertex2f(x+0.1832768690296f , y-0.1167054502341f );//C1      //B1(y-value) - C1(y-value) = 0.1167054502341
    glVertex2f(x,y-0.1167054502341f); //D1

        glEnd();
    glFlush();

}

void FrontWindow1()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0.79f, 0.93f, 0.96f);


    glVertex2f(-0.1869122884657,0.4036567645432);//H1
    glVertex2f(-0.14,0.46);//F1

    glVertex2f(-0.1507996088326,0.4036567645432);//G1



    glEnd();
    glFlush();
}

void FrontWindow2()
{
    glBegin(GL_QUADS);

    glColor3f(0.79f, 0.93f, 0.96f);


    glVertex2f(-0.140677115299,0.4036567645432);//K1
    glVertex2f(-0.1256301654519,0.46);//I1

    glVertex2f(-0.1059323401974,0.46);//J1
    glVertex2f(-0.1059323401974,0.4036567645432);//L1


    glEnd();
    glFlush();
}

void metroDoor(float x1 , float y1)

{
    glBegin(GL_QUADS);
    glColor3f(0.36f, 0.36f, 0.36f);                                 //A1(x1-value)- I(x1-value) = -0.0755576703622
    glVertex2f(x1,y1);//B1
    glVertex2f(x1+0.0755576703622f , y1 );//I                      //A1(y1-value) - D1(y1-value) = 0.1460402195819
    glVertex2f(x1+0.0755576703622f , y1-0.1460402195819 );//A1
    glVertex2f(x1,y1-0.1460402195819); //D1

        glEnd();
         glFlush();


}

void Metroground()
{
    glBegin(GL_POLYGON);

    glColor3f(0.07f, 0.60f, 0.74f);


    glVertex2f(-0.1435947769341,0.2511826525513);//S
    glVertex2f(-0.2547870153902,0.3299438214578);//Q

    glVertex2f(1.6383251756938,0.3299438214578);//A1
    glVertex2f(1.3979884585497,0.2511826525513);//U


    glEnd();
    glFlush();
}

void Metro()
{
    glBegin(GL_POLYGON);

    glColor3f(0.58f, 0.59f, 0.60f);


    glVertex2f(-0.2547870153902,0.3299438214578);//Q
    glVertex2f(-0.0702624041352,0.5459861107718);//V
    glVertex2f(1.402180650994,0.5459861107718);//Z
    glVertex2f(1.6383251756938,0.3299438214578);//A1
        glEnd();
    glFlush();


         FrontWindow1();
         FrontWindow2();


     float x = 0.0413956624331;//W - x value
     float y = 0.4804187657662;//W - y value

    for(int i = 0 ; i < 5 ; i++)
    {

        metroWindow(x,y);

        x += 0.2944989897575f;


    }

     float x1 = -0.0478643816085;//I - x value
     float y1 = 0.4809300509784;//I - y value

    for(int i = 0 ; i < 5 ; i++)
    {

        metroDoor(x1,y1);

        x1 += 0.2907079706502; //I (x-value) + J (x-value) -  = -0.2907079706502


    }






}




void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    Sky();
    River();
    Bridge();
    Par1();
    Par2();
    Par3();
    Metro();
    Metroground();


  glutSwapBuffers();   // IMPORTANT for double buffer
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("Metro Rail");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return EXIT_SUCCESS;
}
