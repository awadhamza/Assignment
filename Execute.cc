#include "src/Execute.hh"
#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include "src/Tokenizer.h"

using namespace std;

/*
 * Note to self
 * 
	string str = "string";
	char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	
	// do stuff
	delete [] cstr;
 *  
 */


void Execute::makeCharPointers(vector<CMD*> CMDlist)
{
	for(unsigned j = 0; j < CMDlist.size(); j++){ //Goes through every CMD object
		
		Tokenizer token(CMDlist.at(j)->getInstruction());		//Gets its string
		
		string currentWord;
		char* newCMD = new char[CMDlist.at(j)->getInstruction().size() + 1];		// + 1 for a null pointer at the end
		int i = 0;
		
		while((currentWord = token.next()) != "")	//Iteratees to next word in string
		{
			
			
			for(unsigned j = 0; j < currentWord.size(); j++)
			{
				
				newCMD[i + j] = currentWord.at(j);
				
			}
			
			executables[executablesSize] = newCMD;
						
		}
		
	}
	
}

Execute::~Execute() 
{
	while(executablesSize)
	{
		delete executables[executablesSize];
	}
	delete executables[executablesSize]; //this is because of design implementation
}

void Execute::execute(std::vector<CMD*> CMDlist)
{
	int vec_index = 0;
	int success = 0;

	//for( unsigned i = 0; i < CMDlist.size(); i++)
	//{
	//	cout << CMDlist.at(i)->getInstruction() << " " << i << " ===== ";
	//}
	//cout << endl;
	
	for( vec_index; vec_index < CMDlist.size(); ++vec_index )
	{
		int temp = 0;	
		pid_t pid = fork();
		
		std::string currCommand = CMDlist.at(vec_index)->getInstruction();
		char** argz;
			
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
