//
// Created by Molly on 1/23/20.
//
#include <iostream>
#include "HangmanGame.cpp"
#include <string>

using namespace std;
int main()
{
    const int MAX_GUESSES = 10;
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


        //string sGuess = string(0,letterGuess);

        if (letterGuess == game.getWord())
        {
            game.setHiddenWord(game.getWord());
            break;
        }
        //check if the guess is included in the word
        game.setHiddenWord(game.checkGuess(game.getWord(), game.getHiddenWord(), letterGuess));
        //if the word does not contain the guess then increase the incorect counter
        game.increaseGuess();
    }

    //if exited the loop then the play either guessed the word
    //or ran out of guessed
    if (game.getHiddenWord()==(game.getWord()))
    {
        cout <<"Congratulations, you guessed it! The word was " << game.getWord();
    }
    else
    {
        cout << "Out of tries! The word was " << game.getWord();
    }



};