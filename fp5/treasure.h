#pragma once
enum trDirection { STOPtr = 0, LEFTtr, RIGHTtr, UPtr, DOWNtr };
trDirection dirtr;
gameOver treasure;
bool trg;
int xtr, ytr;

void Setuptr()
{
	xtr = 1;
	ytr = hight / 2;
	trg = false;
	treasure.meny = false;
	treasure.money = false;
	dirtr = STOPtr;
}

void trmap()
{
	this_thread::sleep_for(chrono::milliseconds(200));
	system("cls");
	cout << "Score: " << score << endl;
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++) {
			if (i > 7 && i < 11 && j == 0)
				cout << " ";
			else if (j == 0 || j == width - 1)
				cout << "#";
			else if (i == hight / 2 - 1 && j == width - 5)
				cout << "M";
			if (i == ytr - 1 && j == xtr)
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

void Inputtr()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case'w':
			dirtr = UPtr;
			break;
		case'a':
			dirtr = LEFTtr;
			break;
		case's':
			dirtr = DOWNtr;
			break;
		case'd':
			dirtr = RIGHTtr;
			break;
		}
	}
}

void Logictr()
{
	switch (dirtr)
	{
	case LEFTtr:
		xtr--;
		break;
	case RIGHTtr:
		xtr++;
		break;
	case UPtr:
		ytr--;
		break;
	case DOWNtr:
		ytr++;
		break;
	}
	
	if (xtr < 0 && ytr > 7 && ytr < 11) {
		trg = true;
		treasure.meny = true;
	}
	else if (xtr > width || xtr < 0 || ytr > hight || ytr < 0)
		dirtr = STOPtr;
	if (ytr == hight / 2 && xtr == 35)
	{
		if (score >= 20) {
			system("cls");
			cout << "YOU WIN!";
			exit(0);
		}
		else
		{
			cout << "Requires 20 coins";
			this_thread::sleep_for(chrono::milliseconds(750));
		}
	}
}