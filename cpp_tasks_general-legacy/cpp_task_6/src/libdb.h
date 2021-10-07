/*
 * libdb.h
 *
 *
 *      Author: user
 */

#ifndef LIBDB_H_
#define LIBDB_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cmath>

#include "structfile.h"
#include "namelist.h"

namespace libdb {

std::ostream& operator<<(std::ostream &out,
		const std::vector<structDB::citizen> &dataBase) {
	for (auto &citizen : dataBase) {
		if (citizen.fullName == dataBase[dataBase.size() - 1].fullName
				&& citizen.address.street
						== dataBase[dataBase.size() - 1].address.street
				&& citizen.address.houseNumber
						== dataBase[dataBase.size() - 1].address.houseNumber
				&& citizen.address.flatNumber
						== dataBase[dataBase.size() - 1].address.flatNumber
				&& citizen.age == dataBase[dataBase.size() - 1].age
				&& citizen.gender == dataBase[dataBase.size() - 1].gender) {

			out << citizen.fullName << ';' << citizen.address.street << ';'
					<< citizen.address.houseNumber << ';'
					<< citizen.address.flatNumber << ';' << citizen.gender
					<< ';' << citizen.age;
		} else {

			out << citizen.fullName << ';' << citizen.address.street << ';'
					<< citizen.address.houseNumber << ';'
					<< citizen.address.flatNumber << ';' << citizen.gender
					<< ';' << citizen.age << '\n';

		}
	}
	return out;
}

std::vector<structDB::citizen>& operator>>(std::istream &in,
		std::vector<structDB::citizen> &dataBase) {

	dataBase.clear();

	while (!in.eof()) {

		structDB::citizen citizen;

		char tempChar;

		in.get(tempChar);
		while (tempChar != ';') {
			citizen.fullName += tempChar;

			in.get(tempChar);
		}

		in.get(tempChar);
		while (tempChar != ';') {
			citizen.address.street += tempChar;
			in.get(tempChar);
		}

		std::string numberTemp;

		in.get(tempChar);
		while (tempChar != ';') {
			numberTemp += tempChar;
			in.get(tempChar);
		}

		citizen.address.houseNumber = std::stoi(numberTemp);
		numberTemp = "";

		in.get(tempChar);
		while (tempChar != ';') {
			numberTemp += tempChar;
			in.get(tempChar);
		}

		citizen.address.flatNumber = std::stoi(numberTemp);
		numberTemp = "";

		in.get(tempChar);
		while (tempChar != ';') {
			citizen.gender += tempChar;
			in.get(tempChar);
		}

		numberTemp = "";

		in.get(tempChar);
		while (tempChar != '\n' && !in.eof()) {

			numberTemp += tempChar;
			in.get(tempChar);
		}

		citizen.age = std::stoi(numberTemp);

		dataBase.push_back(citizen);

	}

	return dataBase;
}

void safeInput(auto &variableToWriteTo, std::string messageToDisplayDuringInput,
		std::string messageToDisplayIfErrorOccurs = "Unacceptable input value!",
		int minAcceptableValue = -2147483648, int maxAcceptableValue =
				2147483647) {

	if (minAcceptableValue == -2147483648 && maxAcceptableValue == 2147483647) {

		std::cout << messageToDisplayDuringInput << ": ";
		std::cin >> variableToWriteTo;
		std::cout << std::endl;

	} else if (minAcceptableValue != -2147483648
			&& maxAcceptableValue == 2147483647) {

		std::cout << messageToDisplayDuringInput << ": ";
		std::cin >> variableToWriteTo;
		std::cout << std::endl;
		if (variableToWriteTo < minAcceptableValue) {
			bool isValidInput = false;
			while (isValidInput != true) {
				std::cout << messageToDisplayIfErrorOccurs << std::endl
						<< std::endl << messageToDisplayDuringInput << ": ";
				std::cin >> variableToWriteTo;
				std::cout << std::endl;
				if (variableToWriteTo >= minAcceptableValue) {
					isValidInput = true;
				}
			}
		}
	} else if (minAcceptableValue == -2147483648
			&& maxAcceptableValue != 2147483647) {

		std::cout << messageToDisplayDuringInput << ": ";
		std::cin >> variableToWriteTo;
		std::cout << std::endl;
		if (variableToWriteTo > maxAcceptableValue) {
			bool isValidInput = false;
			while (isValidInput != true) {
				std::cout << messageToDisplayIfErrorOccurs << std::endl
						<< std::endl << messageToDisplayDuringInput << ": ";
				std::cin >> variableToWriteTo;
				std::cout << std::endl;
				if (variableToWriteTo <= maxAcceptableValue) {
					isValidInput = true;
				}
			}
		}
	} else if (minAcceptableValue != -2147483648
			&& maxAcceptableValue != 2147483647) {

		std::cout << messageToDisplayDuringInput << ": ";
		std::cin >> variableToWriteTo;
		std::cout << std::endl;
		if (variableToWriteTo < minAcceptableValue
				|| variableToWriteTo > maxAcceptableValue) {
			bool isValidInput = false;
			while (isValidInput != true) {
				std::cout << messageToDisplayIfErrorOccurs << std::endl
						<< std::endl << messageToDisplayDuringInput << ": ";
				std::cin >> variableToWriteTo;
				std::cout << std::endl;
				if (variableToWriteTo >= minAcceptableValue
						&& variableToWriteTo <= maxAcceptableValue) {
					isValidInput = true;
				}
			}
		}
	}

}

void outputDataBase(std::vector<structDB::citizen> dataBase) {
	std::cout << "=========BEGIN DATABASE OUTPUT=========" << std::endl;
	for (auto &citizen : dataBase) {
		if (citizen.fullName == dataBase[dataBase.size() - 1].fullName
				&& citizen.address.street
						== dataBase[dataBase.size() - 1].address.street
				&& citizen.address.houseNumber
						== dataBase[dataBase.size() - 1].address.houseNumber
				&& citizen.address.flatNumber
						== dataBase[dataBase.size() - 1].address.flatNumber
				&& citizen.age == dataBase[dataBase.size() - 1].age
				&& citizen.gender == dataBase[dataBase.size() - 1].gender) {

			std::cout << citizen.fullName << std::endl << citizen.address.street
					<< ", " << citizen.address.houseNumber << ", "
					<< citizen.address.flatNumber << std::endl << citizen.gender
					<< std::endl << citizen.age << std::endl;

		} else {
			std::cout << citizen.fullName << std::endl << citizen.address.street
					<< ", " << citizen.address.houseNumber << ", "
					<< citizen.address.flatNumber << std::endl << citizen.gender
					<< std::endl << citizen.age << std::endl << std::endl;
		}
	}
	std::cout << "=========END  DATABASE  OUTPUT=========" << std::endl << std::endl;
}

void writeToDataBase(std::vector<structDB::citizen> &dataBase,
		std::string fullName, std::string street, unsigned int houseNumber,
		unsigned int flatNumber, std::string gender, unsigned int age) {

	structDB::citizen currentCitizen;
	currentCitizen.fullName = fullName;
	currentCitizen.address.street = street;
	currentCitizen.address.houseNumber = houseNumber;
	currentCitizen.address.flatNumber = flatNumber;
	currentCitizen.gender = gender;
	currentCitizen.age = age;

	dataBase.push_back(currentCitizen);

}

void sortDataBase(std::vector<structDB::citizen> &dataBase) {

	std::sort(dataBase.begin(), dataBase.end(),
			[](structDB::citizen first, structDB::citizen second) {
				return first.fullName < second.fullName;
			});

}

void locateAndPrint(std::vector<structDB::citizen> &dataBase) {
	std::cout << "Select social group to locate and print:" << std::endl
			<< "1. Pensioners" << std::endl << std::endl;

	unsigned short int selection;

	safeInput(selection, "Selection", "Unacceptable selection value!", 1, 1); // @suppress("Invalid arguments")

	std::string output = "";

	switch (selection) {

	case 1:
		unsigned int amount = 0;
		std::cout << "=========BEGIN SEARCH QUERRY OUTPUT========="
				<< std::endl;
		for (auto &citizen : dataBase) {
			if ((citizen.age > 65 && citizen.gender == "Male")
					|| (citizen.age > 60 && citizen.gender == "Female")) {
				output = output + citizen.fullName + '\n'
						+ citizen.address.street + ", "
						+ std::to_string(citizen.address.houseNumber) + ", "
						+ std::to_string(citizen.address.flatNumber) + '\n'
						+ citizen.gender + '\n' + std::to_string(citizen.age)
						+ '\n' + '\n';
				amount++;
			}
		}
		output.pop_back();
		std::cout << output << "=========END  SEARCH QUERRY  OUTPUT========="
				<< std::endl << "Amount of found objects: " << amount
				<< std::endl << std::endl;
		break;

	}

}

void readDBFromFile_TextMode(std::vector<structDB::citizen> &dataBase,
		std::string fileName) {

	std::fstream fileToReadFrom;

	fileToReadFrom.open(fileName, std::ios::in);

	fileToReadFrom >> dataBase;

	fileToReadFrom.close();

}

void writeDBToFile_TextMode(std::vector<structDB::citizen> dataBase,
		std::string fileName) {

	std::fstream fileToWriteTo;

	fileToWriteTo.open(fileName, std::ios::out);

	fileToWriteTo << dataBase;

	fileToWriteTo.close();

}

// This really is crazy

void readDBFromFile_BinaryMode(std::vector<structDB::citizen> &dataBase,
        std::string fileName) {

	dataBase.clear();

    std::ifstream fileToReadFrom;

    fileToReadFrom.open(fileName, std::ios::binary);

    while (!fileToReadFrom.eof()) {
        size_t sizeToRead; // note the size_t

        fileToReadFrom.read(reinterpret_cast<char*>(&sizeToRead),
                sizeof(sizeToRead));


        char* buffer =  new char[sizeToRead];

        fileToReadFrom.read(reinterpret_cast<char*>(buffer), sizeToRead);

        std::string currentLine{buffer};

        delete[] buffer;

        unsigned int currChar = 0;

    	while (currentLine[currChar] != '\0') {

    		structDB::citizen citizen;

    		while (currentLine[currChar] != ';') {
    			citizen.fullName += currentLine[currChar];
    			currChar++;

    		}

    		currChar++;
    		while (currentLine[currChar] != ';') {
    			citizen.address.street += currentLine[currChar];
    			currChar++;
    		}

    		std::string numberTemp;

    		currChar++;
    		while (currentLine[currChar] != ';') {
    			numberTemp += currentLine[currChar];
    			currChar++;
    		}

    		citizen.address.houseNumber = std::stoi(numberTemp);
    		numberTemp = "";

    		currChar++;
    		while (currentLine[currChar] != ';') {
    			numberTemp += currentLine[currChar];
    			currChar++;
    		}

    		citizen.address.flatNumber = std::stoi(numberTemp);
    		numberTemp = "";

    		currChar++;
    		while (currentLine[currChar] != ';') {
    			citizen.gender += currentLine[currChar];
    			currChar++;
    		}

    		numberTemp = "";

    		currChar++;
    		while (currentLine[currChar] != '\0') {

    			numberTemp += currentLine[currChar];
    			currChar++;
    		}

    		citizen.age = std::stoi(numberTemp);

    		dataBase.push_back(citizen);

    	}

        fileToReadFrom.peek();
    }

    fileToReadFrom.close();
}

void writeDBToFile_BinaryMode(std::vector<structDB::citizen> dataBase,
        std::string fileName) {

    std::fstream fileToWriteTo;

    fileToWriteTo.open(fileName, std::ios::binary | std::ios::out);

   for (auto &citizen : dataBase) {
        std::string currentCitizenEntry = citizen.fullName + ';'
                + citizen.address.street + ';'
                + std::to_string(citizen.address.houseNumber) + ';'
                + std::to_string(citizen.address.flatNumber) + ';'
                + citizen.gender + ';' + std::to_string(citizen.age);

        size_t sizeOfLine = currentCitizenEntry.size()+1;
        char lineTermination = '\0';

        fileToWriteTo.write(reinterpret_cast<char*>(&sizeOfLine),
               sizeof(sizeOfLine));

        for (auto &citizen : currentCitizenEntry) {
        	fileToWriteTo.write(reinterpret_cast<char*>(&citizen),
        	        		sizeof(char));
        }
        fileToWriteTo.write(reinterpret_cast<char*>(&lineTermination),
                	        		sizeof(char));
    }
}

namespace randomizeDB {

std::string randomMaleName() {
	std::string fullName;

	fullName = names::maleFirstNames[std::rand() % 100] + ' '
			+ names::middleNames[std::rand() % 200] + ' '
			+ names::lastNames[std::rand() % 200];

	return fullName;
}

std::string randomFemaleName() {
	std::string fullName;

	fullName = names::femaleFirstNames[std::rand() % 100] + ' '
			+ names::middleNames[std::rand() % 200] + ' '
			+ names::lastNames[std::rand() % 200];

	return fullName;
}

void addRandomEntriesToDataBase(std::vector<structDB::citizen> &dataBase,
		unsigned int amountToGenerate, double maleToFemaleRatio) {

	for (unsigned int i = 0; i < amountToGenerate; i++) {

		if ((std::rand() % 101) < maleToFemaleRatio * 100) {

			writeToDataBase(dataBase, randomMaleName(),
					names::streetNames[std::rand() % 30],
					static_cast<unsigned int>(std::rand() % 51 + 1),
					static_cast<unsigned int>(std::rand() % 201 + 1), "Male",
					static_cast<unsigned int>(std::rand() % 90));

		} else {

			writeToDataBase(dataBase, randomFemaleName(),
					names::streetNames[std::rand() % 30],
					static_cast<unsigned int>(std::rand() % 51 + 1),
					static_cast<unsigned int>(std::rand() % 201 + 1), "Female",
					static_cast<unsigned int>(std::rand() % 90));

		}
	}

}
}

}

#endif /* LIBDB_H_ */
