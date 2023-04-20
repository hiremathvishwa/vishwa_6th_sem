#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>

using namespace std;

void myinit() {
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5);
    glMatrixMode(GL_MODELVIEW);
}
void plot(float x, float y) {
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void circle_1(float r) {
    float x = r, y;

    while (x >= 0) {
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        x -= 0.01;
        y = sqrt((r * r) - (x * x));
    }

}
void circle_2(float r) {
    float o = 0;
    float x = 0, y = 0;
    while (o < 360) {
        x = r * cosf(o);
        y = r * sinf(o);
        o += 1.0;
        plot(x + 3, y + 2);
    }
}
void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    circle_1(2.0);// radius input 10
    circle_2(1.0);
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle drawing");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
