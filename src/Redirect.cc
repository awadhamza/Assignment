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
			return str;
		}
	}
}

void Redirect::readyVector()
{
	string commandCopy = getString();
	string strFunc;
	string dirFunc;
	while(commandCopy.size())
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

void Redirect::execute(string fullCommand, int connector)
{
	readyVector();
	
	
	
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

string Redirect::getType()
{
	return typePath;
}
