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
        int inputBar;
        cin >> inputBar;
        cout << "Enter Bar to add element: ";
        int removalBar;
        cin >> removalBar;

        bool validPop = !getStackFromNo(inputBar).isEmpty();
        bool validPush = false;
        if (validPop) {
            validPush = checkValidPush(getStackFromNo(removalBar), getStackFromNo(inputBar).peek());
        }
        if (validPop && validPush) {
            getStackFromNo(inputBar).push(getStackFromNo(removalBar).pop());
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
stack gamePlay::getStackFromNo(int No)const{
    if (No == 1) {
        return *leftStack;
    }
    else if (No == 2) {
        return *middleStack;
    }
    else if (No == 3) {
        return *rightStack;
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
    for (int i = 0; i < 3; i++) {
        //J = No of rows in one bar
        int j = 0;
        if (i == 0) {
            j = leftStack->Toss;
            changeColor(4);
        }
        else if (i==1) {
            j = middleStack->Toss;
            changeColor(2);
        }
        else {
            j = rightStack->Toss;
            changeColor(3);
        }
        int x = 0;
        //No of Vertical lines in 1 Bar(Rows)
        for (; j > 0; j--) {

            //No of Horizonatl dash in one line of One Bar (Coloumns of 1 Row)
            //    -
            //   ---
            //  -----
            // -------
            //---------
            //   No of Dashes in Each Line is (LineNo*2) - 1

            for (int k = 0; k < (j*2)-1; k++) {
                //Every line above starts from one inner coloumn
                // 20 = starting position
                // k = No of "-" in single line
                // x = Space to move before printing every line
                // i*20 = No of Spaces to leave for every bar( i = 0,1,2 respectively)
                gotoXY(10 + k+x +(i*35), 20-x);
                cout << "-";
            }
            x++;
        }
        changeColor(7);
        gotoXY(15+(i*35), 23);
        cout << i+1;
        
    }
    gotoXY(0, 0);
}