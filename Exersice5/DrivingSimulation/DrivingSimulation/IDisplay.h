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
	/**
	 * @brief pure virtual Function, ready to be implemented in an concrete observer
	 * @param -
	 * @return -
	 */
	virtual void Update() = 0;

	virtual ~IDisplay() = default;

	using SPter = std::shared_ptr<IDisplay>;
};

#endif //IDISPLAY_H

