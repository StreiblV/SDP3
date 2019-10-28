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

Carpool::Carpool(Carpool const& toCopy) {
	*this = toCopy;
}

void Carpool::Add(Vehicle vehicle) {
	try {
		if (FindVehicle(vehicle.GetNumberplate()) != mVehicles.cend()) {
			throw exception("Add failed: Number already in the Database!");
		}

		mVehicles.emplace_back(make_unique<Vehicle>(vehicle));
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
	Add(tmp);
}

void Carpool::AddTruck(std::string const& brand, std::string const& numberplate, Fuel fuel) {
	Truck tmp{ brand, numberplate, fuel };
	Add(tmp);
}

void Carpool::AddMotorcycle(std::string const& brand, std::string const& numberplate, Fuel fuel) {
	Motorcycle tmp{ brand, numberplate, fuel };
	Add(tmp);
}

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
		cout << "The vehicle with the numberplate :" << numberplate << " is not registered in this carpool! " << endl;
	}
	else {
		//Vehicle currentVehicle = **foundVehicle;
		(**foundVehicle).Print();
	}
}

VehicleItor Carpool::FindVehicle(std::string const& numberplate)  {
	auto PredNumberP = [numberplate](unique_ptr<Vehicle> const&  v) {
		return (numberplate == (*v).GetNumberplate());
	};

	return find_if(mVehicles.begin(), mVehicles.end(), PredNumberP);
}

void Carpool::PrintVehicles() {
	auto LPrint = [](TUptr const& x) { (*x).Print(); };
	//for_each(mVehicles.cbegin(), mVehicles.cend(), LPrint);
	for (VehicleCItor i = mVehicles.cbegin(); i != mVehicles.cend(); i++) {
		(**i).Print();
	}
}

unsigned long Carpool::TotalMileage() const {
	unsigned long tmpMileage = 0;
	for (VehicleCItor i = mVehicles.cbegin(); i != mVehicles.cend(); i++ ) {
		tmpMileage += (**i).GetMileage();
	}
	return tmpMileage;
}

Carpool& Carpool::operator=(Carpool const& toCopy) {
	if (&toCopy != this)  {
		for (VehicleCItor i = toCopy.mVehicles.cbegin(); i < toCopy.mVehicles.cend(); i++) {
			Vehicle tmp = (**i);
			Add(tmp);
		}
	}
	return *this;
}