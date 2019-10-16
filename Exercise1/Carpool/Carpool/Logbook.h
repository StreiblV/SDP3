#ifndef CARPOOL

#include <string>
#include <stdio.h>
#include <list>
#include <iostream>

class Logbook
{
public:
	void AddNewEntry(std::string date, int distance);
	void PrintLogEntries();
	int GetTotalDistance();
	void ChangeLastEntry(std::string date, int distance);

private:
	typedef std::pair<std::string, int> Entry;
	std::list<Entry> m_entries;
};

#endif //CARPOOL