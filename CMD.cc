#include "CMD.hh"
#include <vector>

CMD::CMD() : instruction(""), connector(0) {}

CMD::~CMD() {}

CMD::CMD(std::string instruction, int connector) : instruction(instruction), connector(connector) {}

int CMD::getConnector(){
	return connector;
}

std::string CMD::getString(){
	return instruction;
}
