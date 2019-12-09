/* ______________________________________________________________________
| Workfile : IDisplay.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef IDISPLAY_H
#define IDISPLAY_H

#include <memory>

class IDisplay {

public:
	virtual void Update() = 0;
	virtual ~IDisplay() = default;

	using SPter = std::shared_ptr<IDisplay>;
};

#endif //IDISPLAY_H

