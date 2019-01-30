#pragma once
#include "MouseEvents.h"


void Loads() {
	//////////Menu//////////
	Game::startBtn = Button(710, 350, 500, 100, "Start Game");
	Game::infoBtn = Button(710, 550, 500, 100, "Information");
	Game::exitBtn = Button(710, 750, 500, 100, "Exit");
	Game::logo.push_back(Figure(0, 20, 1124, 225));
	Game::logo.push_back(Figure(2, 20, 1124 + 20 * 4, 225));
	Game::logo.push_back(Figure(3, 20, 1124 - 20, 225 - 20 * 2));
	Game::logo.push_back(Figure(5, 20, 1124 + 20 * 3, 225 - 20));
	Game::logo.push_back(Figure(6, 20, 1124 + 20 * 4, 225 - 3 * 20));
	Game::logo.push_back(Figure(0, 20, 1124 + 20 * 2, 225 - 20 * 6));
	//////////Info//////////
	Game::backInfoBtn = Button(100, 100, 500, 100, "Back");
	//////////Game//////////
	Game::backGameBtn = Button(1400, 930, 400, 80, "Back");
	Game::newGameBtn = Button(1400, 810, 400, 80, "New Game ");
	Game::next = Figure(rand()%6, 80, 1550, 200);
	////////////////////////
}

void Initialize(int argc, char **argv) {
	srand(time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(gameProps::windowWidth, gameProps::windowHeight);	//Window size
	glutInitWindowPosition(800, 400);										//Window position
	glutCreateWindow(gameProps::nameOfWindow.c_str());						//Window name
																			/**/
	Loads();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1920, 1080, 0);
	/**/
	glutDisplayFunc(Draw);				//Draw
	glutMouseFunc(onMouse);				//Mouse
	glutKeyboardFunc(onKeyboard);		//Keyboard
	glutMainLoop();
}
