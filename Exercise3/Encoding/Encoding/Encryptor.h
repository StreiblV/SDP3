/* ______________________________________________________________________
| Workfile : ICompany .h
| Description : [ Interface ] Interface between Client and Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <string>
#include "Object.h"

class Encryptor : public Object
{
public:
	virtual void Encrypt(std::string const& fileName) = 0;
	virtual void Decrypt(std::string const& fileName) = 0;

private:
	void GenFile(std::string const& newFileName, std::string const& content);
};

#endif // ENCRYPTOR_H