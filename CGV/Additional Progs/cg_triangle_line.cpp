#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

void myinit(){
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}
void disp(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5,1,0);
    glBegin(GL_LINES);
        glVertex2f(250,0);
        glVertex2f(0,0);
        glVertex2f(0,0);
        glVertex2f(0,250);
        glVertex2f(250,0);
        glVertex2f(0,250);
    glEnd();
    glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Triangle with Line primitive");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}