//============================================================================
// Name        : 2020.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

int main() {

	// first

	std::srand(std::time(0));

	 int arr1[10];

	 std::cout << "Initial array is: ";
	 for(int i = 0; i < 10; i++) {
	 arr1[i] = std::rand() % 21 - 10;
	 std::cout << arr1[i] << " ";
	 }

	 int MultipleArr = arr1[0];

	 std::cout << std::endl << "Resulting array is: ";
	 for(int i = 0; i < 10; i++) {
	 arr1[i] *= MultipleArr;
	 std::cout << arr1[i] << " ";
	 }

	 // second
	 int n;
	 std::cout << std::endl << std::endl << "Enter the length of an array n (n > 10): ";
	 while(std::cin >> n) {
	 if (n <= 10) {
	 std::cout << "Enter a value that is more than 10" << std::endl;
	 std::cout << "Enter the length of an array n (n > 10): ";
	 } else {
	 break;
	 }
	 }

	 int arr2[n]; // n is a non-constant variable, hence memory allocation is dynamic. El Psy Congroo

	 for(int i = 0; i < n; i++) {
	 std::cout << "Enter a value for arr[" << i << "]: ";
	 std::cin >> arr2[i];
	 }

	 std::cout << "Resulting array is: ";
	 for(int i = 0; i < n; i++) {
	 std::cout << arr2[i] << " ";
	 }
	 std::cout << std::endl;

	 std::cout << "Resulting array is: ";
	 for(int i = 0; i < n; i++) {
	 if (arr2[i] == 0) {
	 arr2[i] -= 9;
	 }
	 std::cout << arr2[i] << " ";
	 }
	 std::cout << std::endl;

	 int k1, k2;

	 std::cout << "Enter a value of k1 (0 < k1 < " << n << "): ";
	 while(std::cin >> k1) {
	 if (k1 < 0 || k1 >= n || k1 < 0) {
	 std::cout << "Enter a value that is more than 0 and less than " << n << ": " << std::endl;
	 std::cout << "Enter a value of k1: ";
	 } else {
	 break;
	 }
	 }

	 std::cout << "Enter a value of k2 ("<< k1 << " <= k2 < " << n << "): ";
	 while(std::cin >> k2) {
	 if (k2 <= k1 || k1 >= n || k2 < 0) {
	 std::cout << "Enter a value that is more or equal to " << k1 << " and less than " << n << ": " << std::endl;
	 std::cout << "Enter a value of k2: ";
	 } else {
	 break;
	 }
	 }

	 long double Average = 0;
	 unsigned int count = 0;

	 for(int i = k1; i <= k2; i++) {
	 Average += static_cast<long double>(arr2[i]);
	 count++;
	 if (i == k2) {
	 Average /= static_cast<long double>(count);
	 std::cout << "Average of elements from " << k1 << " to " << k2 << " is: " << Average << std::endl;
	 }
	 }

	 // third

	 std::vector<int> arr3;

	 int m;
	 std::cout << std::endl << std::endl << "Enter the length of an array m (m > 5): ";
	 while(std::cin >> m) {
	 if (m <= 5) {
	 std::cout << "Enter a value that is more than 5" << std::endl;
	 std::cout << "Enter the length of an array m (m > 5): ";
	 } else {
	 break;
	 }
	 }

	 for(int i = 0; i < m; i++) {
	 std::cout << "Enter a value for arr[" << i << "]: ";
	 int input;
	 std::cin >> input;
	 arr3.push_back(input);
	 }

	 std::cout << "Resulting array is: ";
	 for (int i : arr3) {
	 std::cout << i << " ";
	 }
	 std::cout << std::endl;

	 arr3.push_back(19);
	 std::cout << "Resulting array is: ";
	 for (int i : arr3) {
	 std::cout << i << " ";
	 }
	 std::cout << std::endl;

	 long int Sum = 0;

	 std::cout << "Sum of all elements in the array is: ";
	 for (int i : arr3) {
	 Sum += i;
	 }
	 std::cout << Sum << std::endl;

	 for (int i : arr3) {
	 if (i == 3) {
	 arr3.erase(arr3.begin() + i);
	 break;
	 }
	 }

	 std::cout << "Resulting array is: ";
	 for (int i : arr3) {
	 std::cout << i << " ";
	 }
	 std::cout << std::endl;


	// fourth
	std::string String = "";

	std::cout << "Enter a string: ";

	getline(std::cin, String);

	std::cout << String << std::endl;

	std::cout << "String length is: " << String.length() << std::endl;

	/*for (unsigned int i = 0; i < 10; i++) {

		StringTemp.erase(
				std::remove(StringTemp.begin(), StringTemp.end(),
						static_cast<char>(48 + i)), StringTemp.end());
	}
	*/
	int NumbersInString = 0;
	for (unsigned int i = 0; i < String.length(); i++) {
		if (String[i] >= '0' && String[i] <= '9') {
			NumbersInString++;
		}
	}

	// std::cout << "Numbers among all the characters: " << static_cast<int>(String.length() - StringTemp.length()) << std::endl;

	std::cout << "Among " << String.length() << " characters, "
			<< NumbersInString
			<< " are digits., the ratio is" << static_cast<double>(String.length())/NumbersInString << std::endl;

	char l1, l2;

	std::cout << "Enter a character value for l1: ";
	std::cin >> l1;

	std::cout << "Enter a character value for l2: ";
	std::cin >> l2;

	std::string StringSubTemp = String;

	StringSubTemp.erase(0, StringSubTemp.find(l1));
	StringSubTemp.erase(StringSubTemp.find(l2) + 1, StringSubTemp.length());

	//std::cout << StringSubTemp << std::endl;

	//std::string Sub = StringSubTemp.substr(String.find(l1), String.find(l2));

	std::cout << "Substring is: " << StringSubTemp << std::endl;

	std::string Can = "Can you can a can as a canner can can a can?";

	std::string UserCan = "";

	std::cout << "Enter a user string: ";
	std::cin >> UserCan;

	size_t pos = 0;
	while (true) {
		pos = Can.find("can", pos);

		if (pos == std::string::npos) {
			break;
		} else if (Can.substr(pos, 6) == "canner") {
			pos += 6;
			continue;
		}
		Can.replace(pos, 3, UserCan);

		pos += 3;
	}

	std::cout << Can;

	// TODO

	return 0;
}
