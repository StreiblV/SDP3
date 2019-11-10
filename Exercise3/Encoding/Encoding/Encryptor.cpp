/* ______________________________________________________________________
| Workfile : Encryptor.cpp
| Description : [ SOURCE] Base Class for encryptors
| Name : Daniel Weyrer									PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Encryptor.h"


void Encryptor::GenFile(std::string const& FileName, std::string const& content) {
		std::ofstream outFile{ FileName, std::ios::out };
		if (!outFile.good() || outFile.fail()) {
			outFile.close();
			throw std::exception("Error creating new File");
		}
		outFile << content;
		outFile.close();
}

std::string Encryptor::ReadFile(std::string const& fileName) {
	std::string tmp;
		std::ifstream inFile{ fileName, std::ios::in };
		if (inFile.eof() && inFile.fail() && !inFile.good()) {
			inFile.close();
			throw std::exception("Error Reading File!");
		}
		//Seek end, to calc the size of inFile
		inFile.seekg(std::ios::end);
		//Reserve the size of inFile in tmp --> more Efficent when copying larger files!
		tmp.reserve(inFile.tellg());
		//Seek beginning to start reading
		inFile.seekg(std::ios::beg);
		//assigning content of inFile to tmp string
		tmp.assign(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>());
		inFile.close();

		return tmp;
}
