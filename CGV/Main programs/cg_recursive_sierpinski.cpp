#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

using namespace std;


void myinit() {
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}
void draw_triangle(float a[2], float b[2], float c[2]) {
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(a[0], a[1]);
    glVertex2f(b[0], b[1]);
    glVertex2f(c[0], c[1]);
    glEnd();
}
void divide_triangle(float a[2], float b[2], float c[2], int n) {
    float m1[2] = { 0,0 }, m2[2] = { 0,0 }, m3[2] = { 0,0 };
    if (n > 0) {
        for (int j = 0;j < 2;j++) {
            m1[j] = (a[j] + b[j]) / 2;
            m2[j] = (b[j] + c[j]) / 2;
            m3[j] = (a[j] + c[j]) / 2;
        }
        divide_triangle(a, m1, m3, n - 1);
        divide_triangle(m1, b, m2, n - 1);
        divide_triangle(m3, m2, c, n - 1);
    }
    else {
        draw_triangle(a, b, c);
    }
}

void disp() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);
    float a[2] = { 10,0 }, b[2] = { 40,0 }, c[2] = { 25,30 };
    divide_triangle(a, b, c, 2);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(50, 50);
    glutCreateWindow("recursive sierpinski");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}