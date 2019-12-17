/* ______________________________________________________________________
| Workfile : Referral.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef REFERRAL_H
#define REFERRAL_H
#include "Type.h"

#include <memory>

class Referral : public Type {
public:
	Referral(std::shared_ptr<Type> const& to, std::string const& name);

	//visitorfunc
	virtual void Accept(IVisitor& v) override;

	//Getters
	virtual cIterItems GetBegin() const override;
	virtual cIterItems GetEnd() const override;
	virtual eType GetType() const override;

	//Adds Item to Folder the referral is pointing to
	virtual void AddItem(std::shared_ptr<Type> const& item) override;


private:
	std::shared_ptr<Type> m_ref;
};

#endif //!REFERRAL_H

