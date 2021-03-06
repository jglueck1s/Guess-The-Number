// Guess The Number PvAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//add a section that recognizes different numbers that are both the same distance from the generated number. like 3 and 7 are equal distance from 5.
//still need to make all the code pretty.


#include "pch.h"
#include <iostream>
#include <random>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include<Windows.h>

int menuChoice;
char ready;
int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
menu://------------------------------------------------------------------------------menu step
	system("cls");
	int playerHealth = 20;
	int aiHealth = 20;
	int playerGuess;
	int roundNumber = 1;
	std::cout << "** Welcome to Guess the Number **\n\nFor help press 1.\n\nTo start playing press 2.\n\nTo exit press 3.\n\n";
	std::cin >> menuChoice;
	if (menuChoice < 1 || menuChoice>3) 
	{
		system("cls");
		std::cout << "Invalid Choice, Please Pick 1, 2, or 3.\n\n\n";
		system("pause");
		goto menu;
	}
	if (menuChoice == 1) 
	{
		system("cls");
		std::cout << "\nAt the start of each turn the computer will pick a random number ranging from 1 to 10.\n"<<
			"You will then be asked to guess a number.\n"<<
			"The AI will then pick a number and it will be compared to yours.\n"<<
			"Whoever has the closest number does damage to the other player.\n\n\n";
		system("pause");
		goto menu;
	}
	if (menuChoice == 2)
	{
		system("cls");
		while ((playerHealth > 0) && (aiHealth > 0)) 
		{
			system("cls");
		running://-------------------------------------------------------------------running step

			std::cout << "\nPlayer Health: " << playerHealth << std::endl;
			std::cout << "\nAI Health: " << aiHealth;
			std::cout << "\n\n------------------------------------------ROUND #"<<roundNumber<<"----------------------------------------------------\n\n";
			std::cout << "The random number is being generated......\n";
			std::random_device rd;
			std::default_random_engine cG(rd());//------------------------------------Computer Generator.
			std::uniform_int_distribution<int> randomCG(1, 10);//---------------------------Computer choice limited to 1-10.
			int randomCGNumber = randomCG(cG);
			std::cout << "\n\nPlayer One, please choose a number from 1 to 10: ";
			std::cin >> playerGuess;
			while(playerGuess<1||playerGuess>10)
			{
				std::cout << "\nBad Choice. Please pick a number from 1 to 10.\n";
				system("pause");
				system("cls");
				goto running;	
			}
			std::mt19937 aiG(time(NULL));//----------------------------------------------------AI generator
			std::uniform_int_distribution<int> randomAI(1, 10);//------------------------------AI choice limited to 1-10.
			int aiGuess = randomAI(aiG);
			int absplayerDifference = std::abs(playerGuess - randomCGNumber);
			int absAIDifference = std::abs(aiGuess - randomCGNumber);
			system("cls");
			
			
			
			
			if (playerGuess == aiGuess) 
			{
				std::cout << "\nPlayer Health: " << playerHealth << std::endl;
				std::cout << "\nAI Health: " << aiHealth;
				std::cout << "\n\n------------------------------------------ROUND #" << roundNumber << "----------------------------------------------------\n\n";
				std::cout << "You and the AI made the same guess. No one loses.\n\n";
				std::cout << "The number was: " << randomCGNumber << "\n\nYour Choice: " << playerGuess << "\n\nThe AI Choice: " << aiGuess << "\n\n";
			}
			else if (absplayerDifference > absAIDifference) 
			{
				playerHealth = playerHealth - absplayerDifference;
				std::cout << "\nPlayer Health: " << playerHealth << std::endl;
				std::cout << "\nAI Health: " << aiHealth;
				std::cout << "\n\n------------------------------------------ROUND #" << roundNumber << "----------------------------------------------------\n\n";
				std::cout << "You lost "<<absplayerDifference<<" points.\n\n";
				std::cout << "The number was: " << randomCGNumber << "\n\nYour Choice: " << playerGuess << "\n\nThe AI Choice: " << aiGuess << "\n\n";
			}
			else
			{
				aiHealth = aiHealth - absAIDifference;
				std::cout << "\nPlayer Health: " << playerHealth << std::endl;
				std::cout << "\nAI Health: " << aiHealth;
				std::cout << "\n\n------------------------------------------ROUND #" << roundNumber << "----------------------------------------------------\n\n";
				std::cout << "\nThe AI lost "<<absAIDifference<<" points!!\n\n";
				std::cout << "The number was: " << randomCGNumber << "\n\nYour Choice: " << playerGuess << "\n\nThe AI Choice: " << aiGuess << "\n\n";
			}
			roundNumber = roundNumber++;
			system("pause");
			
			}
		}
	if (playerHealth <= 0)
		{
			system("cls");
			std::cout << "\nPlayer Health: " << playerHealth << std::endl;
			std::cout << "\nAI Health: " << aiHealth;
			std::cout << "\n\n------------------------------------------ROUND #" << roundNumber << "----------------------------------------------------\n";
			std::cout << "\n\nYou lose. Better luck next game!\n\n" << std::endl;
			std::cout <<" \\\n"<<
						" /                                 />\n"<<
						" \\__+_____________________/\\/\\___/ /|\n"<<
						" ()______________________      / /|/\\\n"<<
						"             /0 0  ---- |----    /---\\\n"<<
						"            |0 o 0 ----|| - \ --|      \\\n"<<
						"             \\0_0/____/ |    |  |\\     \\\n"<<
						"                         \\__/__/  |      \\\n"<<
						"Bang! Bang!                       |       \\\n"<<
						"                                  |        \\\n"<<
						"                                  |__________|";

			system("pause");
			goto menu;
		}
	if (aiHealth <= 0)
		{
			system("cls");
			std::cout << "\nPlayer Health: " << playerHealth << std::endl;
			std::cout << "\nAI Health: " << aiHealth;
			std::cout << "\n\n------------------------------------------ROUND #" << roundNumber << "----------------------------------------------------\n";
			std::cout << "\n\nYou win! Good luck next game!\n\n" << std::endl;
			system("pause"); 
			goto menu;
		
	}
	if(menuChoice==3)
	{
		return 0;
	}
	
	
	
	return 0;

}

