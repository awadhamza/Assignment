#include "src/Group.hh"
#include "src/Tokenizer.h"
#include "src/Command.hh"
#include "src/Execute.hh"

Group::Group(std::string newInstruction, int newConnector) : Base(){
		instruction = newInstruction;
		connector = newConnector;
		done = 0;
	}
	
Group::~Group(){
	for(unsigned i = 0; i < Grouplist.size(); i++){
		Grouplist.pop_back();
	}
}

void Group::makeGroup(string instruction)
{
		Command* splitCommands = new Command();
		splitCommands -> splitString(instruction);
		Grouplist = splitCommands -> getVector();
}

void Group::execute(string execCommand, int testOrBrac)
{
	makeGroup(instruction);
	Execute *execGroup = new Execute();
	execGroup -> execute(Grouplist);
	setDone(Grouplist.at(Grouplist.size() - 1) -> getDone());
}

bool Group::is_Group(){
	return true;
}
