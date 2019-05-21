// Lotto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void bubblesort(int n, int a[])
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp;
			}
		}
	}
}

int getnumbers()
{
	int n = rand() % 53;
	return n;
}

void printticket(int n[])
{
	for (int i = 0; i < 6; i++) {
		cout << n[i];
		if (i != 5) {
			cout << ", ";
		}
		if (i == 5) {
			cout << "\n";
		}
	}
}

bool thesame(int n[], int m[])
{
	for (int i = 0; i < 6; i++)
	{
		if (n[i] != m[i]) {
			return false;
		}
	}
	return true;
}

void pickednumbers(int n [])
{

	for (int i = 0; i < 6; i++)
	{
		int num = getnumbers();

		if (i == 0) {
			n[i] = num;
		}
		else
		{
			for (int k = 0; k < i;)
			{
				if (num == n[k])
				{
					num = getnumbers();
				}
				else
				{
					k++;
				}
			}
			n[i] = num;
		}

	}

	bubblesort(6, n);
	
}



int main()
{
	srand(time(NULL));
	int LottoT[6];
	int WinningT[6];
	pickednumbers(LottoT);
	cout << "Lotto numbers: ";
	printticket(LottoT);
	bool found = false;
	int count = 0;

	clock_t startTime, endTime;
	
	startTime = clock();
	while (found == false)
	{
		pickednumbers(WinningT);
		if (thesame(LottoT, WinningT) == true) {
			found = true;
		}
		count++;
	}
	// code to be timed goes here
	endTime = clock();
	cout << "Time taken: " << ((double)(endTime - startTime)) / CLOCKS_PER_SEC << "seconds." << endl;
	cout << "Number of draws: " << count << ";  weeks: " << count / 2 << ";  years: " << (count / 2) / 52 << "\n";
	cout << "Winning Ticket: ";
	printticket(WinningT);
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
