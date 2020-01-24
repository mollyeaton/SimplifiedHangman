//
// Created by Molly on 1/23/20.
//
//#include <boost/algorithm/string.hpp>
#include "HangmanGame.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

inline HangmanGame::HangmanGame()
{
    displayMessage();
    guesses = 0;

    word = pickWord();
    hiddenWord = hideWord(word);
}

inline void HangmanGame::displayMessage()
{
    cout << "Welcome to the Hangman Game!\nThe computer will choose a random word from the '1000 most common words'"<< endl;
    cout << "You will have a maximum of 10 guesses. Feel free to guess the full word at any point." << endl;

}

inline string HangmanGame::pickWord()
{
    srand((unsigned) time(0));
    vector <string> wordVec;
    string readWord;
    ifstream fIn;
    //find the csv file and open it
    fIn.open(string("../") + "1-1000.txt");
    while (fIn && fIn.peek() != EOF)
    {
        getline(fIn, readWord);
        wordVec.push_back(readWord);
    }
    int wordChoice = (rand() %1000);

    fIn.close();
    return wordVec[wordChoice];
}

inline string HangmanGame::hideWord(string word)
{
    //initialize empty string
    string hidden = "";
    //loop through the word
    for (int i = 0; i < word.length(); i++)
    {
        hidden+="*";
    }

    return hidden;

}

inline string HangmanGame::checkGuess(string word, string hiddenWord, string guess)
{
    //declare temporary string
    string tempHidden = "";
    //loop through the word
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == tolower(guess[0])) //character is equal
            tempHidden += guess[0]; //add character to string
        else if (hiddenWord[i] != ('*')) //letter was already guessed
            tempHidden += hiddenWord[i]; //add previously guessed character to string
        else //guess was not correct
            tempHidden += "*"; //keep character hidden
    }

    return tempHidden;

}

inline void HangmanGame::increaseGuess()
{
    guesses ++;
}

inline int HangmanGame::getGuesses()
{
    return guesses;
}

inline std::string HangmanGame::getWord()
{
    return word;
}

inline std::string HangmanGame::getHiddenWord()
{
    return hiddenWord;
}

inline void HangmanGame::setHiddenWord(string hWord)
{
    hiddenWord = hWord;
}