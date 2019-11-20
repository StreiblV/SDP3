/* ______________________________________________________________________
| Workfile : TestDriver.cpp
| Description : Tests all functions and interfaces
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 13.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Testdriver.h"

int main()
{
	///////////////////////////////////////////////
	//   Test alphabet and numbers
	///////////////////////////////////////////////
	CreateFullTest("Test alphabet and numbers", "alphabet");

	///////////////////////////////////////////////
	//   Test special characters
	///////////////////////////////////////////////
	CreateFullTest("Test special characters", "specialCharacters");

	///////////////////////////////////////////////
	//   Testing an email file
	///////////////////////////////////////////////
	CreateFullTest("Testing an email file", "email");

	///////////////////////////////////////////////
	//   Test if no file is there
	///////////////////////////////////////////////
	CreateFullTest("Test if no file is there", "youCannotFindMe");

	///////////////////////////////////////////////
	//   Test if file is empty
	///////////////////////////////////////////////
	CreateFullTest("Test if the file is empty", "emptyFile");

	return 0;
}

void test_EPOS(std::string filename) {
	//call encryt and decrypt of a specific file
	c_epos.EncryptRSA(filename + ".txt");
	c_epos.DecryptRSA(filename + ".RSA");
}

void test_NN(TEncoding type, std::string filename) {
	//checks if it is ceasar of RSA and pass the correct file
	if (type == TEncoding::eCaesar) {
		c_nortelNetworks.Encipher(TEncoding::eCaesar, filename + ".txt");
		c_nortelNetworks.Decipher(TEncoding::eCaesar, filename + ".Caesar");
	}
	else {
		c_nortelNetworks.Encipher(TEncoding::eRSA, filename + ".txt");
		c_nortelNetworks.Decipher(TEncoding::eRSA, filename + ".RSA");
	}
}

void PrintSubheader(std::string subtitle) {
	//print fancy subtitle
	std::cout << "###################################" << std::endl;
	std::cout << "####  " << subtitle << std::endl;
	std::cout << "###################################" << std::endl;
}

void CreateFullTest(std::string subtitle, std::string filename) {

	//is used to output all errors in red
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//Tests the epos interface
	PrintSubheader(subtitle);
	std::cout << "Test epos... ";
	SetConsoleTextAttribute(hConsole, 4);	//error-handling: set color red
	test_EPOS("../testFiles/"+ filename);
	SetConsoleTextAttribute(hConsole, 15);	//error-handling: set color white
	std::cout << "...completed!" << std::endl;

	//Tests the Caesar functions of the NN interface
	std::cout << "Test Nortel Networks Caesar... ";
	SetConsoleTextAttribute(hConsole, 4);	//error-handling: set color red
	test_NN(TEncoding::eCaesar, "../testFiles/"+ filename + "-c");
	SetConsoleTextAttribute(hConsole, 15);	//error-handling: set color white
	std::cout << " completed!" << std::endl;

	//Tests the RSA functions of the NN interface
	std::cout << "Test Nortel Networks RSA... ";
	SetConsoleTextAttribute(hConsole, 4);	//error-handling: set color red
	test_NN(TEncoding::eRSA, "../testFiles/" + filename + "-r");
	SetConsoleTextAttribute(hConsole, 15);	//error-handling: set color white
	std::cout << " completed!" << std::endl;
	std::cout << std::endl;
}