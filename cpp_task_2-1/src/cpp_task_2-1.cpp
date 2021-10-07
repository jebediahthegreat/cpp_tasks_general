//============================================================================
// Name        : cpp_task_2-1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

	// 1

	for (int i = 0; i < 128; i++) {

		std::cout << i << " - " << '"' << static_cast<char>(i) << '"'
				<< std::endl;

	}

	// 2

	std::cout << std::endl;

	char a;

	std::cout << "Enter a character: ";
	std::cin >> a;

	if (a >= '0' && a <= '9') {
		std::cout << "Symbol is a number" << std::endl;
	} else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
		std::cout << "Character is a letter" << std::endl;
	} else {
		std::cout << "Character type is unknown" << std::endl;
	}

	std::cout << std::endl;

	// 3

	long int x;

	std::cout << "Enter a non-negative value of x: ";
	std::cin >> x;

	long long int y;

	switch (x % 4) {

	case 0: y = -1;
		std::cout << "y(x) = " << y << std::endl;;
		break;

	case 1: y = 2*x + 1;
		std::cout << "y(x) = " << y << std::endl;
		break;

	case 2: y = -x;
		std::cout << "y(x) = " << y << std::endl;
		break;

	case 3: y = 3*x;
		std::cout << "y(x) = " << y << std::endl;
		break;
	}

	// 4

	double x1;
	std::cout << "Enter a value of x, so that (|x| < 1): ";
		std::cin >> x1;

	for (signed short int acc = 2; acc < 7; acc++) {
		std::cout << "Accuracy is 10^-" << acc << ';';
		long double expression = 1/(pow((1-x1),3));
		double accur = static_cast<double>(pow(10, acc));
		expression = roundf(expression*accur)/accur;

		// std::cout << "Debug: " << "expression is: " << std::fixed << std::setprecision(10) << expression;

		long double ex1 = 1 + 3*x1;

		unsigned long int i = 0;
		long double n = 3;
		while (static_cast<long double>(roundf(ex1*accur)/accur) != expression) {
			ex1 += (((n-1)*n)/2)*pow(x1, n-2);
			n++;
			i++;
			/* std::cout << "Debug: " << "expression is: "
					<< std::fixed << std::setprecision(10) << expression
					<< " ex1 is: " << std::fixed << std::setprecision(10)
			<< (long double)(roundf(ex1*accur)/accur) << std::endl; */
		}
		std::cout << " Amount of iterations is: " << i << std::endl;
	}

}
