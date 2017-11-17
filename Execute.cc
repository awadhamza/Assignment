#include "src/Execute.hh"
#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


using namespace std;

Execute::Execute()
{
}

Execute::~Execute() 
{

}

void Execute::execute(std::vector<Base*> executeList)
{
	unsigned vec_index = 0;
	int success = 0;

	for(vec_index = 0; vec_index < executeList.size(); vec_index++)
	{
		if(vec_index > 0)
		{
			if((executeList.at(vec_index - 1)->getDone() == 1))	//Failure
			{
				if(executeList.at(vec_index - 1)->getConnector() == 3) // "&&"
				{
					executeList.at(vec_index)->setDone(1);	//make failure
				}
			}

			else if ((executeList.at(vec_index - 1)->getDone() == 2)) // SUCCESS
			{
				if(executeList.at(vec_index - 1)->getConnector() == 2) // "||"
				{
					executeList.at(vec_index)->setDone(2);	//make success
				}				
			}
		}
		if(executeList.at(vec_index) -> getConnector() == 4 || executeList.at(vec_index) -> getConnector() == 5){	//If connector = '[' || connector = ']'
			executeList.at(vec_index + 1) -> execute("stat", executeList.at(vec_index) -> getConnector());
		}
		else if(executeList.at(vec_index) -> getDone() == 0){ //Unchecked done status
			executeList.at(vec_index) -> execute("fork", executeList.at(vec_index) -> getConnector());
		}
	}
	
	for(unsigned i = 0; i < executeList.size(); i++)
	{
		executeList.pop_back();
	}
	return;
}
