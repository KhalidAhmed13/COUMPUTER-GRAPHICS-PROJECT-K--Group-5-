#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define PI 3.141592653589793


using namespace std;
float trainleft;
float trainright;
float sunY;
float t  = 0.0f;
float R;
float G;
float B;
float RR;
float RG;
float RB;
bool above = false;
bool below = true;
float cloudx;

float boatx = -0.2f;
float boaty = -0.2f;
float boatsx = 1.0f;
float boatsy = 1.0f;
bool flag = true;
float color;

void plotCirclePoints(float xc, float yc, float x, float y)
{
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc - x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc + y, yc + x);
    glVertex2f(xc - y, yc + x);
    glVertex2f(xc + y, yc - x);
    glVertex2f(xc - y, yc - x);
}

void Sun(float xc, float yc, float r)
{
     glColor3f(0.85f, 0.71f, 0.11f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc);   // center

    for (float angle = 0; angle <= 360; angle += 1)
    {
        float rad = angle * 3.1416f / 180.0f;
        glVertex2f(xc + cos(rad) * r, yc + sin(rad) * r);
    }

    glEnd();
}



void Sky()
{
    glBegin(GL_QUADS);
    glColor3f(R,G,B);


    glVertex2f(-0.9971888839077,-0.2473947971585);//K
    glVertex2f(-1,1);//A

    glVertex2f(1,1);//B
    glVertex2f(0.9878445002373,-0.315032477823);//R

    glEnd();
    glFlush();
}



void drawCircle(float cx, float cy, float r)
{
    int segments = 100;   // smoothness
    glBegin(GL_POLYGON);

    for (int i = 0; i < segments; i++)
    {
        float angle = 2.0f * PI * i / segments;
        float x = r * cos(angle);
        float y = r * sin(angle);

        glVertex2f(cx + x, cy + y);
    }

    glEnd();
}


void River()
{
    glBegin(GL_QUADS);
    glColor3f(RR,RG,RB);


    glVertex2f(-1,-1);//D
    glVertex2f(-1,-0.2473947971585);//K

    glVertex2f(1,-0.315032477823);//R
    glVertex2f(1,-1);//C

    glEnd();
    glFlush();
}
void Boat()
{
glPushMatrix();

// Move boat to rotation center
glTranslatef(boatx,boaty , 0.0f);

// Rotate diagonally (negative = clockwise)
glRotatef(-10.0f, -0.3f, 0.0f, 1.0f);

glScalef(boatsx ,boatsy ,0.0f);

// =====================
// Boat Body (Brown)
// =====================
glColor3f(0.55f, 0.27f, 0.07f);
glBegin(GL_POLYGON);
    glVertex2f(-0.6267f, -0.7880f);
    glVertex2f(-0.0683f, -0.5036f);
    glVertex2f(-0.0718f, -0.5913f);
    glVertex2f(-0.5494f, -0.8337f);
glEnd();

// =====================
// Long Sail (Right)
// =====================
glColor3f(0.9f, 0.9f, 0.8f);
glBegin(GL_POLYGON);
    glVertex2f(-0.5452f, -0.2358f);
    glVertex2f(-0.3554f, -0.6364f);
    glVertex2f(-0.0683f, -0.5036f);
glEnd();

// =====================
// Short Sail (Left)
// =====================
glBegin(GL_POLYGON);
    glVertex2f(-0.5662f, -0.7333f);
    glVertex2f(-0.5156f, -0.3370f);
    glVertex2f(-0.3554f, -0.6364f);
glEnd();

// =====================
// Black Line Between Sails
// =====================
glColor3f(0.0f, 0.0f, 0.0f);
glLineWidth(2.0f);
glBegin(GL_LINES);
    glVertex2f(-0.3554f, -0.6364f);
    glVertex2f(-0.5452f, -0.2358f);
glEnd();

glPopMatrix();
glFlush();

}



