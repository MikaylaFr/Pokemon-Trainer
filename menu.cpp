/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Function implementation file for Menu class. Includes functions that let the program know if
 * they want to continue or quit at the beginning and end of the program. Includes input validation.
 * *********************************************************************/

#include "menu.hpp"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <sstream>
using std::stringstream;

#include <random>

//starting menu function, asks user if they want to start or quit the program. 
//If user wants to quit, program returns false. If the want to continue to the game, returns true.
//Includes input validation
bool Menu::begin()
{
	string input;
	bool cont = true;
	cout << "Choose one of the following:" << endl;
	while (cont)
	{	cout << "(1) Play game" << endl;
		cout << "(2) Quit" << endl;
		getline(cin, input);
	
		if(input[0] == '1' && input.length() == 1)  //input validation
			return true;
		else if(input[0] == '2' && input.length() == 1)
			return false;
		else
			cout<< "Invalid input, please choose one of the menu options." << endl;
	}
	return true;
}

//ending menu function, asks user if they want to keep playing or quit the program.
//If user wants to quit, program returns false. If the want to continue to the simulation, returns true.
//Includes input validation
bool Menu::end()
{
	string input;
	bool cont = true;
	cout << "Play again?" << endl;
	while (cont)
	{       cout << "(1) Yes, continue" << endl;
		cout << "(2) No, quit" << endl;
		getline(cin, input);

		if(input[0] == '1' && input.length() == 1) //input validation
			return true;
		else if(input[0] == '2' && input.length() == 1)
			return false;
		else
		{	
			cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
			cout << "Invalid input" << endl;
			cout << string(49, '=') << endl;
		}
	}
	return true;
}


//Input validation function for positive integers. Accepts strings a parameter, searches string for acceptable characters.
//If user enters unacceptable character, program loops until whole string is acceptable characters.
int Menu::validateInt(string input)
{
 	string entry = input;
	bool cont = true; //loop control
	int number; //integer that will be returned

	while(cont)
	{
		int count = 0;
		int stleng = entry.length(); //length of string
		
		for(int i=0; i<stleng; i++)
		{
			if(entry[i] >= 48 && entry[i] <= 57)
				count++;
		}
			
			if(count != stleng)
			{       cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
				cout << "Invalid input, please enter positive integers only. Try again." << endl;
				cout << string(49, '=') << endl;
				getline(cin, entry);
			}
			else if(count == stleng)
			{       stringstream convert (entry); //create string stream object called convert
								//http://www.cplusplus.com/forum/beginner/58833/
			
				if(convert >> number && !(convert >> entry)) //additional input validation
					return number;
				else
				{	cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
					cout << "Error! Please enter positive integers only. Try again." << endl;
					cout << string(49, '=') << endl;
					getline(cin, entry);
				}
			}
	}
	return true;
}

//Input validation function for names. Accepts strings a parameter, searches string for acceptable characters.
//If user enters unacceptable character, program loops until whole string is acceptable characters.
string Menu::validateName(string input)
{ 	
	string entry = input;
	bool cont = true; //loop control

	while(cont)
	{
		int count = 0;
		int stleng = entry.length(); //length of string
		
		for(int i=0; i<stleng; i++)
		{
			if((entry[i] >= 'a' && entry[i] <= 'z') || (entry[i] >= 'A' && entry[i] <= 'Z') || entry[i] == ' ') 
				count++;
		}
			
			if(count != stleng)
			{       cout << "Invalid input, please enter letters and spaces only. Try again." << endl;
				getline(cin, entry);
			}
			else if(count == stleng)
			{       
				return entry;
			}
	}
	return 0;
}


//Input validation function for positive doubles. Accepts strings a parameter, searches string for acceptable characters.
//If user enters unacceptable character, program loops until whole string is acceptable characters.
double Menu::validateDoub(string input)
{
	string entry = input;
	bool cont = true; //loop control
	double number; //integer that will be returned

	while(cont)
	{
		int count = 0;
		int stleng = entry.length(); //length of string
		
		for(int i=0; i<stleng; i++)
		{
			if((entry[i] >= 48 && entry[i] <= 57) || entry[i] == 46)
				count++;
		}
			
			if(count != stleng)
			{       cout << "Invalid input, please enter positive integers only. Try again." << endl;
				getline(cin, entry);
			}
			else if(count == stleng)
			{       stringstream convert (entry); //create string stream object called convert
								//http://www.cplusplus.com/forum/beginner/58833/
			
				if(convert >> number && !(convert >> entry)) //additional input validation
					return number;
				else
				{	cout << "Error! Please enter positive integers only. Try again." << endl;
					getline(cin, entry);
				}
			}
	}
	return true;

}


 //Input validation function for positive and negative integers. Accepts strings a parameter, searches string for acceptable characters.
 //If user enters unacceptable character, program loops until whole string is acceptable characters.
int Menu::validateAllInt(string input)
{
 	string entry = input;
	bool cont = true; //loop control
	int number; //integer that will be returned

	while(cont)
	{
		int count = 0;
		int stleng = entry.length(); //length of string
		
		for(int i=0; i<stleng; i++)
		{
			if((entry[i] >= 48 && entry[i] <= 57) || entry[i] == 45)
				count++;
		}
			
			if(count != stleng)
			{       cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
				cout << "Invalid input, please enter integers only. Try again." << endl;
				cout << string(49, '=') << endl;
				getline(cin, entry);
			}
			else if(count == stleng)
			{       stringstream convert (entry); //create string stream object called convert
								//http://www.cplusplus.com/forum/beginner/58833/
			
				if(convert >> number && !(convert >> entry)) //additional input validation
					return number;
				else
				{	cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
					cout << "Error! Please enter integers only. Try again." << endl;
					cout << string(49, '=') << endl;
					getline(cin, entry);
				}
			}
	}
	return true;
}

//Fuction that returns a random number between the min and max that is passed to the function. https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
int Menu::randomInt(int min, int max) const
{
	if (min >= max) {
          int temp = min;
          min = max;
          max = temp;
        }
	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<int> randInt(min, max);

	return randInt(gen);
}
