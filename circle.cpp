#include <GL/glut.h>
#include <cmath>  // for sin, cos, M_PI

void draw_ring_sector(float XCenter, float YCenter, float radius, float width, float startang, float endang) {
    float radius1 = radius - width / 2;
    float radius2 = radius + width / 2;

    glBegin(GL_LINE_LOOP);

    for (float i = startang; i <= endang; i += 1.0f) {
        float ang = i * M_PI / 180.0f;  // convert degrees to radians
        glVertex2f(XCenter + cos(ang) * radius1, YCenter + sin(ang) * radius1);
    }

    for (float i = endang; i >= startang; i -= 1.0f) {
        float ang = i * M_PI / 180.0f;
        glVertex2f(XCenter + cos(ang) * radius2, YCenter + sin(ang) * radius2);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // black
    glLineWidth(2.0f);
    
    // Draw a ring sector
    draw_ring_sector(200, 150, 50, 20, 0, 180); // center at (200,150), radius 50, width 20, 0° to 180°
    
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    gluOrtho2D(0.0, 400.0, 0.0, 300.0); // 2D projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ring Sector Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
