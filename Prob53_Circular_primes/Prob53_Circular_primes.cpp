// Prob53_Circular_primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int CheckPrime(unsigned int n)
{
	int i;
	float sr;
	sr = sqrtf(n);
	for (i = 2; i < sr && n % i != 0; i++);
	if (i > sr)
		return 1; // not 0 true
	return 0;
	// 0 is false
}

int main()
{
	unsigned int i, j, n, digit, temp;
	float sr;
	int prime, digitcount, factor, ctr, primectr = 2; // primectr = 0 (initital) + 2 (algo disregards 2 and 5 )
	//55
	for (i = 2; i < 1000000; i++)
	{
		if (i % 2 != 0 && i % 5 != 0)
		{
			//sr = sqrtf(i);
			//for (j = 3; j <= sr && i % j != 0; j++);
			if (CheckPrime(i))
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
				{
					//no number with even digit is found here
					printf("\n%d", i);
					prime = 1;
					if (i >= 100000)
					{
						digitcount = 5;
						factor = 1000000;
					}
					else if (i >= 10000)
					{
						digitcount = 4;
						factor = 100000;
					}
					else if (i >= 1000)
					{
						digitcount = 3;
						factor = 10000;
					}
					else if (i >= 100)
					{
						digitcount = 2;
						factor = 1000;
					}
					else if (i >= 10)
					{
						digitcount = 1;
						factor = 100;
					}
					else
					{
						digitcount = 0;
					}
					n = i; //recycling variable n here
					for (ctr = 0; ctr < digitcount; ctr++)
					{
						temp = (n % 10) * factor;
						n = n + temp;
						n = n / 10;
						//check if this anagram of n is also prime
						prime = prime && CheckPrime(n);
						printf(" => %d", n);
					}
					if (prime)
					{
						printf("*");
						primectr++;
					}
						
				}
					
			}
		}
	}
	printf("\n\n%d", primectr);
}

/*

int main()
{
	unsigned long int i, n = 123456, temp;
	for (i = 0; i < 5; i++)
	{
		temp = (n % 10) * 1000000;
		n = n + temp;
		n = n / 10;
		printf("\n%d", n);
	}
}
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
