#include "Interface.hh"

#include <iostream>

Interface::Interface() {}

Interface::~Interface() {}

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