void Bridge()
{
    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.45f, 0.16f);


    glVertex2f(-0.9997394863153,-0.4262208144234);//G
    glVertex2f(-1,0.2);//F

    glVertex2f(1,0.2);//H
    glVertex2f(1,-0.4262208144234);//P

    glEnd();
    glFlush();
}
void BridgePillerLine()
{
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1,0.3152721986892);//W1
    glVertex2f(1,0.3152721986892);//z1
    glEnd();
    glFlush();


}

void BridgeSmallPiller(float x5 , float y5)

{
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(x5, y5 );//A2
    glVertex2f(x5,y5+0.072319898118); //A2 (y value) - B2(y value)= 0.072319898118

         glEnd();
         glFlush();


}


void BridgeLargePiller(float x6 , float y6)

{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(x6,y6);//D2
    glVertex2f(x6+0.0203022955381f , y6 );//E2                        //E2(x-value)- D2(x-value) = 0.0203022955381
    glVertex2f(x6+0.0203022955381f , y6-0.0838964834766f );//F2      //E2(y-value) - F2(y-value) = 0.0838964834766
    glVertex2f(x6,y6-0.0838964834766f); //G2

        glEnd();
    glFlush();

}


void BridgeUpperpart()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);


    glVertex2f(-1,0.2);//F
    glVertex2f(-1,0.2429523005712);//U1

    glVertex2f(1,0.2429523005712);//V1
    glVertex2f(1,0.2);//H

    glEnd();

    //for bridge small piller

    float x5 = -0.9431364567251;//A2 - x value
     float y5 = 0.2429523005712;//B2 - y value

    for(int i = 0 ; i < 50 ; i++)
    {

        BridgeSmallPiller(x5,y5);

        x5 += 0.0399230401513f;


    }

    glEnd();

    //for bridge large piller

    float x6 = -0.8916364635461;//D2 - x value = -0.8916364635461
     float y6 = 0.3268487840478;//D2 - y value

    for(int i = 0 ; i < 8 ; i++)
    {

        BridgeLargePiller(x6,y6);

        x6 += 0.2543002451811f; //M2 (x value) - I2 (X value) = 0.2543002451811
    }

    glEnd();



    glFlush();
}


void bridgeHalfCircle(float cx, float cy, float r)  //r = S1 (x-value)- R1 (X-value) = 0.5508333101402
{
    glBegin(GL_POLYGON);


    for (int i = 0; i <= 180; i++)
    {
        float angle = i * 3.1416f / 180;
        float x5 = cx + r * cos(angle);
        float y5 = cy + r * sin(angle);
        glVertex2f(x5, y5);
    }
    glEnd();
}





void Par1()
{
    glBegin(GL_POLYGON);

    glColor3f(0.0f,0.5f,0.0f);


    glVertex2f(-1,-0.6);//E
    glVertex2f(-1,-0.2473947971585);//K

    glVertex2f(-0.5310625515532,-0.460935968825);//M


    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.89f, 0.82f, 0.38f);


    glVertex2f(-1,-0.6);//E
    glVertex2f(-1,-0.5283384912614);//N2

    glVertex2f(-0.5310625515532,-0.460935968825);//M

    glEnd();
    glFlush();
}


void Par2()
{
    glBegin(GL_POLYGON);

    glColor3f(0.0f,0.5f,0.0f);


    glVertex2f(0.8133941285336,-0.4747971150962);//O
    glVertex2f(1,-0.315032477823);//R

    glVertex2f(1,-0.5303478601908);//T


    glEnd();


    glBegin(GL_TRIANGLES);

    glColor3f(0.89f, 0.82f, 0.38f);


    glVertex2f(0.8133941285336,-0.4747971150962);//O
    glVertex2f(1,-0.5);//O2

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

//back side window

void FrontWindow3()
{
    glBegin(GL_QUADS);

    glColor3f(0.79f, 0.93f, 0.96f);


    glVertex2f(1.4589577986064,0.4036567645432);//W2
    glVertex2f(1.4589577986064,0.46);//U2

    glVertex2f(1.48,0.46);//V2
    glVertex2f(1.4853923285426,0.4036567645432);//Z2



    glEnd();
    glFlush();
}


void FrontWindow4()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0.79f, 0.93f, 0.96f);


    glVertex2f(1.4997897064542,0.4036567645432);//S2
    glVertex2f(1.4882041803231,0.46);//R2

    glVertex2f(1.5507705856168,0.4036567645432);//T2



    glEnd();
    glFlush();
}

