#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include "game.h"
#include<time.h>
#include<stdbool.h>

using namespace std;

void cleanScreen(){
    system("clear");
}

// Changing gameBoard in memory
void startGameBoard(char gameBoard[10][10], char mask[10][10]){
    
    int row, column;
    for(row = 0; row < 10; row++){
        for(column = 0; column < 10; column++){
            gameBoard[row][column] = 'W';
            mask[row][column] = '*';    
        }
    }
}

void showGameBoard(char gameBoard[10][10]){
    
    int row, column;
    for(column = 0; column < 10; column++ ){
        cout << '|' << column << '|';
    }
    cout << '\n';
    cout << '\n';

    for(row = 0; row < 10; row++){
        for(column = 0; column < 10; column++){
            cout << '|' << gameBoard[row][column] << '|';    
        }
        cout << " |" << row << '|';
        cout<< "\n";
    }

}

void positioningBoat(char gameBoard[10][10]){

    srand((unsigned)time(NULL));
    int cont = 0, quantidade = 12;
    int row, column;
    
    while (cont <= quantidade)
    {
        row = rand() % 10;
        column = rand() % 10;
        
        if(gameBoard[row][column] == 'W'){
            if(gameBoard[row][column] != 'P' && gameBoard[row][column] != 'G' && gameBoard[row][column] != 'B'){
                if(cont <= 5){
                    gameBoard[row][column] = 'P'; // 10 Points
                    cont++;
                }else if(cont > 5 && cont <= 9){
                    gameBoard[row][column] = 'G'; // 20 Points
                    cont++;
                }else{
                    gameBoard[row][column] = 'B'; // 40 Points
                    cont++;
                }
        }
    }
    
    }
}

void checkShot(char gameBoard[10][10], int playRow, int playColumn, int *score, string *msg){

    switch (gameBoard[playRow][playColumn])
    {
    case 'P':
        *score = *score + 10;
        *msg = "You hitted boat P !!";
        break;
    case 'G':
        *score = *score + 20;
        *msg = "You hitted boat G !!";
        break;
    case 'B':
        *score = *score + 40;
        *msg = "You hitted boat B !!";
        break;
    default:
        *msg = "You hitted the water !!";
    }

}

void optionAfterGame(int *score){
    
    int option;
    cout << "End the Game!!";
    cout << "\n Your score was " << *score;
    cout << "\n Would you like play again ?";
    cout << "\n 1- Yes";
    cout << "\n 2- No \n";
    cin >> option;

    switch (option)
    {
    case 1:
        game();
        break;
    case 2:
        menu();
        break;
    default:
        break;
    }
}

int checkMove(string position){
    int move;
    do{
        cout << "\n Put the " << position << " that you'd like to play:\t";
        cin >> move;        
    }while(!isValid(move));
    
    return move;
}

bool isValid(int move){
    if(move < 0 || move > 9){
        cout << "\n Number is not valid, try again!!";
        return false;
    }else{
        return true;
    }
}

void game(){
    
    char gameBoard[10][10], mask[10][10];
    int row, column;
    int playRow, playColumn;
    int statusGame = 1;
    int score;
    int tries = 0, maxTries = 5;
    string msg = "Welcome the GAME!!";

    startGameBoard(gameBoard, mask);
    positioningBoat(gameBoard);
    while (tries <= maxTries)
    {   
        cleanScreen();
        showGameBoard(mask);
        cout << "\n" << msg;
        cout << "\n Your score: \t" << score << "\t Tentativas restantes: " << maxTries - tries;       
        playRow = checkMove("Row");
        playColumn = checkMove("Column");
        checkShot(gameBoard, playRow, playColumn, &score, &msg);
        mask[playRow][playColumn] = gameBoard[playRow][playColumn];
        tries++;
    }
    cleanScreen();
    optionAfterGame(&score);
    
}

void menu(){
    
    int option;
    while (option < 1 || option > 3)
    {
        cleanScreen();
        cout << " Welcome to the Game!! ";
        cout << "\n 1- Start the game";
        cout << "\n 2- About ";
        cout << "\n 3- Exit";
        cout << "\n Choose the one option above:\t";

        cin >> option;
        switch (option)
        {
        case 1:
            cleanScreen();
            game();
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }
    
}