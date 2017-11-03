#ifndef CMD_HH
#define CMD_HH


#include <iostream>

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
