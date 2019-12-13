#pragma once
#include <string>



class FBullCowGame {
public:  
	void Reset(); // TO DO make a more rich return value

	int GetMaxTries();
	int GetCurrentTry();

	bool IsGameWon();
	bool CheckGuessValidity(std::string); // TO DO make a more rich return value


private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	bool IsIsogram(std::string);
};
