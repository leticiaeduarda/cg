#include <GL/freeglut.h>

#define DELTA 0.02
#define LARGURA 32
#define ALTURA 24

typedef struct {
	float x, y, z;
} Vetor;

Vetor direcao, posicao;

static void inicio() {
	//define screen backgroud

	glClearColor(0.5, 0.5, 0.5, 1);

	//initial position in center of the screen
	posicao.x = LARGURA / 2;
	posicao.y = ALTURA / 2;

	// defining an initiail movement direction
	direcao.x = DELTA;
	direcao.y = DELTA;

}

static void ocioso()
{
	// Threating the colision
	// If it colides with the border, and it is gonig in the border direction, changes the direction
	if (posicao.x <= 1 && direcao.x < 0) direcao.x = DELTA; // left border
	if (posicao.x >= LARGURA - 1 && direcao.x > 0) direcao.x = -DELTA; // right border
	if (posicao.y <= 1 && direcao.y < 0) direcao.y = DELTA; // bottom border
	if (posicao.y >= ALTURA - 1 && direcao.y > 0) direcao.y = -DELTA; // hight border

	posicao.x += direcao.x;
	posicao.y += direcao.y;

	// redraw the screen
	glutPostRedisplay();
}

static void teclado(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT: direcao.x = -DELTA; break;
	case GLUT_KEY_RIGHT: direcao.x = DELTA; break;
	case GLUT_KEY_DOWN: direcao.y = -DELTA; break;
	case GLUT_KEY_UP: direcao.y = DELTA; break;
	}
}

static void desenhar()
{
	//Clear the frameBuffer with the background color
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, LARGURA, 0, ALTURA, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Translation
	glTranslatef(posicao.x, posicao.y, 0);

	//It draws a red square center in origin
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glEnd();

	// Change the GrameBuffers (double buffering)
	glutSwapBuffers();

}

int main(int argc, char** argv) {

	// Glut starting
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	//glutInitWindowPosition(80, 80);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1280, 960);
	//glutInitWindowSize(400, 600);
	glutCreateWindow("Square");

	// Application initial setup
	inicio();

	// CallBack functions
	glutDisplayFunc(desenhar);
	glutIdleFunc(ocioso);
	glutSpecialFunc(teclado);

	// Graphic Application Loop
	glutMainLoop();

	return 0;

}
