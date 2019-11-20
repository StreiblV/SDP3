/* ______________________________________________________________________
| Workfile : TestDriver.h
| Description : Tests all functions and interfaces
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 13.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include <iostream>
#include <windows.h>  //used for error-handling: colors

#include "Client_Epos.h"
#include "Client_NortelNetworks.h"

#include "AEpos.h"
#include "ANortelNetworks.h"

AEpos epos;
ANortelNetworks aNN;
Client_Epos c_epos(epos);
Client_NortelNetworks c_nortelNetworks(aNN);

//calls the epos and NN test and also print the subtitle
void CreateFullTest(std::string subtitle, std::string filename);

//tests all function of the epos interface
void test_EPOS(std::string filename);

//tests all functions of the nortel networks interface
void test_NN(TEncoding type, std::string filename);

//print the subtitle of the test
void PrintSubheader(std::string subtitle);