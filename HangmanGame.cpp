//
// Created by Molly on 1/23/20.
//

#include "HangmanGame.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

inline HangmanGame::HangmanGame()
{
    displayMessage();
    guesses = 0;
    word = getWord();
}

inline void HangmanGame::displayMessage()
{
    cout << "Welcome to the Hangman Game!\nThe computer will choose a random word from the '1000 most common words'"<<
            "You will have a maximum of 10 guesses. Feel free to guess the full word at any point." << endl;

}

inline string HangmanGame::getWord()
{
    vector <string> wordVec;
    string readWord;
    ifstream fIn;
    //find the csv file and open it
    fIn.open("1-1000.txt");
    while (fIn && fIn.peek() != EOF)
    {
        getline(fIn, readWord);
        wordVec.push_back(readWord);
    }
    int wordChoice = rand() %1000;


    return wordVec[wordChoice];
}