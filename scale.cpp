#include <GL/glut.h> 
void initGL() { 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0); 
	glViewport(0,0,1000,1000);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
}
 
void display() {
	glClear(GL_COLOR_BUFFER_BIT); 
	glLineWidth(4.0);
	GLdouble x,y;
	
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
 

			glLoadIdentity(); 
			glTranslated(x, y, 0.0); 
			
			glBegin(GL_POLYGON); 
				glColor3f(0.0, 0.0, 0.0); 
				glVertex2i(50,0);
				glVertex2i(100,50);
				glVertex2i(50,100);
				glVertex2i(0,50);
			glEnd();

			x+=200.0;
			y+=200.0;

            int xs=2;
            int ys=2;

			glLoadIdentity(); 
			glTranslated(x, y, 0.0); 
			
			glBegin(GL_POLYGON); 
				glColor3f(0.0, 0.0, 0.0); 
				glVertex2i(50*xs,0*ys);
				glVertex2i(100*xs,50*ys);
				glVertex2i(50*xs,100*ys);
				glVertex2i(0*xs,50*ys);
			glEnd();

	glFlush();
}


int main(int argc, char** argv) {
	
	glutInit(&argc, argv); 
	glutCreateWindow("Scale"); 
	glutInitWindowSize(640, 480); 
	glutInitWindowPosition(50, 50); 
	initGL();
	glutDisplayFunc(display); 
	glutMainLoop(); 
	return 0;
	
}
