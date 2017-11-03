#include "Interface.hh"
#include "Menu.hh"
#include "Execute.hh"

using std::vector;
using std::cout;
using std::endl;
using std::cin;

Interface::Interface() : connectors(0), commands(0) {}

Interface::~Interface() {}

void Interface::changeConVec(vector<int> newConnectors) {
	 connectors = newConnectors;
 }

void Interface::changeCommandVec(vector<vector<char*>> newCommands) {
	commands = newCommands;
}


void Interface::orchestrate()
{
	while(true)
	{
		Menu *menu = new Menu();
		Command *command = new Command();
		Execute *eggsocute = new Execute();
		
		menu->getPrompt();
		command->splitString(menu->accessString());
		changeConVec(command -> getConVec());
		changeCommandVec(command -> getCommandVec());
		eggsocute->execute(commands, connectors);
		
		delete menu;
		delete command;
		delete eggsocute;
	}
	return;
}
