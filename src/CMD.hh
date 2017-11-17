#ifndef CMD_HH
#define CMD_HH

#include "Base.hh"

#include <iostream>
#include <vector>

class CMD : public Base {
	private:
	public:
		CMD();
		CMD(std::string, int);
		void execute(std::string, int);
		int execute_fork(char[], char*[]);
		std::string getInstruction();
		int execute_stat(char [], char );
		bool is_Group();
};

#endif
