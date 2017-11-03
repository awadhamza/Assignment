#include "CMD.hh"
#include <vector>
#include <sstream>

using namespace std;

CMD::CMD() : instruction(""), connector(0) {}


CMD::CMD(std::string instruction, int connector) : instruction(instruction), connector(connector) {}

int CMD::getConnector(){
	return connector;
}

string CMD::getInstruction(){
	/*
	istringstream inSS(instruction);
	string curr = "";
	vector<char*> v;
	while(inSS >> curr){
	   v.push_back((char*)curr.c_str());
        }
	

//	char* args[25];
	char* args;
	for(int i = 0; i < v.size(); i++){
		args[i] = *v.at(i);
	}
	args[v.size()] = 0;
	return args;
	*/
	
	//return instruction.c_str();
	return instruction;
}
