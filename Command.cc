#include "Command.hh"
#include "Interface.hh"
#include "CMD.hh"
#include "Tokenizer.h"
#include <vector>
#include <string>

int Command::checkConnector(std::string conString){
        if(conString.at(conString.size() - 1) = "&"){
                return 3;
        }
        else if(conString.at(conString.size() - 1) = "|"){
                return 2;
        }
        else if(conString.at(conString.size() - 1) = ";"){
                return 1;
        }
        else{
                return 0;
        }
}

std::string Command::cutConnector(std::string cutString){
        return conString.substr(0, conString.size() - 1);
}

void Command::splitString(std::string instruction){
        Tokenizer splitter(instruction);

        int connection;
        std::string currCommand;
        std::string basket = "";
	CMD* temp;

        while((currCommand = splitter.next()) != "")
        {
                connection = checkConnector(currCommand);
                if(connection == 0){
                        if(basket = ""){
                                basket = currCommand;
                        }
                        else{
                                basket += " " + currCommand;
                        }
                }
                else{
                        if(connection == 1){
                                currCommand = cutConnector(currCommand);
                                basket += " " + currCommand;
			}
			
			temp = new CMD(basket, connection);
			CMDlist.push_back(temp);
			basket = "";
		}
	}
	temp = new CMD(basket, 0);
	CMDlist.push_back(temp);
}
