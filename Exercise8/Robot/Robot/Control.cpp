#include "Control.h"
#include "Control.h"

void Control::AddCommand(TcmdPtr cmd) {
	try {
		if (cmd == nullptr) {
			throw std::exception("Given Command is nullptr!");
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
		//iterate through vector and call Execute() on all elements, copy to undolist after execution
		for (auto elem : m_commands) {
			elem->Execute();
			m_undoList.emplace_back(elem);
		}
	}
	catch (std::bad_alloc const& ex) {
		std::cerr << "Memory allocation: " << ex.what() << std::endl;
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception during Execution: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unhandled exception in Start()!" << std::endl;
	}

}

void Control::Undo(size_t const count) {
	try {
		size_t i = 0;
		while(i < count && m_undoList.size() > 0 ) {
			m_undoList.back()->Unexecute();
			m_undoList.pop_back();
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
