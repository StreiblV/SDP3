#include "Carpool.h"

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
	Carpool carpool;
	carpool.Add("Audi", "PE-21HR", Fuel::Diesel);
	carpool.Add("Daniels Sweetheart", "LL-Caro1", Fuel::Gas);
	carpool.Add("Fiat Multipla", "RO-666H", Fuel::Petrol);
	carpool.Add("VW Golf", "PE-35CK", Fuel::Electricity);

	//2. Remove Vehicle
	carpool.Remove("PE-35CK");	//should delete
	carpool.Remove("PE-35CK");	//no car should be found

	//3. Find Vehicle
	carpool.SearchByNumberplate("RO-666H"); //should find car
	carpool.SearchByNumberplate("RO-677H");	//no car should be found

	//4. Print vehicles
	carpool.PrintVehicles();


	//5. Logbook

	//6. Carpool copy & zuweisbar
	Carpool copied{ carpool };
	Carpool copied2;
	copied2 = copied;

	return 0;
}