#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include &lt;GL/gl.h&gt;
#include &lt;GL/glut.h&gt;
float x1,x2,Y1,y2;
void display(void){
float dy,dx,step,x,y,k,Xin,Yin;
dx=x2-x1;
dy=y2-Y1;
if(abs(dx)&gt;abs(dy)){
step=abs(dx);
}
else{
step=abs(dy);
Xin=dx/step;
Yin=dy/step;
x=x1;
y=Y1;
glColor3f(0.0,1.0,0.0);
glEnable(GL_LINE_STIPPLE);
glLineStipple(0,0x5555);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
for(k=1;k&lt;=step;k++){
x=x+Xin;
y=y+Yin;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
glFlush();
}
void myInit(void){
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0);
}
int main(int argc, char**argv){
printf(&quot;Value of x1:&quot;);
scanf(&quot;%f&quot;,&amp;x1);
printf(&quot;Value of x2:&quot;);
scanf(&quot;%f&quot;,&amp;x2);
printf(&quot;Value of y1:&quot;);
scanf(&quot;%f&quot;,&amp;Y1);

printf(&quot;Value of y2:&quot;);
scanf(&quot;%f&quot;,&amp;y2);
glutInit(&amp; argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,150);
glutCreateWindow(&quot;&quot;);
myInit();
glutDisplayFunc(display);
glutMainLoop();
}