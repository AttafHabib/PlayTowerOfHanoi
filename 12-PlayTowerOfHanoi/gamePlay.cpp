#include "gamePlay.h"
gamePlay::gamePlay(int size) {
	initializeGame(size);
}
void gamePlay::initializeGame(int size) {
	stack leftStack(size);
    //Biggest tile below. Smallest on Top
    for (int i = 0; i < size; i++) {
        leftStack.push(size-i);
    }
	stack rightStack(size);
	stack middleStack(size);
	menu(leftStack,middleStack,rightStack);
}
void gamePlay::menu(stack left, stack middle, stack right) {
    bool gameEnd = false;
    while (!gameEnd) {
        cout << "Welcome to Tower Of Hanoi Game." << endl;
        displayBars(left,middle,right);
        cout << "Enter Bar to remove element: ";
        int inputBar;
        cin >> inputBar;
        bool validBar = false;
        if (inputBar == 1) {
            validBar = checkValidPop(left);
        }
        else if (inputBar == 2) {
            validBar = checkValidPop(middle);
        }
        else if (inputBar == 3) {
            validBar = checkValidPop(right);
        }
        else {
            cout << "Invalid Choice. Removal Not Possible" << endl;
        }
        cout << endl;
        if (validBar) {
            cout << "Enter Bar to add element: ";
            cin >> inputBar;
        }
        cout << endl;
        //Game Ends if Bars shifted to any of the other two Bars
        if (middle.isFull()||right.isFull()) {
            cout << "Congratulations! You Have Won The Game";
            gameEnd = true;
        }
    }
}
bool gamePlay::checkValidPush(stack obj,int value)const{
    bool result = false;
    if (!obj.peek() || obj.peek()>value) {
        result = true;
    }
    else {
        result = false;
    }
    return result;
}
bool gamePlay::checkValidPop(stack obj)const {
    return obj.pop();
}
//Changing commandline Color
void gamePlay::changeColor(int ColorVal) {
	//0 = Black 8 = Gray
	//1 = Blue 9 = Light Blue
	//2 = Green a = Light Green
	//3 = Aqua b = Light Aqua
	//4 = Red c = Light Red
	//5 = Purple d = Light Purple
	//6 = Yellow e = Light Yellow
	//7 = White f = Bright White
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, ColorVal);
}
//Change Cursor coordinates
void gamePlay::gotoXY(int col, int row)
{
	COORD coord;
	coord.X = col;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void gamePlay::displayBars(stack left,stack middle,stack right) {
    //Main Bottom Bar
    for (int i = 0; i < 3; i++) {
        gotoXY(20+(i*30), 20);
        cout << "--------------------";
    }
    //Red
    changeColor(4);
    //LeftBar
    for (int i = left.size; i > 0; i--) {

    }
    //Green
    changeColor(2);
    //Middle Bar
    for (int i = middle.size; i > 0; i--) {
    }
    //Yellow
    changeColor(6);
    //Right Bar
    for (int i = right.size; i > 0; i--) {

    }
    //Back to orignal White
    changeColor(7);
}