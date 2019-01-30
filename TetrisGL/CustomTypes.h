#pragma once
#include "DrawFunctions.h"


class Button {
	float X, Y;
	int width, height;
	string text;
public:
	bool onClick = false;
	Button() {}
	Button(float _X, float _Y, int _wid, int _heig, string _text) {
		X = _X; Y = _Y; width = _wid; height = _heig; text = _text;
	}
	void inline Draw() {
		//non clicked
		if (!onClick) {
			Color::Gray();
			DrawRectangle(X + 4, Y + 4, width, height, 6);
			Color::Silver();
			FillRectangle(X, Y, width, height);
			Color::Black();
			glWrite(X - 4 + (width - text.size() * 22) / 2, Y - 4 + (height + 24) / 1.8, text);
		}
		//clicked
		else {
			Color::Gray();
			DrawRectangle(X + 4, Y + 4, width, height, 5);
			Color::Silver();
			FillRectangle(X + 4, Y + 4, width, height);
			Color::Black();
			glWrite(X + (width - text.size() * 22) / 2, Y + (height + 24) / 1.8, text);
		}
	}
	Rect GetFiled() { return Rect(X, Y, width, height); }
	bool inline Hover(int x, int y) {
		if (x >= X && x < (X + width))
			if (y >= Y && y < (Y + height))
				return true;
		return false;
	}
};

