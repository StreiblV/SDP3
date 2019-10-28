/*______________________________________________________________________
|Workfile:		Logbook.h
|Description:	[HEADER] Class for collection driver data
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#ifndef LOGBOOK
#define LOGBOOK

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

#endif //LOGBOOK