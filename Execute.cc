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

void Execute::execute(std::vector<CMD*> CMDlist)
{
	unsigned vec_index = 0;
	int success = 0;

	for(vec_index = 0; vec_index < CMDlist.size(); vec_index++)
	{
		if(vec_index > 0)
		{
			
			if((CMDlist.at(vec_index - 1)->getDone() == 1))	//Failure
			{
				if(CMDlist.at(vec_index - 1)->getConnector() == 3) // "&&"
				{
					CMDlist.at(vec_index)->setDone(1);	//make failure
				}
			}

			else if ((CMDlist.at(vec_index - 1)->getDone() == 2)) // SUCCESS
			{
				
				if(CMDlist.at(vec_index - 1)->getConnector() == 2) // "||"
				{
					CMDlist.at(vec_index)->setDone(2);	//make success
				}				
			}
		}
		if(CMDlist.at(vec_index) -> getConnector() == 4){
			CMDlist.at(vec_index + 1) -> execute("stat");
			return;
		}
		if(CMDlist.at(vec_index) -> getDone() == 0){ //
			CMDlist.at(vec_index) -> execute("fork");
		}
	}
	
	for(unsigned i = 0; i < CMDlist.size(); i++)
	{
		CMDlist.pop_back();
	}
}
