#include "Execute.hh"
#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

int vec_index = 0;
int success = 0;

Execute::Execute() {}

Execute::~Execute() {}

void Execute::execute(vector<vector<char*>> cmds, vector<int> connectors)
{
	cout << "This is outputting in EXECUTE()" << endl;
	
	//cout << "About to execute. Here are the commands within the command vector." << endl;
	
	//for(unsigned i = 0; i < cmds.size(); ++i)
	//{
	//	cout << "Index: " << i << endl;
	//	for(unsigned j = 0; j < cmds.at(i).size(); ++j)
	//	{
	//		
	//		cout << cmds.at(i).at(j) << " ";
	//		
	//	}
	//	cout << endl;
	//	
	//}
	
	cout << "DONE OUTPUTTING CMDLIST" << endl;
	
	/*
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
	
	*/
	return;
	
}
