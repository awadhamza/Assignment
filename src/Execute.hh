#ifndef EXECUTE_HH
#define EXECUTE_HH

#include <string>
#include <vector>

#include "src/CMD.hh"

class Execute {
	private:
		char** executables;
		int executablesSize = 0;
	public:
		Execute();
		~Execute();
		void execute(std::vector<CMD*> );
		void makeCharPointers(std::vector<CMD*> );
		
};


#endif
