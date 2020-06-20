#include "gamePlay.h"
gamePlay::gamePlay(int size) {
	initializeGame(size);
}
void gamePlay::initializeGame(int size) {
    leftStack = new stack(size);
    rightStack = new stack(size);
    middleStack = new stack(size);
    //Biggest tile below. Smallest on Top
    for (int i = 0; i < size; i++) {
        leftStack->push(size-i);
    }
	
	menu();
}
void gamePlay::menu() {
    bool gameEnd = false;
    while (!gameEnd) {
        system("CLS");
        cout << "Welcome to Tower Of Hanoi Game." << endl;
        displayBars();

        gotoXY(0, 25);
        cout << "Enter Bar to remove element: ";
        int removalBar;
        cin >> removalBar;
        cout << "Enter Bar to add element: ";
        int inputBar;
        cin >> inputBar;

        bool validPop = !(*getStackFromNo(removalBar)).isEmpty();
        bool validPush = false;
        if (validPop) {
            validPush = checkValidPush(*getStackFromNo(inputBar), (*getStackFromNo(removalBar)).peek());
        }
        if (validPop && validPush) {
            stack *outputst = getStackFromNo(inputBar);
            stack *inputst = getStackFromNo(removalBar);
            int valuetopush = (*getStackFromNo(removalBar)).pop();
                (*outputst).push(valuetopush);
        }
        cout << endl;
        //Game Ends if Bars shifted to any of the other two Bars
        if (middleStack->isFull()||rightStack->isFull()) {
            cout << "Congratulations! You Have Won The Game";
            gameEnd = true;
        }
        gotoXY(0, 0);
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
stack* gamePlay::getStackFromNo(int No)const{
    if (No == 1) {
        return leftStack;
    }
    else if (No == 2) {
        return middleStack;
    }
    else if (No == 3) {
        return rightStack;
    }
    else {
        return NULL;
    }
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
void gamePlay::displayBars() {
    //Main Bottom Bar
    //Total Bars
    stack *obj = NULL;
    for (int i = 0; i < 3; i++) {
        //J = No of rows in one bar
        changeColor(3 + i);
        obj = getStackFromNo(i + 1);
        obj->display(20+(i*35), 20);
        
        gotoXY(17 + (i * 35), 23);
        changeColor(6);
        cout << "Bar "<<i+1;
    }
    changeColor(7);
    gotoXY(0, 0);
}