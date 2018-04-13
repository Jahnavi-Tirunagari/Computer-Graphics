#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

float x1, y1, x2, y2, dx, dy, L, xnew, ynew, xlist[1500], ylist[1500];
int times = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(0.0f, 0.0f, 5.0f);
    glLoadIdentity();
    glBegin(GL_LINES);
        times = 0;
        while (times <= L) {
            glVertex2f(xlist[times], ylist[times]);
            times += 1;
        }
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
    glClearColor(0.8, 0.0, 0.0, 1.0);
}
int main(int argc, char** argv)
{
    printf("Enter x1: ");
    scanf("%f", &x1);
    printf("Enter y1: ");
    scanf("%f", &y1);
    printf("Enter x2: ");
    scanf("%f", &x2);
    printf("Enter y2: ");
    scanf("%f", &y2);
    dx = x2 - x1;
    dy = y2 - y1;
    L = (abs(dx) > abs(dy)) ? dx : dy;
    xnew = dx / L;
    ynew = dy / L;
    while (times <= L) {
        xlist[times] = x1 + times * xnew;
        ylist[times] = y1 + times * ynew;
        times += 1;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Test");
    intiopenGL();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
