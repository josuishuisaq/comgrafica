#include <time.h> 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
  
void delay(unsigned int mseconds) 
{ 
    clock_t goal = mseconds + clock(); 
    while (goal > clock()) 
        ; 
} 

void myInit (void) 
{ 

    glClearColor(0.0, 0.0, 0.0, 1.0); 

    glMatrixMode(GL_PROJECTION);  
      
    gluOrtho2D(-5, 5, -5, 5); 
} 
  
void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 

  glColor3f(1.0,1.0,0.0);

    glRotated(4.0, 1.0, 1.0, 0.0);

    glBegin(GL_LINES);
    glVertex2i(-3, -2);
    glVertex2i(4, 3);
    glEnd();

    glFlush();

    delay(10); 
} 
  
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    glutInitWindowSize(600, 450); 
    glutInitWindowPosition(200, 200); 
      
    glutCreateWindow("LINEA 2D"); 
    myInit(); 
    glBegin(GL_LINES);
    glVertex2f(30, 30);
    glVertex2f(60, 60);
    glEnd();
      
    glutDisplayFunc(display); 
    glutMainLoop(); 
    
    return 0;
} 