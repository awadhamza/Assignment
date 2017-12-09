#include "Redirect.hh"


string Redirect::findNextDirection(string command)
{
	string str;
	
	for(unsigned i = 0; i < command.size(); i++)
	{
		if(command.at(i) == "|")
		{
			str = "|";
		} else if (command.at(i) == ">")
		{
			if(command.at(i+1) == ">")
			{
				str = ">";
			}
			str = ">>";
		} else if(command.at(i) == "<"){
			str = "<";
		} else {
			str = "";
		}
		return str;
	}
}

void Redirect::execute()
{
	
}

void Redirect::execute(string fullCommand, int connector)
{
	
	string nextDirect = findNextDirection(fullCommand);
	
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
