// Race.cpp : Defines the entry point for the console application.
// Filename Race.cpp
// Written by: Kurt Whalen
// Written on: 2/11/14

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using namespace std;

char T;
char H;
char trackT[70] = {T};
char trackH[70] = {H};


char move(int x, char* arr, char a) /*moves tortoise and hare*/
{
	arr[a] = 0;
	arr[x] = a;
	return arr[a, x];
}

int moveH(int x) /*moves hare*/
{
	trackH[H] = 0;
	trackH[x] = H;
	return trackH[H];
}

int tortoise(int i) /*plug in rand number and get the proper array movement*/
{
	int mT;	/*value goes into moveT() function*/
	if (0 <= i && i <= 39)  /*since rand() %100 will be able to make numbers 0-99 the limits had to be set this way*/
		mT = trackT[T] + 4;
	else if (40 <= i && i <= 49)
		mT = trackT[T] - 2;
	else if (50 <= i && i <= 99)
		mT = trackT[T] + 2;
	
	if (mT < 1) /*ensures T doesn't run off the array*/
		mT = 0;
	else if (mT > 69)
		mT = 69;
	return mT;
}

int hare(int i) /*plug in rand number to get the proper array movement*/
{
	int mH;	/*value goes into moveT() function*/
	if (0 <= i && i <= 29)  /*since rand() %100 will be able to make numbers 0-99 the limits had to be set this way*/
		mH = trackH[H];
	else if (30 <= i && i <= 54)
		mH = trackH[H] + 10;
	else if (55 <= i && i <= 69)
		mH = trackH[H] - 15;
	else if (70 <= i && i <= 79)
		mH = trackH[H] + 5;
	else if (80 <= i && i <= 99)
		mH = trackH[H] - 3;
	
	if (mH < 1) /*ensures H doesn't run off the array*/
		mH = 0;
	else if (mH > 69)
		mH = 69;
	return mH;
}


int main()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << "BANG !!!" <<endl << "AND THEY'RE OFF !!!" << endl;
		while (trackT[T] < 69 || trackH[H] < 69);
		{
			int num = rand() % 100;
			int mH = hare(num);
			int mT = tortoise(num);

			move(mH, trackT, T);
			move(mT, trackH, H);

			for (int i = 0; i < 70; i++) /*loop that prints the hare line of the race*/
			{
				if (trackH[i] == 0)
					cout << "_";
				else if (trackH[i] == H)
					cout << "H";
			}
			cout << endl;

			for (int i = 0; i < 70; i++) /*loop that prints the tortoise line of the race*/
			{
				if (trackT[i] == 0)
					cout << " ";
				else if (trackT[i] == T)
					cout << "T";
			}
			cout << endl;

			if (trackH[H] == 69 && trackT[T] == 69) /*end conditions printout*/
				cout << "It's a tie." << endl;
			else if (trackH[H] == 69)
				cout << "Hare wins. Yuck." << endl;
			else if (trackT[T] == 69)
				cout << "TORTOISE WINS!!! YAY!!!" << endl;

		}
	}
	
	return 0;
}

