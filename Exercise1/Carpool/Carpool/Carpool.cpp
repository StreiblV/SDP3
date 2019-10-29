/*______________________________________________________________________
|Workfile:		Carpool.cpp
|Description:	Manages main functionality of the Carpool
|Name:			Weyrer Daniel							PKZ: S1820306044
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/
#include "Carpool.h"

using namespace std; 

Carpool::Carpool() {
}

Carpool::~Carpool() {
}

//Deep copy already defined in the assignment operator
Carpool::Carpool(Carpool const& toCopy) {
	*this = toCopy;
}

//Adds car only if it isn`t already contained in the Container; throws and catches an exception
//if the number is already contained
void Carpool::Add(TUptr v) {
	try {
		if (FindVehicle((*v).GetNumberplate()) != this->mVehicles.cend()) {
			throw exception("Add failed: Number already in the Database!");
		}

		//unique pointers can only be moved, not copied!
		mVehicles.emplace_back(move(v));
	}
	catch (exception const& ex) {
		cerr << ex.what() << endl;
	}
	catch (bad_alloc const& ex) {
		cerr << "memory allocation: " << ex.what() << endl;
	}
}

void Carpool::AddCar(std::string const& brand, std::string const& numberplate, Fuel fuel) {
	Car tmp{ brand, numberplate, fuel };
	Add(make_unique<Car>(tmp));
}

void Carpool::AddTruck(std::string const& brand, std::string const& numberplate, Fuel fuel) {
	Truck tmp{ brand, numberplate, fuel };
	Add(make_unique<Truck>(tmp));
}

void Carpool::AddMotorcycle(std::string const& brand, std::string const& numberplate, Fuel fuel) {
	Motorcycle tmp{ brand, numberplate, fuel };
	Add(make_unique<Motorcycle>(tmp));
}

//uses private helper function "FindVehicle" to find the car which needs to be deleted
//throws and catches an exception if there is no such numberplate registered in the database
void Carpool::Remove(std::string const& numberplate) {
	try {
		VehicleCItor vehicleToDel = FindVehicle(numberplate);
		if (vehicleToDel == mVehicles.cend()) {
			throw exception("Delete failed: The entered numberplate is not registered in this carpool!");
		}
		else {
			mVehicles.erase(vehicleToDel);
		}
	}
	catch (exception const& ex) {
		cerr << ex.what() << endl;
	}
	catch (bad_alloc const& ex) {
		cerr << "memory allocation: " << ex.what() << endl;
	}
}


void Carpool::AddLogbookEntry(std::string const& numberplate, int const& day, 
						  int const& month, int const& year, int const distance) {
	VehicleItor tmp = FindVehicle(numberplate);
	(**tmp).AddNewLogbookEntry(day, month, year, distance);
}

void Carpool::ChangeLastLogbookEntry(std::string const& numberplate, int const& day,
									int const& month, int const& year, int const distance) {
	VehicleItor tmp = FindVehicle(numberplate);
	(**tmp).ChangeLastLogbookEntry(day, month, year, distance);
}

void Carpool::SearchByNumberplate(std::string const& numberplate) {
	VehicleCItor foundVehicle = FindVehicle(numberplate);
	if (foundVehicle == mVehicles.end()) {
		cerr << "The vehicle with the numberplate :" << numberplate << " is not registered in this carpool! " << endl;
	}
	else {
		(**foundVehicle).Print(cout);
	}
}

//Private Helperfunction based on STL-Find_if and a UnaryPred
//Returns Iterator to given numberplate (if found)
//Returns Iterator == cont.end() if not found
VehicleItor Carpool::FindVehicle(std::string const& numberplate)  {
	auto PredNumberP = [numberplate](unique_ptr<Vehicle> const&  v) {
		return (numberplate == (*v).GetNumberplate());
	};

	return find_if(mVehicles.begin(), mVehicles.end(), PredNumberP);
}

unsigned long Carpool::TotalMileage() const {
	unsigned long tmpMileage = 0;
	for (VehicleCItor i = mVehicles.cbegin(); i != mVehicles.cend(); i++ ) {
		tmpMileage += (**i).GetMileage();
	}
	return tmpMileage;
}

//Iterates through the container and performs a deep copy
Carpool& Carpool::operator=(Carpool const& toCopy) {
	if (&toCopy != this)  {
		for (VehicleCItor i = toCopy.mVehicles.cbegin(); i < toCopy.mVehicles.cend(); i++) {
			Add((**i).Clone());
		}
	}
	return *this;
}

//Overloaded Output-Operator
ostream& operator<<(ostream& ost, Carpool const& c) {
	if (ost.good()) {
		auto LPrint = [&ost](TUptr const& x) { (*x).Print(ost); ost << endl; };
		for_each(c.mVehicles.cbegin(), c.mVehicles.cend(), LPrint);
	}
	return ost;
}
