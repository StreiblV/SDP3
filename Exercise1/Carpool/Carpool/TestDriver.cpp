/*______________________________________________________________________
|Workfile:		TestDriver.cpp
|Description:	File for testing the code
|Name:			Viktoria Streibl						PKZ: S1810306013
				Daniel Weyrer							PKZ: S1820306044
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/
#include "Carpool.h"

void SectionHeader(std::string headerTitle);

int main() {

	/*
		1. Hinzufügen von neuen Fahrzeugen.
		2. Entfernen von bestehenden Fahrzeugen.
		3. Suchen eines Fahrzeuges nach seinem Kennzeichen.
		4. Ausgeben aller Fahrzeuge samt ihrer Eigenschaften und dem Fahrtenbuch auf dem Ausgabestrom
		und in einer Datei.
		5. Verwenden Sie im Fuhrpark zur Verwaltung aller Fahrzeuge einen entsprechenden Container!
		6. Der Fuhrpark muss kopierbar und zweisbar sein!
	*/

	//1. Add Vehicles
	SectionHeader("1. Add Vehicles");
	Carpool carpool;
	//Cars
	carpool.AddCar("Audi", "PE-21HR", Fuel::Diesel);
	carpool.AddCar("Daniels Sweetheart", "LL-Caro1", Fuel::Gas);
	carpool.AddCar("Fiat Multipla", "RO-666H", Fuel::Petrol);
	carpool.AddCar("VW Golf", "PE-35CK", Fuel::Electricity);
	std::cout << "Cars added successfully..." << std::endl;
	//Trucks
	carpool.AddTruck("Man", "LL-Bau1", Fuel::Diesel);
	carpool.AddTruck("Mercedes", "LE-Bau2", Fuel::Diesel);
	carpool.AddTruck("Volvo", "FR-Erde1", Fuel::Petrol);
	std::cout << "Trucks added successfully..." << std::endl;
	//Motorcycles
	carpool.AddMotorcycle("BMW", "IL-24TW", Fuel::Petrol);
	carpool.AddMotorcycle("Honda", "PE-VS13", Fuel::Petrol);
	std::cout << "Motorcycles added successfully..." << std::endl;
	std::cout << std::endl;

	//2. Remove Vehicle
	SectionHeader("2. Remove Vehicle");
	carpool.Remove("PE-35CK");	//should be able to delete
	std::cout << "Car removed successfully..." << std::endl;
	carpool.Remove("LE-Bau2");	//should be able to delete
	std::cout << "Truck removed successfully..." << std::endl;
	carpool.Remove("PE-VS13");	//should be able to delete
	std::cout << "Motorcycle removed successfully..." << std::endl;

	carpool.Remove("PE-35CK");	//no car should be found
	std::cout << std::endl;


	//3. Find Vehicle
	SectionHeader("3. Find Vehicle");
	carpool.SearchByNumberplate("RO-666H"); //should find car
	carpool.SearchByNumberplate("RO-677H");	//no car should be found
	std::cout << std::endl;

	//4. Print vehicles
	SectionHeader("4. Print vehicles");
	std::cout << carpool << std::endl;
	std::cout << std::endl;

	//5. Logbook
	SectionHeader("5. Logbook");
	std::cout << "Add 3 Entries" << std::endl;
	carpool.AddLogbookEntry("LL-Caro1", 14, 2, 2017, 45);		//works...
	carpool.AddLogbookEntry("LL-Caro1", 25, 2, 2017, 46);		//works...
	carpool.AddLogbookEntry("LL-Caro1", 14, 2, 2018, 5);		//works...

	std::cout << "Add Entry with same date" << std::endl;
	carpool.AddLogbookEntry("LL-Caro1", 14, 2, 2018, 45);		//should be combined with the last entry
	carpool.AddLogbookEntry("LL-Caro1", 23, 12, 2018, 45);		//works...

	std::cout << "Add old Entry" << std::endl;
	carpool.AddLogbookEntry("LL-Caro1", 14, 12, 2017, 45);		//dont work - to old

	std::cout << "Add Entry for the future" << std::endl;
	carpool.AddLogbookEntry("LL-Caro1", 14, 12, 2019, 45);		//dont work - to old
	std::cout << std::endl;

	//6. Carpool copy & co
	SectionHeader("6. Carpool copy & co");
	Carpool copied{ carpool };
	Carpool copied2;
	copied2 = copied;
	
	std::cout << "Original..." << std::endl;
	std::cout << carpool << std::endl;
	std::cout << "Copied via Copy-CTor..." << std::endl;
	std::cout << copied << std::endl;
	std::cout << "Copied via Assignment..." << std::endl;
	std::cout << copied2 << std::endl;

	return 0;
}

void SectionHeader(std::string headerTitle) {
	std::cout << "##################################" << std::endl;
	std::cout << "## " << headerTitle << std::endl;
	std::cout << "##################################" << std::endl;
}