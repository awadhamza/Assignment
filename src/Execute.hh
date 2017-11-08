#ifndef EXECUTE_HH
#define EXECUTE_HH

#include <string>
#include <vector>

#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include "Tokenizer.h"

#include "CMD.hh"

class Execute {
	private:
		char** executables[1024];
		int executablesSize = 0; //The index
	public:
		Execute();
		~Execute();
		void execute(std::vector<CMD*> );
		void makeCharPointers(std::vector<CMD*> );
		
};


#endif
