#include <stdio.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

int option = 1;

struct Point {
    int x;
    int y;
};

struct Color {
    float r, g, b;
};

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Black background
    glColor3f(1.0, 1.0, 1.0);  // White color for points
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

Color getPixelColor(int x, int y) {
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void setPixelColor(int x, int y, Color color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void boundaryFill(int x, int y, Color fColor, Color bColor) {
    Color color = getPixelColor(x, y);

    // If the pixel is not the boundary color and not the fill color, fill it
    if ((color.r != fColor.r || color.g != fColor.g || color.b != fColor.b) &&
        (color.r != bColor.r || color.g != bColor.g || color.b != bColor.b)) {
        setPixelColor(x, y, fColor);

        // Recursively call boundary fill for adjacent pixels
        boundaryFill(x + 1, y, fColor, bColor);
        boundaryFill(x, y + 1, fColor, bColor);
        boundaryFill(x - 1, y, fColor, bColor);
        boundaryFill(x, y - 1, fColor, bColor);
    }
}

// This function checks if a point (x, y) is inside the polygon
bool isInsidePolygon(int x, int y) {
    // Check if the point (x, y) is inside the square with vertices (250, 250), (250, 300), (300, 300), (300, 250)
    // You can expand this function for more complex polygons
    return (x >= 250 && x <= 300 && y >= 250 && y <= 300);
}

void onMouseClick(int button, int state, int x, int y) {
    Color fColor = {0.0f, 1.0f, 0.0f};  // Fill color (green)
    Color bColor = {1.0f, 1.0f, 1.0f};  // Boundary color (white)

    // Adjust y-axis for OpenGL coordinate system
    if (isInsidePolygon(x, 500 - y)) {
        boundaryFill(x, 500 - y, fColor, bColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a simple polygon (square) to test the boundary fill
    glBegin(GL_LINE_LOOP);
    glVertex2i(250, 250);
    glVertex2i(250, 300);
    glVertex2i(300, 300);
    glVertex2i(300, 250);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Polygon Filling");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(onMouseClick);

    glutMainLoop();
    return 0;
}
