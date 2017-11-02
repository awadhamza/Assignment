#include "Interface.hh"
#include "Menu.hh"
#include "Execute.hh"

Interface::Interface() {}

Interface::~Interface() {}

void Interface::orchestrate()
{
	while(true)
	{
		Menu *menu = new Menu();
		Command *command = new Command();
		Execute *eggsocute = new Execute();
		
		menu->getPrompt();
		command->splitString(menu->accessString());
		eggsocute->execute(command->getVector());
		
		delete menu;
		delete command;
		delete eggsocute;
	}
	return;
}
