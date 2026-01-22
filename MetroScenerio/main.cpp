#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define PI 3.141592653589793
using namespace std;


// Right Fishing Boat
float fishBoatX = 0.40f;
float fishBoatY = -0.58f;
float fishFloat = 0.0f;
float rodAngle = 0.0f;
bool rodUp = true;
bool boatUp = true;
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
float planex = -1.0f;

void playSound()
{
    PlaySound("backgroundMusic.wav", NULL, SND_FILENAME | SND_ASYNC);


}



// Function to draw the plane with adjusted body and wings
void drawplane()
{
    glColor3f(1.0f, 0.00f, 0.00f);
    glBegin(GL_POLYGON);

    glVertex2f(-0.94695502627, 0.8297598709841);//A2
    glVertex2f(-0.7409532355147, 0.707026172492);//B2
    glVertex2f(0.1326295334156, 0.7104991164772);//C2
    glVertex2f(0.1326295334156, 0.7104991164772);//D2
    glVertex2f(-0.0131666857243, 0.8340278463325);//E2

    glEnd();
//PLANE FRONT WINDOW
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.0333912486078, 0.80790263469);//F2
    glVertex2f(0.0180130601429, 0.807240681457);//G2
    glVertex2f(0.0691391833503, 0.7683035677559);//I2
    glVertex2f(-0.0345166120971, 0.770765639542);//H2
    glEnd();
//PLANE WINDOW 2
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1519412984639, 0.7944691903301);//M2
    glVertex2f(-0.1205307536241, 0.7943474440323);//J2
    glVertex2f(-0.1202872610284, 0.7639108695751);//K2
    glVertex2f(-0.1510890743791, 0.7634238843838);//L2
    glEnd();
//PLANE WINDOW 3
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2174918575783, 0.7933133066166);//Q2
    glVertex2f(-0.1848241416916, 0.7926031388799);//N2
    glVertex2f(-0.1842915158891, 0.7595803391249);//O2
    glVertex2f(-0.2173143156441, 0.7594027971907);//P2
    glEnd();
//PLANE WINDOW 4
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2812294119442, 0.7926031388799);//R2
    glVertex2f(-0.248029070255, 0.7922480550116);//S2
    glVertex2f(-0.2485616960575, 0.7599354229932);//T2
    glVertex2f(-0.2817620377467, 0.7594027971907);//U2
    glEnd();
//PLANE WINDOW 5
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.3137195858967, 0.7918929711432);//W2
    glVertex2f(-0.3135420439626, 0.7594027971907);//Z2
    glVertex2f(-0.3469199275859, 0.7590477133224);//A3
    glVertex2f(-0.3476300953226, 0.7920705130774);//V2
    glEnd();
    //PLANE WINDOW 6
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.4123526411541, 0.7908624222398);//B3
    glVertex2f(-0.3786983199456, 0.7914914749726);//C3
    glVertex2f(-0.3783578141015, 0.759651472142);//D3
    glVertex2f(-0.4114090620548, 0.7587807328635);//E3
    glEnd();
    //PLANE WINDOW 7
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.4763657682763, 0.7917227924589);//F3
    glVertex2f(-0.443831104882, 0.7917227924589);//G3
    glVertex2f(-0.4436419498622, 0.7580531989462);//H3
    glVertex2f(-0.4761766132565772, 0.7578640439264183);//I3
    glEnd();
    //PLANE WINDOW 8
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.54, 0.79);//J3
    glVertex2f(-0.5081236650177, 0.7905125933701);//K3
    glVertex2f(-0.5083698012732, 0.7578995395154);//L3
    glVertex2f(-0.5401090820629, 0.7572737102987);//M3
    glEnd();
    //PLANE WINDOW 9
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.6059601466992, 0.7903528738722);//N3
    glVertex2f(-0.5722327457268, 0.7903528738722);//O3
    glVertex2f(-0.5714832479274, 0.758873966298);//P3
    glVertex2f(-0.6052106488998, 0.758873966298);//Q3
    glEnd();
    //PLANE WINDOW 10
    glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_QUADS);
    glVertex2f(-0.6704169574464, 0.7903528738722);//R3
    glVertex2f(-0.6389380498722, 0.7903528738722);//S3
    glVertex2f(-0.6374390542734, 0.7581244684986);//T3
    glVertex2f(-0.6689179618476, 0.7581244684986);//U3
    glEnd();

    glFlush();

}

