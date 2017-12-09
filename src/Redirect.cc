#include "Redirect.hh"
#include "Tokenizer.h"

void Redirect::readyVector()
{
	string currCommand;
	Tokenizer splitter(getString());
	vector<string> vectorCopy = getVector();
	
	while((currCommand = splitter.next()) != "")
	{
		
		vectorCopy.push_back(currCommand);
		
	}
}

void Redirect::execute()
{
	execute(getString(), getConnector());
}

void Redirect::execute(string fullCommand, int connector)
{
	readyVector();
	
	vector<string> vectorCopy = getVector();
	
	while(true){
		
		if(vectorCopy.size() >= 3)
		{
			string leftString = vectorCopy.at(vectorCopy.size() - 3);
			string leftConnector = vectorCopy.at(vectorCopy.size() - 2);
			string rightString = vectorCopy.at(vectorCopy.size() - 1);
		} else {
			break;
		}
		if(leftConnector == '|')
		{
			executePipe(leftString, rightString);
		} else if (leftConnector == '>')
		{
			executeG(leftString, rightString);
		} else if (leftConnector == ">>")
		{
			executeGG(leftString, rightString);
		} else if (leftConnector == '<')
		{
			executeL(leftString, rightString);
		}
		
	}
	
}

void executePipe(string , string )
{
	
}
void executeGG(string , string )
{
	
}
void executeG(string , string )
{
	
}
void executeL(string , string )
{
	
}

bool Redirect::is_Group()
{
	return false;
}

void Redirect::setType(string path)
{
	typePath = path;
}

void Redirect::setString(string str)
{
	fullPath = str;
}

string Redirect::getString()
{
	return fullPath;
}

string Redirect::getConnector()
{
	return connector;
}

vector<string> Redirect::getVector()
{
	return separatedPath;
}
