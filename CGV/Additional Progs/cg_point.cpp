#include<stdio.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>


void disp(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
        glVertex2f(250,250);
    glEnd();
    glFlush();
}

void myinit(){
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("First");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}