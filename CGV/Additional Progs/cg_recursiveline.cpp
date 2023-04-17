#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>

using namespace std;

void myinit() {
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 50);
    glMatrixMode(GL_MODELVIEW);
}
void draw_point(float* p) {
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2fv(p);
    glEnd();
}
void mid(float* low, float* high, int n) {
    float midd[2];
    if (n > 0) {
        for (int i = 0;i < 2;i++) {
            midd[i] = (low[i] + high[i]) / 2;
        }
        draw_point(midd);
        mid(low, midd, n - 1);
        mid(midd, high, n - 1);
    }
}
void disp() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    float a[2] = { 20,20 }, b[2] = { 40,30 };
    mid(a, b, 10);
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint line creation");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
}