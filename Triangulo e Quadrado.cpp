#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <string>
#include <gl/glut.h>

// FONTE: https://youtu.be/1taGCskfxM0

using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0, 0, 1);

	glBegin(GL_TRIANGLES);

	glVertex2f(-0.5, 0.1);
	glVertex2f(-0.3, 0.4);
	glVertex2f(-0.1, 0.1);

	glEnd();

	glColor3f(0, 1, 1);

	glBegin(GL_QUADS);

	glVertex2f(0.1, 0.4);
	glVertex2f(0.1, 0.1);
	glVertex2f(0.4, 0.1);
	glVertex2f(0.4, 0.4);

	glEnd();

	glutSwapBuffers();

}


int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 600);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Triangle using OpenGL");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;

}