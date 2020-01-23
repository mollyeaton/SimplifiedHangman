//
// Created by Molly on 1/23/20.
//

#ifndef MOLLYEATONPROJECT1_HANGMANGAME_H
#define MOLLYEATONPROJECT1_HANGMANGAME_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>



class HangmanGame
{
private:
    std::string word;
    std::string hiddenWord;
    std::string letterGuess;

    int guesses ;
    const int MAX_GUESSES = 10;
    //std::vector <std::string> wordVec;

public:

    HangmanGame();

    static void displayMessage();

    static std::string getWord();

    static std::string hideWord();

    static std::string checkGuess();

    static void increaseGuess();



};

#endif //MOLLYEATONPROJECT1_HANGMANGAME_H
