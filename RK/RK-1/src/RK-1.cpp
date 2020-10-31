//============================================================================
// Name        : RK-1.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "substitution-func.h"

int main() {

	if (std::experimental::filesystem::exists("./.config") != true) { // @suppress("Invalid arguments")

		std::cout
				<< "You're running the program for the first time, creating a persistent values file..."
				<< std::endl << std::endl;

		switch (subfunc::createAndFillConfig()) {

		case 0:
			break;

		case 1:
			break;

		case 2:
			std::remove(".config");

		}

	}

	bool toExit = false;

	while (toExit != true) {

		switch (subfunc::mainMenu()) {

		case 1:
			subfunc::printRaw(subfunc::parseConfig("ciphertextfile"));
			break;
		case 2:
			subfunc::printDecrypted(subfunc::parseConfig("ciphertextfile"),
					subfunc::parseConfig("decryptionkey"));
			break;
		case 3:
			subfunc::saveDecrypted(subfunc::parseConfig("decryptedtextfile"),
					subfunc::decryptAndStore(
							subfunc::parseConfig("ciphertextfile"),
							subfunc::parseConfig("decryptionkey")));
			break;
		case 4:
			subfunc::printValues();
			break;
		case 5:
			subfunc::editDecryptionKey();
			break;
		case 6:
			subfunc::changeCiphertextFileName();
			break;
		case 7:
			subfunc::changeDecryptedTextFileName();
			break;
		case 8:
			toExit = true;
			break;
		default:
			std::cout << "Unacceptable selection value!" << std::endl
					<< std::endl;

		}

	}

	return 0;
}
