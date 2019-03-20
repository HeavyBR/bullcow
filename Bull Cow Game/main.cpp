/* this is the console executable that makes use of the BullCow class, this acts as the view in a MVC pattern, and as responsable for 
all user interaction, for game logic see the FBullCowGame class*/



#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"



using FText = std::string;
using int32 = int;


void print_info();
void Play_Game();
void print_guess(FText guess);
bool ask_to_play_again();
FBullCowGame BCGame;
FText get_guess(FText guess);


	int main()
	{
		
		
		do {
			print_info();
			Play_Game();
		} while (ask_to_play_again());


		return 0;
	}

	void Play_Game()
	{
		BCGame.Reset();
		int32 MaxTries = BCGame.GetMaxTries();
		//constexpr int32 COUNT = 5;
		FText guess = "";
		for (int32 i = 0; i < MaxTries; i++)
		{
			get_guess(guess);
		}
	}


	void print_info()
	{
		constexpr int32 WORLD_LENGHT = 5;
		
		std::cout << "Welcome to Bulls and Cows game!" << std::endl;
		std::cout << "Can you guess the " << WORLD_LENGHT << " letter isogram i'm thinking off?" << std::endl;
		
		

		return;
	}

	FText get_guess(FText otherGuess)
	{
		if (BCGame.GetCurrentTry() == 1)
			std::cout << "This is your first try \n";

		std::cout << "Please type your guest: " << std::endl;
		getline(std::cin, otherGuess);

		print_guess(otherGuess);

		std::cout << std::endl;
		return otherGuess;
	}

	void print_guess(FText guess)
	{

		std::cout << "Your guess is: " << guess << std::endl;

	}

	bool ask_to_play_again() 
	{
		std::cout << "Do you want to play again y\n ? \n";
		
		FText Response = "";

		getline(std::cin, Response);

		return (Response[0] == 'y') || (Response[0] == 'Y');



	}