void planewings()
{
    glColor3f(0.37f,0.48f,0.53f);  // Set the color to blue for the wings
    glBegin(GL_QUADS);
    glVertex2f(-0.4120114940569, 0.8315262262922);
    glVertex2f(-0.5575869969369, 0.9145857681942);
    glVertex2f(-0.392696120721, 0.9182704805119);
    glVertex2f(-0.2132251249094, 0.8329360586975);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.5594293530958, 0.6152028923831);
    glVertex2f(-0.3494007509883, 0.7423254673429);
    glVertex2f(-0.1071309161012, 0.7450890015812);
    glVertex2f(-0.3908537645622, 0.6179664266214);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.9463800782724, 0.830388911753);
    glVertex2f(-0.8098426371209, 0.8310712929997);
    glVertex2f(-0.9143837853032, 0.9795311623298);
    glVertex2f(-0.9474778543361, 0.978906745933);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.9150957177143, 0.8150047787132);
    glVertex2f(-0.8394247406884, 0.8137642708931);
    glVertex2f(-0.9293615576454, 0.7532895146634);
    glVertex2f(-0.9895261869201, 0.7529793877084);
    glEnd();

    glFlush();
}

void Plane()
{
    drawplane();
    planewings();
}
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

void background()
{
    glColor3f(0.32f, 0.65f, 0.32f);
 // Light green grass color
    glBegin(GL_POLYGON);

    glVertex2f(0.0308346265936, -0.214423825252);
    glVertex2f(0.1540455070058, -0.0676421677174);
    glVertex2f(0.1652620343511, -0.0558091668621);
    glVertex2f(0.1758174466172, -0.0487722253513);
    glVertex2f(0.182854388128, -0.0487722253513);
    glVertex2f(0.1895003884437, -0.0518997549117);
    glVertex2f(0.1941916827842, -0.0565910492522);
    glVertex2f(0.32, -0.14);
    glVertex2f(0.3473947231655, -0.1567578108452);
    glVertex2f(0.3236723335077, -0.2051149897629);
    glVertex2f(0.4043439468838, -0.2529448462179);
    glVertex2f(0.5135557488279, -0.281714566973);
    glVertex2f(0.3085059673026, -0.2576852957005);
    glVertex2f(0.2340152263579, -0.2536804171551);
    glVertex2f(0.1338932627225, -0.243267732937);
    glEnd();

    glColor3f(0.32f, 0.65f, 0.32f); // Light green grass color
    glBegin(GL_POLYGON);
    glVertex2f(0.5691542719232, -0.2907631950049);
    glVertex2f(0.5366285744006, -0.2816521600138);
    glVertex2f(0.4220110494215, -0.2671111307254);
    glVertex2f(0.4043439468838, -0.2529448462179);
    glVertex2f(0.3236723335077, -0.2051149897629);
    glVertex2f(0.0308346265936, -0.214423825252);
    glVertex2f(0.3473947231655, -0.1567578108452);
    glVertex2f(0.3473947231655, -0.1567578108452);
    glVertex2f(0.4133288461293, -0.0763776442184);
    glVertex2f(0.4635190784811, -0.0982916893297);
    glVertex2f(0.495459429054, -0.1370706608632);
    glVertex2f(0.527458505563, -0.1792512617159);
    glVertex2f(0.547336719758, -0.2248257040167);
    glVertex2f(0.56, -0.26);

    glEnd();


    glColor3f(0.56f, 0.47f, 0.07f); // Light green grass color
    glBegin(GL_POLYGON);
    glVertex2f(0.5691542719232, -0.2907631950049);
    glVertex2f(0.5366285744006, -0.2816521600138);
    glVertex2f(0.4220110494215, -0.2671111307254);
    glVertex2f(0.4043439468838, -0.2529448462179);
    glVertex2f(0.3236723335077, -0.2051149897629);
    glVertex2f(0.0308346265936, -0.214423825252);
    glVertex2f(0.3473947231655, -0.1567578108452);
    glVertex2f(0.3473947231655, -0.1567578108452);
    glVertex2f(0.4133288461293, -0.0763776442184);
    glVertex2f(0.4635190784811, -0.0982916893297);
    glVertex2f(0.495459429054, -0.1370706608632);
    glVertex2f(0.527458505563, -0.1792512617159);
    glVertex2f(0.547336719758, -0.2248257040167);
    glVertex2f(0.56, -0.26);

    glEnd();


    glColor3f(0.55f, 0.27f, 0.07f);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(0.3644427025137, -0.1763132073391);
    glVertex2f(0.3642106904113, -0.0543750883458);
    glEnd();

    glColor3f(0.0f, 0.39f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.295187514663, -0.064400803089);//w
    glVertex2f(0.4333336418965, -0.0617942723865);//l
    glVertex2f(0.3668671089823, 0.0724420587932);//m
    glEnd();

    glFlush();
}

