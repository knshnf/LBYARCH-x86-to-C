/*
LBYARCH S11
FETALVERO, KENSHIN GAMBOA
GUTIERREZ, CARLOS KRISTOFFER PABALAN
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

float sdotC(float* A, float* B, int n) {
	float result = 0;

	for (int i = 0; i < n; i++) {
		result += A[i] * B[i];
	}

	return result;
}

extern float sdotASM(int* A, int* B, int n);

void avgTime(int vectorSize, int iterations, float* A, float* B);
float rand_float(float min, float max);

int main() {
	int n;
	int idx = 0;
	float* A;
	float* B;

	printf("Enter Size of Vector: ");
	scanf_s("%d", &n);

	A = (float*)malloc(n * sizeof(float));
	B = (float*)malloc(n * sizeof(float));

	if (A == NULL && B == NULL) {
		printf("Unsuccessful Memory Allocation. \n");
	}
	else {
		avgTime(n, 30, A, B);

		/* Uncomment this if you want to intiialize the vectors.
		printf("Enter Vector A (separated by space): ");

		for (int i = 0; i < n; i++) {
			scanf_s("%f", &A[i]);
		}

		printf("Enter Vector B (separated by space): ");

		for (int i = 0; i < n; i++) {
			scanf_s("%f", &B[i]);
		}

		printf("\nResult - C: %f\n", sdotC(A, B, n));
		printf("Result - ASM: %f\n", sdotASM(A, B, n));
		*/
	}


	free(A);
	free(B);

	return 0;
}

void avgTime(int vectorSize, int iterations, float* A, float* B) {
	clock_t avgTimeC = 0;
	clock_t avgTimeASM = 0;

	// Initialize vector
	for (int j = 0; j < vectorSize; j++) {
		float random_float = rand_float(1, 5);
		A[j] = random_float;
		B[j] = random_float;
	}

	for (int i = 0; i < iterations; i++) {
		clock_t beginC = clock();
		float sdotResultC = sdotC(A, B, vectorSize);
		clock_t endC = clock();
		avgTimeC += (endC - beginC);
		// printf("C: % \nf", (double)(endC - beginC) / CLOCKS_PER_SEC);

		clock_t beginASM = clock();
		float sdotResultASM = sdotASM(A, B, vectorSize);
		clock_t endASM = clock();
		avgTimeASM += (endASM - beginASM);
		// printf("ASM: %f\n\n", (double)(endASM - beginASM) / CLOCKS_PER_SEC);

		if (sdotResultC != sdotResultASM) {
			printf("ERROR: C and x86-64 returned different values.\n\n");
			return;
		}
	}

	double avgTimeCSeconds = (double)avgTimeC / iterations / CLOCKS_PER_SEC;
	double avgTimeASMSeconds = (double)avgTimeASM / iterations / CLOCKS_PER_SEC;
	printf("Average Execution Time - C: %f seconds\n", avgTimeCSeconds);
	printf("Average Execution Time - x86-64: %f seconds\n\n", avgTimeASMSeconds);
}

float rand_float(float min, float max) {
	float scale = rand() / (float)RAND_MAX;
	return min + scale * (max - min);
}
