#include "Control.h"
#include "Control.h"

void Control::AddCommand(TcmdPtr cmd) {
	try {
		if (cmd == nullptr) {
			throw("Given Command is nullptr!");
		}
		m_commands.emplace_back(cmd);
	}
	catch (std::bad_alloc const& ex) {
		std::cerr << "Memory allocation: " << ex.what() << std::endl;
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception in AddCommand: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unhandled exception in AddCommand()!" << std::endl;
	}
}

void Control::Start() {
	try {
		for (auto i = m_commands.cbegin(); i != --m_commands.cend(); i++) {
			(*i)->Execute();
			std::move(i, i, back_inserter(m_undoList));
		}
	}
	catch (std::bad_alloc const& ex) {
		std::cerr << "Memory allocation: " << ex.what() << std::endl;
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unhandled exception in Start()!" << std::endl;
	}

}

void Control::Undo(size_t const count) {
	try {
		for (auto i = --m_undoList.cend(); i != (m_undoList.cend() - count); i--) {
			(*i)->Unexecute();
			m_undoList.erase(i);
		}
	}
	catch (std::bad_alloc const& ex) {
		std::cerr << "Memory allocation: " << ex.what() << std::endl;
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unhandled exception in Undo()!" << std::endl;
	}
}

void Control::Reset() {
	m_commands.clear();
	Undo(m_undoList.size());
}
