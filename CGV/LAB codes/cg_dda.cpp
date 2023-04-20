// DDA line drawing algorithm
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<math.h>
void myinit() {
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0, 10, 0, 10);
    glMatrixMode(GL_MODELVIEW);
}
void plot(float x, float y) {
    glPointSize(3);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}
void dda_line(int xo, int yo, int xend, int yend) {
    int dx = xend - xo, dy = yend - yo, steps, f;
    float xi, yi, x = xo, y = yo;
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    }
    else { steps = abs(dy); }
    xi = float(dx) / float(steps);
    yi = float(dy) / float(steps);
    plot(roundf(x), roundf(y));
    for (f = 0;f < steps;f++) {
        x += xi;
        y += yi;
        plot(roundf(x), roundf(y));
    }
}
void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    dda_line(5, 5, 8, 9);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA line algorithm");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}