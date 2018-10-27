// Guess The Number PvAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Things to add:
//random number generator.
//random number guesser for the ai.
//number retriever for the player.
//number comparator.
//who is closer.
//health tracker.
//health subtractor.
//end when player or ai reaches zero health.
//make all of the code pretty.


#include "pch.h"
#include <iostream>
#include <random>

int menuChoice;
int playerHealth = 20;
int aiHealth = 20;
int playerGuess;

int main()
{
	std::cout << "** Welcome to Guess the Number **\n\nFor help press 1.\n\nTo start playing press 2.\n\nTo exit press 3.\n\n";
	std::cin >> menuChoice;
	if (menuChoice < 1 || menuChoice>3) 
	{
		std::cout << "Invalid Choice, Please Pick 1, 2, or 3.\n\n\n";
	}
	if (menuChoice == 1) 
	{
		std::cout << "\nAt the start of each turn the computer will pick a random number ranging from 1 to 10.\n"<<
			"You will then be asked to guess a number.\n"<<
			"The AI will then pick a number and it will be compared to yours.\n"<<
			"Whoever has the closest number does damage to the other player.\n\n\n";
	}
	if (menuChoice == 2)
	{
		while ((playerHealth > 0) || (aiHealth > 0)) 
		{
			std::cout << "The computer is choosing a number......\n\n";
			std::default_random_engine choosenNumber();
			std::cout << "Player, please choose your number: ";
			std::cin >> playerGuess;


		}
	}
	
	
	
	return 0;

}

