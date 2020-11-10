//============================================================================
// Name        : 2020.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "libsort.h"

int main() {

	std::srand(std::time(0));

	// odd-even

	std::vector<int> vec;
	unsigned int size;

	std::cout << "Enter the size of a vector to be initialized: ";
	std::cin >> size;
	std::cout << std::endl;

	std::cout << "Random vector is: ";
	for (unsigned int i = 0; i < size; i++) {
		vec.push_back(std::rand() % 201 - 100);
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	libsort::oddEven::oddEvenSort(vec);

	// merge

	std::cout << "Random vector is: ";
	vec.clear();
	for (unsigned int i = 0; i < size; i++) {
		vec.push_back(std::rand() % 200 - 100);
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	libsort::merge::mergeSort(vec);

	std::cout << "Merge sorted array is: ";
	for (auto &current : vec) {
		std::cout << current << " ";
	}
	std::cout << std::endl << std::endl;

	// bitonic

	std::cout << "Random vector is: ";
	vec.clear();
	for (unsigned int i = 0; i < size; i++) {
		vec.push_back(std::rand() % 200 - 100);
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	bool incr = true;
	libsort::bitonic::bitonicSort(vec, 0, vec.size(), incr);

	std::cout << "Bitonic sorted array is: ";
	for (auto &current : vec) {
		std::cout << current << " ";
	}
	std::cout << std::endl << std::endl;

	return 0;
}
