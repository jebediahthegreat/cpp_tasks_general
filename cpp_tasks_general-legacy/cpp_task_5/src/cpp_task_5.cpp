//============================================================================
// Name        : cpp_task_5.cpp
// Author      : John Doe
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "maplib.h"

int main() {

	std::srand(std::time(0));

	// unordered_multimap

	std::unordered_multimap<int, std::string> unorderedMultimap;

	for (auto i = 0; i < 4; i++) {
		for (auto i = 0; i < 10; i++) {
			std::pair<int, std::string> current(rand() % 10,
					wordlist::randomWord[rand() % 30]);
			unorderedMultimap.insert(current);
		}
	}

	libmap::unorderedmultimap::returnThisUnorderedMultimap(unorderedMultimap);

	unorderedMultimap.erase(1);

	libmap::unorderedmultimap::returnThisUnorderedMultimap(unorderedMultimap);

	unorderedMultimap.erase(2);

	libmap::unorderedmultimap::returnThisUnorderedMultimap(unorderedMultimap);

	for (auto i = 0; i < 3; i++) {
		std::pair<int, std::string> current(3,
				wordlist::randomWord[rand() % 30]);
		unorderedMultimap.insert(current);
	}

	libmap::unorderedmultimap::returnThisUnorderedMultimap(unorderedMultimap);

	std::map<int, std::string> map;

	libmap::unorderedmultimap::unorderedMultimapToMap(unorderedMultimap, map);

	libmap::map::returnThisMap(map);

	// map

	auto countIf = std::count_if(map.begin(), map.end(),
			[](std::pair<int, std::string> current) {
				return (current.first >= -2 && current.first <= 6);
			});

	std::cout << "There are " << countIf << " elements in the map " << '"'
			<< "map" << '"' << " that are in range [-2,6]" << std::endl
			<< std::endl;

	std::vector<int> vec;

	std::transform(map.begin(), map.end(), std::back_inserter(vec),
			[](std::pair<int, std::string> current) {
				return current.first;
			});

	libmap::vector::returnThisVector(vec);

	// vector

	auto result = std::find(vec.begin(), vec.end(), 3);
	if (result != vec.end()) {
		std::cout << "vec contains: " << 3 << std::endl << std::endl;
	} else {
		std::cout << "vec does not contain: " << 3 << std::endl << std::endl;
	}

	replace_if(vec.begin(), vec.end(), [](auto i) {
		return (i < 0);
	}, 0);

	std::sort(vec.begin(), vec.end());

	libmap::vector::returnThisVector(vec);

	std::set<int> set;

	for (auto &current : vec) {
		set.insert(current);
	}

	// set

	libmap::set::returnThisSet(set);

	return 0;
}
