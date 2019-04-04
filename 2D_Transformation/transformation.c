#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int a,b,c,d,tx,ty;
void init(void)
{
 glClearColor(0.0,0.0,0.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,200.0,0.0,200.0);
}
void setpoint(GLint x,GLint y)
{
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
}
void transform(int x,int y,int tx,int ty)
{
 glColor3f (0.0, 1.0, 0.0);
 setpoint(x+tx,y+ty);
 glColor3f (255.0, 255.0, 255.0);
}
int round1(double number)
{
 return (number>=0) ? (int)(number+0.5):(int)(number-0.5);
}
void LineWithDDA(int x0,int y0,int x1,int y1)
{
 int dy=y1-y0;
 int dx=x1-x0;
 int steps,i;
 float xinc,yinc,x=x0,y=y0;
 if(abs(dx)>abs(dy))
 {
  steps=abs(dx);
 }
 else
 {
  steps=abs(dy);
 }
 xinc=(float)dx/(float)steps;
 yinc=(float)dy/(float)steps;
 setpoint(round1(x),round1(y));
 transform(round1(x),round1(y),tx,ty);
 for(i=0;i<steps;i++)
 {
  x+=xinc;
  y+=yinc;
  setpoint(round1(x),round1(y));
  transform(round1(x),round1(y),tx,ty);
 }
 glutSwapBuffers();
}
void draw()
{

 glClear(GL_COLOR_BUFFER_BIT);
 LineWithDDA(a,b,c,d);
 glFlush();
}
int main(int argc,char **argv)
{

 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,50);
 glutInitWindowSize(500,500);

 printf("Enter x1 : ");
 scanf("%d",&a);
 printf("Enter y1 : ");
 scanf("%d",&b);
 printf("Enter x2 : ");
 scanf("%d",&c);
 printf("Enter y2 : ");
 scanf("%d",&d);
 printf("Enter tx : ");
 scanf("%d",&tx);
 printf("Enter ty : ");
 scanf("%d",&ty);

 glutCreateWindow("line translation...");
 init();
 glutDisplayFunc(draw);
 glutMainLoop();
 return 0;
}


