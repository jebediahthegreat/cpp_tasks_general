//============================================================================
// Name        : cpp_task_6.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "libdb.h"
#include "structfile.h"

int main() {

	// TODO (probably never): !!!Make a proper user interface (like in RK-1)!!!

	std::srand(std::time(0));

	std::vector<structDB::citizen> dataBase;

	libdb::randomizeDB::addRandomEntriesToDataBase(dataBase, 50, 0.5);

	libdb::outputDataBase(dataBase);

	libdb::sortDataBase(dataBase);

	libdb::outputDataBase(dataBase);

	libdb::locateAndPrint(dataBase);

	libdb::writeDBToFile_TextMode(dataBase, "writetofile.txt");

	libdb::readDBFromFile_TextMode(dataBase, "writetofile.txt");

	libdb::outputDataBase(dataBase);

	libdb::writeDBToFile_BinaryMode(dataBase, "writetofilebinary.txt");

	libdb::readDBFromFile_BinaryMode(dataBase, "writetofilebinary.txt");

	libdb::outputDataBase(dataBase);

	return 0;
}
