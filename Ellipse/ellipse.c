 #include<stdio.h>
 #include<GL/glut.h>
#include<stdlib.h>

int pntX1, pntY1,rx,ry;
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.9f, 0.3f, 0.6f);
	glPointSize(1.0);

	ellipse(pntX1,pntY1,rx,ry);

	glFlush ();
}

 void ellipse(int xc,int yc,int rx,int ry)
 {
   //int gm=DETECT,gd;
   int x, y, p;

   x=0;
   y=ry;
   p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
   while((2*x*ry*ry)<(2*y*rx*rx))
   {
        plot(xc+x,yc-y);
        plot(xc-x,yc+y);
        plot(xc+x,yc+y);
        plot(xc-x,yc-y);

        if(p<0)
        {
     x=x+1;
     p=p+(2*ry*ry*x)+(ry*ry);
        }
        else
        {
     x=x+1;
     y=y-1;
     p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
        }
   }
   p=((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;

         while(y>=0)
   {
        plot(xc+x,yc-y);
        plot(xc-x,yc+y);
        plot(xc+x,yc+y);
        plot(xc-x,yc-y);

        if(p>0)
        {
     y=y-1;
     p=p-(2*rx*rx*y)+(rx*rx);

        }
        else
        {
     y=y-1;
     x=x+1;
     p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
        }
   }

 }

 int main(int argc, char** argv)
 {


   printf("Enter Xc=");
   scanf("%d",&pntX1);
   printf("Enter Yc=");
   scanf("%d",&pntY1);
   printf("Enter Rx=");
   scanf("%d",&rx);
   printf("Enter Ry=");
   scanf("%d",&ry);
   glutInit(&argc, argv);
   	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   	glutInitWindowSize (640, 480);
   	glutInitWindowPosition (100, 150);
   	glutCreateWindow ("Midpoint Ellipse Drawing Alogrithms");
   	glutDisplayFunc(myDisplay);
   	myInit ();
   	glutMainLoop();

 }








