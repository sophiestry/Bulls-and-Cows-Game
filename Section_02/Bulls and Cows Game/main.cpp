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
FText GetGuess();
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
	

	std::cout << "Welcome to Bulls and Cows, a cool child-friendly word game!" << std::endl;
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

	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();  //TODO make loop checking valid

		//Submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print numbers of bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows;
		std::cout << "! Nice try, doug!"
			<< std::endl;

	}
	// TODO add game summary
}



FText GetGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();
	//get a guess form the player

	std::cout << std::endl;
	
	std::cout << "Try " << CurrentTry << ". Take a guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
	 
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again? (y/n) ";
	std::cout << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}


	
