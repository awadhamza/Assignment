#include "CMD.hh"
#include <vector>

CMD::CMD() : instruction(""), connector(0) {}

CMD::~CMD() {}

CMD::CMD(std::string instruction, int connector) : instruction(instruction), connector(connector) {}

int CMD::checkConnector(std::string curr)
{
	
	if(curr == "&&" )
	{
		return 3;
	} else if (curr == "||")
	{
		return 2;
	} else if (curr == ";")
	{
		return 1;
	} else {
		return 0;
	}
	
}


void CMD::splitString()
{
	
	Tokenizer splitter(instruction);
	Tokenizer stagger(instruction);
	
	int connection;
	std::string currCommand;
	std::string basket;
	std::string nextCommand = stagger.next(); //This is to stagger the current splitter
	
	std::vector<std::string> commands;
	
	
	while((currCommand = splitter.next()) != "")
	{
		//commands.push(currCommand);
		std::string basket = currCommand;
		
		while(!checkConnector(nextCommand))
		{
			basket = basket + " " + nextCommand;//Since the command hasn't found a connector
			nextCommand = stagger.next();		//Continue looking ahead
		}
		
		//Now we should get the connector, if any, but we must recall our splitter		
		//When this command line is concactenated, regroup our splitter to one behind stagger
		splitter = stagger;
		stagger = splitter.next();
		
		//Set strings back
		currCommand = splitter.retString();
		nextCommand = stagger.retString();
		
		connection = checkConnector(currCommand);	//Function autosets connector type in ints
		
		CMDList.push_back(new CMD(basket,connection));	//Push back a new CMD obj with command and connector type
		
		currCommand = splitter.next(); //This acts as an iterator
		nextCommand = stagger.next(); //This acts as an iterator;
	}
	
	return;
}
