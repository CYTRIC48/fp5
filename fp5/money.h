#pragma once
#include <thread>
#include <ctime>
#include <iostream>
#include <conio.h>

using namespace std;

class gameOver
{
public:
	bool over;
	bool money;
	bool meny;
};

gameOver moneyrule;
const int width = 40;
const int hight = 20;
int x, y, moneyX, moneyY, score;
bool gotomain;
bool gg;
enum eDirection { LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
	srand(time(NULL));
	gotomain = false;
	gg = false;
	moneyrule.over = false;
	moneyrule.meny = false;
	dir = LEFT;
	x = width - 2;
	y = hight / 2 - 1;
	moneyX = rand() % width - 1;
	moneyY = rand() % hight;
	score = 0;
}

void Draw()
{
	this_thread::sleep_for(chrono::milliseconds(200));
	system("cls");
	cout << "Score: " << score << endl;
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++) {
			if (i > 7 && i < 11 && j == 39)
				cout << " ";
			else if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << "@";
			else if (i == moneyY && j == moneyX)
				cout << "$";
			else
				cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
}

void Input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case'w':
			dir = UP;
			break;
		case'a':
			dir = LEFT;
			break;
		case's':
			dir = DOWN;
			break;
		case'd':
			dir = RIGHT;
			break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x >= 40 && y > 7 && y < 11) {
		moneyrule.meny = true;
		gg = true;
	}
	else if (x > width || x < 0 || y > hight || y < 0) {
		gg = true;
		moneyrule.over = true;
	}
	if (x == moneyX && y == moneyY) {
		score++;
		moneyX = rand() % width - 1;
		moneyY = rand() % hight;
	}
}