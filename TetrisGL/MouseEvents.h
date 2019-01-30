#pragma once
#include "KeyboardEvents.h"


void onMouse(int button, int state, int x, int y) {
	x = x * gameProps::windwScale;
	y = y * gameProps::windwScale;
	switch (gameProps::globalScene)
	{
	case 0: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Game::startBtn.Hover(x, y)) { Game::startBtn.onClick = true; }
			else if (Game::infoBtn.Hover(x, y)) { Game::infoBtn.onClick = true; }
			else if (Game::exitBtn.Hover(x, y)) { Game::exitBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (Game::startBtn.onClick) { Game::startBtn.onClick = false; gameProps::globalScene = 2; }
			else if (Game::infoBtn.onClick) { Game::infoBtn.onClick = false; gameProps::globalScene = 1; }
			else if (Game::exitBtn.onClick) { Game::exitBtn.onClick = false; exit(0); }
		} 
		break;}
	case 1: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Game::backInfoBtn.Hover(x, y)) { Game::backInfoBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (Game::backInfoBtn.onClick) { Game::backInfoBtn.onClick = false; gameProps::globalScene = 0;  }
		}
		break; }
	case 2: {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (Game::backGameBtn.Hover(x, y)) { Game::backGameBtn.onClick = true; }
			else if (Game::newGameBtn.Hover(x, y)) { Game::newGameBtn.onClick = true; }
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
			if (Game::backGameBtn.onClick) { Game::backGameBtn.onClick = false; gameProps::globalScene = 0; }
			else if (Game::newGameBtn.onClick) { Game::newGameBtn.onClick = false; }
		}
		break; }
	}
	
	Draw();
}