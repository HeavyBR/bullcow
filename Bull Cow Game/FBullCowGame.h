#pragma once
#include <string>


using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


enum class EWordStatus
{
	INVALID_STATUS,
	OK,
	NOT_ISOGRAM,
	LESS_LENGHT,
	NOT_LOWERCASE

};


class FBullCowGame
{
public:

	FBullCowGame(); // Constructor


	void Reset(); //TODO, make a more rich return value
	int32 GetMaxTries() const;  
	bool isGameWon() const;
	EWordStatus CheckGuessValidity(FString guess);
	int32 GetCurrentTry() const;
	int32 GetHiddenWord() const;

	FBullCowCount SubmitGuess(FString);


private:

	int32 myCurrentTry ;
	int32 myMaxTries;
	FString myHiddenWord;
	bool isgamewon;
};