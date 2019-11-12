/* ______________________________________________________________________
| Workfile : Encryptor.cpp
| Description : [ SOURCE] Base Class for encryptors
| Name : Daniel Weyrer									PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Encryptor.h"

//Generate file with given FileName and store the given content in it
void Encryptor::GenFile(std::string const& FileName, std::string const& content) {
		//Create File
		std::ofstream outFile{ FileName, std::ios::out };

		//Check created file; throw exception in case of a fault
		if (!outFile.good() || outFile.fail()) {
			outFile.close();
			throw std::exception("Error creating new File");
		}
		//write content into created file and close it afterwards
		outFile << content;
		outFile.close();
}
//Check Ending of File and add new ending if valid
std::string Encryptor::NewFileEnding(std::string const& oldFileName, std::string const& oldFileEnding, std::string const& newFileEnding) {

	//check for correct file_ending
	std::string::const_iterator it = std::search(oldFileName.cbegin(), oldFileName.cend(), oldFileEnding.cbegin(), oldFileEnding.cend());

	if (it == oldFileName.cend()) {
		throw std::exception("wrong file-ending! Check filename.");
	}

	//create new Filename with new FileEnding
	std::string newFileName;

	newFileName.assign(oldFileName.cbegin(), (--it));
	newFileName += newFileEnding;

	return newFileName;
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
