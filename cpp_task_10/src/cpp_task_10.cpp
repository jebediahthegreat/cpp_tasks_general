//============================================================================
// Name        : cpp_task_10.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;
using namespace std;

int main() {

	cout
			<< "\n1) Print current path;\n"
					"2) Print contents of a catalogue;\n"
					"3) Create a catalogue;\n"
					"4) Print file size;\n"
					"5) Copy file;\n"
					"6) Delete file;\n"
					"7) Delete a catalogue recursively (with files);\n"
					"8) Move between catalogues up/down;\n"
					"9) Rename files and catalogues;\n"
					"10) Move files/catalogues.\n";

	int num;

	cin >> num;
	if (num == 1) {
		auto &out = std::cout;
		fs::path workdir = fs::current_path();
		out << workdir;
	}
	if (num == 2) {
		for (fs::directory_iterator end, dir("./"); dir != end; dir++) { // @suppress("Invalid arguments")
			std::cout << *dir << std::endl;
		}
	}
	if (num == 3) {
		string name = "dir";
		if (!fs::is_directory(name)) { // @suppress("Invalid arguments")
			fs::create_directory(name); // @suppress("Invalid arguments")
			std::cout << "Folder " << name << " created";
		} else {
			std::cout << "Folder " << name << " already exists";
		}
	}
	if (num == 4) {
		string fileName = "fileTestSize.txt";
		fs::path p = fs::current_path() / fileName;
		auto n = fs::file_size(p);
		std::cout << "File size " << fileName << " " << n << "\n";
	}
	if (num == 5) {
		fs::path source = fs::current_path() / "sourceCopy.txt";
		fs::path target = fs::current_path() / "targetCopy.txt";
		std::experimental::filesystem::copy_file(source, target);
	}
	if (num == 6) {
		string fileName = "fileToDel.txt";
		fs::path source = fs::current_path() / fileName;
		if (fs::remove(source)) {
			std::cout << "File has been deleted";
		} else {
			std::cout << "Error while deleting";
		}
	}
	if (num == 7) {
		string fileName = "dirToDel";
		fs::path source = fs::current_path() / fileName;
		auto n = fs::remove_all(source);
		if (n > 0) {
			std::cout << n << " files deleted";
		} else {
			std::cout << "Error while deleting ";
		}
	}
	if (num == 8) {
		string tmp = "Current working directory: ";
		fs::path source = fs::current_path();
		std::cout << tmp << source << "\n";
		fs::path parent = source.parent_path();
		std::cout << tmp << parent << "\n";
		std::cout << tmp << source << "\n";
	}
	if (num == 9) {
		string fileName = "fileToRenamе1.txt";
		fs::path source = fs::current_path() / fileName;
		fs::rename(source / fileName, source / "fileToRenamе1.txt");
		cout << fileName << "->fileToRenamе2.txt";
	}
	if (num == 10) {
		string fileName = "fileToMove.txt", fileName1 = "fileToMoveIn.txt";
		fs::path source = fs::current_path() / fileName;
		fs::path target = fs::current_path() / fileName1;
		std::experimental::filesystem::copy_file(source, target);
		if (fs::remove(source)) {
			std::cout << "File renamed";
		} else {
			std::cout << "Error while moving";
		}
	}
}
