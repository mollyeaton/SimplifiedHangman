//Molly Eaton
//CS 120
//Project 1

/*
 * This is the main driver for the Hangman Game project.
 * A game object is created and the file loops through until the game is won or lost.
 */

#include <iostream>
#include "HangmanGame.h"


using namespace std;
int main(){
    //declare the maximum number of guesses allowed
    const int MAX_GUESSES = 15;

    //create a new game object
    HangmanGame game;

    //while loop to continue game until the user runs out of guesses or guessed the word
    while (game.get_guesses() < MAX_GUESSES && game.get_hidden_word().find('*') != std::string::npos){
        //display the hidden word and number of incorrect guesses
        cout << "Word: " << game.get_hidden_word() << ", Guesses taken: " << game.get_guesses() << endl;

        //user input is the guess
        string letter_guess;
        cout << "Enter your guess: ";
        cin >> letter_guess ;

        //exit the loop if the guess was the correct word
        if (letter_guess == game.get_word()){
            //set the hidden word the original word
            game.set_hidden_word(game.get_word());
            break;
        }

        //check if the guess is included in the word
        game.set_hidden_word(game.check_guess(game.get_word(), game.get_hidden_word(), letter_guess));
        //increase the number of guesses with each iteration of the loop
        game.increase_guess();
    }

    //if exited the loop then the player either guessed the word
    //or ran out of guesses
    if (game.get_hidden_word()==(game.get_word())){
        cout <<"Congratulations, you guessed it! The word was " << game.get_word();
    }
    else {
        cout << "Out of tries! The word was " << game.get_word();
    }

};