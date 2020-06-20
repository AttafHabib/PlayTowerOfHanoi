#pragma once
#include <iostream>
#include <windows.h>
class stack
{
private:
	int* gameStack;
public:
	int size;
	int Toss;

	stack(int size);
	void push(int x);
	int pop();
	bool isFull()const;
	bool isEmpty()const;
	void display(int col,int row)const;
	int peek()const;
	void initialize();
};

