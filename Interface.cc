#include "Interface.hh"

#include <iostream>

Interface::Interface() {}

Interface::~Interface() {}

void Interface::changeConVec(vector<int> newConnectors) : connectors(newConnectors){}

void Interface::changeCommandVec(vector<vector<char*>> newCommands) : commands(newCommands){}

void Interface::orchestrate()
{
	
	Menu *menu;
	Command *command;
	Execute *eggsocute;
	
	menu->getPrompt();
	command->splitString(menu->accessString());
	eggsocute->execute();
	
	return;
}
