#include <iostream>
#include <time.h>
//#include </usr/local/cuda-8.0/extras/CUPTI/include/GL/glut.h>
//#include <GL/glut.h>
#include "/usr/include/GL/glut.h"
#include "/usr/include/GL/glu.h"
#include "/usr/include/GL/gl.h"

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(50,50);
	glVertex2f(100,200);
	glEnd();

	glFlush();
}

int main (int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (640, 480);
  glutCreateWindow ("Test");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,640,0,480);

  glutDisplayFunc (display);
  glutMainLoop();
}
