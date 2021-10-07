/*
 * libsort.h
 *
 *  Created on: Nov 2, 2020
 *      Author: user
 */

#ifndef LIBSORT_H_
#define LIBSORT_H_

#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

namespace libsort {

namespace oddEven {

void oddEvenSort(std::vector<int> &vect1) {
	bool isSorted = false; // Initially array is unsorted

	while (!isSorted) {
		isSorted = true;

		for (unsigned int i = 1;
				i <= static_cast<unsigned int>(vect1.size()) - 2; i += 2) {
			if (vect1[i] > vect1[i + 1]) {
				int temp = vect1[i];
				vect1[i] = vect1[i + 1];
				vect1[i + 1] = temp;
				isSorted = false;
			}
		}

		// Perform Bubble sort on even indexed element
		for (unsigned int i = 0;
				i <= static_cast<unsigned int>(vect1.size()) - 2; i += 2) {
			if (vect1[i] > vect1[i + 1]) {
				int temp = vect1[i];
				vect1[i] = vect1[i + 1];
				vect1[i + 1] = temp;
				isSorted = false;
			}
		}
	}
	std::cout << "Odd-even sorted vector is: ";
	for (unsigned int i = 0; i < static_cast<unsigned int>(vect1.size()); i++) {
		std::cout << vect1[i] << " ";
	}
	std::cout << std::endl << std::endl;
	return;
}

}

namespace merge {

void sort(std::vector<int> &left, std::vector<int> &right,
		std::vector<int> &vector) {
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR) {
		if (left[j] < right[k]) {
			vector[i] = left[j];
			j++;
		} else {
			vector[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		vector[i] = left[j];
		j++;
		i++;
	}
	while (k < nR) {
		vector[i] = right[k];
		k++;
		i++;
	}
}

void mergeSort(std::vector<int> &vector) {
	if (vector.size() <= 1)
		return;

	int mid = vector.size() / 2;
	std::vector<int> left;
	std::vector<int> right;

	for (size_t j = 0; static_cast<int>(j) < mid; j++)
		left.push_back(vector[j]);
	for (size_t j = 0; j < (vector.size()) - mid; j++)
		right.push_back(vector[mid + j]);

	mergeSort(left);
	mergeSort(right);
	sort(left, right, vector);
}

}

namespace bitonic {

void compAndSwap(std::vector<int> &vector, int i, int j, bool dir) {
	if (dir == (vector[i] > vector[j]))
		std::iter_swap(vector.begin() + i, vector.begin() + j);
}

void bitonicMerge(std::vector<int> &vector, int begin, int size, bool dir) {
	if (size > 1) {
		int k = size / 2;
		for (int i = begin; i < begin + k; i++)
			compAndSwap(vector, i, i + k, dir);
		bitonicMerge(vector, begin, k, dir);
		bitonicMerge(vector, begin + k, k, dir);
	}
}

void bitonicSortSort(std::vector<int> &vector, int begin, int size, bool dir) {
	if (size > 1) {
		int k = size / 2;

		bitonicSortSort(vector, begin, k, 1);

		bitonicSortSort(vector, begin + k, k, 0);

		bitonicMerge(vector, begin, size, dir);
	}
}

void bitonicSort(std::vector<int> &vector, int begin, int size, bool dir) {

	int back;
	bool even = true;

	if (vector.size() % 2 != 0) {
		back = vector.back();
		even = false;
		vector.pop_back();
	}

	bitonicSortSort(vector, begin, vector.size(), dir);

	if (even == false) {

		for (long unsigned int i = 0; i < vector.size(); i++) {
			if ((vector[i] > back && vector[i + 1] < back)
					|| (vector[i] < back && vector[i + 1] > back)) {
				vector.insert(vector.begin() + i, back);
				break;
			}
		}

	}

}

}

}

#endif /* LIBSORT_H_ */
