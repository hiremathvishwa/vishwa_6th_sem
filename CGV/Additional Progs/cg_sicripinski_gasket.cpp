#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<time.h>

void myinit(){
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
    glMatrixMode(GL_MODELVIEW);
}

void disp(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    float p[2] = {0,0};
    while((p[0]>10 || p[0]<20) && (p[1] > 10 || p[1] < 20)){
        p[0] = rand()%20;
        p[1] = rand()%20;
    }
    float v[3][2] = {{10,10},{15,20},{20,10}};
    int x;
    for(int i=0;i<10000;i++){
        x = rand()%3;
        p[0] = (p[0] + v[x][0])/2;
        p[1] = (p[1] + v[x][1])/2;
        glBegin(GL_POINTS);
            glVertex2f(p[0],p[1]);
        glEnd();
        glFlush();
    }
    glFlush();
}

int main(int argc,char ** argv){
    glutInit(&argc,argv);
    srand(time(0));
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(0,100,0,100);
    glutCreateWindow("Sicripinski Gasket");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}