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


char* Execute::makeCharPointers(vector<CMD*> CMDlist)
{
	for(unsigned j = 0; j < CMDlist.size(); j++){
		
		Tokenizer token(CMDlist.at(j)->getInstruction());
		
		string currentWord;
		char* argArray[CMDlist.at(j)->getInstruction().size()];
		int i = 0;
		
		while((currentWord = token.next()) != "")	//Iteratees to next word in array
		{
			
			
			while(argArray[i]){
				i++;
			}
			
			argArray[i] = (char*)currentWord.c_str();
			
		}
		
		executables[executablesSize] = new char(argArray);
		executablesSize++;
		
		for(int j = 0; argArray[j]; j++) {
			argArray[j] = 0;
		}
	}
	
}

Execute::~Execute() {}

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
