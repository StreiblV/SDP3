/* ______________________________________________________________________
| Workfile : Type.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef TYPE_H
#define TYPE_H

#include "IVisitor.h"
#include "Object.h"

#include <string>
#include <memory>
#include <list>

enum class eType {
	FILE,
	FOLDER,
	REFERRAL
};

class Type : public Object {
public:
	typedef std::shared_ptr<Type> pType;
	typedef std::list<std::shared_ptr<Type>>::const_iterator cIterItems;
	typedef std::list<std::shared_ptr<Type>>::iterator IterItems;

	//cTor
	Type() : m_prev{ nullptr } {}

	//Accept for Visitor
	virtual void Accept(IVisitor& v) = 0;

	//Getter and Setter
	std::string GetName() const;
	virtual cIterItems GetcBegin() const = 0;
	virtual IterItems GetBegin() = 0;
	virtual cIterItems GetcEnd() const = 0;

	void SetPrev(Type* const& to);
	Type* GetPrev() const;

	//Adds Item if it isn`t contained yet
	virtual void AddItem(std::shared_ptr<Type> const& item) = 0;

	//returns type 
	virtual eType GetType() const = 0;

protected:
	std::shared_ptr<IVisitor> m_pVisitor;
	Type* m_prev;
	std::string m_name;
};
#endif//!TYPE_H
