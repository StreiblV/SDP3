/* ______________________________________________________________________
| Workfile : Caesar.cpp
| Description : [ SOURCE ] Derived Class to encrypt via Caeser-procedure
| Name : Daniel Weyrer								PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Caesar.h"

static const std::size_t maxNumberASCII = 2 ^ 7;
static const std::string fileEnding = ".Caesar";

//Encryption: ASCII-128-Bit 
void Caesar::Encrypt(std::string const& fileName) {
	std::string sEncrypt = ReadFile(fileName);
	std::transform(sEncrypt.begin(), sEncrypt.end(), sEncrypt.begin(), EncryptSingleChar);
	GenFile(fileName, sEncrypt);
}

void Caesar::Decrypt(std::string const& fileName) {
	try {
		//check for correct file_ending
		std::string::const_iterator it = std::search(fileName.cbegin(), fileName.cend(), fileEnding);
		if (it == fileName.end()) {
			throw std::exception("wrong file-ending! Check filename.");
		}

		//create new Filename without ending
		std::string newFileName;

		newFileName.assign(fileName.cbegin(), (--it));
		std::string sDecrypt = ReadFile(fileName);
		std::transform(sDecrypt.begin(), sDecrypt.end(), sDecrypt.begin(), DecryptSingleChar);

		Encryptor::GenFile(newFileName, sDecrypt);
	}

	catch (std::exception const& ex) {
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
}

void Caesar::GenFile(std::string const& FileName, std::string const& content) {
	std::string newFileName = FileName + fileEnding;
	Encryptor::GenFile(newFileName, content);
}

void Caesar::EncryptSingleChar(char c) {
	c = ((c + key) % maxNumberASCII);
}
