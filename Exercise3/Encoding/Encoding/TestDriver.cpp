#include "Testdriver.h"

int main()
{
	testRSA_EPOS("../testFiles/alphabet");
	test_NN(TEncoding::eCaesar, "../testFiles/alphabet-c");
	test_NN(TEncoding::eRSA, "../testFiles/alphabet-r");

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