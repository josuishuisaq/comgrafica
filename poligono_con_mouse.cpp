 #include <GL/glut.h>  
 #include <cmath>  

void display()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int a=700;
int b=700;
int primero=0;

typedef struct{  
   float x;  
   float y;  
 }Punto2d; 
Punto2d p1,p2,p3,p4;

void dibujarPoligono(Punto2d pt1,Punto2d pt2,Punto2d pt3,Punto2d pt4)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
            glVertex2i(pt1.x,pt1.y);
            glVertex2i(pt2.x,pt2.y);
            glVertex2i(pt3.x,pt3.y);
            glVertex2i(pt4.x,pt4.y);
        glEnd();
        glFlush();
}
void mouse(int btn, int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON)
        if(state==GLUT_DOWN)
        {
            switch(primero)
            {
                case 0:
                    p1.x=x;
                    p1.y=(b-y);
                    primero=1;
                    break;

                case 1:
                    p2.x=x;
                    p2.y=b-y;
                    primero=2;
                    break;
                case 2:
                    p3.x=x;
                    p3.y=b-y;
                    primero=3;
                    break;
                case 3:
                    p4.x=x;
                    p4.y=b-y;
                    primero=0;
                    dibujarPoligono(p1,p2,p3,p4);
                    break;

            }
        }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitWindowSize(a,b);
    glutCreateWindow("poligono con mouse");
    gluOrtho2D(0.0,(GLdouble)a,0.0,(GLdouble)b);  
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}