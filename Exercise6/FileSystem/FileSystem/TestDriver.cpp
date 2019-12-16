/* ______________________________________________________________________
| Workfile : TestDriver.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "FileSystem.h"
#include "Type.h"
#include "File.h"
#include "Folder.h"
#include "Referral.h"

#include <iostream>

int main() {
	Folder x{ "x" };
	Folder y{ "y" };
	Folder z{ "z" };
	FileSystem FS{ std::make_shared<Folder>(x) };
	FS.Add("/", std::make_shared<Folder>(y));
	FS.Add("/y/", std::make_shared<Folder>(z));

}