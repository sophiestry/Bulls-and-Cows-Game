/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern and is responsible for all user interaction. For game logic see the FBullCowGame class.

*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

// make an instant of a new game
FBullCowGame BCGame;

//the entry point
int main()
{
	std::cout << BCGame.GetCurrentTry();
	bool bPlayAgain = false;
	do {
		PrintIntro();

		PlayGame();

		std::cout << std::endl;

		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	
	return 0;
	std::cout << std::endl;
}


//introduce the game
void PrintIntro() {

	std::cout << std::endl;
	std::cout <<std::endl;
	std::cout << "Welcome to Bulls and Cows, a very cool word game for intellectuals only!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?"
		<< std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	//loop for the number of turns asking for guesses
	
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries )
	{
		FText Guess = GetValidGuess(); 

		//Submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows;
		std::cout << "! Nice try, doug!"
			<< std::endl;

	}
	// TODO add game summary
}


// loop until the player gives a valid guess
FText GetValidGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();
	//get a guess form the player

	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Take a guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Counting to " << BCGame.GetHiddenWordLength() << " too hard for ya, eh? I thought I knew you. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "I sad an ISOGRAM! Can u read?\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "DON'T YELL AT ME, I'M SENSITIVE!! >:^( \n";
			break;
		default:
			return Guess;

		}
	} while (Status != EGuessStatus::OK); // keep loopin until we get no errors
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to try and not be a failure this time? (y/n) ";
	std::cout << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}


	
