#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //tire back L
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-6,-22);
    glVertex2f(-6,-19);
    glVertex2f(-10,-19);
    glVertex2f(-10,-22);
    glEnd();
    //tire back R
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(6,-22);
    glVertex2f(6,-19);
    glVertex2f(10,-19);
    glVertex2f(10,-22);
    glEnd();

    //tire line front L
    glColor3f(0,0,0);
    glLineWidth(2.5);
     glBegin(GL_LINES);
     glVertex2f(-1.3,13.0);
     glVertex2f(-7.0,14.0);
     glVertex2f(-1.3,13.0);
     glVertex2f(-7.0,12.0);
    glEnd();

    //tire line front R
    glColor3f(0,0,0);
    glLineWidth(2.5);
     glBegin(GL_LINES);
     glVertex2f(1.1,13.0);
     glVertex2f(7.0,14.0);
     glVertex2f(1.1,13.0);
     glVertex2f(7.0,12.0);
    glEnd();

    //tire Front L
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-6,11);
    glVertex2f(-6,15);
    glVertex2f(-10,15);
    glVertex2f(-10,11);
    glEnd();

    //tire Front R
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(6,11);
    glVertex2f(6,15);
    glVertex2f(10,15);
    glVertex2f(10,11);
    glEnd();
    //body 3
    glColor3f(0,0.55,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-9.0,-5.0);
    glVertex2f(9.0,-5.0);
    glVertex2f(0.0,13.0);
    glEnd();
    //body 2
    glColor3f(0,0.75,0);
    glBegin(GL_QUADS);
    glVertex2f(-9,-15);
    glVertex2f(9,-15);
    glVertex2f(9,-5);
    glVertex2f(-9,-5);
    glEnd();
    //body 1
    glColor3f(0,0.75,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-7.0,-22.0);
    glVertex2f(7.0,-22.0);
    glVertex2f(0.0,20.0);
    glEnd();

    //back dash
    glColor3f(0,0.55,0);
    glBegin(GL_QUADS);
    glVertex2f(-5,-22);
    glVertex2f(5,-22);
    glVertex2f(5,-16);
    glVertex2f(-5,-16);
    glEnd();
    //back wind
    glColor3f(0,0.39,0);
    glBegin(GL_QUADS);
    glVertex2f(-15,-22);
    glVertex2f(-15,-25);
    glVertex2f(15,-25);
    glVertex2f(15,-22);
    glEnd();
    //Front wind
    glColor3f(0,0.39,0);
    glBegin(GL_QUADS);
    glVertex2f(8,16);
    glVertex2f(8,18);
    glVertex2f(-8,18);
    glVertex2f(-8,16);
    glEnd();
    //Driver
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-3.0,-13.0);
    glVertex2f(3.0,-13.0);
    glVertex2f(0.0,-5.0);
    glEnd();



    glFlush();
}
void Initialize()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
}
int main(int Argc, char** Argv)
{
    glutInit(&Argc, Argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 650);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Flag of Francei");
    Initialize();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
