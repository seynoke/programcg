#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1, x2;
float y1_old, y2_old; // Renamed to avoid conflict
void display(void) {
float dx, dy, p, x, y;
dx = x2 - x1;
dy = y2_old - y1_old;
// Initialize decision parameter
p = (2 * dy)- dx;
// Set initial point (x1, y1_coord)
x = x1;
y = y1_old;
glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
glBegin(GL_POINTS);
glVertex2i(x, y); // Plot the starting point
glEnd();
// Bresenham's line algorithm
while (x < x2) {
if (p < 0) {
p = p + (2 * dy); // Move horizontally
x++;
} else {
p = p + 2 * (dy - dx); // Move diagonally
x++;
y++; // Increment y if the line goes up
}
glBegin(GL_POINTS);
glVertex2i(x, y); // Plot the current point
glEnd();
}
glFlush(); // Ensure all OpenGL commands are executed
glutSwapBuffers(); // Swap buffers if double buffering is used
}
void myInit(void) {
glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
glMatrixMode(GL_PROJECTION); // Set up projection matrix
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set 2D orthogonal projection
}

int main(int argc, char **argv) {
printf("Value of x1 : ");
scanf("%f", &x1);
printf("Value of y1 : ");
scanf("%f", &y1_old); // Updated with renamed variable
printf("Value of x2 : ");
scanf("%f", &x2);
printf("Value of y2 : ");
scanf("%f", &y2_old); // Updated with renamed variable
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Enable double buffering
glutInitWindowSize(640, 480);
glutInitWindowPosition(100, 150);
glutCreateWindow("Bresenham's Line Drawing");
myInit();
glutDisplayFunc(display);
glutMainLoop();
}