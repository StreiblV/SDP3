#include "Carpool.h"

int main() {
	
	//TODO: Testfälle

	Carpool carpool;
	carpool.Add("PE-21HR", "Audi A6", Fuel::Diesel);
	carpool.Add("LL-Caro1", "Daniels Sweetheart", Fuel::Gas);
	carpool.Add("RO-666H", "Fiat Multipla", Fuel::Petrol);
	carpool.Add("PE-35CK", "VW Golf", Fuel::Electricity);

	return 0;
}