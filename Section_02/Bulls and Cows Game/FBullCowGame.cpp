#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map 

using int32 = int;

FBullCowGame::FBullCowGame() {	Reset(); }  // default constructor


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3, 6}, {4, 6}, {5, 9}, {6, 14}, {7, 18} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{

	const FString HIDDEN_WORD = "donkey"; // this MUST be an ISOGRAM!!
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guess isn't an isogram 
	{
		return EGuessStatus::Not_Isogram; // return an error
	}
	else if (!IsLowerCase(Guess)) 
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

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter strings as isograms
	if (Word.length() <= 1) { return true; }

	TMap <char, bool> LetterSeen; //setup our map
	for (auto Letter : Word)   // for all letters of the word 
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) { // if the letter is in the map
			return false; // we do NOT have an isogram
		}
		else 
		{
			LetterSeen[Letter] = true;
		}
			
				
			// otherwise
				// add the letter to the map as seen
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word) 
	{
		if (!islower(Letter)) 
		{
			return false;
		}
	}
	return true;
}
