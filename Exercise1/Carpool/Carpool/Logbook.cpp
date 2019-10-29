/*______________________________________________________________________
|Workfile:		Logbook.cpp
|Description:	Class for collection driver data
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/
#include "Logbook.h"
using namespace std;

void Logbook::AddNewEntry(Date const& date, int const& distance) {
	//check if date is valid
	if (date.day == 0 || date.month == 0 || date.year == 0) {
		return;
	}

	//check if there is already an entry in the list
	if (m_entries.empty()) {
		//add new entry to list
		m_entries.push_back(make_pair(date, distance));
	}else{
		//get last entry from the list
		Entry lastEntry = m_entries.back();

		try {
			//check if the new date is equal to the last entry's date
			if (lastEntry.first.day == date.day &&
				lastEntry.first.month == date.month &&
				lastEntry.first.year == date.year)
			{
				//delete last entry
				m_entries.pop_back();
				//add new entry + old entry's kilometer
				m_entries.push_back(make_pair(date, distance + lastEntry.second));
			}
			
			//check if the new entry is older than the last one
			if (date.year == lastEntry.first.year) {
				if (date.month < lastEntry.first.month) {
					throw exception("Wrong Date: Please input a date after the last entry");
				}
				else if (date.month == lastEntry.first.month) {
					if (date.day < lastEntry.first.day) {
						throw exception("Wrong Date: Please input a date after the last entry");
					}
				}
			}else if (date.year < lastEntry.first.year) {
				throw exception("Wrong Date: Please input a date after the last entry");
			}
			else {
				//add new entry to list
				m_entries.push_back(make_pair(date, distance));
			}
		}
		catch (exception const& ex) {
			cerr << ex.what() << endl;
		}
	}
}

ostream& Logbook::PrintLogEntries(ostream& ost) {
	//check if ostream is valid
	if (ost.good()) {
		//print all log entries
		for (auto e : m_entries) {
			ost << e.first.day << ".";
			ost << e.first.month << ".";
			ost << e.first.year << "    ";
			ost << e.second << " km";
			ost << endl;
		}
	}
	return ost;
}

unsigned long Logbook::GetTotalDistance() const {
	unsigned long sum = 0;
	//adds up all driven kilometers
	for (auto e : m_entries) {
		sum += e.second;
	}
	return sum;
}

void Logbook::ChangeLastEntry(Date const& date, int const& distance) {
	//remove last entry
	m_entries.pop_back();
	//add new entry
	m_entries.push_back(make_pair(date, distance));
}