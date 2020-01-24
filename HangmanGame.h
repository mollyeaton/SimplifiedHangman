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

    //std::vector <std::string> wordVec;

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
