
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#define PI 3.141592653589

int sceneNo = 1;
GLfloat w,h;
void renderScene(void);

GLfloat rotval=100;
GLfloat movex=1.5;
//All the variables

GLfloat scene1_bodyx = 1.5;
GLfloat scene1_frontleg=0,scene1_backleg=0;
int scene1_counter=0;
char scene1_movement;

GLfloat scene1_bodyxdog = -1.5;
GLfloat scene1_frontlegdog=0,scene1_backlegdog=0;
int scene1_counterdog=0;
char scene1_movementdog;
GLfloat scene4_bodyx = 6;
GLfloat scene4_frontlegdog=0,scene4_backlegdog=0;
int scene4_counterdog=0;
char scene4_movementdog;


GLfloat moneytx = 1.15f;
GLfloat moneyty = -0.28f;
GLfloat pinkguyx = 0.4f;

GLfloat scene7_bodyx = 1.5;
GLfloat scene7_frontleg=0,scene7_backleg=0;
int scene7_counter=0;
char scene7_movement;

void addLight()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    GLfloat light0_pos[]= {2.0,0.0,-5.0,1.0};
    GLfloat light0_dir[]= {-10.0,20.0,-10.0,0.0};
    GLfloat diffuse0[]= {1.0,1.0,1.0,1.0,};
    GLfloat diffuse[]= {0.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse0);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
}


void drawString1(const char *string)
{
	  char *c;
	  glPushMatrix();
	  glScalef(0.02,0.02,1);

	  while (*string)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *string++);
	  glPopMatrix();
}


void drawString2D(const char *string)
{
	  char *c;
	  glPushMatrix();
	  while (*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *string++);
	  glPopMatrix();
}

void drawString(const char *string,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x,y,z);
	  glScalef(0.02,0.02,1);

	  while (*string)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *string++);
	  glPopMatrix();
}


void drawString2(float x,float y,float z, char * string) {
    glRasterPos3f(x, y, z);

   for (char * c = string;* c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, * c); // Updates the position
    }
}



void introductionDisplay() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 0.0f, -5.0f);  // Move right and into the screen
    glColor3f(1,1,1);
    glPushMatrix();
        glTranslatef(-4,2,0);
        glScalef(0.2,0.2,1);
        drawString1("COMPUTER GRAPHICS");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3,1.4,0);
        glScalef(0.2,0.2,1);
        drawString1("MINI PROJECT");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3,0,0);
        glScalef(0.2,0.2,1);
        drawString1("ADOPTION SHELTER");
    glPopMatrix();


    glPushMatrix();
        glTranslatef(-3,-1,0);
        glScalef(0.1,0.1,1);
        drawString1("Sanjitha Singh      1DS16CS739");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3,-1.9,0);
        glScalef(0.1,0.1,1);
        drawString1("Sara Manha          1DS16CS740");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3,-2.8,0);
        glScalef(0.1,0.1,1);
        drawString1("Saragalla Ramya     1DS16CS741");
    glPopMatrix();

   glutSwapBuffers();
}

void sceneOneAnimations()
{
    scene1_counter+=1;
    if(scene1_counter%2!=0)
    {
        scene1_movement='f';
    }
    else
    {
        scene1_movement='b';
    }
    scene1_bodyx-=0.1;
    if(scene1_movement=='f')
    {

        scene1_frontleg=15;
        scene1_backleg=0;
    }
    if(scene1_movement=='b')
    {

        scene1_backleg=15;
        scene1_frontleg=0;
    }
    if(scene1_bodyx<-1.5)
    {
        scene1_bodyx=1.5;
    }

    //dog animations

    scene1_counterdog+=1;
    if(scene1_counterdog%2!=0)
    {
        scene1_movementdog='f';
    }
    else
    {
        scene1_movementdog='b';
    }

    if(scene1_movementdog=='f')
    {

        scene1_frontlegdog=15;
        scene1_backlegdog=0;
    }
    if(scene1_movementdog=='b')
    {

        scene1_backlegdog=15;
        scene1_frontlegdog=0;
    }

}

void sceneOneDrawBackground()
{
    glPushMatrix();
    glTranslatef(0,0,-2.5);
    glScalef(2,1,1);
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(-1.0,0.0,0.0);
    glVertex3f(-0.5,0.8,0.0);
    glVertex3f(0.0,0.0,0.0);
    glEnd();
    //right mountain
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.35f, 0.05f);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.5,0.8,0.0);
    glVertex3f(1.0,0.0,0.0);
    glEnd();
    glPopMatrix();

    //grass patch
    glPushMatrix();
    glTranslatef(0,0,-2.5);
    glColor3f(0,1,0);
    glScalef(2,0.5,1);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,-0.75,0.0);
    glVertex3f(-1.0,-0.75,0.0);
    glEnd();
    glPopMatrix();

    //road
    glPushMatrix();
    glTranslatef(0,-0.3,-2.4);
    glColor3f(0.1,0.1,0.1);
    glScalef(2,2,1);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,-0.75,0.0);
    glVertex3f(-1.0,-0.75,0.0);
    glEnd();
    glPopMatrix();
}


