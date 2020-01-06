/* ______________________________________________________________________
| Workfile : Ingredient.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "Coffeemachine.h"

#include <vector>
#include <memory>
#include <string>


class Ingredient : public Coffeemachine {
public:
	virtual std::string GetDescription() = 0;
	virtual double GetCost() = 0;

protected:
	std::shared_ptr<Coffeemachine> m_coffee;

private:
	double m_cost;
};

#endif //!INGREDIENT_H

