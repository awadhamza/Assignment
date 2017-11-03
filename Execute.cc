#include "src/Execute.hh"
#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include "src/Tokenizer.h"
#include <string.h>

using namespace std;

int vec_index = 0;
int success = 0;

Execute::Execute() {}

Execute::~Execute() {}

void Execute::execute(std::vector<CMD*> CMDlist)
{
	
	
	
	for( vec_index; vec_index < CMDlist.size(); ++vec_index )
	{
			
		pid_t pid = fork();
		
		//std::string currCommand = CMDlist.at(vec_index)->getInstruction();
		
		//const char* argsChar = (CMDlist.at(vec_index)->getInstruction());
		//char* const* args = argsChar;
		//char* first = &argsChar[0];
		string argsChar = (CMDlist.at(vec_index)->getInstruction());
		
		vector<char> VectoChar(argsChar.length() + 1);
		strcpy(&VectoChar[0], argsChar.c_str());
		char* argsVec = &VectoChar[0];
		const char* first = &argsVec[0];
		char* const* args = &argsVec;
		
		if(pid < 0) //fork failed
		{
			std::cout << "Fork error. Quitting Program." << std::endl;
			
			exit(-1);
			
		} else if (pid > 0) //parent process
		{
			
		} else //child process
		{
			execvp(first, args);
			/*
			if(CMDlist.at(vec_index)->getConnector() == 3) // && connector
			{
				execvp(args[0], args);
			} 
			else if (CMDlist.at(vec_index)->getConnector() == 2) // || connector
			{
				
			}
			else // ';' or ""
			{
				
				
				
			} */
		}
	}
	wait(0);
		/*
		for(int i = 0; i < argsChar.length(); i++){
			cout << "DIS TING " << args[i] << endl;
		}
		*/
		
		/*
		string argsChar = (CMDlist.at(vec_index)->getInstruction());
		
		vector<char> VectoChar(argsChar.length() + 1);
		strcpy(&VectoChar[0], argsChar.c_str());
		char argsVecTemp = VectoChar[0];
		argsVecTemp[static_cast<int>(argsChar.length())] = '\0';
		char* argsVec = &argsVecTemp;
		const char* first = &argsVec[0];
		char* const* args = &argsVec;
		*/
		
		
		//char* args[2];
		//args[0] = (char*)currCommand.c_str();
		//args[1] = 0;
			/*
		if(pid == 0) //Child process
		{
			success++;
			if(CMDlist.at(vec_index)->getConnector() == 3)
			{
				if( execvp(first, args) == -1 ) // if a command with a && failed
				{			
					success--;		
					perror("exec");
					while(CMDlist.at(vec_index)->getConnector() == 3)
					{
						vec_index++;
					}
					//vec_index++;
					
				}		
			}
			else if (CMDlist.at(vec_index)->getConnector() == 2)
			{
				int tempVecIndex = vec_index;
				
				while(CMDlist.at(vec_index)->getConnector() == 2)
					{
						vec_index++;
					}
				if( execvp(first, args) == -1 ) // if a command with a && failed
				{	
					success--;		
					perror("exec");
					vec_index = tempVecIndex + 1;
					
				}	
			}
			else if (CMDlist.at(vec_index)->getConnector() == 1)
			{
				if( execvp(first, args) == -1 )
				{
					perror("exec");
				}
			}
			else
			{
				if( execvp(first, args) == -1 )
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
			wait(0);
		} 
		else 	//Fork failed
		{
			std::cout << "Fork error. Quitting Program." << std::endl;
			
			exit(-1);
			
		}
	
	*/
	
	return;
	
}
