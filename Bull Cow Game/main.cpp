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
void print_game_summary();
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
		while(!BCGame.isGameWon() && BCGame.GetCurrentTry() < MaxTries)
		{
			guess = get_guess(guess);
			FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
		}

		print_game_summary();
	}


	void print_info()
	{


		std::cout << "Welcome to Bulls and Cows game!" << std::endl;
		std::cout << "Can you guess the " << BCGame.GetHiddenWord() << " letter isogram i'm thinking off?" << std::endl;



		return;
	}

	FText get_guess(FText otherGuess)
	{

		EWordStatus Status = EWordStatus::INVALID_STATUS;
		do {
			std::cout << "Please type your guest: " << std::endl;
			getline(std::cin, otherGuess);
			Status = BCGame.CheckGuessValidity(otherGuess);


			switch (Status)
			{

			case EWordStatus::LESS_LENGHT:

				std::cout << "Please, type a " << BCGame.GetHiddenWord() << " letters string" << std::endl;

				break;
			case EWordStatus::NOT_ISOGRAM:

				std::cout << "Please, type a isogram string" << std::endl;

				break;

			case EWordStatus::NOT_LOWERCASE:

				std::cout << "Please, type in lowercase letters" << std::endl;

			default:

				return otherGuess;

			}

			std::cout << std::endl;

		} while (Status != EWordStatus::OK);




	}

	void print_guess(FText guess)
	{

		std::cout << "Your guess is: " << guess << std::endl;

	}

	bool ask_to_play_again()
	{
		std::cout << "Do you want to play again Y/N ?" << std::endl;

		FText Response = "";

		getline(std::cin, Response);

		return (Response[0] == 'y') || (Response[0] == 'Y');
	}


void print_game_summary()
{
	if(BCGame.isGameWon())
	{
		std::cout << "You win !!!!" << std::endl;
	}

	else
	{
		std::cout << "Better luck next time!\n";
	}

}
