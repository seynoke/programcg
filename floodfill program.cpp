#include <GL/glut.h>
#include <iostream>
using namespace std;

struct Color {
    float r, g, b;
};

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}


void setPixelColor(int x, int y, Color color) {
    glColor3f(color.r, color.g, color.b); 
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}


bool isInsidePolygon(int x, int y) {
    return (x >= 250 && x <= 300 && y >= 250 && y <= 300);
}


void floodFill(int x, int y, Color oldColor, Color newColor) {
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);

   
    if (x < 0 || x >= 500 || y < 0 || y >= 500) return;
    if (color.r != oldColor.r || color.g != oldColor.g || color.b != oldColor.b) return;

    setPixelColor(x, y, newColor);

    
    floodFill(x + 1, y, oldColor, newColor);
    floodFill(x - 1, y, oldColor, newColor);
    floodFill(x, y + 1, oldColor, newColor);
    floodFill(x, y - 1, oldColor, newColor);
}


void onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Color newColor = {0.0f, 1.0f, 0.0f};  
        Color oldColor = {0.0f, 0.0f, 0.0f}; 

        if (isInsidePolygon(x, 500 - y)) {  
            floodFill(x, 500 - y, oldColor, newColor);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);  

    glBegin(GL_LINE_LOOP);
    glVertex2i(250, 250);
    glVertex2i(250, 300);
    glVertex2i(300, 300);
    glVertex2i(300, 250);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    cout << "Click inside the square to fill it with green." << endl;

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

