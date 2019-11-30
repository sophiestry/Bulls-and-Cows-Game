#include <iostream>
#include <string>
using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();


//the entry point
int main()
{
	PrintIntro();

	GetGuessAndPrintBack();
	GetGuessAndPrintBack();

	cout << endl;
	return 0;
}

//introduce the game
void PrintIntro() {
	
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows, a cool child-friendly word game!" << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?"
		<< endl;
	return;
}

//get a guess form the player
string GetGuessAndPrintBack() {

	cout << endl;

	cout << "Take a guess: ";
	string Guess = "";
	getline(cin, Guess);


	//repeat the guess
	cout << "Your answer was: " << Guess;
	cout << "! Nice Try!"
		<< endl;

	return Guess;
}


	
