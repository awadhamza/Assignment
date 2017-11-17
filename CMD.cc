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
#include <sys/stat.h>

using namespace std;

CMD::CMD() : instruction(""), connector(0), done(0) {}


CMD::CMD(std::string instruction, int connector) : instruction(instruction), connector(connector), done(0) {}

void CMD::execute(string execCommand, int testOrBrac){
	while(execCommand.at(0) == ' '){
		execCommand = execCommand.substr(1, execCommand.size() - 1);
	}
	while(execCommand.at(execCommand.size() - 1) == ' '){
		execCommand = execCommand.substr(0, execCommand.size() - 2);
	}
	
	if(instruction == "exit" || instruction.size() == 0)
	{
		exit(0);
	}
		
	int temp = 0;	
		
	string completeCommand = instruction;
	
	while(completeCommand.at(0) == ' '){
		completeCommand = completeCommand.substr(1, completeCommand.size() - 1);
	}
	while(completeCommand.at(completeCommand.size() - 1) == ' '){
		completeCommand = completeCommand.substr(0, completeCommand.size() - 2);
	}
	
	char splitCommand[1024];
  	char *executables[1024];
		
	int count = 0;
	while(count != 1024){
		executables[count] = NULL;
		count++;
	}
	memset(splitCommand, 0, 1023);

 	int charSize = completeCommand.size();
  	char* addLetter = NULL;
 	int i = 0;
  	int executablesIndex = 0;
  	
  	int commandStatus = 0;
  	
  		if(execCommand == "fork"){
			if(completeCommand.substr(0, 4) == "echo" && completeCommand.at(5) == '"' && completeCommand.at(completeCommand.size() - 1) == '"'){
				string temp1 = completeCommand.substr(0, 5);
				string temp2 = completeCommand.substr(6, completeCommand.size() - 7);
				completeCommand = temp1 + temp2;
			}	
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
  		
			commandStatus = execute_fork(splitCommand, executables); //0 if not checked, 1 if failed, and 2 if done correctly
		}
		else if(execCommand == "stat"){
			char flag;
			unsigned int p = 0;
			if((completeCommand.at(completeCommand.size() - 1) != ']' || completeCommand.at(completeCommand.size() - 2) != ' ') && testOrBrac == 5){
				cout << "missing ']'" << endl;
				exit(0);
			}
			else if (testOrBrac == 5){
				completeCommand = completeCommand.substr(0, completeCommand.size() - 2);
				while(completeCommand.at(0) == ' '){
					completeCommand = completeCommand.substr(1, completeCommand.size() - 1);
				}
				while(completeCommand.at(completeCommand.size() - 1) == ' '){
					completeCommand = completeCommand.substr(0, completeCommand.size() - 2);
				}
			}
			
			//cout << "this string: " << completeCommand << endl;
			
			for (unsigned int j = 0; j < completeCommand.size(); j++){
				if(j == 0 && completeCommand[j] == '-'){
					flag = completeCommand[j + 1];
					j += 3;
				}		
    			splitCommand[p] = completeCommand[j];
    			p++;
			}
			commandStatus = execute_stat(splitCommand, flag); //0 if not checked, 1 if failed, and 2 if done correctly
		}
  		setDone(commandStatus);
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

int CMD::execute_stat(char splitCommand[], char flag){
	
		struct stat buf;
		//Note to self stat constructor arguments: stat(char a[], reference to struct)
		
		stat(splitCommand, &buf);
		if(flag == 'e')
		{
			if( S_ISREG( buf.st_mode ) != 0 || S_ISDIR( buf.st_mode ) != 0)
			{
				cout << "(True)" << endl;
				return 2;
			}
			else
			{
				cout << "(False)" << endl;
				return 1;
			}
		}
		else if (flag == 'f')
		{
			if( S_ISREG( buf.st_mode ) != 0 )
			{
				cout << "(True)" << endl;
				return 2;
			}
			else
			{
				cout << "(False)" << endl;
				return 1;
			}
		}
		else     //flag == 'd'
		{
			if( S_ISDIR( buf.st_mode ) != 0 )
			{
				cout << "(True)" << endl;
				return 2;
			}
			else
			{
				cout << "(False)" << endl;
				return 1;
			}
		}
			
		cout << "DIDN'T DETECT FLAG" << endl;
	//}
	//else {
	//	wait(0);
		return 0;
	//}
}

bool CMD::is_Group(){
	return false;
}
