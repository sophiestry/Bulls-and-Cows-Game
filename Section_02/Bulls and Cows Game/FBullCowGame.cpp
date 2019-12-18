#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "donkey";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't an isogram, 
	{
		return EGuessStatus::Not_Isogram; // return an error
	}
	else if (false) // if the guess isn't lowercase, 
	{
		return EGuessStatus::Not_Lowercase; // return an error
	}
	else if (Guess.length()  != GetHiddenWordLength()) // if the guess length is wrong, 
	{
		return EGuessStatus::Wrong_Length; // return an error
	}
	else // otherwise
	{
		return EGuessStatus::OK; // return OK
	}
		
}

// receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{

	MyCurrentTry++;

	FBullCowCount BullCowCount;

	// loop through all letters in the hidden word
	int32 WordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{

		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{
			// if the match then 
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{

				if (MHWChar == GChar) {
					BullCowCount.Bulls++; // increment bulls

				}
				else {
					BullCowCount.Cows++; // increment cows if not
				}
			}

		}

	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}