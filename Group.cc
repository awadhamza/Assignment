#include "src/Group.hh"
#include "src/Tokenizer.h"
#include "src/Command.hh"

Group::Group(std::string newInstruction, int newConnector) : Base(){
		instruction = newInstruction;
		connector = newConnector;
		done = 0;
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
	for(unsigned i = 0; i < Grouplist.size(); i++)
	{
		Grouplist.at(i)->execute(Grouplist.at(i)->getInstruction(), Grouplist.at(i)->getConnector());
	}
	
	
}

bool Group::is_Group(){
	return true;
}
