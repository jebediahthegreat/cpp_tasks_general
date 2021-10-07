//============================================================================
// Name        : 2020.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

// Frankenstein code is the best code, especially when it is taken from your own work from a year ago
// TODO refactoring and cleanup

#include <iostream>
#include <vector>
#include <string>
#include <random>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

void SafeIntInput(int &Number, int ValueMin, int ValueMax,
		std::string Message) {

	if (ValueMin != INT_MIN && ValueMax != INT_MAX) {

		std::cout << Message << " (min is " << ValueMin << ", max is "
				<< ValueMax << "): ";
		std::cin >> Number;

		if (Number > ValueMax || Number < ValueMin) {
			bool IsValueValid = false;
			while (!IsValueValid) {
				std::cout << "Please enter a valid value: ";
				std::cin >> Number;
				if (Number <= ValueMax && Number >= ValueMin) {
					IsValueValid = true;
				}
			}
		}
		std::cout << std::endl;
	} else if (ValueMin == INT_MIN && ValueMax != INT_MAX) {
		std::cout << Message << " (max is " << ValueMax << "): ";
		std::cin >> Number;

		if (Number > ValueMax) {
			bool IsValueValid = false;
			while (!IsValueValid) {
				std::cout << "Please enter a valid value: ";
				std::cin >> Number;
				if (Number <= ValueMax) {
					IsValueValid = true;
				}
			}
		}

	} else if (ValueMax == INT_MAX && ValueMin != INT_MIN) {
		std::cout << Message << " (min is " << ValueMin << "): ";
		std::cin >> Number;

		if (Number < ValueMin) {
			bool IsValueValid = false;
			while (!IsValueValid) {
				std::cout << "Please enter a valid value: ";
				std::cin >> Number;
				if (Number >= ValueMin) {
					IsValueValid = true;
				}
			}
		}

	} else {
		std::cout << Message << ": ";
		std::cin >> Number;

	}

}

int main() {

	std::random_device rd;

	// first

	int arr1[10];

	std::cout << "Initial array is: ";
	for (int i = 0; i < 10; i++) {
		arr1[i] = rd() % 21 - 10;
		std::cout << arr1[i] << " ";
	}

	std::cout << std::endl << "Squares of 1st, 2nd, 7th elements is equal to: ";
	std::cout << arr1[1] * arr1[1] + arr1[2] * arr1[2] + arr1[7] * arr1[7];
	std::cout << std::endl << std::endl;

	// second
	int n;
	SafeIntInput(n, 11, INT_MAX, "Enter the desired length of the array");

	int *arr2 = new int[n]();
	for (int i = 0; i < n; i++) {
		std::cout << "Enter a value for arr[" << i << "]: ";
		std::cin >> arr2[i];
	}

	std::cout << "Resulting array is: ";
	for (int i = 0; i < n; i++) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Resulting array is: ";
	for (int i = 0; i < n; i++) {
		if (arr2[i] % 2 == 0)
			arr2[i] /= 3;
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	int k1, k2;

	SafeIntInput(k1, 1, n, "Enter the desired value of k1");

	SafeIntInput(k2, k1, n, "Enter the desired value of k2");

	long double Average = 0;
	unsigned int count = 0;

	for (int i = k1; i <= k2; i++) {
		Average += static_cast<long double>(arr2[i]);
		count++;
		if (i == k2) {
			Average /= static_cast<long double>(count);
			std::cout << "Average of elements from " << k1 << " to " << k2
					<< " is: " << Average << std::endl << std::endl;
		}
	}

	// third
	// showpos is here for formatting reasons for the output to be more readable and nice looking

	int n1, m;

	SafeIntInput(n1, 5, 10, "Enter the desired number of rows for the matrix");
	SafeIntInput(m, 5, 10,
			"Enter the desired number of columns for the matrix");

	// Allocating an aray of pointers pointed by a pointer

	int **A = new int*[n1]();
	int **B = new int*[n1]();
	int **C = new int*[n1]();

	for (int i = 0; i < n1; i++) {
		A[i] = new int[m]();
		B[i] = new int[m]();
		C[i] = new int[m]();
	}

	std::cout << "First matrix is:" << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n1; j++) {
			A[j][i] = rd() % 11 - 5;
			std::cout << std::showpos << A[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Second matrix is:" << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n1; j++) {
			B[j][i] = rd() % 11 - 5;
			std::cout << B[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Matrix sum is:" << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n1; j++) {
			C[j][i] = A[j][i] + B[j][i];
			std::cout << C[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::noshowpos;

	for (int i = 0; i < n1; i++) {
		delete[] A[i];
		delete[] B[i];
		delete[] C[i];
	}
	delete[] A;
	delete[] B;
	delete[] C;

	// fourth

	char* str1 = new char[256]();
	char* str2 = new char[256]();

	std::cout << "Enter a desired string(1): ";
	std::cin.ignore(1);
	std::cin.getline(str1, 256);

	std::cout << "Enter a desired string(2): ";
	std::cin.ignore(1);
	std::cin.getline(str2, 256);

	std::cout << std::endl;

	std::cout << "First string is: " << str1 << std::endl;
	std::cout << "Second string is: " << str2 << std::endl;

	int Str1Size = 0;
	while(str1[Str1Size] != '\0') {
		Str1Size++;
	}
	int Str2Size = 0;
	while(str2[Str2Size] != '\0') {
		Str2Size++;
	}

	char* str3 = new char[Str1Size + Str2Size + 1];

	for(int count = 0; count < Str1Size + Str2Size + 1; count++) {
		if (count < Str1Size) {
			str3[count] = str1[count];
		} else {
			str3[count] = str2[count - Str1Size];
		}
	}

	std::cout << "Resulting character array is: " << str3;

	delete[] str1;
	delete[] str2;
	delete[] str3;

	return 0;
}
