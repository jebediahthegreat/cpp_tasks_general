//============================================================================
// Name        : 2020.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

// I am deeply sorry for my combined usage of camelCase and PascalCase, at least I tried making the logical separation between uses of each

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <random>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

//just for the sake of task 3 part 3, will put the function to the separate library to not make a dump out of the source code
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

// Because doing range-based output every time takes a lot of space and is ugly
template<class T, size_t N>
void OutPutArray(std::array<T, N> &Array, std::string Message) {
	std::cout << Message << ": ";
	for (auto i : Array) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
template<class T>
void OutPutVector(std::vector<T> &Vector, std::string Message) {
	std::cout << Message << ": ";
	for (auto i : Vector) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main() {

	std::random_device rd;

	// 1

	std::array<int, 10> arr1;

	arr1.fill(21);
	OutPutArray(arr1, "The array arr1 currently looks like");

	for (int &i : arr1) {
		i = rd() % 21 - 10;
	}
	OutPutArray(arr1, "The array arr1 currently looks like");

	std::cout << std::endl;
	// 2

	std::vector<double> arr2;

	for (auto i : arr1) {
		arr2.push_back(i);
	}
	OutPutVector(arr2,
			"Copying values from the array to the vector, resulting vector");

	std::cout << "The sum of all the elements of the vector is equal to: ";
	int sum = 0;
	for (auto i : arr2) {
		sum += i;
	}
	std::cout << sum << std::endl;

	for (int i = 3; i < 7; i++) {
		arr2.erase(arr2.begin() + 3);
	}
	OutPutVector(arr2,
			"After removing elements from index 3 to index 6, the vector looks like");

	for (int i = 0; i < 4; i++) {
		arr2.insert(arr2.end() - 2, -0.7);
	}
	OutPutVector(arr2,
			"After inserting 4 elements of value -0.7 next to the second element from the end, the vector looks like");

	/*
	 // I wish that would be an option, but this, unfortunately is not how the erase function works
	 for (auto& i : arr2) {
	 if (i <= -2) {
	 arr2.erase(i);
	 }
	 }
	 */
	for (long unsigned int i = 0; i < arr2.size(); i++) {
		if (arr2[i] <= -2) {
			arr2.erase(arr2.begin() + i);
		}
	}
	OutPutVector(arr2,
			"After removing the first element that is not larger than -2, the vector looks like");

	arr2.insert(arr2.end(), 21);
	OutPutVector(arr2,
			"After inserting the variant number to the end, the vector looks like");

	for (auto &i : arr2) {
		i /= (arr2.front() - arr2.back());
	}
	OutPutVector(arr2,
			"After dividing every element of the vector by the difference between the first and the last element of it, the vector looks like");
	std::cout << "The number of elements in the array is " << arr2.size()
			<< std::endl << std::endl;

	// 3

	std::string str;
	std::cout << "Enter the desired string: ";
	std::getline(std::cin, str);

	std::cout << "The string is: " << str << std::endl;
	double Chars = 0;
	for (auto i : str) {
		if ((i != 'a' && i != 'e' && i != 'i' && i != 'o' && i != 'u')
				&& (i >= 'a' && i <= 'z')) {
			Chars++;
		}
	}
	std::cout << "The length of the string is " << str.length()
			<< ", the share of consonants is " << Chars / str.length()
			<< std::endl;

	int l1, l2;

	SafeIntInput(l1, 0, str.length(),
			"Enter the desired value of l1 (the position of the first symbol of the substring)");
	SafeIntInput(l2, l1, str.length(),
			"Enter the desired value of l2 (the position of the last symbol of the substring)");

	// I like to think this solution is quite elegant, as it does not utilize neither loops nor the cmath library to calculate the absolute value of (l1-l2)
	std::cout << "The resulting substring is: "
			<< str.substr(l1,
					1 + ((l1 - l2) * (((l1 - l2) > 0) - ((l1 - l2) < 0))))
			<< std::endl << std::endl;

	std::string canString = "Can you can a can as a canner can can a can?";
	std::cout << "The initial can string is: " << canString << std::endl;

	std::cout << "Enter the desired string to replace word " << '"' << "can"
			<< '"' << " with: ";
	std::string userCan;
	std::cin.ignore(1);
	std::getline(std::cin, userCan);

	for (size_t pos = canString.find("can"); pos != std::string::npos; pos =
			canString.find("can", pos)) {
		if (canString[pos - 1] == ' '
				&& (canString[pos + 3] == ' ' || canString[pos + 3] == '?'
						|| canString[pos + 3] == '.'
						|| canString[pos + 3] == '!')) {
			canString.replace(pos, 3, userCan);
		} else if (pos + 2 == canString.length()) {
			canString.replace(pos, 3, userCan);
		} else {
			pos = canString.find(" ", pos);
		}
	}

	std::cout << "Resulting string is: " << canString;

	//NOTE TODO: There is a strange bug present that causes the output of substring to be null if the l1 and l2 are both equal to the position of the last character,
	// however, it doesn't happen when l1 and l2 are equal but aren't equal to the position of the last char

}
