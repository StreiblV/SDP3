#ifndef CARPOOL

#include <string>
#include <stdio.h>
#include <list>
#include <iostream>

class Logbook
{
public:
	void AddNewEntry(std::string const& date, int const& distance);
	void PrintLogEntries();
	unsigned long GetTotalDistance() const;
	void ChangeLastEntry(std::string const& date, int const& distance);

private:
	typedef std::pair<std::string, int> Entry;
	std::list<Entry> m_entries;
};

#endif //CARPOOL