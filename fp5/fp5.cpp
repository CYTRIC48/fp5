#include "money.h"
#include "treasure.h"

enum mainDirection { STOPm = 0, LEFTm, RIGHTm, UPm, DOWNm };
mainDirection dirm;
gameOver gamerule;
int xm, ym;

void gamemoney();
void trgame();

void Setupm()
{
	dirm = STOPm;
	xm = width / 2 - 1;
	ym = hight / 4 - 5;
}

void mainmap()
{
	this_thread::sleep_for(chrono::milliseconds(200));
	system("cls");
	for (int i = 0; i < width + 1; i++) {
		if (i > 16 && i < 24)
			cout << " ";
		else
			cout << "#";
	}
	cout << endl;

	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++) {
			if ((i > 7 && i < 11 && j == 39) || (i > 7 && i < 11 && j == 0))
				cout << " ";
			else if (j == 0 || j == width - 1)
				cout << "#";
			if (i == ym && j == xm)
				cout << "@";
			else
				cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
}

void Inputm()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case'w':
			dirm = UPm;
			break;
		case'a':
			dirm = LEFTm;
			break;
		case's':
			dirm = DOWNm;
			break;
		case'd':
			dirm = RIGHTm;
			break;
		}
	}
}

void Logicm()
{
	switch (dirm)
	{
	case LEFTm:
		xm--;
		break;
	case RIGHTm:
		xm++;
		break;
	case UPm:
		ym--;
		break;
	case DOWNm:
		ym++;
		break;
	}

	if (xm > 16 && xm < 24 && ym < 0)
		exit(0);
	if (xm > width - 1 && ym > 7 && ym < 11) {
		gamerule.money = true;
		moneyrule.over = true;
		treasure.money = true;
	}
	if (xm < 0 && ym > 7 && ym < 11) {
		gamerule.money = true;
		moneyrule.over = true;
	}
	else if (xm > width || xm < 0 || ym > hight || ym < 0)
		dirm = STOPm;
}

void gamevoid()
{
	treasure.money = false;
	dirtr = STOPtr;
	dir = LEFT;
	trg = false;
	gg = false;
	x = width - 2;
	y = hight / 2 - 1;
	xtr = 1;
	ytr = hight / 2;
	while (moneyrule.over == false)
	{
		while (gamerule.money == false)
		{
			mainmap();
			Inputm();
			Logicm();
		}
	}
	if (treasure.money == true)
		trgame();
	else
		gamemoney();
}

void gamemoney()
{
	dirm = STOPm;
	moneyrule.over = false;
	gamerule.money = false;
	while (gg == false) 
	{
		Draw();
		Input();
		Logic();
	}

	if (moneyrule.meny == true) 
	{
		xm = 1;
		ym = 9;
		gamevoid();
	}
}

void trgame()
{
	dirm = STOPm;
	moneyrule.over = false;
	gamerule.money = false;
	while (trg == false)
	{
		trmap();
		Inputtr();
		Logictr();
	}
	xm = 38;
	ym = 9;
	gamevoid();
}

int main()
{
	Setupm();
	Setuptr();
	Setup();
	gamevoid();
	return 0;
}