void tree()
{
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(-0.8614777073501, -0.4835819073043);
    glVertex2f(-0.801392119717, -0.4835819073043);
    glVertex2f(-0.7959924647932, -0.1888981290592);
    glVertex2f(-0.8541946058188, -0.1886162952874);
    glEnd();

    glColor3f(0.0f, 0.39f, 0.0f);  // Dark green color

    float cx = -0.8294650635141f;  // X coordinate of the circle's center
    float cy = -0.1206023261226f;  // Y coordinate of the circle's center
    float r = 0.1f;  // Radius of the circle
    int segments = 100;  // Number of segments for smoothness

    glBegin(GL_POLYGON);  // Begin drawing the circle

    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float x = r * cos(angle);
        float y = r * sin(angle);

        glVertex2f(cx + x, cy + y);  // Calculate and plot each point on the circle
    }

    glEnd();


    glColor3f(0.0f, 0.39f, 0.0f);  // Dark green color

    float cx2 = -0.6981538553702f;  // X coordinate of the circle's center
    float cy2 = -0.0824797173067f;  // Y coordinate of the circle's center
    float r2 = 0.1f;  // Radius of the circle
    int segments2 = 100;  // Number of segments for smoothness

    glBegin(GL_POLYGON);  // Begin drawing the circle

    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float x2 = r * cos(angle);
        float y2 = r * sin(angle);

        glVertex2f(cx2 + x2, cy2 + y2);  // Calculate and plot each point on the circle
    }

    glEnd();

     glColor3f(0.0f, 0.39f, 0.0f);  // Dark green color

    float cx3 = -0.7842827123248f;  // X coordinate of the circle's center
    float cy3 = 0.0163566759199f;   // Y coordinate of the circle's center
    float r3 = 0.1f;  // Radius of the circle
    int segments3 = 100;  // Number of segments for smoothness

    glBegin(GL_POLYGON);  // Begin drawing the circle

    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float x3 = r * cos(angle);
        float y3 = r * sin(angle);

        glVertex2f(cx3 + x3, cy3 + y3);  // Calculate and plot each point on the circle
    }

    glEnd();

    glColor3f(0.0f, 0.39f, 0.0f);  // Dark green color

    float cx4 = -0.9613083633681f;  // X coordinate of the circle's center
    float cy4 = -0.0811910323106f;  // Y coordinate of the circle's center
    float r4 = 0.1f;  // Radius of the circle
    int segments4 = 100;  // Number of segments for smoothness

    glBegin(GL_POLYGON);  // Begin drawing the circle

    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float x4 = r * cos(angle);
        float y4 = r * sin(angle);

        glVertex2f(cx4 + x4, cy4 + y4);  // Calculate and plot each point on the circle
    }

    glEnd();

    glColor3f(0.0f, 0.39f, 0.0f);  // Dark green color

    float cx5 = -0.9f;  // X coordinate of the circle's center
    float cy5 = 0.0f;   // Y coordinate of the circle's center
    float r5 = 0.1f;    // Radius of the circle
    int segments5 = 100; // Number of segments for smoothness

    glBegin(GL_POLYGON);  // Begin drawing the circle

    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        float x5 = r * cos(angle);
        float y5 = r * sin(angle);

        glVertex2f(cx5 + x5, cy5 + y5);  // Calculate and plot each point on the circle
    }

    glEnd();
    glFlush();
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

    glVertex2f(1,-0.2473947971585);//R
    glVertex2f(1,-1);//C

    glEnd();
    glFlush();
}
void Boat()
{
    glPushMatrix();

    // Move boat to rotation center
    glTranslatef(boatx,boaty, 0.0f);

    // Rotate diagonally (negative = clockwise)
    glRotatef(-10.0f, -0.3f, 0.0f, 1.0f);

    glScalef(boatsx,boatsy,0.0f);


    // Boat Body (Brown)
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6267f, -0.7880f);
    glVertex2f(-0.0683f, -0.5036f);
    glVertex2f(-0.0718f, -0.5913f);
    glVertex2f(-0.5494f, -0.8337f);
    glEnd();

    // Long Sail (Right)
    glColor3f(0.9f, 0.9f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5452f, -0.2358f);
    glVertex2f(-0.3554f, -0.6364f);
    glVertex2f(-0.0683f, -0.5036f);
    glEnd();


    // Short Sail (Left)
    glBegin(GL_POLYGON);
    glVertex2f(-0.5662f, -0.7333f);
    glVertex2f(-0.5156f, -0.3370f);
    glVertex2f(-0.3554f, -0.6364f);
    glEnd();


