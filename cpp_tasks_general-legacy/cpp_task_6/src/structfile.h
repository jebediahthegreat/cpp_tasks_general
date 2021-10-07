/*
 * structfile.h
 *
 *
 *      Author: user
 */

#ifndef STRUCTFILE_H_
#define STRUCTFILE_H_

#include <string>

namespace structDB {

struct citizen {
	std::string fullName;
	struct Address {
		std::string street;
		unsigned int houseNumber;
		unsigned int flatNumber;
	};
	Address address;
	std::string gender;
	unsigned int age;

};

}


#endif /* STRUCTFILE_H_ */
