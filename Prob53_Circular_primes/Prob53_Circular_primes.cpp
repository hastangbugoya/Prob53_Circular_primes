// Prob53_Circular_primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	unsigned int i, j, n, digit;
	float sr;
	for (i = 1; i < 1000000; i++)
	{
		if (i % 2 != 0)
		{
			sr = sqrtf(i);
			for (j = 3; j <= sr && i % j != 0; j++);
			if (j > sr)
			{
				n = i;
				
				while (n > 0)
				{
					digit = n % 10;
					if (digit % 2 == 0 || digit == 5)
						break;
					n = n / 10;
				}
				if (n <= 0)
					printf("\n%d", i);
			}
		}
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
