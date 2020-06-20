#pragma once
#include "stack.h"
#include <iostream>
#include <windows.h>
using namespace std;

class gamePlay
{
private:
	void initializeGame(int size);
	void menu(stack left, stack middle, stack right);
	bool checkValidPush(stack obj, int  value)const;
	bool checkValidPop(stack obj)const;
	void changeColor(int ColorVal);
	void gotoXY(int col, int row);
	void displayBars(stack left,stack middle,stack right);
public:
	gamePlay(int size);
};

