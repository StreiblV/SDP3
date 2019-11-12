/* ______________________________________________________________________
| Workfile : Caesar.cpp
| Description : [ SOURCE ] Derived Class to encrypt via Caeser-procedure
| Name : Daniel Weyrer								PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Caesar.h"

static const unsigned int maxNumberASCII = 127;
static const std::string fileEndingCaesar = ".Caesar";
static const std::string fileEndingUnencrypted = ".txt";
static const std::string decryptedFileAppendix = "_decrypted";


//Reads content of given File, encrypts and saves it into a new File with a new FileEnding
void Caesar::Encrypt(std::string const& fileName) {
	try {

		std::string newFileName = Encryptor::NewFileEnding(fileName, fileEndingUnencrypted, fileEndingCaesar);

		//Read content of File
		std::string unencrypted = ReadFile(fileName);

		//Lambda Function to Encrypt a single Char
		auto EncryptSingleChar = [this, fileName](char const c) {
			if (c > maxNumberASCII) {
				std::cerr << "Character " << c << " in  file " << fileName << " is not a standard-ASCII value!" << std::endl;
				return c;
			}
			char encryptedChar = ((c + key) % maxNumberASCII);
			return encryptedChar;
		};

		std::string encrypted;

		//Iterate through unencrypted string, encrypt every single char and save it into "encrypted"
		std::transform(unencrypted.cbegin(), unencrypted.cend(), std::back_inserter(encrypted), EncryptSingleChar);

		//Generate File with encrypted content
		GenFile(newFileName, encrypted);
	}
	catch (std::exception const& ex) {
		std::cerr << "Error while encrypting " << '"' << fileName << '"' << " :" << ex.what() << std::endl;
	}
}

//Decrypts the content of the given file and saves it into a new file
void Caesar::Decrypt(std::string const& fileName) {
	try {
		std::string newFileName = Encryptor::NewFileEnding(fileName, fileEndingCaesar, fileEndingUnencrypted, decryptedFileAppendix);

		//read file to String
		std::string encrypted = ReadFile(fileName);


		//Lambdafunction for decrypting a single char
		auto DecryptSingleChar = [this, fileName](char const c) {
			if (c > maxNumberASCII) {
				std::cerr << "Character " << c << " in  file " << fileName << " is not a standard-ASCII value!" << std::endl;
				return c;
			}
			char decryptedChar = (((c - key) + maxNumberASCII) % maxNumberASCII);
			return decryptedChar;
		};

		std::string decrypted;

		//Iterate through encrypted string, decrypt every single char and save it into "decrypted"
		std::transform(encrypted.cbegin(), encrypted.cend(), std::back_inserter(decrypted), DecryptSingleChar);

		Encryptor::GenFile(newFileName, decrypted);
	}

	catch (std::exception const& ex) {
		std::cerr << "Error while decrypting " << '"' << fileName << '"' << " :" << ex.what() << std::endl;
	}
}
