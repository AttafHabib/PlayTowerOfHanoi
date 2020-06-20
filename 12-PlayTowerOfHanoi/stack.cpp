#include "stack.h"
using namespace std;
stack::stack(int size) {
	this->size = size;
	Toss = 0;
	gameStack = new int[size];

}
void stack::push(int x) {
	if (!isFull()) {
		gameStack[Toss] = x;
		Toss++;
	}
}
int stack::pop() {
	if (Toss >0) {
		return gameStack[--Toss];
	}
	else {
		return NULL;
	}

}
bool stack::isFull()const {
	return size == Toss;
}
bool stack::isEmpty()const {
	return !Toss;
}
void stack::display()const {
	cout << "[";
	for (int i = 0; i < Toss; i++)
	{
		if (i > 0) {
			cout << ",";
		}
		cout << gameStack[i];
	}
	cout << "]\n";
}
int stack::peek()const {
	if (Toss > 0) {
		return gameStack[Toss - 1];
	}
	else {
		return NULL;
	}
}
