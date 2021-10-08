//============================================================================
// Name        : 2020.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

enum ArgCodes {
	VecSumOption, CocktailSortOption, IncreasingFlag, DecreasingFlag, InvalidArg
};

ArgCodes EvaluateArgs(std::string Arg) {
	if (Arg == "vecsum")
		return VecSumOption;
	if (Arg == "cocktailsort")
		return CocktailSortOption;
	if (Arg == "--increasing")
		return IncreasingFlag;
	if (Arg == "--decreasing")
		return DecreasingFlag;
	return InvalidArg;
}

//too good of a function to just not use, it makes life so much easier
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

std::vector<int> operator +(const std::vector<int> &Vector1,
		const std::vector<int> &Vector2) {
	std::vector<int> result;
	size_t lenMax = 0;
	if (Vector1.size() > Vector2.size()) {
		lenMax = Vector1.size();
	} else {
		lenMax = Vector2.size();
	}
	result.resize(lenMax, 0);
	for (long unsigned int i = 0; i < lenMax; i++) {
		if (i < Vector1.size()) {
			result[i] += Vector1[i];
		}
		if (i < Vector2.size()) {
			result[i] += Vector2[i];
		}
	}
	return result;
}

void CocktailSort(std::vector<int> &Vector, bool Direction) {

	bool swapped = true;
	int end = Vector.size()-1;
	int start = 0;

	if (Direction == false) {
		while (swapped) {
			swapped = false;

			for (int i = 0; i < end; ++i) {
				if (Vector[i] > Vector[i + 1]) {
					int temp = Vector[i];
					Vector[i] = Vector[i + 1];
					Vector[i + 1] = temp;
					swapped = true;
				}
			}

			if (!swapped)
				break;

			swapped = false;

			--end;

			for (int i = end - 1; i >= start; --i) {
				if (Vector[i] > Vector[i + 1]) {
					int temp = Vector[i];
					Vector[i] = Vector[i + 1];
					Vector[i + 1] = temp;
					swapped = true;
				}
			}

			++start;
		}
	} else {

		while (swapped) {
			swapped = false;

			for (int i = 0; i < end; ++i) {
				if (Vector[i] < Vector[i + 1]) {
					int temp = Vector[i];
					Vector[i] = Vector[i + 1];
					Vector[i + 1] = temp;
					swapped = true;
				}
			}

			if (!swapped)
				break;

			swapped = false;

			--end;

			for (int i = end - 1; i >= start; --i) {
				if (Vector[i] < Vector[i + 1]) {
					int temp = Vector[i];
					Vector[i] = Vector[i + 1];
					Vector[i + 1] = temp;
					swapped = true;
				}
			}

			++start;
		}
	}

}

int main(int argc, char *argv[]) {
std::vector<std::string> args;
for (int i = 1; i < argc; i++) {
	args.push_back(argv[i]);
}
if (args[0] == "vecsum") {
	for (long unsigned int i = 1; i < args.size(); i++) {
		switch (EvaluateArgs(args[i])) {
		default:
			std::cout << "Unknown argument " << '"' << args[i] << '"'
					<< ", exiting..." << std::endl;
			return 1;
		}
	}
	int vectorSize1 = 0;
	int vectorSize2 = 0;
	std::vector<int> vector1;
	std::vector<int> vector2;
	SafeIntInput(vectorSize1, 1, INT_MAX,
			"Type the desired size for the first vector");
	SafeIntInput(vectorSize2, 1, INT_MAX,
			"Type the desired size for the second vector");
	for (int i = 0; i < vectorSize1; i++) {
		int tempVar;
		std::cout << "Enter the desired value for vector1[" << i << "]: ";
		std::cin >> tempVar;
		vector1.push_back(tempVar);
		std::cout << std::endl;
	}
	for (int i = 0; i < vectorSize2; i++) {
		int tempVar;
		std::cout << "Enter the desired value for vector2[" << i << "]: ";
		std::cin >> tempVar;
		vector2.push_back(tempVar);
		std::cout << std::endl;
	}
	std::cout << "Vector1's values look like: ";
	for (auto i : vector1) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "Vector2's values look like: ";
	for (auto i : vector2) {
		std::cout << i << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "Calculating vector sum..." << std::endl
			<< std::endl;
	std::vector<int> vectorSum;
	vectorSum = vector1 + vector2;
	std::cout << "The resulting vector is: ";
	for (auto i : vectorSum) {
		std::cout << i << " ";
	}
	return 0;
} else if (args[0] == "cocktailsort") {
	bool decreasing = false;
	bool directionChanged = false;
	for (long unsigned int i = 1; i < args.size(); i++) {
		switch (EvaluateArgs(args[i])) {
		case DecreasingFlag:
			if (directionChanged == false) {
				decreasing = true;
				directionChanged = true;
			} else {
				std::cout
						<< "Direction defined by more than one flag, exiting..."
						<< std::endl;
				return 2;
			}
			break;
		case IncreasingFlag:
			if (directionChanged == false) {
				decreasing = false;
				directionChanged = true;
			} else {
				std::cout
						<< "Direction defined by more than one flag, exiting..."
						<< std::endl;
				return 2;
			}
			break;
		default:
			std::cout << "Unknown argument " << '"' << args[i] << '"'
					<< ", exiting..." << std::endl;
			return 1;
		}
	}
	if (directionChanged == false && decreasing == false) {
		std::cout
				<< "No direction flag detected, using the default sorting direction (increasing)..."
				<< std::endl << std::endl;
	}
	int vectorSize = 0;
	std::vector<int> vector;
	SafeIntInput(vectorSize, 1, INT_MAX, "Type the desired vector size");
	for (int i = 0; i < vectorSize; i++) {
		int tempVar;
		std::cout << "Enter the desired value for vector[" << i << "]: ";
		std::cin >> tempVar;
		vector.push_back(tempVar);
		std::cout << std::endl;
	}
	std::cout << std::endl << "The unsorted vector looks like: ";
	for (auto i : vector) {
		std::cout << i << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "Sorting the vector..." << std::endl << std::endl;
	CocktailSort(vector, decreasing);
	std::cout << "The resulting vector is: ";
	for (auto i : vector) {
		std::cout << i << " ";
	}
	return 0;
} else {
	std::cout << "Unknown option " << '"' << args[0] << '"' << ", exiting..."
			<< std::endl;
	return 1;
}
}
