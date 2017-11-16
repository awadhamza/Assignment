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
		if(vec_index == 0){
			CMDlist.at(vec_index) -> execute();
		}
		
		if(vec_index > 0)
		{
			
			if((CMDlist.at(vec_index - 1)->getDone() == 1))	//Failure
			{
				if(CMDlist.at(vec_index - 1)->getConnector() == 3) // "&&"
				{
					vec_index++;	//offset
					CMDlist.at(vec_index - 1)->setDone(1);	//make failure
				}
				else  // "||" or ';'
				{
					CMDlist.at(vec_index) -> execute();
				}
			}
			else if ((CMDlist.at(vec_index - 1)->getDone() == 2)) // SUCCESS
			{
				
				if(CMDlist.at(vec_index - 1)->getConnector() == 2) // "||"
				{
					vec_index++;	//offset
					CMDlist.at(vec_index - 1)->setDone(2);	//make failure
				}
				else  // "&&" or ';'
				{
					CMDlist.at(vec_index) -> execute();
				}
				
			}
		}
	}
	
	for(unsigned i = 0; i < CMDlist.size(); i++)
	{
		CMDlist.pop_back();
	}
	
	/*
	
	for( vec_index; vec_index < CMDlist.size(); ++vec_index )
	{  		
			{
				if(CMDlist.at(vec_index)->getConnector() == 3)	//If "&&" connector
				{
					
					CMDlist.at(vec_index)->setDone(2); //Setting to true if it will work
					execvp(splitCommand, executables); //If success, parent should iterate to the next one
					
					//If failed, will set done to 1
					CMDlist.at(vec_index)->setDone(1); //Setting to false since failed
					while(CMDlist.at(vec_index)->getConnector() == 3)
					{
						CMDlist.at(vec_index)->setDone(1);
						vec_index++;
					}
					CMDlist.at(vec_index)->setDone(1);
					vec_index++;	//Offset
					exit(0);
					
				} 
				else if (CMDlist.at(vec_index)->getConnector() == 2)	//If "||" connector
				{
					CMDlist.at(vec_index)->setDone(2); //Setting to true if it will work
					while(CMDlist.at(vec_index)->getConnector() == 2)
					{
						CMDlist.at(vec_index)->setDone(2);
						vec_index++;
					}
					CMDlist.at(vec_index)->setDone(2);
					vec_index++;	//Offset
					
					execvp(splitCommand, executables); //If success, parent should iterate to the next one
					
					//If failed, will set done to 1
					CMDlist.at(vec_index)->setDone(1); //Setting to false since failed and parent should go to next
					vec_index = indexSave;
					exit(0);
					while(CMDlist.at(vec_index)->getConnector() == 2)
					{
						CMDlist.at(vec_index)->setDone(0);
						vec_index++;
					}
					exit(0);
					
				} else { //if ';' or ''
					
					CMDlist.at(vec_index)->setDone(2);	//Success
					execvp(splitCommand, executables);
					
					CMDlist.at(vec_index)->setDone(1);	//Failure
					exit(0);
					
				}
			} else if (CMDlist.at(vec_index)->getDone() == 1) //------------------------If this command had failed
			{
				if(CMDlist.at(vec_index)->getConnector() == 3)
				{
					
					while(CMDlist.at(vec_index)->getConnector() == 3){
						vec_index++;
					}
					
				} else if (CMDlist.at(vec_index)->getConnector() == 2){
					//Don't offset or do anything, the forloop will iterate
				} else {
					//Don't offset or do anything, the forloop will iterate
				}
			} else if (CMDlist.at(vec_index)->getDone() == 2) //-----------------------If this command had succeeded
			{
				if(CMDlist.at(vec_index)->getConnector() == 3)
				{
					
					//Don't offset or do anything, the forloop will iterate
					
				} else if (CMDlist.at(vec_index)->getConnector() == 2){
					
					while(CMDlist.at(vec_index)->getConnector() == 3){
						vec_index++;
					}
					
				} else {
					//Don't offset or do anything, the forloop will iterate
				}
			}			
			
		} else //parent process
		{
			int status = 0;
			while ((pid = wait(&status)) > 0);
		}
	}
	return;
	*/
	
}
