#include "Execute.hh"
#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include "Tokenizer.h"

using namespace std;

char* makeCharPointers(string instruc)
{
	Tokenizer token(instruc);
	
	string currentWord;
	char* argArray[1024];
	int i = 0;
	
	while((currentWord = token.next()) != "")
	{
		
		
		while(argArray[i]){
			i++;
		}
		
		argArray[i] = (char*)currentWord.c_str();
		
	}
	
	for(int j = 0; argArray[j]; j++) {
		argArray[j] = 0;
	}
	
}

int vec_index = 0;
int success = 0;

Execute::Execute() {}

Execute::~Execute() {}

void Execute::execute(std::vector<CMD*> CMDlist)
{
	
	
	
	for( vec_index; vec_index < CMDlist.size(); ++vec_index )
	{
		int temp = 0;	
		pid_t pid = fork();
		
		std::string currCommand = CMDlist.at(vec_index)->getInstruction();
		
		char* argz[1024] = {makeCharPointers(currCommand)};
			
		if(pid == 0) //Child process
		{
			if(CMDlist.at(vec_index)->getConnector() == 3)
			{
				success++;
				vec_index++;
				
				if(execvp(argz[0], argz) < 0){
					perror("exec failed");
					while(CMDlist.at(vec_index)->getConnector() == 3)
					{
						vec_index++;
					}
					//vec_index++; //for offset
					success--;
					
				}
			}
			else if (CMDlist.at(vec_index)->getConnector() == 2)
			{
				temp = vec_index;
				while(CMDlist.at(vec_index)->getConnector() == 2)
				{
					vec_index++;
				}
				//vec_index++; //for offset
				success++;
				
				if(execvp(argz[0], argz) < 0)
				{
					perror("exec failure");
					success--;
					vec_index = temp + 1;
				}
				
			}
			else 
			{
				vec_index++;
				success++;
				
				if(execvp(argz[0], argz) < 0)
				{
					perror("exec failure");
					success;
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
		else if(getpid() < 0)	//Fork failed
		{
			std::cout << "Fork error. Quitting Program." << std::endl;
			
			exit(-1);
			
		}
	
	
	return;
	
}
