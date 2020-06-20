#pragma once
#include <iostream>
class stack
{
private:
	int Toss;
	int* gameStack;
public:
	int size;
	stack(int size);
	void push(int x);
	int pop();
	bool isFull()const;
	bool isEmpty()const;
	void display()const;
	int peek()const;
	void initialize();
};

