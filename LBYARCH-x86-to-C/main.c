#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

float sdotC(float* A, float* B, int n) {
	float result = 0;

	for (int i = 0; i < n; i++) {
		result += A[i] * B[i];
	}

	return result;
}

extern float sdotASM(int* A, int* B, int n);

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
		printf("Enter Vector A (separated by space): ");

		for (int i = 0; i < n; i++) {
			scanf_s("%f", &A[i]);
		}

		printf("Enter Vector B (separated by space): ");

		for (int i = 0; i < n; i++) {
			scanf_s("%f", &B[i]);
		}

		printf("RESULT: %f", sdotASM(A, B, n));
	}


	free(A);
	free(B);

	return 0;
}