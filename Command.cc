#include "Command.hh"
#include "Interface.hh"
#include <vector>
#include <sstream>
#include <string>

using std::vector;
using namespace std;

int iteratorNum = 0;

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
	
	istringstream inSS(instruction)
	string curr = "";
	while( inSS >> curr )
	{
		
		vector<char*> commandChars;
		vector<int> connectorVector;
		vector<vector<char*>> commandVector;
		int connection = checkConnector(curr);
		
		if(checkConnector(curr) == 0)
		{
			char* temp = (char*)curr.c_str();
			commandChars.push_back(temp);
		}
		else if(checkConnector(curr) == 1)
		{
			char* temp = (char*)curr.c_str();
			commandChars.push_back(temp);
			connectorVector.push_back(1);
			
		}
		else if(checkConnector(curr) == 2)
		{
			char* temp = (char*)curr.c_str();
			commandChars.push_back(temp);
			connectorVector.push_back(2);
		}
		else if(checkConnector(curr) == 3)
		{
			char* temp = (char*)curr.c_str();
			commandChars.push_back(temp);
			connectorVector.push_back(3);
		}
	}
	
	//------------------------------------------ new implementation above ^^^
		Tokenizer splitter(instruction);

        int connection;
        std::string currCommand;
        vector<vector<char*>> commandVector;
        vector<int> connectorVector;
        vector<char*> commandChars;

        while((currCommand = splitter.next()) != "")
        {
				
                connection = checkConnector(currCommand);
                if(connection == 0){
                        commandChars.push_back((char*)currCommand.c_str());
                        connectorVector.push_back(connection);
                        //////==========================================
                        std::cout << "command chars is now: ";
                        for(unsigned i = 0; i < commandChars.size(); ++i)
                        {
							std::cout << commandChars.at(i) << " ";
						}
						std::cout << std::endl << "and iteratorNum is now: " << iteratorNum << std::endl;
						//////==========================================
                }
                else{
                        if(connection == 1){
                                currCommand = cutConnector(currCommand);
                                commandChars.push_back((char*)currCommand.c_str());
                        }
                        commandChars.push_back(0);
                        connectorVector.push_back(connection);
                        
						std::cout << std::endl;
                        
                        commandVector.push_back(commandChars);
                        //////==========================================
                        std::cout << "command chars is now: ";
                        for(unsigned i = 0; i < commandChars.size(); ++i)
                        {
							std::cout << commandChars.at(0) << " ";
						}
						std::cout << std::endl << "and iteratorNum is now: " << iteratorNum << std::endl;
						//////==========================================
                        while(commandChars.size() > 0){
                                commandChars.pop_back();
                        }
                }
                iteratorNum++;
        }
        commandChars.push_back(0);
		commandVector.push_back(commandChars);
		
		//std::cout << "These are chars: ";
		//for (int i = 0; i < commandVector.size(); i++){
		//		for(int j = 0; j < commandVector.at(i).size(); j++){
		//			std::cout << commandVector.at(i).at(j) << " ";
		//		}
		//}
		//std::cout << std::endl;
                        
        CMDVec = commandVector;
        connectVec = connectorVector;
}

vector<int> Command::getConVec(){
	return connectVec;
}
	
vector<vector<char*>> Command::getCommandVec(){
	return CMDVec;
}
