//============================================================================
// Name        : 2020.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

	long double x;
	unsigned long int a;
	unsigned short int b;

	unsigned int c, d, e, f;

	bool k, l, m, n;

	std::cout << "Enter value of x: ";
	std::cin >> x;

	std::cout << "Enter value of a: ";
	std::cin >> a;

	std::cout << "Enter value of b: ";
	std::cin >> b;

	std::cout << "Enter value of k: ";
	std::cin >> k;

	std::cout << "Enter value of l: ";
	std::cin >> l;

	std::cout << "Enter value of m: ";
	std::cin >> m;

	std::cout << "Enter value of n: ";
	std::cin >> n;

	std::cout << "Enter value of c: ";
	std::cin >> c;

	std::cout << "Enter value of d: ";
	std::cin >> d;

	std::cout << "Enter value of e: ";
	std::cin >> e;

	std::cout << "Enter value of f: ";
	std::cin >> f;

	// TODO: Add unacceptable variable value handling;
	// TODO: Optimise variable value input process (less lines of code);

	signed long int first = pow(x, 8) + 3*pow(x, 3) + 5;

	double second = abs(a)*7 + sqrt(a+2);

	bool third = n || (!(l ^ k) && m);

	unsigned short int fourth = pow(2, b);

	signed long int fifth = (f | ~e) & (c ^ ~d);

	std::cout << "1. " << std::fixed << std::setprecision(3) << first << std::endl
			<< "2. " << std::showpos << second << std::endl
			<< "3. " << std::boolalpha << third << std::endl
			<< "4.1. " << fourth << std::endl
			<< "4.2. " << std::oct << fourth << std::endl
			<< "5. " << std::hex << std::showbase << std::setfill('0') << std::left << std::setw(10) << fifth;
}
