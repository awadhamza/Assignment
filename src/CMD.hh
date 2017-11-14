#ifndef CMD_HH
#define CMD_HH

<<<<<<< HEAD:src/CMD.hh
//#include "Command.hh"
=======

>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368:src/CMD.hh
#include <iostream>
#include <vector>

class CMD {
	private:
		std::string instruction;
		int connector;
	public:
		CMD();
		CMD(std::string, int);
		int getConnector();
		std::string getInstruction();
};

#endif
