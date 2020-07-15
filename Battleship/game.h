#ifndef GAME_H
#define GAME_H

void cleanScreen();
void game();
void menu();
void startGameBoard(char gameBoard[10][10], char mask[10][10]);
void positioningBoat(char gameBoard[10][10]);
void showGameBoard(char gameBoard[10][10]);
void optionAfterGame(int *score);
bool isValid(int move);
#endif