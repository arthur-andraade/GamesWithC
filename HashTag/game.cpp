#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include "game.h"

using namespace std;

void clearScreen(){
    system("clear");
}

void showBoard(char board[3][3]){

    int row, column;
    for ( row = 0; row < 3; row++)
    {
        for( column = 0; column < 3; column++){
            cout << "|" << board[row][column] << "|";
        }
        cout << "\n";
    }

}

void initBoard(char board[3][3]){
    
    int row, column;
    int count = 0;
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'}; 

    for ( row = 0; row < 3; row++)
    {
        for( column = 0; column < 3; column++){
            board[row][column] = letters[count];
            count++;
        }
    }
}

void checkBoar(char move, int player, char board[3][3]){
    int row, column;
    for(row = 0; row < 3;row++){
        for(column = 0; column < 3; column++){
            if( move == board[row][column]){
                if(player == 1){
                    board[row][column] = 'X';
                }else{
                    board[row][column] = 'O';
                }
            }
        }
    }
}

int checkWinner(char board[3][3]){

    //Checking column
    int column;
    for(column = 0; column < 3; column++){
        if( board[0][column] == 'X' && board[1][column] == 'X' && board[2][column] == 'X'){
            return 1;
        }
        if( board[0][column] == 'O' && board[1][column] == 'O' && board[2][column] == 'O'){
            return 0;
        }
    }

    //Checking row
    int row;
    for(row = 0; row < 3; row++){
        if( board[row][0] == 'X' && board[row][1] == 'X' && board[row][2] == 'X' ){
            return 1;
        }

        if( board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == 'O' ){
            return 0;
        }
    }

    //Checking diagonal 1
    if( board[0][0] == board[1][1] && board[2][2] == board[1][1]){
        if(board[0][0] == 'X'){
            return 1;
        }else{
            return 0;
        }
    }

    //Checkinf diagonal 2
    if( board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[1][1] == 'X'){
            return 1;
        }else{
            return 0;
        }
    }

    return -1;
}

char upperCase(char move){
    switch (move)
    {
    case 'a':
        return 'A';
    case 'b':
        return 'B';
    case 'c':
        return 'C';
    case 'd':
        return 'D';
    case 'e':
        return 'E';
    case 'f':
        return 'F';
    case 'g':
        return 'G';
    case 'h':
        return 'H';
    case 'i':
        return 'I';
    default:
        return move;
    }
}

char readPlayer(string name){
    char move;
    cout << "\n What position would you like play "<< name << " ?\t";
    cin >> move;
    return upperCase(move);
}

void runningGame(string player1, string player2, int scorePlayer1, int scorePlayer2){

    char board[3][3];
    initBoard(board);
    showBoard(board);
    int tries = 0;
    int playing = 1; // Player1 = 1, Player2 = 0
    char move;

    while(tries < 9){
        if(playing == 1){
            move = readPlayer(player1);
            checkBoar(move, playing, board);
            tries++;
            playing = 0;
        }else{
            move = readPlayer(player2);
            checkBoar(move, playing, board);
            tries++;
            playing = 1;
        }
        clearScreen();
        showBoard(board);

        if(checkWinner(board) == 1){
            cout << "\nPlayer " << player1 << " win this round!!";
            scorePlayer1++;
            break;
        }else if(checkWinner(board) == 0){
            cout << "\nPlayer " << player2 << " win this round!!";
            scorePlayer2++;
            break;
        }

    }

    cout << "\n| Player 1 | Player 2 |";
    cout << "\n|    " << scorePlayer1 << "     |     " << scorePlayer2 << "  |";
    
    int playAgain; // 1 -Yes, 2 - No
    cout << "\nWould you like play again ?";
    cout << "\n1 - Yes";
    cout << "\n2 - No\n";
    cin >> playAgain;
    if(playAgain == 1){
        clearScreen();
        runningGame(player1, player2, scorePlayer1, scorePlayer2);
    }else{
        if(scorePlayer1 > scorePlayer2){
            cout << "\n Player " << player1 << " win the game!!";
        }else{
            cout << "\n Player " << player2 << " win the game!!";
        }
    }

}

void game(){

    int option;
    string player1;
    string player2;
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;

    while ( option < 0 || option > 3)
    {   
        clearScreen();
        menu();
        cin >> option;

        switch (option)
        {
            case 1:
                cout << "\nName the player 1:\t";
                cin >> player1;
                cout << "\nName the player 2:\t";
                cin >> player2;
                clearScreen();
                runningGame(player1, player2, scorePlayer1, scorePlayer2);
                break;
            case 2:
                cout << "Informations about the game";
                break;
            case 3: 
                cout << "See you!!";
                break;
        }
    }
    
}

void menu(){
    cout << "\nWelcome to the game";
    cout << "\n1 - Start";
    cout << "\n2 - About";
    cout << "\n3 - Exit";
    cout << "\nChoose the number of option that you'd like:\t";
}