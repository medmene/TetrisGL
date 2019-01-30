#include "Inits.h"


void Draw() {
	switch (gameProps::globalScene)
	{
	case 0: DrawMenuScene(); break;
	case 1: DrawSecondScene(); break;
	case 2: DrawGameScene(); break;
	}
	glutSwapBuffers();
}

void main(int argc, char **argv) {
	Initialize(argc, argv);
	return;
}