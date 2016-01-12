//001 High/Low Guessing Game
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int genNum();
void guess(int i, int score, int total);
void start();

int main()
{
	start();
	return 0;
}

void start()
{
	srand(time(NULL));
	int startNum = genNum();
	printf("Starting number is %i\n", startNum);
	guess(startNum, 0, 0);
}

void guess(int i, int score, int total)
{
	printf("Enter a guess: ");
	string userGuess;
	cin >> userGuess;
	int num = genNum();
	bool correct = (num>=i && userGuess == "higher") || (num < i && userGuess == "lower");

	if (correct) 
	{
		printf("Correct. Number was %i and you guessed %s \n", num, userGuess.c_str());
		score+=1, total+=1;
	}
	else 
	{
		printf("Incorrect. Number was %i and you guessed %s \n", num, userGuess.c_str());
		total+=1;
	}
	
	printf("Continue? (y/n) \n");
	char input;
	cin >> input;
	if((input == 'y' || input == 'Y') && correct)
	{
		guess(num, score, total);
	}
	else if ((input == 'y' || input == 'Y') && !correct) 
	{
		guess(num, score, total);
	}
	else 
	{
		cout << score << endl << total << endl;
		printf("Your score was %i/%i \n", score, total);
		exit(1);
	}

}

int genNum(){return rand()%100 + 1;}