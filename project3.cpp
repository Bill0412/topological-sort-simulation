#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <iostream>
#include "target.h"
#define MAXN 10001

int Bucket[10001];
int HashTable[MAXN];

int is_prime(int n)
{
	if(n == 2 || n == 3) {
		return 1;
	}
	if(n == 1 || n == 0) {
		return 0;
	}

	int max = (int) sqrt(n);

	for(int i = 2; i <= max; i ++) {
		// if divides
		if(! (n % i)) {
			return 0;
		}
	}

	return 1;
}

// n is an integer, the function returns a prime next to n
int get_next_prime(int n)
{
	for(int i = n; 1; i++) {
		if(is_prime(i)) {
			// printf("prime: %d\n", i);
			return i;
		}
	}
}

int generateRandomInteger(int min, int max)
{

	return min + rand() % (max - min);
}

int generateRandomUniqueInteger(int min, int max)
{
	int res;
	while(Bucket[res = generateRandomInteger(min, max)]);
	Bucket[res] = 1;

	return res;
}

// linear probing applied
int main() {
	// printf("%d", generateRandomInteger(0, 100));
	srand((unsigned)time(0));
	int N, a, count;
	N = 2000;//generateRandomInteger(1, 1000);
	N = get_next_prime(N);
	printf("Hash Table Size: %d\n", N);
	count = N / 3; //generateRandomInteger(1 , N / 10);
	printf("Number of Integers to be inserted: %d\n", count);

	printf("Number Generated: ");
	for(int i = 0; i < count; i++){
		int m = generateRandomUniqueInteger(1, 10000);

		printf("%d ", m);
		int index = m % N;

		for(int j = index; j < index + N; j++) {
			int t = j % N;
			if(!HashTable[t]) {
				HashTable[t] = m;
				break;
			}
		}
	}

	printf("\n\nHash Table:\n");

	int negative = -1;
	for(int i = 0; i < N; i++) {
		printf("(%d):", i);
		if(HashTable[i]) {
			printf("%d ", HashTable[i]);
		} else {
			HashTable[i] = negative--;
			// printf("%d ", negative--);
			printf("%d ", HashTable[i]);
		}
	}
	printf("\n\nReconstructed Sequence:\n");

	auto start = std::chrono::high_resolution_clock::now();

	target(N, HashTable);

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "\n\nElapsed time: " << elapsed.count() << " s\n";
	return 0;
}
