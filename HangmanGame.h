// Molly Eaton
// CS 120
// Project 1

/*
 * The HangmanGame.h file contains all function declarations and private fields.
 */

#ifndef MOLLYEATONPROJECT1_HANGMANGAME_H
#define MOLLYEATONPROJECT1_HANGMANGAME_H

#include <vector>
#include <fstream>
#include <iostream>

class HangmanGame{
private:
    //fields
    std::string f_word;
    std::string f_hidden_word;

    int f_guesses ;

public:
    //default constructor
    HangmanGame();

    //game functions
    static void display_message();

    static std::string pick_word();

    static std::string hide_word(std:: string p_word);

    static std::string check_guess(std::string p_word, std::string p_hidden_word, std::string p_guess);

    void increase_guess();

    //getters
    int get_guesses();

    std::string get_word();

    std::string get_hidden_word();

    //setter
    void set_hidden_word(std::string p_hidden_word);

};

#endif //MOLLYEATONPROJECT1_HANGMANGAME_H
