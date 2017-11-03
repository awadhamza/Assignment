#include "Interface.hh"
#include "Menu.hh"
#include "Execute.hh"

Interface::Interface() {}

Interface::~Interface() {}

void Interface::changeConVec(vector<int> newConnectors) : connectors(newConnectors){}

void Interface::changeCommandVec(vector<vector<char*>> newCommands) : commands(newCommands){}

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
