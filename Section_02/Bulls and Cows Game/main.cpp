#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

//the entry point
int main()
{
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
	
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a cool child-fristd::endly word game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?"
		<< std::endl;
	return;
}


void PlayGame()
{
	 // make an instant of a new game
	FBullCowGame BCGame;
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	//loop for the number of turns asking for guesses

	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		//repeat the guess
		std::cout << "Your answer was: " << Guess;
		std::cout << "! Nice Try!"
			<< std::endl;

	}
}



std::string GetGuess() {

	FBullCowGame BCGame;
	int CurrentTry = BCGame.GetCurrentTry();
	//get a guess form the player

	std::cout << std::endl;
	
	std::cout << "Try " << CurrentTry << ". Take a guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
	 
}

bool AskToPlayAgain()
{
	std::cout << "Would you like to play again? (y/n) ";
	std::cout << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}


	
