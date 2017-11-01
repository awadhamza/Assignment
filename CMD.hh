#ifndef CMD_HH
#define CMD_HH
#include "Tokenizer.h"
#include "Command.hh"
#include <iostream>

class CMD : public Command {
	private:
		std::string instruction;
		int connector;
	public:
		CMD();
		~CMD();
		CMD(std::string, int);
		int getConnector();
		std::string getString();
};

#endif
