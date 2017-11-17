#include "src/CMD.hh"
#include <vector>
#include <sstream>
#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

using namespace std;

CMD::CMD() : instruction(""), connector(0), done(0) {}


CMD::CMD(std::string instruction, int connector) : instruction(instruction), connector(connector), done(0) {}

int CMD::getConnector(){
	return connector;
}

void CMD::changeConnector(int newConnector){
	connector = newConnector;
	return;
}

int CMD::getDone(){
	return done;
}

void CMD::setDone(int newDone){
	done = newDone;
	return;
}

void CMD::execute(){
	if(instruction == "exit" || instruction.size() == 0)
		{
			exit(0);
		}
		
		int temp = 0;	
		
		string completeCommand = instruction;
		char splitCommand[1024];
  		char *executables[1024];
  		int charSize = completeCommand.size();
  		char* addLetter = NULL;
 		int i = 0;
  		int executablesIndex = 0;
  
  		for (unsigned int j = 0; j < completeCommand.size(); j++){
    			splitCommand[j] = completeCommand[j];
  		}
  		
  		//splitCommand[charSize] = ' ';
  		splitCommand[charSize + 1] = '0';
  
  		addLetter = strtok(splitCommand, " " );
  	
  		while(addLetter != NULL){
    		executables[i++] = addLetter;
    		addLetter = strtok(NULL, " ");
   			executablesIndex++;
  		}
  		
  		
		//for (unsigned int k = 0; k < completeCommand.size() + 1; k++){
    	//		cout << splitCommand[k] << endl;
  		//}
  		
  		cout << "SPLITCOMMAND: ";
  		for(unsigned i = 0; i < charSize + 1; i++)
  		{
			cout << splitCommand[i] << " ";
		} cout << endl;
		
  		cout << "EXECUTABLES: " << executables[0] << " " << endl;
  		
  		int commandStatus = execute_fork(splitCommand, executables); //0 if not checked, 1 if failed, and 2 if done correctly
  		done = commandStatus;
  		
  		/*
  		int ii = 1023;
  		while(ii)
  		{
			delete executables[ii];
			delete splitCommand[ii];
		}
  		*/
  		return;
}

int CMD::execute_fork(char splitCommand[], char* executables[]){
	
	pid_t pid = fork();
	
	if(pid < 0) //fork failed
		{
			std::cout << "Fork error. Quitting Program." << std::endl;
			exit(-1);
		}
	
	else if(pid == 0)//child process
		{
			if(done == 0){
				execvp(splitCommand, executables);
				done = 1;
			}
			return done;
		}
	else{
			wait(0);
			done = 2;
			return done;
		}
}

string CMD::getInstruction(){
	return instruction;
}
