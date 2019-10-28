#include "Logbook.h"
using namespace std;

void Logbook::AddNewEntry(Date const& date, int const& distance) {
	Entry lastEntry = *m_entries.end();

	try {
		if (lastEntry.first.day == date.day &&
			lastEntry.first.month == date.month &&
			lastEntry.first.year == date.year)
		{
			m_entries.pop_back();
			m_entries.push_back(make_pair(date, distance + lastEntry.second));
		}
		else if (lastEntry.first.day == date.day &&
			lastEntry.first.month == date.month &&
			lastEntry.first.year == date.year)
		{
			throw exception("Wrong Date: Please input a date after "+
							lastEntry.first.day + '.' + 
							lastEntry.first.month + '.' +
							lastEntry.first.year);
		}
		else {
			m_entries.push_back(make_pair(date, distance));
		}
	}
	catch (exception const& ex) {
		cerr << ex.what() << endl;
	}	
}

void Logbook::PrintLogEntries() {
	for (auto e : m_entries) {
		cout << e.first.day << ".";
		cout << e.first.month << ".";
		cout << e.first.year << ".";
		cout << e.second << " km";
		cout << endl;
	}
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