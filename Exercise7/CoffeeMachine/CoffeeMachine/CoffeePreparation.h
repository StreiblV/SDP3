/* ______________________________________________________________________
| Workfile : CoffeePreparation.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef COFFEEPREPARATION_H
#define COFFEEPREPARATION_H

#include "Object.h"

#include "Coffeemachine.h"
#include "Espresso.h"
#include "BlackCoffee.h"
#include "Decaffeinated.h"

#include "Milk.h"
#include "Mocca.h"
#include "SojaMilk.h"
#include "Sugar.h"
#include "Cream.h"

#include <memory>
#include <list>
#include <iostream>

class CoffeePreparation : public Object {

public:
	void Prepare(Coffeemachine::SPtr const& coffee);
	void Display(std::ostream& os);

	//Prints prepared coffee with all ingredients and the price!
	void Finished();

private:
	std::list<Coffeemachine::SPtr> m_Ingredients;
};

#endif //!COFFEEPREPARATION_H

