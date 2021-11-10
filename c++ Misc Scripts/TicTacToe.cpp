#include <iostream>
#include <string>
#include <iterator>
using std::string;

void printGrid(string *stringArray[]) {
    for(int i = 0; i < 4; i++) {
        std::cout << *stringArray[i];
    }
}

int main() {
    //definition of a text row in tic tac toe
    string border = "+---+---+---+";
    string boxes =  "|   |   |   |\n";
    string rowText = border + "\n" + boxes;

    //containers for rows 1-3s
    string r1 = rowText;
    string r2 = rowText;
    string r3 = rowText;

    string *stringArray[4] = {&r1, &r2, &r2, &border};

//    std::cout << *stringArray[1] << "\n";
//    *stringArray[1] = "HAHAHA";
//    std::cout << *stringArray[1] << "\n" << r2;

    /*Text array values for midpoint of each box
    const int LEFT_PLACE = 16;
    const int MIDDLE_PLACE = 20;
    const int RIGHT_PLACE = 24;
    Each place is spaced 4 chars starting from FIRST_PLACE @ #16, ending at 24
    */
    const int FIRST_PLACE = 16;
    const int PLACE_DIFF = 4;


    char grid [3][3];
    const char PLAYER1_PIECE = 'X';
    const char PLAYER2_PIECE = 'Y';

    int rowChoice = 1;
    int columnChoice = 2;
    grid[rowChoice-1][columnChoice-1] = PLAYER1_PIECE;

    int columnPlace = (columnChoice -1) * PLACE_DIFF + FIRST_PLACE;

    switch(rowChoice) {
    case 1:
        r1[columnPlace] = PLAYER1_PIECE;
        break;
    case 2:
        r2[columnPlace] = PLAYER1_PIECE;
        break;
    case 3:
        r3[columnPlace] = PLAYER1_PIECE;
        break;
    }

    grid[rowChoice-1][columnChoice-1] = 'X';

    printGrid(stringArray);
}
