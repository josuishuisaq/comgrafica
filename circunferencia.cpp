#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, r;

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void trazar(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}

void punto_medio_circulo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	trazar(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		trazar(x, y);
		trazar(x, -y);
		trazar(-x, y);
		trazar(-x, -y);
		trazar(y, x);
		trazar(-y, x);
		trazar(y, -x);
		trazar(-y, -x);
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	punto_medio_circulo();

	glFlush ();
}

int main(int argc, char** argv)
{	
	 /*   
    AL habilitar ésta parte el usuario puede ingresar sus coordenadas

    cout << "Entrar coordenadas y radio:\n\n" << endl;
   	cout << "Coordenada X   : "; cin >> pntX1;
	cout << "\nCoordena Y : "; cin >> pntY1;
	cout << "\nRadio : "; cin >> r;
    */    
    pntX1=150;
    pntY1=200;
    r=100;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Circulo con punto medio");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}