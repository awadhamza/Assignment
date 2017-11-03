#include "Command.hh"
#include "Interface.hh"
#include "Tokenizer.hh"
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
        vector<vetor<char*>> commandVector;
        vector<int> connectorVector;
        vector<char*> commandChars;

        while((currCommand = splitter.next()) != "")
        {
                connection = checkConnector(currCommand);
                if(connection == 0){
                        commandChars.push_back(currCommand.c_str());
                }
                else{
                        if(connection == 1){
                                currCommand = cutConnector(currCommand);
                                commandChars.push_back(currCommand.c_str());
                        }

                        commandChars.push_back(0);
                        connectorVector.push_back(connection);
                        commandVector.push_back(commandChars);
                        while(commandChars.size() > 0){
                                commandChars.pop_back();
                        }
                }
        }
        changeConVec(connectorVector);
        changeCommandVec(commandVector);
}

