#include <iostream>

#include "Client_Epos.h"
#include "Client_NortelNetworks.h"

#include "AEpos.h"
#include "ANortelNetworks.h"

AEpos epos;
ANortelNetworks aNN;

Client_Epos c_epos(epos);
Client_NortelNetworks c_nortelNetworks(aNN);

void testRSA_EPOS(std::string filename);
void test_NN(TEncoding type, std::string filename);