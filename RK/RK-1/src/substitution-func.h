/*
 * substitution-func.h
 *
 *
 *      Author: John Doe
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <experimental/filesystem>

#ifndef SUBSTITUTION_FUNC_H_
#define SUBSTITUTION_FUNC_H_

namespace subfunc {

// TODO: Make creation of decip file automatic if it does not exist
// TODO: Force user to input name of new cip file on start if previously specified one does not exist

int createAndFillConfig() {

	std::fstream configFile;

	configFile.open(".config", std::ios::out);

	if (!configFile) {

		std::cout << "Error creating config file" << std::endl << std::endl;

		return 1;

	} else {

		std::string ciphertextFileName;
		std::string decryptedTextFileName;

		std::cout << "Type in the name of the ciphertext file: ";
		std::cin >> ciphertextFileName;
		std::cout << std::endl;

		if (std::experimental::filesystem::exists(ciphertextFileName) // @suppress("Invalid arguments")
		== false) {

			bool fileExists = false;

			while (fileExists != true) {

				std::cout << "File doesn't exist or the file name is wrong..."
						<< std::endl << std::endl;

				std::cout << "Type in the name of the ciphertext file: ";
				std::cin >> ciphertextFileName;
				std::cout << std::endl;

				if (std::experimental::filesystem::exists(ciphertextFileName) // @suppress("Invalid arguments")
				!= false) {

					fileExists = true;

				}
			}
		}

		std::cout << "Type in the desired name of the decrypted text file: ";
		std::cin >> decryptedTextFileName;
		std::cout << std::endl;

		std::fstream decryptedTextFile;

		decryptedTextFile.open(decryptedTextFileName, std::ios::out);

		if (!decryptedTextFile) {

			std::cout << "Error creating decrypted text file" << std::endl
					<< std::endl;

			return 2;

		} else {

			decryptedTextFile.close();

			configFile << "decryptionkey=ABCDEFGHIJKLMNOPQRSTUVWXYZ" << ';'
					<< "\n" << "ciphertextfile=" << ciphertextFileName << ';'
					<< "\n" << "decryptedtextfile=" << decryptedTextFileName
					<< ';';

			configFile.close();

			return 0;

		}

		return 0;

	}
}

int mainMenu() {

	std::cout
			<< "Welcome to the Substitution Cipher Decoding Toolkit V1.28! Select the operation you'd like to perform:"
			<< std::endl << "1. Print the raw ciphertext" << std::endl
			<< "2. Print text decrypted with the current key" << std::endl
			<< "3. Save text decrypted with the current key to file"
			<< std::endl << "4. View the environmental variable values"
			<< std::endl << "5. Change the decryption key" << std::endl
			<< "6. Change the ciphertext file name" << std::endl
			<< "7. Change the decrypted text file name" << std::endl
			<< "8. Exit" << std::endl << std::endl;

	unsigned short int selection;

	std::cout << "Selection: ";
	std::cin >> selection;
	std::cout << std::endl;

	return selection;

}

std::string parseConfig(std::string value) {

	// Future Invention double-o-nine, """elegant""" config file parser
	// It's really, really bad, but at least it does the job
	// And about 60% of time spend on this code went on implementing the config parsing

	// TODO: Un-monkeycode config parsing function

	unsigned int txtSize = std::experimental::filesystem::file_size(".config"); // @suppress("Invalid arguments")

	std::ifstream configFile(".config");

	char confData[txtSize];

	if (configFile.is_open()) {
		unsigned int i = 0;
		while (!configFile.eof()) {
			configFile.get(confData[i]);
			i++;
		}
	}

	unsigned short int delimiterPos;

	if (value == "decryptionkey") {
		delimiterPos = 1;
	} else if (value == "ciphertextfile") {
		delimiterPos = 2;
	} else {
		delimiterPos = 3;
	}

	unsigned int allocateSize = 0;
	unsigned int delimiterCount = 0;
	for (unsigned int i = 0; i < txtSize; i++) {
		if (confData[i] == '=') {
			delimiterCount++;
			if (delimiterCount == delimiterPos) {
				while (confData[i + 1] != ';') {
					allocateSize++;
					i++;
				}
				break;
			}
		}
	}
	char confValueArray[allocateSize];
	delimiterCount = 0;
	for (unsigned int i = 0; i < txtSize; i++) {
		if (confData[i] == '=') {
			delimiterCount++;
			if (delimiterCount == delimiterPos) {
				unsigned int j = 0;
				while (confData[i + 1] != ';') {
					confValueArray[j] = confData[i + 1];
					i++;
					j++;
				}
				break;
			}
		}
	}

	std::string confValue;

	for (unsigned int i = 0; i < allocateSize; i++) {
		confValue += confValueArray[i];
	}

	return confValue;
}

void printRaw(std::string cipherTextFileName) {

	std::ifstream textfile(cipherTextFileName);

	std::cout << "Raw text is: " << std::endl;

	if (textfile.is_open()) {
		while (!textfile.eof()) {
			char tempChar;
			textfile.get(tempChar);
			std::cout << tempChar;
		}
	}
	std::cout << std::endl << std::endl;

}

void printDecrypted(std::string cipherTextFileName, std::string decryptionKey) {

	unsigned int txtSize = std::experimental::filesystem::file_size( // @suppress("Invalid arguments")
			cipherTextFileName);

	std::ifstream textfile(cipherTextFileName);

	char text[txtSize];

	unsigned int i = 0;
	if (textfile.is_open()) {
		while (!textfile.eof()) {
			textfile.get(text[i]);
			i++;
		}
	}

	char decryptionKeyArray[decryptionKey.size() + 1];
	for (unsigned int i = 0; i < decryptionKey.size(); i++) {
		decryptionKeyArray[i] = decryptionKey[i];
	}

	std::cout << "Printing decrypted text: " << std::endl;

	for (unsigned int i = 0; i < txtSize; i++) {
		for (unsigned int j = 0; j < decryptionKey.size(); j++) {
			if (static_cast<unsigned int>(text[i]) - 65 == j) {
				text[i] = decryptionKeyArray[j];
				break;
			}
		}
		std::cout << text[i];
	}
	std::cout << std::endl << std::endl;

}

std::string decryptAndStore(std::string cipherTextFileName,
		std::string decryptionKey) {

	unsigned int txtSize = std::experimental::filesystem::file_size( // @suppress("Invalid arguments")
			cipherTextFileName);

	std::ifstream textfile(cipherTextFileName);

	char text[txtSize];

	unsigned int i = 0;
	if (textfile.is_open()) {
		while (!textfile.eof()) {
			textfile.get(text[i]);
			i++;
		}
	}

	char decryptionKeyArray[decryptionKey.size() + 1];
	for (unsigned int i = 0; i < decryptionKey.size(); i++) {
		decryptionKeyArray[i] = decryptionKey[i];
	}

	for (unsigned int i = 0; i < txtSize; i++) {
		for (unsigned int j = 0; j < decryptionKey.size(); j++) {
			if (static_cast<unsigned int>(text[i]) - 65 == j) {
				text[i] = decryptionKeyArray[j];
				break;
			}
		}
	}

	std::string textString;

	for (unsigned int i = 0; i < txtSize; i++) {
		textString += text[i];
	}

	return textString;

}

void saveDecrypted(std::string decryptedTextFileName, std::string textString) {

	std::remove(decryptedTextFileName.c_str());

	std::fstream decryptedTextFile;

	decryptedTextFile.open(decryptedTextFileName, std::ios::out);

	decryptedTextFile << textString;

	decryptedTextFile.close();

}

void printValues() {
	std::cout << "Decryption Key: " << parseConfig("decryptionkey") << std::endl
			<< "Ciphertext File: " << parseConfig("ciphertextfile") << std::endl
			<< "Decrypted Text File: " << parseConfig("decryptedtextfile")
			<< std::endl << std::endl;
}

// BIG TODO: !!!Optimise the config changes!!!

void editDecryptionKey() {

	std::string decryptionKeyCurrent = parseConfig("decryptionkey");
	std::string ciphertextFileNameCurrent = parseConfig("ciphertextfile");
	std::string decryptedTextFileNameCurrent = parseConfig("decryptedtextfile");

	unsigned int selection;

	std::cout << "Select which letter you'd like to change:" << std::endl;

	for (unsigned int i = 0; i < decryptionKeyCurrent.size(); i++) {
		std::cout << i + 1 << ". " << decryptionKeyCurrent[i] << std::endl;
	}
	std::cout << std::endl << "Selection: ";
	std::cin >> selection;
	std::cout << std::endl;

	if (selection < 1 || selection > decryptionKeyCurrent.size()) {
		bool isValidSelectionValue = false;
		while (isValidSelectionValue != true) {
			std::cout << "Unacceptable selection value!" << std::endl
					<< std::endl << "Selection: ";
			std::cin >> selection;
			std::cout << std::endl;
			if (selection > 0 && selection < decryptionKeyCurrent.size() + 1) {
				isValidSelectionValue = true;
			}
		}
	}

	char letterToChangeTo;

	std::cout << "Pick a letter to change #" << selection << " to: ";
	std::cin >> letterToChangeTo;
	std::cout << std::endl;
	if (static_cast<int>(letterToChangeTo) < 65
			|| static_cast<int>(letterToChangeTo) > 90) {
		bool isValidChangeValue = false;
		while (isValidChangeValue != true) {
			std::cout << "Unacceptable to-change value!" << std::endl
					<< std::endl << "Pick a letter to change #" << selection
					<< " to: ";
			std::cin >> letterToChangeTo;
			std::cout << std::endl;
			if (static_cast<int>(letterToChangeTo) > 64
					&& static_cast<int>(letterToChangeTo) < 91) {
				isValidChangeValue = true;
			}
		}
	}

	decryptionKeyCurrent[selection - 1] = letterToChangeTo;

	std::remove(".config");

	std::fstream configFile;

	configFile.open(".config", std::ios::out);

	configFile << "decryptionkey=" << decryptionKeyCurrent << ';' << "\n"
			<< "ciphertextfile=" << ciphertextFileNameCurrent << ';' << "\n"
			<< "decryptedtextfile=" << decryptedTextFileNameCurrent << ';';

	configFile.close();

}

void changeCiphertextFileName() {

	std::string decryptionKeyCurrent = parseConfig("decryptionkey");
	std::string decryptedTextFileNameCurrent = parseConfig("decryptedtextfile");

	std::string ciphertextFileNameNew;

	std::cout << "What file name to change current ciphertext filename to: ";
	std::cin >> ciphertextFileNameNew;
	std::cout << std::endl;

	if (std::experimental::filesystem::exists(ciphertextFileNameNew) // @suppress("Invalid arguments")
	== false) {

		bool fileExists = false;

		while (fileExists != true) {

			std::cout << "File doesn't exist or the file name is wrong..."
					<< std::endl << std::endl
					<< "Type in the name of the ciphertext file: ";
			std::cin >> ciphertextFileNameNew;
			std::cout << std::endl;

			if (std::experimental::filesystem::exists(ciphertextFileNameNew) // @suppress("Invalid arguments")
			!= false) {

				fileExists = true;

			}
		}
	}

	std::remove(".config");

	std::fstream configFile;

	configFile.open(".config", std::ios::out);

	configFile << "decryptionkey=" << decryptionKeyCurrent << ';' << "\n"
			<< "ciphertextfile=" << ciphertextFileNameNew << ';' << "\n"
			<< "decryptedtextfile=" << decryptedTextFileNameCurrent << ';';

}

void changeDecryptedTextFileName() {

	std::string decryptionKeyCurrent = parseConfig("decryptionkey");
	std::string ciphertextFileNameCurrent = parseConfig("ciphertextfile");
	std::string decryptedTextFileNameCurrent = parseConfig("decryptedtextfile");

	std::string decryptedTextFileNameNew;

	std::cout
			<< "What file name to change current decrypted text filename to: ";
	std::cin >> decryptedTextFileNameNew;
	std::cout << std::endl;

	std::remove(decryptedTextFileNameCurrent.c_str());

	std::cout << "Old decrypted text file deleted, run " << '"'
			<< "Save text decrypted with the current key to file" << '"'
			<< " operation again." << std::endl << std::endl;

	std::fstream decryptedTextFileNew;

	decryptedTextFileNew.open(decryptedTextFileNameNew, std::ios::out);

	std::remove(".config");

	std::fstream configFile;

	configFile.open(".config", std::ios::out);

	configFile << "decryptionkey=" << decryptionKeyCurrent << ';' << "\n"
			<< "ciphertextfile=" << ciphertextFileNameCurrent << ';' << "\n"
			<< "decryptedtextfile=" << decryptedTextFileNameNew << ';';

}

}
#endif /* SUBSTITUTION_FUNC_H_ */
