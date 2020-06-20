#pragma once
#include "stack.h"
#include <iostream>
#include <windows.h>
using namespace std;

class gamePlay
{
private:
	stack* leftStack;
	stack* rightStack;
	stack* middleStack;
	void initializeGame(int size);
	void menu();
	bool checkValidPush(stack obj, int  value)const;
	stack* getStackFromNo(int NO)const;
	void changeColor(int ColorVal);
	void gotoXY(int col, int row);
	void displayBars();
public:
	gamePlay(int size);
};

