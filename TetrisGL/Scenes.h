#pragma once
#include "CustomTypes.h"

namespace Game {
	Button startBtn, infoBtn, exitBtn;	
	Button backInfoBtn;
	Button newGameBtn, backGameBtn;
	vector<Figure> logo;
	Figure next;
	Figure cur;
	int direction = -1;
}

void DrawGrid() {
	for (int i = 0; i < 13; ++i)
		for (int j = 0; j < 11; ++j)
			DrawRectangle(86 + i * 90, 46 + j * 90, 90, 90, 2);
}

void DrawFrame() {
	Color::Black();
	FillRectangle(0, 0, 1920, 1080);
	Color::Aqua();
	DrawRectangle(80, 40, 1185, 1004, 4);
}

void DrawLogo() {
	Color::Orange();
	DrawRectangle(1100, 50, 150, 200, 2);
	for (int i = 0; i < Game::logo.size(); ++i)
		Game::logo[i].Draw(0);
}

void DrawMenuScene() {
	Color::Black();
	FillRectangle(0, 0, 1920, 1080);
	Color::Aqua();
	glWrite((1920 - 6 * 18) / 2, 150, "Tetris");
	Game::startBtn.Draw();
	Game::infoBtn.Draw();
	Game::exitBtn.Draw();
	DrawLogo();
}

//Info
void DrawSecondScene() {
	Color::Black();
	FillRectangle(0, 0, 1920, 1080);
	Color::Aqua();
	DrawRectangle((1920 - 1650) / 2, 250, 1650, 750, 4);
	Game::backInfoBtn.Draw();
	Color::White();
	glWrite(200, 350, "Author: megagem.");
	glWrite(200, 400, "Simple realisation of game \"Tetris\".");
	glWrite(200, 500, "Recomended using standart window size.");
	glWrite(200, 550, "Controls:");
	glWrite(300, 600, "W - up");
	glWrite(300, 650, "S - down");
	glWrite(300, 700, "D - right");
	glWrite(300, 750, "A - left");
	glWrite(200, 850, "C++ OpenGL Microsoft Visual Studio 2015.");
	glWrite(200, 900, "Github: https://github.com/medmene/SnakeGL");
}

void DrawGameScene() {
	Color::Black();
	FillRectangle(0, 0, 1920, 1080);
	Color::Aqua();
	DrawRectangle(80, 40, 1185, 1004, 4);
	Game::backGameBtn.Draw();
	Game::newGameBtn.Draw();
	Game::next.Draw(0);
}