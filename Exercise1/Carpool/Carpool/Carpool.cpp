#include "Carpool.h"

using namespace std; 

Carpool::Carpool() {
}

Carpool::~Carpool() {
}

Carpool::Carpool(Carpool const& toCopy) {
	mVehicles = toCopy.mVehicles;
}

void Carpool::Add(Vehicle vehicle) {
	try {
		if (FindVehicle(vehicle.GetNumberplate()) != mVehicles.cend()) {
			throw exception("Add failed: Number already in the Database!");
		}

		mVehicles.emplace_back(vehicle);
	}
	catch (exception const& ex) {
		cerr << ex.what() << endl;
		return;
	}
	catch (bad_alloc const& ex) {
		cerr << "memory allocation: " << endl;
	}
}

void Carpool::Add(std::string const& brand, std::string const& numberplate, Fuel fuel) {
	Vehicle tmp{ brand, numberplate, fuel };
	Add(tmp);
}

void Carpool::Remove(std::string const& numberplate) {
	try {
		auto vehicleToDel = FindVehicle(numberplate);
		if (vehicleToDel == mVehicles.cend()) {
			throw exception("Delete failed: The entered numberplate is not registered in this carpool!");
		}
		else {
			mVehicles.erase(vehicleToDel);
		}
	}
	catch (exception const& ex) {
		cerr << ex.what() << endl;
		return;
	}
	catch (bad_alloc const& ex) {
		cerr << "memory allocation: " << endl;
	}
}

void Carpool::AddLogbookEntry(std::string const& numberplate, std::string const& date, int const distance) {
	VehicleItor tmp = FindVehicle(numberplate);
	(*tmp).AddNewLogbookEntry(date, distance);

}

void Carpool::ChangeLastLogbookEntry(std::string const& numberplate, std::string const& date, int const distance) {
	VehicleItor tmp = FindVehicle(numberplate);
	(*tmp).ChangeLastLogbookEntry(date, distance);
}

void Carpool::SearchByNumberplate(std::string const& numberplate) {
	auto foundVehicle = FindVehicle(numberplate);
	if (foundVehicle == mVehicles.end()) {
		cout << "The vehicle with the numberplate :" << numberplate << " is not registered in this carpool! " << endl;
	}
	else {
		Vehicle currentVehicle = *foundVehicle;
		currentVehicle.Print();
	}
}

VehicleItor Carpool::FindVehicle(std::string const& numberplate)  {
	auto PredNumberP = [numberplate](Vehicle vehicle) { //can be deleted after == operator is overloaded!
		return (numberplate == vehicle.GetNumberplate());
	};

	return find_if(mVehicles.begin(), mVehicles.end(), PredNumberP);
}

void Carpool::PrintVehicles() {
	for (Vehicle elem : mVehicles) {
		elem.Print();
	}
}

unsigned long Carpool::TotalMileage() const {
	unsigned long tmpMileage = 0;
	for (Vehicle const elem : mVehicles) {
		tmpMileage += elem.GetMileage();
	}
	return tmpMileage;
}

Carpool& Carpool::operator=(Carpool const& toCopy) {
	if (&toCopy != this)  {
		mVehicles = toCopy.mVehicles;
	}
	return *this;
}

