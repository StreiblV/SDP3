#include "MacroMovement.h"

void MacroMovement::Execute() {
	for (auto i = m_movement.cbegin(); i != --m_movement.cend(); i++) {
		(*i)->Execute();
		std::move(i, i, m_undoMovement.back());
	}
}

void MacroMovement::Unexecute() {
	for (auto i = --m_undoMovement.cend(); i != --m_undoMovement.cend(); i--) {
		(*i)->Unexecute();
		m_undoMovement.erase(i);
	}
}
