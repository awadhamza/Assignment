#ifndef CMD_HH
#define CMD_HH

//#include "Command.hh"

#include <iostream>
#include <vector>

class CMD {
	private:
		std::string instruction;
		int connector;
		int done;
	public:
		CMD();
		CMD(std::string, int);
		int getConnector();
		void changeConnector(int);
		int getDone();
		void setDone(int);
		void execute();
		int execute_fork(char[], char*[]);
		std::string getInstruction();
};

#endif
