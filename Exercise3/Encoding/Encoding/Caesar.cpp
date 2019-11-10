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

//!! privateMemberfunction cant be used in transform (pointer to member not possible!)
//Encryption: ASCII-128-Bit 
void Caesar::Encrypt(std::string const& fileName) {
	auto EncryptSingleChar = [this](char const c) { char encrypted = ((c + key) % maxNumberASCII); return encrypted; };
	std::string sEncrypt = ReadFile(fileName);
	std::string encrypted;
	std::transform(sEncrypt.begin(), sEncrypt.end(), std::back_inserter(encrypted), EncryptSingleChar);
	GenFile(fileName, sEncrypt);
}

void Caesar::Decrypt(std::string const& fileName) {
	try {
		//check for correct file_ending
		std::string::const_iterator it = std::search(fileName.cbegin(), fileName.cend(), fileEnding.cbegin(), fileEnding.cend());
		if (it == fileName.end()) {
			throw std::exception("wrong file-ending! Check filename.");
		}

		//create new Filename without ending
		std::string newFileName;

		auto DecryptSingleChar = [this](char const c) { char encrypted = (((c - key) + maxNumberASCII) % maxNumberASCII);
															return encrypted; };


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

//char Caesar::EncryptSingleChar(char const c) {
//	char encrChar;
//	return encrChar	= ((c + key) % maxNumberASCII);
//}
//
//char Caesar::DecryptSingleChar(char const c) {
//	char decrChar;
//	return decrChar = ((c - key) + maxNumberASCII) % maxNumberASCII;
//}
