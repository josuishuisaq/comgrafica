#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float Angulo = 0.0f;

float lx=0.0f,lz=-1.0f, ly = 0.0f;

float x=0.0f, z=5.0f, y = 1.75f;

float alfAngulo = 0.0f;
float alfMove = 0;
int xOrigin = -1;

int h,w;

int frame;
long time, timebase;
char s[50];

int mainWindow, subWindow1;
int border = 6;

void setProjection(int w1, int h1)
{
	float ratio;

	ratio = 1.0f * w1 / h1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

        glViewport(0, 0, w1, h1);

	gluPerspective(45,ratio,0.1,1000);
	glMatrixMode(GL_MODELVIEW);
}

void changeSize(int w1,int h1) {

	if(h1 == 0)
		h1 = 1;

	w = w1;
	h = h1;

	glutSetWindow(subWindow1);
	glutPositionWindow(border,border);
	glutReshapeWindow(w-2*border, h - border*3/2);
	setProjection(w-2*border, h/2 - border*3/2);

}

void drawSnowMan() {

	glColor3f(0.0f, 1.0f, 0.0f);

	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);
}

void ajustarBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

	char *c;
	glRasterPos3f(x, y,z);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
}

void setOrthographicProjection() {

	glMatrixMode(GL_PROJECTION);

	glPushMatrix();

	glLoadIdentity();

	gluOrtho2D(0, w, h, 0);

	glMatrixMode(GL_MODELVIEW);
}

void computePos(float alfMove) {

	x += alfMove * lx * 0.1f;
	z += alfMove * lz * 0.1f;
}

void ajustarScene2() {


	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++)
		{
			glPushMatrix();
			glTranslatef(i*10.0f, 0.0f, j * 10.0f);
			drawSnowMan();
			glPopMatrix();
		}
}

void ajustarScene() {
	glutSetWindow(mainWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void ajustarScenesw1() {

	glutSetWindow(subWindow1);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x, y, z,
		  x + lx,y + ly,z + lz,
		  0.0f,1.0f,0.0f);

	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(x,y,z);
	glRotatef(180-(Angulo+alfAngulo)*180.0/3.14,0.0,1.0,0.0);
	glutSolidCone(0.2,0.8f,4,4);
	glPopMatrix();

	ajustarScene2();

	glutSwapBuffers();

}


void ajustarSceneAll() {

	if (alfMove) {
		computePos(alfMove);
		glutSetWindow(mainWindow);
		glutPostRedisplay();
	}

	ajustarScene();
	ajustarScenesw1();

}

void processNormalKeys(unsigned char key, int xx, int yy) {

	if (key == 27) {
		glutDestroyWindow(mainWindow);
		exit(0);
	}
}

void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_UP : alfMove = 0.5f; break;
		case GLUT_KEY_DOWN : alfMove = -0.5f; break;
	}
	glutSetWindow(mainWindow);
	glutPostRedisplay();

}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : alfMove = 0;break;
	}
}


void init() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
    glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	mainWindow = glutCreateWindow("Mover objeto con teclado");

	glutDisplayFunc(ajustarSceneAll);
	glutReshapeFunc(changeSize);

	glutIdleFunc(ajustarSceneAll);
	init();

	subWindow1 = glutCreateSubWindow(mainWindow, border,border,w-2*border, h/2 - border*3/2);
	glutDisplayFunc(ajustarScenesw1);
	init();

	glutMainLoop();
	
	return 1;
}