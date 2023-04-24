#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

using namespace std;
void myinit() {
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(-50, 50, -50, 50);
    glMatrixMode(GL_MODELVIEW);
}
void plot(float x, float y) {
    glColor3f(1, 0, 0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}
void draw_circle(int r) {
    float x = 0, y = r;
    float p = 5 / 4 - r;
    plot(x, y);
    plot(x, -y);
    while (y > x) {
        if (p < 0) {
            x++;
            p += 2 * x + 1;
        }
        else {
            y--;
            x++;
            p += 2 * (x - y) + 1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(y, -x);
        plot(-y, -x);
        plot(-y, x);
    }
}
void disp() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    draw_circle(40);
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle drawing Algorithm");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}