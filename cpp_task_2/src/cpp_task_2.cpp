//============================================================================
// Name        : 2020.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

unsigned long int fact(unsigned long int Number) {
	unsigned long int res = 1;
	unsigned long int iter = 1;

	if (Number == 0) {
		return 0;
	} else {
		while(iter != Number) {
			iter++;
			res *= iter;
		}

		return res;
	}
}

int main() {

	// 1

	for (int i = 0; i < 128; i++) {

		std::cout << i << " - " << '"' << static_cast<char>(i) << '"' << std::endl;

	}

	// 2

	std::cout << std::endl;

	char a;

	std::cout << "Enter a character: ";
	std::cin >> a;

	if (static_cast<int>(a) > 47 && static_cast<int>(a) < 58) {
		std::cout << "Symbol is a number" << std::endl;
	} else if ( (static_cast<int>(a) > 64 && static_cast<int>(a) < 91) ||
			(static_cast<int>(a) > 96 && static_cast<int>(a) < 123)) {
		std::cout << "Character is a letter" << std::endl;
	} else {
		std::cout << "Character type is unknown" << std::endl;
	}

	// 3

	std::cout << std::endl;

	long int x;

	std::cout << "Enter a non-negative value of x: ";
	std::cin >> x;

	long double y;

	switch (x % 4) {

	case 0: y = static_cast<double>(x)*static_cast<double>(x);
		std::cout << "y(x) = " << y << std::endl;;
		break;

	case 1: y = 1 - static_cast<double>(x)*static_cast<double>(x);
		std::cout << "y(x) = " << y << std::endl;
		break;

	case 2: y = 1/static_cast<double>(x);
		std::cout << "y(x) = " << y << std::endl;
		break;

	case 3: y = x;
		std::cout << "y(x) = " << y << std::endl;
		break;
	}

	// 4

	for (signed short int acc = 2; acc < 7; acc++) {
		std::cout << "Accuracy is 10^-" << acc << ';';
		long double ex = std::exp(x);
		double accur = static_cast<double>(pow(10, acc));
		ex = roundf(ex*accur)/accur;

		// std::cout << "Debug: " << "ex is: " << std::fixed << std::setprecision(10) << ex;

		long double ex1 = 1 + x;

		unsigned long int i = 0;
		long double n = 2;
		while (static_cast<long double>(roundf(ex1*accur)/accur) != ex) {
			ex1 += (pow(static_cast<long double>(x), n)/fact(n));
			n++;
			i++;
			/* std::cout << "Debug: " << "ex is: "
					<< std::fixed << std::setprecision(10) << ex
					<< " ex1 is: " << std::fixed << std::setprecision(10)
			<< (long double)(roundf(ex1*accur)/accur) << std::endl; */
		}
		std::cout << " Amount of iterations is: " << i << std::endl;
	}

	return 0;
}