// Black Line Between Sails

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.3554f, -0.6364f);
    glVertex2f(-0.5452f, -0.2358f);
    glEnd();

    glPopMatrix();
    glFlush();

}

void FishingBoat()
{
    glPushMatrix();

    // Boat floating movement
    glTranslatef(fishBoatX, fishBoatY + fishFloat, 0.0f);


    // Boat Body
    glColor3f(0.45f, 0.25f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(0.00f, -0.05f);
    glVertex2f(0.35f, -0.02f);
    glVertex2f(0.30f, -0.10f);
    glVertex2f(0.05f, -0.12f);
    glEnd();


    // Sail
    glColor3f(0.9f, 0.9f, 0.85f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.18f, 0.18f);
    glVertex2f(0.18f, -0.02f);
    glVertex2f(0.30f, -0.02f);
    glEnd();


    // Mast
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.18f, -0.02f);
    glVertex2f(0.18f, 0.20f);
    glEnd();


    // Fisherman (Sitting)

    // Head
    glColor3f(1.0f, 0.8f, 0.6f);
    drawCircle(0.10f, 0.02f, 0.02f);

    // Body
    glColor3f(0.2f, 0.2f, 0.8f);
    glBegin(GL_LINES);
    glVertex2f(0.10f, 0.00f);
    glVertex2f(0.10f, -0.05f);
    glEnd();


    // Fishing Rod (Animated)

    glPushMatrix();

    // Hand position
    glTranslatef(0.10f, 0.00f, 0.0f);

    // Rod rotation
    glRotatef(rodAngle, 0.0f, 0.0f, 1.0f);

    // Rod
    glColor3f(0.4f, 0.2f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.12f, -0.12f);
    glEnd();

    // Fishing Line
    glBegin(GL_LINES);
    glVertex2f(0.12f, -0.12f);
    glVertex2f(0.12f, -0.25f);
    glEnd();

    glPopMatrix();

    glPopMatrix();
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

void BridgeSmallPiller(float x5, float y5)

{
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(x5, y5 );//A2
    glVertex2f(x5,y5+0.072319898118); //A2 (y value) - B2(y value)= 0.072319898118

    glEnd();
    glFlush();


}


void BridgeLargePiller(float x6, float y6)

{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(x6,y6);//D2
    glVertex2f(x6+0.0203022955381f, y6 ); //E2                        //E2(x-value)- D2(x-value) = 0.0203022955381
    glVertex2f(x6+0.0203022955381f, y6-0.0838964834766f ); //F2      //E2(y-value) - F2(y-value) = 0.0838964834766
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


void metroWindow(float x, float y)

{
    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.93f, 0.96f);
    glVertex2f(x,y);//W
    glVertex2f(x+0.1832768690296f, y ); //B1                        //B1(x-value)- W(x-value) = 0.1832768690296
    glVertex2f(x+0.1832768690296f, y-0.1167054502341f ); //C1      //B1(y-value) - C1(y-value) = 0.1167054502341
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

void metroDoor(float x1, float y1)

{
    // for large squre door
    glBegin(GL_QUADS);
    glColor3f(0.36f, 0.36f, 0.36f);                                 //A1(x-value)- I(x-value) = -0.0755576703622
    glVertex2f(x1,y1);//I
    glVertex2f(x1+0.0755576703622f, y1 ); //A1                     //A1(y-value) - D1(y-value) = 0.1460402195819
    glVertex2f(x1+0.0755576703622f, y1-0.1460402195819f ); //D1
    glVertex2f(x1,y1-0.1460402195819f); //B1

    glEnd();


    //  door line

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(x1+0.0397434232971f, y1 ); //C1
    glVertex2f(x1+0.0397434232971f, y1-0.1475011107239f ); //E1

    glEnd();


}


// right door glass


void metroDoorglass1(float x2, float y2)

{
    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.93f, 0.96f);                                  //G1(x-value)- F1(x-value) = 0.0195946148387
    glVertex2f(x2,y2);//F1
    glVertex2f(x2+0.0195946148387f, y2 ); //G1                      //G1(y-value) - I1(y-value) = 0.0776629462188
    glVertex2f(x2+0.0195946148387f, y2-0.0776629462188f ); //H1
    glVertex2f(x2,y2-0.0776629462188f); //I1

    glEnd();

}
//left door glass

void metroDoorglass2(float x3, float y3)

{
    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.93f, 0.96f);                                  //L1(x-value)- K1(x-value) = 0.02
    glVertex2f(x3,y3);//K1
    glVertex2f(x3+0.02f, y3 ); //L1                      //L1(y-value) - M1(y-value) = 0.0793419561894
    glVertex2f(x3+0.02f, y3-0.0793419561894f ); //M1
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

    planex += 0.02f;

    if(planex >= 8.00f)
    {
        planex = -8.00f;
    }

    if(above == false && below == true )
    {

        sunY += 0.0005f;


    }
    else if (above == true && below == false)
    {
        sunY -= 0.0005f;


    }





    if (trainleft <= -3.0f)
    {


        trainleft= 1.5f;




    }
    if (trainright >= 7.0f)
    {


        trainright= -7.5f;




    }


    if(sunY >= 0.75f && above == false && below == true  )
    {
        above = true;
        below = false;




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
    else if( t >=0.0f && above == true && below == false)
    {

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

    else
    {

        cloudx = -1.6f;
    }


// Fishing rod up-down animation
    if (rodUp)
    {
        rodAngle += 0.3f;      // rod going up

        if (rodAngle >= 10.0f) // max up angle
            rodUp = false;
    }
    else
    {
        rodAngle -= 0.3f;      // rod going down

        if (rodAngle <= -25.0f) // max down angle
            rodUp = true;
    }



// Fishing boat floating

    if (boatUp)
    {
        fishFloat += 0.0002f;      // move up slowly

        if (fishFloat >= 0.02f)    // max height
            boatUp = false;
    }
    else
    {
        fishFloat -= 0.0002f;      // move down slowly

        if (fishFloat <= -0.02f)   // min height
            boatUp = true;
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



    Bridge();


    metroTrain(trainleft);
    metroTrain(trainright);

    BridgePillerLine();
    BridgeUpperpart();

    glColor3f(R, G, B);
    bridgeHalfCircle(0.0303880365053f, -0.4262208144234f, 0.5508333101402f);

    glPushMatrix();
    glTranslatef(0.0f,-0.2f, 0.0f);
    background();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,-0.16f,0.0f);
    River();
    glPopMatrix();
    Par1();
    Par2();
    Par3();


    glColor3f(color, color, color);

    glPushMatrix();
    glTranslatef(cloudx, 0.0f, 0.0f);
    drawCircle(-0.1f, 0.8f, 0.0931772472179f);  // Draw cloud 1
    drawCircle(0.05f, 0.8f, 0.1567941478983f);  // Draw cloud 2
    drawCircle(0.24f, 0.8f, 0.1272743704149f);  // Draw cloud 3
    drawCircle(-0.4f, 0.8f, 0.0917201246409f);  // Draw cloud 4
    drawCircle(-0.5f, 0.8f, 0.06425599519322091f);  // Draw cloud 5
    glPopMatrix();

    tree();
    Boat();
    FishingBoat();



    glPushMatrix();
    glScalef(0.2f,0.2f,0.0f);
    glTranslatef(planex,2.9f,0.0f);
    Plane();
    glPopMatrix();




    glutSwapBuffers();  // Swap buffers for smooth animation
}


void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);  // Set orthogonal projection for 2D rendering
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
    glutTimerFunc(2, update, 0);
    playSound();
    glutMainLoop();
    return EXIT_SUCCESS;
}
