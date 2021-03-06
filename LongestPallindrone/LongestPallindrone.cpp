// LongestPallindrone.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <unordered_map>


// Given a string of lowercase or uppercase characters
// find the length of the longest pallindromes that 
// can be built with those letters
// this is case sensitive
// for example, "Mm" is not considered a palindrome here
// largest input string = 1010

std::unordered_map<char, int> Characters;
void CountCharacters(std::string szString)
{
	printf("\n Input String = %s", szString.c_str());

	for (int x = 0; x < szString.size(); x++) {
		Characters[szString[x]] = Characters[szString[x]]++;
	}

	// output count results
	printf("\nCharacter Count Results");
	for (auto itMap = Characters.begin(); itMap != Characters.end(); ++itMap) {
		printf("\nKey: %c,  Value: %d", itMap->first, itMap->second);
	}

	// determine longest possible
	int iCount = 1;
	for (auto itMap = Characters.begin(); itMap != Characters.end(); ++itMap) {
		iCount += itMap->second % 2;
	}
	iCount *= 2;
	iCount++;
	printf("\n Largest Pallindrone: %d", iCount);

}


int main()
{

	std::string szString = "abccccdd";

	CountCharacters(szString);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
