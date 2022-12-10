#include "controller.h"
#include "DBController.h"

int main(int argc, char** argv) {
	res = searchBest10();
	hislen = searchLength();
	init_db();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(windowSizeX, windowSizeY);
	glutInitWindowPosition(500, 50);
	glutCreateWindow("Plane Wars");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(KeyUp);
	glutMouseFunc(mousePressed);

	glutMainLoop();
	return 0;
}