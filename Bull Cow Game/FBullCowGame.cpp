#include "pch.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{

	Reset();

}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString MYHIDDENWORD = "planet";
	myHiddenWord = MYHIDDENWORD;

	myCurrentTry = 1;
	myMaxTries = MAX_TRIES;
	isgamewon = false;

}

int32 FBullCowGame::GetMaxTries () const
{



	return myMaxTries;
}

bool FBullCowGame::isGameWon() const
{



	return isgamewon;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString guess)
{



	if (false) // If its not a isogram
	{
		return EWordStatus::NOT_ISOGRAM;
	}
	else if (false) // If its not lowercase
	{
		return EWordStatus::NOT_LOWERCASE;
	}
	else if (myHiddenWord.length() != guess.length()) // If its less lenght then magic word
	{

		return EWordStatus::LESS_LENGHT;

	}
	else
	{
		return EWordStatus::OK; // everything is ok
	}



}

int32 FBullCowGame::GetCurrentTry() const
{


	return myCurrentTry;
}

int32 FBullCowGame::GetHiddenWord() const
{



	return myHiddenWord.length();
}

FBullCowCount FBullCowGame::SubmitGuess(FString SubmitedGuess)
{
	// Incrementa a tentativa
	myCurrentTry++;
		
	//Cria uma variável de retorno
	FBullCowCount BullCowCount;
	int32 HiddenWordLenght = myHiddenWord.length();
	//Loop em todas as letras do guess
	for (int32 i = 0; i < HiddenWordLenght; i++)
	{
		//compara as letras com a palavra correta
		for (int32 j = 0; j < HiddenWordLenght; j++)
		{
			if (SubmitedGuess[j] == myHiddenWord[i])		//and //nda
			{
				if (i == j) 
				{ 
					BullCowCount.Bulls++; 
				}

				else 
				{ 
					BullCowCount.Cows++; 

				} //incrementa cows
			}
			// se não forem iguais
			
		}

	}
	
	if (BullCowCount.Bulls == HiddenWordLenght)
		isgamewon = true;
	else
		isgamewon = false;

	return BullCowCount;
}
