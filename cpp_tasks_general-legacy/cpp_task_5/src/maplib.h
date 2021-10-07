/*
 * maplib.h
 *
 *  Created on: Nov 1, 2020
 *      Author: user
 */

#ifndef MAPLIB_H_
#define MAPLIB_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include "wordlist.h"

namespace libmap {

namespace unorderedmultimap {

void returnThisUnorderedMultimap(
		std::unordered_multimap<int, std::string> thisUnorderedMultimap) {

	auto returnMap = [](std::pair<int, std::string> current) {
		std::cout << current.first << " " << current.second << std::endl;
	};

	std::cout << "Unordered multimap contains: " << std::endl;
	for_each(thisUnorderedMultimap.begin(), thisUnorderedMultimap.end(),
			returnMap);
	std::cout << std::endl;
}

int unorderedMultimapMinKeyIndex(
		std::unordered_multimap<int, std::string> thisUnorderedMultimap) {
	int minKeyIndex = 2147483647;

	auto min = [&minKeyIndex](std::pair<int, std::string> current) {
		if (current.first < minKeyIndex)
			minKeyIndex = current.first;
	};

	for_each(thisUnorderedMultimap.begin(), thisUnorderedMultimap.end(), min);

	return minKeyIndex;
}

int unorderedMultimapMaxKeyIndex(
		std::unordered_multimap<int, std::string> thisUnorderedMultimap) {
	int maxKeyIndex = unorderedMultimapMinKeyIndex(thisUnorderedMultimap);

	auto max = [&maxKeyIndex](std::pair<int, std::string> current) {
		if (current.first > maxKeyIndex)
			maxKeyIndex = current.first;
	};

	for_each(thisUnorderedMultimap.begin(), thisUnorderedMultimap.end(), max);

	return maxKeyIndex;
}

void unorderedMultimapToMap(
		std::unordered_multimap<int, std::string> thisUnorderedMultimap,
		std::map<int, std::string> &thisMap) {

	thisMap.clear();

	std::unordered_multimap<int, std::string>::iterator uMIterator;

	for (auto i = unorderedMultimapMinKeyIndex(thisUnorderedMultimap);
			i <= unorderedMultimapMaxKeyIndex(thisUnorderedMultimap); i++) {
		uMIterator = thisUnorderedMultimap.find(i);
		if (uMIterator != thisUnorderedMultimap.end()) {
			std::pair<int, std::string> current(i, uMIterator->second);
			thisMap.insert(current);
		} else {
			continue;
		}
	}

}

}

namespace map {

void returnThisMap(std::map<int, std::string> thisMap) {

	auto returnMap = [](std::pair<int, std::string> current) {
		std::cout << current.first << " " << current.second << std::endl;
	};

	std::cout << "Map contains: " << std::endl;
	for_each(thisMap.begin(), thisMap.end(), returnMap);
	std::cout << std::endl;
}

}

namespace vector {

void returnThisVector(std::vector<int> thisVector) {

	auto returnVector = [](auto current) {
		std::cout << current << " ";
	};
	std::cout << "Vector contains: " << std::endl;
	for_each(thisVector.begin(), thisVector.end(), returnVector);
	std::cout << std::endl << std::endl;

}

}

namespace set {

void returnThisSet(std::set<int> thisSet) {

	auto returnSet = [](auto current) {
		std::cout << current << " ";
	};

	std::cout << "Set contains: " << std::endl;
	for_each(thisSet.begin(), thisSet.end(), returnSet);
	std::cout << std::endl << std::endl;

}

}

}

#endif /* MAPLIB_H_ */