void metroDoor(float x1 , float y1)

{    // for large squre door
    glBegin(GL_QUADS);
    glColor3f(0.36f, 0.36f, 0.36f);                                 //A1(x-value)- I(x-value) = -0.0755576703622
    glVertex2f(x1,y1);//I
    glVertex2f(x1+0.0755576703622f , y1 );//A1                     //A1(y-value) - D1(y-value) = 0.1460402195819
    glVertex2f(x1+0.0755576703622f , y1-0.1460402195819f );//D1
    glVertex2f(x1,y1-0.1460402195819f); //B1

        glEnd();


    //  door line

         glBegin(GL_LINES);
         glColor3f(1.0f, 0.0f, 0.0f);
           glVertex2f(x1+0.0397434232971f , y1 );//C1
           glVertex2f(x1+0.0397434232971f , y1-0.1475011107239f );//E1

         glEnd();


}


      // right door glass


void metroDoorglass1(float x2 , float y2)

{
    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.93f, 0.96f);                                  //G1(x-value)- F1(x-value) = 0.0195946148387
    glVertex2f(x2,y2);//F1
    glVertex2f(x2+0.0195946148387f , y2 );//G1                      //G1(y-value) - I1(y-value) = 0.0776629462188
    glVertex2f(x2+0.0195946148387f , y2-0.0776629462188f );//H1
    glVertex2f(x2,y2-0.0776629462188f); //I1

        glEnd();

}
//left door glass

void metroDoorglass2(float x3 , float y3)

{
    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.93f, 0.96f);                                  //L1(x-value)- K1(x-value) = 0.02
    glVertex2f(x3,y3);//K1
    glVertex2f(x3+0.02f , y3 );//L1                      //L1(y-value) - M1(y-value) = 0.0793419561894
    glVertex2f(x3+0.02f , y3-0.0793419561894f );//M1
    glVertex2f(x3,y3-0.0793419561894); //N1

        glEnd();

}


void Metroground()
{
    glBegin(GL_POLYGON);

    glColor3f(0.08f, 0.61f, 0.74f);


    glVertex2f(-0.1435947769341,0.2511826525513);//S
    glVertex2f(-0.2547870153902,0.3299438214578);//Q

    glVertex2f(1.6383251756938,0.3299438214578);//A1
    glVertex2f(1.3979884585497,0.2511826525513);//U


    glEnd();
    glFlush();
}

void MetroUp()
{
    glBegin(GL_POLYGON);

    glColor3f(0.02f, 0.33f, 0.18f);


    glVertex2f(-0.2547870153902,0.3299438214578);//Q
    glVertex2f(-0.0702624041352,0.5459861107718);//V
    glVertex2f(1.402180650994,0.5459861107718);//Z
    glVertex2f(1.6383251756938,0.3299438214578);//A1
        glEnd();
    glFlush();


         FrontWindow1();
         FrontWindow2();
         FrontWindow3();
         FrontWindow4();



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

        x1 += 0.2927079706502; //I (x-value) + J (x-value)  = 0.2927079706502


    }


    float x2 = -0.0366571055259;//F1 - x value
     float y2 = 0.4558842819022;//F1 - y value


    for(int i = 0 ; i < 5 ; i++)
    {

        metroDoorglass1(x2,y2);

        x2 += 0.292707970650; //I (x-value) + J (x-value)  = 0.2927079706502


    }


    float x3 = 0;//K1 - x value
     float y3 = 0.4558842819022;//K1 - y value


    for(int i = 0 ; i < 5 ; i++)
    {

        metroDoorglass2(x3,y3);

        x3 += 0.292707970650; //I (x-value) + J (x-value)  = 0.2927079706502


    }








}

