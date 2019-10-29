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

	//add new logbook entry to list
	void AddNewEntry(Date const& date, int const& distance);

	//print all logbook entries
	std::ostream& PrintLogEntries(std::ostream& ost);

	//calculate all driven kilometers
	unsigned long GetTotalDistance() const;

	//change the last logbook entry in the list
	void ChangeLastEntry(Date const& date, int const& distance);

private:
	typedef std::pair<Date, int> Entry;
	std::list<Entry> m_entries;
};

#endif //LOGBOOK