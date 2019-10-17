#include "Carpool.h"

using namespace std; 

void Carpool::Add(Vehicle const& vehicle) {
	try {
		if (FindVehicle(vehicle.GetNumberplate()) == mVehicles.cend()) {
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

void Carpool::Remove(std::string const& numberplate) {
	try {
		auto vehicleToDel = FindVehicle(numberplate);
		if (vehicleToDel == mVehicles.cend()) {
			throw exception("Delete failed: the entered numberplate is not existing!");
		}
		remove(mVehicles.begin(), mVehicles.end(), *vehicleToDel);
	}
	catch (exception const& ex) {
		cerr << ex.what() << endl;
		return;
	}
	catch (bad_alloc const& ex) {
		cerr << "memory allocation: " << endl;
	}
}

void Carpool::SearchByNumberplate(std::string const& numberplate) {
	auto foundVehicle = FindVehicle(numberplate);
	if (foundVehicle != mVehicles.end()) {
		cout << "The vehicle with the numberplate :" << numberplate << "is not registered in this carpool! " << endl;
	}
	*foundVehicle.Print();
}



VehicleCItor Carpool::FindVehicle(std::string const& numberplate) const {
	auto PredNumberP = [numberplate](Vehicle const& vehicle) { //can be deleted after == operator is overloaded!
		return (numberplate == vehicle.GetNumberPlate());
	};

	return find_if(mVehicles.cbegin(), --mVehicles.cend(), PredNumberP);
}

unsigned long Carpool::TotalMileage() const {
	return 0;
}

