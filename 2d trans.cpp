#include <GL/gl.h>
#include <GL/glut.h>
struct Point2D {
float x, y;
};
Point2D startPoint = {-1.0f, -2.0f};
Point2D endPoint = {4.0f, 5.0f};
Point2D translationVector = {10.0f, -5.0f};
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
// Original Line (Red)
glColor3f(1.0f, 0.0f, 0.0f); // Red
glBegin(GL_LINES);
glVertex2f(startPoint.x, startPoint.y);
glVertex2f(endPoint.x, endPoint.y);
glEnd();
// Translated Line (Blue)
glColor3f(0.0f, 0.0f, 1.0f); // Blue
glBegin(GL_LINES);
glVertex2f(startPoint.x + translationVector.x, startPoint.y + translationVector.y);
glVertex2f(endPoint.x + translationVector.x, endPoint.y + translationVector.y);
glEnd();
glutSwapBuffers();
}
void init() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // black background
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-20, 20, -20, 20, -20, 20); // Orthographic projection
glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(500, 500);
glutCreateWindow("2D Line Translation");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
2D1.cpp
Displaying 2D1.cpp.
2D Translation 
Dipika Tidke
•
12 Apr

2D1.cpp
C++
Class comments

Add class comment…