void sceneOneDrawCharacter()
{
    glPushMatrix();//man
    //Draw head
    glPushMatrix();
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glTranslatef(0,0.4,0);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glScalef(0.2,0.2,0.2);
    glTranslatef(-0.5,2.0,1.5);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    //Draw body

    glPushMatrix();
    glColor3f(1,1,0.5);
    glScalef(0.3,0.5,0.1);
    glTranslatef(0,-0.1,1.0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.35,0.06,0.2);
    //glRotatef(30,0,0,1);
    glTranslatef(-0.35,0.0,1.2);
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(scene1_frontleg,0,0,1);//visible leg
    glTranslatef(0,-0.4,0.1);
    glColor3f(0,0,1);
    glScalef(0.1,0.3,0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//leg behind
    glRotatef(scene1_backleg,0,0,1);
    glTranslatef(0,-0.4,0);
    glColor3f(0,0,1);
    glScalef(0.1,0.3,0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6582,0.66,0.6336);
    glLineWidth(4);
    glTranslatef(-0.2,0.0,0);
    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(-0.8,-0.15,0);
    glEnd();
    glPopMatrix();
    glPopMatrix();

}

void sceneOneDrawDog()
{
    glPushMatrix();
    glColor3f(0.97,0.8082,0.0873);
    glTranslatef(-0.7,-0.2,0);
    glScalef(0.3,0.3,1);
    glPushMatrix();
    glPushMatrix();//body
    glScalef(1.3,0.8,1);
    glTranslatef(-0.1,-0.2,0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.65,-0.5,0);
    glVertex3f(-0.75,0.5,0);
    glVertex3f(0.75,0.5,0);
    glVertex3f(0.65,-0.5,0);
    glEnd();
    glPopMatrix();
    //neck
    glPushMatrix();
    glScalef(1,0.6,1);
    glTranslatef(-1.1,0.5,0);
    glBegin(GL_POLYGON);
    glVertex3f(0.1,-0.5,0);
    glVertex3f(0.2,-0.25,0);
    glVertex3f(-0.15,0.5,0);
    glVertex3f(-0.2,0.25,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//head
    glTranslatef(-1.84,0.2,0);
    glRotatef(-50,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1,0,0);
    glVertex3f(0.1,0,0);
    glVertex3f(0.4,0.7,0);
    glVertex3f(-0.4,0.7,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right ear
    glTranslatef(-1.6,0.85,0);
    glRotatef(55,0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.1,0,0);
    glVertex3f(0.1,0.2,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left ear
    glTranslatef(-1.7,0.65,0);
    glRotatef(55,0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,0);
    glVertex3f(0,0.2,0);
    glVertex3f(0.2,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,-0.2,0);
    glRotatef(-20,0,0,1);
    glScalef(3,0.6,1);
    glBegin(GL_POLYGON);
    glVertex3f(0.1,-0.5,0);
    glVertex3f(0.2,-0.25,0);
    glVertex3f(-0.15,0.5,0);
    glVertex3f(-0.2,0.25,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//front-front leg
    glTranslatef(-0.8,-1,0);
    glRotatef(scene1_frontlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0.1,0,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0,0.1,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//front-back leg
    glTranslatef(-0.6,-1,-0.1);
    glRotatef(scene1_backlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//back-front leg
    glTranslatef(0.5,-1,0);
    glRotatef(scene1_frontlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//back-back leg
    glTranslatef(0.3,-1,-0.1);
    glRotatef(scene1_backlegdog,0,0,1);
    glScalef(1.5,10,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1.7,0.5,0);
    glutSolidSphere(0.06,20,20);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();//dog close

}


void sceneOneDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(3,3,1);
    glPushMatrix();//full screen

    sceneOneDrawBackground();


    glTranslatef(scene1_bodyx,0,-2.3);
    glPushMatrix();//characters that move
    glTranslatef(0,0,0);
    sceneOneDrawCharacter();

    sceneOneDrawDog();
    glPopMatrix();//characters that move


    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
        glTranslatef(-1.2,0.8,-1);
        glScalef(0.05,0.05,1);

        drawString("You don't have to run alone",-2,1,-1);
    glPopMatrix();
    glutSwapBuffers();

    sceneOneAnimations();

}

GLfloat scene2_offset=1;
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

// Function to Draw Circle
void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius) {
	glPushMatrix();

	glTranslatef(x, y, 0);
	glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	for (GLfloat i = 0; i < 360; i += 5)
		glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
	glEnd();

	glPopMatrix();
}


// Function to Draw Circle
void drawSemiCircle(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat radius,
	GLfloat start_angle, GLfloat end_angle) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	for (GLfloat i = start_angle; i < end_angle; i += 5)
		glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
	glEnd();

	glPopMatrix();
}

// Function to Draw Arc
void drawArc(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3ub(r, g, b);
	for (GLfloat i = 90; i < 270; i++)
		glVertex2f(15 * sin(i * PI / 180), 15 * cos(i * PI / 180));
	glEnd();
	glPointSize(1);

	glPopMatrix();
}

// Function to Draw a Woman
void drawWoman(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(203, 166, 108); // Darker Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		232, 190, 123, // Lighter Skin
		1, 1,
		30);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(485, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, -180, 0);

	// Left Eye
	drawCircle(505, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(508, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(530, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(532, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	drawArc(514, 388, .5, .3,
		20, 20, 20);

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(518, 405);
	glVertex2f(522, 398);
	glVertex2f(522, 398);
	glVertex2f(518, 395);
	glEnd();
	glLineWidth(1);

	// Arms
	glLineWidth(10);
	glBegin(GL_LINES);//down
	glColor3ub(232, 190, 123); // Lighter Skin
	glVertex2f(470, 340);
	glVertex2f(600, 200);
	glVertex2f(475, 340);
	glVertex2f(605, 200);
	glVertex2f(480, 340);
	glVertex2f(610, 200);
	glEnd();
	glLineWidth(1);

	glPushMatrix();
	glTranslated(0,scene2_offset,0);
    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(232, 190, 123);
	glVertex2f(500, 340);//up
	glVertex2f(620, 240);
	glVertex2f(500, 340);
	glVertex2f(625, 240);
	glVertex2f(510, 340);
	glVertex2f(630, 240);
	glEnd();
	glLineWidth(1);
    glPopMatrix();
	// Top
	glBegin(GL_POLYGON);
	glColor3ub(top_r, top_g, top_b);
	glVertex2f(460, 370);
	glVertex2f(560, 370);
	glVertex2f(540, 300);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(skirt_r, skirt_g, skirt_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glVertex2f(560, 180);
	glVertex2f(460, 180);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(ribbon_r, ribbon_g, ribbon_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glLineWidth(1);

	// Legs
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(232, 190, 123); // Lighter Skin
	glVertex2f(490, 180);
	glVertex2f(490, 120);
	glVertex2f(495, 180);
	glVertex2f(495, 120);

	glVertex2f(525, 180);
	glVertex2f(525, 120);
	glVertex2f(530, 180);
	glVertex2f(530, 120);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}


void kitchen()
{
    glPushMatrix();
   //kitchen counter horizontal
    glBegin(GL_POLYGON);
	glColor3ub(158,11, 67);
	glVertex2f(00, 400);
	glVertex2f(00, 625);
	glVertex2f(1450, 625);
	glVertex2f(1450, 400);
	glEnd();

	//vertical slab
	 glBegin(GL_POLYGON);
	glColor3ub(158, 11, 67);
	glVertex2f(00, 600);
	glVertex2f(00, 50);
	glVertex2f(220, 50);
	glVertex2f(220, 600);
	glEnd();

	//sink
	 glBegin(GL_POLYGON);
	glColor3ub(216, 229, 237);
	glVertex2f(45, 350);
	glVertex2f(180, 350);
	glVertex2f(180, 120);
	glVertex2f(45, 120);
	glEnd();

	//oven
	glBegin(GL_POLYGON);
	glColor3ub(250,252,252);
	glVertex2f(1000,700);
	glVertex2f(1200,700);
	glVertex2f(1200,550);
	glVertex2f(1000,550);
	glEnd();
	//oven border
	//top
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex2f(1000, 700);
	glVertex2f(1200, 700);
	glEnd();
	glLineWidth(1);
    //right
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex2f(1200, 700);
	glVertex2f(1200, 550);
	glEnd();
	glLineWidth(1);
    //left
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex2f(1000, 700);
	glVertex2f(1000, 550);
	glEnd();
	glLineWidth(1);

    //bottom
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex2f(1000, 550);
	glVertex2f(1200, 550);
	glEnd();
	glLineWidth(1);

	//handle
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(1160,650);
	glVertex2f(1180,650);
	glVertex2f(1180,590);
	glVertex2f(1160,590);
	glEnd();


	//cupboard1
	 glBegin(GL_POLYGON);
	glColor3ub(5, 145, 227);
	glVertex2f(220, 400);
	glVertex2f(460, 400);
	glVertex2f(460, 150);
	glVertex2f(220, 150);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(3, 9, 115);
	glVertex2f(460, 400);
	glVertex2f(460, 150);
	glVertex2f(465, 400);
	glVertex2f(465, 150);
	glEnd();
	glLineWidth(1);

	glBegin(GL_POLYGON);//handle
	glColor3ub(3,9,115);
	glVertex2f(420,300);
	glVertex2f(440,300);
	glVertex2f(440,250);
	glVertex2f(420,250);
	glEnd();

	//cupboard2
	 glBegin(GL_POLYGON);
	glColor3ub(5, 145, 227);
	glVertex2f(465, 400);
	glVertex2f(705, 400);
	glVertex2f(705, 150);
	glVertex2f(465, 150);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(3, 9, 115);
	glVertex2f(705, 400);
	glVertex2f(705, 150);
	glVertex2f(710, 400);
	glVertex2f(710, 150);
	glEnd();
	glLineWidth(1);

	glBegin(GL_POLYGON);
	glColor3ub(3,9,115);
	glVertex2f(665,300);
	glVertex2f(685,300);
	glVertex2f(685,250);
	glVertex2f(665,250);
	glEnd();

	//cupboard3
	glBegin(GL_POLYGON);
	glColor3ub(5, 145, 227);
	glVertex2f(710, 400);
	glVertex2f(950, 400);
	glVertex2f(950, 150);
	glVertex2f(710, 150);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(3, 9, 115);
	glVertex2f(950, 400);
	glVertex2f(950, 150);
	glVertex2f(955, 400);
	glVertex2f(955, 150);
	glEnd();
	glLineWidth(1);

	glBegin(GL_POLYGON);
	glColor3ub(3,9,115);
	glVertex2f(910,300);
	glVertex2f(930,300);
	glVertex2f(930,250);
	glVertex2f(910,250);
	glEnd();

	//cupboard4
	glBegin(GL_POLYGON);
	glColor3ub(5, 145, 227);
	glVertex2f(955, 400);
	glVertex2f(1195, 400);
	glVertex2f(1195, 150);
	glVertex2f(955, 150);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(3, 9, 115);
	glVertex2f(1195, 400);
	glVertex2f(1195, 150);
	glVertex2f(1200, 400);
	glVertex2f(1200, 150);
	glEnd();
	glLineWidth(1);

	glBegin(GL_POLYGON);
	glColor3ub(3,9,115);
	glVertex2f(1155,300);
	glVertex2f(1175,300);
	glVertex2f(1175,250);
	glVertex2f(1155,250);
	glEnd();

	//cupboard5
	glBegin(GL_POLYGON);
	glColor3ub(5, 145, 227);
	glVertex2f(1200, 400);
	glVertex2f(1400, 400);
	glVertex2f(1400, 150);
	glVertex2f(1200, 150);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(3,9,115);
	glVertex2f(1360,300);
	glVertex2f(1380,300);
	glVertex2f(1380,250);
	glVertex2f(1360,250);
	glEnd();

    //bordercupboard

    glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(3, 9, 115);
	glVertex2f(220, 150);
	glVertex2f(1400, 150);
	glEnd();
	glLineWidth(10);

	 glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(3, 9, 115);
	glVertex2f(220, 400);
	glVertex2f(1400, 400);
	glEnd();
	glLineWidth(10);

	//draw plate
	glPushMatrix();
	glColor3ub(252,249,242);
	drawFilledCircle(100,200,50);
	glPopMatrix();
    glPopMatrix();
}

void cat()
{
    glPushMatrix();
    glScaled(0.75,0.75,0.75);
    glTranslated(220,100,0);

    //head
    glColor3ub(232,190,123);
    drawFilledCircle(450,650,50);
    //triangle

    glBegin(GL_POLYGON);
    glVertex2f(415,680);
    glVertex2f(440,690);
    glVertex2f(420,730);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(465,690);
    glVertex2f(490,680);
    glVertex2f(475,730);
    glEnd();
    //eyes
    glPushMatrix();
      glColor3f(0,0,0);
      glPointSize(15.0);
     glBegin(GL_POINTS);
       glVertex2f(425,670);
       glVertex2f(475,670);
    glEnd();
    glPopMatrix();
    //nose
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(440,650);
    glVertex2f(470,650);
    glVertex2f(453,625);
    glEnd();
    //moustache
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(380,655);
    glVertex2f(435,645);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(380,615);
    glVertex2f(435,630);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(530,655);
    glVertex2f(475,645);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(530,620);
    glVertex2f(475,630);
    glEnd();
    //body
    glColor3ub(232,190,123);
    glBegin(GL_POLYGON);
    glVertex2f(450,620);
    glVertex2f(380,480);
    glVertex2f(520,480);
    glEnd();
     //tail
     glBegin(GL_LINES);
    glVertex2f(510,500);
    glVertex2f(550,550);
    glEnd();

    glPopMatrix();
}




   void scene2display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    kitchen();
    cat();
    glTranslatef(-880,-90,0);
    //8glRotated(180,0.0,1.0,0.0);
    drawWoman(1630, 50, -1, 1,
		20, 20, 20,
		229, 49, 49, // top
		37, 107, 202, // bottom
		229, 49, 49);

    glPopMatrix();
     glPushMatrix();
    glColor3f(0,0,0);
        glTranslatef(50,750,0);
        glScalef(0.5,0.5,1);
        drawString2D("You don't have to do your chores alone");
    glPopMatrix();
    glutSwapBuffers();
}



void initializeScreen() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1400, 0, 800);
}







void sceneFourDrawCharacter()
{
    glPushMatrix();//man
    //Draw head
    glPushMatrix();
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glTranslatef(0,0.4,0);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    glPushMatrix();//eye
    glColor3f(0, 0, 0);
    glScalef(0.2,0.2,0.2);
    glTranslatef(0.4,2.0,1.5);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    //Draw body

    glPushMatrix();
    glColor3f(1,1,0.5);
    glScalef(0.3,0.5,0.1);
    glTranslatef(0,-0.1,1.0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.35,0.06,0.2);
    glTranslatef(0.5,0.0,1.2);
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.4,0.1);
    glColor3f(0,0,1);
    glScalef(0.1,0.3,0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//leg behind
    glTranslatef(0,-0.4,0);
    glColor3f(0,0,1);
    glScalef(0.1,0.3,0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

}

void sceneFourDrawDog()
{
    glPushMatrix();
    glColor3f(0.97,0.8082,0.0873);
    glTranslatef(-0.7,-0.2,0);
    glScalef(0.3,0.3,1);
    glPushMatrix();
    glPushMatrix();//body
    glScalef(1.3,0.8,1);
    glTranslatef(-0.1,-0.2,0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.65,-0.5,0);
    glVertex3f(-0.75,0.5,0);
    glVertex3f(0.75,0.5,0);
    glVertex3f(0.65,-0.5,0);
    glEnd();
    glPopMatrix();
    //neck
    glPushMatrix();
    glScalef(1,0.6,1);
    glTranslatef(-1.1,0.5,0);
    glBegin(GL_POLYGON);
    glVertex3f(0.1,-0.5,0);
    glVertex3f(0.2,-0.25,0);
    glVertex3f(-0.15,0.5,0);
    glVertex3f(-0.2,0.25,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//head
    glTranslatef(-1.84,0.2,0);
    glRotatef(-50,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1,0,0);
    glVertex3f(0.1,0,0);
    glVertex3f(0.4,0.7,0);
    glVertex3f(-0.4,0.7,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right ear
    glTranslatef(-1.6,0.85,0);
    glRotatef(55,0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.1,0,0);
    glVertex3f(0.1,0.2,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left ear
    glTranslatef(-1.7,0.65,0);
    glRotatef(55,0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,0);
    glVertex3f(0,0.2,0);
    glVertex3f(0.2,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,-0.2,0);
    glRotatef(-20,0,0,1);
    glScalef(3,0.6,1);
    glBegin(GL_POLYGON);
    glVertex3f(0.1,-0.5,0);
    glVertex3f(0.2,-0.25,0);
    glVertex3f(-0.15,0.5,0);
    glVertex3f(-0.2,0.25,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//front-front leg
    glTranslatef(-0.8,-1,0);
    glRotatef(scene4_frontlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0.1,0,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0,0.1,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//front-back leg
    glTranslatef(-0.6,-1,-0.1);
    glRotatef(scene4_backlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//back-front leg
    glTranslatef(0.5,-1,0);
    glRotatef(scene4_frontlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//back-back leg
    glTranslatef(0.3,-1,-0.1);
    glRotatef(scene4_backlegdog,0,0,1);
    glScalef(1.5,10,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1.7,0.5,0);
    glutSolidSphere(0.06,20,20);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();//dog close

}


void sceneFourAnimations()
{
    scene4_bodyx-=0.1;

    if(scene4_bodyx<5)
    {
        scene4_bodyx=7;
    }


    scene4_counterdog+=1;
    if(scene4_counterdog%2!=0)
    {
        scene4_movementdog='f';
    }
    else
    {
        scene4_movementdog='b';
    }

    if(scene4_movementdog=='f')
    {

        scene4_frontlegdog=15;
        scene4_backlegdog=0;
    }
    if(scene4_movementdog=='b')
    {

        scene4_backlegdog=15;
        scene4_frontlegdog=0;
    }

}

void drawTree(){

    glPushMatrix();
     glPushMatrix();//trunk
        glScalef(1,2.5,1);
        glColor3f(0.8,0.5768,0.056);
        glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();//head
        glTranslatef(0,1.5,1);
        glColor3f(0.0819,0.91,0.2337);
        glutSolidSphere(1,20,20);
    glPopMatrix();
    glPopMatrix();


    glPopMatrix();
}

void drawLeftSide(){
    glPushMatrix();
    glColor3f(1,0.82,0.988);
    glBegin(GL_POLYGON);
    glVertex3f(-w/2,-h/2,-20);
    glVertex3f(0,-h/2,-20);
    glVertex3f(0,h/2,-20);
    glVertex3f(-w/2,h/2,-20);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //bed
    glTranslatef(-3,-0.8,-18);
    glScalef(6,1.4,1);
        glColor3f(1,0,0);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix(); //base
    glTranslatef(-3,-1.5,-18);
    glScalef(6,0.5,1);
        glColor3f(0.8,0.5768,0.056);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//leg
         glTranslatef(-0.4,-2.5,-18);
    glScalef(0.8,2,1);
        glColor3f(0.8,0.5768,0.056);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//leg
         glTranslatef(-5.5,-2.5,-18);
    glScalef(0.8,2,1);
        glColor3f(0.8,0.5768,0.056);
        glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();//pillow
        glTranslatef(-0.5,0.15,-18);
        glScalef(1,0.5,1);
        glColor3f(1,1,1);
        glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();//head
        glTranslatef(-3,2,-15);
        glColor3f(0.95f, 0.8107f, 0.4275f);
        glutSolidSphere(0.7,20,20);
    glPopMatrix();


    glPushMatrix();//body
        glTranslatef(-3,0.4,-15);
        glScalef(1.2,1.8,1);
        glColor3f(1,1,0.5);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//human leg
    glTranslatef(-2.5,-0.9,-12);
    glColor3f(0,0,1);
    glScalef(0.4,1.5,0.1);
    glutSolidCube(1.0);
    glPopMatrix();

     glPushMatrix();//human leg left
    glTranslatef(-3.5,-0.9,-12);
    glColor3f(0,0,1);
    glScalef(0.4,1.5,0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//left hand
    glTranslatef(-3.8,0.7,-14);
    glRotatef(75,0,0,1);
    glScalef(1.2,0.2,1);
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//right hand
    glTranslatef(-2.3,0.7,-14);
    glRotatef(-75,0,0,1);
    glScalef(1.2,0.2,1);
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//right eye
    glColor3f(0,0,0);
    glTranslatef(-2.6,2,-14);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    glPushMatrix();//left eye
    glColor3f(0,0,0);
    glTranslatef(-3.3,2,-14);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    //eyebrows

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-3.3,2.3,-14);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(-0.2,-0.2,0);
    glEnd();
        glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-2.6,2.3,-14);
    glLineWidth(5);
    glBegin(GL_LINES);

    glVertex3f(0,0,0);
    glVertex3f(0.2,-0.2,0);

    glEnd();
        glPopMatrix();



}


void drawRightSide(){
     glPushMatrix();
    glColor3f(0.056,0.8,0.1924);
    glBegin(GL_POLYGON);
    glVertex3f(0,-1,-20);
    glVertex3f(w/2,-1,-20);
    glVertex3f(w/2,-h/2,-20);
    glVertex3f(0,-h/2,-20);
    glEnd();
    glPopMatrix();
     glPushMatrix();
        glTranslatef(2,0,-10);
        glScalef(2,2,2);
        sceneFourDrawCharacter();
    glPopMatrix();
    glPushMatrix();
     glTranslatef(scene4_bodyx,0,-10);
     glScalef(2,2,2);
        sceneFourDrawDog();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,0.2,-15);
        drawTree();
    glPopMatrix();

}


void sceneFourDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        drawLeftSide();
    glPopMatrix();
    glPushMatrix();
     drawRightSide();
    glPopMatrix();


     glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(-3.5,-2.5,-1);
        glScalef(0.15,0.15,1);
        drawString("You don't have to be alone",-3.2,-2.5,-1);
    glPopMatrix();

    glutSwapBuffers();

    sceneFourAnimations();


}



void sceneButBeforedisplay() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 0.0f, -5.0f);  // Move right and into the screen
    glColor3f(0,0,0);
    glLineWidth(3);
    glPointSize(3);
    glPushMatrix();
        glTranslatef(-3.5,2,0);
        glColor3f(0.5075,0.042,0.84);
        glScalef(0.1,0.1,1);
        drawString1("But before you head to your nearest");
    glPopMatrix();

        glPushMatrix();
        glColor3ub(214, 27, 11);
        glTranslatef(-2,1.2,0);
        glScalef(0.2,0.2,1);
        drawString1("Pet Shop");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2,0.5,0);
        glColor3f(0.5075,0.042,0.84);
        glScalef(0.1,0.1,1);
        drawString1("Consider this:");
    glPopMatrix();


    glPushMatrix();
        glTranslatef(-5.5,-0.3,0);
        glColor3ub(214, 11, 96);
        glScalef(0.1,0.1,1);
        drawString1("Animals are bred in \"mills\" to supply to pet shops");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-4.5,-0.9,0);
        glColor3ub(214, 11, 96);
        glScalef(0.1,0.1,1);
        drawString1("They are mistreated and kept in cages");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3,-1.5,0);
        glColor3ub(198, 214, 11);
        glScalef(0.1,0.1,1);
        drawString1("It\'s all about profit!");
    glPopMatrix();

   glutSwapBuffers();

}

void drawMoney() {
    glRotatef(55, 0.0, 0.0, 1.0);
    glLineWidth(1.5f);
    glScalef(0.3, 0.3, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 1.0f, 0.0f);
    glEnd();
}

/* Handlerfor window-repaint event. Called back when the windowfirst appears and
   whenever the window needs to be re-painted. */
void moneymakerDisplay() {
    GLfloat offset = 0.0f;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    //Road
    glPushMatrix();
    glTranslatef(-8.0f, 0.0f, -10.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(1.5f, -10.0f, 0.0f);
    glVertex3f(1.5f, 10.0f, 0.0f);
    glVertex3f(-1.5f, 10.0f, 0.0f);
    glVertex3f(-1.5f, -10.0f, 0.0f);
    glEnd();
    glPopMatrix();

    //Draw Pavement outline
    glPushMatrix();
    glTranslatef(-5.0f, 0.0f, -10.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(1.7f, -8.5f, 0.0f);
    glVertex3f(1.7f, 8.5f, 0.0f);
    glVertex3f(-1.7f, 8.5f, 0.0f);
    glVertex3f(-1.7f, -8.5f, 0.0f);
    glEnd();
    glPopMatrix();

    //lines of the pavement
    glPushMatrix();
    glTranslatef(-5.0f, 0.0f, -10.0f);
    glLineWidth(3.0);
    offset = -5.0f;
   for (int i = 1; i < 8; i++) {
        glBegin(GL_LINES);
        glVertex3f(1.7f, offset, 0.0f);
        glVertex3f(-1.7f, offset, 0.0f);
        glEnd();
        offset += 1.5f;
    }
    glPopMatrix();

    //Pet Shop Sign
    glPushMatrix();
    glColor3f(0.9064f, 0.96f, 0.3168f);
    glTranslatef(-4.1f, 0.0f, -8.0f);
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(1.0f, -1.5f, 0.0f);
    glVertex3f(-1.0f, -1.5f, 0.0f);
    glEnd();
    glPopMatrix();

    //Pet shop header
    glPushMatrix();
    glColor3f(0.69f, 0.5979f, 0.0759f);
    glTranslatef(-4.1f, 0.0f, -8.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.1f, 0.0f);
    glVertex3f(-0.5f, 0.1f, 0.0f);
    glEnd();
    glPopMatrix();

    /**make this 3d**/
    //Pet shop leg right
    glPushMatrix();
    glColor3f(0.69f, 0.5979f, 0.0759f);
    glTranslatef(-4.1f, -2.0f, -9.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.8f, 0.0f);
    glVertex3f(-0.2f, 0.8f, 0.0f);
    glEnd();
    glPopMatrix();

    //Pet shop leg right
    glPushMatrix();
    glColor3f(0.69f, 0.5979f, 0.0759f);
    glTranslatef(-5.0f, -2.0f, -9.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-0.2f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.8f, 0.0f);
    glVertex3f(-0.2f, 0.8f, 0.0f);
    glEnd();
    glPopMatrix();

    //Arrow
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-4.2f, -1.0f, -8.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.2f, 0.0f);
    glVertex3f(-0.5f, 0.2f, 0.0f);
    glEnd();
    glPopMatrix();
    //Arrow Head
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-4.2f, -0.9f, -8.0f);
    glBegin(GL_POLYGON);
    glVertex3f(0.5f, 0.2f, 0.0f);
    glVertex3f(0.8f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.2f, 0.0f);
    glEnd();
    glPopMatrix();

    //Pet Shop - Text

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    drawString2(-3.8f, -0.3f, -7.0f, "PET");
    drawString2(-3.9f, -0.5f, -7.0f, "SHOP");
    glPopMatrix();

    //Counter Top
    glPushMatrix();
    glColor3f(1.0, 0.75, 0.0);
    glTranslatef(2.0f, -1.0f, -8.0f);
    glScalef(4.5f, 2.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, -0.5f, 0.0f);
    glVertex3f(-1.0f, -0.5f, 0.0f);
    glEnd();
    glPopMatrix();
    //Counter Bottom
    glPushMatrix();
    glColor3f(0.9, 0.675, 0.0);
    glTranslatef(2.0f, -2.0f, -8.0f);
    glScalef(4.5f, 2.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, -0.5f, 0.0f);
    glVertex3f(-1.0f, -0.5f, 0.0f);
    glEnd();
    glPopMatrix();

    //Cages
    glPushMatrix();
    glColor3f(0.71, 0.71, 0.71);
    glTranslatef(5.0f, 3.0f, -10.0f);
    glScalef(3.0f, 2.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, -0.5f, 0.0f);
    glVertex3f(-1.0f, -0.5f, 0.0f);
    glEnd();
    glPopMatrix();

    //Draw lines on cages
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(1.95f, 2.95f, -9.8f);
    glLineWidth(3.0);
    offset = 0.0f;
   for (int i = 1; i < 15; i++) {
        glBegin(GL_LINES);
        glVertex3f(offset, 1.0f, 0.0f);
        glVertex3f(offset, -1.0f, 0.0f);
        glEnd();
        offset += 0.5f;
    }
    glPopMatrix();

    //Draw Cage Outline Top
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(4.95f, 2.9f, -9.8f);
    glScalef(3.0f, 1.0f, 1.0f);
    glLineWidth(9.0);
    glBegin(GL_LINES);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    //Draw Cage Outline Bottom
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(4.95f, 1.0f, -9.8f);
    glScalef(3.0f, 1.0f, 1.0f);
    glLineWidth(9.0);
    glBegin(GL_LINES);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    //Cages - Label

    //Cages - container
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(4.95f, 2.5f, -9.0f);
    glScalef(1.0f, 1.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.2f, 0.0f);
    glVertex3f(-0.5f, 0.2f, 0.0f);
    glEnd();
    glPopMatrix();

    //Cages - text
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    drawString2(4.1f, 2.3f, -8.0f, "Cages");
    glPopMatrix();

    //Draw pink character
glPushMatrix(); //Animation
    glTranslatef(0.4f, 0.08f, 0.0);
//    glScalef(2.0f,2.0f,1.0);
    glPushMatrix();
    //Draw head
        glPushMatrix();
            glTranslatef(0.4f, 1.9f, -7.0);
            glColor3f(0.95f, 0.8107f, 0.4275f);
            glutSolidSphere(0.4f, 20, 20);
        glPopMatrix();

    //Draw body
        glPushMatrix();
            glTranslatef(0.4f, 1.5f, -7.5);
            glScalef(0.4f, 0.4f, 1.0f);
            glBegin(GL_TRIANGLES);
            glColor3f(0.95f, 0.57f, 0.912f);
            glVertex3f(0.0f, 1.5f, 0.0f);
            glVertex3f(-1.5f, -1.5f, 0.0f);
            glVertex3f(1.5f, -1.5f, 0.0f);
            glEnd();
        glPopMatrix();

    //Draw legs
        glPushMatrix();
            glTranslatef(0.4f, 1.3f, -8.5);
            glColor3f(0.0, 0.0, 0.0);
            glLineWidth(1.5f);
            glBegin(GL_LINES);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(-0.5f, -0.5f, 0.0f);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.5f, -0.5f, 0.0f);
            glEnd();
        glPopMatrix();

    //Draw eyes
        glPushMatrix();
            glTranslatef(0.15f, 1.7f, -6.5);
            glColor3f(0.0, 0.0, 0.0);
            glScalef(0.1, 0.1, 1.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(0.0, 0.00, 0.0);
            glVertex3f(1.00, 2.00, 0.0);
            glVertex3f(2.00, 0.00, 0.0);
            glEnd();
        glPopMatrix();

    //Draw left hand

        glPushMatrix();
            glTranslatef(0.4f, 1.3f, -6.5);
            glColor3f(0.0, 0.0, 0.0);
            glLineWidth(1.5f);
            glScalef(1.7, 1.7, 1.0);
            glBegin(GL_LINES);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(-0.3f, -0.1f, 0.0f);
            glEnd();
        glPopMatrix();

    //Draw Right hand
        glPushMatrix();
            glTranslatef(0.2f, 1.8f, -8.5);
            glColor3f(0.0, 0.0, 0.0);
            glLineWidth(1.5f);
            glScalef(1.7, 1.7, 1.0);
            glBegin(GL_LINES);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(-0.3f, -0.1f, 0.0f);
            glEnd();
        glPopMatrix();

    glPopMatrix();

    //Draw dog
    glPushMatrix();
    glTranslatef(0.1f, 1.f, -5);
    glPushMatrix();
    glColor3f(0.97,0.8082,0.0873);
    glTranslatef(-0.7,-0.2,0);
    glScalef(0.3,0.3,1);
    glPushMatrix();
    glPushMatrix();//body
    glScalef(1.3,0.8,1);
    glTranslatef(-0.1,-0.2,0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.65,-0.5,0);
    glVertex3f(-0.75,0.5,0);
    glVertex3f(0.75,0.5,0);
    glVertex3f(0.65,-0.5,0);
    glEnd();
    glPopMatrix();
    //neck
    glPushMatrix();
    glScalef(1,0.6,1);
    glTranslatef(-1.1,0.5,0);
    glBegin(GL_POLYGON);
    glVertex3f(0.1,-0.5,0);
    glVertex3f(0.2,-0.25,0);
    glVertex3f(-0.15,0.5,0);
    glVertex3f(-0.2,0.25,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//head
    glTranslatef(-1.84,0.2,0);
    glRotatef(-50,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1,0,0);
    glVertex3f(0.1,0,0);
    glVertex3f(0.4,0.7,0);
    glVertex3f(-0.4,0.7,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//right ear
    glTranslatef(-1.6,0.85,0);
    glRotatef(55,0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.1,0,0);
    glVertex3f(0.1,0.2,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//left ear
    glTranslatef(-1.7,0.65,0);
    glRotatef(55,0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,0);
    glVertex3f(0,0.2,0);
    glVertex3f(0.2,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,-0.2,0);
    glRotatef(-20,0,0,1);
    glScalef(3,0.6,1);
    glBegin(GL_POLYGON);
    glVertex3f(0.1,-0.5,0);
    glVertex3f(0.2,-0.25,0);
    glVertex3f(-0.15,0.5,0);
    glVertex3f(-0.2,0.25,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//front-front leg
    glTranslatef(-0.8,-1,0);
    glRotatef(scene1_frontlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0.1,0,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0,0.1,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//front-back leg
    glTranslatef(-0.6,-1,-0.1);
    glRotatef(scene1_backlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//back-front leg
    glTranslatef(0.5,-1,0);
    glRotatef(scene1_frontlegdog,0,0,1);
    glScalef(1.5,7,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();//back-back leg
    glTranslatef(0.3,-1,-0.1);
    glRotatef(scene1_backlegdog,0,0,1);
    glScalef(1.5,10,1);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(0,0.1,0);
    glVertex3f(0.1,0.1,0);
    glVertex3f(0.1,0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1.7,0.5,0);
    glutSolidSphere(0.06,20,20);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();

glPopMatrix();

    /**Draw purple guy*/
    glPushMatrix();
    //Draw head
    glPushMatrix();
    glTranslatef(2.0f, 0.2f, -5.0);
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glutSolidSphere(0.5f, 20, 20);
    glPopMatrix();

    //Draw body
    glPushMatrix();
    glTranslatef(2.4f, -0.7f, -6.0);
    glScalef(0.8f, 0.8f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.1496f, 0.4418f, 0.88f);
    glVertex3f(0.0f, 1.5f, 0.0f);
    glVertex3f(-1.5f, -1.5f, 0.0f);
    glVertex3f(1.5f, -1.5f, 0.0f);
    glEnd();
    glPopMatrix();

    //Draw legs
    glPushMatrix();
    glTranslatef(2.3f, -1.8f, -7.0);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -1.f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -1.f, 0.0f);
    glEnd();
    glPopMatrix();

    //Draw eyes
    glPushMatrix();
    glTranslatef(1.5f, 0.2f, -4.5);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -0.15f, 0.0f);
    glEnd();
    glPopMatrix();

    //Draw eyebrow

    glPushMatrix();
    glTranslatef(1.4f, 0.25f, -4.5);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.3f, 0.1f, 0.0f);
    glEnd();
    glPopMatrix();

    //Draw left hand

    glPushMatrix();
    glTranslatef(1.6f, -0.5f, -4.5);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(1.5f);
    glScalef(2.5, 2.5, 1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -0.1f, 0.0f);
    glVertex3f(-0.3f, 0.0f, 0.0f);
    glEnd();
    glPopMatrix();

    //Draw Right hand
    glPushMatrix();
    glTranslatef(2.5f, -0.4f, -6.5);
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(1.5f);
    glScalef(3.5, 3.5, 1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -0.1f, 0.0f);
    glVertex3f(-0.3f, 0.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    //Stack of money - static
    glPushMatrix();

        glPushMatrix();
        glTranslatef(1.0f, -0.5f, -4.1);
        glColor3f(0.0, 1.0, 0.1);
        drawMoney();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.98f, -0.51f, -4.2);
        glColor3f(0.0, 0.87, 0.087);
        drawMoney();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.97f, -0.52f, -4.3);
        glColor3f(0.0747, 0.83, 0.1502);
        drawMoney();
        glPopMatrix();

        //right hand stack


        glPushMatrix();
        glTranslatef(1.2f, -0.3f, -4.2);
        glColor3f(0.0, 0.87, 0.087);
        drawMoney();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.25f, -0.31f, -4.3);
        glColor3f(0.0747, 0.83, 0.1502);
        drawMoney();
        glPopMatrix();
    glPopMatrix();

    //Dynamic Stack
    glPushMatrix();
        glPushMatrix();
        glTranslatef(moneytx, moneyty, -4.0);
        glColor3f(0.0, 1.0, 0.1);
        drawMoney();
        glPopMatrix();
    glPopMatrix();
glPopMatrix();

    glutSwapBuffers();

    //Translation increments
     if(moneytx<=0.88f && moneyty<=-0.4f){
        moneytx = 1.15f;
        moneyty = -0.28f;
     }
    else{
        moneytx-=0.01;
        moneyty-=0.006;
    }

    if(pinkguyx>=-1.0)
    pinkguyx-=0.01;
    else
        pinkguyx = 0.08;

}



void drawSignBoard(GLfloat signbody[],GLfloat signheader[])
{
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
    // Top face (y = 1.0f)
    glColor3f(signbody[0],signbody[1],signbody[2]);
    glVertex3f( 1.0f, 1.0f, -0.5f);
    glVertex3f(-1.0f, 1.0f, -0.5f);
    glVertex3f(-1.0f, 1.0f,  0.5f);
    glVertex3f( 1.0f, 1.0f,  0.5f);

    // Bottom face (y = -1.0f)

    glVertex3f(2.0f, -1.0f,  0.5f);
    glVertex3f(-2.0f, -1.0f,  0.5f);
    glVertex3f(-2.0f, -1.0f, -0.5f);
    glVertex3f( 2.0f, -1.0f, -0.5f);

    // Front face  (z = 1.0f)

    glVertex3f( 1.0f,  1.0f, 0.5f);
    glVertex3f(-1.0f,  1.0f, 0.5f);
    glVertex3f(-2.0f, -1.0f, 0.5f);
    glVertex3f( 2.0f, -1.0f, 0.5f);

    // Back face (z = -1.0f)

    glVertex3f( 2.0f, -1.0f, -0.5f);
    glVertex3f(-2.0f, -1.0f, -0.5f);
    glVertex3f(-1.0f,  1.0f, -0.5f);
    glVertex3f( 1.0f,  1.0f, -0.5f);

    // Left face (x = -1.0f)

    glVertex3f(-1.0f,  1.0f,  0.5f);
    glVertex3f(-1.0f,  1.0f, -0.5f);
    glVertex3f(-2.0f, -1.0f, -0.5f);
    glVertex3f(-2.0f, -1.0f,  0.5f);

    // Right face (x = 1.0f)

    glVertex3f(1.0f,  1.0f, -0.5f);
    glVertex3f(1.0f,  1.0f,  0.5f);
    glVertex3f(2.0f, -1.0f,  0.5f);
    glVertex3f(2.0f, -1.0f, -0.5f);
    glEnd();  // End of drawing color-cube
    glPopMatrix();
    //Header
    glPushMatrix();
    glColor3f(signheader[0],signheader[1],signheader[2]);
    glTranslatef(0.0f, 1.25f, 0.0f);
    glScalef(2,0.5,1.0);
    glutSolidCube(1.0);
    glPopMatrix();
    //legs
    glPushMatrix();
        glColor3f(0.76,0.5634,0.0228);
        glTranslatef(-1.0,-1.0,-.5);
        glScalef(0.5,1,0.5);
        glutSolidCube(1.0);
    glPopMatrix();
     glPushMatrix();
        glColor3f(0.76,0.5634,0.0228);
        glTranslatef(1.0,-1.0,-.25);
        glScalef(0.5,1,0.5);
        glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();


}

void drawPetShop(){
     glPushMatrix();

     glTranslatef(-3,2,-12.0f);
     glScalef(2.0,2.0f,2.0f);
    glPushMatrix();
    glTranslatef(5.0f, -2.0f, 0);
    glRotatef(-90.0,0.0f,1.0f,0.0f);
    glColor3f(1.0, 1.0, 0.0);
    glScalef(2.0f,2.0f,2.0f);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(5.0f, -1.0f, 0);
    glRotatef(180.0,0.0,1.0,0.0);
    glRotatef(-90.0,0.0f,1.0f,0.0f);
    glScalef(2.0,0.5,2.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();

}

void drawPetShopSignBoard(){

    glPushMatrix();
    glTranslatef(3.f, -2.5f, -12.0f);
    glRotatef(-45.0f,0.0f,1.0f,0.0f);
    glPushMatrix();
    GLfloat bodyColor[] = {0.9064f, 0.96f, 0.3168f};
    GLfloat headerColor[] = {0.69f, 0.5979f, 0.0759f};
    glScalef(0.5,0.5,0.5);
    drawSignBoard(bodyColor, headerColor);
    glPopMatrix();
    //Arrow
    glPushMatrix();
    glTranslatef(0.5, 0.1f, 0);
    glPushMatrix();//Arrow cuboid
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-0.1f, -0.2f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.2f, 0.0f);
    glVertex3f(-0.5f, 0.2f, 0.0f);
    glEnd();
    glPopMatrix();
    //Arrow Head
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-0.2f, -0.1f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(0.5f, 0.2f, 0.0f);
    glVertex3f(0.8f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.2f, 0.0f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(2.3f, -2.1f,0);
    glScalef(0.08,0.08,1.0);
  //  glRotatef(0,0,0,1);
    drawString("PET",0,0,-11);
    drawString("SHOP",0,-3.5,-11);
    glPopMatrix();
    glPopMatrix();
}

void drawPawsBoard(){
    glPushMatrix();//Paws Board
        glColor3f(1,1,1);
         glTranslatef(-2.0f, -0.2f, -12.5f);
         glRotatef(45.0,0.0f,1.0f,0.0f);
         glScalef(2.5,1.7,0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glLineWidth(3);
    glTranslatef(-2.5f,0.2f,-12);
    glScalef(0.1,0.1,1);
    drawString("P.A.W.S",0.2f, 0.f,1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,0);
    glLineWidth(3);
    glTranslatef(-2.4f,-0.1f,-12);
    glScalef(0.08,0.08,1);
    drawString("Adoption",0.f, 0.f,1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,0);
    glLineWidth(3);
    glTranslatef(-2.4f,-0.4f,-12);
    glScalef(0.08,0.08,1);
    drawString("Center",0.f, 0.f,1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glLineWidth(3);
    glTranslatef(-2.6f,-0.8f,-12);
    glScalef(0.08,0.08,1);
    drawString("Adopt Now!",0.f, 0.f,1);
    glPopMatrix();


}


void drawFence(){

  glPushMatrix();
    glTranslatef(0.f, 0.0f, -15.0f);
    glRotatef(45.0,0.0f,1.0f,0.0f);
    glColor3f(1,1,0);
    glScalef(0.8,2.5,0.2);
    glTranslatef(35.5f, -0.2f, 0.0f);//Initial
    for(int i=0;i<40;i++){//front facing fences
         glutSolidCube(1);
           glTranslatef(-1.5,0.00,0);
    }
    glPopMatrix();

}


void drawRoad(){

    glPushMatrix();//ROADDDDDDDDDDDDDDD
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(-w/2,-h/2,-30);
        glVertex3f(w/2,-h/2,-30);
        glVertex3f(w/2,-0.8,-30);//
        glVertex3f(-w/2,-3,-30);
        glEnd();

    glPopMatrix();

}


void drawShelter(){
    //Drawing the shelter
    glPushMatrix();
    glTranslatef(2.f, 1.8f, -20.0f);
    glRotatef(45.0,0.0f,1.0f,0.0f);
    glScalef(3.0f,2.5f,2.0f);
    glColor3f(0.0, 1.0, 1.0);
    glutSolidCube(2.0);
    glPopMatrix();

}

void drawGrassPatch(){
        glPushMatrix();
    glTranslatef(-15.f, -2.0f, -18.0f);
    glColor3f(0,1,0);
    glRotatef(90,1,0,0);
    glRotatef(43,0,0,1);
    glScalef(20,100,0.5);
    glutSolidCube(1);
    glPopMatrix();


}


void sceneSixDrawCharacter()
{
    glPushMatrix();//man
    //Draw head
    glPushMatrix();
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glTranslatef(0,0.4,0);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();

    glPushMatrix();//draw eye
    glColor3f(0, 0, 0);
    glScalef(0.2,0.2,0.2);
    glTranslatef(-0.5,2.0,0.9);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

     glPushMatrix();//draw eye
    glColor3f(0, 0, 0);
    glScalef(0.2,0.2,0.2);
    glTranslatef(0.5,2.0,0.9);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();

    //Draw body

    glPushMatrix();
    glColor3f(1,1,0.5);
    glScalef(0.4,0.6,0.4);
    glTranslatef(0,-0.1,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  //STUPID ARM
    glRotatef(75,0,0,1);
    glScalef(0.4,0.1,0.1);
    glTranslatef(0,3,0);
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();  //STUPID ARM
    glRotatef(-75,0,0,1);
    glScalef(0.4,0.1,0.1);
    glTranslatef(0,3,0);
    glColor3f(0.95f, 0.8107f, 0.4275f);
    glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();
    glRotatef(scene7_frontleg,0,0,1);//visible leg
    glTranslatef(0.1,-0.4,0.1);
    glColor3f(0,0,1);
    glScalef(0.15,0.5,0.15);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();//leg behind
    glRotatef(scene7_backleg,0,0,1);
    glTranslatef(-0.1,-0.4,0);
    glColor3f(0,0,1);
    glScalef(0.15,0.5,0.15);
    glutSolidCube(1.0);
    glPopMatrix();

}


void scene7display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    drawRoad();
    drawShelter();
    drawFence();
    drawGrassPatch();
    drawPetShop();
    drawPetShopSignBoard();
    drawPawsBoard();

    glPushMatrix();
    glColor3f(1,0,0);
        glTranslatef(movex,-1,-5);
        glRotatef(rotval,0,1,0);
        sceneSixDrawCharacter();
    glPopMatrix();


    glPopMatrix();
    glutSwapBuffers();

    if(rotval<260&&movex==1.5){
    rotval+=0.5;
    }
    else if(movex>-1.5)
        movex-=0.01;
    else{
        rotval=100;
        movex=1.5;
    }

}


void lastScene_display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 0.0f, -5.0f);  // Move right and into the screen
    glColor3f(0,0,0);
    glLineWidth(5);
    glPointSize(5);
    glPushMatrix();
    glColor3ub(214, 27, 11);
        glTranslatef(-3,2.5,0);
        glScalef(0.2,0.2,1);
        drawString1("WHY BREED OR BUY");
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
        glTranslatef(-2,1.8,0);
        glScalef(0.2,0.2,1);
        drawString1("WHILE THE");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.5,1.1,0);
        glColor3ub(214, 27, 11);
        glScalef(0.2,0.2,1);
        drawString1("HOMELESS DIE");
    glPopMatrix();

    glPushMatrix();//Paws logo
    glTranslatef(1,0,0);
    glPushMatrix();
    glTranslatef(-2,0,0);
    glColor3ub(214, 129, 11);
    glutSolidSphere(0.4,20,20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0.5,0);
    glColor3f(0.84,0.6006,0.042);
    glutSolidSphere(0.4,20,20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0);
    glColor3f(0.84,0.6006,0.042);
    glutSolidSphere(0.4,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,-1,0);
    glColor3f(0.84,0.6006,0.042);
    glutSolidSphere(0.8,20,20);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.5,-2.4,0);
        glColor3f(0.5075,0.042,0.84);
        glScalef(0.1,0.1,1);
        drawString1("PET ANIMAL WELFARE SOCIETY (PAWS)");
    glPopMatrix();
   glutSwapBuffers();
}


void adoptiondisplay(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 0.0f, -5.0f);  // Move right and into the screen
    glColor3f(0,0,0);
    glLineWidth(3);
    glPointSize(3);
	 glPushMatrix();
        glTranslatef(-2,2,0);
        glColor3f(0.5075,0.042,0.84);
        glScalef(0.1,0.1,1);
        drawString1("Go to your nearest");
    glPopMatrix();

        glPushMatrix();
        glColor3ub(96, 214, 11);
        glTranslatef(-3.5,1.2,0);
        glScalef(0.2,0.2,1);
        drawString1("Adoption Shelter");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5.5,0.0,0);
        glColor3ub(214, 11, 96);
        glScalef(0.1,0.1,1);
        drawString1("All the animals in the adoption shelter are rescued");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5.5,-0.4,0);
        glScalef(0.1,0.1,1);
        drawString1("from the streets. They\'re given a temporary residence");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5.5,-0.8,0);
        glScalef(0.1,0.1,1);
        drawString1("and care,waiting for someone like you to come along &");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.5,-2,0);
        glColor3ub(12, 237, 248);
        glScalef(0.2,0.2,1);
        drawString1("Give them a home");
    glPopMatrix();


   glutSwapBuffers();
}





void timer7(int value)
{
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(25, timer7, 0); // next timer call milliseconds later
}







/* Called back when timer expired */
void timer5(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(25, timer5, 0); // next timer call milliseconds later
}





void timer1(int value)
{
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(150, timer1, 0); // next timer call milliseconds later
}

void timer2(int value)
{
    glutPostRedisplay();


    if(scene2_offset>=-40 && scene2_offset<=30)
        scene2_offset-=10;
    else
        scene2_offset=30;
    glutTimerFunc(125,timer2,0);
}


void timer4(int value)
{
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(150, timer4, 0); // next timer call milliseconds later
}

void perspectiveReshape(GLsizei width, GLsizei height) { // GLsizeifor non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1; // To prevent divide by 0
    GLfloat aspect = (GLfloat) width / (GLfloat) height;

    // Set the view port to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the view port
    glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
    glLoadIdentity(); // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void orthoReshape(GLsizei width, GLsizei height) {
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
    w=width;
    h=height;
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();


   if (width >= height) {

      glOrtho(-3.0 * aspect, 3.0 * aspect, -3.0, 3.0, 0.1, 100);
   } else {
     glOrtho(-3.0, 3.0, -3.0 / aspect, 3.0 / aspect, 0.1, 100);
   }
}



void keyPress(int key, int x, int y) {
	switch (key) {
		// Go to Previous Scene
	case GLUT_KEY_LEFT:
	case GLUT_KEY_UP:
		if (sceneNo == 1)
			break;
		sceneNo--;
		break;
		// Go to Next Scene
	case GLUT_KEY_RIGHT:
	case GLUT_KEY_DOWN:
		if (sceneNo == 10)
			break;
		sceneNo++;
		break;
		// Quit Story
	case GLUT_KEY_END:
	case GLUT_KEY_F4:
		exit(0);
		break;
	default:
		break;
	}

	renderScene();
}



void initGL1() {
    glutCreateWindow("Introduction");          // Create window with the given title
   glutDisplayFunc(introductionDisplay);       // Register callback handler for window re-paint event
   glutReshapeFunc(orthoReshape);       // Register callback handler for window re-size event
   glutSpecialFunc(keyPress);
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void initGL2(){

    glutDisplayFunc(sceneOneDisplay); // Register callback handler for window re-paint event
    glutReshapeFunc(orthoReshape); // Register callback handler for window re-size event
   glutSpecialFunc(keyPress);
     glutTimerFunc(0, timer1, 0);
    glClearColor(0.098, 0.98, 0.98, 1.0f);
    glClearDepth(1.0f); // Set background depth tofarthest
    glEnable(GL_DEPTH_TEST); // Enable depth testingfor z-culling
    glDepthFunc(GL_LEQUAL); // Set the type of depth-test
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

void initGL3(){
    glutCreateWindow("scene2");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	// Enable Smoothening
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	// Display Function
	glutDisplayFunc(scene2display);


    glClearColor(1,1,1,1);
    initializeScreen();
    glutSpecialFunc(keyPress);
    glutTimerFunc(25, timer2, 0);

}

void initGL4(){
glutCreateWindow("Scene 4"); // Create window with the given title
    glutDisplayFunc(sceneFourDisplay); // Register callback handler for window re-paint event
    glutReshapeFunc(orthoReshape);
    glutSpecialFunc(keyPress);
     glutTimerFunc(0, timer4, 0);
      glClearColor(0.41, 0.9607, 1, 1.0f);
    glClearDepth(1.0f); // Set background depth tofarthest
    glEnable(GL_DEPTH_TEST); // Enable depth testingfor z-culling
    glDepthFunc(GL_LEQUAL); // Set the type of depth-test
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

void initGL5(){
     glutCreateWindow("But before you buy");          // Create window with the given title
   glutDisplayFunc(sceneButBeforedisplay);       // Register callback handler for window re-paint event
   glutReshapeFunc(orthoReshape);
    glutSpecialFunc(keyPress);
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


void initGL6(){
     glutCreateWindow("Scene 5"); // Create window with the given title
    glutDisplayFunc(moneymakerDisplay); // Register callback handler for window re-paint event
    glutReshapeFunc(perspectiveReshape);
    glutTimerFunc(0, timer5, 0);
    glutSpecialFunc(keyPress);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearDepth(1.0f); // Set background depth tofarthest
    glEnable(GL_DEPTH_TEST); // Enable depth testingfor z-culling
    glDepthFunc(GL_LEQUAL); // Set the type of depth-test
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}


void initGL8(){
     glutCreateWindow("Scene 7"); // Create window with the given title
    glutDisplayFunc(scene7display); // Register callback handler for window re-paint event
    glutReshapeFunc(perspectiveReshape); // Register callback handler for window re-size event
     glutTimerFunc(0, timer7, 0);
    glutSpecialFunc(keyPress);
    glClearColor(0.0356, 0.8615, 0.89, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    addLight();


}

void initGL9(){
    glutCreateWindow("Logo");
    glutDisplayFunc(lastScene_display);       // Register callback handler for window re-paint event
   glutReshapeFunc(orthoReshape);       // Register callback handler for window re-size event
    glutSpecialFunc(keyPress);
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


void initGL7(){
glutCreateWindow("Adoption Shelter");
    glutDisplayFunc(adoptiondisplay);       // Register callback handler for window re-paint event
   glutReshapeFunc(orthoReshape);       // Register callback handler for window re-size event
  glutSpecialFunc(keyPress);
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

}



void renderScene(){
    switch(sceneNo){
    case 1:
        initGL1();
        break;
    case 2:
        initGL2();
        break;
    case 3:
        initGL3();
        break;
    case 4:
        initGL4();
        break;
         case 5:
        initGL5();
        break;
     case 6:
        initGL6();
        break;
    case 7:
        initGL7();
        break;
    case 8:
        initGL8();
        break;
	case 9:
		initGL9();
		break;
	default:
		break;

    }

}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
    glutInitWindowSize(1360, 720);
    glutInitWindowPosition(0, 0);
    renderScene();
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
