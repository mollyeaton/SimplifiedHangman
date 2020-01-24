//Molly Eaton
//CS 120
//Project 1

/*
 * The HangmanGame.cpp file is the source code for all of the functions used. All declared functions are given
 * their actual functionality in this file.
 */

#include "HangmanGame.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//default constructor
/**
 * Requires: nothing
 * Modifies: word, hiddenWord, guesses
 * Effects:  Returns nothing
 */
HangmanGame::HangmanGame(){
    display_message();
    f_guesses = 0; //initialize the guesses

    f_word = pick_word(); //choose the word & initialize variable
    f_hidden_word = hide_word(f_word); //hide the word & initialize the word
}

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  displays the introduction message
 */
void HangmanGame::display_message(){
    //display the into messages
    cout << "Welcome to the Hangman Game!\nThe computer will choose a random word from the '1000 most common words'"<< endl;
    cout << "You will have a maximum of 10 guesses. Feel free to guess the full word at any point." << endl;

}

/**
 * Requires: nothing
 * Modifies: word
 * Effects:  returns string. loads the words from a file into a temp vector and picks one randomly
 */
string HangmanGame::pick_word(){
    //seed the random number generator
    srand((unsigned) time(0));

    //create vector to hold all of the words pulled in
    vector <string> word_vec;
    string read_word; //create variable to hold each word read in

    //create the input stream for the file
    ifstream f_in;
    //find the text file and open it
    f_in.open(string("../") + "1-1000.txt");
    //while the file still has information and is good
    while (f_in && f_in.peek() != EOF){
        //read in each line and store in the temp variable
        getline(f_in, read_word);
        word_vec.push_back(read_word); //add the word to the vector
    }
    //use the random number generator to pick a number between 0-1000
    int word_choice = (rand() %1000);

    f_in.close(); //close the file

    //the word at the random index in the vector will be the word used
    return word_vec[word_choice];
}

/**
 * Requires: string word
 * Modifies: hiddenWord
 * Effects:  returns string. loops through the words and replaces all characters with '*'
 */
string HangmanGame::hide_word(string p_word){
    //initialize empty string
    string hidden = "";
    //loop through the word
    for (int i = 0; i < p_word.length(); i++){
        //add an asterick for every letter in the word
        hidden+="*";
    }

    return hidden;
}

/**
 * Requires: string word, string hiddenWord, string guess
 * Modifies: hiddenWord
 * Effects:  returns string. compares the word with the guess and updates the hiddenWord to reflect guess.
 */
string HangmanGame::check_guess(string p_word, string p_hidden_word, string p_guess){
    //declare temporary string
    string temp_hidden = "";
    //loop through the word
    for (int i = 0; i < p_word.length(); i++){
        if (p_word[i] == tolower(p_guess[0])) //character is equal
            temp_hidden += p_guess[0]; //add character to string
        else if (p_hidden_word[i] != ('*')) //letter was already guessed
            temp_hidden += p_hidden_word[i]; //add previously guessed character to string
        else //guess was not correct
            temp_hidden += "*"; //keep character hidden
    }

    return temp_hidden;
}

/**
 * Requires: nothing
 * Modifies: guesses
 * Effects:  increases the guess count by 1
 */
void HangmanGame::increase_guess(){
    f_guesses ++; //increase the number of guesses used
}

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns int guesses
 */
int HangmanGame::get_guesses(){
    return f_guesses; //return the number of guesses used
}

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns string word
 */
std::string HangmanGame::get_word(){
    return f_word; //return the word that is being used in the game
}

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  returns string hiddenWord
 */
std::string HangmanGame::get_hidden_word(){
    return f_hidden_word; //return the hidden version of the word being used
}

/**
 * Requires: string hWord
 * Modifies: hiddenWord
 * Effects:  changes the hiddenWord to the parameter
 */
void HangmanGame::set_hidden_word(string p_hidden_word){
    f_hidden_word = p_hidden_word; //set the hidden word
}