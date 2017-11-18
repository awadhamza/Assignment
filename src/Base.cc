#include "Base.hh"

void Base::changeConnector(int newConnector){
		connector = newConnector;
		return;
}

int Base::getConnector(){
	return connector;
}

int Base::getDone(){
	return done;
}

void Base::setDone(int newDone){
	done = newDone;
	return;
}

std::string Base::getInstruction(){
	return instruction;
}
