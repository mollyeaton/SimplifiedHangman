// Molly Eaton
// CS 120
// Project 1

/*
 * The HangmanGame.h file contains all function declarations and private fields.
 * Private fields:
 * string word : the word that will be guessed in the game
 * string hiddenWord : the version of the word that shows correct guesses and what's left to be guessed
 * int guesses : the current count of number of guesses taken
 * Public functions:
 * displayMessage() ; pickWord() ; hideWord() ; checkGuess() ; increaseGuess() ; getGuesses() ; getWord()
 * getHiddenWord() ; setHiddenWord()
 */

#ifndef MOLLYEATONPROJECT1_HANGMANGAME_H
#define MOLLYEATONPROJECT1_HANGMANGAME_H

#include <vector>
#include <fstream>
#include <iostream>

class HangmanGame
{
private:
    std::string word;
    std::string hiddenWord;

    int guesses ;

public:

    HangmanGame();

    static void displayMessage();

    static std::string pickWord();

    static std::string hideWord(std:: string word);

    static std::string checkGuess(std::string word, std::string hiddenWord, std::string guess);

    void increaseGuess();

    int getGuesses();

    std::string getWord();

    std::string getHiddenWord();

    void setHiddenWord(std::string hWord);

};

#endif //MOLLYEATONPROJECT1_HANGMANGAME_H
