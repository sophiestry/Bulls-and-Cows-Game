/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern and is responsible for all user interaction. For game logic see the FBullCowGame class.

*/

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

 // to make syntax Unreal friendly :^)
using FText = std::string;
using int32 = int;

// function prototypes a outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // make an instant of a new game

//the entry point
int main()
{
	
	bool bPlayAgain = false;
	do {
		PrintIntro();

		PlayGame();

		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	
	return 0;
	std::cout << std::endl;
}


//introduce the game
void PrintIntro() {
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Welcome to Bulls and Cows, a very cool word game for intellectuals only!" << std::endl;
	std::cout << std::endl;
	std::cout << "                    { __ }                    A ____A                         " << std::endl;
	std::cout << "                   ( ^  ^ )                  ( U   U )                        " << std::endl;
	std::cout << "       ____________ \\    /                    |     | ____________           " << std::endl;
	std::cout << "     /|              (  )                     ( o o )            | \\         " << std::endl;
	std::cout << "    / |     BULL      |                           |        COW   |  \\        " << std::endl; 
	std::cout << "   *  |_______________|                           |______________|   *        " << std::endl;
	std::cout << "      |  U            |                           |         UUUU |            " << std::endl;
	std::cout << "      ^               ^                           ^              ^            " << std::endl;
	std::cout << "                                                                              " << std::endl;

	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of? \n";
	return;
}


void PlayGame()
{
	BCGame.Reset();
	
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << std::endl;
	//loop for the number of turns asking for guesses
	
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries )
	{
		FText Guess = GetValidGuess(); 

		//Submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows;
		std::cout << "! :^O \n";
		std::cout << std::endl;

	}

	PrintGameSummary();
	return;
}


// loop until the player gives a valid guess
FText GetValidGuess() {

	//get a guess form the player

	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Take a guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Counting to " << BCGame.GetHiddenWordLength() << " too hard for ya, eh? I thought I knew you. \n \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "I sad an ISOGRAM! Can u read? \n \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "DON'T YELL AT ME, I'M SENSITIVE!! >:^( \n \n";
			break;
		default:
			break;

		}
	} while (Status != EGuessStatus::OK); // keep loopin until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to try and prove yourself again? I'll even give u the same word. (y/n) ";
	std::cout << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}


void PrintGameSummary() 
{
	if (BCGame.IsGameWon()) 
	{
		std::cout << "YASSS QUEEN, U WEEN! <3 \n";
	}
	else
	{
		std::cout << "...I'm not mad. I'm just dissapointed. \n";
	}
}
