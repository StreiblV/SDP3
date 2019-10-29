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
	if (date.day == 0 || date.month == 0 || date.year == 0) {
		return;
	}

	if (m_entries.empty()) {
		m_entries.push_back(make_pair(date, distance));
	}else{
		Entry lastEntry = m_entries.back();

		try {
			if (lastEntry.first.day == date.day &&
				lastEntry.first.month == date.month &&
				lastEntry.first.year == date.year)
			{
				m_entries.pop_back();
				m_entries.push_back(make_pair(date, distance + lastEntry.second));
			}
			
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
				m_entries.push_back(make_pair(date, distance));
			}
		}
		catch (exception const& ex) {
			cerr << ex.what() << endl;
		}
	}
}

ostream& Logbook::PrintLogEntries(ostream& ost) {
	if (ost.good()) {
		for (auto e : m_entries) {
			ost << e.first.day << ".";
			ost << e.first.month << ".";
			ost << e.first.year << ".";
			ost << e.second << " km";
			ost << endl;
		}
	}
	return ost;
}

unsigned long Logbook::GetTotalDistance() const {
	unsigned long sum = 0;
	for (auto e : m_entries) {
		sum += e.second;
	}
	return sum;
}

void Logbook::ChangeLastEntry(Date const& date, int const& distance) {
	m_entries.pop_back();
	m_entries.push_back(make_pair(date, distance));
}