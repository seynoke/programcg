#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define MAX 10

int choice, choice1, choice2;
int vertices, x[MAX], y[MAX];
int i, xaux[MAX], yaux[MAX];
int line_x[2], c;
float slope;

void init() {
    glClearColor(0.101, 1.0, 0.980, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (choice == 4) {
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glVertex2f(0, 500); glVertex2f(0, -500);
        glVertex2f(-500, 0); glVertex2f(500, 0);
        glEnd();
    }

    if (choice1 == 3 || choice1 == 4) {
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glVertex2f(500, 500); glVertex2f(-500, -500);
        glVertex2f(-500, 500); glVertex2f(500, -500);
        glEnd();
    }

    if (choice1 == 6) {
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glVertex2f(line_x[0], ((slope * line_x[0]) + c));
        glVertex2f(line_x[1], ((slope * line_x[1]) + c));
        glEnd();
    }

    glLineWidth(5.0);
    glBegin(GL_LINE_LOOP); 
    glColor3f(0, 0, 0);
    for (i = 0; i < vertices; i++)
        glVertex2f(x[i], y[i]);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 0, 0);
    for (i = 0; i < vertices; i++)
        glVertex2f(xaux[i], yaux[i]);
    glEnd();

    glFlush();
}

void translation() {
    int dx, dy;
    printf("\n\nTRANSLATION\nEnter translation factor (dx dy): ");
    scanf("%d%d", &dx, &dy);
    for (i = 0; i < vertices; i++) {
        xaux[i] += dx;
        yaux[i] += dy;
    }
}

void rotation() {
    int x_pivot, y_pivot, angle, x_shifted, y_shifted;
    printf("\n\nROTATION\nEnter pivot point: ");
    scanf("%d %d", &x_pivot, &y_pivot);
    printf("Enter angle of rotation (in degree): ");
    scanf("%d", &angle);
    for (i = 0; i < vertices; i++) {
        x_shifted = xaux[i] - x_pivot;
        y_shifted = yaux[i] - y_pivot;
        xaux[i] = x_pivot + (x_shifted * cos(angle * 3.14 / 180) - y_shifted * sin(angle * 3.14 / 180));
        yaux[i] = y_pivot + (x_shifted * sin(angle * 3.14 / 180) + y_shifted * cos(angle * 3.14 / 180));
    }
}

void scaling() {
    int x_scale, y_scale;
    printf("\n\nSCALING\nEnter the scaling factor: ");
    scanf("%d %d", &x_scale, &y_scale);
    for (i = 0; i < vertices; i++) {
        xaux[i] *= x_scale;
        yaux[i] *= y_scale;
    }
}

void x_axis() {
    for (i = 0; i < vertices; i++)
        yaux[i] = -yaux[i];
}

void y_axis() {
    for (i = 0; i < vertices; i++)
        xaux[i] = -xaux[i];
}

void y_equal_xp() {
    for (i = 0; i < vertices; i++) {
        xaux[i] = y[i];
        yaux[i] = x[i];
    }
}

void y_equal_xn() {
    for (i = 0; i < vertices; i++) {
        xaux[i] = -y[i];
        yaux[i] = -x[i];
    }
}

void origin() {
    for (i = 0; i < vertices; i++) {
        xaux[i] = -xaux[i];
        yaux[i] = -yaux[i];
    }
}

void straight_line() {
    printf("\n\nREFLECTION ALONG A STRAIGHT LINE\nEnter x1: ");
    scanf("%d", &line_x[0]);
    printf("Enter x2: ");
    scanf("%d", &line_x[1]);
    printf("Enter slope (m): ");
    scanf("%f", &slope);
    printf("Enter intercept (c): ");
    scanf("%d", &c);
    for (i = 0; i < vertices; i++) {
        xaux[i] = (((1 - slope * slope) * x[i]) + (2 * slope * (y[i] - c))) / (1 + slope * slope);
        yaux[i] = (((slope * slope - 1) * y[i]) + (2 * slope * x[i]) + 2 * c) / (1 + slope * slope);
    }
}

void reflection() {
    printf("\n\nREFLECTION OPTIONS:\n1. X-axis\n2. Y-axis\n3. y = x\n4. y = -x\n5. Origin\n6. y = mx + c\nEnter your choice: ");
    scanf("%d", &choice1);
    switch (choice1) {
        case 1: x_axis(); break;
        case 2: y_axis(); break;
        case 3: y_equal_xp(); break;
        case 4: y_equal_xn(); break;
        case 5: origin(); break;
        case 6: straight_line(); break;
        default: printf("Invalid Choice\n"); break;
    }
}

void shearing() {
    int shear;
    printf("\n\nSHEARING\nEnter shearing factor: ");
    scanf("%d", &shear);
    printf("1. X-axis\n2. Y-axis\nChoose axis: ");
    scanf("%d", &choice2);
    switch (choice2) {
        case 1:
            for (i = 0; i < vertices; i++) {
                xaux[i] = x[i] + shear * y[i];
                yaux[i] = y[i];
            }
            break;
        case 2:
            for (i = 0; i < vertices; i++) {
                xaux[i] = x[i];
                yaux[i] = y[i] + shear * x[i];
            }
            break;
        default: printf("Invalid Choice\n"); break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    printf("Before transformation color - Black\nAfter transformation color - Red\nRange: -500 to 500\n");

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter coordinates:\n");
    for (i = 0; i < vertices; i++) {
        printf("Vertex-%d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
        xaux[i] = x[i];
        yaux[i] = y[i];
    }

    printf("\n2D TRANSFORMATIONS\n1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5. Shearing\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: translation(); break;
        case 2: rotation(); break;
        case 3: scaling(); break;
        case 4: reflection(); break;
        case 5: shearing(); break;
        default: printf("Invalid input\n"); break;
    }

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 750);
    glutCreateWindow("2D Transformations");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
