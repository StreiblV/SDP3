/* ______________________________________________________________________
| Workfile : Object .h
| Description : [ HEADER ] Class for the global Object
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef OBJECT_INCLUDED
#define OBJECT_INCLUDED
class Object {
public:
	// ------------------------------------------------------------------------
	// Destructor of the class Object
	// -------------------------------------------------------------------------
	virtual ~Object() = default;
protected:
	// ------------------------------------------------------------------------
	// Constructor of the class Object
	// No object of the class can be created directly
	// -------------------------------------------------------------------------
	Object() = default;
};
#endif //OBJECT_INCLUDED