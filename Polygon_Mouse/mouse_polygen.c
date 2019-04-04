#include<GL/glut.h> //includes the opengl, glu, and glut header files
#include<stdlib.h> //includes the standard library header file

int x[50],y[50],i=1,j=1;

void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {


        x[i] = mousex;
        y[i] = 480-mousey;

        i++;
        }

   else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)//undo(clear)the drawing
           {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
     }
glutPostRedisplay();
     }

void display(void)
{
    glColor3f(1,0,0); // sets the current drawing (foreground) color to blue
    glPointSize(2); // sets the size of points to be drawn (in pixels)

    glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
    glLoadIdentity();//multiply the current matrix by identity matrix
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);//sets the parallel(orthographic) projection of the full frame buffer

  for (int k=0;k<=i;k++)
{

       glBegin(GL_LINES); // writes pixels on the frame buffer with the current drawing color
       glVertex2i(x[k],y[k]);   // sets vertex
       glVertex2i(x[k+1],y[k+1]);
       glEnd();
}

    glFlush();     // flushes the frame buffer to the screen
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize(640,480);   //sets the width and height of the window in pixels
    glutInitWindowPosition(10,10);//sets the position of the window in pixels from top left corner
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
    glutCreateWindow("DDA Line Drawing");//creates the window as specified by the user as above.

    glClearColor(1, 1, 1, 0); // sets the backgraound color to white light
    glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call

    glutDisplayFunc(display);//links the display event with the display event handler(display)
    glutMouseFunc(mouse);//keyboard event handler
    glutMainLoop();//loops the current event
}
