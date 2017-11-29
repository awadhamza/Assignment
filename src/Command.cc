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
	if(instruction.at(0) == '#'){
		return;
	}
	std::string firstPart;
	std::string secondPart;
	bool notInQuotes = true;
	for(unsigned int i = 0; i < instruction.size() - 1; i++){
		if(instruction.at(i) == '&' && instruction.at(i + 1) == '&' && notInQuotes){
			firstPart = instruction.substr(0, i);
			secondPart = instruction.substr((i + 2), instruction.size());
			firstPart += " && ";
			firstPart += secondPart;
			instruction = firstPart;
			i += 2;
		}
		if(instruction.at(i) == '|' && instruction.at(i + 1) == '|' && notInQuotes){
			firstPart = instruction.substr(0, i);
                        secondPart = instruction.substr((i + 2), instruction.size());
                        firstPart += " || ";
                        firstPart += secondPart;
			instruction = firstPart;
			i += 2;
		}
		if(instruction.at(i) == '\"'){
			if(notInQuotes)
				notInQuotes = false;
			else
				notInQuotes = true;
		}
	}
	notInQuotes = true;
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
			int openParenCount = 0;
			int closedParenCount = 0;

			if(currCommand.at(0) == '('){
				while(!stringDone){
					if(currCommand == ""){
						if(!stringDone){
							cout << "Missing ')'" << endl;
							exit(0);
						}
						break;
					}
						
					if(basket == ""){
						basket = currCommand;
					}
					else{
						basket += " " + currCommand;
					}
					currCommand = splitter.next();
					
					openParenCount = 0;
					for(unsigned int k = 0; k < basket.size(); k++){
						if(basket.at(k) == '('){
                                                        openParenCount++;
                                                }
					}
					 closedParenCount = 0;
                                        for(unsigned int k = 0; k < basket.size(); k++){
                                                if(basket.at(k) == ')'){
                                                        closedParenCount++;
                                                }
                                        }
                                        if(closedParenCount == openParenCount){
                                                stringDone = true;
                                        }
				}
				
				if(basket.at(0) == '('){
					basket = basket.substr(1, basket.size() - 2);
				}
				if(basket.at(basket.size() - 1) == ')'){
					basket = basket.substr(0, basket.size());
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
			if(currCommand.size() > 0 && currCommand.at(0) == '\"'){
				do{
					if(currCommand == ""){
						cout << "Missing '\"'" << endl;
                                                exit(0);
						return;
					}
				
					basket += " " + currCommand;
					currCommand = splitter.next();
				
				} while(basket.at(basket.size() - 1) != '\"');

				if(currCommand == ""){
					connection = 0;
				} 
				else{
					connection = checkConnector(currCommand);
				}
				temp = new CMD(basket, connection);
				commandList.push_back(temp);

				basket = "";

				if(currCommand != ""){
					currCommand = splitter.next();
				}
				else{
					return;
				}
			}
			
			if(currCommand.size() > 0 && currCommand.at(0) == '#'){
				temp = new CMD(basket, 0);
                        	commandList.push_back(temp);
                		return;
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

