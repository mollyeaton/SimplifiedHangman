//Molly Eaton
//CS 120
//Project 1

#include "HangmanGame.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//default constructor
HangmanGame::HangmanGame()
{
    displayMessage();
    guesses = 0; //initialize the guesses

    word = pickWord(); //choose the word & initialize variable
    hiddenWord = hideWord(word); //hide the word & initialize the word
}

void HangmanGame::displayMessage()
{
    //display the into messages
    cout << "Welcome to the Hangman Game!\nThe computer will choose a random word from the '1000 most common words'"<< endl;
    cout << "You will have a maximum of 10 guesses. Feel free to guess the full word at any point." << endl;

}

string HangmanGame::pickWord()
{
    //seed the random number generator
    srand((unsigned) time(0));

    //create vector to hold all of the words pulled in
    vector <string> wordVec;
    string readWord; //create variable to hold each word read in

    //create the input stream for the file
    ifstream fIn;
    //find the text file and open it
    fIn.open(string("../") + "1-1000.txt");
    //while the file still has information and is good
    while (fIn && fIn.peek() != EOF)
    {
        //read in each line and store in the temp variable
        getline(fIn, readWord);
        wordVec.push_back(readWord); //add the word to the vector
    }
    //use the random number generator to pick a number between 0-1000
    int wordChoice = (rand() %1000);

    fIn.close(); //close the file

    //the word at the random index in the vector will be the word used
    return wordVec[wordChoice];
}

string HangmanGame::hideWord(string word)
{
    //initialize empty string
    string hidden = "";
    //loop through the word
    for (int i = 0; i < word.length(); i++)
    {
        //add an asterick for every letter in the word
        hidden+="*";
    }

    return hidden;
}

string HangmanGame::checkGuess(string word, string hiddenWord, string guess)
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

void HangmanGame::increaseGuess()
{
    guesses ++; //increase the number of guesses used
}

int HangmanGame::getGuesses()
{
    return guesses; //return the number of guesses used
}

std::string HangmanGame::getWord()
{
    return word; //return the word that is being used in the game
}

std::string HangmanGame::getHiddenWord()
{
    return hiddenWord; //return the hidden version of the word being used
}

void HangmanGame::setHiddenWord(string hWord)
{
    hiddenWord = hWord; //set the hidden word
}