class Figure {
	int blockSize = 70;
	int type; //[0 1 2 3 4 5 6]	
	float x, y;
	void DopDraw(float X, float Y) {
		FillRectangle(X, Y, blockSize, blockSize);
		Color::Black();
		DrawRectangle(X, Y, blockSize, blockSize, 2);
	}
	void DrawI(float X, float Y, int dir) {
		if (dir == 0 || dir == 2){
			Color::Aqua(); DopDraw(X - blockSize, Y);
			Color::Aqua(); DopDraw(X, Y);
			Color::Aqua(); DopDraw(X + blockSize, Y);
			Color::Aqua(); DopDraw(X + blockSize*2, Y);
			}
		else {
			Color::Aqua(); DopDraw(X, Y - blockSize);
			Color::Aqua(); DopDraw(X, Y);
			Color::Aqua(); DopDraw(X, Y + blockSize);
			Color::Aqua(); DopDraw(X, Y + blockSize*2);
		}
	}
	void DrawJ(float X, float Y, int dir) {
		switch (dir)
		{
		case 0: { // |__
			Color::Blue(); DopDraw(X, Y);
			Color::Blue(); DopDraw(X - blockSize, Y);
			Color::Blue(); DopDraw(X - blockSize, Y - blockSize);
			Color::Blue(); DopDraw(X + blockSize, Y);
			break;
		}
		case 1: { //Ã
			Color::Blue(); DopDraw(X, Y);
			Color::Blue(); DopDraw(X, Y - blockSize);
			Color::Blue(); DopDraw(X + blockSize, Y - blockSize);
			Color::Blue(); DopDraw(X, Y + blockSize);
			break;
		}
		case 2: {//--.
			Color::Blue(); DopDraw(X, Y);
			Color::Blue(); DopDraw(X - blockSize, Y);
			Color::Blue(); DopDraw(X + blockSize, Y);
			Color::Blue(); DopDraw(X + blockSize, Y + blockSize);
			break;
		}
		case 3: {// _|
			Color::Blue(); DopDraw(X, Y - blockSize);
			Color::Blue(); DopDraw(X, Y);
			Color::Blue(); DopDraw(X, Y + blockSize);
			Color::Blue(); DopDraw(X - blockSize, Y + blockSize);
			break;
		}
		}
	}
	void DrawL(float X, float Y, int dir) {
		switch (dir)
		{
		case 0: { // __|
			Color::Orange(); DopDraw(X, Y);
			Color::Orange(); DopDraw(X - blockSize, Y);
			Color::Orange(); DopDraw(X + blockSize, Y - blockSize);
			Color::Orange(); DopDraw(X + blockSize, Y);
			break;
		}
		case 1: { // |.
			Color::Orange(); DopDraw(X, Y);
			Color::Orange(); DopDraw(X, Y - blockSize);
			Color::Orange(); DopDraw(X + blockSize, Y + blockSize);
			Color::Orange(); DopDraw(X, Y + blockSize);
			break;
		}
		case 2: {//.--
			Color::Orange(); DopDraw(X, Y);
			Color::Orange(); DopDraw(X - blockSize, Y);
			Color::Orange(); DopDraw(X + blockSize, Y);
			Color::Orange(); DopDraw(X - blockSize, Y + blockSize);
			break;
		}
		case 3: {// *|
			Color::Orange(); DopDraw(X, Y - blockSize);
			Color::Orange(); DopDraw(X, Y);
			Color::Orange(); DopDraw(X, Y + blockSize);
			Color::Orange(); DopDraw(X - blockSize, Y - blockSize);
			break;
		}
		}
	}
	void DrawO(float X, float Y) {
		Color::Yellow(); DopDraw(X, Y);
		Color::Yellow(); DopDraw(X + blockSize, Y);
		Color::Yellow(); DopDraw(X + blockSize, Y + blockSize);
		Color::Yellow(); DopDraw(X, Y + blockSize);
	}
	void DrawS(float X, float Y, int dir) {
		switch (dir)
		{
		case 0: case 2: { // .|*
			Color::Green(); DopDraw(X, Y);
			Color::Green(); DopDraw(X + blockSize, Y);
			Color::Green(); DopDraw(X, Y + blockSize);
			Color::Green(); DopDraw(X - blockSize, Y + blockSize);
			break;
		}
		case 1: case 3:{ // *-.
			Color::Green(); DopDraw(X, Y);
			Color::Green(); DopDraw(X, Y + blockSize);
			Color::Green();	DopDraw(X - blockSize, Y);
			Color::Green(); DopDraw(X - blockSize, Y - blockSize);
			break;
		}
		}
	}
	void DrawZ(float X, float Y, int dir) {
		switch (dir)
		{
		case 0: case 2: { // .|*
			Color::Red(); DopDraw(X, Y);
			Color::Red(); DopDraw(X - blockSize, Y);
			Color::Red(); DopDraw(X, Y + blockSize);
			Color::Red(); DopDraw(X + blockSize, Y + blockSize);
			break;
		}
		case 1: case 3: { // *-.
			Color::Red(); DopDraw(X, Y);
			Color::Red(); DopDraw(X, Y - blockSize);
			Color::Red(); DopDraw(X - blockSize, Y);
			Color::Red(); DopDraw(X - blockSize, Y + blockSize);
			break;
		}
		}
	}
	void DrawT(float X, float Y, int dir) {
		switch (dir)
		{
		case 0: {
			Color::DarkViolet(); DopDraw(X, Y);
			Color::DarkViolet(); DopDraw(X - blockSize, Y);
			Color::DarkViolet(); DopDraw(X + blockSize, Y);
			Color::DarkViolet(); DopDraw(X, Y - blockSize);
			break; }
		case 1: {
			Color::DarkViolet(); DopDraw(X, Y);
			Color::DarkViolet(); DopDraw(X, Y - blockSize);
			Color::DarkViolet(); DopDraw(X, Y + blockSize);
			Color::DarkViolet(); DopDraw(X + blockSize, Y);
			break; }
		case 2: {
			Color::DarkViolet(); DopDraw(X, Y);
			Color::DarkViolet(); DopDraw(X - blockSize, Y);
			Color::DarkViolet(); DopDraw(X + blockSize, Y);
			Color::DarkViolet(); DopDraw(X, Y + blockSize);
			break; }
		case 3: {
			Color::DarkViolet(); DopDraw(X, Y);
			Color::DarkViolet(); DopDraw(X, Y - blockSize);
			Color::DarkViolet(); DopDraw(X, Y + blockSize);
			Color::DarkViolet(); DopDraw(X - blockSize, Y);
			break; }
		}
	}	
public:
	Figure() {}
	Figure(int tp) {
		type = tp;
	}
	Figure(int tp, int Bsz, float _X, float _Y) {
		type = tp; blockSize = Bsz;
		x = _X; y = _Y;
	}
	void Draw(float X, float Y, int dir) {		
		switch (type){
		case 0: DrawI(X, Y, dir); break;
		case 1: DrawJ(X, Y, dir); break;
		case 2: DrawL(X, Y, dir); break;
		case 3: DrawO(X, Y); break;
		case 4: DrawS(X, Y, dir); break;
		case 5: DrawT(X, Y, dir); break;
		case 6: DrawZ(X, Y, dir); break;
		}
	}
	void Draw(int dir) { Draw(x, y, dir); }
	int GetType() { return type; }
	void SetNewType(int tp) { if (tp > -1 && tp < 7) type = tp; }
};