#pragma once
#include "Scenes.h"


void onKeyboard(unsigned char key, int x, int y) {
	if (gameProps::globalScene == 2) {
		switch (key) {
		case 'W': case 'w':
			break;
		case 'A': case 'a':
			Game::direction--;
			if (Game::direction < 0) Game::direction = 3;
			break;
		case 'S': case 's':
			break;
		case 'D': case 'd':
			Game::direction++;
			if (Game::direction > 3) Game::direction = 0;
			break;
		}
		Draw();
	}
}