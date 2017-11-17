#include "src/Command.hh"

#include "src/Interface.hh"

#include "src/Tokenizer.h"
#include "src/Interface.hh"

#include "src/Tokenizer.h"
#include <vector>
#include <string>

Command::~Command()
{
	for(unsigned i = CMDlist.size(); i > CMDlist.size(); --i)
	{
		delete CMDlist.at(i);
		CMDlist.at(i) = 0;
		CMDlist.pop_back();
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
	CMD* temp;

	if(instruction == ""){
		CMDlist.push_back(new CMD(instruction, 0));
		return;
	}

        while((currCommand = splitter.next()) != "")
        {
		connection = checkConnector(currCommand);
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
			CMDlist.push_back(temp);
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
			CMDlist.push_back(temp);
			basket = "";
		}
	}

	temp = new CMD(basket, 0);
	CMDlist.push_back(temp);
	
	if(instruction.at(instruction.size() - 1) == ';'){
		CMDlist.pop_back();
	}
	CMDlist.at(CMDlist.size() - 1) -> changeConnector(0);
}

std::vector<CMD*> Command::getVector()
{
	return CMDlist;
}

