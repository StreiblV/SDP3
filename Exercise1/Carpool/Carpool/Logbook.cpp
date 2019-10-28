#include "Logbook.h"
using namespace std;

void Logbook::AddNewEntry(string date, int distance) {
	m_entries.push_back(make_pair(date, distance));
}

void Logbook::PrintLogEntries() {
	for (auto e : m_entries) {
		cout << e.first;
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

void Logbook::ChangeLastEntry(std::string date, int distance) {
	m_entries.pop_back();
	m_entries.push_back(make_pair(date, distance));
}