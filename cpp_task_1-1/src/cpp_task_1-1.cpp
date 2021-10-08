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

	long int x;
	long int a;
	unsigned short int b;

	unsigned int c, d, e, f;

	bool k, l, m, n;

	// ---------------------------------------------------------------------------------------------------------------------------

	std::cout
			<< "Hello! Be so kind as to input the values for the following variables:"
			<< std::endl;

	std::cout << "For expression " << '"' << "5x^6 - 8x^3 + 4" << '"'
			<< ", enter the desired value of x: ";
	std::cin >> x;

	signed long int first = pow(x, 8) + 3 * pow(x, 3) + 5;

	std::cout << "5*" << x << "^6 - 8*" << x << "^3 + 4 = " << std::showpos
			<< first << std::noshowpos << std::endl << std::endl;

	// ---------------------------------------------------------------------------------------------------------------------------

	std::cout << "For expression " << '"' << "4|a-5| + sqrt(7a-6)" << '"'
			<< ", enter the desired value of a (a >= 0, a <= 2^32-1): ";
	std::cin >> a;

	double second = abs(a - 5) * 4 + sqrt(7 * a - 6);

	std::cout << "4*|" << a << "-5| + sqrt(7*" << a << "-6) = " << std::fixed
			<< std::setprecision(3) << second << std::endl << std::endl;

	// ---------------------------------------------------------------------------------------------------------------------------

	std::cout << "For expression " << '"' << "l || n && (m XOR (!k))" << '"'
			<< ", enter the desired value of k: ";
	std::cin >> k;

	std::cout << "Enter the desired value of l: ";
	std::cin >> l;

	std::cout << "Enter the desired value of m: ";
	std::cin >> m;

	std::cout << "Enter the desired value of n: ";
	std::cin >> n;

	bool third = (l || n) && (m ^ !k);

	std::cout << l << " || " << n << " && (" << m << " XOR (!" << k << ")) = "
			<< std::boolalpha << third << std::endl << std::endl;

	// ---------------------------------------------------------------------------------------------------------------------------

	std::cout << "For expression " << '"' << "2^b" << '"'
			<< ", enter the desired value of b (b >= 0, b <= 7): ";
	std::cin >> b;

	unsigned short int fourth = pow(2, b);

	std::cout << "2^" << b << " = " << fourth << std::endl << "2^" << b << " = "
			<< std::oct << fourth << " base 8" << std::endl;

	// ---------------------------------------------------------------------------------------------------------------------------

	std::cout << "For expression " << '"' << "e | (~d & c) ^ f" << '"'
			<< ", enter the desired value of c (c >= 0, c <= 2^16 - 1): ";
	std::cin >> c;

	std::cout << "Enter the desired value of d (d >= 0, d <= 2^16 - 1): ";
	std::cin >> d;

	std::cout << "Enter the desired value of e (e >= 0, e <= 2^16 - 1): ";
	std::cin >> e;

	std::cout << "Enter the desired value of f (f >= 0, f <= 2^16 - 1): ";
	std::cin >> f;

	signed long int fifth = (e | (~d & c)) ^ f;

	std::cout << e << " | (~" << d << " & " << c << ") ^ " << f << " = "
			<< std::hex << std::showbase << std::setfill('0') << std::internal
			<< std::setw(10) << fifth;

	// ---------------------------------------------------------------------------------------------------------------------------

	// TODO: Add unacceptable variable value handling;
	// TODO: Optimise variable value input process (less lines of code);

}
