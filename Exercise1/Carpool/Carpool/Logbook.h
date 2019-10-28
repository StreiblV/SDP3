#ifndef CARPOOL

#include <string>
#include <stdio.h>
#include <list>
#include <iostream>

class Logbook
{
public:
	struct Date {
		size_t day;
		size_t month;
		size_t year;
	};

	void AddNewEntry(Date const& date, int const& distance);
	void PrintLogEntries();
	unsigned long GetTotalDistance() const;
	void ChangeLastEntry(Date const& date, int const& distance);

private:
	typedef std::pair<Date, int> Entry;
	std::list<Entry> m_entries;
};

#endif //CARPOOL