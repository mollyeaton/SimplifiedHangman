//
// Created by Molly on 1/23/20.
//

#include "HangmanGame.h"

using namespace std;

HangmanGame::HangmanGame()
{
    guesses = 0;
    word = getWord();
}

void HangmanGame::displayMessage()
{
    cout << "Welcome to the Hangman Game!\nThe computer will choose a random word from the '1000 most common words'"<<
            "You will have a maximum of 10 guesses. Feel free to guess the full word at any point." << endl;

}

string HangmanGame::getWord()
{
    return "test";
}