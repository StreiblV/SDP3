/* ______________________________________________________________________
| Workfile : RPM_Sensor.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "RPM_Sensor.h"


RPM_Sensor::RPM_Sensor(std::string const& fileName) {
	ReadFile(fileName);
}

unsigned int RPM_Sensor::GetRevolutions() {
	if (currPos != mRevTable.cend()) {
		return (*currPos++);
	}
	else {
		std::cerr<< "End of testdata reached!" <<std::endl;
		return 0;
	}
}

void RPM_Sensor::ReadFile(std::string const& fileName) {
	unsigned int tmp;
	//Create Filestream
	try {
		std::ifstream inFile{ fileName, std::ios::binary };

		//Check file; throw exception in case of a fault
		if (!inFile.good() || inFile.fail()) {
			inFile.close();
			throw std::exception("Error opening file!");
		}

		while (inFile >> tmp) {
			mRevTable.push_back(tmp);
		}
		inFile.close();
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception while reading File: "<< ex.what() <<std::endl;
	}
	catch (std::bad_alloc const& ex) {
		std::cerr << "Memory allocation error: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unhandled exception!" << std::endl;
	}
}
