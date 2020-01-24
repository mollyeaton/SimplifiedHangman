//Molly Eaton
//CS 120
//Project 1

/*
 * This is the main driver for the Hangman Game project.
 * This file contains the main class and does the footwork.
 * A game object is created and a random word will be chosen to play with. The player has 15 guesses to
 * try and guess the word. While the player is guessing, the program loops through multiple functions to keep the
 * word hidden until the player either guesses the word or runs out of choices. The into and final messages are
 * displayed within this file.
 */

#include <iostream>
#include "HangmanGame.h"


using namespace std;
int main()
{
    //declare the maximum number of guesses allowed
    const int MAX_GUESSES = 15;

    //create a new game object
    HangmanGame game;

    //while loop to continue game until the user runs out of guesses or guessed the word
    while (game.getGuesses() < MAX_GUESSES && game.getHiddenWord().find('*') != std::string::npos)
    {
        //display the hidden word and number of incorrect guesses
        cout << "Word: " << game.getHiddenWord() << ", Guesses taken: " << game.getGuesses() << endl;

        //user input is the guess
        string letterGuess;
        cout << "Enter your guess: ";
        cin >> letterGuess ;

        //exit the loop if the guess was the correct word
        if (letterGuess == game.getWord())
        {
            //set the hidden word the original word
            game.setHiddenWord(game.getWord());
            break;
        }

        //check if the guess is included in the word
        game.setHiddenWord(game.checkGuess(game.getWord(), game.getHiddenWord(), letterGuess));
        //increase the number of guesses with each iteration of the loop
        game.increaseGuess();
    }

    //if exited the loop then the player either guessed the word
    //or ran out of guesses
    if (game.getHiddenWord()==(game.getWord()))
    {
        cout <<"Congratulations, you guessed it! The word was " << game.getWord();
    }
    else
    {
        cout << "Out of tries! The word was " << game.getWord();
    }

};