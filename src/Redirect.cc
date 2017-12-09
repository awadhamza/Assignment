#include "Redirect.hh"


string Redirect::findNextDirection(string command)
{
	string str;
	
	for(unsigned i = 0; i < command.size(); i++)
	{
		if(command.at(i) == '|')
		{
			str = "|";
			return str;
		} else if (command.at(i) == '>')
		{
			if(command.at(i+1) == '>')
			{
				str = ">";
				return str;
			}
			str = ">>";
			return str;
		} else if(command.at(i) == '<'){
			str = "<";
			return str;
		} else {
			str = "";
			return str;
		}
	}
}

string Redirect::findNextString(string command)
{
	string str;
	
	for(unsigned i = 0; i < command.size(); i++)
	{
		if(command.at(i) != '|' && command.at(i) != '>' && command.at(i) != '<' && command.at(i) != '\0')
		{
			str += command.at(i);
		}
		else
		{
			if(command.at(command.size() - 1) == ' '){
				substr(0, command.size() - 1);
			}
			return str;
		}
	}
}

void Redirect::readyVector()
{
	string commandCopy = getString();
	string strFunc;
	string dirFunc;
	while(commandCopy.size() > 0)
	{
		//Get next string and direction char
		strFunc = findNextString(commandCopy);
		dirFunc = findNextDirection(commandCopy);
		//Remove those receieved strings from string copy
		commandCopy.erase(0, strFunc.size());
		commandCopy.erase(0, dirFunc.size());
		//Push the strings in order to the ultimate vector
		separatedPath.push_back(strFunc);
		separatedPath.push_back(dirFunc);
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
