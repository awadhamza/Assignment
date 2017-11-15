#ifndef EXECUTE_HH
#define EXECUTE_HH

#include "CMD.hh"

#include <vector>
using std::vector;

class Execute {
	private:
	
	public:
		Execute();
		~Execute();
		void doThis(char[] , char*[]);
		void execute(vector<CMD*> );
		
		
};


#endif
