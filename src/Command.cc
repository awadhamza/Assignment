#include "Command.hh"

#include "Interface.hh"

#include "Tokenizer.h"
#include "Interface.hh"

#include "Tokenizer.h"
#include <vector>
#include <string>

using std::endl;
using std::cout;

Command::~Command()
{
	for(unsigned i = commandList.size(); i > commandList.size(); --i)
	{
		delete commandList.at(i);
		commandList.at(i) = 0;
		commandList.pop_back();
	}
}

int Command::checkConnector(std::string conString){
	if(conString == "[" && conString.size() == 1){
		return 5;
	}
	else if(conString == "test" && conString.size() == 4){
		return  4;
	}
    	else if(conString.at(conString.size() - 1) == '&' && conString.at(conString.size() - 2) == '&'){
		return 3;
	}
    	else if(conString.at(conString.size() - 1) == '|' && conString.at(conString.size() - 2) == '|'){
        	return 2;
    	}
    	else if(conString.at(conString.size() - 1) == ';'){
		return 1;
    	}
    	else{
        	return 0;
    	}
}

std::string Command::cutConnector(std::string cutString){
	std::string temp;
	if(cutString == "]"){
		temp = cutString;
	}
	else{
		temp = cutString.substr(0, cutString.size() - 1);
        }
	return temp;
}

void Command::splitString(std::string instruction){
        Tokenizer splitter(instruction);

        int connection;
        std::string currCommand;
        std::string basket = "";
		Base* temp;

	if(instruction == ""){
		commandList.push_back(new CMD(instruction, 0));
		return;
	}
	
		bool stringDone = false;

        while((currCommand = splitter.next()) != "")
        {
			stringDone = false;
			int parenCount = 0;
			if(currCommand.at(0) == '('){
				while(!stringDone){
					if(currCommand == ""){
							exit(0);
					}
					if(currCommand.at(currCommand.size() - 1) == ')'){
						if(parenCount == 0){
							stringDone = true;
						}
						else{
							parenCount--;
						}
					}
					if(basket == ""){
						basket = currCommand;
					}
					else{
						basket += " " + currCommand;
					}
					currCommand = splitter.next();
					if(currCommand != "" && currCommand.at(0) == '('){
						parenCount++;
					}
				}
				if(basket.at(0) == '('){
					basket = basket.substr(1, basket.size() - 2);
				}
				if(basket.at(basket.size() - 1) == ')'){
					basket = basket.substr(0, basket.size() - 2);
				}
				if(currCommand != ""){
					connection = checkConnector(currCommand);
				}
				else{
					connection = 0;
				}
				temp = new Group(basket, connection);
				commandList.push_back(temp);
				
				basket = "";
				
				if(currCommand != ""){
				currCommand = splitter.next();
				}
			}
		
			if(stringDone && currCommand == ""){
				return;
			}
		
			if(currCommand == ""){
				connection = 0;
			}
			else{
				connection = checkConnector(currCommand);
			}
			
			if(connection == 0){
				if(basket == ""){
					basket = currCommand;
				}
				else{
					basket += " " + currCommand;
				}
			}
		else if(connection == 4 || connection == 5){
			temp = new CMD("", connection);
			commandList.push_back(temp);
		}
        else{
			if(connection == 1){
					currCommand = cutConnector(currCommand);
					if(basket == ""){
						basket = currCommand;
					}
					else if(currCommand == "]"){}
					else{
						basket += " " + currCommand;
					}
			}
			temp = new CMD(basket, connection);
			commandList.push_back(temp);
			basket = "";
		}
	}
	
	temp = new CMD(basket, 0);
	commandList.push_back(temp);
	basket = "";
	
	if(instruction.at(instruction.size() - 1) == ';'){
		commandList.pop_back();
	}
	commandList.at(commandList.size() - 1) -> changeConnector(0);
}

std::vector<Base*> Command::getVector()
{
	return commandList;
}

