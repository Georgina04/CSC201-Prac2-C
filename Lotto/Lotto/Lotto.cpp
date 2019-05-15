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
	int n[6];
	pickednumbers(n);
	for (int i = 0; i < 6; i++)
	{
		cout << n[i] << "\n";
	}
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
