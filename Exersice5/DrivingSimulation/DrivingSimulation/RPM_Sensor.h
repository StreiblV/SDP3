/* ______________________________________________________________________
| Workfile : RPM_Sensor.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef RPM_SENSOR_H
#define RPM_SENSOR_H

#include "Object.h"

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <iostream>

class RPM_Sensor : public Object {
public:

	/**
	 * @brief Constructor, calls ReadFile() to read and store integers in the vector
	 * @param
	 * @return current RPMs
	 */
	RPM_Sensor(std::string const& fileName);

	/**
	 * @brief Getter
	 * @param
	 * @return current RPMs
	 */
	unsigned int GetRevolutions();

private:
	unsigned int mRevolutions;
	std::vector<unsigned int> mRevTable;
	std::vector<unsigned int>::const_iterator currPos;
	
	
	/**
	 * @brief Reads integers of file (line by line) and stores them into mRevTable
	 * @param fileName with fileName
	 * @return -
	 */
	void ReadFile(std::string const& fileName);

};

#endif //RPM_SENSOR_H
