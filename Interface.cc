#include "Interface.hh"

Interface::Interface() {}

Interface::~Interface() {}

void Interface::orchestrate()
{
	
	Menu menu;
	Command command;
	Execute eggsocute;
	
	menu.getPrompt();
	command.splitString(Menu::accessString());
	eggsocute.execute();
	
	return;
}
