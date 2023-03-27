// display an axonometric triangle or a right angled triangle
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>

void myinit(){
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}
float root_three = pow(3,0.5);
void disp(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0); // red
    // triangle 1 containing 30,60,90 as angles
    /*
               A
        (30,30)|\
               | \
               |  \
               |___\ (30(√3 + 1),0)
        (30,0) B    C

        angle at A = 60*, B = 90*, C = 30*
        assume side AB = x then general notation of sides in axonometric triangle will be
        AB = x
        AC = 2x
        BC = x√3
        For any value of x this is valid
    */
    glBegin(GL_POLYGON);
        glVertex2f(30,0);
        glVertex2f(30,30);
        glVertex2f(30*(root_three+1),0);
    glEnd();
    // triangle 2 containing 45,90,45 as angles
    /*
               A
         (0,25)|\
               | \
               |  \
               |___\ (25,0)
        (0,0)  B    C
        angle at A = 45*, B = 90*, C = 45*
    */
    glColor3f(0,0,1); // blue
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,25);
        glVertex2f(25,0);
    glEnd();
    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Axonometric triangles");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}