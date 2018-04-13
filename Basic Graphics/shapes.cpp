#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.0f);
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
glVertex3f(0.0f, 0.0f, 2.0f);
glVertex3f(0.5f, 0.5f, 0.0f);
glVertex3f(0.5f, 0.7f, 0.0f);
glVertex3f(0.4f, 0.9f, 0.0f);
glEnd();
glBegin(GL_POINTS);
glVertex3f(-0.9f, 0.0f, 0.0f);
glVertex3f(-0.7f, 0.0f, 0.0f);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3f(-0.8f, 0.5f, 2.0f);
glVertex3f(-0.5f, -0.5f, 0.0f);
glVertex3f(-0.5f, -0.7f, 0.0f);
glVertex3f(-0.4f, -0.9f, 0.0f);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex3f(-1.0f, 0.0f, 0.0f);
glVertex3f(0.0f, -1.0f, 0.0f);
glVertex3f(1.0f, 0.0f, 0.0f);
glVertex3f(0.0f, 1.0f, 0.0f);
glVertex3f(-1.0f, 0.0f, 0.0f);
glEnd();
glColor3f(0.0f, 1.0f, 0.0f);
glBegin(GL_POLYGON);
glVertex3f(-0.5f, 0.0f, 0.0f);
glVertex3f(0.0f, -0.5f, 0.0f);
glVertex3f(0.0f, -0.2f, 0.0f);
glVertex3f(-0.2f, 0.0f, 0.0f);
glVertex3f(-0.5f, 0.0f, 0.0f);
glEnd();
glRotatef(1.0,1.0,1.0, 1.0);
glBegin(GL_TRIANGLES);
    glColor3f( 1, 0, 0 ); // red
    glVertex2f( -0.8, -0.8 );
    glColor3f( 0, 1, 0 ); // green
    glVertex2f( 0.8, -0.8 );
    glColor3f( 0, 0, 1 ); // blue
    glVertex2f( 0, 0.9 );
    glEnd();
glutPostRedisplay();
glutSwapBuffers();
}
void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}
void intiopenGL()
{
 glClearColor(0.8, 0.0, 0.0, 1);
 glEnable(GL_DEPTH_TEST);
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
 glutInitWindowSize(800, 600);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("OpenGL Test");
 intiopenGL();
 glutDisplayFunc(display);
 glutIdleFunc(display);
 glutReshapeFunc(reshape);
 glutMainLoop();
 return 0;
}
