#include &lt;GL/glut.h&gt;
#include &lt;math.h&gt;
void plotCirclePoints(int x_center, int y_center, int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x_center + x, y_center + y);
glVertex2i(x_center - x, y_center + y);
glVertex2i(x_center + x, y_center - y);
glVertex2i(x_center - x, y_center - y);
glVertex2i(x_center + y, y_center + x);
glVertex2i(x_center - y, y_center + x);
glVertex2i(x_center + y, y_center - x);
glVertex2i(x_center - y, y_center - x);
glEnd();
}
void drawCircle(int x_center, int y_center, int radius)
{
int x = 0;
int y = radius;
int p = 3 - 2 * radius;
plotCirclePoints(x_center, y_center, x, y);
while (x &lt;= y)
{
x++;
if (p &lt;= 0)
{
p = p + 4 * x + 6;
}
else
{
y--;
p = p + 4 * (x - y) + 10;
}
plotCirclePoints(x_center, y_center, x, y);
}
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);

drawCircle(0, 0, 100);
glFlush();
}
int main(int argc, char** argv)
{
glutInit(&amp;argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(900, 900);
glutCreateWindow(&quot;Bresenham&#39;s Circle Algorithm&quot;);
glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
glOrtho(-400, 400, -400, 400, -1, 1);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}