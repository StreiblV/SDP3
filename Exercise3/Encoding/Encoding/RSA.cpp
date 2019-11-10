/* ______________________________________________________________________
| Workfile : RSA.cpp
| Description : [ SOURCE ] Derived Class to encrypt via RSA-procedure
| Name : Daniel Weyrer								PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "RSA.h"

static const std::size_t maxNumberASCII = 2 ^ 7;
static const std::string fileEnding = ".RSA";

void RSA::Encrypt(std::string const& fileName) {
	try {
		std::string unEncrypted = ReadFile(fileName);
		std::string encrypted;

		auto EncryptSingleChar = [this](char const c) {char encr = ((c ^ e) % n); return encr; };
		std::transform(unEncrypted.cbegin(), unEncrypted.cend(), std::back_inserter(encrypted), EncryptSingleChar);

	}
	catch (std::exception const& ex) {
		std::cerr << "" << ex.what()<< std::endl;
	}
}

void RSA::Decrypt(std::string const& fileName) {
	try {
		//check for correct file_ending
		std::string::const_iterator it = std::search(fileName.cbegin(), fileName.cend(), fileEnding.cbegin(), fileEnding.cend());
		if (it == fileName.end()) {
			throw std::exception("wrong file-ending! Check filename.");
		}

		//create new Filename without ending
		std::string newFileName;

		newFileName.assign(fileName.cbegin(), (--it));
		std::string sDecrypt = ReadFile(fileName);
		std::string decrypted;
		auto DecryptSingleChar = [this](char const c) {char decr = (c ^ d) % n; return decr; };

		std::transform(sDecrypt.begin(), sDecrypt.end(), std::back_inserter(decrypted), DecryptSingleChar);

		Encryptor::GenFile(newFileName, decrypted);
	}
	catch (std::exception const& ex) {
		std::cerr << "" << ex.what() << std::endl;
	}
}

void RSA::GenFile(std::string const& FileName, std::string const& content) {
	std::string newFileName = FileName + ".RSA";
	Encryptor::GenFile(newFileName, content);
}

//void RSA::EncryptSingleChar(char& c) {
//	c = (c ^ e) % n;
//}
//
//void RSA::DecryptSingleChar(char& c) {
//	c = (c ^ d) % n;
//}
