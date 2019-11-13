#include "Testdriver.h"

#include <windows.h>

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

	return 0;
}

void testRSA_EPOS(std::string filename) {
	c_epos.EncryptRSA(filename + ".txt");
	c_epos.DecryptRSA(filename + ".RSA");
}

void test_NN(TEncoding type, std::string filename) {
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
	std::cout << "###################################" << std::endl;
	std::cout << subtitle << std::endl;
	std::cout << "###################################" << std::endl;
}

void CreateFullTest(std::string subtitle, std::string filename) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	PrintSubheader(subtitle);
	std::cout << "Test epos... ";
	SetConsoleTextAttribute(hConsole, 4);
	testRSA_EPOS("../testFiles/"+ filename);
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "...completed!" << std::endl;

	std::cout << "Test Nortel Networks Caesar... ";
	SetConsoleTextAttribute(hConsole, 4);
	test_NN(TEncoding::eCaesar, "../testFiles/"+ filename + "-c");
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " completed!" << std::endl;

	std::cout << "Test Nortel Networks RSA... ";
	SetConsoleTextAttribute(hConsole, 4);
	test_NN(TEncoding::eRSA, "../testFiles/" + filename + "-r");
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " completed!" << std::endl;
	std::cout << std::endl;
}