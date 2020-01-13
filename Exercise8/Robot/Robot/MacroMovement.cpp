#include "MacroMovement.h"

void MacroMovement::Execute() {
	for (auto elem : m_movement) {
		if (elem == nullptr) {
			throw std::exception("Nullptr in given commandlist of MacroMovement!");
		}
		elem->Execute();
		m_undoMovement.emplace_back(elem);
	}
}

void MacroMovement::Unexecute() {
	size_t i = 0;
	while (i < m_undoMovement.size() && m_undoMovement.size() > 0) {
		m_undoMovement.back()->Unexecute();
		m_undoMovement.pop_back();
	}
}
