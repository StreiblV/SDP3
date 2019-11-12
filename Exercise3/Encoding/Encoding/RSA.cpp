/* ______________________________________________________________________
| Workfile : RSA.cpp
| Description : [ SOURCE ] Derived Class to encrypt via RSA-procedure
| Name : Daniel Weyrer								PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "RSA.h"

static const std::string fileEndingRSA = ".RSA";
static const std::string fileEndingUnencrypted = ".txt";
static const std::string decryptedFileAppendix = "_decrypted";


//Reads content of given File, encrypts and saves it into a new File with a new FileEnding
void RSA::Encrypt(std::string const& fileName) {
	try {

		std::string newFileName = Encryptor::NewFileEnding(fileName, fileEndingUnencrypted, fileEndingRSA);

		//Read unencrypted file and save it into unencrypted
		std::string unencrypted = ReadFile(fileName);


		auto EncryptSingleChar = [this](char const c) {
			return CalcPowMod(c, e, n); 
		};

		std::string encrypted;

		//iterate through unencrypted string, encrypt every single char and save it into encrypted
		std::transform(unencrypted.cbegin(), unencrypted.cend(), std::back_inserter(encrypted), EncryptSingleChar);

		Encryptor::GenFile(newFileName, encrypted);
	}
	catch (std::exception const& ex) {
		std::cerr << "Error while encrypting " << '"' << fileName << '"' << " :" << ex.what()<< std::endl;
	}
}

//Decrypts the content of the given file and saves it into a new file
void RSA::Decrypt(std::string const& fileName) {
	try {
		std::string newFileName = Encryptor::NewFileEnding(fileName, fileEndingRSA, fileEndingUnencrypted, decryptedFileAppendix);

		//read content of encrypted file into encrypted
		std::string encrypted = ReadFile(fileName);

		//Lambda for decrypting a single char
		auto DecryptSingleChar = [this](char const c) { 
			return CalcPowMod(c, d, n); 
		};

		std::string decrypted;

		//iterate through encrypted string, decrypt it char by char and save it into decrypted
		std::transform(encrypted.begin(), encrypted.end(), std::back_inserter(decrypted), DecryptSingleChar);

		Encryptor::GenFile(newFileName, decrypted);
	}
	catch (std::exception const& ex) {
		std::cerr << "Error while decrypting "<< '"' << fileName << '"' << " :"<< ex.what() << std::endl;
	}
}

//Calculates (c^pow) % mod; Avoids high numbers by doing it step by step
char RSA::CalcPowMod(char const c, unsigned int const pow, unsigned int const mod) {
	
	unsigned int tmp, mult;

	//necessary cast to do the calculation!
	tmp = mult = static_cast<unsigned char>(c);
	
	for (size_t i = 1; i < pow; i++) {
		tmp = (tmp * mult) % mod;
	}
	return static_cast<char>(tmp);
}
