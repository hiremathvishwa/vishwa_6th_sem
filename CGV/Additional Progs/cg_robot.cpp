#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void myinit(){
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

void disp(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    // head
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(0.75,0.5);
        glVertex2f(0.75,0.75);
        glVertex2f(-0.75,0.75);
        glVertex2f(-0.75,0.5);
    glEnd();
    // neck
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(0.25,0);
        glVertex2f(0.25,0.5);
        glVertex2f(-0.25,0.5);
        glVertex2f(-0.25,0);
    glEnd();
    // body 
    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(0.75,0);
        glVertex2f(0.75,-0.75);
        glVertex2f(-0.75,-0.75);
        glVertex2f(-0.75,0);
    glEnd();
    // hand 1
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(-1,0);
        glVertex2f(-0.8,0);
        glVertex2f(-0.8,-0.5);
        glVertex2f(-1,-0.5);
    glEnd();
    // hand 2
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(0.8,0);
        glVertex2f(1,0);
        glVertex2f(1,-0.5);
        glVertex2f(0.8,-0.5);
    glEnd();

    glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Robot");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}