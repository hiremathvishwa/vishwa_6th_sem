#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

void myinit()
{
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void disp()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    float head[4][2] = {{0.75, 0.5}, {0.75, 0.75}, {-0.75, 0.75}, {-0.75, 0.5}};
    float body[4][2] = {{0.75, 0}, {0.75, -0.75}, {-0.75, -0.75}, {-0.75, 0}};
    float h1[4][2] = {{-1, 0}, {-0.8, 0}, {-0.8, -0.5}, {-1, -0.5}};
    float h2[4][2] = {{0.8, 0}, {1, 0}, {1, -0.5}, {0.8, -0.5}};
    float neck[4][2] = {{0.25, 0}, {0.25, 0.5}, {-0.25, 0.5}, {-0.25, 0}};

    //head
    glLineWidth(3);
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 3; i++)
    {
        glVertex2fv(head[i]);
        glVertex2fv(head[i + 1]);
    }
    glVertex2fv(head[3]);
    glVertex2fv(head[0]);
    glEnd();
    //body
    glLineWidth(3);
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 3; i++)
    {
        glVertex2fv(body[i]);
        glVertex2fv(body[i + 1]);
    }
    glVertex2fv(body[3]);
    glVertex2fv(body[0]);
    glEnd();
    //neck
    glLineWidth(2.5);
    glColor3f(0, 1, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
    {
        glVertex2fv(neck[i]);
        glVertex2fv(neck[i + 1]);
    }
    glEnd();
    //hand1
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
    {
        glVertex2fv(h1[i]);
        glVertex2fv(h1[i + 1]);
    }
    glEnd();
    //hand2
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
    {
        glVertex2fv(h2[i]);
        glVertex2fv(h2[i + 1]);
    }

    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Robot with line primitives");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}