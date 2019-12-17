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
#include "vld.h"

#include <iostream>

int main() {
	FileSystem FS{ std::make_shared<Folder>("x") };
	FS.Add("/", std::make_shared<Folder>("y"));
	FS.Add("/y/", std::make_shared<Folder>("z"));
	FS.Add("/y/z/", std::make_shared<File>(1, 1, "file"));
	FS.Add("/y/", std::make_shared <File>(1, 1, "file1"));
	//FS.Add("/y/", std::make_shared<Referral>());
	

}