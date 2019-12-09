/* ______________________________________________________________________
| Workfile : RPM_Sensor.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "RPM_Sensor.h"


unsigned int RPM_Sensor::GetRevolutions() {
	std::advance(currPos, 1);
	if (currPos != mRevolutions.cend()) {
		return (*currPos);
	}
	else {
		throw std::exception("Reached end of Testdata!");
	}
}

unsigned int RPM_Sensor::ReadFile(std::string const& fileName) {
	unsigned int tmp;
	//Create Filestream
	std::ifstream inFile{ fileName, std::ios::binary };

	//Check created file; throw exception in case of a fault
	if (!inFile.good() || inFile.fail()) {
		inFile.close();
		throw std::exception("Error creating new File");
	}

	while (inFile >> tmp) {
		mRevTable.push_back(tmp);
	}
	inFile.close();
}
