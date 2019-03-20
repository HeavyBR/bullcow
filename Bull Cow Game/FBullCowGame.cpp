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

}

int32 FBullCowGame::GetMaxTries () const
{



	return myMaxTries;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString guess)
{
	return false;
}

int32 FBullCowGame::GetCurrentTry() const
{


	return myCurrentTry;
}

FBullCowCount FBullCowGame::SubmitGuess(FString)
{

	myCurrentTry++;
	myMaxTries--;

	FBullCowCount BullCowCount;

	
	return BullCowCount;
}
