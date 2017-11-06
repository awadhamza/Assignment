#include "src/Command.hh"
#include "src/Interface.hh"

#include "src/Tokenizer.h"
#include <vector>
#include <string>

Command::~Command()
{
	for(unsigned i = CMDlist.size(); i > CMDlist.size(); --i)
	{
		delete CMDlist.at(i);
		CMDlist.at(i) = nullptr;
		CMDlist.pop_back();
	}
}

int Command::checkConnector(std::string conString){
        if(conString.at(conString.size() - 1) == '&'){
                return 3;
        }
        else if(conString.at(conString.size() - 1) == '|'){
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
        return cutString.substr(0, cutString.size() - 1);
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
                        if(basket == ""){
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
	//TEST CASE BELOW!
	//std::cout << "-----------------------------------------" << std::endl
	//		  << "THE FINAL VECTOR SIZE FOR THIS PROMPT IS: " << CMDlist.size() << std::endl
	//		  << "With these elements: " << std::endl;
	//		  for(unsigned i = 0; i < CMDlist.size(); ++i)
	//		  {
	//			  std::cout << CMDlist.at(i)->getInstruction() << std::endl;
	//		  }
}

std::vector<CMD*> Command::getVector()
{
	return CMDlist;
}

