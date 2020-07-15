#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void cleanScreen()
{
    system("clear");
}

string word()
{

    string words[5] = {"car", "orange", "book", "monkey", "lion"};

    int number = rand() % 5;

    return words[number];
}

string checkWord(string word, string mask, char letter, int *time)
{

    int length = word.size();
    int count = 0;

    while (count < length)
    {

        if (word[count] == letter)
        {
            mask[count] = word[count];
        }
        else
        {

            if (*time == 0)
            {
                *time = 1;
            }
            else
            {
                *time = 0;
            }
        }
        count++;
    }

    return mask;
}

bool tryWord(string word, string trying)
{

    if (word == trying)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//MODO SINGLE PLAYER
void singlePlayer()
{

    
    string wordSecret = word();
    int length = wordSecret.size();

    string mask;
    int count = 0;

    while (count <= length - 1)
    {
        mask += "_";
        count++;
    }

    bool loop = true;
    int tries = 0;
    char letter;
    string trying;
    int time = -1;

    while (loop)
    {
        if (tries > (length + 3))
        {
            cleanScreen();
            cout << "\n You lost the game!! ";
            break;
        }

        if (tries != 0)
        {
            cleanScreen();
            mask = checkWord(wordSecret, mask, letter, &time);
        }

        cout << ">> Option selected SINGLE PLAYER <<" << "\n";
        cout << "word > " << mask <<  " length " << length << "\n";

        cout << "Tries >> " << tries << "\n";
        cout << "Write a letter or write # to try the word:\t";
        cin >> letter;

        if (letter == '#')
        {

            cout << "\n";
            cin >> trying;

            if (tryWord(wordSecret, trying))
            {
                cleanScreen();
                cout << " >>> You WIN !! <<< \n";
                cout << ">> TOTAL OF TRIES | " << tries << " |";

                break;
            }
            else
            {
                cleanScreen();
                cout << ">>> You LOST !! <<<";
                break;
            }
        }
        tries++;
    }
}

//MODO MULTIPLAYER

void multiplayer()
{

    // Main variables
    int player1 = 0, player2 = 0; 
    string wordSecret = word();
    int lengthword = wordSecret.size();
    string mask;
    int count1 = 0;
    bool loop = true;
    int timePlayer = 0; // |0| é a time the player 1, e |1| é time the player 2
    char letter;
    string trying;
    //----------------------------------------------------------------------------------

    //Creating the mask to word selected
    while (count1 < lengthword)
    {
        mask += "_";
        count1++;
    }

    //Loop Visual
    while (loop)
    {
        if(mask == wordSecret){
            cout << "\n Nobody try the word correctly";
            break;
        }

        cout << "word >> " << mask << "( length " << mask.size() << ")\n";

        //PLAYER 1
        if (timePlayer == 0)
        {

            cout << "Player 1 >> Total of tries |" << player1 << "| \n";
            cout << "Write a letter or write # to try the word:\t";
            cin >> letter;

            if (letter == '#')
            {

                cout << "\n";
                cin >> trying;

                if (tryWord(wordSecret, trying))
                {
                    cleanScreen();
                    cout << " >>> You WIN PLAYER 1!! <<< \n";
                    cout << ">> TOTAL OF TRIES | " << player1 << " |";
                    break;
                }
                else
                {
                    cleanScreen();
                    cout << ">>> You LOST !! <<<";
                    break;
                }
            }
            else
            {
                mask = checkWord(wordSecret, mask, letter, &timePlayer);
                cleanScreen();
                player1++;
            }
        }
        //PLAYER 2
        else
        {

            cout << "Player 2 >> Total de tentaivas |" << player2 << "| \n";
            cout << "Digite uma letter ou digite # para arriscar uma word:\t";
            cin >> letter;

            if (letter == '#')
            {
                cout << "\n";
                cin >> trying;

                if (tryWord(wordSecret, trying))
                {
                    cleanScreen();
                    cout << " >>> You WIN PLAYER 2!! <<< \n";
                    cout << ">> TOTAL OF TRIES | " << player2 << " |";

                    break;
                }
                else
                {
                    cleanScreen();
                    cout << ">>> You LOST PLAYER 2!! <<<";
                    break;
                }
            }
            else
            {
                mask = checkWord(wordSecret, mask, letter, &timePlayer);
                cleanScreen();
                player2++;
            }
        }
    }
}

//MENU GAME
void menu()
{

    int op = 0;

    cout << "----> MENU PRINCIPAL <---- \n";
    cout << "1 - Single player \n";
    cout << "2 - Multiplayer \n";
    cout << "3 - Exit \n";
    cout << " Select one of options above: \t";

    cin >> op;

    switch (op)
    {
    case 1:
        //SINGLE PLAYER
        cleanScreen();
        singlePlayer();
        break;

    case 2:
        //MULTIPLAYER
        cleanScreen();
        cout << ">> Option selected MULTIPLAYER << \n";
        multiplayer();
        break;

    case 3:
        system("exit");

        break;

    default:
        cleanScreen();
        menu();
        break;
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    menu();

    return 0;
}