void update(int value)
{
    trainleft -= 0.018f;// move left
    trainright += 0.018f;

    if(above == false && below == true )
    {

        sunY += 0.0005f;


    }
    else if (above == true && below == false)
    {
        sunY -= 0.0005f;


    }





    if (trainleft <= -3.0f){


        trainleft= 1.5f;




}
       if (trainright >= 7.0f){


        trainright= -7.5f;




}


    if(sunY >= 0.75f && above == false && below == true  )
    {
        above = true;
        below = false;

        cout << "above :" << above << endl;
        cout << "below :" << below << endl;


    }

    else if(sunY <= 0.0f && above == true && below == false)
    {
        above = false;
        below = true;
    }


    if( t <= 1.0f && above == false && below == true )
    {
        t += 0.0006555f;

        R = 0.02f + 0.98f*t - 0.4f*t*t;
        G = 0.02f + 0.90f*t - 0.07f*t*t;
        B = 0.10f + 0.90f*t*t;

        RR = 0.02f + 0.51f * pow(t, 1.4f);
        RG = 0.05f + 0.76f * pow(t, 1.2f);
        RB = 0.20f + 0.72f * t;

        color = 0.5f + 0.5f * t;

    }
    else if( t >=0.0f && above == true && below == false){

        t -= 0.0006555f ;
        R = 0.02f + 0.98f*t - 0.4f*t*t;
        G = 0.02f + 0.90f*t - 0.07f*t*t;
        B = 0.10f + 0.90f*t*t;

        RR = 0.02f + 0.51f * pow(t, 1.4f);
        RG = 0.05f + 0.76f * pow(t, 1.2f);
        RB = 0.20f + 0.72f * t;

        color = 0.5f + 0.5f * t;

    }

    if(boaty <= -0.03f && flag)
    {
        boatx +=0.0005;
        boaty += 0.0005;
        boatsx -= 0.0005;
        boatsy -= 0.0005;
    }
    else if(boatsx >= 0.0f && boatsy >= 0.0f)
    {
        boatx -=0.00023;
        boaty -= 0.00023;

        boatsx -= 0.0005;
        boatsy -= 0.0005;
        flag = false;
    }

    if(boatsx <= 0.0f && boatsy <= 0.0f)
    {
        boatsx = 1.0f;
        boatsy = 1.0f;
        boatx = -0.2f;
        boaty = -0.2f;
        flag = true;
    }
    if(cloudx <= 1.8f )
    {
        cloudx += 0.0005f;

    }

    else{

      cloudx = -1.6f;
    }










    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}


void metroTrain(float trainMovex)
{


    glPushMatrix();

    glTranslatef(trainMovex, 0.0f, 0.0f);
    MetroUp();
    Metroground();

    glPopMatrix();


}




void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    Sky();
    glPushMatrix();
    glTranslatef(0.0f, sunY, 0.0f);
    Sun(0.8f, 0.0f, 0.1f);
    glPopMatrix();
    River();

    Bridge();


    Par1();
    Par2();
    Par3();


    metroTrain(trainleft);
    metroTrain(trainright);

    BridgePillerLine();
    BridgeUpperpart();

    glColor3f(R,G,B);
    bridgeHalfCircle(0.0303880365053f, -0.4262208144234f,0.5508333101402f);





     //cloud

     glColor3f(color,color,color);

     glPushMatrix();

     glTranslatef(cloudx, 0.0f, 0.0f);

    drawCircle(-0.1f, 0.8f, 0.0931772472179f); //w1



    drawCircle(0.05f, 0.8f, 0.1567941478983f); //z1


    drawCircle(0.24f, 0.8f, 0.1272743704149f); //a2



    drawCircle(-0.4f, 0.8f, 0.0917201246409f); //c2



    drawCircle(-0.5f, 0.8f, 0.06425599519322091f); //b2

    glPopMatrix();

    glFlush();



     Boat();
    glutPostRedisplay();



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
    glutTimerFunc(2,update, 0);

    glutMainLoop();
    return EXIT_SUCCESS;
}
