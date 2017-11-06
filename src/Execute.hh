#ifndef EXECUTE_HH
#define EXECUTE_HH

#include <string>

#include <vector>
#include "CMD.hh"

class Execute {
	private:
		char** executables;
		int executablesSize = 0;
	public:
		Execute();
		~Execute();
		void execute(std::vector<CMD*> );
		char* makeCharPointers(std::vector<CMD*> );
		
};


#endif
