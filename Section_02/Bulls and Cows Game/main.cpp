#include <iostream>
#include <string>
using namespace std;

int main()
{
	//introduce the game
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows, a cool child-friendly word game!" << endl;
	cout << "Can you guess the " << WORD_LENGTH; 
	cout << " letter isogram I'm thinking of?" 
	<< endl;

	//get a guess form the player
	cout << endl;

	cout << "Take a guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << endl;

	//repeat the guess
	cout << "Your answer was: " << Guess; 
	cout << "! Nice Try!" 
		<< endl;

	//ask again

	cout << endl;
	cout << "Take a guess: ";
	getline (cin, Guess);
	cout << endl;

	//repeat the answer
	
	cout << "Your answer was: " << Guess;
	cout << "! Good one!"
		<< endl;
	
	return 0;
}