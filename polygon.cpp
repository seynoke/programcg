#include &lt;GL/glut.h&gt;
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(-0.5, -0.5);
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f(0.5, -0.5);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex2f(-0.5, 0.5);
glEnd();
glFlush();
}
int main (int args, char** argv)
{
glutInit(&amp;args, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(900, 900);
glutCreateWindow(&quot;OpenGl Polygon Example&quot;);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}