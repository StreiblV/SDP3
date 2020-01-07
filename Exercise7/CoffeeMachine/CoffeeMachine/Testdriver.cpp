#include <iostream>

#include "CoffeePreparation.h"


#include <memory>

using namespace std;

int main() {
	CoffeePreparation prep;

	Coffeemachine::SPtr c1{ make_shared<Espresso>() };
	Coffeemachine::SPtr c2{ make_shared<Mocca>() };

	prep.Prepare(make_shared<SojaMilk>(make_shared<Sugar>(c1)));
	prep.Prepare(make_shared<Sugar>(make_shared<Cream>(make_shared<SojaMilk>(c2))));

	prep.Display(cout);
	prep.Finished();
	prep.Finished();

}