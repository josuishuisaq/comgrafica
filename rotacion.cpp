
#include <GL/glut.h>  
 

char title[] = "Rotar";
 
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);                   
   glEnable(GL_DEPTH_TEST);   
   glDepthFunc(GL_LEQUAL);    
   glShadeModel(GL_SMOOTH);  
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}
 
GLfloat angle = 45.0f;
int refreshmill=1;

void timer(int value)
{
   glutPostRedisplay();
   glutTimerFunc(refreshmill, timer, 0);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT ); 
   glMatrixMode(GL_MODELVIEW);    
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

   glLoadIdentity();                 
   glPushMatrix();
   glTranslatef(0.5f, 0.0f, 0.0f); 
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glBegin(GL_QUADS);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(0.3f, 0.3f);
   glVertex2f(-0.3f, 0.3f);
   glVertex2f(-0.3f, -0.3f);
   glVertex2f(0.3f, -0.3f);
   glEnd();
   glPopMatrix();
   glutSwapBuffers();
   angle+=0.2;
 
}
 

void reshape(GLsizei width, GLsizei height) { 
   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();            
   if(width>=height)
   {
      gluOrtho2D(-1.0*aspect, 1.0*aspect, -1.0, 1.0);
   }
   else
   {
      gluOrtho2D(-1.0,1.0,-1.0/aspect, 1.0/aspect);   
   }
  
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);            

   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow(title);         
   glutDisplayFunc(display);      
   glutReshapeFunc(reshape);       
   glutTimerFunc(0,timer,0);
   //initGL();                    
   glutMainLoop();                 
   return 0;
}