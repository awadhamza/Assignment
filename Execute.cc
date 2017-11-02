#include "Execute.hh"
#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>

int vec_index = 0;
int success = 0;

Execute::Execute() {}

Execute::~Execute() {}

void Execute::execute(std::vector<CMD*> CMDlist)
{
	
	
	
	for( vec_index; vec_index < CMDlist.size(); ++vec_index )
	{
			
		pid_t pid = fork();
		
		std::string currCommand = CMDlist.at(vec_index)->getInstruction();
		
		char* args[2];
		args[0] = (char*)currCommand.c_str();
		args[1] = 0;
			
		if(pid == 0) //Child process
		{
			if(CMDlist.at(vec_index)->getConnector() == 3)
			{
				if( execvp(args[0], args) == -1 ) // if a command with a && failed
				{					
					perror("exec");
					while(CMDlist.at(vec_index)->getConnector() == 3)
					{
						vec_index++;
					}
					//vec_index++;
					
				}
				else
				{
					success++;
				}			
			}
			else if (CMDlist.at(vec_index)->getConnector() == 2)
			{
				if( execvp(args[0], args) == -1 ) // if a command with a && failed
				{					
					perror("exec");
					vec_index++;
					
				}
				else
				{
					while(CMDlist.at(vec_index)->getConnector() == 2)
					{
						vec_index++;
					}
					//vec_index++;
					
					success++;
				}	
			}
			else if (CMDlist.at(vec_index)->getConnector() == 1)
			{
				if( execvp(args[0], args) == -1 )
				{
					perror("exec");
				}
			}
			else
			{
				if( execvp(args[0], args) == -1 )
				{
					perror("exec");
				}
			}
			
		}					
	} 
		if (getpid() > 0)	//Parent's block
		{
			for(unsigned i = 0; i < success; ++i)
			{
				wait(0);
			}
		} 
		else 	//Fork failed
		{
			std::cout << "Fork error. Quitting Program." << std::endl;
			
			exit(-1);
			
		}
	
	
	return;
	
}
